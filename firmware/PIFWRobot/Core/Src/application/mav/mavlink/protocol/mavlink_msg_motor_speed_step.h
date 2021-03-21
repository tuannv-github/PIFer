#pragma once
// MESSAGE MOTOR_SPEED_STEP PACKING

#define MAVLINK_MSG_ID_MOTOR_SPEED_STEP 8


typedef struct __mavlink_motor_speed_step_t {
 float motor_0; /*<  Motor 0 speed*/
 float motor_1; /*<  Motor 1 Speed*/
} mavlink_motor_speed_step_t;

#define MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN 8
#define MAVLINK_MSG_ID_MOTOR_SPEED_STEP_MIN_LEN 8
#define MAVLINK_MSG_ID_8_LEN 8
#define MAVLINK_MSG_ID_8_MIN_LEN 8

#define MAVLINK_MSG_ID_MOTOR_SPEED_STEP_CRC 75
#define MAVLINK_MSG_ID_8_CRC 75



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MOTOR_SPEED_STEP { \
    8, \
    "MOTOR_SPEED_STEP", \
    2, \
    {  { "motor_0", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_motor_speed_step_t, motor_0) }, \
         { "motor_1", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_motor_speed_step_t, motor_1) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MOTOR_SPEED_STEP { \
    "MOTOR_SPEED_STEP", \
    2, \
    {  { "motor_0", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_motor_speed_step_t, motor_0) }, \
         { "motor_1", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_motor_speed_step_t, motor_1) }, \
         } \
}
#endif

/**
 * @brief Pack a motor_speed_step message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param motor_0  Motor 0 speed
 * @param motor_1  Motor 1 Speed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_speed_step_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float motor_0, float motor_1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN];
    _mav_put_float(buf, 0, motor_0);
    _mav_put_float(buf, 4, motor_1);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN);
#else
    mavlink_motor_speed_step_t packet;
    packet.motor_0 = motor_0;
    packet.motor_1 = motor_1;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOTOR_SPEED_STEP;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_MIN_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_CRC);
}

/**
 * @brief Pack a motor_speed_step message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor_0  Motor 0 speed
 * @param motor_1  Motor 1 Speed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_speed_step_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float motor_0,float motor_1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN];
    _mav_put_float(buf, 0, motor_0);
    _mav_put_float(buf, 4, motor_1);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN);
#else
    mavlink_motor_speed_step_t packet;
    packet.motor_0 = motor_0;
    packet.motor_1 = motor_1;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOTOR_SPEED_STEP;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_MIN_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_CRC);
}

/**
 * @brief Encode a motor_speed_step struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param motor_speed_step C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_speed_step_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_motor_speed_step_t* motor_speed_step)
{
    return mavlink_msg_motor_speed_step_pack(system_id, component_id, msg, motor_speed_step->motor_0, motor_speed_step->motor_1);
}

/**
 * @brief Encode a motor_speed_step struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor_speed_step C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_speed_step_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_motor_speed_step_t* motor_speed_step)
{
    return mavlink_msg_motor_speed_step_pack_chan(system_id, component_id, chan, msg, motor_speed_step->motor_0, motor_speed_step->motor_1);
}

/**
 * @brief Send a motor_speed_step message
 * @param chan MAVLink channel to send the message
 *
 * @param motor_0  Motor 0 speed
 * @param motor_1  Motor 1 Speed
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_motor_speed_step_send(mavlink_channel_t chan, float motor_0, float motor_1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN];
    _mav_put_float(buf, 0, motor_0);
    _mav_put_float(buf, 4, motor_1);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_SPEED_STEP, buf, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_MIN_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_CRC);
#else
    mavlink_motor_speed_step_t packet;
    packet.motor_0 = motor_0;
    packet.motor_1 = motor_1;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_SPEED_STEP, (const char *)&packet, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_MIN_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_CRC);
#endif
}

/**
 * @brief Send a motor_speed_step message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_motor_speed_step_send_struct(mavlink_channel_t chan, const mavlink_motor_speed_step_t* motor_speed_step)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_motor_speed_step_send(chan, motor_speed_step->motor_0, motor_speed_step->motor_1);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_SPEED_STEP, (const char *)motor_speed_step, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_MIN_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_CRC);
#endif
}

#if MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_motor_speed_step_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float motor_0, float motor_1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, motor_0);
    _mav_put_float(buf, 4, motor_1);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_SPEED_STEP, buf, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_MIN_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_CRC);
#else
    mavlink_motor_speed_step_t *packet = (mavlink_motor_speed_step_t *)msgbuf;
    packet->motor_0 = motor_0;
    packet->motor_1 = motor_1;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_SPEED_STEP, (const char *)packet, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_MIN_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_CRC);
#endif
}
#endif

#endif

// MESSAGE MOTOR_SPEED_STEP UNPACKING


/**
 * @brief Get field motor_0 from motor_speed_step message
 *
 * @return  Motor 0 speed
 */
static inline float mavlink_msg_motor_speed_step_get_motor_0(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field motor_1 from motor_speed_step message
 *
 * @return  Motor 1 Speed
 */
static inline float mavlink_msg_motor_speed_step_get_motor_1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a motor_speed_step message into a struct
 *
 * @param msg The message to decode
 * @param motor_speed_step C-struct to decode the message contents into
 */
static inline void mavlink_msg_motor_speed_step_decode(const mavlink_message_t* msg, mavlink_motor_speed_step_t* motor_speed_step)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    motor_speed_step->motor_0 = mavlink_msg_motor_speed_step_get_motor_0(msg);
    motor_speed_step->motor_1 = mavlink_msg_motor_speed_step_get_motor_1(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN? msg->len : MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN;
        memset(motor_speed_step, 0, MAVLINK_MSG_ID_MOTOR_SPEED_STEP_LEN);
    memcpy(motor_speed_step, _MAV_PAYLOAD(msg), len);
#endif
}
