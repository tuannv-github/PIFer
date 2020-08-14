/*
 * Mode_Basic.c
 *
 *  Created on: Oct 10, 2019
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

static void tilt_report_callback(uint8_t *ctx){
	mavlink_message_t msg;
	uint8_t mav_send_buf[256];
	float tilt = imu_get_tilt() - params.angle_adjusted;
	mavlink_msg_evt_tilt_pack(0,0,&msg,tilt);
	uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
	com_send(mav_send_buf, len);
}

void mode_run_init(){
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
}

void mode_run_deinit(){
	// Hardware de-initialization
	motors_deinit();
	imu_deinit();

	// Periodic task de-initialization
	timer_unregister_callback(gtimerid_tilt_controller);
	timer_unregister_callback(gtimerid_vel_controller);
	timer_unregister_callback(gtimerid_imu_tilt);
}

void on_mode_run_mavlink_recv(mavlink_message_t *msg){
	switch(msg->msgid){
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
