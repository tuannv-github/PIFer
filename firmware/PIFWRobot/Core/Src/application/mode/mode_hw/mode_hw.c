/*
 * Mode_HW.c
 *
 *  Created on: Dec 18, 2019
 *      Author: 16138
 */

#include "mode_hw.h"

timer_id_t gtimerid_speed_report;

#if MOTOR_TYPE==0
static void speed_report_callback(void* ctx){
	mavlink_message_t msg;

	int32_t motor0_enc = enc_read(MOTOR_0);
	int32_t motor1_enc = enc_read(MOTOR_1);

	mavlink_msg_motor_speed_pack(0,0,&msg,motor0_enc,motor1_enc);
	mav_send_msg(&msg);
}
#endif

static int motor_speed(mavlink_message_t *msg){
#if MOTOR_TYPE==0
	mavlink_motor_speed_t motor_speed_msg;
	mavlink_msg_motor_speed_decode(msg, &motor_speed_msg);
	motors_setspeed(MOTOR_0, motor_speed_msg.motor_speed_0);
	motors_setspeed(MOTOR_1, motor_speed_msg.motor_speed_1);
#elif MOTOR_TYPE==1
	mavlink_motor_speed_step_t speed_step_msg;
	mavlink_msg_motor_speed_step_decode(msg, &speed_step_msg);
	stepmotor_speed(MOTOR_0, speed_step_msg.motor_0);
	stepmotor_speed(MOTOR_1, speed_step_msg.motor_1);
#endif

	return 0;
}

static int hw_params(mavlink_message_t *msg){
	mavlink_hw_params_t hw_params_msg;
	mavlink_msg_hw_params_decode(msg,&hw_params_msg);

	if(hw_params_msg.motor0_invert == MAV_TRUE){
		params.motor0_invert = true;
	}else params.motor0_invert = false;
	if(hw_params_msg.motor1_invert == MAV_TRUE){
		params.motor1_invert = true;
	}else params.motor1_invert = false;

	if(hw_params_msg.encoder0_invert == MAV_TRUE){
		params.encoder0_invert = true;
	}else params.encoder0_invert = false;
	if(hw_params_msg.encoder1_invert == MAV_TRUE){
		params.encoder1_invert = true;
	}else params.encoder1_invert = false;

#if MOTOR_TYPE==0
	if(hw_params_msg.encoder_exchange == MAV_TRUE){
		params.encoder_exchange = true;
	}else params.encoder_exchange = false;

	params.motor0_pos_deadband = hw_params_msg.motor0_pos_deadband;
	params.motor0_neg_deadband = hw_params_msg.motor0_neg_deadband;
	params.motor1_pos_deadband = hw_params_msg.motor1_pos_deadband;
	params.motor1_neg_deadband = hw_params_msg.motor1_neg_deadband;

	motors_deinit();
	motors_init();
	enc_deinit();
	enc_init();
#endif
	return 0;
}

static int load_params(){
	params_load();

	mavlink_message_t msg;

#if MOTOR_TYPE==0
	motor_type_t motor_type = MOTOR_TYPE_DC;
#elif MOTOR_TYPE==1
	motor_type_t motor_type = MOTOR_TYPE_STEP;
#endif

	bool_t motor0_invert = params.motor0_invert == true ? MAV_TRUE : MAV_FALSE;
	bool_t motor1_invert = params.motor1_invert == true ? MAV_TRUE : MAV_FALSE;
	bool_t encoder0_invert = params.encoder0_invert == true ? MAV_TRUE : MAV_FALSE;
	bool_t encoder1_invert = params.encoder1_invert == true ? MAV_TRUE : MAV_FALSE;
	bool_t encoder_ex = params.encoder_exchange == true ? MAV_TRUE : MAV_FALSE;

	mavlink_msg_hw_params_pack(0,0,&msg, motor_type, motor0_invert,motor1_invert,encoder0_invert,encoder1_invert,encoder_ex,
			params.motor0_pos_deadband, params.motor0_neg_deadband, params.motor1_pos_deadband, params.motor1_neg_deadband);
	mav_send_msg(&msg);

	return 0;
}

static int save_params(){
	params_save();
	return 0;
}

void mode_hw_init(){
	// Hardware initialization
#if MOTOR_TYPE==0
	motors_init();
	enc_init();
#elif MOTOR_TYPE==1
	stepmotor_init();
#endif

	// Periodic task initialization
#if MOTOR_TYPE==0
	gtimerid_speed_report = timer_register_callback(speed_report_callback, ENC_RP_PERIOD, 0, TIMER_MODE_REPEAT);
#endif

}

void mode_hw_deinit(){
	// Hardware de-initialization
#if MOTOR_TYPE==0
	motors_deinit();
	enc_deinit();
#endif

#if MOTOR_TYPE==0
	// Background task de-initialization
	timer_unregister_callback(gtimerid_speed_report);
#endif
}

void on_mode_hw_mavlink_recv(mavlink_message_t *msg){
	switch(msg->msgid){
	case MAVLINK_MSG_ID_MOTOR_SPEED:
		if(motor_speed(msg) != 0) respond_error();
		else respond_ok();
		break;
	case MAVLINK_MSG_ID_MOTOR_SPEED_STEP:
		if(motor_speed(msg) != 0) respond_error();
		else respond_ok();
		break;
	case MAVLINK_MSG_ID_CMD_PARAMS:
		{
			mavlink_cmd_params_t cmd_params_msg;
			mavlink_msg_cmd_params_decode(msg,&cmd_params_msg);
			if(cmd_params_msg.cmd_params == CMD_LOAD){
				if(load_params() != 0) respond_error();
				else respond_ok();
			}

			else if(cmd_params_msg.cmd_params == CMD_SAVE){
				if(save_params() != 0) respond_error();
				else respond_ok();
			}
		}
	break;
	case MAVLINK_MSG_ID_HW_PARAMS:
		if(hw_params(msg) != 0) respond_error();
		else respond_ok();
		break;
	default:
		break;
	}
}
