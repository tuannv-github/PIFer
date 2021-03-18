#pragma once
// MESSAGE DISTANCE PACKING

#define MAVLINK_MSG_ID_DISTANCE 22


typedef struct __mavlink_distance_t {
 float distance; /*<  */
 uint16_t uwb_address; /*<  */
 uint16_t anchor; /*<  */
} mavlink_distance_t;

#define MAVLINK_MSG_ID_DISTANCE_LEN 8
#define MAVLINK_MSG_ID_DISTANCE_MIN_LEN 8
#define MAVLINK_MSG_ID_22_LEN 8
#define MAVLINK_MSG_ID_22_MIN_LEN 8

#define MAVLINK_MSG_ID_DISTANCE_CRC 33
#define MAVLINK_MSG_ID_22_CRC 33



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DISTANCE { \
    22, \
    "DISTANCE", \
    3, \
    {  { "uwb_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_distance_t, uwb_address) }, \
         { "anchor", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_distance_t, anchor) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_distance_t, distance) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DISTANCE { \
    "DISTANCE", \
    3, \
    {  { "uwb_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_distance_t, uwb_address) }, \
         { "anchor", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_distance_t, anchor) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_distance_t, distance) }, \
         } \
}
#endif

/**
 * @brief Pack a distance message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uwb_address  
 * @param anchor  
 * @param distance  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_distance_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t uwb_address, uint16_t anchor, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DISTANCE_LEN];
    _mav_put_float(buf, 0, distance);
    _mav_put_uint16_t(buf, 4, uwb_address);
    _mav_put_uint16_t(buf, 6, anchor);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DISTANCE_LEN);
#else
    mavlink_distance_t packet;
    packet.distance = distance;
    packet.uwb_address = uwb_address;
    packet.anchor = anchor;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DISTANCE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DISTANCE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_LEN, MAVLINK_MSG_ID_DISTANCE_CRC);
}

/**
 * @brief Pack a distance message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uwb_address  
 * @param anchor  
 * @param distance  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_distance_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t uwb_address,uint16_t anchor,float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DISTANCE_LEN];
    _mav_put_float(buf, 0, distance);
    _mav_put_uint16_t(buf, 4, uwb_address);
    _mav_put_uint16_t(buf, 6, anchor);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DISTANCE_LEN);
#else
    mavlink_distance_t packet;
    packet.distance = distance;
    packet.uwb_address = uwb_address;
    packet.anchor = anchor;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DISTANCE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DISTANCE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_LEN, MAVLINK_MSG_ID_DISTANCE_CRC);
}

/**
 * @brief Encode a distance struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param distance C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_distance_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_distance_t* distance)
{
    return mavlink_msg_distance_pack(system_id, component_id, msg, distance->uwb_address, distance->anchor, distance->distance);
}

/**
 * @brief Encode a distance struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param distance C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_distance_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_distance_t* distance)
{
    return mavlink_msg_distance_pack_chan(system_id, component_id, chan, msg, distance->uwb_address, distance->anchor, distance->distance);
}

/**
 * @brief Send a distance message
 * @param chan MAVLink channel to send the message
 *
 * @param uwb_address  
 * @param anchor  
 * @param distance  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_distance_send(mavlink_channel_t chan, uint16_t uwb_address, uint16_t anchor, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DISTANCE_LEN];
    _mav_put_float(buf, 0, distance);
    _mav_put_uint16_t(buf, 4, uwb_address);
    _mav_put_uint16_t(buf, 6, anchor);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DISTANCE, buf, MAVLINK_MSG_ID_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_LEN, MAVLINK_MSG_ID_DISTANCE_CRC);
#else
    mavlink_distance_t packet;
    packet.distance = distance;
    packet.uwb_address = uwb_address;
    packet.anchor = anchor;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DISTANCE, (const char *)&packet, MAVLINK_MSG_ID_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_LEN, MAVLINK_MSG_ID_DISTANCE_CRC);
#endif
}

/**
 * @brief Send a distance message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_distance_send_struct(mavlink_channel_t chan, const mavlink_distance_t* distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_distance_send(chan, distance->uwb_address, distance->anchor, distance->distance);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DISTANCE, (const char *)distance, MAVLINK_MSG_ID_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_LEN, MAVLINK_MSG_ID_DISTANCE_CRC);
#endif
}

#if MAVLINK_MSG_ID_DISTANCE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_distance_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t uwb_address, uint16_t anchor, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, distance);
    _mav_put_uint16_t(buf, 4, uwb_address);
    _mav_put_uint16_t(buf, 6, anchor);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DISTANCE, buf, MAVLINK_MSG_ID_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_LEN, MAVLINK_MSG_ID_DISTANCE_CRC);
#else
    mavlink_distance_t *packet = (mavlink_distance_t *)msgbuf;
    packet->distance = distance;
    packet->uwb_address = uwb_address;
    packet->anchor = anchor;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DISTANCE, (const char *)packet, MAVLINK_MSG_ID_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_LEN, MAVLINK_MSG_ID_DISTANCE_CRC);
#endif
}
#endif

#endif

// MESSAGE DISTANCE UNPACKING


/**
 * @brief Get field uwb_address from distance message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_distance_get_uwb_address(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field anchor from distance message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_distance_get_anchor(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field distance from distance message
 *
 * @return  
 */
static inline float mavlink_msg_distance_get_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a distance message into a struct
 *
 * @param msg The message to decode
 * @param distance C-struct to decode the message contents into
 */
static inline void mavlink_msg_distance_decode(const mavlink_message_t* msg, mavlink_distance_t* distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    distance->distance = mavlink_msg_distance_get_distance(msg);
    distance->uwb_address = mavlink_msg_distance_get_uwb_address(msg);
    distance->anchor = mavlink_msg_distance_get_anchor(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DISTANCE_LEN? msg->len : MAVLINK_MSG_ID_DISTANCE_LEN;
        memset(distance, 0, MAVLINK_MSG_ID_DISTANCE_LEN);
    memcpy(distance, _MAV_PAYLOAD(msg), len);
#endif
}
