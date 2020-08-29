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
#define BUZZER_Pin GPIO_PIN_13
#define BUZZER_GPIO_Port GPIOC
#define MTR1_DIR_MCU_Pin GPIO_PIN_14
#define MTR1_DIR_MCU_GPIO_Port GPIOC
#define MTR1_ENB_MCU_Pin GPIO_PIN_15
#define MTR1_ENB_MCU_GPIO_Port GPIOC
#define MTR2_DIR_MCU_Pin GPIO_PIN_0
#define MTR2_DIR_MCU_GPIO_Port GPIOD
#define MTR2_ENB_MCU_Pin GPIO_PIN_1
#define MTR2_ENB_MCU_GPIO_Port GPIOD
#define MTR1_PWM_MCU_Pin GPIO_PIN_0
#define MTR1_PWM_MCU_GPIO_Port GPIOA
#define MTR2_PWM_MCU_Pin GPIO_PIN_1
#define MTR2_PWM_MCU_GPIO_Port GPIOA
#define ESP_RX_MCU_Pin GPIO_PIN_2
#define ESP_RX_MCU_GPIO_Port GPIOA
#define ESP_TX_MCU_Pin GPIO_PIN_3
#define ESP_TX_MCU_GPIO_Port GPIOA
#define BLUE_RESET_Pin GPIO_PIN_4
#define BLUE_RESET_GPIO_Port GPIOA
#define RF_PWR_Pin GPIO_PIN_5
#define RF_PWR_GPIO_Port GPIOA
#define ENC_1A_MCU_Pin GPIO_PIN_6
#define ENC_1A_MCU_GPIO_Port GPIOA
#define ENC_1B_MCU_Pin GPIO_PIN_7
#define ENC_1B_MCU_GPIO_Port GPIOA
#define BTN_Pin GPIO_PIN_0
#define BTN_GPIO_Port GPIOB
#define RF_SET_Pin GPIO_PIN_1
#define RF_SET_GPIO_Port GPIOB
#define RF_RXD_Pin GPIO_PIN_10
#define RF_RXD_GPIO_Port GPIOB
#define RF_TXD_Pin GPIO_PIN_11
#define RF_TXD_GPIO_Port GPIOB
#define DWM_SPI_CSn_Pin GPIO_PIN_12
#define DWM_SPI_CSn_GPIO_Port GPIOB
#define DWM_SPI_CLK_Pin GPIO_PIN_13
#define DWM_SPI_CLK_GPIO_Port GPIOB
#define DWM_SPI_MISO_Pin GPIO_PIN_14
#define DWM_SPI_MISO_GPIO_Port GPIOB
#define DWM_SPI_MOSI_Pin GPIO_PIN_15
#define DWM_SPI_MOSI_GPIO_Port GPIOB
#define LED_Pin GPIO_PIN_8
#define LED_GPIO_Port GPIOA
#define BLUE_RX_Pin GPIO_PIN_9
#define BLUE_RX_GPIO_Port GPIOA
#define BLUE_TX_Pin GPIO_PIN_10
#define BLUE_TX_GPIO_Port GPIOA
#define BLUE_KEY_Pin GPIO_PIN_11
#define BLUE_KEY_GPIO_Port GPIOA
#define NRF24_IRQ_Pin GPIO_PIN_12
#define NRF24_IRQ_GPIO_Port GPIOA
#define NRF24_CSN_Pin GPIO_PIN_15
#define NRF24_CSN_GPIO_Port GPIOA
#define NRF24_SCK_Pin GPIO_PIN_3
#define NRF24_SCK_GPIO_Port GPIOB
#define NRF24_MISO_Pin GPIO_PIN_4
#define NRF24_MISO_GPIO_Port GPIOB
#define NRF24_MOSI_Pin GPIO_PIN_5
#define NRF24_MOSI_GPIO_Port GPIOB
#define ENC_2B_MCU_Pin GPIO_PIN_6
#define ENC_2B_MCU_GPIO_Port GPIOB
#define ENC_2A_MCU_Pin GPIO_PIN_7
#define ENC_2A_MCU_GPIO_Port GPIOB
#define GY9250_SCL_Pin GPIO_PIN_8
#define GY9250_SCL_GPIO_Port GPIOB
#define GY9250_SDA_Pin GPIO_PIN_9
#define GY9250_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
