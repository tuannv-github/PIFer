#pragma once
// MESSAGE EVT_MAG_RAW PACKING

#define MAVLINK_MSG_ID_EVT_MAG_RAW 11

MAVPACKED(
typedef struct __mavlink_evt_mag_raw_t {
 int16_t mag_x; /*<  Mag X*/
 int16_t mag_y; /*<  Mag Y*/
 int16_t mag_z; /*<  Mag Z*/
}) mavlink_evt_mag_raw_t;

#define MAVLINK_MSG_ID_EVT_MAG_RAW_LEN 6
#define MAVLINK_MSG_ID_EVT_MAG_RAW_MIN_LEN 6
#define MAVLINK_MSG_ID_11_LEN 6
#define MAVLINK_MSG_ID_11_MIN_LEN 6

#define MAVLINK_MSG_ID_EVT_MAG_RAW_CRC 156
#define MAVLINK_MSG_ID_11_CRC 156



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EVT_MAG_RAW { \
    11, \
    "EVT_MAG_RAW", \
    3, \
    {  { "mag_x", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_evt_mag_raw_t, mag_x) }, \
         { "mag_y", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_evt_mag_raw_t, mag_y) }, \
         { "mag_z", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_evt_mag_raw_t, mag_z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EVT_MAG_RAW { \
    "EVT_MAG_RAW", \
    3, \
    {  { "mag_x", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_evt_mag_raw_t, mag_x) }, \
         { "mag_y", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_evt_mag_raw_t, mag_y) }, \
         { "mag_z", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_evt_mag_raw_t, mag_z) }, \
         } \
}
#endif

