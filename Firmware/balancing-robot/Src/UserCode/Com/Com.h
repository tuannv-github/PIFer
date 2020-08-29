/*
 * Com.h
 *
 *  Created on: Oct 10, 2019
 *      Author: 16138
 */

#ifndef USERCODE_COM_COM_H_
#define USERCODE_COM_COM_H_

#include "UserCode/Com/Serial/Serial.h"
#include "UserCode/Com/Mav/protocol/mavlink.h"

typedef void (*on_mav_recv_t)(mavlink_message_t*);

// Initialize communication over mavlink/uart
void com_init();

// Send mavlink packet
// Packet have to be packed to an array with size len before sending
void com_send(uint8_t *data, uint16_t len);

// Receive mavlink packet
void com_set_on_mav_recv(on_mav_recv_t on_mav_recv);

// Quick respond OK for a command
void respond_ok(void);

#endif /* USERCODE_COM_COM_H_ */
