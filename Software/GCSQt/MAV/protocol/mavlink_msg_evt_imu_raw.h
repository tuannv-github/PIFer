#pragma once
// MESSAGE EVT_IMU_RAW PACKING

#define MAVLINK_MSG_ID_EVT_IMU_RAW 10

MAVPACKED(
typedef struct __mavlink_evt_imu_raw_t {
 float roll; /*<  roll*/
 int16_t gyro_x; /*<  Gyro X*/
 int16_t gyro_y; /*<  Gyro Y*/
 int16_t gyro_z; /*<  Gyro Z*/
}) mavlink_evt_imu_raw_t;

#define MAVLINK_MSG_ID_EVT_IMU_RAW_LEN 10
#define MAVLINK_MSG_ID_EVT_IMU_RAW_MIN_LEN 10
#define MAVLINK_MSG_ID_10_LEN 10
#define MAVLINK_MSG_ID_10_MIN_LEN 10

#define MAVLINK_MSG_ID_EVT_IMU_RAW_CRC 143
#define MAVLINK_MSG_ID_10_CRC 143



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EVT_IMU_RAW { \
    10, \
    "EVT_IMU_RAW", \
    4, \
    {  { "gyro_x", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_evt_imu_raw_t, gyro_x) }, \
         { "gyro_y", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_evt_imu_raw_t, gyro_y) }, \
         { "gyro_z", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_evt_imu_raw_t, gyro_z) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_evt_imu_raw_t, roll) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EVT_IMU_RAW { \
    "EVT_IMU_RAW", \
    4, \
    {  { "gyro_x", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_evt_imu_raw_t, gyro_x) }, \
         { "gyro_y", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_evt_imu_raw_t, gyro_y) }, \
         { "gyro_z", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_evt_imu_raw_t, gyro_z) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_evt_imu_raw_t, roll) }, \
         } \
}
#endif

