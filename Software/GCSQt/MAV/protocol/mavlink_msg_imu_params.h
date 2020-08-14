#pragma once
// MESSAGE IMU_PARAMS PACKING

#define MAVLINK_MSG_ID_IMU_PARAMS 9

MAVPACKED(
typedef struct __mavlink_imu_params_t {
 float angle_adjusted; /*<  Angle adjusted*/
 float believe_in_gyro; /*<  Believe in gyro*/
 int16_t gyro_offset_x; /*<  Gyro Offset X*/
 int16_t gyro_offset_y; /*<  Gyro Offset Y*/
 int16_t gyro_offset_z; /*<  Gyro Offset Z*/
 int16_t mag_offset_x; /*<  Mag Offset X*/
 int16_t mag_offset_y; /*<  Mag Offset Y*/
 int16_t mag_offset_z; /*<  Mag Offset Z*/
 int16_t mag_scale_x; /*<  Mag Scale X*/
 int16_t mag_scale_y; /*<  Mag Scale Y*/
 int16_t mag_scale_z; /*<  Mag Scale Z*/
}) mavlink_imu_params_t;

#define MAVLINK_MSG_ID_IMU_PARAMS_LEN 26
#define MAVLINK_MSG_ID_IMU_PARAMS_MIN_LEN 26
#define MAVLINK_MSG_ID_9_LEN 26
#define MAVLINK_MSG_ID_9_MIN_LEN 26

#define MAVLINK_MSG_ID_IMU_PARAMS_CRC 108
#define MAVLINK_MSG_ID_9_CRC 108



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_IMU_PARAMS { \
    9, \
    "IMU_PARAMS", \
    11, \
    {  { "gyro_offset_x", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_imu_params_t, gyro_offset_x) }, \
         { "gyro_offset_y", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_imu_params_t, gyro_offset_y) }, \
         { "gyro_offset_z", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_imu_params_t, gyro_offset_z) }, \
         { "mag_offset_x", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_imu_params_t, mag_offset_x) }, \
         { "mag_offset_y", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_imu_params_t, mag_offset_y) }, \
         { "mag_offset_z", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_imu_params_t, mag_offset_z) }, \
         { "mag_scale_x", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_imu_params_t, mag_scale_x) }, \
         { "mag_scale_y", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_imu_params_t, mag_scale_y) }, \
         { "mag_scale_z", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_imu_params_t, mag_scale_z) }, \
         { "angle_adjusted", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_imu_params_t, angle_adjusted) }, \
         { "believe_in_gyro", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_imu_params_t, believe_in_gyro) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_IMU_PARAMS { \
    "IMU_PARAMS", \
    11, \
    {  { "gyro_offset_x", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_imu_params_t, gyro_offset_x) }, \
         { "gyro_offset_y", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_imu_params_t, gyro_offset_y) }, \
         { "gyro_offset_z", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_imu_params_t, gyro_offset_z) }, \
         { "mag_offset_x", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_imu_params_t, mag_offset_x) }, \
         { "mag_offset_y", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_imu_params_t, mag_offset_y) }, \
         { "mag_offset_z", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_imu_params_t, mag_offset_z) }, \
         { "mag_scale_x", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_imu_params_t, mag_scale_x) }, \
         { "mag_scale_y", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_imu_params_t, mag_scale_y) }, \
         { "mag_scale_z", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_imu_params_t, mag_scale_z) }, \
         { "angle_adjusted", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_imu_params_t, angle_adjusted) }, \
         { "believe_in_gyro", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_imu_params_t, believe_in_gyro) }, \
         } \
}
#endif

