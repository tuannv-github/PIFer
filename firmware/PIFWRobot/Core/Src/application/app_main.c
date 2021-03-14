/*
 * app_main.c
 *
 *  Created on: Oct 9, 2019
 *      Author: 16138
 */

#ifndef USERCODE_APP_MAIN_C_
#define USERCODE_APP_MAIN_C_

#include <application/app_main.h>

typedef void (*func_t)(void);
typedef struct{
	func_t 		 	init;			// Save mode init function pointer
	func_t 		 	deinit;		// Save mode de-init function pointer
	on_mav_recv_t 	on_mode_mav_recv;	// Save mode msg receive function pointer
}app_t;

void app_reset(app_t *app, func_t init, func_t deinit, on_mav_recv_t on_mav_recv){
	app->init = init;
	app->deinit = deinit;
	app->on_mode_mav_recv = on_mav_recv;
}
void app_run_init(app_t *app){
	app->init();
}
void app_run_deinit(app_t *app){
	app->deinit();
}
void app_run_on_msg_recv(app_t *app, mavlink_message_t *msg){
	app->on_mode_mav_recv(msg);
}

void LED_Callback(void *context)
{
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

static app_t g_app;

static void on_mavlink_recv(mavlink_message_t *msg){

	// Check if message is a change mode command. If not, send message to higher level layer
	if(msg->msgid == MAVLINK_MSG_ID_CMD_CHANGE_MODE){

		// De-initialize current mode
		app_run_deinit(&g_app);

		// Parse change mode message
		mavlink_cmd_change_mode_t cmd_change_mode;
		mavlink_msg_cmd_change_mode_decode(msg, &cmd_change_mode);

		// Prepare for new mode
		if(cmd_change_mode.cmd_change_mode == MODE_RUN){
			app_reset(&g_app, mode_run_init, mode_run_deinit, on_mode_run_mavlink_recv);
		}
		else if(cmd_change_mode.cmd_change_mode == MODE_HW){
			app_reset(&g_app, mode_hw_init, mode_hw_deinit, on_mode_hw_mavlink_recv);
		}
		else if(cmd_change_mode.cmd_change_mode == MODE_IMU){
			app_reset(&g_app, mode_imu_init, mode_imu_deinit, on_mode_imu_mavlink_recv);
		}
		else if(cmd_change_mode.cmd_change_mode == MODE_PIDT_TW || cmd_change_mode.cmd_change_mode == MODE_PIDT_TA){
			app_reset(&g_app, mode_pidt_init, mode_pidt_deinit, on_mode_pidt_mavlink_recv);
		}

		// Initialize new mode
		app_run_init(&g_app);

		// Response OK
		respond_ok();
	}
	else{
		app_run_on_msg_recv(&g_app, msg);
	}
}

void app_main(){

	buzzer_sys_start();

	timer_init();
	timer_register_callback(LED_Callback, 500, 0, TIMER_MODE_REPEAT);

	// Load parameters from non-volatile memory
	params_load();

	// Run default mode
	app_reset(&g_app, mode_run_init, mode_run_deinit, on_mode_run_mavlink_recv);
	app_run_init(&g_app);

	// Initialize communication
	mav_init();
	mav_set_on_mav_recv(on_mavlink_recv);
}

#endif /* USERCODE_APP_MAIN_C_ */
