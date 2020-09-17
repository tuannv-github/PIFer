/*
 * esp8266.h
 *
 *  Created on: Sep 12, 2020
 *      Author: tuannv
 */

#ifndef APPLICATION_COM_ESP8266_ESP8266_H_
#define APPLICATION_COM_ESP8266_ESP8266_H_

#include <stdint.h>

#include <application/buzzer/buzzer.h>

#define WC_CMD_0 	"AT+CWSAP_DEF=\"PIFer\",\"12345678\",1,2,4,0\r\n"
#define WC_RES_0_0	"OK\r\n"

#define WC_CMD_1 	"AT+CIPMUX=1\r\n"
#define WC_CMD_2	"AT+CIPSERVER=1,1001\r\n"
#define WI_SEND		"AT+CIPSEND=0,%d\r\n"

int esp8266_init();
int esp8266_write(char *arr, uint16_t len);
int esp8266_read(char *arr, uint16_t *len);

#endif /* APPLICATION_COM_ESP8266_ESP8266_H_ */
