/*
 * Motors.c
 *
 *  Created on: Oct 9, 2019
 *      Author: 16138
 */

#include <application/motors/motors.h>
#include <stdlib.h>

#include "tim.h"
#include "gpio.h"


typedef void (*set_speed_func_t)(int32_t speed);

static set_speed_func_t gset_speed_motor0;
static set_speed_func_t gset_speed_motor1;

static void motor0_setspeed(int32_t speed);
static void motor0_setspeed_invert(int32_t speed);
static void motor1_setspeed(int32_t speed);
static void motor1_setspeed_invert(int32_t speed);

void motors_init(){
	HAL_TIM_PWM_Start(&MOTOR0_TIMER, MOTOR0_CHANNEL);
	HAL_TIM_PWM_Start(&MOTOR1_TIMER, MOTOR1_CHANNEL);

	HAL_GPIO_WritePin(MTR1_DIR_MCU_GPIO_Port, MTR1_DIR_MCU_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MTR2_DIR_MCU_GPIO_Port, MTR2_DIR_MCU_Pin, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, 999);
	__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, 999);

	if(params.motor0_invert == true){
		gset_speed_motor0 = motor0_setspeed_invert;
	}
	else gset_speed_motor0 = motor0_setspeed;

	if(params.motor1_invert == true){
		gset_speed_motor1 = motor1_setspeed_invert;
	}
	else gset_speed_motor1 = motor1_setspeed;
}

void motors_deinit(){
	// Disable motors if we have enable pins
	HAL_GPIO_WritePin(MTR1_DIR_MCU_GPIO_Port, MTR1_DIR_MCU_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MTR2_DIR_MCU_GPIO_Port, MTR2_DIR_MCU_Pin, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, 0);
	__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, 0);
}

static void motor0_setspeed(int32_t speed){
	if(speed > 0){
		__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, abs(speed));
		HAL_GPIO_WritePin(MTR1_DIR_MCU_GPIO_Port, MTR1_DIR_MCU_Pin, GPIO_PIN_RESET);
	}else{
		__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, 1000 - abs(speed));
		HAL_GPIO_WritePin(MTR1_DIR_MCU_GPIO_Port, MTR1_DIR_MCU_Pin, GPIO_PIN_SET);
	}
}

static void motor0_setspeed_invert(int32_t speed){
	if(speed > 0){
		__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, 1000 - abs(speed));
		HAL_GPIO_WritePin(MTR1_DIR_MCU_GPIO_Port, MTR1_DIR_MCU_Pin, GPIO_PIN_SET);
	}else{
		__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, abs(speed));
		HAL_GPIO_WritePin(MTR1_DIR_MCU_GPIO_Port, MTR1_DIR_MCU_Pin, GPIO_PIN_RESET);
	}
}

static void motor1_setspeed(int32_t speed){
	if(speed > 0){
		__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, abs(speed));
		HAL_GPIO_WritePin(MTR2_DIR_MCU_GPIO_Port, MTR2_DIR_MCU_Pin, GPIO_PIN_RESET);
	}else{
		__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, 1000 - abs(speed));
		HAL_GPIO_WritePin(MTR2_DIR_MCU_GPIO_Port, MTR2_DIR_MCU_Pin, GPIO_PIN_SET);
	}
}

static void motor1_setspeed_invert(int32_t speed){
	if(speed > 0){
		__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, 1000 - abs(speed));
		HAL_GPIO_WritePin(MTR2_DIR_MCU_GPIO_Port, MTR2_DIR_MCU_Pin, GPIO_PIN_SET);
	}else{
		__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, abs(speed));
		HAL_GPIO_WritePin(MTR2_DIR_MCU_GPIO_Port, MTR2_DIR_MCU_Pin, GPIO_PIN_RESET);
	}
}

void motors_setspeed(motors_t motor, int32_t speed){
	switch(motor){
	case MOTOR_0:
		if(speed!=0) speed = speed > 0 ? (speed+params.motor0_pos_deadband) : (speed+params.motor0_neg_deadband);
		if(speed > 999) speed = 999;
		if(speed < -999) speed = -999;
		gset_speed_motor0(speed);
		break;
	case MOTOR_1:
		if(speed!=0) speed = speed > 0 ? (speed+params.motor1_pos_deadband) : (speed+params.motor1_neg_deadband);
		if(speed > 999) speed = 999;
		if(speed < -999) speed = -999;
		gset_speed_motor1(speed);
		break;
	}
}
