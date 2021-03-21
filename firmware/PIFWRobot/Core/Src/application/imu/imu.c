/*
 * IMU.c
 *
 *  Created on: Oct 9, 2019
 *      Author: 16138
 */

#ifndef USERCODE_IMU_IMU_C_
#define USERCODE_IMU_IMU_C_

#include <application/imu/imu.h>
#include <application/params/params.h>
#include <application/user_define.h>
#include <math.h>

#include "madgwick/madgwick.h"

static float roll;
static float pitch;
static float gam_raw[9];

TID(gtid_imu_callback);

static void imu_callback(void* ctx){
	if(mpu9250_get_accel_gyro(&gam_raw[0], &gam_raw[1], &gam_raw[2], &gam_raw[3], &gam_raw[4], &gam_raw[5]) < 0) return;
	if(mpu9250_get_mag(&gam_raw[6], &gam_raw[7], &gam_raw[8]) < 0) return;

	float accel_roll  = atan2(gam_raw[1], sqrt(gam_raw[0]*gam_raw[0] + gam_raw[2]*gam_raw[2]))*180.f/M_PI;
	float accel_pitch = atan2(-gam_raw[0], sqrt(gam_raw[1]*gam_raw[1] + gam_raw[2]*gam_raw[2]))*180.f/M_PI;
	float roll_rate = (gam_raw[3]-params.gx_bias)*0.001f*IMU_PERIOD_MS;
	float pitch_rate = (gam_raw[4]-params.gy_bias)*0.001f*IMU_PERIOD_MS;
	roll = params.g_believe*(roll+roll_rate) + (1-params.g_believe)*accel_roll;
	pitch = params.g_believe*(pitch+pitch_rate) + (1-params.g_believe)*accel_pitch;
	if(isnan(roll)) roll = 0;
	if(isnan(pitch)) pitch = 0;

	float gx = (gam_raw[3] - params.gx_bias)*M_PI/180.0f;
	float gy = (gam_raw[4] - params.gy_bias)*M_PI/180.0f;
	float gz = (gam_raw[5] - params.gz_bias)*M_PI/180.0f;
	float ax = gam_raw[0];
	float ay = gam_raw[1];
	float az = gam_raw[2];
	float mx = (gam_raw[6] - params.mx_bias)/params.mx_scale;
	float my = (gam_raw[7] - params.my_bias)/params.my_scale;
	float mz = (gam_raw[8] - params.mz_bias)/params.mz_scale;
	madwgick_gam_update(gx, gy, gz, ax, ay, az, mx, my, mz, 0.001f*IMU_PERIOD_MS);
}

int imu_init(void){
	mpu9250_init();
	gtid_imu_callback = timer_register_callback(imu_callback, IMU_PERIOD_MS, 0, TIMER_MODE_REPEAT);

	madwgick_init(params.madgwick_beta);

	return true;
}

int imu_deinit(void){
	timer_unregister_callback(gtid_imu_callback);
	return true;
}

int imu_test_connection(){
	return mpu9250_test();
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

int imu_get_accel_raw(float raw[3]){
	raw[0] = gam_raw[0];
	raw[1] = gam_raw[1];
	raw[2] = gam_raw[2];
	return 0;
}

int imu_get_gyro_raw(float raw[3]){
	raw[0] = gam_raw[3];
	raw[1] = gam_raw[4];
	raw[2] = gam_raw[5];
	return 0;
}

int imu_get_mag_raw(float raw[3]){
	raw[0] = gam_raw[6];
	raw[1] = gam_raw[7];
	raw[2] = gam_raw[8];
	return 0;
}

#endif /* USERCODE_IMU_IMU_C_ */
