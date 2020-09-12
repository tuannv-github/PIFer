/*
 * Mode_Basic.c
 *
 *  Created on: Oct 10, 2019
 *      Author: 16138
 */

#include "mode_run.h"

#ifdef ROBOT_MODEL_TWO_WHEELS

typedef struct{
	float vx;
	float vy;
	float omega;
	uint8_t cnt;
}cmd_velocity_t;

static cmd_velocity_t gcmd_velocity;

TID(gtid_tilt_controller);
TID(gtid_vel_controller);
TID(gtid_imu_tilt);

static float tilt_setpoint;

static void tilt_controller_callback(uint8_t* ctx){
	float tilt;
	switch(params.tilt_type){
	case ROLL:
		tilt = imu_get_roll();
		break;
	case PITCH:
		tilt = imu_get_pitch();
		break;
	default:
		tilt = 0;
	}
	tilt -= params.tilt_offset;

	float speed = pid_compute(&params.pid[0], tilt_setpoint, tilt, 0.001f*TILT_CONTROLLER_PERIOD);
	if(tilt > 70 || tilt < -70) {
		speed = 0;
		pid_reset(&params.pid[0]);
		pid_reset(&params.pid[1]);
	}
	motors_setspeed(MOTOR_0, speed - (float)gcmd_velocity.omega*OMEGA_COEFF);
	motors_setspeed(MOTOR_1, speed + (float)gcmd_velocity.omega*OMEGA_COEFF);
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

	tilt_setpoint = pid_compute(&params.pid[1], gcmd_velocity.vx*VELOC_COEFF, direction, 0.001f*VEL_CONTROLLER_PERIOD);
}

static void tilt_report_callback(uint8_t *ctx){
	mavlink_message_t msg;
	uint8_t mav_send_buf[256];

	float tilt;
	switch(params.tilt_type){
	case ROLL:
		tilt = imu_get_roll();
		break;
	case PITCH:
		tilt = imu_get_pitch();
		break;
	default:
		tilt = 0;
	}
	tilt -= params.tilt_offset;

	mavlink_msg_evt_tilt_pack(0,0,&msg,tilt);
	uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
	com_send(mav_send_buf, len);
}

void mode_run_init(){
	// Hardware initialization
	motors_init();
	enc_init();
	imu_init();

	params.pid[1].maxIPart = 5;
	params.pid[1].minIpart = -5;

	pid_reset(&params.pid[0]);
	pid_reset(&params.pid[1]);
	pid_reset(&params.pid[2]);

	// Periodic task initialization
	gtid_tilt_controller = timer_register_callback(tilt_controller_callback, TILT_CONTROLLER_PERIOD, 0, TIMER_MODE_REPEAT);
	gtid_vel_controller = timer_register_callback(vel_controller_callback, VEL_CONTROLLER_PERIOD, 0, TIMER_MODE_REPEAT);
	gtid_imu_tilt = timer_register_callback(tilt_report_callback, TILT_REPORT_PERIOD, 0, TIMER_MODE_REPEAT);
}

void mode_run_deinit(){
	// Hardware de-initialization
	motors_deinit();
	enc_deinit();
	imu_deinit();

	// Periodic task de-initialization
	timer_unregister_callback(gtid_tilt_controller);
	timer_unregister_callback(gtid_vel_controller);
	timer_unregister_callback(gtid_imu_tilt);
}

void on_mode_run_mavlink_recv(mavlink_message_t *msg){
	switch(msg->msgid){
	case MAVLINK_MSG_ID_CMD_VELOCITY:
		{
			mavlink_cmd_velocity_t cmd_velocity;
			mavlink_msg_cmd_velocity_decode(msg, &cmd_velocity);

			gcmd_velocity.vx = cmd_velocity.v;
			if(gcmd_velocity.vx > 1) gcmd_velocity.vx=1;
			if(gcmd_velocity.vx < -1) gcmd_velocity.vx=-1;

			gcmd_velocity.omega = cmd_velocity.omega;
			if(gcmd_velocity.omega > 1) gcmd_velocity.omega=1;
			if(gcmd_velocity.omega < -1) gcmd_velocity.omega=-1;

			gcmd_velocity.cnt = (CONTROL_TIMEOUT_MS/VEL_CONTROLLER_PERIOD);
		}
		break;
	default:
		break;
	}
}

#endif
