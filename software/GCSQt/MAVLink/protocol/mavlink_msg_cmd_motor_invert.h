#pragma once
// MESSAGE CMD_MOTOR_INVERT PACKING

#define MAVLINK_MSG_ID_CMD_MOTOR_INVERT 7

MAVPACKED(
typedef struct __mavlink_cmd_motor_invert_t {
 int8_t motor_0_invert; /*<  Motor 0 Invert*/
 int8_t motor_1_invert; /*<  Motor 1 Invert*/
}) mavlink_cmd_motor_invert_t;

#define MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN 2
#define MAVLINK_MSG_ID_CMD_MOTOR_INVERT_MIN_LEN 2
#define MAVLINK_MSG_ID_7_LEN 2
#define MAVLINK_MSG_ID_7_MIN_LEN 2

#define MAVLINK_MSG_ID_CMD_MOTOR_INVERT_CRC 117
#define MAVLINK_MSG_ID_7_CRC 117



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CMD_MOTOR_INVERT { \
    7, \
    "CMD_MOTOR_INVERT", \
    2, \
    {  { "motor_0_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_cmd_motor_invert_t, motor_0_invert) }, \
         { "motor_1_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 1, offsetof(mavlink_cmd_motor_invert_t, motor_1_invert) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CMD_MOTOR_INVERT { \
    "CMD_MOTOR_INVERT", \
    2, \
    {  { "motor_0_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_cmd_motor_invert_t, motor_0_invert) }, \
         { "motor_1_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 1, offsetof(mavlink_cmd_motor_invert_t, motor_1_invert) }, \
         } \
}
#endif

/**
 * @brief Pack a cmd_motor_invert message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param motor_0_invert  Motor 0 Invert
 * @param motor_1_invert  Motor 1 Invert
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_motor_invert_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int8_t motor_0_invert, int8_t motor_1_invert)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN];
    _mav_put_int8_t(buf, 0, motor_0_invert);
    _mav_put_int8_t(buf, 1, motor_1_invert);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN);
#else
    mavlink_cmd_motor_invert_t packet;
    packet.motor_0_invert = motor_0_invert;
    packet.motor_1_invert = motor_1_invert;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_MOTOR_INVERT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_MIN_LEN, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_CRC);
}

/**
 * @brief Pack a cmd_motor_invert message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor_0_invert  Motor 0 Invert
 * @param motor_1_invert  Motor 1 Invert
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_motor_invert_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int8_t motor_0_invert,int8_t motor_1_invert)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN];
    _mav_put_int8_t(buf, 0, motor_0_invert);
    _mav_put_int8_t(buf, 1, motor_1_invert);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN);
#else
    mavlink_cmd_motor_invert_t packet;
    packet.motor_0_invert = motor_0_invert;
    packet.motor_1_invert = motor_1_invert;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_MOTOR_INVERT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_MIN_LEN, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_CRC);
}

/**
 * @brief Encode a cmd_motor_invert struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cmd_motor_invert C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_motor_invert_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cmd_motor_invert_t* cmd_motor_invert)
{
    return mavlink_msg_cmd_motor_invert_pack(system_id, component_id, msg, cmd_motor_invert->motor_0_invert, cmd_motor_invert->motor_1_invert);
}

/**
 * @brief Encode a cmd_motor_invert struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_motor_invert C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_motor_invert_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cmd_motor_invert_t* cmd_motor_invert)
{
    return mavlink_msg_cmd_motor_invert_pack_chan(system_id, component_id, chan, msg, cmd_motor_invert->motor_0_invert, cmd_motor_invert->motor_1_invert);
}

/**
 * @brief Send a cmd_motor_invert message
 * @param chan MAVLink channel to send the message
 *
 * @param motor_0_invert  Motor 0 Invert
 * @param motor_1_invert  Motor 1 Invert
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cmd_motor_invert_send(mavlink_channel_t chan, int8_t motor_0_invert, int8_t motor_1_invert)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN];
    _mav_put_int8_t(buf, 0, motor_0_invert);
    _mav_put_int8_t(buf, 1, motor_1_invert);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_MOTOR_INVERT, buf, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_MIN_LEN, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_CRC);
#else
    mavlink_cmd_motor_invert_t packet;
    packet.motor_0_invert = motor_0_invert;
    packet.motor_1_invert = motor_1_invert;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_MOTOR_INVERT, (const char *)&packet, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_MIN_LEN, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_CRC);
#endif
}

/**
 * @brief Send a cmd_motor_invert message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cmd_motor_invert_send_struct(mavlink_channel_t chan, const mavlink_cmd_motor_invert_t* cmd_motor_invert)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cmd_motor_invert_send(chan, cmd_motor_invert->motor_0_invert, cmd_motor_invert->motor_1_invert);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_MOTOR_INVERT, (const char *)cmd_motor_invert, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_MIN_LEN, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_CRC);
#endif
}

#if MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cmd_motor_invert_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int8_t motor_0_invert, int8_t motor_1_invert)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int8_t(buf, 0, motor_0_invert);
    _mav_put_int8_t(buf, 1, motor_1_invert);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_MOTOR_INVERT, buf, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_MIN_LEN, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_CRC);
#else
    mavlink_cmd_motor_invert_t *packet = (mavlink_cmd_motor_invert_t *)msgbuf;
    packet->motor_0_invert = motor_0_invert;
    packet->motor_1_invert = motor_1_invert;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_MOTOR_INVERT, (const char *)packet, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_MIN_LEN, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_CRC);
#endif
}
#endif

#endif

// MESSAGE CMD_MOTOR_INVERT UNPACKING


/**
 * @brief Get field motor_0_invert from cmd_motor_invert message
 *
 * @return  Motor 0 Invert
 */
static inline int8_t mavlink_msg_cmd_motor_invert_get_motor_0_invert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  0);
}

/**
 * @brief Get field motor_1_invert from cmd_motor_invert message
 *
 * @return  Motor 1 Invert
 */
static inline int8_t mavlink_msg_cmd_motor_invert_get_motor_1_invert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  1);
}

/**
 * @brief Decode a cmd_motor_invert message into a struct
 *
 * @param msg The message to decode
 * @param cmd_motor_invert C-struct to decode the message contents into
 */
static inline void mavlink_msg_cmd_motor_invert_decode(const mavlink_message_t* msg, mavlink_cmd_motor_invert_t* cmd_motor_invert)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cmd_motor_invert->motor_0_invert = mavlink_msg_cmd_motor_invert_get_motor_0_invert(msg);
    cmd_motor_invert->motor_1_invert = mavlink_msg_cmd_motor_invert_get_motor_1_invert(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN? msg->len : MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN;
        memset(cmd_motor_invert, 0, MAVLINK_MSG_ID_CMD_MOTOR_INVERT_LEN);
    memcpy(cmd_motor_invert, _MAV_PAYLOAD(msg), len);
#endif
}
