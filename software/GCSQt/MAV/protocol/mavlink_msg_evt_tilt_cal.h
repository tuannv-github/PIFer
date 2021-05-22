#pragma once
// MESSAGE EVT_TILT_CAL PACKING

#define MAVLINK_MSG_ID_EVT_TILT_CAL 5


typedef struct __mavlink_evt_tilt_cal_t {
 float tilt; /*<  */
} mavlink_evt_tilt_cal_t;

#define MAVLINK_MSG_ID_EVT_TILT_CAL_LEN 4
#define MAVLINK_MSG_ID_EVT_TILT_CAL_MIN_LEN 4
#define MAVLINK_MSG_ID_5_LEN 4
#define MAVLINK_MSG_ID_5_MIN_LEN 4

#define MAVLINK_MSG_ID_EVT_TILT_CAL_CRC 132
#define MAVLINK_MSG_ID_5_CRC 132



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EVT_TILT_CAL { \
    5, \
    "EVT_TILT_CAL", \
    1, \
    {  { "tilt", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_evt_tilt_cal_t, tilt) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EVT_TILT_CAL { \
    "EVT_TILT_CAL", \
    1, \
    {  { "tilt", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_evt_tilt_cal_t, tilt) }, \
         } \
}
#endif

/**
 * @brief Pack a evt_tilt_cal message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param tilt  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_evt_tilt_cal_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float tilt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_TILT_CAL_LEN];
    _mav_put_float(buf, 0, tilt);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EVT_TILT_CAL_LEN);
#else
    mavlink_evt_tilt_cal_t packet;
    packet.tilt = tilt;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EVT_TILT_CAL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EVT_TILT_CAL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EVT_TILT_CAL_MIN_LEN, MAVLINK_MSG_ID_EVT_TILT_CAL_LEN, MAVLINK_MSG_ID_EVT_TILT_CAL_CRC);
}

/**
 * @brief Pack a evt_tilt_cal message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tilt  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_evt_tilt_cal_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float tilt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_TILT_CAL_LEN];
    _mav_put_float(buf, 0, tilt);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EVT_TILT_CAL_LEN);
#else
    mavlink_evt_tilt_cal_t packet;
    packet.tilt = tilt;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EVT_TILT_CAL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EVT_TILT_CAL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EVT_TILT_CAL_MIN_LEN, MAVLINK_MSG_ID_EVT_TILT_CAL_LEN, MAVLINK_MSG_ID_EVT_TILT_CAL_CRC);
}

/**
 * @brief Encode a evt_tilt_cal struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param evt_tilt_cal C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_evt_tilt_cal_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_evt_tilt_cal_t* evt_tilt_cal)
{
    return mavlink_msg_evt_tilt_cal_pack(system_id, component_id, msg, evt_tilt_cal->tilt);
}

/**
 * @brief Encode a evt_tilt_cal struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param evt_tilt_cal C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_evt_tilt_cal_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_evt_tilt_cal_t* evt_tilt_cal)
{
    return mavlink_msg_evt_tilt_cal_pack_chan(system_id, component_id, chan, msg, evt_tilt_cal->tilt);
}

/**
 * @brief Send a evt_tilt_cal message
 * @param chan MAVLink channel to send the message
 *
 * @param tilt  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_evt_tilt_cal_send(mavlink_channel_t chan, float tilt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_TILT_CAL_LEN];
    _mav_put_float(buf, 0, tilt);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_TILT_CAL, buf, MAVLINK_MSG_ID_EVT_TILT_CAL_MIN_LEN, MAVLINK_MSG_ID_EVT_TILT_CAL_LEN, MAVLINK_MSG_ID_EVT_TILT_CAL_CRC);
#else
    mavlink_evt_tilt_cal_t packet;
    packet.tilt = tilt;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_TILT_CAL, (const char *)&packet, MAVLINK_MSG_ID_EVT_TILT_CAL_MIN_LEN, MAVLINK_MSG_ID_EVT_TILT_CAL_LEN, MAVLINK_MSG_ID_EVT_TILT_CAL_CRC);
#endif
}

/**
 * @brief Send a evt_tilt_cal message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_evt_tilt_cal_send_struct(mavlink_channel_t chan, const mavlink_evt_tilt_cal_t* evt_tilt_cal)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_evt_tilt_cal_send(chan, evt_tilt_cal->tilt);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_TILT_CAL, (const char *)evt_tilt_cal, MAVLINK_MSG_ID_EVT_TILT_CAL_MIN_LEN, MAVLINK_MSG_ID_EVT_TILT_CAL_LEN, MAVLINK_MSG_ID_EVT_TILT_CAL_CRC);
#endif
}

#if MAVLINK_MSG_ID_EVT_TILT_CAL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_evt_tilt_cal_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float tilt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, tilt);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_TILT_CAL, buf, MAVLINK_MSG_ID_EVT_TILT_CAL_MIN_LEN, MAVLINK_MSG_ID_EVT_TILT_CAL_LEN, MAVLINK_MSG_ID_EVT_TILT_CAL_CRC);
#else
    mavlink_evt_tilt_cal_t *packet = (mavlink_evt_tilt_cal_t *)msgbuf;
    packet->tilt = tilt;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_TILT_CAL, (const char *)packet, MAVLINK_MSG_ID_EVT_TILT_CAL_MIN_LEN, MAVLINK_MSG_ID_EVT_TILT_CAL_LEN, MAVLINK_MSG_ID_EVT_TILT_CAL_CRC);
#endif
}
#endif

#endif

// MESSAGE EVT_TILT_CAL UNPACKING


/**
 * @brief Get field tilt from evt_tilt_cal message
 *
 * @return  
 */
static inline float mavlink_msg_evt_tilt_cal_get_tilt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a evt_tilt_cal message into a struct
 *
 * @param msg The message to decode
 * @param evt_tilt_cal C-struct to decode the message contents into
 */
static inline void mavlink_msg_evt_tilt_cal_decode(const mavlink_message_t* msg, mavlink_evt_tilt_cal_t* evt_tilt_cal)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    evt_tilt_cal->tilt = mavlink_msg_evt_tilt_cal_get_tilt(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EVT_TILT_CAL_LEN? msg->len : MAVLINK_MSG_ID_EVT_TILT_CAL_LEN;
        memset(evt_tilt_cal, 0, MAVLINK_MSG_ID_EVT_TILT_CAL_LEN);
    memcpy(evt_tilt_cal, _MAV_PAYLOAD(msg), len);
#endif
}
