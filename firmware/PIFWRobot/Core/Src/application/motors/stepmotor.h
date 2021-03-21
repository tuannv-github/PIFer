/*
 * stepmotor.h
 *
 *  Created on: Mar 18, 2021
 *      Author: PC
 */

#ifndef USER_MOTOR_STEPMOTOR_H_
#define USER_MOTOR_STEPMOTOR_H_

#include <application/user_define.h>


//typedef enum{
//	MOTOR_1 = 0,
//	MOTOR_2
//}motor_;
//typedef struct velocity_motor{
//	float vel_left ;
//	float vel_right;
//	float vel_linear ;
//	float vel_angular ;
//}velocity_;


//typedef struct stepmotor{
//	uint8_t enable;
//	uint8_t dir;
//	uint8_t duty;
//	uint32_t frequency;
//
//} stepmotor_;
void stepmotor_init();
void stepmotor_set_speed(float v_linear, float v_angular);


#endif /* USER_MOTOR_STEPMOTOR_H_ */
