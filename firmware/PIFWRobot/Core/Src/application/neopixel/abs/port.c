// Peripheral usage
#include <string.h>

#include "stm32f1xx_hal.h"

#include "../config.h"
#include "port.h"

extern TIM_HandleTypeDef TIMER;
extern DMA_HandleTypeDef TIMER_DMA;

// LED color buffer
uint8_t rgb_arr[NUM_BYTES] = {0};

// LED write buffer
#define WR_BUF_LEN (NUM_BPP * 8 * 2)
uint8_t wr_buf[WR_BUF_LEN] = {0};
uint_fast8_t wr_buf_p = 0;

static inline uint8_t scale8(uint8_t x, uint8_t scale) {
  return ((uint16_t)x * scale) >> 8;
}

// Set a single color (RGB) to index
void led_set_RGB(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
#if (NUM_BPP == 4) // SK6812
  rgb_arr[4 * index] = scale8(g, 0xB0); // g;
  rgb_arr[4 * index + 1] = r;
  rgb_arr[4 * index + 2] = scale8(b, 0xF0); // b;
  rgb_arr[4 * index + 3] = 0;
#else // WS2812B
  rgb_arr[3 * index] = scale8(g, 0xB0); // g;
  rgb_arr[3 * index + 1] = r;
  rgb_arr[3 * index + 2] = scale8(b, 0xF0); // b;
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

// Shuttle the data to the LEDs!
void led_render() {
  if(wr_buf_p != 0 || TIMER_DMA.State != HAL_DMA_STATE_READY) {
    // Ongoing transfer, cancel!
    for(uint8_t i = 0; i < WR_BUF_LEN; ++i) wr_buf[i] = 0;
    wr_buf_p = 0;
    HAL_TIM_PWM_Stop_DMA(&TIMER, TIMER_CHANNEL);
    return;
  }
  // Ooh boi the first data buffer half (and the second!)
#if (NUM_BPP == 4) // SK6812
  for(uint_fast8_t i = 0; i < 8; ++i) {
    wr_buf[i     ] = PWM_LO << (((rgb_arr[0] << i) & 0x80) > 0);
    wr_buf[i +  8] = PWM_LO << (((rgb_arr[1] << i) & 0x80) > 0);
    wr_buf[i + 16] = PWM_LO << (((rgb_arr[2] << i) & 0x80) > 0);
    wr_buf[i + 24] = PWM_LO << (((rgb_arr[3] << i) & 0x80) > 0);
    wr_buf[i + 32] = PWM_LO << (((rgb_arr[4] << i) & 0x80) > 0);
    wr_buf[i + 40] = PWM_LO << (((rgb_arr[5] << i) & 0x80) > 0);
    wr_buf[i + 48] = PWM_LO << (((rgb_arr[6] << i) & 0x80) > 0);
    wr_buf[i + 56] = PWM_LO << (((rgb_arr[7] << i) & 0x80) > 0);
  }
#else // WS2812B
  for(uint_fast8_t i = 0; i < 8; ++i) {
    wr_buf[i     ] = PWM_LO << (((rgb_arr[0] << i) & 0x80) > 0);
    wr_buf[i +  8] = PWM_LO << (((rgb_arr[1] << i) & 0x80) > 0);
    wr_buf[i + 16] = PWM_LO << (((rgb_arr[2] << i) & 0x80) > 0);
    wr_buf[i + 24] = PWM_LO << (((rgb_arr[3] << i) & 0x80) > 0);
    wr_buf[i + 32] = PWM_LO << (((rgb_arr[4] << i) & 0x80) > 0);
    wr_buf[i + 40] = PWM_LO << (((rgb_arr[5] << i) & 0x80) > 0);
  }
#endif // End SK6812 WS2812B case differentiation

  HAL_TIM_PWM_Start_DMA(&TIMER, TIMER_CHANNEL, (uint32_t *)wr_buf, WR_BUF_LEN);
  wr_buf_p = 2; // Since we're ready for the next buffer
}

void HAL_TIM_PWM_PulseFinishedHalfCpltCallback(TIM_HandleTypeDef *htim) {
  // DMA buffer set from LED(wr_buf_p) to LED(wr_buf_p + 1)
  if(wr_buf_p < NUM_PIXELS) {
    // We're in. Fill the even buffer
#if (NUM_BPP == 4) // SK6812
    for(uint_fast8_t i = 0; i < 8; ++i) {
      wr_buf[i     ] = PWM_LO << (((rgb_arr[4 * wr_buf_p    ] << i) & 0x80) > 0);
      wr_buf[i +  8] = PWM_LO << (((rgb_arr[4 * wr_buf_p + 1] << i) & 0x80) > 0);
      wr_buf[i + 16] = PWM_LO << (((rgb_arr[4 * wr_buf_p + 2] << i) & 0x80) > 0);
      wr_buf[i + 24] = PWM_LO << (((rgb_arr[4 * wr_buf_p + 3] << i) & 0x80) > 0);
    }
#else // WS2812B
    for(uint_fast8_t i = 0; i < 8; ++i) {
      wr_buf[i     ] = PWM_LO << (((rgb_arr[3 * wr_buf_p    ] << i) & 0x80) > 0);
      wr_buf[i +  8] = PWM_LO << (((rgb_arr[3 * wr_buf_p + 1] << i) & 0x80) > 0);
      wr_buf[i + 16] = PWM_LO << (((rgb_arr[3 * wr_buf_p + 2] << i) & 0x80) > 0);
    }
#endif // End SK6812 WS2812B case differentiation
    wr_buf_p++;
  } else if (wr_buf_p < NUM_PIXELS + 2) {
    // Last two transfers are resets. SK6812: 64 * 1.25 us = 80 us == good enough reset
  	//                               WS2812B: 48 * 1.25 us = 60 us == good enough reset
    // First half reset zero fill
    for(uint8_t i = 0; i < WR_BUF_LEN / 2; ++i) wr_buf[i] = 0;
    wr_buf_p++;
  }
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim) {
  // DMA buffer set from LED(wr_buf_p) to LED(wr_buf_p + 1)
  if(wr_buf_p < NUM_PIXELS) {
    // We're in. Fill the odd buffer
#if (NUM_BPP == 4) // SK6812
    for(uint_fast8_t i = 0; i < 8; ++i) {
      wr_buf[i + 32] = PWM_LO << (((rgb_arr[4 * wr_buf_p    ] << i) & 0x80) > 0);
      wr_buf[i + 40] = PWM_LO << (((rgb_arr[4 * wr_buf_p + 1] << i) & 0x80) > 0);
      wr_buf[i + 48] = PWM_LO << (((rgb_arr[4 * wr_buf_p + 2] << i) & 0x80) > 0);
      wr_buf[i + 56] = PWM_LO << (((rgb_arr[4 * wr_buf_p + 3] << i) & 0x80) > 0);
    }
#else // WS2812B
    for(uint_fast8_t i = 0; i < 8; ++i) {
      wr_buf[i + 24] = PWM_LO << (((rgb_arr[3 * wr_buf_p    ] << i) & 0x80) > 0);
      wr_buf[i + 32] = PWM_LO << (((rgb_arr[3 * wr_buf_p + 1] << i) & 0x80) > 0);
      wr_buf[i + 40] = PWM_LO << (((rgb_arr[3 * wr_buf_p + 2] << i) & 0x80) > 0);
    }
#endif // End SK6812 WS2812B case differentiation
    wr_buf_p++;
  } else if (wr_buf_p < NUM_PIXELS + 2) {
    // Second half reset zero fill
    for(uint8_t i = WR_BUF_LEN / 2; i < WR_BUF_LEN; ++i) wr_buf[i] = 0;
    ++wr_buf_p;
  } else {
    // We're done. Lean back and until next time!
    wr_buf_p = 0;
    HAL_TIM_PWM_Stop_DMA(&TIMER, TIMER_CHANNEL);
  }
}
