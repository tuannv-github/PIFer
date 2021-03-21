#pragma once
// MESSAGE CONTROL PACKING

#define MAVLINK_MSG_ID_CONTROL 27


typedef struct __mavlink_control_t {
 float left; /*<  */
 float right; /*<  */
} mavlink_control_t;

#define MAVLINK_MSG_ID_CONTROL_LEN 8
#define MAVLINK_MSG_ID_CONTROL_MIN_LEN 8
#define MAVLINK_MSG_ID_27_LEN 8
#define MAVLINK_MSG_ID_27_MIN_LEN 8

#define MAVLINK_MSG_ID_CONTROL_CRC 103
#define MAVLINK_MSG_ID_27_CRC 103



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CONTROL { \
    27, \
    "CONTROL", \
    2, \
    {  { "left", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_control_t, left) }, \
         { "right", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_control_t, right) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CONTROL { \
    "CONTROL", \
    2, \
    {  { "left", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_control_t, left) }, \
         { "right", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_control_t, right) }, \
         } \
}
#endif

/**
 * @brief Pack a control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param left  
 * @param right  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float left, float right)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_LEN];
    _mav_put_float(buf, 0, left);
    _mav_put_float(buf, 4, right);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONTROL_LEN);
#else
    mavlink_control_t packet;
    packet.left = left;
    packet.right = right;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CONTROL_MIN_LEN, MAVLINK_MSG_ID_CONTROL_LEN, MAVLINK_MSG_ID_CONTROL_CRC);
}

/**
 * @brief Pack a control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param left  
 * @param right  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float left,float right)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_LEN];
    _mav_put_float(buf, 0, left);
    _mav_put_float(buf, 4, right);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONTROL_LEN);
#else
    mavlink_control_t packet;
    packet.left = left;
    packet.right = right;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CONTROL_MIN_LEN, MAVLINK_MSG_ID_CONTROL_LEN, MAVLINK_MSG_ID_CONTROL_CRC);
}

/**
 * @brief Encode a control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_control_t* control)
{
    return mavlink_msg_control_pack(system_id, component_id, msg, control->left, control->right);
}

/**
 * @brief Encode a control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_control_t* control)
{
    return mavlink_msg_control_pack_chan(system_id, component_id, chan, msg, control->left, control->right);
}

/**
 * @brief Send a control message
 * @param chan MAVLink channel to send the message
 *
 * @param left  
 * @param right  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_control_send(mavlink_channel_t chan, float left, float right)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_LEN];
    _mav_put_float(buf, 0, left);
    _mav_put_float(buf, 4, right);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL, buf, MAVLINK_MSG_ID_CONTROL_MIN_LEN, MAVLINK_MSG_ID_CONTROL_LEN, MAVLINK_MSG_ID_CONTROL_CRC);
#else
    mavlink_control_t packet;
    packet.left = left;
    packet.right = right;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_CONTROL_MIN_LEN, MAVLINK_MSG_ID_CONTROL_LEN, MAVLINK_MSG_ID_CONTROL_CRC);
#endif
}

/**
 * @brief Send a control message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_control_send_struct(mavlink_channel_t chan, const mavlink_control_t* control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_control_send(chan, control->left, control->right);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL, (const char *)control, MAVLINK_MSG_ID_CONTROL_MIN_LEN, MAVLINK_MSG_ID_CONTROL_LEN, MAVLINK_MSG_ID_CONTROL_CRC);
#endif
}

#if MAVLINK_MSG_ID_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float left, float right)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, left);
    _mav_put_float(buf, 4, right);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL, buf, MAVLINK_MSG_ID_CONTROL_MIN_LEN, MAVLINK_MSG_ID_CONTROL_LEN, MAVLINK_MSG_ID_CONTROL_CRC);
#else
    mavlink_control_t *packet = (mavlink_control_t *)msgbuf;
    packet->left = left;
    packet->right = right;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL, (const char *)packet, MAVLINK_MSG_ID_CONTROL_MIN_LEN, MAVLINK_MSG_ID_CONTROL_LEN, MAVLINK_MSG_ID_CONTROL_CRC);
#endif
}
#endif

#endif

// MESSAGE CONTROL UNPACKING


/**
 * @brief Get field left from control message
 *
 * @return  
 */
static inline float mavlink_msg_control_get_left(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field right from control message
 *
 * @return  
 */
static inline float mavlink_msg_control_get_right(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a control message into a struct
 *
 * @param msg The message to decode
 * @param control C-struct to decode the message contents into
 */
static inline void mavlink_msg_control_decode(const mavlink_message_t* msg, mavlink_control_t* control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    control->left = mavlink_msg_control_get_left(msg);
    control->right = mavlink_msg_control_get_right(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CONTROL_LEN? msg->len : MAVLINK_MSG_ID_CONTROL_LEN;
        memset(control, 0, MAVLINK_MSG_ID_CONTROL_LEN);
    memcpy(control, _MAV_PAYLOAD(msg), len);
#endif
}
