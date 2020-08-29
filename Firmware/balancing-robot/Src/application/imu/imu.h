/*
 * IMU.h
 *
 *  Created on: Oct 9, 2019
 *      Author: 16138
 */

#ifndef APPLICATION_IMU_IMU_H_
#define APPLICATION_IMU_IMU_H_

#include <application/imu/mpu6050/MPU6050.h>
#include <application/imu/mpu9250/MPU9250.h>
#include <application/timer/timer.h>
#include <stdbool.h>

typedef void (*connection_failed_cb_t)(void);

bool  imu_init(void);
bool  imu_deinit(void);
bool  imu_test_connection();
void  imu_set_failed_cb(connection_failed_cb_t connection_failed_cb);

float imu_get_roll(void);
float imu_get_pitch(void);
float imu_get_yaw(void);
float imu_get_tilt(void);
void  imu_get_gyro_raw(int16_t raw[3]);

#endif /* APPLICATION_IMU_IMU_H_ */
