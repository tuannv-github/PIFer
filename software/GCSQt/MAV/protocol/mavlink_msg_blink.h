#pragma once
// MESSAGE BLINK PACKING

#define MAVLINK_MSG_ID_BLINK 19


typedef struct __mavlink_blink_t {
 uint16_t uwb_address; /*<  */
 uint8_t role; /*<  */
} mavlink_blink_t;

#define MAVLINK_MSG_ID_BLINK_LEN 3
#define MAVLINK_MSG_ID_BLINK_MIN_LEN 3
#define MAVLINK_MSG_ID_19_LEN 3
#define MAVLINK_MSG_ID_19_MIN_LEN 3

#define MAVLINK_MSG_ID_BLINK_CRC 92
#define MAVLINK_MSG_ID_19_CRC 92



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BLINK { \
    19, \
    "BLINK", \
    2, \
    {  { "uwb_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_blink_t, uwb_address) }, \
         { "role", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_blink_t, role) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BLINK { \
    "BLINK", \
    2, \
    {  { "uwb_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_blink_t, uwb_address) }, \
         { "role", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_blink_t, role) }, \
         } \
}
#endif

/**
 * @brief Pack a blink message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uwb_address  
 * @param role  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_blink_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t uwb_address, uint8_t role)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BLINK_LEN];
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint8_t(buf, 2, role);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BLINK_LEN);
#else
    mavlink_blink_t packet;
    packet.uwb_address = uwb_address;
    packet.role = role;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BLINK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BLINK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BLINK_MIN_LEN, MAVLINK_MSG_ID_BLINK_LEN, MAVLINK_MSG_ID_BLINK_CRC);
}

/**
 * @brief Pack a blink message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uwb_address  
 * @param role  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_blink_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t uwb_address,uint8_t role)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BLINK_LEN];
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint8_t(buf, 2, role);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BLINK_LEN);
#else
    mavlink_blink_t packet;
    packet.uwb_address = uwb_address;
    packet.role = role;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BLINK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BLINK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BLINK_MIN_LEN, MAVLINK_MSG_ID_BLINK_LEN, MAVLINK_MSG_ID_BLINK_CRC);
}

/**
 * @brief Encode a blink struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param blink C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_blink_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_blink_t* blink)
{
    return mavlink_msg_blink_pack(system_id, component_id, msg, blink->uwb_address, blink->role);
}

/**
 * @brief Encode a blink struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param blink C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_blink_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_blink_t* blink)
{
    return mavlink_msg_blink_pack_chan(system_id, component_id, chan, msg, blink->uwb_address, blink->role);
}

/**
 * @brief Send a blink message
 * @param chan MAVLink channel to send the message
 *
 * @param uwb_address  
 * @param role  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_blink_send(mavlink_channel_t chan, uint16_t uwb_address, uint8_t role)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BLINK_LEN];
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint8_t(buf, 2, role);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BLINK, buf, MAVLINK_MSG_ID_BLINK_MIN_LEN, MAVLINK_MSG_ID_BLINK_LEN, MAVLINK_MSG_ID_BLINK_CRC);
#else
    mavlink_blink_t packet;
    packet.uwb_address = uwb_address;
    packet.role = role;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BLINK, (const char *)&packet, MAVLINK_MSG_ID_BLINK_MIN_LEN, MAVLINK_MSG_ID_BLINK_LEN, MAVLINK_MSG_ID_BLINK_CRC);
#endif
}

/**
 * @brief Send a blink message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_blink_send_struct(mavlink_channel_t chan, const mavlink_blink_t* blink)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_blink_send(chan, blink->uwb_address, blink->role);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BLINK, (const char *)blink, MAVLINK_MSG_ID_BLINK_MIN_LEN, MAVLINK_MSG_ID_BLINK_LEN, MAVLINK_MSG_ID_BLINK_CRC);
#endif
}

#if MAVLINK_MSG_ID_BLINK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_blink_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t uwb_address, uint8_t role)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint8_t(buf, 2, role);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BLINK, buf, MAVLINK_MSG_ID_BLINK_MIN_LEN, MAVLINK_MSG_ID_BLINK_LEN, MAVLINK_MSG_ID_BLINK_CRC);
#else
    mavlink_blink_t *packet = (mavlink_blink_t *)msgbuf;
    packet->uwb_address = uwb_address;
    packet->role = role;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BLINK, (const char *)packet, MAVLINK_MSG_ID_BLINK_MIN_LEN, MAVLINK_MSG_ID_BLINK_LEN, MAVLINK_MSG_ID_BLINK_CRC);
#endif
}
#endif

#endif

// MESSAGE BLINK UNPACKING


/**
 * @brief Get field uwb_address from blink message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_blink_get_uwb_address(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field role from blink message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_blink_get_role(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a blink message into a struct
 *
 * @param msg The message to decode
 * @param blink C-struct to decode the message contents into
 */
static inline void mavlink_msg_blink_decode(const mavlink_message_t* msg, mavlink_blink_t* blink)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    blink->uwb_address = mavlink_msg_blink_get_uwb_address(msg);
    blink->role = mavlink_msg_blink_get_role(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_BLINK_LEN? msg->len : MAVLINK_MSG_ID_BLINK_LEN;
        memset(blink, 0, MAVLINK_MSG_ID_BLINK_LEN);
    memcpy(blink, _MAV_PAYLOAD(msg), len);
#endif
}
