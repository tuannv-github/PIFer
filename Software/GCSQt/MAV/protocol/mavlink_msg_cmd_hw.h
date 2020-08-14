#pragma once
// MESSAGE CMD_HW PACKING

#define MAVLINK_MSG_ID_CMD_HW 7

MAVPACKED(
typedef struct __mavlink_cmd_hw_t {
 int8_t motor0_invert; /*<  Motor 0 Invert*/
 int8_t motor1_invert; /*<  Motor 1 Invert*/
 int8_t encoder0_invert; /*<  Encoder 0 Invert*/
 int8_t encoder1_invert; /*<  Encoder 1 Invert*/
 int8_t encoder_exchange; /*<  Switch to invert encoder from motor 0 to motor 1 and vice versa*/
}) mavlink_cmd_hw_t;

#define MAVLINK_MSG_ID_CMD_HW_LEN 5
#define MAVLINK_MSG_ID_CMD_HW_MIN_LEN 5
#define MAVLINK_MSG_ID_7_LEN 5
#define MAVLINK_MSG_ID_7_MIN_LEN 5

#define MAVLINK_MSG_ID_CMD_HW_CRC 224
#define MAVLINK_MSG_ID_7_CRC 224



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CMD_HW { \
    7, \
    "CMD_HW", \
    5, \
    {  { "motor0_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_cmd_hw_t, motor0_invert) }, \
         { "motor1_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 1, offsetof(mavlink_cmd_hw_t, motor1_invert) }, \
         { "encoder0_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 2, offsetof(mavlink_cmd_hw_t, encoder0_invert) }, \
         { "encoder1_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 3, offsetof(mavlink_cmd_hw_t, encoder1_invert) }, \
         { "encoder_exchange", NULL, MAVLINK_TYPE_INT8_T, 0, 4, offsetof(mavlink_cmd_hw_t, encoder_exchange) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CMD_HW { \
    "CMD_HW", \
    5, \
    {  { "motor0_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_cmd_hw_t, motor0_invert) }, \
         { "motor1_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 1, offsetof(mavlink_cmd_hw_t, motor1_invert) }, \
         { "encoder0_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 2, offsetof(mavlink_cmd_hw_t, encoder0_invert) }, \
         { "encoder1_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 3, offsetof(mavlink_cmd_hw_t, encoder1_invert) }, \
         { "encoder_exchange", NULL, MAVLINK_TYPE_INT8_T, 0, 4, offsetof(mavlink_cmd_hw_t, encoder_exchange) }, \
         } \
}
#endif

/**
 * @brief Pack a cmd_hw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param motor0_invert  Motor 0 Invert
 * @param motor1_invert  Motor 1 Invert
 * @param encoder0_invert  Encoder 0 Invert
 * @param encoder1_invert  Encoder 1 Invert
 * @param encoder_exchange  Switch to invert encoder from motor 0 to motor 1 and vice versa
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_hw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int8_t motor0_invert, int8_t motor1_invert, int8_t encoder0_invert, int8_t encoder1_invert, int8_t encoder_exchange)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_HW_LEN];
    _mav_put_int8_t(buf, 0, motor0_invert);
    _mav_put_int8_t(buf, 1, motor1_invert);
    _mav_put_int8_t(buf, 2, encoder0_invert);
    _mav_put_int8_t(buf, 3, encoder1_invert);
    _mav_put_int8_t(buf, 4, encoder_exchange);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_HW_LEN);
#else
    mavlink_cmd_hw_t packet;
    packet.motor0_invert = motor0_invert;
    packet.motor1_invert = motor1_invert;
    packet.encoder0_invert = encoder0_invert;
    packet.encoder1_invert = encoder1_invert;
    packet.encoder_exchange = encoder_exchange;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_HW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_HW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CMD_HW_MIN_LEN, MAVLINK_MSG_ID_CMD_HW_LEN, MAVLINK_MSG_ID_CMD_HW_CRC);
}

/**
 * @brief Pack a cmd_hw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor0_invert  Motor 0 Invert
 * @param motor1_invert  Motor 1 Invert
 * @param encoder0_invert  Encoder 0 Invert
 * @param encoder1_invert  Encoder 1 Invert
 * @param encoder_exchange  Switch to invert encoder from motor 0 to motor 1 and vice versa
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_hw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int8_t motor0_invert,int8_t motor1_invert,int8_t encoder0_invert,int8_t encoder1_invert,int8_t encoder_exchange)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_HW_LEN];
    _mav_put_int8_t(buf, 0, motor0_invert);
    _mav_put_int8_t(buf, 1, motor1_invert);
    _mav_put_int8_t(buf, 2, encoder0_invert);
    _mav_put_int8_t(buf, 3, encoder1_invert);
    _mav_put_int8_t(buf, 4, encoder_exchange);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_HW_LEN);
#else
    mavlink_cmd_hw_t packet;
    packet.motor0_invert = motor0_invert;
    packet.motor1_invert = motor1_invert;
    packet.encoder0_invert = encoder0_invert;
    packet.encoder1_invert = encoder1_invert;
    packet.encoder_exchange = encoder_exchange;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_HW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_HW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CMD_HW_MIN_LEN, MAVLINK_MSG_ID_CMD_HW_LEN, MAVLINK_MSG_ID_CMD_HW_CRC);
}

/**
 * @brief Encode a cmd_hw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cmd_hw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_hw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cmd_hw_t* cmd_hw)
{
    return mavlink_msg_cmd_hw_pack(system_id, component_id, msg, cmd_hw->motor0_invert, cmd_hw->motor1_invert, cmd_hw->encoder0_invert, cmd_hw->encoder1_invert, cmd_hw->encoder_exchange);
}

/**
 * @brief Encode a cmd_hw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_hw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_hw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cmd_hw_t* cmd_hw)
{
    return mavlink_msg_cmd_hw_pack_chan(system_id, component_id, chan, msg, cmd_hw->motor0_invert, cmd_hw->motor1_invert, cmd_hw->encoder0_invert, cmd_hw->encoder1_invert, cmd_hw->encoder_exchange);
}

/**
 * @brief Send a cmd_hw message
 * @param chan MAVLink channel to send the message
 *
 * @param motor0_invert  Motor 0 Invert
 * @param motor1_invert  Motor 1 Invert
 * @param encoder0_invert  Encoder 0 Invert
 * @param encoder1_invert  Encoder 1 Invert
 * @param encoder_exchange  Switch to invert encoder from motor 0 to motor 1 and vice versa
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cmd_hw_send(mavlink_channel_t chan, int8_t motor0_invert, int8_t motor1_invert, int8_t encoder0_invert, int8_t encoder1_invert, int8_t encoder_exchange)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_HW_LEN];
    _mav_put_int8_t(buf, 0, motor0_invert);
    _mav_put_int8_t(buf, 1, motor1_invert);
    _mav_put_int8_t(buf, 2, encoder0_invert);
    _mav_put_int8_t(buf, 3, encoder1_invert);
    _mav_put_int8_t(buf, 4, encoder_exchange);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_HW, buf, MAVLINK_MSG_ID_CMD_HW_MIN_LEN, MAVLINK_MSG_ID_CMD_HW_LEN, MAVLINK_MSG_ID_CMD_HW_CRC);
#else
    mavlink_cmd_hw_t packet;
    packet.motor0_invert = motor0_invert;
    packet.motor1_invert = motor1_invert;
    packet.encoder0_invert = encoder0_invert;
    packet.encoder1_invert = encoder1_invert;
    packet.encoder_exchange = encoder_exchange;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_HW, (const char *)&packet, MAVLINK_MSG_ID_CMD_HW_MIN_LEN, MAVLINK_MSG_ID_CMD_HW_LEN, MAVLINK_MSG_ID_CMD_HW_CRC);
#endif
}

/**
 * @brief Send a cmd_hw message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cmd_hw_send_struct(mavlink_channel_t chan, const mavlink_cmd_hw_t* cmd_hw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cmd_hw_send(chan, cmd_hw->motor0_invert, cmd_hw->motor1_invert, cmd_hw->encoder0_invert, cmd_hw->encoder1_invert, cmd_hw->encoder_exchange);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_HW, (const char *)cmd_hw, MAVLINK_MSG_ID_CMD_HW_MIN_LEN, MAVLINK_MSG_ID_CMD_HW_LEN, MAVLINK_MSG_ID_CMD_HW_CRC);
#endif
}

#if MAVLINK_MSG_ID_CMD_HW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cmd_hw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int8_t motor0_invert, int8_t motor1_invert, int8_t encoder0_invert, int8_t encoder1_invert, int8_t encoder_exchange)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int8_t(buf, 0, motor0_invert);
    _mav_put_int8_t(buf, 1, motor1_invert);
    _mav_put_int8_t(buf, 2, encoder0_invert);
    _mav_put_int8_t(buf, 3, encoder1_invert);
    _mav_put_int8_t(buf, 4, encoder_exchange);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_HW, buf, MAVLINK_MSG_ID_CMD_HW_MIN_LEN, MAVLINK_MSG_ID_CMD_HW_LEN, MAVLINK_MSG_ID_CMD_HW_CRC);
#else
    mavlink_cmd_hw_t *packet = (mavlink_cmd_hw_t *)msgbuf;
    packet->motor0_invert = motor0_invert;
    packet->motor1_invert = motor1_invert;
    packet->encoder0_invert = encoder0_invert;
    packet->encoder1_invert = encoder1_invert;
    packet->encoder_exchange = encoder_exchange;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_HW, (const char *)packet, MAVLINK_MSG_ID_CMD_HW_MIN_LEN, MAVLINK_MSG_ID_CMD_HW_LEN, MAVLINK_MSG_ID_CMD_HW_CRC);
#endif
}
#endif

#endif

// MESSAGE CMD_HW UNPACKING


/**
 * @brief Get field motor0_invert from cmd_hw message
 *
 * @return  Motor 0 Invert
 */
static inline int8_t mavlink_msg_cmd_hw_get_motor0_invert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  0);
}

/**
 * @brief Get field motor1_invert from cmd_hw message
 *
 * @return  Motor 1 Invert
 */
static inline int8_t mavlink_msg_cmd_hw_get_motor1_invert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  1);
}

