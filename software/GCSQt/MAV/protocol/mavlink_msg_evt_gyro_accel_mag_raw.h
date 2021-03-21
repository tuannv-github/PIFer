#pragma once
// MESSAGE EVT_GYRO_ACCEL_MAG_RAW PACKING

#define MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW 13


typedef struct __mavlink_evt_gyro_accel_mag_raw_t {
 float gx; /*<  Gyro X*/
 float gy; /*<  Gyro Y*/
 float gz; /*<  Gyro Z*/
 float ax; /*<  Accel X*/
 float ay; /*<  Accel Y*/
 float az; /*<  Accel Z*/
 float mx; /*<  Mag X*/
 float my; /*<  Mag Y*/
 float mz; /*<  Mag Z*/
} mavlink_evt_gyro_accel_mag_raw_t;

#define MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN 36
#define MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_MIN_LEN 36
#define MAVLINK_MSG_ID_13_LEN 36
#define MAVLINK_MSG_ID_13_MIN_LEN 36

#define MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_CRC 22
#define MAVLINK_MSG_ID_13_CRC 22



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EVT_GYRO_ACCEL_MAG_RAW { \
    13, \
    "EVT_GYRO_ACCEL_MAG_RAW", \
    9, \
    {  { "gx", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_evt_gyro_accel_mag_raw_t, gx) }, \
         { "gy", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_evt_gyro_accel_mag_raw_t, gy) }, \
         { "gz", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_evt_gyro_accel_mag_raw_t, gz) }, \
         { "ax", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_evt_gyro_accel_mag_raw_t, ax) }, \
         { "ay", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_evt_gyro_accel_mag_raw_t, ay) }, \
         { "az", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_evt_gyro_accel_mag_raw_t, az) }, \
         { "mx", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_evt_gyro_accel_mag_raw_t, mx) }, \
         { "my", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_evt_gyro_accel_mag_raw_t, my) }, \
         { "mz", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_evt_gyro_accel_mag_raw_t, mz) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EVT_GYRO_ACCEL_MAG_RAW { \
    "EVT_GYRO_ACCEL_MAG_RAW", \
    9, \
    {  { "gx", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_evt_gyro_accel_mag_raw_t, gx) }, \
         { "gy", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_evt_gyro_accel_mag_raw_t, gy) }, \
         { "gz", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_evt_gyro_accel_mag_raw_t, gz) }, \
         { "ax", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_evt_gyro_accel_mag_raw_t, ax) }, \
         { "ay", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_evt_gyro_accel_mag_raw_t, ay) }, \
         { "az", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_evt_gyro_accel_mag_raw_t, az) }, \
         { "mx", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_evt_gyro_accel_mag_raw_t, mx) }, \
         { "my", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_evt_gyro_accel_mag_raw_t, my) }, \
         { "mz", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_evt_gyro_accel_mag_raw_t, mz) }, \
         } \
}
#endif

