/*
 * Motors.h
 *
 *  Created on: Oct 9, 2019
 *      Author: 16138
 */

#ifndef USERCODE_MOTORS_MOTORS_H_
#define USERCODE_MOTORS_MOTORS_H_

#include <stdbool.h>
#include "UserCode/user_define.h"

typedef enum{
	MOTOR_0,
	MOTOR_1
}motors_t;

void motors_init();
void motors_deinit();
void motors_setspeed(motors_t motor, int32_t speed); // Speed range -1000, 1000

#endif /* USERCODE_MOTORS_MOTORS_H_ */