/**
 * @brief Pack a evt_mag_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mag_x  Mag X
 * @param mag_y  Mag Y
 * @param mag_z  Mag Z
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_evt_mag_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t mag_x, int16_t mag_y, int16_t mag_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_MAG_RAW_LEN];
    _mav_put_int16_t(buf, 0, mag_x);
    _mav_put_int16_t(buf, 2, mag_y);
    _mav_put_int16_t(buf, 4, mag_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EVT_MAG_RAW_LEN);
#else
    mavlink_evt_mag_raw_t packet;
    packet.mag_x = mag_x;
    packet.mag_y = mag_y;
    packet.mag_z = mag_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EVT_MAG_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EVT_MAG_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EVT_MAG_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_MAG_RAW_LEN, MAVLINK_MSG_ID_EVT_MAG_RAW_CRC);
}

/**
 * @brief Pack a evt_mag_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mag_x  Mag X
 * @param mag_y  Mag Y
 * @param mag_z  Mag Z
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_evt_mag_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t mag_x,int16_t mag_y,int16_t mag_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_MAG_RAW_LEN];
    _mav_put_int16_t(buf, 0, mag_x);
    _mav_put_int16_t(buf, 2, mag_y);
    _mav_put_int16_t(buf, 4, mag_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EVT_MAG_RAW_LEN);
#else
    mavlink_evt_mag_raw_t packet;
    packet.mag_x = mag_x;
    packet.mag_y = mag_y;
    packet.mag_z = mag_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EVT_MAG_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EVT_MAG_RAW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EVT_MAG_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_MAG_RAW_LEN, MAVLINK_MSG_ID_EVT_MAG_RAW_CRC);
}

/**
 * @brief Encode a evt_mag_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param evt_mag_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_evt_mag_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_evt_mag_raw_t* evt_mag_raw)
{
    return mavlink_msg_evt_mag_raw_pack(system_id, component_id, msg, evt_mag_raw->mag_x, evt_mag_raw->mag_y, evt_mag_raw->mag_z);
}

/**
 * @brief Encode a evt_mag_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param evt_mag_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_evt_mag_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_evt_mag_raw_t* evt_mag_raw)
{
    return mavlink_msg_evt_mag_raw_pack_chan(system_id, component_id, chan, msg, evt_mag_raw->mag_x, evt_mag_raw->mag_y, evt_mag_raw->mag_z);
}

/**
 * @brief Send a evt_mag_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param mag_x  Mag X
 * @param mag_y  Mag Y
 * @param mag_z  Mag Z
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_evt_mag_raw_send(mavlink_channel_t chan, int16_t mag_x, int16_t mag_y, int16_t mag_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_MAG_RAW_LEN];
    _mav_put_int16_t(buf, 0, mag_x);
    _mav_put_int16_t(buf, 2, mag_y);
    _mav_put_int16_t(buf, 4, mag_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_MAG_RAW, buf, MAVLINK_MSG_ID_EVT_MAG_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_MAG_RAW_LEN, MAVLINK_MSG_ID_EVT_MAG_RAW_CRC);
#else
    mavlink_evt_mag_raw_t packet;
    packet.mag_x = mag_x;
    packet.mag_y = mag_y;
    packet.mag_z = mag_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_MAG_RAW, (const char *)&packet, MAVLINK_MSG_ID_EVT_MAG_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_MAG_RAW_LEN, MAVLINK_MSG_ID_EVT_MAG_RAW_CRC);
#endif
}

/**
 * @brief Send a evt_mag_raw message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_evt_mag_raw_send_struct(mavlink_channel_t chan, const mavlink_evt_mag_raw_t* evt_mag_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_evt_mag_raw_send(chan, evt_mag_raw->mag_x, evt_mag_raw->mag_y, evt_mag_raw->mag_z);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_MAG_RAW, (const char *)evt_mag_raw, MAVLINK_MSG_ID_EVT_MAG_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_MAG_RAW_LEN, MAVLINK_MSG_ID_EVT_MAG_RAW_CRC);
#endif
}

#if MAVLINK_MSG_ID_EVT_MAG_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_evt_mag_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t mag_x, int16_t mag_y, int16_t mag_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 0, mag_x);
    _mav_put_int16_t(buf, 2, mag_y);
    _mav_put_int16_t(buf, 4, mag_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_MAG_RAW, buf, MAVLINK_MSG_ID_EVT_MAG_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_MAG_RAW_LEN, MAVLINK_MSG_ID_EVT_MAG_RAW_CRC);
#else
    mavlink_evt_mag_raw_t *packet = (mavlink_evt_mag_raw_t *)msgbuf;
    packet->mag_x = mag_x;
    packet->mag_y = mag_y;
    packet->mag_z = mag_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_MAG_RAW, (const char *)packet, MAVLINK_MSG_ID_EVT_MAG_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_MAG_RAW_LEN, MAVLINK_MSG_ID_EVT_MAG_RAW_CRC);
#endif
}
#endif

#endif

// MESSAGE EVT_MAG_RAW UNPACKING


/**
 * @brief Get field mag_x from evt_mag_raw message
 *
 * @return  Mag X
 */
static inline int16_t mavlink_msg_evt_mag_raw_get_mag_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field mag_y from evt_mag_raw message
 *
 * @return  Mag Y
 */
static inline int16_t mavlink_msg_evt_mag_raw_get_mag_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field mag_z from evt_mag_raw message
 *
 * @return  Mag Z
 */
static inline int16_t mavlink_msg_evt_mag_raw_get_mag_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Decode a evt_mag_raw message into a struct
 *
 * @param msg The message to decode
 * @param evt_mag_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_evt_mag_raw_decode(const mavlink_message_t* msg, mavlink_evt_mag_raw_t* evt_mag_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    evt_mag_raw->mag_x = mavlink_msg_evt_mag_raw_get_mag_x(msg);
    evt_mag_raw->mag_y = mavlink_msg_evt_mag_raw_get_mag_y(msg);
    evt_mag_raw->mag_z = mavlink_msg_evt_mag_raw_get_mag_z(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EVT_MAG_RAW_LEN? msg->len : MAVLINK_MSG_ID_EVT_MAG_RAW_LEN;
        memset(evt_mag_raw, 0, MAVLINK_MSG_ID_EVT_MAG_RAW_LEN);
    memcpy(evt_mag_raw, _MAV_PAYLOAD(msg), len);
#endif
}
