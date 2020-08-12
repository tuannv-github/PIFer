/*
 * IMU.c
 *
 *  Created on: Oct 9, 2019
 *      Author: 16138
 */

#ifndef USERCODE_IMU_IMU_C_
#define USERCODE_IMU_IMU_C_

#include <math.h>
#include <UserCode/IMU/IMU.h>
#include "UserCode/Params/Params.h"
#include "UserCode/user_define.h"

static connection_failed_cb_t gconnection_failed_cb = 0;
static float roll;
static float pitch;
static timer_id_t gtimer_ID_imu_callback;
static int16_t motion_6[6];

static void imu_callback(uint8_t* ctx){
	mpu6050_get_motion(&motion_6[0], &motion_6[1], &motion_6[2], &motion_6[3], &motion_6[4], &motion_6[5]);
	float accel_roll  = atan2(motion_6[1], sqrt(motion_6[0]*motion_6[0] + motion_6[2]*motion_6[2]))*360/M_PI;
	float accel_pitch = atan2(-motion_6[0], sqrt(motion_6[1]*motion_6[1] + motion_6[2]*motion_6[2]))*360/M_PI;
	float roll_rate = ((motion_6[3]-params.gx_offset)*250.0/32768.0)/100.0;
	float pitch_rate = ((motion_6[4]-params.gy_offset)*250.0/32768.0)/100.0;
	roll = params.believe_in_gyro *(roll+roll_rate) + (1-params.believe_in_gyro)*accel_roll;
	pitch = params.believe_in_gyro *(pitch+pitch_rate) + (1-params.believe_in_gyro)*accel_pitch;
	if(isnan(roll)) roll = 0;
	if(isnan(pitch)) pitch = 0;
}

bool imu_init(void){
	MPU6050_init();
	mpu6050_set_full_scale_gyro_range(MPU6050_FS_SEL_250);
	mpu6050_set_full_scale_accel_range(MPU6050_AFS_SEL_2G);
	if(!MPU6050_test_connection() && gconnection_failed_cb != 0) {
		gconnection_failed_cb();
		return false;
	}
	gtimer_ID_imu_callback = timer_register_callback(imu_callback, IMU_PERIOD, 0, TIMER_MODE_REPEAT);
	return true;
}

bool  imu_deinit(void){
	timer_unregister_callback(gtimer_ID_imu_callback);
	return true;
}

bool imu_test_connection(){
	return MPU6050_test_connection();
}

float imu_get_roll(void){
	return roll;
}

float imu_get_pitch(void){
	return pitch;
}

float imu_get_yaw(void){
	return 0;
}

float imu_get_tilt(void){
#if TILT == 0
	return pitch;
#elif TILT == 1
	return roll;
#endif
}

void imu_set_failed_cb(connection_failed_cb_t connection_failed_cb){
	gconnection_failed_cb = connection_failed_cb;
}

void imu_get_gyro_raw(int16_t raw[3]){
	raw[0] = motion_6[3];
	raw[1] = motion_6[4];
	raw[2] = motion_6[5];
}



#endif /* USERCODE_IMU_IMU_C_ */