/**
 * @brief Pack a evt_imu_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param gyro_x  Gyro X
 * @param gyro_y  Gyro Y
 * @param gyro_z  Gyro Z
 * @param roll  roll
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_evt_imu_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t gyro_x, int16_t gyro_y, int16_t gyro_z, float roll)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_IMU_RAW_LEN];
    _mav_put_float(buf, 0, roll);
    _mav_put_int16_t(buf, 4, gyro_x);
    _mav_put_int16_t(buf, 6, gyro_y);
    _mav_put_int16_t(buf, 8, gyro_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EVT_IMU_RAW_LEN);
#else
    mavlink_evt_imu_raw_t packet;
    packet.roll = roll;
    packet.gyro_x = gyro_x;
    packet.gyro_y = gyro_y;
    packet.gyro_z = gyro_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EVT_IMU_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EVT_IMU_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EVT_IMU_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_IMU_RAW_LEN, MAVLINK_MSG_ID_EVT_IMU_RAW_CRC);
}

/**
 * @brief Pack a evt_imu_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gyro_x  Gyro X
 * @param gyro_y  Gyro Y
 * @param gyro_z  Gyro Z
 * @param roll  roll
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_evt_imu_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t gyro_x,int16_t gyro_y,int16_t gyro_z,float roll)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_IMU_RAW_LEN];
    _mav_put_float(buf, 0, roll);
    _mav_put_int16_t(buf, 4, gyro_x);
    _mav_put_int16_t(buf, 6, gyro_y);
    _mav_put_int16_t(buf, 8, gyro_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EVT_IMU_RAW_LEN);
#else
    mavlink_evt_imu_raw_t packet;
    packet.roll = roll;
    packet.gyro_x = gyro_x;
    packet.gyro_y = gyro_y;
    packet.gyro_z = gyro_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EVT_IMU_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EVT_IMU_RAW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EVT_IMU_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_IMU_RAW_LEN, MAVLINK_MSG_ID_EVT_IMU_RAW_CRC);
}

/**
 * @brief Encode a evt_imu_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param evt_imu_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_evt_imu_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_evt_imu_raw_t* evt_imu_raw)
{
    return mavlink_msg_evt_imu_raw_pack(system_id, component_id, msg, evt_imu_raw->gyro_x, evt_imu_raw->gyro_y, evt_imu_raw->gyro_z, evt_imu_raw->roll);
}

/**
 * @brief Encode a evt_imu_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param evt_imu_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_evt_imu_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_evt_imu_raw_t* evt_imu_raw)
{
    return mavlink_msg_evt_imu_raw_pack_chan(system_id, component_id, chan, msg, evt_imu_raw->gyro_x, evt_imu_raw->gyro_y, evt_imu_raw->gyro_z, evt_imu_raw->roll);
}

/**
 * @brief Send a evt_imu_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param gyro_x  Gyro X
 * @param gyro_y  Gyro Y
 * @param gyro_z  Gyro Z
 * @param roll  roll
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_evt_imu_raw_send(mavlink_channel_t chan, int16_t gyro_x, int16_t gyro_y, int16_t gyro_z, float roll)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_IMU_RAW_LEN];
    _mav_put_float(buf, 0, roll);
    _mav_put_int16_t(buf, 4, gyro_x);
    _mav_put_int16_t(buf, 6, gyro_y);
    _mav_put_int16_t(buf, 8, gyro_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_IMU_RAW, buf, MAVLINK_MSG_ID_EVT_IMU_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_IMU_RAW_LEN, MAVLINK_MSG_ID_EVT_IMU_RAW_CRC);
#else
    mavlink_evt_imu_raw_t packet;
    packet.roll = roll;
    packet.gyro_x = gyro_x;
    packet.gyro_y = gyro_y;
    packet.gyro_z = gyro_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_IMU_RAW, (const char *)&packet, MAVLINK_MSG_ID_EVT_IMU_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_IMU_RAW_LEN, MAVLINK_MSG_ID_EVT_IMU_RAW_CRC);
#endif
}

/**
 * @brief Send a evt_imu_raw message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_evt_imu_raw_send_struct(mavlink_channel_t chan, const mavlink_evt_imu_raw_t* evt_imu_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_evt_imu_raw_send(chan, evt_imu_raw->gyro_x, evt_imu_raw->gyro_y, evt_imu_raw->gyro_z, evt_imu_raw->roll);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_IMU_RAW, (const char *)evt_imu_raw, MAVLINK_MSG_ID_EVT_IMU_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_IMU_RAW_LEN, MAVLINK_MSG_ID_EVT_IMU_RAW_CRC);
#endif
}

#if MAVLINK_MSG_ID_EVT_IMU_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_evt_imu_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t gyro_x, int16_t gyro_y, int16_t gyro_z, float roll)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, roll);
    _mav_put_int16_t(buf, 4, gyro_x);
    _mav_put_int16_t(buf, 6, gyro_y);
    _mav_put_int16_t(buf, 8, gyro_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_IMU_RAW, buf, MAVLINK_MSG_ID_EVT_IMU_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_IMU_RAW_LEN, MAVLINK_MSG_ID_EVT_IMU_RAW_CRC);
#else
    mavlink_evt_imu_raw_t *packet = (mavlink_evt_imu_raw_t *)msgbuf;
    packet->roll = roll;
    packet->gyro_x = gyro_x;
    packet->gyro_y = gyro_y;
    packet->gyro_z = gyro_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_IMU_RAW, (const char *)packet, MAVLINK_MSG_ID_EVT_IMU_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_IMU_RAW_LEN, MAVLINK_MSG_ID_EVT_IMU_RAW_CRC);
#endif
}
#endif

#endif

// MESSAGE EVT_IMU_RAW UNPACKING


/**
 * @brief Get field gyro_x from evt_imu_raw message
 *
 * @return  Gyro X
 */
static inline int16_t mavlink_msg_evt_imu_raw_get_gyro_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field gyro_y from evt_imu_raw message
 *
 * @return  Gyro Y
 */
static inline int16_t mavlink_msg_evt_imu_raw_get_gyro_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field gyro_z from evt_imu_raw message
 *
 * @return  Gyro Z
 */
static inline int16_t mavlink_msg_evt_imu_raw_get_gyro_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field roll from evt_imu_raw message
 *
 * @return  roll
 */
static inline float mavlink_msg_evt_imu_raw_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a evt_imu_raw message into a struct
 *
 * @param msg The message to decode
 * @param evt_imu_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_evt_imu_raw_decode(const mavlink_message_t* msg, mavlink_evt_imu_raw_t* evt_imu_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    evt_imu_raw->roll = mavlink_msg_evt_imu_raw_get_roll(msg);
    evt_imu_raw->gyro_x = mavlink_msg_evt_imu_raw_get_gyro_x(msg);
    evt_imu_raw->gyro_y = mavlink_msg_evt_imu_raw_get_gyro_y(msg);
    evt_imu_raw->gyro_z = mavlink_msg_evt_imu_raw_get_gyro_z(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EVT_IMU_RAW_LEN? msg->len : MAVLINK_MSG_ID_EVT_IMU_RAW_LEN;
        memset(evt_imu_raw, 0, MAVLINK_MSG_ID_EVT_IMU_RAW_LEN);
    memcpy(evt_imu_raw, _MAV_PAYLOAD(msg), len);
#endif
}
