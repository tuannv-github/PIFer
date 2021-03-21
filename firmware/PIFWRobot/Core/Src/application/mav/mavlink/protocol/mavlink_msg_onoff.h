#pragma once
// MESSAGE ONOFF PACKING

#define MAVLINK_MSG_ID_ONOFF 20


typedef struct __mavlink_onoff_t {
 uint16_t uwb_address; /*<  */
 uint8_t value; /*<  */
} mavlink_onoff_t;

#define MAVLINK_MSG_ID_ONOFF_LEN 3
#define MAVLINK_MSG_ID_ONOFF_MIN_LEN 3
#define MAVLINK_MSG_ID_20_LEN 3
#define MAVLINK_MSG_ID_20_MIN_LEN 3

#define MAVLINK_MSG_ID_ONOFF_CRC 35
#define MAVLINK_MSG_ID_20_CRC 35



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ONOFF { \
    20, \
    "ONOFF", \
    2, \
    {  { "uwb_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_onoff_t, uwb_address) }, \
         { "value", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_onoff_t, value) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ONOFF { \
    "ONOFF", \
    2, \
    {  { "uwb_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_onoff_t, uwb_address) }, \
         { "value", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_onoff_t, value) }, \
         } \
}
#endif

/**
 * @brief Pack a onoff message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uwb_address  
 * @param value  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_onoff_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t uwb_address, uint8_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ONOFF_LEN];
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint8_t(buf, 2, value);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ONOFF_LEN);
#else
    mavlink_onoff_t packet;
    packet.uwb_address = uwb_address;
    packet.value = value;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ONOFF_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ONOFF;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ONOFF_MIN_LEN, MAVLINK_MSG_ID_ONOFF_LEN, MAVLINK_MSG_ID_ONOFF_CRC);
}

/**
 * @brief Pack a onoff message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uwb_address  
 * @param value  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_onoff_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t uwb_address,uint8_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ONOFF_LEN];
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint8_t(buf, 2, value);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ONOFF_LEN);
#else
    mavlink_onoff_t packet;
    packet.uwb_address = uwb_address;
    packet.value = value;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ONOFF_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ONOFF;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ONOFF_MIN_LEN, MAVLINK_MSG_ID_ONOFF_LEN, MAVLINK_MSG_ID_ONOFF_CRC);
}

/**
 * @brief Encode a onoff struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param onoff C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_onoff_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_onoff_t* onoff)
{
    return mavlink_msg_onoff_pack(system_id, component_id, msg, onoff->uwb_address, onoff->value);
}

/**
 * @brief Encode a onoff struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param onoff C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_onoff_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_onoff_t* onoff)
{
    return mavlink_msg_onoff_pack_chan(system_id, component_id, chan, msg, onoff->uwb_address, onoff->value);
}

/**
 * @brief Send a onoff message
 * @param chan MAVLink channel to send the message
 *
 * @param uwb_address  
 * @param value  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_onoff_send(mavlink_channel_t chan, uint16_t uwb_address, uint8_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ONOFF_LEN];
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint8_t(buf, 2, value);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ONOFF, buf, MAVLINK_MSG_ID_ONOFF_MIN_LEN, MAVLINK_MSG_ID_ONOFF_LEN, MAVLINK_MSG_ID_ONOFF_CRC);
#else
    mavlink_onoff_t packet;
    packet.uwb_address = uwb_address;
    packet.value = value;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ONOFF, (const char *)&packet, MAVLINK_MSG_ID_ONOFF_MIN_LEN, MAVLINK_MSG_ID_ONOFF_LEN, MAVLINK_MSG_ID_ONOFF_CRC);
#endif
}

/**
 * @brief Send a onoff message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_onoff_send_struct(mavlink_channel_t chan, const mavlink_onoff_t* onoff)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_onoff_send(chan, onoff->uwb_address, onoff->value);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ONOFF, (const char *)onoff, MAVLINK_MSG_ID_ONOFF_MIN_LEN, MAVLINK_MSG_ID_ONOFF_LEN, MAVLINK_MSG_ID_ONOFF_CRC);
#endif
}

#if MAVLINK_MSG_ID_ONOFF_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_onoff_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t uwb_address, uint8_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint8_t(buf, 2, value);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ONOFF, buf, MAVLINK_MSG_ID_ONOFF_MIN_LEN, MAVLINK_MSG_ID_ONOFF_LEN, MAVLINK_MSG_ID_ONOFF_CRC);
#else
    mavlink_onoff_t *packet = (mavlink_onoff_t *)msgbuf;
    packet->uwb_address = uwb_address;
    packet->value = value;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ONOFF, (const char *)packet, MAVLINK_MSG_ID_ONOFF_MIN_LEN, MAVLINK_MSG_ID_ONOFF_LEN, MAVLINK_MSG_ID_ONOFF_CRC);
#endif
}
#endif

#endif

// MESSAGE ONOFF UNPACKING


/**
 * @brief Get field uwb_address from onoff message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_onoff_get_uwb_address(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field value from onoff message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_onoff_get_value(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a onoff message into a struct
 *
 * @param msg The message to decode
 * @param onoff C-struct to decode the message contents into
 */
static inline void mavlink_msg_onoff_decode(const mavlink_message_t* msg, mavlink_onoff_t* onoff)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    onoff->uwb_address = mavlink_msg_onoff_get_uwb_address(msg);
    onoff->value = mavlink_msg_onoff_get_value(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ONOFF_LEN? msg->len : MAVLINK_MSG_ID_ONOFF_LEN;
        memset(onoff, 0, MAVLINK_MSG_ID_ONOFF_LEN);
    memcpy(onoff, _MAV_PAYLOAD(msg), len);
#endif
}
