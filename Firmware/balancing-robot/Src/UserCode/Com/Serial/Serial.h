/*
 * Serial.h
 *
 *  Created on: Oct 10, 2019
 *      Author: 16138
 */

#ifndef USERCODE_SERIAL_SERIAL_H_
#define USERCODE_SERIAL_SERIAL_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "usart.h"
#include "circular_buffer/circular_buffer.h"
#include "UserCode/user_define.h"

typedef struct{
	// Public elements. Should be changed by user
	UART_HandleTypeDef* huart;

	// Private elements. Should not be changed by user. User to store internal data
	uint8_t tx_dma_buffer[TX_DMA_BUF_SIZE];
	uint8_t rx_dma_buffer[RX_DMA_BUF_SIZE];
	circular_buf_t tx_cbuf_handle;
	uint8_t tx_buf[TX_CIR_BUF_SIZE];
	circular_buf_t rx_cbuf_handle;
	uint8_t rx_buf[RX_CIR_BUF_SIZE];

	bool tx_completed;
}uart_drv_t;

bool uart_init(uart_drv_t* const uart_drv_);

bool uart_send_chr(uart_drv_t* uart_drv, const uint8_t chr);
bool uart_read_chr(uart_drv_t* uart_drv, uint8_t* chr);

bool uart_send(uart_drv_t* uart_drv, const uint8_t* data, const uint16_t len);
bool uart_read(uart_drv_t* const uart_drv, uint8_t* data, uint16_t* len);
bool uart_readline(uart_drv_t* uart_drv, uint8_t* data, uint16_t* len);

bool uart_tx_reset(uart_drv_t* uart_drv);
bool uart_rx_reset(uart_drv_t* uart_drv);

#endif /* USERCODE_SERIAL_SERIAL_H_ */
