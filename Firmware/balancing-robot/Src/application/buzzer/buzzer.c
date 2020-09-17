/*
 * buzzer.c
 *
 *  Created on: Sep 13, 2020
 *      Author: tuannv
 */

#include <stdbool.h>

#include "buzzer.h"

#include <gpio.h>
#include <application/timer/timer.h>

TID(gbuzzer_id);

static bool gstatus;
static bool gdone = true;

void buzzer_cb(void *ctx){
	if(gstatus){
		gstatus = false;
		HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
		if(!gdone)
			gbuzzer_id = timer_register_callback(buzzer_cb, 100, 0, TIMER_MODE_ONE_SHOT);
	}
	else{
		gstatus = true;
		HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_SET);
		gbuzzer_id = timer_register_callback(buzzer_cb, 200, 0, TIMER_MODE_ONE_SHOT);
	}
}

void buzzer_sys_start(){
	HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_SET);
	HAL_Delay(250);
	HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
	HAL_Delay(250);
	HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_SET);
	HAL_Delay(250);
	HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
}

void buzzer_sys_error(){
	gdone = false;
	gbuzzer_id = timer_register_callback(buzzer_cb, 500, 0, TIMER_MODE_ONE_SHOT);
}

void buzzer_sys_ok(){
	gdone = true;
}
