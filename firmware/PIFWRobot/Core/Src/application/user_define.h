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

// Self-balancing-DC	--> 0
// Turtle-Step			--> 1
#define ROBOT_MODEL		1

// Enable				--> 1
// Disable				--> 0
#define ENABLE_NEOPIXEL	0

// Timer callback define
#define MAX_CALLBACK_FUNC	15

/* IMU definition */
#define MPU9250_I2C			hi2c1
#define MPU9250_I2C_ADDR	(0x68 << 1)
#define AK8963_I2C_ADDR		(0x0c << 1)
#define I2C_TIMEOUT_MS		20

//GFS_SEL_250DPS	--> 0
//GFS_SEL_500DPS	--> 1
//GFS_SEL_1000DPS	--> 2
//GFS_SEL_2000DPS	--> 3
#define GFS_SEL			0

//AFS_SEL_2G		--> 0
//AFS_SEL_4G		--> 1
//AFS_SEL_8G		--> 2
//AFS_SEL_16G		--> 3
#define ACCEL_FS_SEL	0
/* End of IMU definition */

// DC				--> 0
// STEP				--> 1
#if ROBOT_MODEL==0
#define MOTOR_TYPE		0
#elif ROBOT_MODEL==1
#define MOTOR_TYPE		1
#endif

// Motor 0 define
#if MOTOR_TYPE == 0
	#define MOTOR0_TIMER 		htim2
	#define MOTOR0_CHANNEL 		TIM_CHANNEL_1
	#define MOTOR0_ENCODER		htim3
#elif MOTOR_TYPE==1
	#define MOTOR0_TIMER		htim3
	#define MOTOR0_CHANNEL		TIM_CHANNEL_1
	#define MOTOR0_DIR_PORT		GPIOC
	#define MOTOR0_DIR_PIN		GPIO_PIN_14
#endif

// Motor 1 define
#if MOTOR_TYPE == 0
	#define MOTOR1_TIMER 		htim2
	#define MOTOR1_CHANNEL 		TIM_CHANNEL_2
	#define MOTOR1_ENCODER		htim4
#elif MOTOR_TYPE==1
	#define MOTOR1_TIMER		htim4
	#define MOTOR1_CHANNEL  	TIM_CHANNEL_2
	#define MOTOR1_DIR_PORT		GPIOD
	#define MOTOR1_DIR_PIN		GPIO_PIN_0
#endif

// Motor common define
#define ENC_PERIOD		100
#define ENC_RP_PERIOD	(2*ENC_PERIOD)

// IMU define
#define MPU6050_I2C			hi2c1
#define MPU9250_I2C			hi2c1
#define MPU6050_ADDRESS 	(MPU6050_DEFAULT_ADDRESS << 1)
#define TILT_PERIOD_MS		2
#define RPY_PERIOD_MS		10
#define IMU_RAW_RP_PERIOD	45
#define IMU_CAL_RP_PERIOD	55
#define IMU_RPY_RP_PERIOD	60

// UART
#define MAX_UART_INSTANT	3
#define TX_DMA_BUF_SIZE 	512
#define RX_DMA_BUF_SIZE		512
#define TX_CIR_BUF_SIZE 	512
#define RX_CIR_BUF_SIZE 	512

// Serial to DWM1001
#define STD_USART			huart1
#define STD_PERIOD			100

// Serial over ESP8266
#define SOE_USART			huart2
#define SOE_PERIOD			100

// Serial over UART define
#define SOU_USART			huart3
#define SOU_PERIOD			100

// Mavlink
#define MAV_BUFF_SIZE 		128
#define MAVLINK_CB_PERIOD	15	// Mavlink read message callback

// Parameters define
#define PARAMS_PAGE_ADDRESS 		0x0800FC00
#define HAVE_SAVED_DATA				0x01

// ROBOT_MODEL_TWO_WHEELS mode RUN
#define TILT_CONTROLLER_PERIOD		5
#define VEL_CONTROLLER_PERIOD		100
#define IMU_STATUS_REPORT_PERIOD	100
#define RPY_REPORT_PERIOD			100
#define MODE_RUN_REPORT_PERIOD		100
#define CONTROL_TIMEOUT_MS			1000
#define VX_TO_TILT					0.04f
#define OMEGA_COEFF					150.0f
#define VELOC_COEFF					250.0f
#define TILT_REPORT_PERIOD			100

// ROBOT_MODEL_TANK general define
#define WHEEL_PERIOD				50
#define SYNC_PERIOD					100

// ROBOT_MODEL_TANK	mode PIDT
#define PID_REPORT_PERIOD			100
#define SPEED_REPORT_PERIOD			100

#define CONST_G 					9.807f

// STEP MOTOR DEFINE
#define PULSES_PER_METER 	8027
#define ROBOT_WIDTH 		0.16f

#endif /* USERCODE_USER_DEFINE_H_ */
