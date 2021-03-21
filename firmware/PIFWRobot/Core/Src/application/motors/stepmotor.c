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
	HAL_TIM_PWM_Start(&MOTOR1_TIMER, MOTOR1_CHANNEL);
	HAL_TIM_PWM_Start(&MOTOR2_TIMER, MOTOR2_CHANNEL);
	__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, 0);
	__HAL_TIM_SET_COMPARE(&MOTOR2_TIMER, MOTOR2_CHANNEL, 0);
}

void stepmotor_set_speed(float v_linear, float v_angular)
{
	float vel_motor1 = v_linear - (v_angular * WHEEL_WIDTH/2.0f);
	float vel_motor2 = v_linear + (v_angular * WHEEL_WIDTH/2.0f);
	if (vel_motor1 >=0)
	{
		HAL_GPIO_WritePin(MOTOR1_DIR_PORT, MOTOR1_DIR_PIN, GPIO_PIN_RESET);
	}
	else
	{
		vel_motor1 = abs(vel_motor1);
		HAL_GPIO_WritePin(MOTOR1_DIR_PORT, MOTOR1_DIR_PIN, GPIO_PIN_SET);
	}
	if (vel_motor2 >=0)
	{
		HAL_GPIO_WritePin(MOTOR2_DIR_PORT, MOTOR2_DIR_PIN, GPIO_PIN_SET);
	}
	else
	{
		vel_motor2 = abs(vel_motor2);
		HAL_GPIO_WritePin(MOTOR2_DIR_PORT, MOTOR2_DIR_PIN, GPIO_PIN_RESET);
	}
	int freq1,freq2;
	int pulse1,pulse2,pulsespersecond1;
	if (vel_motor1 <= 0.003)
		{
			freq1 = 0;
			pulse1 = freq1;
		}
	else
	{
		float pulsespersecond1 = PULSES_PER_METER * vel_motor1;
		freq1 =1000000/pulsespersecond1  ;
		pulse1 = freq1;
	}
	if (vel_motor2 <= 0.003)
	{
		freq2 = 0;
		pulse2 = freq2;
	}
	else
	{
		float pulsespersecond2 = PULSES_PER_METER * vel_motor2;
		freq2 =1000000/pulsespersecond2  ;
		pulse2 = freq2;
	}

	MOTOR1_TIMER.Instance->ARR = pulse1;
	__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL,  pulse1/2);
	MOTOR2_TIMER.Instance->ARR = pulse2;
	__HAL_TIM_SET_COMPARE(&MOTOR2_TIMER, MOTOR1_CHANNEL,  pulse2/2);

}

