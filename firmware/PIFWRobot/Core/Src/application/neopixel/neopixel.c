/*
 * neopixel.c
 *
 *  Created on: Mar 15, 2021
 *      Author: tuannv
 */
#include "neopixel.h"

#include <application/timer/timer.h>
#include "abs/common.h"
#include "config.h"

#include <application/neopixel/app_loading/loading.h>
#include <application/neopixel/app_rainbow/rainbow.h>
#include <application/neopixel/app_selfbalancing/selfbalancing.h>

static timer_id_t g_neopixel_timer_id = TID_INVALID;
static neopixel_update_func_t g_neopixel_update_func = 0;

void neopixel_set_app(neoxpixel_app_t neoxpixel_app);

static void neopixel_update_callback(void *context)
{
	if(g_neopixel_update_func != 0)
		g_neopixel_update_func();
}

void neopixel_set_app(neoxpixel_app_t neoxpixel_app){
	timer_unregister_callback(g_neopixel_timer_id);

	switch(neoxpixel_app){
	case NEOPIXEL_APP_LOADING:
		g_neopixel_timer_id = timer_register_callback(neopixel_update_callback, 100, 0, TIMER_MODE_REPEAT);
		g_neopixel_update_func = loading;
		break;
	case NEOPIXEL_APP_RAINBOW:
		g_neopixel_timer_id = timer_register_callback(neopixel_update_callback, 20, 0, TIMER_MODE_REPEAT);
		g_neopixel_update_func = rainbow;
		break;
	case NEOPIXEL_APP_SELFBALACING:
		g_neopixel_timer_id = timer_register_callback(neopixel_update_callback, 100, 0, TIMER_MODE_REPEAT);
		g_neopixel_update_func = self_balancing_update;
		break;
	case NEOPIXEL_APP_MAX:
		break;
	}
}

void neopixel_init(){
	neopixel_set_app(NEOPIXEL_APP_LOADING);
}

