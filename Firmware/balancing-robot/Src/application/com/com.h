/*
 * Com.h
 *
 *  Created on: Oct 10, 2019
 *      Author: 16138
 */

#ifndef APPLICATION_COM_COM_H_
#define APPLICATION_COM_COM_H_

#include <application/com/mavlink/protocol/mavlink.h>
#include <application/com/serial/Serial.h>

typedef void (*on_mav_recv_t)(mavlink_message_t*);

// Initialize communication over mavlink/uart
void com_init();

// Send mavlink packet
void com_send(uint8_t *data, uint16_t len);

// Receive mavlink packet
void com_set_on_mav_recv(on_mav_recv_t on_mav_recv);

// Quick respond OK for a command
void respond_ok(void);

#endif /* APPLICATION_COM_COM_H_ */
