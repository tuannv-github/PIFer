#include "Serial.h"
#include "UserCode/Timer/timer.h"

static uart_drv_t* uart_drv;

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == uart_drv->huart->Instance){
		uart_drv->tx_completed = true;
	}
}

void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart){
	HAL_UART_RxCpltCallback(huart);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == uart_drv->huart->Instance){
	    uint16_t currCNDTR = __HAL_DMA_GET_COUNTER(huart->hdmarx);
	    uint16_t length =  sizeof(uart_drv->rx_dma_buffer) - currCNDTR;
	    /* Copy and Process new data */
	    for(uint16_t i=0; i<length; i++)
	    {
	    	circular_buf_put(&uart_drv->rx_cbuf_handle, uart_drv->rx_dma_buffer[i]);
	    }
	    __HAL_DMA_DISABLE(huart->hdmarx);
	    huart->hdmarx->Instance->CNDTR = sizeof(uart_drv->rx_dma_buffer);
	    __HAL_DMA_ENABLE(huart->hdmarx);
	}
}

void uart_cb()
{
	if(uart_drv->tx_completed){
		size_t size = circular_buf_size(&uart_drv->tx_cbuf_handle);
		if(size > sizeof(uart_drv->tx_dma_buffer)) size = sizeof(uart_drv->tx_dma_buffer);
		if(size != 0){
			for(size_t i = 0; i < size; i++){
				circular_buf_get(&uart_drv->tx_cbuf_handle, &uart_drv->tx_dma_buffer[i]);
			}
			uart_drv->tx_completed = false;
			HAL_UART_Transmit_DMA(uart_drv->huart, uart_drv->tx_dma_buffer, size);
		}
	}

	// Check RX Timeout
	HAL_UART_RxCpltCallback(uart_drv->huart);
}

/**
 * @brief Init uart interface
 * 
 * @param uart_drv
 * @return drv_stt_t 
 */
bool uart_init(uart_drv_t* const uart_drv_){
	uart_drv = uart_drv_;

	// Init uart interface using hal
	HAL_UART_MspInit(uart_drv->huart);

	// Init circular buffer for uart driver
	circular_buf_init(&uart_drv->tx_cbuf_handle, uart_drv->tx_buf, sizeof(uart_drv->tx_buf));
	circular_buf_init(&uart_drv->rx_cbuf_handle, uart_drv->rx_buf, sizeof(uart_drv->rx_buf));

	HAL_UART_Receive_DMA(uart_drv->huart, (uint8_t*)uart_drv->rx_dma_buffer, sizeof(uart_drv->rx_dma_buffer));

	uart_drv->tx_completed = true;

	timer_register_callback(uart_cb, SERIAL_PERIOD, 0, TIMER_MODE_REPEAT);
	return true;
}

bool uart_send(uart_drv_t* uart_drv, const uint8_t* data, const uint16_t len){
	for(uint16_t i=0; i<len; i++){
		bool drv_stt = uart_send_chr(uart_drv, data[i]);
		if(drv_stt != true) return drv_stt;
	}
	return true;
}

bool uart_read(uart_drv_t* uart_drv, uint8_t* data, uint16_t* len){
	for(uint16_t i=0; i<*len; i++){
		bool drv_stt = uart_read_chr(uart_drv, data + i);
		if(drv_stt != true){
			*len = i;
			return drv_stt;
		}
	}
	return true;
}

bool uart_readline(uart_drv_t* uart_drv, uint8_t* data, uint16_t* len){
	uint16_t i = 0;
	uint8_t chr;
	uint8_t cnt = 0;
	while(true){
		if(uart_read_chr(uart_drv, &chr) == true){
			if(chr != '\r' && chr != '\n'){
				data[i] = chr;
				i++;
			}
			else if(chr == '\n' && i==0) continue;
			else{
				data[i] = '\r';
				data[i+1] = '\n';
				data[i+2] = 0;
				*len = i + 2;
				return true;
			}
		}
		else{
			if(cnt == 100) break;
			cnt++;
			HAL_Delay(10);
		}
	}
	return true;
}

bool uart_send_chr(uart_drv_t* const uart_drv, const uint8_t chr){
	if(circular_buf_put(&uart_drv->tx_cbuf_handle, chr)){
		return false;
	}
	return true;
}

bool uart_read_chr(uart_drv_t* uart_drv, uint8_t* chr){
	if(circular_buf_get(&uart_drv->rx_cbuf_handle, chr)){
		return false;
	}
	return true;
}

bool uart_tx_reset(uart_drv_t* uart_drv){
	circular_buf_reset(&uart_drv->tx_cbuf_handle);
	return true;
}
bool uart_rx_reset(uart_drv_t* uart_drv){
	circular_buf_reset(&uart_drv->rx_cbuf_handle);
	return true;
}