/**
 * @brief Pack a imu_params message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param gyro_offset_x  Gyro Offset X
 * @param gyro_offset_y  Gyro Offset Y
 * @param gyro_offset_z  Gyro Offset Z
 * @param mag_offset_x  Mag Offset X
 * @param mag_offset_y  Mag Offset Y
 * @param mag_offset_z  Mag Offset Z
 * @param mag_scale_x  Mag Scale X
 * @param mag_scale_y  Mag Scale Y
 * @param mag_scale_z  Mag Scale Z
 * @param angle_adjusted  Angle adjusted
 * @param believe_in_gyro  Believe in gyro
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_imu_params_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t gyro_offset_x, int16_t gyro_offset_y, int16_t gyro_offset_z, int16_t mag_offset_x, int16_t mag_offset_y, int16_t mag_offset_z, int16_t mag_scale_x, int16_t mag_scale_y, int16_t mag_scale_z, float angle_adjusted, float believe_in_gyro)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IMU_PARAMS_LEN];
    _mav_put_float(buf, 0, angle_adjusted);
    _mav_put_float(buf, 4, believe_in_gyro);
    _mav_put_int16_t(buf, 8, gyro_offset_x);
    _mav_put_int16_t(buf, 10, gyro_offset_y);
    _mav_put_int16_t(buf, 12, gyro_offset_z);
    _mav_put_int16_t(buf, 14, mag_offset_x);
    _mav_put_int16_t(buf, 16, mag_offset_y);
    _mav_put_int16_t(buf, 18, mag_offset_z);
    _mav_put_int16_t(buf, 20, mag_scale_x);
    _mav_put_int16_t(buf, 22, mag_scale_y);
    _mav_put_int16_t(buf, 24, mag_scale_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IMU_PARAMS_LEN);
#else
    mavlink_imu_params_t packet;
    packet.angle_adjusted = angle_adjusted;
    packet.believe_in_gyro = believe_in_gyro;
    packet.gyro_offset_x = gyro_offset_x;
    packet.gyro_offset_y = gyro_offset_y;
    packet.gyro_offset_z = gyro_offset_z;
    packet.mag_offset_x = mag_offset_x;
    packet.mag_offset_y = mag_offset_y;
    packet.mag_offset_z = mag_offset_z;
    packet.mag_scale_x = mag_scale_x;
    packet.mag_scale_y = mag_scale_y;
    packet.mag_scale_z = mag_scale_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IMU_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_IMU_PARAMS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_IMU_PARAMS_MIN_LEN, MAVLINK_MSG_ID_IMU_PARAMS_LEN, MAVLINK_MSG_ID_IMU_PARAMS_CRC);
}

/**
 * @brief Pack a imu_params message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gyro_offset_x  Gyro Offset X
 * @param gyro_offset_y  Gyro Offset Y
 * @param gyro_offset_z  Gyro Offset Z
 * @param mag_offset_x  Mag Offset X
 * @param mag_offset_y  Mag Offset Y
 * @param mag_offset_z  Mag Offset Z
 * @param mag_scale_x  Mag Scale X
 * @param mag_scale_y  Mag Scale Y
 * @param mag_scale_z  Mag Scale Z
 * @param angle_adjusted  Angle adjusted
 * @param believe_in_gyro  Believe in gyro
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_imu_params_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t gyro_offset_x,int16_t gyro_offset_y,int16_t gyro_offset_z,int16_t mag_offset_x,int16_t mag_offset_y,int16_t mag_offset_z,int16_t mag_scale_x,int16_t mag_scale_y,int16_t mag_scale_z,float angle_adjusted,float believe_in_gyro)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IMU_PARAMS_LEN];
    _mav_put_float(buf, 0, angle_adjusted);
    _mav_put_float(buf, 4, believe_in_gyro);
    _mav_put_int16_t(buf, 8, gyro_offset_x);
    _mav_put_int16_t(buf, 10, gyro_offset_y);
    _mav_put_int16_t(buf, 12, gyro_offset_z);
    _mav_put_int16_t(buf, 14, mag_offset_x);
    _mav_put_int16_t(buf, 16, mag_offset_y);
    _mav_put_int16_t(buf, 18, mag_offset_z);
    _mav_put_int16_t(buf, 20, mag_scale_x);
    _mav_put_int16_t(buf, 22, mag_scale_y);
    _mav_put_int16_t(buf, 24, mag_scale_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IMU_PARAMS_LEN);
#else
    mavlink_imu_params_t packet;
    packet.angle_adjusted = angle_adjusted;
    packet.believe_in_gyro = believe_in_gyro;
    packet.gyro_offset_x = gyro_offset_x;
    packet.gyro_offset_y = gyro_offset_y;
    packet.gyro_offset_z = gyro_offset_z;
    packet.mag_offset_x = mag_offset_x;
    packet.mag_offset_y = mag_offset_y;
    packet.mag_offset_z = mag_offset_z;
    packet.mag_scale_x = mag_scale_x;
    packet.mag_scale_y = mag_scale_y;
    packet.mag_scale_z = mag_scale_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IMU_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_IMU_PARAMS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_IMU_PARAMS_MIN_LEN, MAVLINK_MSG_ID_IMU_PARAMS_LEN, MAVLINK_MSG_ID_IMU_PARAMS_CRC);
}

/**
 * @brief Encode a imu_params struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param imu_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_imu_params_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_imu_params_t* imu_params)
{
    return mavlink_msg_imu_params_pack(system_id, component_id, msg, imu_params->gyro_offset_x, imu_params->gyro_offset_y, imu_params->gyro_offset_z, imu_params->mag_offset_x, imu_params->mag_offset_y, imu_params->mag_offset_z, imu_params->mag_scale_x, imu_params->mag_scale_y, imu_params->mag_scale_z, imu_params->angle_adjusted, imu_params->believe_in_gyro);
}

/**
 * @brief Encode a imu_params struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param imu_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_imu_params_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_imu_params_t* imu_params)
{
    return mavlink_msg_imu_params_pack_chan(system_id, component_id, chan, msg, imu_params->gyro_offset_x, imu_params->gyro_offset_y, imu_params->gyro_offset_z, imu_params->mag_offset_x, imu_params->mag_offset_y, imu_params->mag_offset_z, imu_params->mag_scale_x, imu_params->mag_scale_y, imu_params->mag_scale_z, imu_params->angle_adjusted, imu_params->believe_in_gyro);
}

/**
 * @brief Send a imu_params message
 * @param chan MAVLink channel to send the message
 *
 * @param gyro_offset_x  Gyro Offset X
 * @param gyro_offset_y  Gyro Offset Y
 * @param gyro_offset_z  Gyro Offset Z
 * @param mag_offset_x  Mag Offset X
 * @param mag_offset_y  Mag Offset Y
 * @param mag_offset_z  Mag Offset Z
 * @param mag_scale_x  Mag Scale X
 * @param mag_scale_y  Mag Scale Y
 * @param mag_scale_z  Mag Scale Z
 * @param angle_adjusted  Angle adjusted
 * @param believe_in_gyro  Believe in gyro
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_imu_params_send(mavlink_channel_t chan, int16_t gyro_offset_x, int16_t gyro_offset_y, int16_t gyro_offset_z, int16_t mag_offset_x, int16_t mag_offset_y, int16_t mag_offset_z, int16_t mag_scale_x, int16_t mag_scale_y, int16_t mag_scale_z, float angle_adjusted, float believe_in_gyro)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IMU_PARAMS_LEN];
    _mav_put_float(buf, 0, angle_adjusted);
    _mav_put_float(buf, 4, believe_in_gyro);
    _mav_put_int16_t(buf, 8, gyro_offset_x);
    _mav_put_int16_t(buf, 10, gyro_offset_y);
    _mav_put_int16_t(buf, 12, gyro_offset_z);
    _mav_put_int16_t(buf, 14, mag_offset_x);
    _mav_put_int16_t(buf, 16, mag_offset_y);
    _mav_put_int16_t(buf, 18, mag_offset_z);
    _mav_put_int16_t(buf, 20, mag_scale_x);
    _mav_put_int16_t(buf, 22, mag_scale_y);
    _mav_put_int16_t(buf, 24, mag_scale_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_PARAMS, buf, MAVLINK_MSG_ID_IMU_PARAMS_MIN_LEN, MAVLINK_MSG_ID_IMU_PARAMS_LEN, MAVLINK_MSG_ID_IMU_PARAMS_CRC);
#else
    mavlink_imu_params_t packet;
    packet.angle_adjusted = angle_adjusted;
    packet.believe_in_gyro = believe_in_gyro;
    packet.gyro_offset_x = gyro_offset_x;
    packet.gyro_offset_y = gyro_offset_y;
    packet.gyro_offset_z = gyro_offset_z;
    packet.mag_offset_x = mag_offset_x;
    packet.mag_offset_y = mag_offset_y;
    packet.mag_offset_z = mag_offset_z;
    packet.mag_scale_x = mag_scale_x;
    packet.mag_scale_y = mag_scale_y;
    packet.mag_scale_z = mag_scale_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_PARAMS, (const char *)&packet, MAVLINK_MSG_ID_IMU_PARAMS_MIN_LEN, MAVLINK_MSG_ID_IMU_PARAMS_LEN, MAVLINK_MSG_ID_IMU_PARAMS_CRC);
#endif
}

/**
 * @brief Send a imu_params message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_imu_params_send_struct(mavlink_channel_t chan, const mavlink_imu_params_t* imu_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_imu_params_send(chan, imu_params->gyro_offset_x, imu_params->gyro_offset_y, imu_params->gyro_offset_z, imu_params->mag_offset_x, imu_params->mag_offset_y, imu_params->mag_offset_z, imu_params->mag_scale_x, imu_params->mag_scale_y, imu_params->mag_scale_z, imu_params->angle_adjusted, imu_params->believe_in_gyro);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_PARAMS, (const char *)imu_params, MAVLINK_MSG_ID_IMU_PARAMS_MIN_LEN, MAVLINK_MSG_ID_IMU_PARAMS_LEN, MAVLINK_MSG_ID_IMU_PARAMS_CRC);
#endif
}

#if MAVLINK_MSG_ID_IMU_PARAMS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_imu_params_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t gyro_offset_x, int16_t gyro_offset_y, int16_t gyro_offset_z, int16_t mag_offset_x, int16_t mag_offset_y, int16_t mag_offset_z, int16_t mag_scale_x, int16_t mag_scale_y, int16_t mag_scale_z, float angle_adjusted, float believe_in_gyro)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, angle_adjusted);
    _mav_put_float(buf, 4, believe_in_gyro);
    _mav_put_int16_t(buf, 8, gyro_offset_x);
    _mav_put_int16_t(buf, 10, gyro_offset_y);
    _mav_put_int16_t(buf, 12, gyro_offset_z);
    _mav_put_int16_t(buf, 14, mag_offset_x);
    _mav_put_int16_t(buf, 16, mag_offset_y);
    _mav_put_int16_t(buf, 18, mag_offset_z);
    _mav_put_int16_t(buf, 20, mag_scale_x);
    _mav_put_int16_t(buf, 22, mag_scale_y);
    _mav_put_int16_t(buf, 24, mag_scale_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_PARAMS, buf, MAVLINK_MSG_ID_IMU_PARAMS_MIN_LEN, MAVLINK_MSG_ID_IMU_PARAMS_LEN, MAVLINK_MSG_ID_IMU_PARAMS_CRC);
#else
    mavlink_imu_params_t *packet = (mavlink_imu_params_t *)msgbuf;
    packet->angle_adjusted = angle_adjusted;
    packet->believe_in_gyro = believe_in_gyro;
    packet->gyro_offset_x = gyro_offset_x;
    packet->gyro_offset_y = gyro_offset_y;
    packet->gyro_offset_z = gyro_offset_z;
    packet->mag_offset_x = mag_offset_x;
    packet->mag_offset_y = mag_offset_y;
    packet->mag_offset_z = mag_offset_z;
    packet->mag_scale_x = mag_scale_x;
    packet->mag_scale_y = mag_scale_y;
    packet->mag_scale_z = mag_scale_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_PARAMS, (const char *)packet, MAVLINK_MSG_ID_IMU_PARAMS_MIN_LEN, MAVLINK_MSG_ID_IMU_PARAMS_LEN, MAVLINK_MSG_ID_IMU_PARAMS_CRC);
#endif
}
#endif

#endif

// MESSAGE IMU_PARAMS UNPACKING


/**
 * @brief Get field gyro_offset_x from imu_params message
 *
 * @return  Gyro Offset X
 */
