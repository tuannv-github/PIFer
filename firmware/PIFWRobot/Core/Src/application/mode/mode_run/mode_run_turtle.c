/*
 * Mode_RUN.c
 *
 *  Created on: Oct 12, 2019
 *      Author: 16138
 */

#include "mode_run.h"

#if ROBOT_MODEL==1

void mode_run_init(){
	// Hardware initialization
	stepmotor_init();

	// Periodic task initialization
}

void mode_run_deinit(){
	// Hardware de-initialization
}

void on_mode_run_mavlink_recv(mavlink_message_t *msg){
	switch(msg->msgid){
	case MAVLINK_MSG_ID_CMD_VELOCITY:
		{
			mavlink_cmd_velocity_t cmd_velocity;
			mavlink_msg_cmd_velocity_decode(msg, &cmd_velocity);
//			float gmotor0_speed = (cmd_velocity.v - cmd_velocity.omega);
//			float gmotor1_speed = (cmd_velocity.v + cmd_velocity.omega);
			stepmotor_set_speed(cmd_velocity.v*LINEAR_SPEED_MAX,  cmd_velocity.omega*ANGULAR_SPEED_MAX);
		}
		break;
	default:
		break;
	}
}

#endif
