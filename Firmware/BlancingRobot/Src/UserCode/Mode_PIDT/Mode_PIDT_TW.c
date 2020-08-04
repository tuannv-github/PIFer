/*
 * PID_Tunnng.c
 *
 *  Created on: Oct 12, 2019
 *      Author: 16138
 */

#include <UserCode/user_define.h>

#ifdef ROBOT_MODEL_TWO_WHEELS

#include <UserCode/IMU/IMU.h>
#include <UserCode/Mode_PIDT/Mode_PIDT.h>
#include "UserCode/Motors/Motors.h"
#include <UserCode/Encoder/Encoder.h>
#include "UserCode/PID/PID.h"
#include "UserCode/Com/Com.h"
#include "UserCode/Params/Params.h"

typedef struct{
	int16_t vx;
	int16_t vy;
	int16_t omega;
	uint8_t cnt;
}cmd_velocity_t;

static cmd_velocity_t gcmd_velocity;

static timer_id_t gtimerid_tilt_controller;
static timer_id_t gtimerid_vel_controller;
static timer_id_t gtimerid_imu_tilt;
static timer_id_t gtimerid_pid_report;
static mavlink_message_t msg;

static float tilt_setpoint;

static void tilt_controller_callback(uint8_t* ctx){
	float tilt = imu_get_tilt() - params.angle_adjusted;

	float speed = pid_compute(&params.pid[0], tilt_setpoint, tilt);
	if(tilt > 90 || tilt < -90) {
		speed = 0;
		pid_reset(&params.pid[0]);
		pid_reset(&params.pid[1]);
	}
	motors_setspeed(MOTOR_0, speed + (float)gcmd_velocity.omega*OMEGA_COEFF);
	motors_setspeed(MOTOR_1, speed - (float)gcmd_velocity.omega*OMEGA_COEFF);
}

static void vel_controller_callback(uint8_t* ctx){

	if(gcmd_velocity.cnt == 0){
		gcmd_velocity.vx = 0;
		gcmd_velocity.omega = 0;
	}
	else{
		gcmd_velocity.cnt--;
	}

	int16_t motor0_speed = enc_read(MOTOR_0);
	int16_t motor1_speed = enc_read(MOTOR_1);
	float direction = -(motor0_speed + motor1_speed)/2;

	tilt_setpoint = pid_compute(&params.pid[1], gcmd_velocity.vx, direction);
}

static void load_params(){
	// Load parameters from non-volatile memory
	params_load();

	// Send parameters to GCS
	uint8_t gmav_send_buf[256];
	uint16_t len;

	mavlink_msg_pid_params_pack(0,0,&msg,PID_TILT,params.pid[0].KP,params.pid[0].KI,params.pid[0].KD);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	com_send(gmav_send_buf, len);

	mavlink_msg_pid_params_pack(0,0,&msg,PID_VEL,params.pid[1].KP,params.pid[1].KI,params.pid[1].KD);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	com_send(gmav_send_buf, len);

	mavlink_msg_pid_params_pack(0,0,&msg,PID_POS,params.pid[2].KP,params.pid[2].KI,params.pid[2].KD);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	com_send(gmav_send_buf, len);

	pid_reset(&params.pid[0]);
	pid_reset(&params.pid[1]);
	pid_reset(&params.pid[2]);
}

static void save_params(){
	// Save parameters to non-volatile memory
	params_save();

	// Respond for a successful operation
	respond_ok();
}

static void write_param(mavlink_message_t *msg){
	// Change current parameters according to GCS
	mavlink_pid_params_t pid_msg;
	mavlink_msg_pid_params_decode(msg,&pid_msg);
	if(pid_msg.pid_control == PID_TILT){
		params.pid[0].KP = pid_msg.KP;
		params.pid[0].KI = pid_msg.KI;
		params.pid[0].KD = pid_msg.KD;

		// Respond for a successful operation
		respond_ok();
	}
	else if(pid_msg.pid_control == PID_VEL){
		params.pid[1].KP = pid_msg.KP;
		params.pid[1].KI = pid_msg.KI;
		params.pid[1].KD = pid_msg.KD;

		// Respond for a successful operation
		respond_ok();
	}
	else if(pid_msg.pid_control == PID_POS){
		params.pid[2].KP = pid_msg.KP;
		params.pid[2].KI = pid_msg.KI;
		params.pid[2].KD = pid_msg.KD;

		// Respond for a successful operation
		respond_ok();
	}
}

