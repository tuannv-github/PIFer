/*
 * esp8266.c
 *
 *  Created on: Sep 12, 2020
 *      Author: tuannv
 */

#include "esp8266.h"

#include <application/user_define.h>
#include <application/serial/uart/uart.h>

static uart_drv_t uart_drv = {
		.huart = &ESP8266_USART,
		.cb_period = ESP8266_PERIOD,
};

int esp8266_init(){
	return 0;
}

int esp8266_write(uint8_t *arr, uint16_t len){
	return 0;
}

int esp8266_read(uint8_t *arr, uint16_t *len){
	return 0;
}
