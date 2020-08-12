#pragma once
// MESSAGE HW_PARAMS PACKING

#define MAVLINK_MSG_ID_HW_PARAMS 8

MAVPACKED(
typedef struct __mavlink_hw_params_t {
 int8_t motor0_invert; /*<  Motor 0 Invert*/
 int8_t motor1_invert; /*<  Motor 1 Invert*/
 int8_t encoder0_invert; /*<  Encoder 0 Invert*/
 int8_t encoder1_invert; /*<  Encoder 1 Invert*/
 int8_t encoder_exchange; /*<  Switch to invert encoder from motor 0 to motor 1 and vice versa*/
}) mavlink_hw_params_t;

#define MAVLINK_MSG_ID_HW_PARAMS_LEN 5
#define MAVLINK_MSG_ID_HW_PARAMS_MIN_LEN 5
#define MAVLINK_MSG_ID_8_LEN 5
#define MAVLINK_MSG_ID_8_MIN_LEN 5

#define MAVLINK_MSG_ID_HW_PARAMS_CRC 213
#define MAVLINK_MSG_ID_8_CRC 213



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HW_PARAMS { \
    8, \
    "HW_PARAMS", \
    5, \
    {  { "motor0_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_hw_params_t, motor0_invert) }, \
         { "motor1_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 1, offsetof(mavlink_hw_params_t, motor1_invert) }, \
         { "encoder0_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 2, offsetof(mavlink_hw_params_t, encoder0_invert) }, \
         { "encoder1_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 3, offsetof(mavlink_hw_params_t, encoder1_invert) }, \
         { "encoder_exchange", NULL, MAVLINK_TYPE_INT8_T, 0, 4, offsetof(mavlink_hw_params_t, encoder_exchange) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HW_PARAMS { \
    "HW_PARAMS", \
    5, \
    {  { "motor0_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_hw_params_t, motor0_invert) }, \
         { "motor1_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 1, offsetof(mavlink_hw_params_t, motor1_invert) }, \
         { "encoder0_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 2, offsetof(mavlink_hw_params_t, encoder0_invert) }, \
         { "encoder1_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 3, offsetof(mavlink_hw_params_t, encoder1_invert) }, \
         { "encoder_exchange", NULL, MAVLINK_TYPE_INT8_T, 0, 4, offsetof(mavlink_hw_params_t, encoder_exchange) }, \
         } \
}
#endif

/**
 * @brief Pack a hw_params message
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
static inline uint16_t mavlink_msg_hw_params_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int8_t motor0_invert, int8_t motor1_invert, int8_t encoder0_invert, int8_t encoder1_invert, int8_t encoder_exchange)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HW_PARAMS_LEN];
    _mav_put_int8_t(buf, 0, motor0_invert);
    _mav_put_int8_t(buf, 1, motor1_invert);
    _mav_put_int8_t(buf, 2, encoder0_invert);
    _mav_put_int8_t(buf, 3, encoder1_invert);
    _mav_put_int8_t(buf, 4, encoder_exchange);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HW_PARAMS_LEN);
#else
    mavlink_hw_params_t packet;
    packet.motor0_invert = motor0_invert;
    packet.motor1_invert = motor1_invert;
    packet.encoder0_invert = encoder0_invert;
    packet.encoder1_invert = encoder1_invert;
    packet.encoder_exchange = encoder_exchange;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HW_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HW_PARAMS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HW_PARAMS_MIN_LEN, MAVLINK_MSG_ID_HW_PARAMS_LEN, MAVLINK_MSG_ID_HW_PARAMS_CRC);
}

/**
 * @brief Pack a hw_params message on a channel
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
static inline uint16_t mavlink_msg_hw_params_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int8_t motor0_invert,int8_t motor1_invert,int8_t encoder0_invert,int8_t encoder1_invert,int8_t encoder_exchange)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HW_PARAMS_LEN];
    _mav_put_int8_t(buf, 0, motor0_invert);
    _mav_put_int8_t(buf, 1, motor1_invert);
    _mav_put_int8_t(buf, 2, encoder0_invert);
    _mav_put_int8_t(buf, 3, encoder1_invert);
    _mav_put_int8_t(buf, 4, encoder_exchange);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HW_PARAMS_LEN);
#else
    mavlink_hw_params_t packet;
    packet.motor0_invert = motor0_invert;
    packet.motor1_invert = motor1_invert;
    packet.encoder0_invert = encoder0_invert;
    packet.encoder1_invert = encoder1_invert;
    packet.encoder_exchange = encoder_exchange;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HW_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HW_PARAMS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HW_PARAMS_MIN_LEN, MAVLINK_MSG_ID_HW_PARAMS_LEN, MAVLINK_MSG_ID_HW_PARAMS_CRC);
}

/**
 * @brief Encode a hw_params struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param hw_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hw_params_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_hw_params_t* hw_params)
{
    return mavlink_msg_hw_params_pack(system_id, component_id, msg, hw_params->motor0_invert, hw_params->motor1_invert, hw_params->encoder0_invert, hw_params->encoder1_invert, hw_params->encoder_exchange);
}

/**
 * @brief Encode a hw_params struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hw_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hw_params_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_hw_params_t* hw_params)
{
    return mavlink_msg_hw_params_pack_chan(system_id, component_id, chan, msg, hw_params->motor0_invert, hw_params->motor1_invert, hw_params->encoder0_invert, hw_params->encoder1_invert, hw_params->encoder_exchange);
}

/**
 * @brief Send a hw_params message
 * @param chan MAVLink channel to send the message
 *
 * @param motor0_invert  Motor 0 Invert
 * @param motor1_invert  Motor 1 Invert
 * @param encoder0_invert  Encoder 0 Invert
 * @param encoder1_invert  Encoder 1 Invert
 * @param encoder_exchange  Switch to invert encoder from motor 0 to motor 1 and vice versa
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_hw_params_send(mavlink_channel_t chan, int8_t motor0_invert, int8_t motor1_invert, int8_t encoder0_invert, int8_t encoder1_invert, int8_t encoder_exchange)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HW_PARAMS_LEN];
    _mav_put_int8_t(buf, 0, motor0_invert);
    _mav_put_int8_t(buf, 1, motor1_invert);
    _mav_put_int8_t(buf, 2, encoder0_invert);
    _mav_put_int8_t(buf, 3, encoder1_invert);
    _mav_put_int8_t(buf, 4, encoder_exchange);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HW_PARAMS, buf, MAVLINK_MSG_ID_HW_PARAMS_MIN_LEN, MAVLINK_MSG_ID_HW_PARAMS_LEN, MAVLINK_MSG_ID_HW_PARAMS_CRC);
#else
    mavlink_hw_params_t packet;
    packet.motor0_invert = motor0_invert;
    packet.motor1_invert = motor1_invert;
    packet.encoder0_invert = encoder0_invert;
    packet.encoder1_invert = encoder1_invert;
    packet.encoder_exchange = encoder_exchange;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HW_PARAMS, (const char *)&packet, MAVLINK_MSG_ID_HW_PARAMS_MIN_LEN, MAVLINK_MSG_ID_HW_PARAMS_LEN, MAVLINK_MSG_ID_HW_PARAMS_CRC);
#endif
}

/**
 * @brief Send a hw_params message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_hw_params_send_struct(mavlink_channel_t chan, const mavlink_hw_params_t* hw_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_hw_params_send(chan, hw_params->motor0_invert, hw_params->motor1_invert, hw_params->encoder0_invert, hw_params->encoder1_invert, hw_params->encoder_exchange);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HW_PARAMS, (const char *)hw_params, MAVLINK_MSG_ID_HW_PARAMS_MIN_LEN, MAVLINK_MSG_ID_HW_PARAMS_LEN, MAVLINK_MSG_ID_HW_PARAMS_CRC);
#endif
}

#if MAVLINK_MSG_ID_HW_PARAMS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_hw_params_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int8_t motor0_invert, int8_t motor1_invert, int8_t encoder0_invert, int8_t encoder1_invert, int8_t encoder_exchange)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int8_t(buf, 0, motor0_invert);
    _mav_put_int8_t(buf, 1, motor1_invert);
    _mav_put_int8_t(buf, 2, encoder0_invert);
    _mav_put_int8_t(buf, 3, encoder1_invert);
    _mav_put_int8_t(buf, 4, encoder_exchange);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HW_PARAMS, buf, MAVLINK_MSG_ID_HW_PARAMS_MIN_LEN, MAVLINK_MSG_ID_HW_PARAMS_LEN, MAVLINK_MSG_ID_HW_PARAMS_CRC);
#else
    mavlink_hw_params_t *packet = (mavlink_hw_params_t *)msgbuf;
    packet->motor0_invert = motor0_invert;
    packet->motor1_invert = motor1_invert;
    packet->encoder0_invert = encoder0_invert;
    packet->encoder1_invert = encoder1_invert;
    packet->encoder_exchange = encoder_exchange;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HW_PARAMS, (const char *)packet, MAVLINK_MSG_ID_HW_PARAMS_MIN_LEN, MAVLINK_MSG_ID_HW_PARAMS_LEN, MAVLINK_MSG_ID_HW_PARAMS_CRC);
#endif
}
#endif

#endif

// MESSAGE HW_PARAMS UNPACKING


/**
 * @brief Get field motor0_invert from hw_params message
 *
 * @return  Motor 0 Invert
 */
static inline int8_t mavlink_msg_hw_params_get_motor0_invert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  0);
}

/**
 * @brief Get field motor1_invert from hw_params message
 *
 * @return  Motor 1 Invert
 */
static inline int8_t mavlink_msg_hw_params_get_motor1_invert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  1);
}

