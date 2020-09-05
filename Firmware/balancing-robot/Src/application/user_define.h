/*
 * user_define.h
 *
 *  Created on: Oct 9, 2019
 *      Author: 16138
 */

#ifndef _USERCODE_USER_DEFINE_H_
#define _USERCODE_USER_DEFINE_H_

#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

// Timer callback define
#define MAX_CALLBACK_FUNC	15

#define IMU_MPU6050

#define ROBOT_MODEL_TWO_WHEELS
//#define ROBOT_MODEL_TANK
//#define ROBOT_MODEL_OMNI

// Motor 0 define
#define MOTOR0_TIMER 	htim2
#define MOTOR0_CHANNEL 	TIM_CHANNEL_1
#define MOTOR0_ENCODER	htim3
#define MOTOR0_INVERT	// define if you want to change motor direction

// Motor 1 define
#define MOTOR1_TIMER 	htim2
#define MOTOR1_CHANNEL 	TIM_CHANNEL_2
#define MOTOR1_ENCODER	htim4
#define MOTOR1_INVERT	// define if you want to change motor direction

// Motor common define
#define ENC_PERIOD		50
#define ENC_RP_PERIOD	100

// IMU define
#define MPU6050_I2C			hi2c1
#define MPU9250_I2C			hi2c1
#define MPU6050_ADDRESS 	(MPU6050_DEFAULT_ADDRESS << 1)
#define IMU_PERIOD			1
#define TILT_ROLL			0
#define TILT_PITCH			1
#define TILT				TILT_PITCH
#define IMU_RAW_RP_PERIOD	45
#define IMU_RES_RP_PERIOD	55

// COM define
#define COM_USART			huart3
#define TX_DMA_BUF_SIZE 	512
#define RX_DMA_BUF_SIZE		512
#define TX_CIR_BUF_SIZE 	512
#define RX_CIR_BUF_SIZE 	512
#define SERIAL_PERIOD		10	// UART transmission
#define MAV_BUFF_SIZE 		512
#define MAVLINK_CB_PERIOD	10	// Mavlink read message callback

// Parameters define
#define PARAMS_PAGE_ADDRESS 0x0800FC00
#define HAVE_SAVED_DATA		0x01

// ROBOT_MODEL_TWO_WHEELS mode RUN
#define TILT_CONTROLLER_PERIOD		5
#define VEL_CONTROLLER_PERIOD		60
#define IMU_STATUS_REPORT_PERIOD	100
#define RPY_REPORT_PERIOD			100
#define TILT_REPORT_PERIOD			100
#define PID_REPORT_PERIOD			100
#define CONTROL_TIMEOUT_MS			1000
#define VX_TO_TILT					0.04
#define OMEGA_COEFF					3.0
#define THROTTLE_COEFF				5

// ROBOT_MODEL_TANK general define
#define WHEEL_PERIOD				50
#define SYNC_PERIOD					100

// ROBOT_MODEL_TANK	mode PIDT
#define PID_REPORT_PERIOD			100
#define SPEED_REPORT_PERIOD			100

#define PARAMS_PAGE_ADDRESS 0x0800FC00
#define HAVE_SAVED_DATA		0x01

#define CONST_G 					9.807f

#endif /* USERCODE_USER_DEFINE_H_ */