/**
 * @brief Get field encoder0_invert from cmd_hw message
 *
 * @return  Encoder 0 Invert
 */
static inline int8_t mavlink_msg_cmd_hw_get_encoder0_invert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  2);
}

/**
 * @brief Get field encoder1_invert from cmd_hw message
 *
 * @return  Encoder 1 Invert
 */
static inline int8_t mavlink_msg_cmd_hw_get_encoder1_invert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  3);
}

/**
 * @brief Get field encoder_exchange from cmd_hw message
 *
 * @return  Switch to invert encoder from motor 0 to motor 1 and vice versa
 */
static inline int8_t mavlink_msg_cmd_hw_get_encoder_exchange(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  4);
}

/**
 * @brief Decode a cmd_hw message into a struct
 *
 * @param msg The message to decode
 * @param cmd_hw C-struct to decode the message contents into
 */
static inline void mavlink_msg_cmd_hw_decode(const mavlink_message_t* msg, mavlink_cmd_hw_t* cmd_hw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cmd_hw->motor0_invert = mavlink_msg_cmd_hw_get_motor0_invert(msg);
    cmd_hw->motor1_invert = mavlink_msg_cmd_hw_get_motor1_invert(msg);
    cmd_hw->encoder0_invert = mavlink_msg_cmd_hw_get_encoder0_invert(msg);
    cmd_hw->encoder1_invert = mavlink_msg_cmd_hw_get_encoder1_invert(msg);
    cmd_hw->encoder_exchange = mavlink_msg_cmd_hw_get_encoder_exchange(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CMD_HW_LEN? msg->len : MAVLINK_MSG_ID_CMD_HW_LEN;
        memset(cmd_hw, 0, MAVLINK_MSG_ID_CMD_HW_LEN);
    memcpy(cmd_hw, _MAV_PAYLOAD(msg), len);
#endif
}
