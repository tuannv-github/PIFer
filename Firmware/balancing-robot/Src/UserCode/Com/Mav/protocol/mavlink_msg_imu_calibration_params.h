#pragma once
// MESSAGE IMU_CALIBRATION_PARAMS PACKING

#define MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS 9

MAVPACKED(
typedef struct __mavlink_imu_calibration_params_t {
 float angle_ajusted; /*<  Angle ajusted*/
 float believe_in_gyro; /*<  Believe in gyro*/
 int16_t gyro_offet_x; /*<  Gyro Offset X*/
 int16_t gyro_offet_y; /*<  Gyro Offset Y*/
 int16_t gyro_offet_z; /*<  Gyro Offset Z*/
}) mavlink_imu_calibration_params_t;

#define MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN 14
#define MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_MIN_LEN 14
#define MAVLINK_MSG_ID_9_LEN 14
#define MAVLINK_MSG_ID_9_MIN_LEN 14

#define MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_CRC 119
#define MAVLINK_MSG_ID_9_CRC 119



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_IMU_CALIBRATION_PARAMS { \
    9, \
    "IMU_CALIBRATION_PARAMS", \
    5, \
    {  { "gyro_offet_x", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_imu_calibration_params_t, gyro_offet_x) }, \
         { "gyro_offet_y", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_imu_calibration_params_t, gyro_offet_y) }, \
         { "gyro_offet_z", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_imu_calibration_params_t, gyro_offet_z) }, \
         { "angle_ajusted", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_imu_calibration_params_t, angle_ajusted) }, \
         { "believe_in_gyro", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_imu_calibration_params_t, believe_in_gyro) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_IMU_CALIBRATION_PARAMS { \
    "IMU_CALIBRATION_PARAMS", \
    5, \
    {  { "gyro_offet_x", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_imu_calibration_params_t, gyro_offet_x) }, \
         { "gyro_offet_y", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_imu_calibration_params_t, gyro_offet_y) }, \
         { "gyro_offet_z", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_imu_calibration_params_t, gyro_offet_z) }, \
         { "angle_ajusted", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_imu_calibration_params_t, angle_ajusted) }, \
         { "believe_in_gyro", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_imu_calibration_params_t, believe_in_gyro) }, \
         } \
}
#endif

