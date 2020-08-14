/*
 * Mode_HW.h
 *
 *  Created on: Dec 18, 2019
 *      Author: 16138
 */

#ifndef USERCODE_MODE_HW_MODE_HW_H_
#define USERCODE_MODE_HW_MODE_HW_H_

#include "UserCode/Com/Com.h"

void mode_hw_init();
void mode_hw_deinit();
void on_mode_hw_mavlink_recv(mavlink_message_t *msg);

#endif /* USERCODE_MODE_HW_MODE_HW_H_ */
