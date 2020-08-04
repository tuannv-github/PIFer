/*
 * Mode_IMU.c
 *
 *  Created on: Oct 13, 2019
 *      Author: 16138
 */

#include "UserCode/user_define.h"

#ifdef IMU_MPU6050

#include "Mode_IMU.h"
#include <UserCode/IMU/IMU.h>
#include "UserCode/Timer/timer.h"
#include "UserCode/Params/Params.h"
#include "UserCode/Com/Com.h"

static timer_id_t gtimer_ID_IMU_Raw;

static void imu_raw_callback(uint8_t* ctx){
//	mavlink_message_t msg;
//	uint8_t gmav_send_buf[256];
//
//	int16_t raw[3];
//	imu_get_gyro_raw(raw);
//	mavlink_msg_evt_gyro_raw_pack(0,0,&msg,raw[0],raw[1],raw[2]);
//	uint16_t len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
//	com_send(gmav_send_buf, len);
//
//	mavlink_msg_evt_tilt_pack(0,0,&msg,imu_get_tilt());
//	len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
//	com_send(gmav_send_buf, len);
}

static void load_imu_params(){
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
}

static void save_imu_params(){
	// Save parameters to non-volatile memory
	params_save();

	// Respond a successful operation
	respond_ok();
}

static void write_param(mavlink_message_t *msg){
	// Change current parameters according to GCS
	mavlink_imu_params_t imu_params_msg;
	mavlink_msg_imu_params_decode(msg,&imu_params_msg);
	params.gx_offset = imu_params_msg.gyro_offset_x;
	params.gy_offset = imu_params_msg.gyro_offset_y;
	params.gz_offset = imu_params_msg.gyro_offset_z;
	params.believe_in_gyro = imu_params_msg.believe_in_gyro;
	params.angle_adjusted = imu_params_msg.angle_adjusted;

	// Respond a successful operation
	respond_ok();
}

void mode_imu_init(){
	// Hardware initialization
	imu_init();

	// Periodic task initialization
	gtimer_ID_IMU_Raw = timer_register_callback(imu_raw_callback, IMU_RAW_RP_PERIOD, 0, TIMER_MODE_REPEAT);
}

void mode_imu_deinit(){
	// Hardware de-initialization
	imu_deinit();

	// Periodic task initialization
	timer_unregister_callback(gtimer_ID_IMU_Raw);
}

void on_mode_imu_mavlink_recv(mavlink_message_t *msg){
	switch(msg->msgid){
	case MAVLINK_MSG_ID_CMD_PARAMS:
		{
			mavlink_cmd_params_t cmd_msg;
			mavlink_msg_cmd_params_decode(msg, &cmd_msg);
			if(cmd_msg.cmd_params == CMD_LOAD) load_imu_params();
			else if(cmd_msg.cmd_params == CMD_SAVE) save_imu_params();
		}
		break;
	case MAVLINK_MSG_ID_IMU_PARAMS:
		write_param(msg);
		break;
	default:
		break;
	}
}

#endif
