#pragma once
// MESSAGE MAG_PARAMS PACKING

#define MAVLINK_MSG_ID_MAG_PARAMS 11


typedef struct __mavlink_mag_params_t {
 float mag_bias_x; /*<  */
 float mag_bias_y; /*<  */
 float mag_bias_z; /*<  */
 float mag_scale_x; /*<  */
 float mag_scale_y; /*<  */
 float mag_scale_z; /*<  */
} mavlink_mag_params_t;

#define MAVLINK_MSG_ID_MAG_PARAMS_LEN 24
#define MAVLINK_MSG_ID_MAG_PARAMS_MIN_LEN 24
#define MAVLINK_MSG_ID_11_LEN 24
#define MAVLINK_MSG_ID_11_MIN_LEN 24

#define MAVLINK_MSG_ID_MAG_PARAMS_CRC 31
#define MAVLINK_MSG_ID_11_CRC 31



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MAG_PARAMS { \
    11, \
    "MAG_PARAMS", \
    6, \
    {  { "mag_bias_x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_mag_params_t, mag_bias_x) }, \
         { "mag_bias_y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_mag_params_t, mag_bias_y) }, \
         { "mag_bias_z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_mag_params_t, mag_bias_z) }, \
         { "mag_scale_x", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_mag_params_t, mag_scale_x) }, \
         { "mag_scale_y", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_mag_params_t, mag_scale_y) }, \
         { "mag_scale_z", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_mag_params_t, mag_scale_z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MAG_PARAMS { \
    "MAG_PARAMS", \
    6, \
    {  { "mag_bias_x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_mag_params_t, mag_bias_x) }, \
         { "mag_bias_y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_mag_params_t, mag_bias_y) }, \
         { "mag_bias_z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_mag_params_t, mag_bias_z) }, \
         { "mag_scale_x", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_mag_params_t, mag_scale_x) }, \
         { "mag_scale_y", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_mag_params_t, mag_scale_y) }, \
         { "mag_scale_z", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_mag_params_t, mag_scale_z) }, \
         } \
}
#endif