/**
 * @brief Pack a evt_gyro_accel_mag_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param gx  Gyro X
 * @param gy  Gyro Y
 * @param gz  Gyro Z
 * @param ax  Accel X
 * @param ay  Accel Y
 * @param az  Accel Z
 * @param mx  Mag X
 * @param my  Mag Y
 * @param mz  Mag Z
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_evt_gyro_accel_mag_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN];
    _mav_put_float(buf, 0, gx);
    _mav_put_float(buf, 4, gy);
    _mav_put_float(buf, 8, gz);
    _mav_put_float(buf, 12, ax);
    _mav_put_float(buf, 16, ay);
    _mav_put_float(buf, 20, az);
    _mav_put_float(buf, 24, mx);
    _mav_put_float(buf, 28, my);
    _mav_put_float(buf, 32, mz);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN);
#else
    mavlink_evt_gyro_accel_mag_raw_t packet;
    packet.gx = gx;
    packet.gy = gy;
    packet.gz = gz;
    packet.ax = ax;
    packet.ay = ay;
    packet.az = az;
    packet.mx = mx;
    packet.my = my;
    packet.mz = mz;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_CRC);
}

/**
 * @brief Pack a evt_gyro_accel_mag_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gx  Gyro X
 * @param gy  Gyro Y
 * @param gz  Gyro Z
 * @param ax  Accel X
 * @param ay  Accel Y
 * @param az  Accel Z
 * @param mx  Mag X
 * @param my  Mag Y
 * @param mz  Mag Z
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_evt_gyro_accel_mag_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float gx,float gy,float gz,float ax,float ay,float az,float mx,float my,float mz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN];
    _mav_put_float(buf, 0, gx);
    _mav_put_float(buf, 4, gy);
    _mav_put_float(buf, 8, gz);
    _mav_put_float(buf, 12, ax);
    _mav_put_float(buf, 16, ay);
    _mav_put_float(buf, 20, az);
    _mav_put_float(buf, 24, mx);
    _mav_put_float(buf, 28, my);
    _mav_put_float(buf, 32, mz);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN);
#else
    mavlink_evt_gyro_accel_mag_raw_t packet;
    packet.gx = gx;
    packet.gy = gy;
    packet.gz = gz;
    packet.ax = ax;
    packet.ay = ay;
    packet.az = az;
    packet.mx = mx;
    packet.my = my;
    packet.mz = mz;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_CRC);
}

/**
 * @brief Encode a evt_gyro_accel_mag_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param evt_gyro_accel_mag_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_evt_gyro_accel_mag_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_evt_gyro_accel_mag_raw_t* evt_gyro_accel_mag_raw)
{
    return mavlink_msg_evt_gyro_accel_mag_raw_pack(system_id, component_id, msg, evt_gyro_accel_mag_raw->gx, evt_gyro_accel_mag_raw->gy, evt_gyro_accel_mag_raw->gz, evt_gyro_accel_mag_raw->ax, evt_gyro_accel_mag_raw->ay, evt_gyro_accel_mag_raw->az, evt_gyro_accel_mag_raw->mx, evt_gyro_accel_mag_raw->my, evt_gyro_accel_mag_raw->mz);
}

/**
 * @brief Encode a evt_gyro_accel_mag_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param evt_gyro_accel_mag_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_evt_gyro_accel_mag_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_evt_gyro_accel_mag_raw_t* evt_gyro_accel_mag_raw)
{
    return mavlink_msg_evt_gyro_accel_mag_raw_pack_chan(system_id, component_id, chan, msg, evt_gyro_accel_mag_raw->gx, evt_gyro_accel_mag_raw->gy, evt_gyro_accel_mag_raw->gz, evt_gyro_accel_mag_raw->ax, evt_gyro_accel_mag_raw->ay, evt_gyro_accel_mag_raw->az, evt_gyro_accel_mag_raw->mx, evt_gyro_accel_mag_raw->my, evt_gyro_accel_mag_raw->mz);
}

/**
 * @brief Send a evt_gyro_accel_mag_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param gx  Gyro X
 * @param gy  Gyro Y
 * @param gz  Gyro Z
 * @param ax  Accel X
 * @param ay  Accel Y
 * @param az  Accel Z
 * @param mx  Mag X
 * @param my  Mag Y
 * @param mz  Mag Z
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_evt_gyro_accel_mag_raw_send(mavlink_channel_t chan, float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN];
    _mav_put_float(buf, 0, gx);
    _mav_put_float(buf, 4, gy);
    _mav_put_float(buf, 8, gz);
    _mav_put_float(buf, 12, ax);
    _mav_put_float(buf, 16, ay);
    _mav_put_float(buf, 20, az);
    _mav_put_float(buf, 24, mx);
    _mav_put_float(buf, 28, my);
    _mav_put_float(buf, 32, mz);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW, buf, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_CRC);
#else
    mavlink_evt_gyro_accel_mag_raw_t packet;
    packet.gx = gx;
    packet.gy = gy;
    packet.gz = gz;
    packet.ax = ax;
    packet.ay = ay;
    packet.az = az;
    packet.mx = mx;
    packet.my = my;
    packet.mz = mz;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW, (const char *)&packet, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_CRC);
#endif
}

/**
 * @brief Send a evt_gyro_accel_mag_raw message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_evt_gyro_accel_mag_raw_send_struct(mavlink_channel_t chan, const mavlink_evt_gyro_accel_mag_raw_t* evt_gyro_accel_mag_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_evt_gyro_accel_mag_raw_send(chan, evt_gyro_accel_mag_raw->gx, evt_gyro_accel_mag_raw->gy, evt_gyro_accel_mag_raw->gz, evt_gyro_accel_mag_raw->ax, evt_gyro_accel_mag_raw->ay, evt_gyro_accel_mag_raw->az, evt_gyro_accel_mag_raw->mx, evt_gyro_accel_mag_raw->my, evt_gyro_accel_mag_raw->mz);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW, (const char *)evt_gyro_accel_mag_raw, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_CRC);
#endif
}

#if MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_evt_gyro_accel_mag_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, gx);
    _mav_put_float(buf, 4, gy);
    _mav_put_float(buf, 8, gz);
    _mav_put_float(buf, 12, ax);
    _mav_put_float(buf, 16, ay);
    _mav_put_float(buf, 20, az);
    _mav_put_float(buf, 24, mx);
    _mav_put_float(buf, 28, my);
    _mav_put_float(buf, 32, mz);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW, buf, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_CRC);
#else
    mavlink_evt_gyro_accel_mag_raw_t *packet = (mavlink_evt_gyro_accel_mag_raw_t *)msgbuf;
    packet->gx = gx;
    packet->gy = gy;
    packet->gz = gz;
    packet->ax = ax;
    packet->ay = ay;
    packet->az = az;
    packet->mx = mx;
    packet->my = my;
    packet->mz = mz;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW, (const char *)packet, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_MIN_LEN, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_CRC);
#endif
}
#endif

#endif

// MESSAGE EVT_GYRO_ACCEL_MAG_RAW UNPACKING


/**
 * @brief Get field gx from evt_gyro_accel_mag_raw message
 *
 * @return  Gyro X
 */