static inline int16_t mavlink_msg_imu_params_get_gyro_offset_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field gyro_offset_y from imu_params message
 *
 * @return  Gyro Offset Y
 */
static inline int16_t mavlink_msg_imu_params_get_gyro_offset_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field gyro_offset_z from imu_params message
 *
 * @return  Gyro Offset Z
 */
static inline int16_t mavlink_msg_imu_params_get_gyro_offset_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field mag_offset_x from imu_params message
 *
 * @return  Mag Offset X
 */
static inline int16_t mavlink_msg_imu_params_get_mag_offset_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field mag_offset_y from imu_params message
 *
 * @return  Mag Offset Y
 */
static inline int16_t mavlink_msg_imu_params_get_mag_offset_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field mag_offset_z from imu_params message
 *
 * @return  Mag Offset Z
 */
static inline int16_t mavlink_msg_imu_params_get_mag_offset_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field mag_scale_x from imu_params message
 *
 * @return  Mag Scale X
 */
static inline int16_t mavlink_msg_imu_params_get_mag_scale_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field mag_scale_y from imu_params message
 *
 * @return  Mag Scale Y
 */
static inline int16_t mavlink_msg_imu_params_get_mag_scale_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field mag_scale_z from imu_params message
 *
 * @return  Mag Scale Z
 */