/**
 * @brief Pack a mag_params message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mag_bias_x  
 * @param mag_bias_y  
 * @param mag_bias_z  
 * @param mag_scale_x  
 * @param mag_scale_y  
 * @param mag_scale_z  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mag_params_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float mag_bias_x, float mag_bias_y, float mag_bias_z, float mag_scale_x, float mag_scale_y, float mag_scale_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MAG_PARAMS_LEN];
    _mav_put_float(buf, 0, mag_bias_x);
    _mav_put_float(buf, 4, mag_bias_y);
    _mav_put_float(buf, 8, mag_bias_z);
    _mav_put_float(buf, 12, mag_scale_x);
    _mav_put_float(buf, 16, mag_scale_y);
    _mav_put_float(buf, 20, mag_scale_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MAG_PARAMS_LEN);
#else
    mavlink_mag_params_t packet;
    packet.mag_bias_x = mag_bias_x;
    packet.mag_bias_y = mag_bias_y;
    packet.mag_bias_z = mag_bias_z;
    packet.mag_scale_x = mag_scale_x;
    packet.mag_scale_y = mag_scale_y;
    packet.mag_scale_z = mag_scale_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MAG_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MAG_PARAMS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MAG_PARAMS_MIN_LEN, MAVLINK_MSG_ID_MAG_PARAMS_LEN, MAVLINK_MSG_ID_MAG_PARAMS_CRC);
}

/**
 * @brief Pack a mag_params message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mag_bias_x  
 * @param mag_bias_y  
 * @param mag_bias_z  
 * @param mag_scale_x  
 * @param mag_scale_y  
 * @param mag_scale_z  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mag_params_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float mag_bias_x,float mag_bias_y,float mag_bias_z,float mag_scale_x,float mag_scale_y,float mag_scale_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MAG_PARAMS_LEN];
    _mav_put_float(buf, 0, mag_bias_x);
    _mav_put_float(buf, 4, mag_bias_y);
    _mav_put_float(buf, 8, mag_bias_z);
    _mav_put_float(buf, 12, mag_scale_x);
    _mav_put_float(buf, 16, mag_scale_y);
    _mav_put_float(buf, 20, mag_scale_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MAG_PARAMS_LEN);
#else
    mavlink_mag_params_t packet;
    packet.mag_bias_x = mag_bias_x;
    packet.mag_bias_y = mag_bias_y;
    packet.mag_bias_z = mag_bias_z;
    packet.mag_scale_x = mag_scale_x;
    packet.mag_scale_y = mag_scale_y;
    packet.mag_scale_z = mag_scale_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MAG_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MAG_PARAMS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MAG_PARAMS_MIN_LEN, MAVLINK_MSG_ID_MAG_PARAMS_LEN, MAVLINK_MSG_ID_MAG_PARAMS_CRC);
}

/**
 * @brief Encode a mag_params struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mag_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mag_params_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mag_params_t* mag_params)
{
    return mavlink_msg_mag_params_pack(system_id, component_id, msg, mag_params->mag_bias_x, mag_params->mag_bias_y, mag_params->mag_bias_z, mag_params->mag_scale_x, mag_params->mag_scale_y, mag_params->mag_scale_z);
}

/**
 * @brief Encode a mag_params struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mag_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mag_params_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mag_params_t* mag_params)
{
    return mavlink_msg_mag_params_pack_chan(system_id, component_id, chan, msg, mag_params->mag_bias_x, mag_params->mag_bias_y, mag_params->mag_bias_z, mag_params->mag_scale_x, mag_params->mag_scale_y, mag_params->mag_scale_z);
}

/**
 * @brief Send a mag_params message
 * @param chan MAVLink channel to send the message
 *
 * @param mag_bias_x  
 * @param mag_bias_y  
 * @param mag_bias_z  
 * @param mag_scale_x  
 * @param mag_scale_y  
 * @param mag_scale_z  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mag_params_send(mavlink_channel_t chan, float mag_bias_x, float mag_bias_y, float mag_bias_z, float mag_scale_x, float mag_scale_y, float mag_scale_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MAG_PARAMS_LEN];
    _mav_put_float(buf, 0, mag_bias_x);
    _mav_put_float(buf, 4, mag_bias_y);
    _mav_put_float(buf, 8, mag_bias_z);
    _mav_put_float(buf, 12, mag_scale_x);
    _mav_put_float(buf, 16, mag_scale_y);
    _mav_put_float(buf, 20, mag_scale_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAG_PARAMS, buf, MAVLINK_MSG_ID_MAG_PARAMS_MIN_LEN, MAVLINK_MSG_ID_MAG_PARAMS_LEN, MAVLINK_MSG_ID_MAG_PARAMS_CRC);
#else
    mavlink_mag_params_t packet;
    packet.mag_bias_x = mag_bias_x;
    packet.mag_bias_y = mag_bias_y;
    packet.mag_bias_z = mag_bias_z;
    packet.mag_scale_x = mag_scale_x;
    packet.mag_scale_y = mag_scale_y;
    packet.mag_scale_z = mag_scale_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAG_PARAMS, (const char *)&packet, MAVLINK_MSG_ID_MAG_PARAMS_MIN_LEN, MAVLINK_MSG_ID_MAG_PARAMS_LEN, MAVLINK_MSG_ID_MAG_PARAMS_CRC);
#endif
}

/**
 * @brief Send a mag_params message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mag_params_send_struct(mavlink_channel_t chan, const mavlink_mag_params_t* mag_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mag_params_send(chan, mag_params->mag_bias_x, mag_params->mag_bias_y, mag_params->mag_bias_z, mag_params->mag_scale_x, mag_params->mag_scale_y, mag_params->mag_scale_z);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAG_PARAMS, (const char *)mag_params, MAVLINK_MSG_ID_MAG_PARAMS_MIN_LEN, MAVLINK_MSG_ID_MAG_PARAMS_LEN, MAVLINK_MSG_ID_MAG_PARAMS_CRC);
#endif
}

#if MAVLINK_MSG_ID_MAG_PARAMS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mag_params_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float mag_bias_x, float mag_bias_y, float mag_bias_z, float mag_scale_x, float mag_scale_y, float mag_scale_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, mag_bias_x);
    _mav_put_float(buf, 4, mag_bias_y);
    _mav_put_float(buf, 8, mag_bias_z);
    _mav_put_float(buf, 12, mag_scale_x);
    _mav_put_float(buf, 16, mag_scale_y);
    _mav_put_float(buf, 20, mag_scale_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAG_PARAMS, buf, MAVLINK_MSG_ID_MAG_PARAMS_MIN_LEN, MAVLINK_MSG_ID_MAG_PARAMS_LEN, MAVLINK_MSG_ID_MAG_PARAMS_CRC);
#else
    mavlink_mag_params_t *packet = (mavlink_mag_params_t *)msgbuf;
    packet->mag_bias_x = mag_bias_x;
    packet->mag_bias_y = mag_bias_y;
    packet->mag_bias_z = mag_bias_z;
    packet->mag_scale_x = mag_scale_x;
    packet->mag_scale_y = mag_scale_y;
    packet->mag_scale_z = mag_scale_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAG_PARAMS, (const char *)packet, MAVLINK_MSG_ID_MAG_PARAMS_MIN_LEN, MAVLINK_MSG_ID_MAG_PARAMS_LEN, MAVLINK_MSG_ID_MAG_PARAMS_CRC);
#endif
}
#endif

#endif

// MESSAGE MAG_PARAMS UNPACKING


/**
 * @brief Get field mag_bias_x from mag_params message
 *
 * @return  
 */
