/*
 * Com.h
 *
 *  Created on: Oct 10, 2019
 *      Author: 16138
 */

#ifndef APPLICATION_MAV_MAV_H_
#define APPLICATION_MAV_MAV_H_

#include <application/mav/mavlink/protocol/mavlink.h>
#include <application/mav/uart/uart.h>

typedef void (*on_mav_recv_t)(mavlink_message_t*);

// Initialize communication over mavlink/uart
void mav_init();

// Send mavlink packet
void mav_send(char *data, uint16_t len);

// Receive mavlink packet
void mav_set_on_mav_recv(on_mav_recv_t on_mav_recv);

// Quick respond OK for a command
void respond_ok(void);
void respond_error(void);

#endif /* APPLICATION_MAV_MAV_H_ */
