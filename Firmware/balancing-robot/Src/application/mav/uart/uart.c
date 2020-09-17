#include <application/timer/timer.h>
#include "uart.h"

static uart_drv_t* uart_drvs[MAX_UART_INSTANT];

static int add_uart_drv_instant(uart_drv_t *uart_drv){
	for(int i=0; i<MAX_UART_INSTANT; i++){
		if(uart_drvs[i] == 0){
			uart_drvs[i] = uart_drv;
			return i;
		}
	}
	return -1;
}

static int find_uart_dev_instant(UART_HandleTypeDef *huart){
	for(int i=0; i<MAX_UART_INSTANT; i++){
		if(uart_drvs[i]->huart->Instance == huart->Instance){
			return i;
		}
	}
	return -1;
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	int idx = find_uart_dev_instant(huart);
	uart_drvs[idx]->tx_completed = true;
}

void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart){
	HAL_UART_RxCpltCallback(huart);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	int idx = find_uart_dev_instant(huart);
	uart_drv_t *uart_drv = uart_drvs[idx];

	uint16_t currCNDTR = __HAL_DMA_GET_COUNTER(huart->hdmarx);
	uint16_t length =  sizeof(uart_drv->rx_dma_buffer) - currCNDTR;

	/* Copy and process new data */
	for(uint16_t i=0; i<length; i++)
	{
		cbuf_put(&uart_drv->rx_cbuf_handle, uart_drv->rx_dma_buffer[i]);
	}

	__HAL_DMA_DISABLE(huart->hdmarx);
	huart->hdmarx->Instance->CNDTR = sizeof(uart_drv->rx_dma_buffer);
	__HAL_DMA_ENABLE(huart->hdmarx);
}

void uart_cb(void *cxt)
{
	uart_drv_t *uart_drv = (uart_drv_t *)cxt;

	if(uart_drv->tx_completed){
		size_t size = cbuf_size(&uart_drv->tx_cbuf_handle);
		if(size > sizeof(uart_drv->tx_dma_buffer)) size = sizeof(uart_drv->tx_dma_buffer);
		if(size != 0){
			for(size_t i = 0; i < size; i++){
				cbuf_get(&uart_drv->tx_cbuf_handle, &uart_drv->tx_dma_buffer[i]);
			}
			uart_drv->tx_completed = false;
			HAL_UART_Transmit_DMA(uart_drv->huart, uart_drv->tx_dma_buffer, size);
		}
	}

	// Check RX Timeout
	HAL_UART_RxCpltCallback(uart_drv->huart);
}

int uart_init(uart_drv_t* uart_drv){

	add_uart_drv_instant(uart_drv);

	// Init uart interface using hal
	HAL_UART_MspInit(uart_drv->huart);

	// Init circular buffer for uart driver
	cbuf_init(&uart_drv->tx_cbuf_handle, uart_drv->tx_buf, sizeof(uart_drv->tx_buf));
	cbuf_init(&uart_drv->rx_cbuf_handle, uart_drv->rx_buf, sizeof(uart_drv->rx_buf));

	HAL_UART_Receive_DMA(uart_drv->huart, (uint8_t*)uart_drv->rx_dma_buffer, sizeof(uart_drv->rx_dma_buffer));

	uart_drv->tx_completed = true;
	uart_drv->cbid = timer_register_callback(uart_cb, uart_drv->cb_period, uart_drv, TIMER_MODE_REPEAT);

	return 0;
}

int uart_send_chr(uart_drv_t *uart_drv, char chr){
	return cbuf_put(&uart_drv->tx_cbuf_handle, chr);
}

int uart_recv_chr(uart_drv_t *uart_drv, char *chr){
	return cbuf_get(&uart_drv->rx_cbuf_handle, chr);
}

int uart_send(uart_drv_t *uart_drv, char *data, uint16_t len){
	for(uint16_t i=0; i<len; i++){
		int drv_stt = uart_send_chr(uart_drv, data[i]);
		if(drv_stt != 0) return drv_stt;
	}
	return 0;
}

int uart_recv(uart_drv_t *uart_drv, char *data, uint16_t *len){
	for(uint16_t i=0; i<*len; i++){
		if(uart_recv_chr(uart_drv, data + i) != 0){
			*len = i;
		}
	}
	return 0;
}

int uart_readline(uart_drv_t* uart_drv, char *data, int timeout){
	char chr;
	int i=0, t=0;
	while(1){
		while(uart_recv_chr(uart_drv, &chr) != 0){
			t++;
			if(t>timeout) return -1;
		}
		if(chr != '\r' && chr != '\n'){
			data[i] = chr;
			 i++;
		}
		else if(chr == '\n' && i==0) continue;
		else{
			data[i] = '\r';
			data[i+1] = '\n';
			data[i+2] = 0;
			return 0;
		}
	}
	return -1;
}

void uart_tx_reset(uart_drv_t* uart_drv){
	cbuf_reset(&uart_drv->tx_cbuf_handle);
}

void uart_rx_reset(uart_drv_t* uart_drv){
	cbuf_reset(&uart_drv->rx_cbuf_handle);
}

void uart_reset(uart_drv_t* uart_drv){
	uart_tx_reset(uart_drv);
	uart_rx_reset(uart_drv);
}
