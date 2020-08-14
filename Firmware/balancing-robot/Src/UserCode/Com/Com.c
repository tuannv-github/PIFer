/*
 * Com.c
 *
 *  Created on: Oct 10, 2019
 *      Author: 16138
 */

#include "Com.h"
#include "usart.h"
#include "UserCode/user_define.h"
#include "UserCode/Timer/timer.h"

static uint8_t mavbuf[MAV_BUFF_SIZE];
static mavlink_message_t msg;
static mavlink_status_t  status;
static on_mav_recv_t gon_mav_recv;

static uart_drv_t uart_drv = {
		.huart = &COM_USART
};

void mavlink_callback(uint8_t* cntx){
	uint16_t mavbuf_len = MAV_BUFF_SIZE;
	uart_read(&uart_drv, mavbuf, &mavbuf_len);
	for(uint16_t i = 0; i < mavbuf_len; i++){
		uint8_t msg_received = mavlink_parse_char(MAVLINK_COMM_0, mavbuf[i], &msg, &status);
		if(msg_received == 1 && gon_mav_recv!=0){
			gon_mav_recv(&msg);
		}
	}
}

void com_init(){
	uart_init(&uart_drv);
	timer_register_callback(mavlink_callback, MAVLINK_CB_PERIOD, 0, TIMER_MODE_REPEAT);
}

void com_set_on_mav_recv(on_mav_recv_t on_mav_recv){
	gon_mav_recv = on_mav_recv;
}

void com_send(uint8_t *data, uint16_t len){
	uart_send(&uart_drv, data, len);
}

void respond_ok(void){
	mavlink_message_t msg;
	uint8_t gmav_send_buf[255];
	mavlink_msg_respond_pack(0,0,&msg,RESPOND_OK);
	uint16_t len = mavlink_msg_to_send_buffer(gmav_send_buf, &msg);
	com_send(gmav_send_buf, len);
}
