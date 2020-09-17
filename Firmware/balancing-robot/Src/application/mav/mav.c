/*
 * Com.c
 *
 *  Created on: Oct 10, 2019
 *      Author: 16138
 */

#include <application/mav/mav.h>
#include <application/timer/timer.h>
#include <application/user_define.h>
#include "usart.h"

static char mavbuf[MAV_BUFF_SIZE];
static mavlink_message_t msg;
static mavlink_status_t  status;
static on_mav_recv_t gon_mav_recv;

static uart_drv_t uart_drv[] = {
		{
			.huart = &SOU_USART,
			.cb_period = SOU_PERIOD,
		},
		{
			.huart = &SOE_USART,
			.cb_period = SOE_PERIOD,
		}

};

void mavlink_callback(void* ctx){
	uint16_t mavbuf_len;

	mavbuf_len = MAV_BUFF_SIZE;
	uart_recv(&uart_drv[0], mavbuf, &mavbuf_len);
	for(uint16_t i = 0; i < mavbuf_len; i++){
		uint8_t msg_received = mavlink_parse_char(MAVLINK_COMM_0, mavbuf[i], &msg, &status);
		if(msg_received == 1 && gon_mav_recv!=0){
			gon_mav_recv(&msg);
		}
	}

	mavbuf_len = MAV_BUFF_SIZE;
	uart_recv(&uart_drv[1], mavbuf, &mavbuf_len);
	for(uint16_t i = 0; i < mavbuf_len; i++){
		uint8_t msg_received = mavlink_parse_char(MAVLINK_COMM_1, mavbuf[i], &msg, &status);
		if(msg_received == 1 && gon_mav_recv!=0){
			gon_mav_recv(&msg);
		}
	}
}

void mav_init(){
	uart_init(&uart_drv[0]);
	uart_init(&uart_drv[1]);
	timer_register_callback(mavlink_callback, MAVLINK_CB_PERIOD, 0, TIMER_MODE_REPEAT);
}

void mav_set_on_mav_recv(on_mav_recv_t on_mav_recv){
	gon_mav_recv = on_mav_recv;
}

void mav_send(char *data, uint16_t len){
	uart_send(&uart_drv[0], data, len);
	uart_send(&uart_drv[1], data, len);
}

void respond_ok(void){
	mavlink_message_t msg;
	char gmav_send_buf[255];
	mavlink_msg_respond_pack(0,0,&msg,RESPOND_OK);
	uint16_t len = mavlink_msg_to_send_buffer((uint8_t*)gmav_send_buf, &msg);
	mav_send(gmav_send_buf, len);
}

void respond_error(void){
	mavlink_message_t msg;
	char gmav_send_buf[255];
	mavlink_msg_respond_pack(0,0,&msg,RESPOND_ERROR);
	uint16_t len = mavlink_msg_to_send_buffer((uint8_t*)gmav_send_buf, &msg);
	mav_send(gmav_send_buf, len);
}
