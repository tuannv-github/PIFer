#pragma once
// MESSAGE GYRO_PARAMS PACKING

#define MAVLINK_MSG_ID_GYRO_PARAMS 9


typedef struct __mavlink_gyro_params_t {
 float gyro_offset_x; /*<  Gyro Offset X*/
 float gyro_offset_y; /*<  Gyro Offset Y*/
 float gyro_offset_z; /*<  Gyro Offset Z*/
} mavlink_gyro_params_t;

#define MAVLINK_MSG_ID_GYRO_PARAMS_LEN 12
#define MAVLINK_MSG_ID_GYRO_PARAMS_MIN_LEN 12
#define MAVLINK_MSG_ID_9_LEN 12
#define MAVLINK_MSG_ID_9_MIN_LEN 12

#define MAVLINK_MSG_ID_GYRO_PARAMS_CRC 249
#define MAVLINK_MSG_ID_9_CRC 249



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GYRO_PARAMS { \
    9, \
    "GYRO_PARAMS", \
    3, \
    {  { "gyro_offset_x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_gyro_params_t, gyro_offset_x) }, \
         { "gyro_offset_y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_gyro_params_t, gyro_offset_y) }, \
         { "gyro_offset_z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gyro_params_t, gyro_offset_z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GYRO_PARAMS { \
    "GYRO_PARAMS", \
    3, \
    {  { "gyro_offset_x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_gyro_params_t, gyro_offset_x) }, \
         { "gyro_offset_y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_gyro_params_t, gyro_offset_y) }, \
         { "gyro_offset_z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gyro_params_t, gyro_offset_z) }, \
         } \
}
#endif

