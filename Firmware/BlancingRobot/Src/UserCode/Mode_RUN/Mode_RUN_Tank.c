/*
 * Mode_RUN.c
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

void mode_run_init(){
	// Hardware initialization
	motors_init();

	pid_reset(&params.pid[0]);
	pid_reset(&params.pid[1]);
	pid_reset(&params.pid[2]);

	// Periodic task initialization
	gwhe_id = timer_register_callback(wheel_callback, WHEEL_PERIOD, 0, TIMER_MODE_REPEAT);
//	gsync_id = timer_register_callback(sync_callback, SYNC_PERIOD, 0, TIMER_MODE_REPEAT);
}

void mode_run_deinit(){
	// Hardware de-initialization
	motors_deinit();

	// Periodic task de-initialization
	timer_unregister_callback(gwhe_id);
//	timer_unregister_callback(gsync_id);
}

void on_mode_run_mavlink_recv(mavlink_message_t *msg){
	switch(msg->msgid){
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
