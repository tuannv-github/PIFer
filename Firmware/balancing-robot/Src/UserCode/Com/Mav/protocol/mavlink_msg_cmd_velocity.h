#pragma once
// MESSAGE CMD_VELOCITY PACKING

#define MAVLINK_MSG_ID_CMD_VELOCITY 3

MAVPACKED(
typedef struct __mavlink_cmd_velocity_t {
 int16_t v; /*<  Velocity*/
 int16_t omega; /*<  Omega*/
}) mavlink_cmd_velocity_t;

#define MAVLINK_MSG_ID_CMD_VELOCITY_LEN 4
#define MAVLINK_MSG_ID_CMD_VELOCITY_MIN_LEN 4
#define MAVLINK_MSG_ID_3_LEN 4
#define MAVLINK_MSG_ID_3_MIN_LEN 4

#define MAVLINK_MSG_ID_CMD_VELOCITY_CRC 63
#define MAVLINK_MSG_ID_3_CRC 63



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CMD_VELOCITY { \
    3, \
    "CMD_VELOCITY", \
    2, \
    {  { "v", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_cmd_velocity_t, v) }, \
         { "omega", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_cmd_velocity_t, omega) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CMD_VELOCITY { \
    "CMD_VELOCITY", \
    2, \
    {  { "v", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_cmd_velocity_t, v) }, \
         { "omega", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_cmd_velocity_t, omega) }, \
         } \
}
#endif

/**
 * @brief Pack a cmd_velocity message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param v  Velocity
 * @param omega  Omega
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_velocity_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t v, int16_t omega)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_VELOCITY_LEN];
    _mav_put_int16_t(buf, 0, v);
    _mav_put_int16_t(buf, 2, omega);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_VELOCITY_LEN);
#else
    mavlink_cmd_velocity_t packet;
    packet.v = v;
    packet.omega = omega;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_VELOCITY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_VELOCITY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CMD_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_CMD_VELOCITY_LEN, MAVLINK_MSG_ID_CMD_VELOCITY_CRC);
}

/**
 * @brief Pack a cmd_velocity message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param v  Velocity
 * @param omega  Omega
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_velocity_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t v,int16_t omega)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_VELOCITY_LEN];
    _mav_put_int16_t(buf, 0, v);
    _mav_put_int16_t(buf, 2, omega);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_VELOCITY_LEN);
#else
    mavlink_cmd_velocity_t packet;
    packet.v = v;
    packet.omega = omega;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_VELOCITY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_VELOCITY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CMD_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_CMD_VELOCITY_LEN, MAVLINK_MSG_ID_CMD_VELOCITY_CRC);
}

/**
 * @brief Encode a cmd_velocity struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cmd_velocity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_velocity_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cmd_velocity_t* cmd_velocity)
{
    return mavlink_msg_cmd_velocity_pack(system_id, component_id, msg, cmd_velocity->v, cmd_velocity->omega);
}

/**
 * @brief Encode a cmd_velocity struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_velocity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_velocity_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cmd_velocity_t* cmd_velocity)
{
    return mavlink_msg_cmd_velocity_pack_chan(system_id, component_id, chan, msg, cmd_velocity->v, cmd_velocity->omega);
}

/**
 * @brief Send a cmd_velocity message
 * @param chan MAVLink channel to send the message
 *
 * @param v  Velocity
 * @param omega  Omega
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cmd_velocity_send(mavlink_channel_t chan, int16_t v, int16_t omega)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_VELOCITY_LEN];
    _mav_put_int16_t(buf, 0, v);
    _mav_put_int16_t(buf, 2, omega);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_VELOCITY, buf, MAVLINK_MSG_ID_CMD_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_CMD_VELOCITY_LEN, MAVLINK_MSG_ID_CMD_VELOCITY_CRC);
#else
    mavlink_cmd_velocity_t packet;
    packet.v = v;
    packet.omega = omega;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_VELOCITY, (const char *)&packet, MAVLINK_MSG_ID_CMD_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_CMD_VELOCITY_LEN, MAVLINK_MSG_ID_CMD_VELOCITY_CRC);
#endif
}

/**
 * @brief Send a cmd_velocity message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cmd_velocity_send_struct(mavlink_channel_t chan, const mavlink_cmd_velocity_t* cmd_velocity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cmd_velocity_send(chan, cmd_velocity->v, cmd_velocity->omega);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_VELOCITY, (const char *)cmd_velocity, MAVLINK_MSG_ID_CMD_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_CMD_VELOCITY_LEN, MAVLINK_MSG_ID_CMD_VELOCITY_CRC);
#endif
}

#if MAVLINK_MSG_ID_CMD_VELOCITY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cmd_velocity_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t v, int16_t omega)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 0, v);
    _mav_put_int16_t(buf, 2, omega);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_VELOCITY, buf, MAVLINK_MSG_ID_CMD_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_CMD_VELOCITY_LEN, MAVLINK_MSG_ID_CMD_VELOCITY_CRC);
#else
    mavlink_cmd_velocity_t *packet = (mavlink_cmd_velocity_t *)msgbuf;
    packet->v = v;
    packet->omega = omega;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_VELOCITY, (const char *)packet, MAVLINK_MSG_ID_CMD_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_CMD_VELOCITY_LEN, MAVLINK_MSG_ID_CMD_VELOCITY_CRC);
#endif
}
#endif

#endif

// MESSAGE CMD_VELOCITY UNPACKING


/**
 * @brief Get field v from cmd_velocity message
 *
 * @return  Velocity
 */
static inline int16_t mavlink_msg_cmd_velocity_get_v(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field omega from cmd_velocity message
 *
 * @return  Omega
 */
static inline int16_t mavlink_msg_cmd_velocity_get_omega(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Decode a cmd_velocity message into a struct
 *
 * @param msg The message to decode
 * @param cmd_velocity C-struct to decode the message contents into
 */
static inline void mavlink_msg_cmd_velocity_decode(const mavlink_message_t* msg, mavlink_cmd_velocity_t* cmd_velocity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cmd_velocity->v = mavlink_msg_cmd_velocity_get_v(msg);
    cmd_velocity->omega = mavlink_msg_cmd_velocity_get_omega(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CMD_VELOCITY_LEN? msg->len : MAVLINK_MSG_ID_CMD_VELOCITY_LEN;
        memset(cmd_velocity, 0, MAVLINK_MSG_ID_CMD_VELOCITY_LEN);
    memcpy(cmd_velocity, _MAV_PAYLOAD(msg), len);
#endif
}
