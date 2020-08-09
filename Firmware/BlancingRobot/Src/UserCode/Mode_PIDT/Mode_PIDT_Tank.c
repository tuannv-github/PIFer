/*
 * PID_Tunnng.c
 *
 *  Created on: Oct 12, 2019
 *      Author: 16138
 */

#include <UserCode/user_define.h>

#ifdef ROBOT_MODEL_TANK

#include <UserCode/Mode_PIDT/Mode_PIDT.h>
#include "UserCode/Motors/Motors.h"
#include "UserCode/IMU/IMU.h"
#include "UserCode/PID/PID.h"
#include "UserCode/Com/Com.h"
#include "UserCode/Params/Params.h"
#include "UserCode/Encoder/Encoder.h"

static timer_id_t gwhe_id;
static timer_id_t gsync_id;
static timer_id_t gwhe_report_id;
static timer_id_t gspe_report_id;

static float gmotor0_speed;
static float gmotor1_speed;
static float gmotor0_sp;
static float gmotor1_sp;

static void wheel_callback(uint8_t* ctx){
	int16_t motor0_speed = enc_read(MOTOR_0);
	int16_t motor1_speed = enc_read(MOTOR_1);

	float speed0 = pid_compute(&params.pid[0], gmotor0_speed, motor0_speed);
	float speed1 = pid_compute(&params.pid[1], gmotor1_speed, motor1_speed);

	motors_setspeed(MOTOR_0, speed0);
	motors_setspeed(MOTOR_1, speed1);
}

static void sync_callback(uint8_t* ctx){
	if(gmotor0_speed > 0 && gmotor1_speed > 0){
		int16_t motor0_speed = enc_read(MOTOR_0);
		int16_t motor1_speed = enc_read(MOTOR_1);

		float balance = pid_compute(&params.pid[2], atan2(gmotor1_speed,gmotor0_speed), atan2((float)motor1_speed,(float)motor0_speed));

		// adjust set point
		gmotor0_sp = gmotor0_speed - balance;
		gmotor1_sp = gmotor1_speed + balance;
	}
	else{
		gmotor0_sp = gmotor0_speed;
		gmotor1_sp = gmotor1_speed;
	}

}


static void load_pid_params(){
	// Load parameters from non-volatile memory
	params_load();

	// Send parameters to GCS
	mavlink_message_t msg;
	uint8_t gmav_send_buf[256];
	uint16_t len;

	mavlink_msg_pid_params_pack(0,0,&msg,PID_SYNC,params.pid[2].KP,params.pid[2].KI,params.pid[2].KD);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	com_send(gmav_send_buf, len);
	pid_reset(&params.pid[2]);

	mavlink_msg_pid_params_pack(0,0,&msg,PID_WHE0,params.pid[0].KP,params.pid[0].KI,params.pid[0].KD);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	com_send(gmav_send_buf, len);
	pid_reset(&params.pid[0]);

	mavlink_msg_pid_params_pack(0,0,&msg,PID_WHE1,params.pid[1].KP,params.pid[1].KI,params.pid[1].KD);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	com_send(gmav_send_buf, len);
	pid_reset(&params.pid[1]);
}

static void save_pid_params(){
	// Save parameters to non-volatile memory
	params_save();

	// Respond for a successful operation
	respond_ok();
}

static void write_param(mavlink_message_t *msg){
	// Change current parameters according to GCS
	mavlink_pid_params_t pid_msg;
	mavlink_msg_pid_params_decode(msg,&pid_msg);

	switch(pid_msg.pid_control){
	case PID_WHE0:
		params.pid[0].KP = pid_msg.KP;
		params.pid[0].KI = pid_msg.KI;
		params.pid[0].KD = pid_msg.KD;
		pid_reset(&params.pid[0]);
		break;
	case PID_WHE1:
		params.pid[1].KP = pid_msg.KP;
		params.pid[1].KI = pid_msg.KI;
		params.pid[1].KD = pid_msg.KD;
		pid_reset(&params.pid[1]);
		break;
	case PID_SYNC:
		params.pid[2].KP = pid_msg.KP;
		params.pid[2].KI = pid_msg.KI;
		params.pid[2].KD = pid_msg.KD;
		pid_reset(&params.pid[2]);
		break;
	}
	// Respond for a successful operation
	respond_ok();
}

