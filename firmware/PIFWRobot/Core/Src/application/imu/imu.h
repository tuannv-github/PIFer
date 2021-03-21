/*
 * IMU.h
 *
 *  Created on: Oct 9, 2019
 *      Author: 16138
 */

#ifndef APPLICATION_IMU_IMU_H_
#define APPLICATION_IMU_IMU_H_

#include <application/imu/mpu9250/mpu9250.h>
#include <application/timer/timer.h>
#include <stdbool.h>


typedef void (*connection_failed_cb_t)(void);

int  imu_init(void);
int  imu_deinit(void);
int  imu_test_connection();

float imu_get_roll(void);
float imu_get_pitch(void);
float imu_get_yaw(void);
int imu_get_rpy(float rpy[3]);

int imu_get_gyro_raw(float raw[3]);
int imu_get_accel_raw(float raw[3]);
int imu_get_mag_raw(float raw[3]);

int imu_get_gyro_cab(float raw[3]);
int imu_get_accel_cab(float raw[3]);
int imu_get_mag_cab(float raw[3]);

#endif /* APPLICATION_IMU_IMU_H_ */