/**
 * @brief Get field encoder0_invert from hw_params message
 *
 * @return  Encoder 0 Invert
 */
static inline int8_t mavlink_msg_hw_params_get_encoder0_invert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  2);
}

/**
 * @brief Get field encoder1_invert from hw_params message
 *
 * @return  Encoder 1 Invert
 */
static inline int8_t mavlink_msg_hw_params_get_encoder1_invert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  3);
}

/**
 * @brief Get field encoder_exchange from hw_params message
 *
 * @return  Switch to invert encoder from motor 0 to motor 1 and vice versa
 */
static inline int8_t mavlink_msg_hw_params_get_encoder_exchange(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  4);
}

/**
 * @brief Decode a hw_params message into a struct
 *
 * @param msg The message to decode
 * @param hw_params C-struct to decode the message contents into
 */
static inline void mavlink_msg_hw_params_decode(const mavlink_message_t* msg, mavlink_hw_params_t* hw_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    hw_params->motor0_invert = mavlink_msg_hw_params_get_motor0_invert(msg);
    hw_params->motor1_invert = mavlink_msg_hw_params_get_motor1_invert(msg);
    hw_params->encoder0_invert = mavlink_msg_hw_params_get_encoder0_invert(msg);
    hw_params->encoder1_invert = mavlink_msg_hw_params_get_encoder1_invert(msg);
    hw_params->encoder_exchange = mavlink_msg_hw_params_get_encoder_exchange(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_HW_PARAMS_LEN? msg->len : MAVLINK_MSG_ID_HW_PARAMS_LEN;
        memset(hw_params, 0, MAVLINK_MSG_ID_HW_PARAMS_LEN);
    memcpy(hw_params, _MAV_PAYLOAD(msg), len);
#endif
}
