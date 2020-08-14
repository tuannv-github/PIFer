#pragma once
// MESSAGE MOTOR_SPEED PACKING

#define MAVLINK_MSG_ID_MOTOR_SPEED 7

MAVPACKED(
typedef struct __mavlink_motor_speed_t {
 int16_t motor_speed_0; /*<  Motor 0 speed*/
 int16_t motor_speed_1; /*<  Motor 1 Speed*/
}) mavlink_motor_speed_t;

#define MAVLINK_MSG_ID_MOTOR_SPEED_LEN 4
#define MAVLINK_MSG_ID_MOTOR_SPEED_MIN_LEN 4
#define MAVLINK_MSG_ID_7_LEN 4
#define MAVLINK_MSG_ID_7_MIN_LEN 4

#define MAVLINK_MSG_ID_MOTOR_SPEED_CRC 183
#define MAVLINK_MSG_ID_7_CRC 183



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MOTOR_SPEED { \
    7, \
    "MOTOR_SPEED", \
    2, \
    {  { "motor_speed_0", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_motor_speed_t, motor_speed_0) }, \
         { "motor_speed_1", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_motor_speed_t, motor_speed_1) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MOTOR_SPEED { \
    "MOTOR_SPEED", \
    2, \
    {  { "motor_speed_0", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_motor_speed_t, motor_speed_0) }, \
         { "motor_speed_1", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_motor_speed_t, motor_speed_1) }, \
         } \
}
#endif

/**
 * @brief Pack a motor_speed message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param motor_speed_0  Motor 0 speed
 * @param motor_speed_1  Motor 1 Speed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_speed_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t motor_speed_0, int16_t motor_speed_1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_SPEED_LEN];
    _mav_put_int16_t(buf, 0, motor_speed_0);
    _mav_put_int16_t(buf, 2, motor_speed_1);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_SPEED_LEN);
#else
    mavlink_motor_speed_t packet;
    packet.motor_speed_0 = motor_speed_0;
    packet.motor_speed_1 = motor_speed_1;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_SPEED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOTOR_SPEED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTOR_SPEED_MIN_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_CRC);
}

/**
 * @brief Pack a motor_speed message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor_speed_0  Motor 0 speed
 * @param motor_speed_1  Motor 1 Speed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_speed_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t motor_speed_0,int16_t motor_speed_1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_SPEED_LEN];
    _mav_put_int16_t(buf, 0, motor_speed_0);
    _mav_put_int16_t(buf, 2, motor_speed_1);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_SPEED_LEN);
#else
    mavlink_motor_speed_t packet;
    packet.motor_speed_0 = motor_speed_0;
    packet.motor_speed_1 = motor_speed_1;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_SPEED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOTOR_SPEED;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTOR_SPEED_MIN_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_CRC);
}

/**
 * @brief Encode a motor_speed struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param motor_speed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_speed_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_motor_speed_t* motor_speed)
{
    return mavlink_msg_motor_speed_pack(system_id, component_id, msg, motor_speed->motor_speed_0, motor_speed->motor_speed_1);
}

/**
 * @brief Encode a motor_speed struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor_speed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_speed_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_motor_speed_t* motor_speed)
{
    return mavlink_msg_motor_speed_pack_chan(system_id, component_id, chan, msg, motor_speed->motor_speed_0, motor_speed->motor_speed_1);
}

/**
 * @brief Send a motor_speed message
 * @param chan MAVLink channel to send the message
 *
 * @param motor_speed_0  Motor 0 speed
 * @param motor_speed_1  Motor 1 Speed
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_motor_speed_send(mavlink_channel_t chan, int16_t motor_speed_0, int16_t motor_speed_1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_SPEED_LEN];
    _mav_put_int16_t(buf, 0, motor_speed_0);
    _mav_put_int16_t(buf, 2, motor_speed_1);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_SPEED, buf, MAVLINK_MSG_ID_MOTOR_SPEED_MIN_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_CRC);
#else
    mavlink_motor_speed_t packet;
    packet.motor_speed_0 = motor_speed_0;
    packet.motor_speed_1 = motor_speed_1;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_SPEED, (const char *)&packet, MAVLINK_MSG_ID_MOTOR_SPEED_MIN_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_CRC);
#endif
}

/**
 * @brief Send a motor_speed message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_motor_speed_send_struct(mavlink_channel_t chan, const mavlink_motor_speed_t* motor_speed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_motor_speed_send(chan, motor_speed->motor_speed_0, motor_speed->motor_speed_1);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_SPEED, (const char *)motor_speed, MAVLINK_MSG_ID_MOTOR_SPEED_MIN_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_CRC);
#endif
}

#if MAVLINK_MSG_ID_MOTOR_SPEED_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_motor_speed_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t motor_speed_0, int16_t motor_speed_1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 0, motor_speed_0);
    _mav_put_int16_t(buf, 2, motor_speed_1);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_SPEED, buf, MAVLINK_MSG_ID_MOTOR_SPEED_MIN_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_CRC);
#else
    mavlink_motor_speed_t *packet = (mavlink_motor_speed_t *)msgbuf;
    packet->motor_speed_0 = motor_speed_0;
    packet->motor_speed_1 = motor_speed_1;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_SPEED, (const char *)packet, MAVLINK_MSG_ID_MOTOR_SPEED_MIN_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_LEN, MAVLINK_MSG_ID_MOTOR_SPEED_CRC);
#endif
}
#endif

#endif

// MESSAGE MOTOR_SPEED UNPACKING


/**
 * @brief Get field motor_speed_0 from motor_speed message
 *
 * @return  Motor 0 speed
 */
static inline int16_t mavlink_msg_motor_speed_get_motor_speed_0(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field motor_speed_1 from motor_speed message
 *
 * @return  Motor 1 Speed
 */
static inline int16_t mavlink_msg_motor_speed_get_motor_speed_1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Decode a motor_speed message into a struct
 *
 * @param msg The message to decode
 * @param motor_speed C-struct to decode the message contents into
 */
static inline void mavlink_msg_motor_speed_decode(const mavlink_message_t* msg, mavlink_motor_speed_t* motor_speed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    motor_speed->motor_speed_0 = mavlink_msg_motor_speed_get_motor_speed_0(msg);
    motor_speed->motor_speed_1 = mavlink_msg_motor_speed_get_motor_speed_1(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MOTOR_SPEED_LEN? msg->len : MAVLINK_MSG_ID_MOTOR_SPEED_LEN;
        memset(motor_speed, 0, MAVLINK_MSG_ID_MOTOR_SPEED_LEN);
    memcpy(motor_speed, _MAV_PAYLOAD(msg), len);
#endif
}
