/*
 * Mode_IMU.c
 *
 *  Created on: Oct 13, 2019
 *      Author: 16138
 */

#include "mode_imu.h"

TID(gtid_imu_raw);
TID(gtid_imu_result);

static void imu_raw_callback(void* ctx){
	mavlink_message_t msg;
	uint8_t gmav_send_buf[256];
	uint16_t len;
	float raw[9];

	imu_get_gyro_raw(raw);
	imu_get_accel_raw(&raw[3]);
	imu_get_mag_raw(&raw[6]);

	mavlink_msg_evt_gyro_accel_mag_raw_pack(0, 0, &msg, raw[0], raw[1], raw[2], raw[3], raw[4], raw[5], raw[6], raw[7], raw[8]);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	mav_send((char*)gmav_send_buf, len);

	float r = imu_get_roll();
	float p = imu_get_pitch();
	float y = imu_get_yaw();
	mavlink_msg_evt_rpy_pack(0,0,&msg,r,p,y);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	mav_send((char*)gmav_send_buf, len);
}

static void imu_result_callback(void* ctx){
	mavlink_message_t msg;
	uint8_t gmav_send_buf[256];
	uint16_t len;
	float raw[9];

	imu_get_gyro_raw(raw);
	imu_get_accel_raw(&raw[3]);
	imu_get_mag_raw(&raw[6]);

	raw[0] -= params.gx_offset;
	raw[1] -= params.gy_offset;
	raw[2] -= params.gz_offset;

	mavlink_msg_evt_gyro_accel_mag_calibrated_pack(0, 0, &msg, raw[0], raw[1], raw[2], raw[3], raw[4], raw[5], raw[6], raw[7], raw[8]);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	mav_send((char*)gmav_send_buf, len);

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
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	mav_send((char*)gmav_send_buf, len);
}

static int load_imu_params(){
	// Load parameters from non-volatile memory
	params_load();

	// Send parameters to GCS
	mavlink_message_t msg;
	uint8_t gmav_send_buf[256];
	uint16_t len;

	mavlink_msg_gyro_params_pack(0,0,&msg, params.gx_offset, params.gy_offset, params.gz_offset);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	mav_send((char*)gmav_send_buf, len);

	mavlink_msg_comp_filter_params_pack(0,0,&msg, params.tilt_type, params.tilt_offset, params.g_believe);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	mav_send((char*)gmav_send_buf, len);

	return 0;
}

static int save_imu_params(){
	// Save parameters to non-volatile memory
	params_save();

	return 0;
}

void mode_imu_init(){
	// Hardware initialization
	imu_init();

	// Periodic task initialization
	gtid_imu_raw = timer_register_callback(imu_raw_callback, IMU_RAW_RP_PERIOD, 0, TIMER_MODE_REPEAT);
	gtid_imu_result = timer_register_callback(imu_result_callback, IMU_RES_RP_PERIOD, 0, TIMER_MODE_REPEAT);
}

void mode_imu_deinit(){
	// Hardware de-initialization
	imu_deinit();

	// Periodic task initialization
	timer_unregister_callback(gtid_imu_raw);
	timer_unregister_callback(gtid_imu_result);
}

void on_mode_imu_mavlink_recv(mavlink_message_t *msg){
	switch(msg->msgid){
	case MAVLINK_MSG_ID_CMD_PARAMS:
		{
			mavlink_cmd_params_t cmd_msg;
			mavlink_msg_cmd_params_decode(msg, &cmd_msg);
			if(cmd_msg.cmd_params == CMD_LOAD) {
				if(load_imu_params() < 0) respond_error();
				else respond_ok();
			}
			else if(cmd_msg.cmd_params == CMD_SAVE) {
				if(save_imu_params() < 0) respond_error();
				else respond_ok();
			}
		}
	break;
	case MAVLINK_MSG_ID_GYRO_PARAMS:
	{
		mavlink_gyro_params_t gyro_params_msg;
		mavlink_msg_gyro_params_decode(msg,&gyro_params_msg);
		params.gx_offset = gyro_params_msg.gyro_offset_x;
		params.gy_offset = gyro_params_msg.gyro_offset_y;
		params.gz_offset = gyro_params_msg.gyro_offset_z;
		respond_ok();
	}
	break;
	case MAVLINK_MSG_ID_COMP_FILTER_PARAMS:
	{
		mavlink_comp_filter_params_t comp_filter_params_msg;
		mavlink_msg_comp_filter_params_decode(msg,&comp_filter_params_msg);
		params.tilt_type = comp_filter_params_msg.tilt_type;
		params.g_believe = comp_filter_params_msg.g_believe;
		params.tilt_offset = comp_filter_params_msg.tilt_offset;
		respond_ok();
	}
	break;
	default:
		break;
	}
}
