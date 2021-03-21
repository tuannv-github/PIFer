#pragma once
// MESSAGE CONTROL_MEASUREMENT PACKING

#define MAVLINK_MSG_ID_CONTROL_MEASUREMENT 30


typedef struct __mavlink_control_measurement_t {
 float left; /*<  */
 float right; /*<  */
 float rx; /*<  */
 float ry; /*<  */
 float range; /*<  */
 float yaw; /*<  */
} mavlink_control_measurement_t;

#define MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN 24
#define MAVLINK_MSG_ID_CONTROL_MEASUREMENT_MIN_LEN 24
#define MAVLINK_MSG_ID_30_LEN 24
#define MAVLINK_MSG_ID_30_MIN_LEN 24

#define MAVLINK_MSG_ID_CONTROL_MEASUREMENT_CRC 72
#define MAVLINK_MSG_ID_30_CRC 72



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CONTROL_MEASUREMENT { \
    30, \
    "CONTROL_MEASUREMENT", \
    6, \
    {  { "left", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_control_measurement_t, left) }, \
         { "right", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_control_measurement_t, right) }, \
         { "rx", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_control_measurement_t, rx) }, \
         { "ry", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_control_measurement_t, ry) }, \
         { "range", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_control_measurement_t, range) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_control_measurement_t, yaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CONTROL_MEASUREMENT { \
    "CONTROL_MEASUREMENT", \
    6, \
    {  { "left", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_control_measurement_t, left) }, \
         { "right", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_control_measurement_t, right) }, \
         { "rx", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_control_measurement_t, rx) }, \
         { "ry", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_control_measurement_t, ry) }, \
         { "range", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_control_measurement_t, range) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_control_measurement_t, yaw) }, \
         } \
}
#endif

/**
 * @brief Pack a control_measurement message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param left  
 * @param right  
 * @param rx  
 * @param ry  
 * @param range  
 * @param yaw  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_control_measurement_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float left, float right, float rx, float ry, float range, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN];
    _mav_put_float(buf, 0, left);
    _mav_put_float(buf, 4, right);
    _mav_put_float(buf, 8, rx);
    _mav_put_float(buf, 12, ry);
    _mav_put_float(buf, 16, range);
    _mav_put_float(buf, 20, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN);
#else
    mavlink_control_measurement_t packet;
    packet.left = left;
    packet.right = right;
    packet.rx = rx;
    packet.ry = ry;
    packet.range = range;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONTROL_MEASUREMENT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_CRC);
}

/**
 * @brief Pack a control_measurement message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param left  
 * @param right  
 * @param rx  
 * @param ry  
 * @param range  
 * @param yaw  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_control_measurement_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float left,float right,float rx,float ry,float range,float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN];
    _mav_put_float(buf, 0, left);
    _mav_put_float(buf, 4, right);
    _mav_put_float(buf, 8, rx);
    _mav_put_float(buf, 12, ry);
    _mav_put_float(buf, 16, range);
    _mav_put_float(buf, 20, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN);
#else
    mavlink_control_measurement_t packet;
    packet.left = left;
    packet.right = right;
    packet.rx = rx;
    packet.ry = ry;
    packet.range = range;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONTROL_MEASUREMENT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_CRC);
}

/**
 * @brief Encode a control_measurement struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param control_measurement C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_control_measurement_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_control_measurement_t* control_measurement)
{
    return mavlink_msg_control_measurement_pack(system_id, component_id, msg, control_measurement->left, control_measurement->right, control_measurement->rx, control_measurement->ry, control_measurement->range, control_measurement->yaw);
}

/**
 * @brief Encode a control_measurement struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param control_measurement C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_control_measurement_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_control_measurement_t* control_measurement)
{
    return mavlink_msg_control_measurement_pack_chan(system_id, component_id, chan, msg, control_measurement->left, control_measurement->right, control_measurement->rx, control_measurement->ry, control_measurement->range, control_measurement->yaw);
}

/**
 * @brief Send a control_measurement message
 * @param chan MAVLink channel to send the message
 *
 * @param left  
 * @param right  
 * @param rx  
 * @param ry  
 * @param range  
 * @param yaw  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_control_measurement_send(mavlink_channel_t chan, float left, float right, float rx, float ry, float range, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN];
    _mav_put_float(buf, 0, left);
    _mav_put_float(buf, 4, right);
    _mav_put_float(buf, 8, rx);
    _mav_put_float(buf, 12, ry);
    _mav_put_float(buf, 16, range);
    _mav_put_float(buf, 20, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_MEASUREMENT, buf, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_CRC);
#else
    mavlink_control_measurement_t packet;
    packet.left = left;
    packet.right = right;
    packet.rx = rx;
    packet.ry = ry;
    packet.range = range;
    packet.yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_MEASUREMENT, (const char *)&packet, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_CRC);
#endif
}

/**
 * @brief Send a control_measurement message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_control_measurement_send_struct(mavlink_channel_t chan, const mavlink_control_measurement_t* control_measurement)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_control_measurement_send(chan, control_measurement->left, control_measurement->right, control_measurement->rx, control_measurement->ry, control_measurement->range, control_measurement->yaw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_MEASUREMENT, (const char *)control_measurement, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_CRC);
#endif
}

#if MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_control_measurement_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float left, float right, float rx, float ry, float range, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, left);
    _mav_put_float(buf, 4, right);
    _mav_put_float(buf, 8, rx);
    _mav_put_float(buf, 12, ry);
    _mav_put_float(buf, 16, range);
    _mav_put_float(buf, 20, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_MEASUREMENT, buf, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_CRC);
#else
    mavlink_control_measurement_t *packet = (mavlink_control_measurement_t *)msgbuf;
    packet->left = left;
    packet->right = right;
    packet->rx = rx;
    packet->ry = ry;
    packet->range = range;
    packet->yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_MEASUREMENT, (const char *)packet, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_CRC);
#endif
}
#endif

#endif

// MESSAGE CONTROL_MEASUREMENT UNPACKING


/**
 * @brief Get field left from control_measurement message
 *
 * @return  
 */
static inline float mavlink_msg_control_measurement_get_left(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field right from control_measurement message
 *
 * @return  
 */
static inline float mavlink_msg_control_measurement_get_right(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field rx from control_measurement message
 *
 * @return  
 */
static inline float mavlink_msg_control_measurement_get_rx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field ry from control_measurement message
 *
 * @return  
 */
static inline float mavlink_msg_control_measurement_get_ry(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field range from control_measurement message
 *
 * @return  
 */
static inline float mavlink_msg_control_measurement_get_range(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field yaw from control_measurement message
 *
 * @return  
 */
static inline float mavlink_msg_control_measurement_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a control_measurement message into a struct
 *
 * @param msg The message to decode
 * @param control_measurement C-struct to decode the message contents into
 */
static inline void mavlink_msg_control_measurement_decode(const mavlink_message_t* msg, mavlink_control_measurement_t* control_measurement)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    control_measurement->left = mavlink_msg_control_measurement_get_left(msg);
    control_measurement->right = mavlink_msg_control_measurement_get_right(msg);
    control_measurement->rx = mavlink_msg_control_measurement_get_rx(msg);
    control_measurement->ry = mavlink_msg_control_measurement_get_ry(msg);
    control_measurement->range = mavlink_msg_control_measurement_get_range(msg);
    control_measurement->yaw = mavlink_msg_control_measurement_get_yaw(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN? msg->len : MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN;
        memset(control_measurement, 0, MAVLINK_MSG_ID_CONTROL_MEASUREMENT_LEN);
    memcpy(control_measurement, _MAV_PAYLOAD(msg), len);
#endif
}