/**
 * @brief Pack a imu_calibration_params message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param gyro_offet_x  Gyro Offset X
 * @param gyro_offet_y  Gyro Offset Y
 * @param gyro_offet_z  Gyro Offset Z
 * @param angle_ajusted  Angle ajusted
 * @param believe_in_gyro  Believe in gyro
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_imu_calibration_params_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t gyro_offet_x, int16_t gyro_offet_y, int16_t gyro_offet_z, float angle_ajusted, float believe_in_gyro)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN];
    _mav_put_float(buf, 0, angle_ajusted);
    _mav_put_float(buf, 4, believe_in_gyro);
    _mav_put_int16_t(buf, 8, gyro_offet_x);
    _mav_put_int16_t(buf, 10, gyro_offet_y);
    _mav_put_int16_t(buf, 12, gyro_offet_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN);
#else
    mavlink_imu_calibration_params_t packet;
    packet.angle_ajusted = angle_ajusted;
    packet.believe_in_gyro = believe_in_gyro;
    packet.gyro_offet_x = gyro_offet_x;
    packet.gyro_offet_y = gyro_offet_y;
    packet.gyro_offet_z = gyro_offet_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_MIN_LEN, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_CRC);
}

/**
 * @brief Pack a imu_calibration_params message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gyro_offet_x  Gyro Offset X
 * @param gyro_offet_y  Gyro Offset Y
 * @param gyro_offet_z  Gyro Offset Z
 * @param angle_ajusted  Angle ajusted
 * @param believe_in_gyro  Believe in gyro
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_imu_calibration_params_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t gyro_offet_x,int16_t gyro_offet_y,int16_t gyro_offet_z,float angle_ajusted,float believe_in_gyro)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN];
    _mav_put_float(buf, 0, angle_ajusted);
    _mav_put_float(buf, 4, believe_in_gyro);
    _mav_put_int16_t(buf, 8, gyro_offet_x);
    _mav_put_int16_t(buf, 10, gyro_offet_y);
    _mav_put_int16_t(buf, 12, gyro_offet_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN);
#else
    mavlink_imu_calibration_params_t packet;
    packet.angle_ajusted = angle_ajusted;
    packet.believe_in_gyro = believe_in_gyro;
    packet.gyro_offet_x = gyro_offet_x;
    packet.gyro_offet_y = gyro_offet_y;
    packet.gyro_offet_z = gyro_offet_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_MIN_LEN, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_CRC);
}

/**
 * @brief Encode a imu_calibration_params struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param imu_calibration_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_imu_calibration_params_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_imu_calibration_params_t* imu_calibration_params)
{
    return mavlink_msg_imu_calibration_params_pack(system_id, component_id, msg, imu_calibration_params->gyro_offet_x, imu_calibration_params->gyro_offet_y, imu_calibration_params->gyro_offet_z, imu_calibration_params->angle_ajusted, imu_calibration_params->believe_in_gyro);
}

/**
 * @brief Encode a imu_calibration_params struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param imu_calibration_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_imu_calibration_params_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_imu_calibration_params_t* imu_calibration_params)
{
    return mavlink_msg_imu_calibration_params_pack_chan(system_id, component_id, chan, msg, imu_calibration_params->gyro_offet_x, imu_calibration_params->gyro_offet_y, imu_calibration_params->gyro_offet_z, imu_calibration_params->angle_ajusted, imu_calibration_params->believe_in_gyro);
}

/**
 * @brief Send a imu_calibration_params message
 * @param chan MAVLink channel to send the message
 *
 * @param gyro_offet_x  Gyro Offset X
 * @param gyro_offet_y  Gyro Offset Y
 * @param gyro_offet_z  Gyro Offset Z
 * @param angle_ajusted  Angle ajusted
 * @param believe_in_gyro  Believe in gyro
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_imu_calibration_params_send(mavlink_channel_t chan, int16_t gyro_offet_x, int16_t gyro_offet_y, int16_t gyro_offet_z, float angle_ajusted, float believe_in_gyro)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN];
    _mav_put_float(buf, 0, angle_ajusted);
    _mav_put_float(buf, 4, believe_in_gyro);
    _mav_put_int16_t(buf, 8, gyro_offet_x);
    _mav_put_int16_t(buf, 10, gyro_offet_y);
    _mav_put_int16_t(buf, 12, gyro_offet_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS, buf, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_MIN_LEN, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_CRC);
#else
    mavlink_imu_calibration_params_t packet;
    packet.angle_ajusted = angle_ajusted;
    packet.believe_in_gyro = believe_in_gyro;
    packet.gyro_offet_x = gyro_offet_x;
    packet.gyro_offet_y = gyro_offet_y;
    packet.gyro_offet_z = gyro_offet_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS, (const char *)&packet, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_MIN_LEN, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_CRC);
#endif
}

/**
 * @brief Send a imu_calibration_params message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_imu_calibration_params_send_struct(mavlink_channel_t chan, const mavlink_imu_calibration_params_t* imu_calibration_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_imu_calibration_params_send(chan, imu_calibration_params->gyro_offet_x, imu_calibration_params->gyro_offet_y, imu_calibration_params->gyro_offet_z, imu_calibration_params->angle_ajusted, imu_calibration_params->believe_in_gyro);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS, (const char *)imu_calibration_params, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_MIN_LEN, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_CRC);
#endif
}

#if MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_imu_calibration_params_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t gyro_offet_x, int16_t gyro_offet_y, int16_t gyro_offet_z, float angle_ajusted, float believe_in_gyro)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, angle_ajusted);
    _mav_put_float(buf, 4, believe_in_gyro);
    _mav_put_int16_t(buf, 8, gyro_offet_x);
    _mav_put_int16_t(buf, 10, gyro_offet_y);
    _mav_put_int16_t(buf, 12, gyro_offet_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS, buf, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_MIN_LEN, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_CRC);
#else
    mavlink_imu_calibration_params_t *packet = (mavlink_imu_calibration_params_t *)msgbuf;
    packet->angle_ajusted = angle_ajusted;
    packet->believe_in_gyro = believe_in_gyro;
    packet->gyro_offet_x = gyro_offet_x;
    packet->gyro_offet_y = gyro_offet_y;
    packet->gyro_offet_z = gyro_offet_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS, (const char *)packet, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_MIN_LEN, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_CRC);
#endif
}
#endif

#endif

// MESSAGE IMU_CALIBRATION_PARAMS UNPACKING


/**
 * @brief Get field gyro_offet_x from imu_calibration_params message
 *
 * @return  Gyro Offset X
 */
static inline int16_t mavlink_msg_imu_calibration_params_get_gyro_offet_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field gyro_offet_y from imu_calibration_params message
 *
 * @return  Gyro Offset Y
 */
static inline int16_t mavlink_msg_imu_calibration_params_get_gyro_offet_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field gyro_offet_z from imu_calibration_params message
 *
 * @return  Gyro Offset Z
 */
static inline int16_t mavlink_msg_imu_calibration_params_get_gyro_offet_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field angle_ajusted from imu_calibration_params message
 *
 * @return  Angle ajusted
 */
static inline float mavlink_msg_imu_calibration_params_get_angle_ajusted(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field believe_in_gyro from imu_calibration_params message
 *
 * @return  Believe in gyro
 */
static inline float mavlink_msg_imu_calibration_params_get_believe_in_gyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a imu_calibration_params message into a struct
 *
 * @param msg The message to decode
 * @param imu_calibration_params C-struct to decode the message contents into
 */
static inline void mavlink_msg_imu_calibration_params_decode(const mavlink_message_t* msg, mavlink_imu_calibration_params_t* imu_calibration_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    imu_calibration_params->angle_ajusted = mavlink_msg_imu_calibration_params_get_angle_ajusted(msg);
    imu_calibration_params->believe_in_gyro = mavlink_msg_imu_calibration_params_get_believe_in_gyro(msg);
    imu_calibration_params->gyro_offet_x = mavlink_msg_imu_calibration_params_get_gyro_offet_x(msg);
    imu_calibration_params->gyro_offet_y = mavlink_msg_imu_calibration_params_get_gyro_offet_y(msg);
    imu_calibration_params->gyro_offet_z = mavlink_msg_imu_calibration_params_get_gyro_offet_z(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN? msg->len : MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN;
        memset(imu_calibration_params, 0, MAVLINK_MSG_ID_IMU_CALIBRATION_PARAMS_LEN);
    memcpy(imu_calibration_params, _MAV_PAYLOAD(msg), len);
#endif
}
