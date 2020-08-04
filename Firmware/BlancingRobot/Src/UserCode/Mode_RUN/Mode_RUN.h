/*
 * Mode_Basic.h
 *
 *  Created on: Oct 10, 2019
 *      Author: 16138
 */

#ifndef USERCODE_MODE_RUN_MODE_RUN_H_
#define USERCODE_MODE_RUN_MODE_RUN_H_

#include "UserCode/Com/Com.h"
#include "UserCode/user_define.h"

void mode_run_init();
void mode_run_deinit();
void on_mode_run_mavlink_recv(mavlink_message_t *msg);

#endif /* USERCODE_MODE_RUN_MODE_RUN_H_ */
