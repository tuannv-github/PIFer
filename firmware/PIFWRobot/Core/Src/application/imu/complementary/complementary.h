/*
 * complementary.h
 *
 *  Created on: Mar 22, 2021
 *      Author: tuannv
 */

#ifndef SRC_APPLICATION_IMU_COMPLEMENTARY_COMPLEMENTARY_H_
#define SRC_APPLICATION_IMU_COMPLEMENTARY_COMPLEMENTARY_H_

#include <application/params/params.h>

void complementary_init();
void complementary_update(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz, float dt);
void complementary_get_q(float q[4]);

#endif /* SRC_APPLICATION_IMU_COMPLEMENTARY_COMPLEMENTARY_H_ */
