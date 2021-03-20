/*
 * Mode_Basic.c
 *
 *  Created on: Oct 10, 2019
 *      Author: 16138
 */

#include <math.h>

#include "mode_run.h"

#ifdef ROBOT_MODEL_TWO_WHEELS

typedef struct{
	float vx;
	float vy;
	float omega;
	uint8_t cnt;
	bool is_dir_change;
}cmd_velocity_t;

TID(gtid_tilt_controller);
TID(gtid_vel_controller);
TID(gtid_imu_tilt);

static cmd_velocity_t gcmd_velocity;
static float tilt_setpoint;

static uint32_t g_left = 0;
static uint32_t g_right = 0;
static uint32_t g_yaw = 0;

static void tilt_controller_callback(void* ctx){
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

	motors_setspeed(MOTOR_0, speed + (float)gcmd_velocity.omega*OMEGA_COEFF);
	motors_setspeed(MOTOR_1, speed - (float)gcmd_velocity.omega*OMEGA_COEFF);
}

static void vel_controller_callback(void *ctx){
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

static void tilt_report_callback(void *ctx){
	mavlink_message_t msg;
	uint8_t mav_send_buf[64];
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
	mav_send((char*)mav_send_buf, len);
}

void mode_run_init(){
	motors_init();
	enc_init();
	imu_init();

	params.pid[1].maxIPart = 5;
	params.pid[1].minIpart = -5;

	params.pid[1].maxDPart = 5;
	params.pid[1].minDpart = -5;

	params.pid[1].maxOut = 5;
	params.pid[1].minOut = -5;

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

#if ENABLE_NEOPIXEL == 1
static timer_id_t g_neopixel_timeout_timer_id = TID_INVALID;
static void neopixel_change_app_idle(void *context){
	neopixel_set_app(NEOPIXEL_APP_RAINBOW);
}
#endif

void on_mode_run_mavlink_recv(mavlink_message_t *msg){
	switch(msg->msgid){
	case MAVLINK_MSG_ID_CMD_VELOCITY:
		{
			mavlink_cmd_velocity_t cmd_velocity;
			mavlink_msg_cmd_velocity_decode(msg, &cmd_velocity);

			if(cmd_velocity.v > -0.15 && cmd_velocity.v < 0.15) cmd_velocity.v = 0;
			if(cmd_velocity.v*gcmd_velocity.vx <= 0) gcmd_velocity.is_dir_change = true;
			gcmd_velocity.vx += 0.5*(cmd_velocity.v-gcmd_velocity.vx);
			if(gcmd_velocity.vx > 1) gcmd_velocity.vx=1;
			if(gcmd_velocity.vx < -1) gcmd_velocity.vx=-1;

			if(cmd_velocity.omega > -0.15 && cmd_velocity.omega < 0.15) cmd_velocity.omega=0;
			gcmd_velocity.omega = cmd_velocity.omega;
			if(gcmd_velocity.omega > 1) gcmd_velocity.omega=1;
			if(gcmd_velocity.omega < -1) gcmd_velocity.omega=-1;

			gcmd_velocity.cnt = (CONTROL_TIMEOUT_MS/VEL_CONTROLLER_PERIOD);

#if ENABLE_NEOPIXEL == 1
			float a = gcmd_velocity.vx > 0 ? gcmd_velocity.vx : -gcmd_velocity.vx;
			float b = gcmd_velocity.omega > 0 ? gcmd_velocity.omega : -gcmd_velocity.omega;
			if(a < 0.1f && b < 0.1f){
				if(g_neopixel_timeout_timer_id == TID_INVALID)
					g_neopixel_timeout_timer_id = timer_register_callback(neopixel_change_app_idle, 2000, NULL, TIMER_MODE_ONE_SHOT);
			}
			else if(g_neopixel_timeout_timer_id != TID_INVALID){
				timer_unregister_callback(g_neopixel_timeout_timer_id);
				neopixel_set_app(NEOPIXEL_APP_SELFBALACING);
				g_neopixel_timeout_timer_id = TID_INVALID;
			}
			neopixel_app_self_balancing_set(gcmd_velocity.vx*4.0f, gcmd_velocity.omega*4.0f);
#endif
		}
		break;
	case MAVLINK_MSG_ID_DISTANCE:
		{
			mavlink_distance_t distance;
			mavlink_msg_distance_decode(msg, &distance);

			mavlink_message_t cm_msg_mav;
			uint8_t mav_send_buf[64];
//			mavlink_msg_control_measurement_pack(0, 0, &cm_msg_mav, left, right, rx, ry, range, yaw);
			uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &cm_msg_mav);
			mav_send((char*)mav_send_buf, len);
		}
		break;
	}
}

#endif