static void tilt_report_callback(uint8_t *ctx){
	mavlink_message_t msg;
	uint8_t mav_send_buf[256];
	float tilt = imu_get_tilt() - params.angle_adjusted;
	mavlink_msg_evt_tilt_pack(0,0,&msg,tilt);
	uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
	com_send(mav_send_buf, len);
}

static void pid_report_callback(uint8_t *ctx){
	mavlink_message_t pid_report_msg;
	uint8_t gmav_send_buf[256];

	mavlink_msg_pid_report_pack(0,0,&pid_report_msg,PID_TILT,
			params.pid[0].sp,
			params.pid[0].fb,
			params.pid[0].P_Part,
			params.pid[0].I_Part,
			params.pid[0].D_Part,
			params.pid[0].U);
	uint16_t len = mavlink_msg_to_send_buffer(gmav_send_buf, &pid_report_msg);
	com_send(gmav_send_buf, len);

	mavlink_msg_pid_report_pack(0,0,&pid_report_msg,PID_VEL,
			params.pid[1].sp,
			params.pid[1].fb,
			params.pid[1].P_Part,
			params.pid[1].I_Part,
			params.pid[1].D_Part,
			params.pid[1].U);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &pid_report_msg);
	com_send(gmav_send_buf, len);

	mavlink_msg_pid_report_pack(0,0,&pid_report_msg,PID_POS,
			params.pid[2].sp,
			params.pid[2].fb,
			params.pid[2].P_Part,
			params.pid[2].I_Part,
			params.pid[2].D_Part,
			params.pid[2].U);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &pid_report_msg);
	com_send(gmav_send_buf, len);
}


void mode_pidt_init(){
	// Hardware initialization
	motors_init();
	imu_init();

	params.pid[1].maxIPart = 5;
	params.pid[1].minIpart = -5;

	pid_reset(&params.pid[0]);
	pid_reset(&params.pid[1]);
	pid_reset(&params.pid[2]);

	// Periodic task initialization
	gtimerid_tilt_controller = timer_register_callback(tilt_controller_callback, TILT_CONTROLLER_PERIOD, 0, TIMER_MODE_REPEAT);
	gtimerid_vel_controller = timer_register_callback(vel_controller_callback, VEL_CONTROLLER_PERIOD, 0, TIMER_MODE_REPEAT);
	gtimerid_imu_tilt = timer_register_callback(tilt_report_callback, TILT_REPORT_PERIOD, 0, TIMER_MODE_REPEAT);
	gtimerid_pid_report = timer_register_callback(pid_report_callback, PID_REPORT_PERIOD, 0, TIMER_MODE_REPEAT);
}

void mode_pidt_deinit(){
	// Hardware de-initialization
	motors_deinit();
	imu_deinit();

	// Periodic task de-initialization
	timer_unregister_callback(gtimerid_tilt_controller);
	timer_unregister_callback(gtimerid_vel_controller);
	timer_unregister_callback(gtimerid_pid_report);
	timer_unregister_callback(gtimerid_imu_tilt);
}

void on_mode_pidt_mavlink_recv(mavlink_message_t *msg){
	switch(msg->msgid){
	case MAVLINK_MSG_ID_CMD_PARAMS:
		{
			mavlink_cmd_params_t cmd_msg;
			mavlink_msg_cmd_params_decode(msg, &cmd_msg);
			if(cmd_msg.cmd_params == CMD_LOAD) load_params();
			else if(cmd_msg.cmd_params == CMD_SAVE) save_params();
		}
		break;
	case MAVLINK_MSG_ID_PID_PARAMS:
		write_param(msg);
		break;
	case MAVLINK_MSG_ID_CMD_VELOCITY:
		{
			mavlink_cmd_velocity_t cmd_velocity;
			mavlink_msg_cmd_velocity_decode(msg, &cmd_velocity);
			gcmd_velocity.vx = cmd_velocity.v;
			gcmd_velocity.omega = cmd_velocity.omega;
			gcmd_velocity.cnt = (CONTROL_TIMEOUT_MS/VEL_CONTROLLER_PERIOD);
		}
		break;
	default:
		break;
	}
}

#endif
