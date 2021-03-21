#pragma once
// MESSAGE HW_PARAMS PACKING

#define MAVLINK_MSG_ID_HW_PARAMS 9


typedef struct __mavlink_hw_params_t {
 int16_t motor0_pos_deadband; /*<  Motor 0 positive deadband*/
 int16_t motor0_neg_deadband; /*<  Motor 0 negative deadband*/
 int16_t motor1_pos_deadband; /*<  Motor 1 positive deadband*/
 int16_t motor1_neg_deadband; /*<  Motor 1 negative deadband*/
 int8_t motor_type; /*<  */
 int8_t motor0_invert; /*<  Motor 0 Invert*/
 int8_t motor1_invert; /*<  Motor 1 Invert*/
 int8_t encoder0_invert; /*<  Encoder 0 Invert*/
 int8_t encoder1_invert; /*<  Encoder 1 Invert*/
 int8_t encoder_exchange; /*<  Switch to invert encoder from motor 0 to motor 1 and vice versa*/
} mavlink_hw_params_t;

#define MAVLINK_MSG_ID_HW_PARAMS_LEN 14
#define MAVLINK_MSG_ID_HW_PARAMS_MIN_LEN 14
#define MAVLINK_MSG_ID_9_LEN 14
#define MAVLINK_MSG_ID_9_MIN_LEN 14

#define MAVLINK_MSG_ID_HW_PARAMS_CRC 30
#define MAVLINK_MSG_ID_9_CRC 30



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HW_PARAMS { \
    9, \
    "HW_PARAMS", \
    10, \
    {  { "motor_type", NULL, MAVLINK_TYPE_INT8_T, 0, 8, offsetof(mavlink_hw_params_t, motor_type) }, \
         { "motor0_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 9, offsetof(mavlink_hw_params_t, motor0_invert) }, \
         { "motor1_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 10, offsetof(mavlink_hw_params_t, motor1_invert) }, \
         { "encoder0_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 11, offsetof(mavlink_hw_params_t, encoder0_invert) }, \
         { "encoder1_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 12, offsetof(mavlink_hw_params_t, encoder1_invert) }, \
         { "encoder_exchange", NULL, MAVLINK_TYPE_INT8_T, 0, 13, offsetof(mavlink_hw_params_t, encoder_exchange) }, \
         { "motor0_pos_deadband", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_hw_params_t, motor0_pos_deadband) }, \
         { "motor0_neg_deadband", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_hw_params_t, motor0_neg_deadband) }, \
         { "motor1_pos_deadband", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_hw_params_t, motor1_pos_deadband) }, \
         { "motor1_neg_deadband", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_hw_params_t, motor1_neg_deadband) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HW_PARAMS { \
    "HW_PARAMS", \
    10, \
    {  { "motor_type", NULL, MAVLINK_TYPE_INT8_T, 0, 8, offsetof(mavlink_hw_params_t, motor_type) }, \
         { "motor0_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 9, offsetof(mavlink_hw_params_t, motor0_invert) }, \
         { "motor1_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 10, offsetof(mavlink_hw_params_t, motor1_invert) }, \
         { "encoder0_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 11, offsetof(mavlink_hw_params_t, encoder0_invert) }, \
         { "encoder1_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 12, offsetof(mavlink_hw_params_t, encoder1_invert) }, \
         { "encoder_exchange", NULL, MAVLINK_TYPE_INT8_T, 0, 13, offsetof(mavlink_hw_params_t, encoder_exchange) }, \
         { "motor0_pos_deadband", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_hw_params_t, motor0_pos_deadband) }, \
         { "motor0_neg_deadband", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_hw_params_t, motor0_neg_deadband) }, \
         { "motor1_pos_deadband", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_hw_params_t, motor1_pos_deadband) }, \
         { "motor1_neg_deadband", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_hw_params_t, motor1_neg_deadband) }, \
         } \
}
#endif