static inline float mavlink_msg_mag_params_get_mag_bias_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field mag_bias_y from mag_params message
 *
 * @return  
 */
static inline float mavlink_msg_mag_params_get_mag_bias_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field mag_bias_z from mag_params message
 *
 * @return  
 */
static inline float mavlink_msg_mag_params_get_mag_bias_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field mag_scale_x from mag_params message
 *
 * @return  
 */
static inline float mavlink_msg_mag_params_get_mag_scale_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field mag_scale_y from mag_params message
 *
 * @return  
 */
static inline float mavlink_msg_mag_params_get_mag_scale_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field mag_scale_z from mag_params message
 *
 * @return  
 */
static inline float mavlink_msg_mag_params_get_mag_scale_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a mag_params message into a struct
 *
 * @param msg The message to decode
 * @param mag_params C-struct to decode the message contents into
 */
static inline void mavlink_msg_mag_params_decode(const mavlink_message_t* msg, mavlink_mag_params_t* mag_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mag_params->mag_bias_x = mavlink_msg_mag_params_get_mag_bias_x(msg);
    mag_params->mag_bias_y = mavlink_msg_mag_params_get_mag_bias_y(msg);
    mag_params->mag_bias_z = mavlink_msg_mag_params_get_mag_bias_z(msg);
    mag_params->mag_scale_x = mavlink_msg_mag_params_get_mag_scale_x(msg);
    mag_params->mag_scale_y = mavlink_msg_mag_params_get_mag_scale_y(msg);
    mag_params->mag_scale_z = mavlink_msg_mag_params_get_mag_scale_z(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MAG_PARAMS_LEN? msg->len : MAVLINK_MSG_ID_MAG_PARAMS_LEN;
        memset(mag_params, 0, MAVLINK_MSG_ID_MAG_PARAMS_LEN);
    memcpy(mag_params, _MAV_PAYLOAD(msg), len);
#endif
}
