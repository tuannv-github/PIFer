/*
 * Mode_IMU.c
 *
 *  Created on: Oct 13, 2019
 *      Author: 16138
 */

#include "mode_imu.h"

TID(gtid_IMU_Raw);

static void imu_raw_callback(uint8_t* ctx){
	mavlink_message_t msg;
	uint8_t gmav_send_buf[256];

	float raw[3];
	uint16_t len;

	imu_get_accel_raw(raw);
	mavlink_msg_evt_accel_raw_pack(0,0,&msg,raw[0],raw[1],raw[2]);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	com_send(gmav_send_buf, len);

	imu_get_gyro_raw(raw);
	mavlink_msg_evt_gyro_raw_pack(0,0,&msg,raw[0],raw[1],raw[2]);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	com_send(gmav_send_buf, len);

	imu_get_mag_raw(raw);
	mavlink_msg_evt_mag_raw_pack(0,0,&msg,raw[0],raw[1],raw[2]);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	com_send(gmav_send_buf, len);

	float r = imu_get_roll();
	float p = imu_get_pitch();
	float y = imu_get_yaw();
	mavlink_msg_evt_rpy_pack(0,0,&msg,r,p,y);
	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	com_send(gmav_send_buf, len);
}

static int load_imu_params(){
	// Load parameters from non-volatile memory
	params_load();

	// Send parameters to GCS
	mavlink_message_t msg;
	uint8_t gmav_send_buf[256];
	mavlink_msg_imu_params_pack(0,0,&msg,
			params.gx_offset, params.gy_offset, params.gz_offset,
			params.mx_offset, params.my_offset, params.mz_offset,
			params.mx_scale, params.my_scale, params.mz_scale,
			params.angle_adjusted, params.believe_in_gyro);
	uint16_t len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	com_send(gmav_send_buf, len);

	return 0;
}

static int save_imu_params(){
	// Save parameters to non-volatile memory
	params_save();

	return 0;
}

static int write_param(mavlink_message_t *msg){
	// Change current parameters according to GCS
	mavlink_imu_params_t imu_params_msg;
	mavlink_msg_imu_params_decode(msg,&imu_params_msg);
	params.gx_offset = imu_params_msg.gyro_offset_x;
	params.gy_offset = imu_params_msg.gyro_offset_y;
	params.gz_offset = imu_params_msg.gyro_offset_z;
	params.believe_in_gyro = imu_params_msg.believe_in_gyro;
	params.angle_adjusted = imu_params_msg.angle_adjusted;

	return 0;
}

void mode_imu_init(){
	// Hardware initialization
	imu_init();

	// Periodic task initialization
	gtid_IMU_Raw = timer_register_callback(imu_raw_callback, IMU_RAW_RP_PERIOD, 0, TIMER_MODE_REPEAT);
}

void mode_imu_deinit(){
	// Hardware de-initialization
	imu_deinit();

	// Periodic task initialization
	timer_unregister_callback(gtid_IMU_Raw);
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
	case MAVLINK_MSG_ID_IMU_PARAMS:
		if(write_param(msg) < 0) respond_error();
		else respond_ok();
		break;
	default:
		break;
	}
}
