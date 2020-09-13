/*
 * esp8266.c
 *
 *  Created on: Sep 12, 2020
 *      Author: tuannv
 */

#include "esp8266.h"

#include <application/user_define.h>
#include <application/serial/uart/uart.h>

static uart_drv_t esp8266_uart_drv = {
		.huart = &ESP8266_USART,
		.cb_period = ESP8266_PERIOD,
};

static uart_drv_t uart_drv = {
		.huart = &COM_USART,
		.cb_period = COM_PERIOD,
};


void esp8266_cb(void *ctx){
	uint8_t data[20];
	uint16_t len = 20;

	uart_recv(&uart_drv, data, &len);
	if(len > 0)
		uart_send(&esp8266_uart_drv, data, len);

	len = 20;
	uart_recv(&esp8266_uart_drv, data, &len);
	if(len > 0)
		uart_send(&uart_drv, data, len);
}

int esp8266_init(){
	uart_init(&esp8266_uart_drv);
	uart_init(&uart_drv);

	timer_register_callback(esp8266_cb, 10, 0, TIMER_MODE_REPEAT);
	return 0;
}

int esp8266_write(uint8_t *arr, uint16_t len){
	return 0;
}

int esp8266_read(uint8_t *arr, uint16_t *len){
	return 0;
}
