/*
 * PID_tunning.h
 *
 *  Created on: Oct 12, 2019
 *      Author: 16138
 */

#ifndef USERCODE_MODE_PIDT_MODE_PIDT_H_
#define USERCODE_MODE_PIDT_MODE_PIDT_H_

#include "UserCode/Com/Com.h"
#include "UserCode/user_define.h"

void mode_pidt_init();
void mode_pidt_deinit();
void on_mode_pidt_mavlink_recv(mavlink_message_t *msg);

#endif /* USERCODE_MODE_PIDT_MODE_PIDT_H_ */
