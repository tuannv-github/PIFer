/*
 * esp8266.h
 *
 *  Created on: Sep 12, 2020
 *      Author: tuannv
 */

#ifndef APPLICATION_COM_ESP8266_ESP8266_H_
#define APPLICATION_COM_ESP8266_ESP8266_H_

#include <stdint.h>

int esp8266_init();
int esp8266_write(uint8_t *arr, uint16_t len);
int esp8266_read(uint8_t *arr, uint16_t *len);

#endif /* APPLICATION_COM_ESP8266_ESP8266_H_ */