/**
 * @brief Pack a hw_params message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param motor_type  
 * @param motor0_invert  Motor 0 Invert
 * @param motor1_invert  Motor 1 Invert
 * @param encoder0_invert  Encoder 0 Invert
 * @param encoder1_invert  Encoder 1 Invert
 * @param encoder_exchange  Switch to invert encoder from motor 0 to motor 1 and vice versa
 * @param motor0_pos_deadband  Motor 0 positive deadband
 * @param motor0_neg_deadband  Motor 0 negative deadband
 * @param motor1_pos_deadband  Motor 1 positive deadband
 * @param motor1_neg_deadband  Motor 1 negative deadband
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hw_params_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int8_t motor_type, int8_t motor0_invert, int8_t motor1_invert, int8_t encoder0_invert, int8_t encoder1_invert, int8_t encoder_exchange, int16_t motor0_pos_deadband, int16_t motor0_neg_deadband, int16_t motor1_pos_deadband, int16_t motor1_neg_deadband)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HW_PARAMS_LEN];
    _mav_put_int16_t(buf, 0, motor0_pos_deadband);
    _mav_put_int16_t(buf, 2, motor0_neg_deadband);
    _mav_put_int16_t(buf, 4, motor1_pos_deadband);
    _mav_put_int16_t(buf, 6, motor1_neg_deadband);
    _mav_put_int8_t(buf, 8, motor_type);
    _mav_put_int8_t(buf, 9, motor0_invert);
    _mav_put_int8_t(buf, 10, motor1_invert);
    _mav_put_int8_t(buf, 11, encoder0_invert);
    _mav_put_int8_t(buf, 12, encoder1_invert);
    _mav_put_int8_t(buf, 13, encoder_exchange);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HW_PARAMS_LEN);
#else
    mavlink_hw_params_t packet;
    packet.motor0_pos_deadband = motor0_pos_deadband;
    packet.motor0_neg_deadband = motor0_neg_deadband;
    packet.motor1_pos_deadband = motor1_pos_deadband;
    packet.motor1_neg_deadband = motor1_neg_deadband;
    packet.motor_type = motor_type;
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
 * @param motor_type  
 * @param motor0_invert  Motor 0 Invert
 * @param motor1_invert  Motor 1 Invert
 * @param encoder0_invert  Encoder 0 Invert
 * @param encoder1_invert  Encoder 1 Invert
 * @param encoder_exchange  Switch to invert encoder from motor 0 to motor 1 and vice versa
 * @param motor0_pos_deadband  Motor 0 positive deadband
 * @param motor0_neg_deadband  Motor 0 negative deadband
 * @param motor1_pos_deadband  Motor 1 positive deadband
 * @param motor1_neg_deadband  Motor 1 negative deadband
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hw_params_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int8_t motor_type,int8_t motor0_invert,int8_t motor1_invert,int8_t encoder0_invert,int8_t encoder1_invert,int8_t encoder_exchange,int16_t motor0_pos_deadband,int16_t motor0_neg_deadband,int16_t motor1_pos_deadband,int16_t motor1_neg_deadband)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HW_PARAMS_LEN];
    _mav_put_int16_t(buf, 0, motor0_pos_deadband);
    _mav_put_int16_t(buf, 2, motor0_neg_deadband);
    _mav_put_int16_t(buf, 4, motor1_pos_deadband);
    _mav_put_int16_t(buf, 6, motor1_neg_deadband);
    _mav_put_int8_t(buf, 8, motor_type);
    _mav_put_int8_t(buf, 9, motor0_invert);
    _mav_put_int8_t(buf, 10, motor1_invert);
    _mav_put_int8_t(buf, 11, encoder0_invert);
    _mav_put_int8_t(buf, 12, encoder1_invert);
    _mav_put_int8_t(buf, 13, encoder_exchange);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HW_PARAMS_LEN);
#else
    mavlink_hw_params_t packet;
    packet.motor0_pos_deadband = motor0_pos_deadband;
    packet.motor0_neg_deadband = motor0_neg_deadband;
    packet.motor1_pos_deadband = motor1_pos_deadband;
    packet.motor1_neg_deadband = motor1_neg_deadband;
    packet.motor_type = motor_type;
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
    return mavlink_msg_hw_params_pack(system_id, component_id, msg, hw_params->motor_type, hw_params->motor0_invert, hw_params->motor1_invert, hw_params->encoder0_invert, hw_params->encoder1_invert, hw_params->encoder_exchange, hw_params->motor0_pos_deadband, hw_params->motor0_neg_deadband, hw_params->motor1_pos_deadband, hw_params->motor1_neg_deadband);
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
    return mavlink_msg_hw_params_pack_chan(system_id, component_id, chan, msg, hw_params->motor_type, hw_params->motor0_invert, hw_params->motor1_invert, hw_params->encoder0_invert, hw_params->encoder1_invert, hw_params->encoder_exchange, hw_params->motor0_pos_deadband, hw_params->motor0_neg_deadband, hw_params->motor1_pos_deadband, hw_params->motor1_neg_deadband);
}

/**
 * @brief Send a hw_params message
 * @param chan MAVLink channel to send the message
 *
 * @param motor_type  
 * @param motor0_invert  Motor 0 Invert
 * @param motor1_invert  Motor 1 Invert
 * @param encoder0_invert  Encoder 0 Invert
 * @param encoder1_invert  Encoder 1 Invert
 * @param encoder_exchange  Switch to invert encoder from motor 0 to motor 1 and vice versa
 * @param motor0_pos_deadband  Motor 0 positive deadband
 * @param motor0_neg_deadband  Motor 0 negative deadband
 * @param motor1_pos_deadband  Motor 1 positive deadband
 * @param motor1_neg_deadband  Motor 1 negative deadband
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_hw_params_send(mavlink_channel_t chan, int8_t motor_type, int8_t motor0_invert, int8_t motor1_invert, int8_t encoder0_invert, int8_t encoder1_invert, int8_t encoder_exchange, int16_t motor0_pos_deadband, int16_t motor0_neg_deadband, int16_t motor1_pos_deadband, int16_t motor1_neg_deadband)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HW_PARAMS_LEN];
    _mav_put_int16_t(buf, 0, motor0_pos_deadband);
    _mav_put_int16_t(buf, 2, motor0_neg_deadband);
    _mav_put_int16_t(buf, 4, motor1_pos_deadband);
    _mav_put_int16_t(buf, 6, motor1_neg_deadband);
    _mav_put_int8_t(buf, 8, motor_type);
    _mav_put_int8_t(buf, 9, motor0_invert);
    _mav_put_int8_t(buf, 10, motor1_invert);
    _mav_put_int8_t(buf, 11, encoder0_invert);
    _mav_put_int8_t(buf, 12, encoder1_invert);
    _mav_put_int8_t(buf, 13, encoder_exchange);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HW_PARAMS, buf, MAVLINK_MSG_ID_HW_PARAMS_MIN_LEN, MAVLINK_MSG_ID_HW_PARAMS_LEN, MAVLINK_MSG_ID_HW_PARAMS_CRC);
#else
    mavlink_hw_params_t packet;
    packet.motor0_pos_deadband = motor0_pos_deadband;
    packet.motor0_neg_deadband = motor0_neg_deadband;
    packet.motor1_pos_deadband = motor1_pos_deadband;
    packet.motor1_neg_deadband = motor1_neg_deadband;
    packet.motor_type = motor_type;
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
    mavlink_msg_hw_params_send(chan, hw_params->motor_type, hw_params->motor0_invert, hw_params->motor1_invert, hw_params->encoder0_invert, hw_params->encoder1_invert, hw_params->encoder_exchange, hw_params->motor0_pos_deadband, hw_params->motor0_neg_deadband, hw_params->motor1_pos_deadband, hw_params->motor1_neg_deadband);
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
static inline void mavlink_msg_hw_params_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int8_t motor_type, int8_t motor0_invert, int8_t motor1_invert, int8_t encoder0_invert, int8_t encoder1_invert, int8_t encoder_exchange, int16_t motor0_pos_deadband, int16_t motor0_neg_deadband, int16_t motor1_pos_deadband, int16_t motor1_neg_deadband)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 0, motor0_pos_deadband);
    _mav_put_int16_t(buf, 2, motor0_neg_deadband);
    _mav_put_int16_t(buf, 4, motor1_pos_deadband);
    _mav_put_int16_t(buf, 6, motor1_neg_deadband);
    _mav_put_int8_t(buf, 8, motor_type);
    _mav_put_int8_t(buf, 9, motor0_invert);
    _mav_put_int8_t(buf, 10, motor1_invert);
    _mav_put_int8_t(buf, 11, encoder0_invert);
    _mav_put_int8_t(buf, 12, encoder1_invert);
    _mav_put_int8_t(buf, 13, encoder_exchange);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HW_PARAMS, buf, MAVLINK_MSG_ID_HW_PARAMS_MIN_LEN, MAVLINK_MSG_ID_HW_PARAMS_LEN, MAVLINK_MSG_ID_HW_PARAMS_CRC);
#else
    mavlink_hw_params_t *packet = (mavlink_hw_params_t *)msgbuf;
    packet->motor0_pos_deadband = motor0_pos_deadband;
    packet->motor0_neg_deadband = motor0_neg_deadband;
    packet->motor1_pos_deadband = motor1_pos_deadband;
    packet->motor1_neg_deadband = motor1_neg_deadband;
    packet->motor_type = motor_type;
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
 * @brief Get field motor_type from hw_params message
 *
 * @return  
 */