/**
 * @brief Pack a gyro_params message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param gyro_offset_x  Gyro Offset X
 * @param gyro_offset_y  Gyro Offset Y
 * @param gyro_offset_z  Gyro Offset Z
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gyro_params_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float gyro_offset_x, float gyro_offset_y, float gyro_offset_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GYRO_PARAMS_LEN];
    _mav_put_float(buf, 0, gyro_offset_x);
    _mav_put_float(buf, 4, gyro_offset_y);
    _mav_put_float(buf, 8, gyro_offset_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GYRO_PARAMS_LEN);
#else
    mavlink_gyro_params_t packet;
    packet.gyro_offset_x = gyro_offset_x;
    packet.gyro_offset_y = gyro_offset_y;
    packet.gyro_offset_z = gyro_offset_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GYRO_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GYRO_PARAMS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GYRO_PARAMS_MIN_LEN, MAVLINK_MSG_ID_GYRO_PARAMS_LEN, MAVLINK_MSG_ID_GYRO_PARAMS_CRC);
}

/**
 * @brief Pack a gyro_params message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gyro_offset_x  Gyro Offset X
 * @param gyro_offset_y  Gyro Offset Y
 * @param gyro_offset_z  Gyro Offset Z
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gyro_params_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float gyro_offset_x,float gyro_offset_y,float gyro_offset_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GYRO_PARAMS_LEN];
    _mav_put_float(buf, 0, gyro_offset_x);
    _mav_put_float(buf, 4, gyro_offset_y);
    _mav_put_float(buf, 8, gyro_offset_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GYRO_PARAMS_LEN);
#else
    mavlink_gyro_params_t packet;
    packet.gyro_offset_x = gyro_offset_x;
    packet.gyro_offset_y = gyro_offset_y;
    packet.gyro_offset_z = gyro_offset_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GYRO_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GYRO_PARAMS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GYRO_PARAMS_MIN_LEN, MAVLINK_MSG_ID_GYRO_PARAMS_LEN, MAVLINK_MSG_ID_GYRO_PARAMS_CRC);
}

/**
 * @brief Encode a gyro_params struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gyro_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gyro_params_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gyro_params_t* gyro_params)
{
    return mavlink_msg_gyro_params_pack(system_id, component_id, msg, gyro_params->gyro_offset_x, gyro_params->gyro_offset_y, gyro_params->gyro_offset_z);
}

/**
 * @brief Encode a gyro_params struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gyro_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gyro_params_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gyro_params_t* gyro_params)
{
    return mavlink_msg_gyro_params_pack_chan(system_id, component_id, chan, msg, gyro_params->gyro_offset_x, gyro_params->gyro_offset_y, gyro_params->gyro_offset_z);
}

/**
 * @brief Send a gyro_params message
 * @param chan MAVLink channel to send the message
 *
 * @param gyro_offset_x  Gyro Offset X
 * @param gyro_offset_y  Gyro Offset Y
 * @param gyro_offset_z  Gyro Offset Z
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gyro_params_send(mavlink_channel_t chan, float gyro_offset_x, float gyro_offset_y, float gyro_offset_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GYRO_PARAMS_LEN];
    _mav_put_float(buf, 0, gyro_offset_x);
    _mav_put_float(buf, 4, gyro_offset_y);
    _mav_put_float(buf, 8, gyro_offset_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GYRO_PARAMS, buf, MAVLINK_MSG_ID_GYRO_PARAMS_MIN_LEN, MAVLINK_MSG_ID_GYRO_PARAMS_LEN, MAVLINK_MSG_ID_GYRO_PARAMS_CRC);
#else
    mavlink_gyro_params_t packet;
    packet.gyro_offset_x = gyro_offset_x;
    packet.gyro_offset_y = gyro_offset_y;
    packet.gyro_offset_z = gyro_offset_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GYRO_PARAMS, (const char *)&packet, MAVLINK_MSG_ID_GYRO_PARAMS_MIN_LEN, MAVLINK_MSG_ID_GYRO_PARAMS_LEN, MAVLINK_MSG_ID_GYRO_PARAMS_CRC);
#endif
}

/**
 * @brief Send a gyro_params message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gyro_params_send_struct(mavlink_channel_t chan, const mavlink_gyro_params_t* gyro_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gyro_params_send(chan, gyro_params->gyro_offset_x, gyro_params->gyro_offset_y, gyro_params->gyro_offset_z);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GYRO_PARAMS, (const char *)gyro_params, MAVLINK_MSG_ID_GYRO_PARAMS_MIN_LEN, MAVLINK_MSG_ID_GYRO_PARAMS_LEN, MAVLINK_MSG_ID_GYRO_PARAMS_CRC);
#endif
}

#if MAVLINK_MSG_ID_GYRO_PARAMS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gyro_params_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float gyro_offset_x, float gyro_offset_y, float gyro_offset_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, gyro_offset_x);
    _mav_put_float(buf, 4, gyro_offset_y);
    _mav_put_float(buf, 8, gyro_offset_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GYRO_PARAMS, buf, MAVLINK_MSG_ID_GYRO_PARAMS_MIN_LEN, MAVLINK_MSG_ID_GYRO_PARAMS_LEN, MAVLINK_MSG_ID_GYRO_PARAMS_CRC);
#else
    mavlink_gyro_params_t *packet = (mavlink_gyro_params_t *)msgbuf;
    packet->gyro_offset_x = gyro_offset_x;
    packet->gyro_offset_y = gyro_offset_y;
    packet->gyro_offset_z = gyro_offset_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GYRO_PARAMS, (const char *)packet, MAVLINK_MSG_ID_GYRO_PARAMS_MIN_LEN, MAVLINK_MSG_ID_GYRO_PARAMS_LEN, MAVLINK_MSG_ID_GYRO_PARAMS_CRC);
#endif
}
#endif

#endif

// MESSAGE GYRO_PARAMS UNPACKING


/**
 * @brief Get field gyro_offset_x from gyro_params message
 *
 * @return  Gyro Offset X
 */
static inline float mavlink_msg_gyro_params_get_gyro_offset_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field gyro_offset_y from gyro_params message
 *
 * @return  Gyro Offset Y
 */
static inline float mavlink_msg_gyro_params_get_gyro_offset_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field gyro_offset_z from gyro_params message
 *
 * @return  Gyro Offset Z
 */
static inline float mavlink_msg_gyro_params_get_gyro_offset_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a gyro_params message into a struct
 *
 * @param msg The message to decode
 * @param gyro_params C-struct to decode the message contents into
 */
static inline void mavlink_msg_gyro_params_decode(const mavlink_message_t* msg, mavlink_gyro_params_t* gyro_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    gyro_params->gyro_offset_x = mavlink_msg_gyro_params_get_gyro_offset_x(msg);
    gyro_params->gyro_offset_y = mavlink_msg_gyro_params_get_gyro_offset_y(msg);
    gyro_params->gyro_offset_z = mavlink_msg_gyro_params_get_gyro_offset_z(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GYRO_PARAMS_LEN? msg->len : MAVLINK_MSG_ID_GYRO_PARAMS_LEN;
        memset(gyro_params, 0, MAVLINK_MSG_ID_GYRO_PARAMS_LEN);
    memcpy(gyro_params, _MAV_PAYLOAD(msg), len);
#endif
}
