/*
 * Mode_IMU.h
 *
 *  Created on: Oct 13, 2019
 *      Author: 16138
 */

#ifndef USERCODE_MODE_IMU_MODE_IMU_H_
#define USERCODE_MODE_IMU_MODE_IMU_H_

#include "UserCode/Com/Com.h"
#include "UserCode/user_define.h"

void mode_imu_init();
void mode_imu_deinit();
void on_mode_imu_mavlink_recv(mavlink_message_t *msg);

#endif /* USERCODE_MODE_IMU_MODE_IMU_H_ */
