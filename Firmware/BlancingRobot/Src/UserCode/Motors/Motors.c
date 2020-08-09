/*
 * Motors.c
 *
 *  Created on: Oct 9, 2019
 *      Author: 16138
 */
#include <stdlib.h>

#include "Motors.h"
#include "tim.h"
#include "gpio.h"
#include <UserCode/Params/Params.h>

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

	HAL_GPIO_WritePin(MOTOR0_DIR_GPIO_Port, MOTOR0_DIR_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MOTOR1_DIR_GPIO_Port, MOTOR1_DIR_Pin, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, 999);
	__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, 999);

	// Enable motors if we have enable pins
	// HAL_GPIO_WritePin(MOTORS_EN0_GPIO_Port, MOTORS_EN0_Pin, GPIO_PIN_RESET);
	// HAL_GPIO_WritePin(MOTORS_EN1_GPIO_Port, MOTORS_EN1_Pin, GPIO_PIN_RESET);

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
	//HAL_GPIO_WritePin(MOTORS_EN0_GPIO_Port, MOTORS_EN0_Pin, GPIO_PIN_RESET);
	// HAL_GPIO_WritePin(MOTORS_EN1_GPIO_Port, MOTORS_EN1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR0_DIR_GPIO_Port, MOTOR0_DIR_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MOTOR1_DIR_GPIO_Port, MOTOR1_DIR_Pin, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, 999);
	__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, 999);
}

static void motor0_setspeed(int32_t speed){
	if(speed > 0){
		__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, abs(speed));
		HAL_GPIO_WritePin(MOTOR0_DIR_GPIO_Port, MOTOR0_DIR_Pin, GPIO_PIN_RESET);
	}else{
		__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, 1000 - abs(speed));
		HAL_GPIO_WritePin(MOTOR0_DIR_GPIO_Port, MOTOR0_DIR_Pin, GPIO_PIN_SET);
	}
}

static void motor0_setspeed_invert(int32_t speed){
	if(speed > 0){
		__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, 1000 - abs(speed));
		HAL_GPIO_WritePin(MOTOR0_DIR_GPIO_Port, MOTOR0_DIR_Pin, GPIO_PIN_SET);
	}else{
		__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, abs(speed));
		HAL_GPIO_WritePin(MOTOR0_DIR_GPIO_Port, MOTOR0_DIR_Pin, GPIO_PIN_RESET);
	}
}

static void motor1_setspeed(int32_t speed){
	if(speed > 0){
		__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, abs(speed));
		HAL_GPIO_WritePin(MOTOR1_DIR_GPIO_Port, MOTOR1_DIR_Pin, GPIO_PIN_RESET);
	}else{
		__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, 1000 - abs(speed));
		HAL_GPIO_WritePin(MOTOR1_DIR_GPIO_Port, MOTOR1_DIR_Pin, GPIO_PIN_SET);
	}
}

static void motor1_setspeed_invert(int32_t speed){
	if(speed > 0){
		__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, 1000 - abs(speed));
		HAL_GPIO_WritePin(MOTOR1_DIR_GPIO_Port, MOTOR1_DIR_Pin, GPIO_PIN_SET);
	}else{
		__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, abs(speed));
		HAL_GPIO_WritePin(MOTOR1_DIR_GPIO_Port, MOTOR1_DIR_Pin, GPIO_PIN_RESET);
	}
}

void motors_setspeed(motors_t motor, int32_t speed){
	if(speed > 999) speed = 999;
	if(speed < -999) speed = -999;
	switch(motor){
	case MOTOR_0:
		gset_speed_motor0(speed);
		break;
	case MOTOR_1:
		gset_speed_motor1(speed);
		break;
	}
}
