/*
 * Mode_HW.c
 *
 *  Created on: Dec 18, 2019
 *      Author: 16138
 */
#include "Mode_HW.h"
#include "UserCode/Timer/timer.h"
#include "UserCode/user_define.h"
#include "UserCode/Motors/Motors.h"
#include "UserCode/Encoder/Encoder.h"
#include "UserCode/Params/Params.h"

timer_id_t gtimerid_speed_report;

static void speed_report_callback(uint8_t* ctx){
	mavlink_message_t speed_msg;
	uint8_t gmav_send_buf[256];

	int32_t motor0_enc= enc_read(MOTOR_0);
	int32_t motor1_enc = enc_read(MOTOR_1);

	mavlink_msg_motor_speed_pack(0,0,&speed_msg,motor0_enc,motor1_enc);
	uint16_t len = mavlink_msg_to_send_buffer(gmav_send_buf, &speed_msg);
	com_send(gmav_send_buf, len);
}

static void on_hw_cmd(mavlink_message_t *msg){
	mavlink_hw_params_t hw_params_msg;
	mavlink_msg_hw_params_decode(msg,&hw_params_msg);

	if(hw_params_msg.motor0_invert == MAV_TRUE){
		params.motor0_invert = true;
	}else params.motor0_invert = false;
	if(hw_params_msg.motor1_invert == MAV_TRUE){
		params.motor1_invert = true;
	}else params.motor1_invert = false;
	motors_init();

	if(hw_params_msg.encoder0_invert == MAV_TRUE){
		params.encoder0_invert = true;
	}else params.encoder0_invert = false;
	if(hw_params_msg.encoder1_invert == MAV_TRUE){
		params.encoder1_invert = true;
	}else params.encoder1_invert = false;

	if(hw_params_msg.encoder_exchange == MAV_TRUE){
		params.encoder_exchange = true;
	}else params.encoder_exchange = false;
	enc_init();

	respond_ok();
}

static void load_params(){
	params_load();

	mavlink_message_t hw_msg;
	uint8_t gmav_send_buf[256];

	bool_t motor0_invert = params.motor0_invert == true ? MAV_TRUE : MAV_FALSE;
	bool_t motor1_invert = params.motor1_invert == true ? MAV_TRUE : MAV_FALSE;
	bool_t encoder0_invert = params.encoder0_invert == true ? MAV_TRUE : MAV_FALSE;
	bool_t encoder1_invert = params.encoder1_invert == true ? MAV_TRUE : MAV_FALSE;
	bool_t encoder_ex = params.encoder_exchange == true ? MAV_TRUE : MAV_FALSE;

	mavlink_msg_hw_params_pack(0,0,&hw_msg,motor0_invert,motor1_invert,encoder0_invert,encoder1_invert,encoder_ex);
	uint16_t len = mavlink_msg_to_send_buffer(gmav_send_buf, &hw_msg);
	com_send(gmav_send_buf, len);
}

static void save_params(){
	params_save();
	respond_ok();
}

void mode_hw_init(){
	// Hardware initialization
	motors_init();

	// Periodic task initialization
	gtimerid_speed_report = timer_register_callback(speed_report_callback, ENC_RP_PERIOD, 0, TIMER_MODE_REPEAT);
}

void mode_hw_deinit(){
	// Hardware de-initialization
	motors_deinit();

	// Background task de-initialization
	timer_unregister_callback(gtimerid_speed_report);
}

void on_mode_hw_mavlink_recv(mavlink_message_t *msg){
	switch(msg->msgid){
	case MAVLINK_MSG_ID_MOTOR_SPEED:
		{
			mavlink_motor_speed_t motor_speed_msg;
			mavlink_msg_motor_speed_decode(msg, &motor_speed_msg);
			motors_setspeed(MOTOR_0, motor_speed_msg.motor_speed_0);
			motors_setspeed(MOTOR_1, motor_speed_msg.motor_speed_1);
		}
		break;
	case MAVLINK_MSG_ID_CMD_PARAMS:
		{
			mavlink_cmd_params_t cmd_params_msg;
			mavlink_msg_cmd_params_decode(msg,&cmd_params_msg);
			if(cmd_params_msg.cmd_params == CMD_LOAD) load_params();
			else if(cmd_params_msg.cmd_params == CMD_SAVE) save_params();
		}
	break;
	case MAVLINK_MSG_ID_HW_PARAMS:
		on_hw_cmd(msg);
		break;
	default:
		break;
	}
}
