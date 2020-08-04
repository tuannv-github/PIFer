/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ONBOARD_LED_Pin GPIO_PIN_13
#define ONBOARD_LED_GPIO_Port GPIOC
#define MOTOR03_DIR_Pin GPIO_PIN_2
#define MOTOR03_DIR_GPIO_Port GPIOA
#define MOTOR2_DIR_Pin GPIO_PIN_3
#define MOTOR2_DIR_GPIO_Port GPIOA
#define MOTOR1_DIR_Pin GPIO_PIN_4
#define MOTOR1_DIR_GPIO_Port GPIOA
#define MOTOR0_DIR_Pin GPIO_PIN_5
#define MOTOR0_DIR_GPIO_Port GPIOA
#define MOTOR3_PWM_Pin GPIO_PIN_8
#define MOTOR3_PWM_GPIO_Port GPIOA
#define MOTOR2_PWM_Pin GPIO_PIN_9
#define MOTOR2_PWM_GPIO_Port GPIOA
#define MOTOR1_PWM_Pin GPIO_PIN_10
#define MOTOR1_PWM_GPIO_Port GPIOA
#define MOTOR0_PWM_Pin GPIO_PIN_11
#define MOTOR0_PWM_GPIO_Port GPIOA
#define IMU_SCL_Pin GPIO_PIN_8
#define IMU_SCL_GPIO_Port GPIOB
#define IMU_SDA_Pin GPIO_PIN_9
#define IMU_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