static inline int8_t mavlink_msg_hw_params_get_motor_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  8);
}

/**
 * @brief Get field motor0_invert from hw_params message
 *
 * @return  Motor 0 Invert
 */
static inline int8_t mavlink_msg_hw_params_get_motor0_invert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  9);
}

/**
 * @brief Get field motor1_invert from hw_params message
 *
 * @return  Motor 1 Invert
 */
static inline int8_t mavlink_msg_hw_params_get_motor1_invert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  10);
}

/**
 * @brief Get field encoder0_invert from hw_params message
 *
 * @return  Encoder 0 Invert
 */
static inline int8_t mavlink_msg_hw_params_get_encoder0_invert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  11);
}

/**
 * @brief Get field encoder1_invert from hw_params message
 *
 * @return  Encoder 1 Invert
 */
static inline int8_t mavlink_msg_hw_params_get_encoder1_invert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  12);
}

/**
 * @brief Get field encoder_exchange from hw_params message
 *
 * @return  Switch to invert encoder from motor 0 to motor 1 and vice versa
 */
static inline int8_t mavlink_msg_hw_params_get_encoder_exchange(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  13);
}

/**
 * @brief Get field motor0_pos_deadband from hw_params message
 *
 * @return  Motor 0 positive deadband
 */
static inline int16_t mavlink_msg_hw_params_get_motor0_pos_deadband(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field motor0_neg_deadband from hw_params message
 *
 * @return  Motor 0 negative deadband
 */
static inline int16_t mavlink_msg_hw_params_get_motor0_neg_deadband(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field motor1_pos_deadband from hw_params message
 *
 * @return  Motor 1 positive deadband
 */
static inline int16_t mavlink_msg_hw_params_get_motor1_pos_deadband(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field motor1_neg_deadband from hw_params message
 *
 * @return  Motor 1 negative deadband
 */
static inline int16_t mavlink_msg_hw_params_get_motor1_neg_deadband(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  6);
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
    hw_params->motor0_pos_deadband = mavlink_msg_hw_params_get_motor0_pos_deadband(msg);
    hw_params->motor0_neg_deadband = mavlink_msg_hw_params_get_motor0_neg_deadband(msg);
    hw_params->motor1_pos_deadband = mavlink_msg_hw_params_get_motor1_pos_deadband(msg);
    hw_params->motor1_neg_deadband = mavlink_msg_hw_params_get_motor1_neg_deadband(msg);
    hw_params->motor_type = mavlink_msg_hw_params_get_motor_type(msg);
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