static inline float mavlink_msg_evt_gyro_accel_mag_raw_get_gx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field gy from evt_gyro_accel_mag_raw message
 *
 * @return  Gyro Y
 */
static inline float mavlink_msg_evt_gyro_accel_mag_raw_get_gy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field gz from evt_gyro_accel_mag_raw message
 *
 * @return  Gyro Z
 */
static inline float mavlink_msg_evt_gyro_accel_mag_raw_get_gz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field ax from evt_gyro_accel_mag_raw message
 *
 * @return  Accel X
 */
static inline float mavlink_msg_evt_gyro_accel_mag_raw_get_ax(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field ay from evt_gyro_accel_mag_raw message
 *
 * @return  Accel Y
 */
static inline float mavlink_msg_evt_gyro_accel_mag_raw_get_ay(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field az from evt_gyro_accel_mag_raw message
 *
 * @return  Accel Z
 */
static inline float mavlink_msg_evt_gyro_accel_mag_raw_get_az(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field mx from evt_gyro_accel_mag_raw message
 *
 * @return  Mag X
 */
static inline float mavlink_msg_evt_gyro_accel_mag_raw_get_mx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field my from evt_gyro_accel_mag_raw message
 *
 * @return  Mag Y
 */
static inline float mavlink_msg_evt_gyro_accel_mag_raw_get_my(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field mz from evt_gyro_accel_mag_raw message
 *
 * @return  Mag Z
 */
static inline float mavlink_msg_evt_gyro_accel_mag_raw_get_mz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Decode a evt_gyro_accel_mag_raw message into a struct
 *
 * @param msg The message to decode
 * @param evt_gyro_accel_mag_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_evt_gyro_accel_mag_raw_decode(const mavlink_message_t* msg, mavlink_evt_gyro_accel_mag_raw_t* evt_gyro_accel_mag_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    evt_gyro_accel_mag_raw->gx = mavlink_msg_evt_gyro_accel_mag_raw_get_gx(msg);
    evt_gyro_accel_mag_raw->gy = mavlink_msg_evt_gyro_accel_mag_raw_get_gy(msg);
    evt_gyro_accel_mag_raw->gz = mavlink_msg_evt_gyro_accel_mag_raw_get_gz(msg);
    evt_gyro_accel_mag_raw->ax = mavlink_msg_evt_gyro_accel_mag_raw_get_ax(msg);
    evt_gyro_accel_mag_raw->ay = mavlink_msg_evt_gyro_accel_mag_raw_get_ay(msg);
    evt_gyro_accel_mag_raw->az = mavlink_msg_evt_gyro_accel_mag_raw_get_az(msg);
    evt_gyro_accel_mag_raw->mx = mavlink_msg_evt_gyro_accel_mag_raw_get_mx(msg);
    evt_gyro_accel_mag_raw->my = mavlink_msg_evt_gyro_accel_mag_raw_get_my(msg);
    evt_gyro_accel_mag_raw->mz = mavlink_msg_evt_gyro_accel_mag_raw_get_mz(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN? msg->len : MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN;
        memset(evt_gyro_accel_mag_raw, 0, MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_LEN);
    memcpy(evt_gyro_accel_mag_raw, _MAV_PAYLOAD(msg), len);
#endif
}