static inline int16_t mavlink_msg_imu_params_get_mag_scale_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field angle_adjusted from imu_params message
 *
 * @return  Angle adjusted
 */
static inline float mavlink_msg_imu_params_get_angle_adjusted(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field believe_in_gyro from imu_params message
 *
 * @return  Believe in gyro
 */
static inline float mavlink_msg_imu_params_get_believe_in_gyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a imu_params message into a struct
 *
 * @param msg The message to decode
 * @param imu_params C-struct to decode the message contents into
 */
static inline void mavlink_msg_imu_params_decode(const mavlink_message_t* msg, mavlink_imu_params_t* imu_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    imu_params->angle_adjusted = mavlink_msg_imu_params_get_angle_adjusted(msg);
    imu_params->believe_in_gyro = mavlink_msg_imu_params_get_believe_in_gyro(msg);
    imu_params->gyro_offset_x = mavlink_msg_imu_params_get_gyro_offset_x(msg);
    imu_params->gyro_offset_y = mavlink_msg_imu_params_get_gyro_offset_y(msg);
    imu_params->gyro_offset_z = mavlink_msg_imu_params_get_gyro_offset_z(msg);
    imu_params->mag_offset_x = mavlink_msg_imu_params_get_mag_offset_x(msg);
    imu_params->mag_offset_y = mavlink_msg_imu_params_get_mag_offset_y(msg);
    imu_params->mag_offset_z = mavlink_msg_imu_params_get_mag_offset_z(msg);
    imu_params->mag_scale_x = mavlink_msg_imu_params_get_mag_scale_x(msg);
    imu_params->mag_scale_y = mavlink_msg_imu_params_get_mag_scale_y(msg);
    imu_params->mag_scale_z = mavlink_msg_imu_params_get_mag_scale_z(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_IMU_PARAMS_LEN? msg->len : MAVLINK_MSG_ID_IMU_PARAMS_LEN;
        memset(imu_params, 0, MAVLINK_MSG_ID_IMU_PARAMS_LEN);
    memcpy(imu_params, _MAV_PAYLOAD(msg), len);
#endif
}
