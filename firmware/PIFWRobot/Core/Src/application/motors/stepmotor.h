/*
 * stepmotor.h
 *
 *  Created on: Mar 18, 2021
 *      Author: PC
 */

#ifndef USER_MOTOR_STEPMOTOR_H_
#define USER_MOTOR_STEPMOTOR_H_

#include <application/user_define.h>
#include "common.h"

void stepmotor_init();
void stepmotor_vw(float v, float w);
void stepmotor_speed(motors_t motor, float speed);

#endif /* USER_MOTOR_STEPMOTOR_H_ */