static void pid_report_callback(uint8_t *ctx){
	mavlink_message_t pid_report_msg;
	uint8_t gmav_send_buf[256];

	mavlink_msg_pid_report_pack(0,0,&pid_report_msg,PID_WHE0,
			params.pid[0].sp,
			params.pid[0].fb,
			params.pid[0].P_Part,
			params.pid[0].I_Part,
			params.pid[0].D_Part,
			params.pid[0].U);
	uint16_t len = mavlink_msg_to_send_buffer(gmav_send_buf, &pid_report_msg);
	com_send(gmav_send_buf, len);

	mavlink_msg_pid_report_pack(0,0,&pid_report_msg,PID_WHE1,
			params.pid[1].sp,
			params.pid[1].fb,
			params.pid[1].P_Part,
			params.pid[1].I_Part,
			params.pid[1].D_Part,
			params.pid[1].U);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &pid_report_msg);
	com_send(gmav_send_buf, len);

	mavlink_msg_pid_report_pack(0,0,&pid_report_msg,PID_SYNC,
			params.pid[2].sp,
			params.pid[2].fb,
			params.pid[2].P_Part,
			params.pid[2].I_Part,
			params.pid[2].D_Part,
			params.pid[2].U);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &pid_report_msg);
	com_send(gmav_send_buf, len);
}

static void speed_report_callback(uint8_t* ctx){
	mavlink_message_t speed_msg;
	uint8_t gmav_send_buf[256];

	int32_t motor0_speed = enc_read(MOTOR_0);
	int32_t motor1_speed = enc_read(MOTOR_1);

	mavlink_msg_motor_speed_pack(0,0,&speed_msg,motor0_speed,motor1_speed);
	uint16_t len = mavlink_msg_to_send_buffer(gmav_send_buf, &speed_msg);
	com_send(gmav_send_buf, len);
}

void mode_pidt_init(){
	// Hardware initialization
	motors_init();

	pid_reset(&params.pid[0]);
	pid_reset(&params.pid[1]);
	pid_reset(&params.pid[2]);

	// Periodic task initialization
	gwhe_id = timer_register_callback(wheel_callback, WHEEL_PERIOD, 0, TIMER_MODE_REPEAT);
//	gsync_id = timer_register_callback(sync_callback, SYNC_PERIOD, 0, TIMER_MODE_REPEAT);
//	gwhe_report_id = timer_register_callback(pid_report_callback, PID_REPORT_PERIOD, 0, TIMER_MODE_REPEAT);
	gspe_report_id = timer_register_callback(speed_report_callback, SPEED_REPORT_PERIOD, 0, TIMER_MODE_REPEAT);
}

void mode_pidt_deinit(){
	// Hardware de-initialization
	motors_deinit();

	// Periodic task de-initialization
	timer_unregister_callback(gwhe_id);
//	timer_unregister_callback(gsync_id);
//	timer_unregister_callback(gwhe_report_id);
	timer_unregister_callback(gspe_report_id);
}

void on_mode_pidt_mavlink_recv(mavlink_message_t *msg){
	switch(msg->msgid){
	case MAVLINK_MSG_ID_CMD_PARAMS:
		{
			mavlink_cmd_params_t cmd;
			mavlink_msg_cmd_params_decode(msg, &cmd);
			if(cmd.cmd_params == CMD_LOAD) load_pid_params();
			else if(cmd.cmd_params == CMD_SAVE) save_pid_params();
		}
		break;
	case MAVLINK_MSG_ID_PID_PARAMS:
		write_param(msg);
		break;
	case MAVLINK_MSG_ID_MOTOR_SPEED:
		{
			mavlink_motor_speed_t motor_speed_msg;
			mavlink_msg_motor_speed_decode(msg, &motor_speed_msg);
			gmotor0_speed = motor_speed_msg.motor_speed_0;
			gmotor1_speed = motor_speed_msg.motor_speed_1;
		}
		break;
	case MAVLINK_MSG_ID_CMD_VELOCITY:
		{
			mavlink_cmd_velocity_t cmd_velocity;
			mavlink_msg_cmd_velocity_decode(msg, &cmd_velocity);
			gmotor0_speed = (cmd_velocity.v - cmd_velocity.omega);
			gmotor1_speed = (cmd_velocity.v + cmd_velocity.omega);
			if(gmotor0_speed < -135) gmotor0_speed = -135;
			if(gmotor0_speed > 135) gmotor0_speed = 135;
			if(gmotor0_speed > -5 && gmotor0_speed < 5) {
				gmotor0_speed = 0;
				pid_reset(&params.pid[0]);
				pid_reset(&params.pid[1]);
				pid_reset(&params.pid[2]);
			}
			if(gmotor1_speed < -135) gmotor1_speed = -135;
			if(gmotor1_speed > 135) gmotor1_speed = 135;
			if(gmotor1_speed > -5 && gmotor1_speed < 5) {
				gmotor1_speed = 0;
				pid_reset(&params.pid[0]);
				pid_reset(&params.pid[1]);
				pid_reset(&params.pid[2]);
			}
		}
		break;
	default:
		break;
	}
}

#endif
