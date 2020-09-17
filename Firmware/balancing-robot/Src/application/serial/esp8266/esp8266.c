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

static bool gconnected = false;
static circular_buf_t g_esp_tx_cbuf_handle;
static uint8_t tx_buf[ESP8266_TX_BUF_SIZE];

static circular_buf_t g_esp_rx_cbuf_handle;
static uint8_t rx_buf[ESP8266_RX_BUF_SIZE];

void esp8266_cb(void *ctx){

	char data[50];

	if(!gconnected){
		if(uart_readline(&esp8266_uart_drv, data, 1000000) == 0){
			if(!strcmp(data,"0,CONNECT\r\n")) gconnected = true;
		}
	}else{
		char chr;
		bool data_flag = false;
		while(uart_recv_chr(&esp8266_uart_drv, &chr) != 0){
			if(chr=='\r') {
				data_flag = false;
				continue;
			}
			if(chr==':') {
				data_flag = true;
				continue;
			}
			if(data_flag){
				cbuf_put(&g_esp_rx_cbuf_handle, chr);
			}
		}
	}

	if(gconnected){
		size_t size = cbuf_size(&g_esp_rx_cbuf_handle);
		sprintf(data, WI_SEND, size);
		uart_send(&esp8266_uart_drv, data, strlen(data));
		for(int i = 0; i < 3; i++){
			if(uart_readline(&esp8266_uart_drv, data, 1000000) != 0) return;
			if(!strcmp(data,"OK\r\n")){
				for(int j = 0; j<size; j++){
					char chr;
					if(cbuf_get(&g_esp_tx_cbuf_handle, &chr) != 0) return;
					uart_send(&esp8266_uart_drv, &chr, 1);
				}
			}
			if(!strcmp(data,"ERROR\r\n")) return;
		}
	}
}

static int esp8266_cmd(char *cmd, int lineout){
	char res[50];
	uart_reset(&esp8266_uart_drv);
	uart_send(&esp8266_uart_drv, cmd, strlen(cmd));
	for(int i = 0; i < lineout; i++){
		if(uart_readline(&esp8266_uart_drv, res, 1000000) != 0) return -1;
		if(!strcmp(res,"OK\r\n")) return 0;
		if(!strcmp(res,"ERROR\r\n")) return -1;
	}
	uart_reset(&esp8266_uart_drv);
	return -1;
}

int esp8266_init(){
	uart_init(&esp8266_uart_drv);

	if(esp8266_cmd(WC_CMD_0, 3) != 0) {
		buzzer_sys_error();
		while(esp8266_cmd(WC_CMD_0, 3) != 0);
	}
	buzzer_sys_ok();

	if(esp8266_cmd(WC_CMD_1, 3) != 0){
		buzzer_sys_error();
		while(esp8266_cmd(WC_CMD_1, 3) != 0);
	}
	buzzer_sys_ok();

	if(esp8266_cmd(WC_CMD_2, 4) != 0){
		buzzer_sys_error();
		while(esp8266_cmd(WC_CMD_2, 4) != 0);
	}
	buzzer_sys_ok();

	timer_register_callback(esp8266_cb, ESP8266_PERIOD, 0, TIMER_MODE_REPEAT);

	cbuf_init(&g_esp_tx_cbuf_handle, tx_buf, ESP8266_TX_BUF_SIZE);
	cbuf_init(&g_esp_rx_cbuf_handle, rx_buf, ESP8266_RX_BUF_SIZE);

	return 0;
}

int esp8266_write(char *arr, uint16_t len){
	if(!gconnected) return -1;
	for(int i=0; i<len; i++){
		if(cbuf_put(&g_esp_tx_cbuf_handle, arr[i]) != 0)
			return -1;
	}
	return 0;
}

int esp8266_read(char *arr, uint16_t *len){
	if(!gconnected) return -1;
	*len = 0;
	while(cbuf_get(&g_esp_rx_cbuf_handle, &arr[*len]) == 0){
		*len += 1;
	}
	return 0;
}
