// Peripheral usage
#include <string.h>
#include <stdbool.h>
#include "stm32f1xx_hal.h"

#include "../config.h"
#include "port.h"

#if (NEO_PIXEL_USE_IMPL == 1)

#define RESET_PADDING	50
#define RGB_BUF_LEN 	(NUM_BPP * NUM_PIXELS)
#define DMA_BUF_LEN		((RGB_BUF_LEN*8)+RESET_PADDING)

extern TIM_HandleTypeDef TIMER;
extern DMA_HandleTypeDef TIMER_DMA;

static uint8_t rgb_arr[RGB_BUF_LEN] = {0};	// LED color buffer
static uint8_t dma_buf[DMA_BUF_LEN] = {0};	// LED write buffer

static inline uint8_t scale8(uint8_t x, uint8_t scale) {
  return ((uint16_t)x * scale) >> 8;
}

// Set a single color (RGB) to index
void led_set_RGB(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
#if (NUM_BPP == 4) // SK6812
  rgb_arr[4 * index] 		= scale8(g, 0xB0); // g;
  rgb_arr[4 * index + 1] 	= r;
  rgb_arr[4 * index + 2] 	= scale8(b, 0xF0); // b;
  rgb_arr[4 * index + 3] 	= 0;
#else // WS2812B
  rgb_arr[3 * index] = scale8(g, 0xB0); // g;
  rgb_arr[3 * index + 1] 	= r;
  rgb_arr[3 * index + 2] 	= scale8(b, 0xF0); // b;
#endif // End SK6812 WS2812B case differentiation
}

uint32_t led_get_RGB(uint8_t index){
	uint32_t color = 0;
#if (NUM_BPP == 4) // SK6812
	color |= rgb_arr[4 * index] 	<< 8 ; //g
	color |= rgb_arr[4 * index + 1] << 16; //r
	color |= rgb_arr[4 * index + 2] << 0;  //b
	color |= rgb_arr[4 * index + 3] << 24;
#else // WS2812B
	color |= rgb_arr[3 * index] 	<< 8;  //g
	color |= rgb_arr[3 * index + 1] << 16; //r
	color |= rgb_arr[3 * index + 2] << 0;  //b
#endif // End SK6812 WS2812B case differentiation
	return color;
}

// Set a single color (RGBW) to index
void led_set_RGBW(uint8_t index, uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
	led_set_RGB(index, r, g, b);
#if (NUM_BPP == 4) // SK6812
	rgb_arr[4 * index + 3] = w;
#endif // End SK6812 WS2812B case differentiation
}

int led_render() {
	  if(TIMER_DMA.State != HAL_DMA_STATE_READY) return -1;
	  for(uint16_t i=0; i<RGB_BUF_LEN; i++){
		  for(uint16_t j=0; j<8; j++) {
			  dma_buf[8*i + j] = PWM_LO << (((rgb_arr[i] << j) & 0x80) == 0x80);
		  }
	  }
	  for(uint16_t j=(RGB_BUF_LEN*8); j<DMA_BUF_LEN; j++) {
		  dma_buf[j] = 0;
	  }
	  HAL_TIM_PWM_Start_DMA(&TIMER, TIMER_CHANNEL, (uint32_t *)dma_buf, DMA_BUF_LEN);
	  return 0;
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim) {
	HAL_TIM_PWM_Stop_DMA(&TIMER, TIMER_CHANNEL);
}

#endif
