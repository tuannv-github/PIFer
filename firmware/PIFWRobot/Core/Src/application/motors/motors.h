/*
 * Motors.h
 *
 *  Created on: Oct 9, 2019
 *      Author: 16138
 */

#ifndef APPLICATION_MOTORS_MOTORS_H_
#define APPLICATION_MOTORS_MOTORS_H_

#include <application/user_define.h>
#include <stdbool.h>

#include "common.h"

void motors_init();
void motors_deinit();
void motors_setspeed(motors_t motor, int32_t speed); // Speed range -1000, 1000

#endif /* APPLICATION_MOTORS_MOTORS_H_ */
