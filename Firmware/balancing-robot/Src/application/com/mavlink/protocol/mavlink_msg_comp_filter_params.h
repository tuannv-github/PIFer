#pragma once
// MESSAGE COMP_FILTER_PARAMS PACKING

#define MAVLINK_MSG_ID_COMP_FILTER_PARAMS 10


typedef struct __mavlink_comp_filter_params_t {
 float tilt_offset; /*<  Tilt angle offset*/
 float g_believe; /*<  Belive in gyroscope*/
 uint8_t tilt_type; /*<  Tilt type*/
} mavlink_comp_filter_params_t;

#define MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN 9
#define MAVLINK_MSG_ID_COMP_FILTER_PARAMS_MIN_LEN 9
#define MAVLINK_MSG_ID_10_LEN 9
#define MAVLINK_MSG_ID_10_MIN_LEN 9

#define MAVLINK_MSG_ID_COMP_FILTER_PARAMS_CRC 157
#define MAVLINK_MSG_ID_10_CRC 157



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_COMP_FILTER_PARAMS { \
    10, \
    "COMP_FILTER_PARAMS", \
    3, \
    {  { "tilt_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_comp_filter_params_t, tilt_type) }, \
         { "tilt_offset", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_comp_filter_params_t, tilt_offset) }, \
         { "g_believe", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_comp_filter_params_t, g_believe) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_COMP_FILTER_PARAMS { \
    "COMP_FILTER_PARAMS", \
    3, \
    {  { "tilt_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_comp_filter_params_t, tilt_type) }, \
         { "tilt_offset", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_comp_filter_params_t, tilt_offset) }, \
         { "g_believe", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_comp_filter_params_t, g_believe) }, \
         } \
}
#endif

/**
 * @brief Pack a comp_filter_params message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param tilt_type  Tilt type
 * @param tilt_offset  Tilt angle offset
 * @param g_believe  Belive in gyroscope
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_comp_filter_params_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t tilt_type, float tilt_offset, float g_believe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN];
    _mav_put_float(buf, 0, tilt_offset);
    _mav_put_float(buf, 4, g_believe);
    _mav_put_uint8_t(buf, 8, tilt_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN);
#else
    mavlink_comp_filter_params_t packet;
    packet.tilt_offset = tilt_offset;
    packet.g_believe = g_believe;
    packet.tilt_type = tilt_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMP_FILTER_PARAMS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_MIN_LEN, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_CRC);
}

/**
 * @brief Pack a comp_filter_params message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tilt_type  Tilt type
 * @param tilt_offset  Tilt angle offset
 * @param g_believe  Belive in gyroscope
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_comp_filter_params_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t tilt_type,float tilt_offset,float g_believe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN];
    _mav_put_float(buf, 0, tilt_offset);
    _mav_put_float(buf, 4, g_believe);
    _mav_put_uint8_t(buf, 8, tilt_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN);
#else
    mavlink_comp_filter_params_t packet;
    packet.tilt_offset = tilt_offset;
    packet.g_believe = g_believe;
    packet.tilt_type = tilt_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMP_FILTER_PARAMS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_MIN_LEN, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_CRC);
}

/**
 * @brief Encode a comp_filter_params struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param comp_filter_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_comp_filter_params_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_comp_filter_params_t* comp_filter_params)
{
    return mavlink_msg_comp_filter_params_pack(system_id, component_id, msg, comp_filter_params->tilt_type, comp_filter_params->tilt_offset, comp_filter_params->g_believe);
}

/**
 * @brief Encode a comp_filter_params struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param comp_filter_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_comp_filter_params_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_comp_filter_params_t* comp_filter_params)
{
    return mavlink_msg_comp_filter_params_pack_chan(system_id, component_id, chan, msg, comp_filter_params->tilt_type, comp_filter_params->tilt_offset, comp_filter_params->g_believe);
}

/**
 * @brief Send a comp_filter_params message
 * @param chan MAVLink channel to send the message
 *
 * @param tilt_type  Tilt type
 * @param tilt_offset  Tilt angle offset
 * @param g_believe  Belive in gyroscope
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_comp_filter_params_send(mavlink_channel_t chan, uint8_t tilt_type, float tilt_offset, float g_believe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN];
    _mav_put_float(buf, 0, tilt_offset);
    _mav_put_float(buf, 4, g_believe);
    _mav_put_uint8_t(buf, 8, tilt_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMP_FILTER_PARAMS, buf, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_MIN_LEN, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_CRC);
#else
    mavlink_comp_filter_params_t packet;
    packet.tilt_offset = tilt_offset;
    packet.g_believe = g_believe;
    packet.tilt_type = tilt_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMP_FILTER_PARAMS, (const char *)&packet, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_MIN_LEN, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_CRC);
#endif
}

/**
 * @brief Send a comp_filter_params message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_comp_filter_params_send_struct(mavlink_channel_t chan, const mavlink_comp_filter_params_t* comp_filter_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_comp_filter_params_send(chan, comp_filter_params->tilt_type, comp_filter_params->tilt_offset, comp_filter_params->g_believe);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMP_FILTER_PARAMS, (const char *)comp_filter_params, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_MIN_LEN, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_CRC);
#endif
}

#if MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_comp_filter_params_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t tilt_type, float tilt_offset, float g_believe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, tilt_offset);
    _mav_put_float(buf, 4, g_believe);
    _mav_put_uint8_t(buf, 8, tilt_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMP_FILTER_PARAMS, buf, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_MIN_LEN, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_CRC);
#else
    mavlink_comp_filter_params_t *packet = (mavlink_comp_filter_params_t *)msgbuf;
    packet->tilt_offset = tilt_offset;
    packet->g_believe = g_believe;
    packet->tilt_type = tilt_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMP_FILTER_PARAMS, (const char *)packet, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_MIN_LEN, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_CRC);
#endif
}
#endif

#endif

// MESSAGE COMP_FILTER_PARAMS UNPACKING


/**
 * @brief Get field tilt_type from comp_filter_params message
 *
 * @return  Tilt type
 */
static inline uint8_t mavlink_msg_comp_filter_params_get_tilt_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field tilt_offset from comp_filter_params message
 *
 * @return  Tilt angle offset
 */
static inline float mavlink_msg_comp_filter_params_get_tilt_offset(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field g_believe from comp_filter_params message
 *
 * @return  Belive in gyroscope
 */
static inline float mavlink_msg_comp_filter_params_get_g_believe(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a comp_filter_params message into a struct
 *
 * @param msg The message to decode
 * @param comp_filter_params C-struct to decode the message contents into
 */
static inline void mavlink_msg_comp_filter_params_decode(const mavlink_message_t* msg, mavlink_comp_filter_params_t* comp_filter_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    comp_filter_params->tilt_offset = mavlink_msg_comp_filter_params_get_tilt_offset(msg);
    comp_filter_params->g_believe = mavlink_msg_comp_filter_params_get_g_believe(msg);
    comp_filter_params->tilt_type = mavlink_msg_comp_filter_params_get_tilt_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN? msg->len : MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN;
        memset(comp_filter_params, 0, MAVLINK_MSG_ID_COMP_FILTER_PARAMS_LEN);
    memcpy(comp_filter_params, _MAV_PAYLOAD(msg), len);
#endif
}
