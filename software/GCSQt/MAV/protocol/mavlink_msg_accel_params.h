#pragma once
// MESSAGE ACCEL_PARAMS PACKING

#define MAVLINK_MSG_ID_ACCEL_PARAMS 10


typedef struct __mavlink_accel_params_t {
 float accel_bias_x; /*<  */
 float accel_bias_y; /*<  */
 float accel_bias_z; /*<  */
} mavlink_accel_params_t;

#define MAVLINK_MSG_ID_ACCEL_PARAMS_LEN 12
#define MAVLINK_MSG_ID_ACCEL_PARAMS_MIN_LEN 12
#define MAVLINK_MSG_ID_10_LEN 12
#define MAVLINK_MSG_ID_10_MIN_LEN 12

#define MAVLINK_MSG_ID_ACCEL_PARAMS_CRC 8
#define MAVLINK_MSG_ID_10_CRC 8



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ACCEL_PARAMS { \
    10, \
    "ACCEL_PARAMS", \
    3, \
    {  { "accel_bias_x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_accel_params_t, accel_bias_x) }, \
         { "accel_bias_y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_accel_params_t, accel_bias_y) }, \
         { "accel_bias_z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_accel_params_t, accel_bias_z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ACCEL_PARAMS { \
    "ACCEL_PARAMS", \
    3, \
    {  { "accel_bias_x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_accel_params_t, accel_bias_x) }, \
         { "accel_bias_y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_accel_params_t, accel_bias_y) }, \
         { "accel_bias_z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_accel_params_t, accel_bias_z) }, \
         } \
}
#endif

