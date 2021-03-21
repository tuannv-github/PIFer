/*
 * stepmotor.c
 *
 *  Created on: Mar 18, 2021
 *      Author: PC
 */
#include <application/motors/stepmotor.h>
#include "math.h"

void stepmotor_init()
{
	HAL_TIM_PWM_Start(&MOTOR0_TIMER, MOTOR0_CHANNEL);
	HAL_TIM_PWM_Start(&MOTOR1_TIMER, MOTOR1_CHANNEL);
	__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, 0);
	__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, 0);
}

void stepmotor_speed(motors_t motor, float speed){
	switch(motor){
	case MOTOR_0:
		if(speed > 0){
			if(params.motor0_invert) HAL_GPIO_WritePin(MOTOR0_DIR_PORT, MOTOR0_DIR_PIN, GPIO_PIN_RESET);
			else HAL_GPIO_WritePin(MOTOR0_DIR_PORT, MOTOR0_DIR_PIN, GPIO_PIN_SET);
		}
		else{
			if(params.motor0_invert) HAL_GPIO_WritePin(MOTOR0_DIR_PORT, MOTOR0_DIR_PIN, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(MOTOR0_DIR_PORT, MOTOR0_DIR_PIN, GPIO_PIN_RESET);
		}
		speed = fabs(speed);
		if(speed < 0.003){
			MOTOR0_TIMER.Instance->ARR = 0;
			__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL,  0);
		}
		else{
			float pulses_per_second = PULSES_PER_METER * speed;
			uint32_t counter_period = (uint32_t)(1000000.0f/pulses_per_second);
			MOTOR0_TIMER.Instance->ARR = counter_period;
			__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL,  counter_period/2);
		}
		break;
	case MOTOR_1:
		if(speed > 0){
			if(params.motor1_invert) HAL_GPIO_WritePin(MOTOR1_DIR_PORT, MOTOR1_DIR_PIN, GPIO_PIN_RESET);
			else HAL_GPIO_WritePin(MOTOR1_DIR_PORT, MOTOR1_DIR_PIN, GPIO_PIN_SET);
		}
		else{
			if(params.motor1_invert) HAL_GPIO_WritePin(MOTOR1_DIR_PORT, MOTOR1_DIR_PIN, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(MOTOR1_DIR_PORT, MOTOR1_DIR_PIN, GPIO_PIN_RESET);
		}
		speed = fabs(speed);
		if(speed < 0.003){
			MOTOR1_TIMER.Instance->ARR = 0;
			__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL,  0);
		}
		else{
			float pulses_per_second = PULSES_PER_METER * speed;
			uint32_t counter_period = (uint32_t)(1000000.0f/pulses_per_second);
			 MOTOR1_TIMER.Instance->ARR = counter_period;
			__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL,  counter_period/2);;
		}
		break;
	}
}

void stepmotor_vw(float v, float w)
{
	float v0 = v - (w * ROBOT_WIDTH/2.0f);
	float v1 = v + (w * ROBOT_WIDTH/2.0f);

	stepmotor_speed(MOTOR_0, v0);
	stepmotor_speed(MOTOR_1, v1);
}

