/*
 * app_main.c
 *
 *  Created on: Oct 9, 2019
 *      Author: 16138
 */

#ifndef USERCODE_APP_MAIN_C_
#define USERCODE_APP_MAIN_C_

#include <application/app_main.h>

#include <application/mode/mode_hw/mode_hw.h>
#include <application/mode/mode_imu/mode_imu.h>
#include <application/mode/mode_pidt/mode_pidt.h>
#include <application/mode/mode_run/mode_run.h>
#include <application/neopixel/neopixel.h>

#include <application/params/params.h>
#include <application/buzzer/buzzer.h>
#include <application/mav/mav.h>

typedef void (*func_t)(void);
typedef struct{
	func_t 		 	init;
	func_t 		 	deinit;
	on_mav_recv_t 	on_mode_mav_recv;
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

	neopixel_init();

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