/**
 * @brief Pack a accel_params message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param accel_bias_x  
 * @param accel_bias_y  
 * @param accel_bias_z  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_accel_params_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float accel_bias_x, float accel_bias_y, float accel_bias_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ACCEL_PARAMS_LEN];
    _mav_put_float(buf, 0, accel_bias_x);
    _mav_put_float(buf, 4, accel_bias_y);
    _mav_put_float(buf, 8, accel_bias_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ACCEL_PARAMS_LEN);
#else
    mavlink_accel_params_t packet;
    packet.accel_bias_x = accel_bias_x;
    packet.accel_bias_y = accel_bias_y;
    packet.accel_bias_z = accel_bias_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ACCEL_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ACCEL_PARAMS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ACCEL_PARAMS_MIN_LEN, MAVLINK_MSG_ID_ACCEL_PARAMS_LEN, MAVLINK_MSG_ID_ACCEL_PARAMS_CRC);
}

/**
 * @brief Pack a accel_params message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param accel_bias_x  
 * @param accel_bias_y  
 * @param accel_bias_z  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_accel_params_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float accel_bias_x,float accel_bias_y,float accel_bias_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ACCEL_PARAMS_LEN];
    _mav_put_float(buf, 0, accel_bias_x);
    _mav_put_float(buf, 4, accel_bias_y);
    _mav_put_float(buf, 8, accel_bias_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ACCEL_PARAMS_LEN);
#else
    mavlink_accel_params_t packet;
    packet.accel_bias_x = accel_bias_x;
    packet.accel_bias_y = accel_bias_y;
    packet.accel_bias_z = accel_bias_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ACCEL_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ACCEL_PARAMS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ACCEL_PARAMS_MIN_LEN, MAVLINK_MSG_ID_ACCEL_PARAMS_LEN, MAVLINK_MSG_ID_ACCEL_PARAMS_CRC);
}

/**
 * @brief Encode a accel_params struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param accel_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_accel_params_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_accel_params_t* accel_params)
{
    return mavlink_msg_accel_params_pack(system_id, component_id, msg, accel_params->accel_bias_x, accel_params->accel_bias_y, accel_params->accel_bias_z);
}

/**
 * @brief Encode a accel_params struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param accel_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_accel_params_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_accel_params_t* accel_params)
{
    return mavlink_msg_accel_params_pack_chan(system_id, component_id, chan, msg, accel_params->accel_bias_x, accel_params->accel_bias_y, accel_params->accel_bias_z);
}

/**
 * @brief Send a accel_params message
 * @param chan MAVLink channel to send the message
 *
 * @param accel_bias_x  
 * @param accel_bias_y  
 * @param accel_bias_z  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_accel_params_send(mavlink_channel_t chan, float accel_bias_x, float accel_bias_y, float accel_bias_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ACCEL_PARAMS_LEN];
    _mav_put_float(buf, 0, accel_bias_x);
    _mav_put_float(buf, 4, accel_bias_y);
    _mav_put_float(buf, 8, accel_bias_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACCEL_PARAMS, buf, MAVLINK_MSG_ID_ACCEL_PARAMS_MIN_LEN, MAVLINK_MSG_ID_ACCEL_PARAMS_LEN, MAVLINK_MSG_ID_ACCEL_PARAMS_CRC);
#else
    mavlink_accel_params_t packet;
    packet.accel_bias_x = accel_bias_x;
    packet.accel_bias_y = accel_bias_y;
    packet.accel_bias_z = accel_bias_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACCEL_PARAMS, (const char *)&packet, MAVLINK_MSG_ID_ACCEL_PARAMS_MIN_LEN, MAVLINK_MSG_ID_ACCEL_PARAMS_LEN, MAVLINK_MSG_ID_ACCEL_PARAMS_CRC);
#endif
}

/**
 * @brief Send a accel_params message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_accel_params_send_struct(mavlink_channel_t chan, const mavlink_accel_params_t* accel_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_accel_params_send(chan, accel_params->accel_bias_x, accel_params->accel_bias_y, accel_params->accel_bias_z);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACCEL_PARAMS, (const char *)accel_params, MAVLINK_MSG_ID_ACCEL_PARAMS_MIN_LEN, MAVLINK_MSG_ID_ACCEL_PARAMS_LEN, MAVLINK_MSG_ID_ACCEL_PARAMS_CRC);
#endif
}

#if MAVLINK_MSG_ID_ACCEL_PARAMS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_accel_params_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float accel_bias_x, float accel_bias_y, float accel_bias_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, accel_bias_x);
    _mav_put_float(buf, 4, accel_bias_y);
    _mav_put_float(buf, 8, accel_bias_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACCEL_PARAMS, buf, MAVLINK_MSG_ID_ACCEL_PARAMS_MIN_LEN, MAVLINK_MSG_ID_ACCEL_PARAMS_LEN, MAVLINK_MSG_ID_ACCEL_PARAMS_CRC);
#else
    mavlink_accel_params_t *packet = (mavlink_accel_params_t *)msgbuf;
    packet->accel_bias_x = accel_bias_x;
    packet->accel_bias_y = accel_bias_y;
    packet->accel_bias_z = accel_bias_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACCEL_PARAMS, (const char *)packet, MAVLINK_MSG_ID_ACCEL_PARAMS_MIN_LEN, MAVLINK_MSG_ID_ACCEL_PARAMS_LEN, MAVLINK_MSG_ID_ACCEL_PARAMS_CRC);
#endif
}
#endif

#endif

// MESSAGE ACCEL_PARAMS UNPACKING


/**
 * @brief Get field accel_bias_x from accel_params message
 *
 * @return  
 */
static inline float mavlink_msg_accel_params_get_accel_bias_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field accel_bias_y from accel_params message
 *
 * @return  
 */
static inline float mavlink_msg_accel_params_get_accel_bias_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field accel_bias_z from accel_params message
 *
 * @return  
 */
static inline float mavlink_msg_accel_params_get_accel_bias_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a accel_params message into a struct
 *
 * @param msg The message to decode
 * @param accel_params C-struct to decode the message contents into
 */
static inline void mavlink_msg_accel_params_decode(const mavlink_message_t* msg, mavlink_accel_params_t* accel_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    accel_params->accel_bias_x = mavlink_msg_accel_params_get_accel_bias_x(msg);
    accel_params->accel_bias_y = mavlink_msg_accel_params_get_accel_bias_y(msg);
    accel_params->accel_bias_z = mavlink_msg_accel_params_get_accel_bias_z(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ACCEL_PARAMS_LEN? msg->len : MAVLINK_MSG_ID_ACCEL_PARAMS_LEN;
        memset(accel_params, 0, MAVLINK_MSG_ID_ACCEL_PARAMS_LEN);
    memcpy(accel_params, _MAV_PAYLOAD(msg), len);
#endif
}
