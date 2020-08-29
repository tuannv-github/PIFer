#pragma once
// MESSAGE EVT_RPY PACKING

#define MAVLINK_MSG_ID_EVT_RPY 5

MAVPACKED(
typedef struct __mavlink_evt_rpy_t {
 float roll; /*<  Roll*/
 float pitch; /*<  Pitch*/
 float yaw; /*<  Yaw*/
}) mavlink_evt_rpy_t;

#define MAVLINK_MSG_ID_EVT_RPY_LEN 12
#define MAVLINK_MSG_ID_EVT_RPY_MIN_LEN 12
#define MAVLINK_MSG_ID_5_LEN 12
#define MAVLINK_MSG_ID_5_MIN_LEN 12

#define MAVLINK_MSG_ID_EVT_RPY_CRC 93
#define MAVLINK_MSG_ID_5_CRC 93



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EVT_RPY { \
    5, \
    "EVT_RPY", \
    3, \
    {  { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_evt_rpy_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_evt_rpy_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_evt_rpy_t, yaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EVT_RPY { \
    "EVT_RPY", \
    3, \
    {  { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_evt_rpy_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_evt_rpy_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_evt_rpy_t, yaw) }, \
         } \
}
#endif

/**
 * @brief Pack a evt_rpy message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param roll  Roll
 * @param pitch  Pitch
 * @param yaw  Yaw
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_evt_rpy_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_RPY_LEN];
    _mav_put_float(buf, 0, roll);
    _mav_put_float(buf, 4, pitch);
    _mav_put_float(buf, 8, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EVT_RPY_LEN);
#else
    mavlink_evt_rpy_t packet;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EVT_RPY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EVT_RPY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EVT_RPY_MIN_LEN, MAVLINK_MSG_ID_EVT_RPY_LEN, MAVLINK_MSG_ID_EVT_RPY_CRC);
}

/**
 * @brief Pack a evt_rpy message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param roll  Roll
 * @param pitch  Pitch
 * @param yaw  Yaw
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_evt_rpy_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float roll,float pitch,float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_RPY_LEN];
    _mav_put_float(buf, 0, roll);
    _mav_put_float(buf, 4, pitch);
    _mav_put_float(buf, 8, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EVT_RPY_LEN);
#else
    mavlink_evt_rpy_t packet;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EVT_RPY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EVT_RPY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EVT_RPY_MIN_LEN, MAVLINK_MSG_ID_EVT_RPY_LEN, MAVLINK_MSG_ID_EVT_RPY_CRC);
}

/**
 * @brief Encode a evt_rpy struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param evt_rpy C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_evt_rpy_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_evt_rpy_t* evt_rpy)
{
    return mavlink_msg_evt_rpy_pack(system_id, component_id, msg, evt_rpy->roll, evt_rpy->pitch, evt_rpy->yaw);
}

/**
 * @brief Encode a evt_rpy struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param evt_rpy C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_evt_rpy_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_evt_rpy_t* evt_rpy)
{
    return mavlink_msg_evt_rpy_pack_chan(system_id, component_id, chan, msg, evt_rpy->roll, evt_rpy->pitch, evt_rpy->yaw);
}

/**
 * @brief Send a evt_rpy message
 * @param chan MAVLink channel to send the message
 *
 * @param roll  Roll
 * @param pitch  Pitch
 * @param yaw  Yaw
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_evt_rpy_send(mavlink_channel_t chan, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_RPY_LEN];
    _mav_put_float(buf, 0, roll);
    _mav_put_float(buf, 4, pitch);
    _mav_put_float(buf, 8, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_RPY, buf, MAVLINK_MSG_ID_EVT_RPY_MIN_LEN, MAVLINK_MSG_ID_EVT_RPY_LEN, MAVLINK_MSG_ID_EVT_RPY_CRC);
#else
    mavlink_evt_rpy_t packet;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_RPY, (const char *)&packet, MAVLINK_MSG_ID_EVT_RPY_MIN_LEN, MAVLINK_MSG_ID_EVT_RPY_LEN, MAVLINK_MSG_ID_EVT_RPY_CRC);
#endif
}

/**
 * @brief Send a evt_rpy message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_evt_rpy_send_struct(mavlink_channel_t chan, const mavlink_evt_rpy_t* evt_rpy)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_evt_rpy_send(chan, evt_rpy->roll, evt_rpy->pitch, evt_rpy->yaw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_RPY, (const char *)evt_rpy, MAVLINK_MSG_ID_EVT_RPY_MIN_LEN, MAVLINK_MSG_ID_EVT_RPY_LEN, MAVLINK_MSG_ID_EVT_RPY_CRC);
#endif
}

#if MAVLINK_MSG_ID_EVT_RPY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_evt_rpy_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, roll);
    _mav_put_float(buf, 4, pitch);
    _mav_put_float(buf, 8, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_RPY, buf, MAVLINK_MSG_ID_EVT_RPY_MIN_LEN, MAVLINK_MSG_ID_EVT_RPY_LEN, MAVLINK_MSG_ID_EVT_RPY_CRC);
#else
    mavlink_evt_rpy_t *packet = (mavlink_evt_rpy_t *)msgbuf;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_RPY, (const char *)packet, MAVLINK_MSG_ID_EVT_RPY_MIN_LEN, MAVLINK_MSG_ID_EVT_RPY_LEN, MAVLINK_MSG_ID_EVT_RPY_CRC);
#endif
}
#endif

#endif

// MESSAGE EVT_RPY UNPACKING


/**
 * @brief Get field roll from evt_rpy message
 *
 * @return  Roll
 */
static inline float mavlink_msg_evt_rpy_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field pitch from evt_rpy message
 *
 * @return  Pitch
 */
static inline float mavlink_msg_evt_rpy_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field yaw from evt_rpy message
 *
 * @return  Yaw
 */
static inline float mavlink_msg_evt_rpy_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a evt_rpy message into a struct
 *
 * @param msg The message to decode
 * @param evt_rpy C-struct to decode the message contents into
 */
static inline void mavlink_msg_evt_rpy_decode(const mavlink_message_t* msg, mavlink_evt_rpy_t* evt_rpy)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    evt_rpy->roll = mavlink_msg_evt_rpy_get_roll(msg);
    evt_rpy->pitch = mavlink_msg_evt_rpy_get_pitch(msg);
    evt_rpy->yaw = mavlink_msg_evt_rpy_get_yaw(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EVT_RPY_LEN? msg->len : MAVLINK_MSG_ID_EVT_RPY_LEN;
        memset(evt_rpy, 0, MAVLINK_MSG_ID_EVT_RPY_LEN);
    memcpy(evt_rpy, _MAV_PAYLOAD(msg), len);
#endif
}
