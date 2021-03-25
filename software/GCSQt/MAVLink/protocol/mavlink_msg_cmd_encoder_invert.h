#pragma once
// MESSAGE CMD_ENCODER_INVERT PACKING

#define MAVLINK_MSG_ID_CMD_ENCODER_INVERT 8

MAVPACKED(
typedef struct __mavlink_cmd_encoder_invert_t {
 int8_t encoder_invert; /*<  Encoder Invert*/
}) mavlink_cmd_encoder_invert_t;

#define MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN 1
#define MAVLINK_MSG_ID_CMD_ENCODER_INVERT_MIN_LEN 1
#define MAVLINK_MSG_ID_8_LEN 1
#define MAVLINK_MSG_ID_8_MIN_LEN 1

#define MAVLINK_MSG_ID_CMD_ENCODER_INVERT_CRC 211
#define MAVLINK_MSG_ID_8_CRC 211



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CMD_ENCODER_INVERT { \
    8, \
    "CMD_ENCODER_INVERT", \
    1, \
    {  { "encoder_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_cmd_encoder_invert_t, encoder_invert) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CMD_ENCODER_INVERT { \
    "CMD_ENCODER_INVERT", \
    1, \
    {  { "encoder_invert", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_cmd_encoder_invert_t, encoder_invert) }, \
         } \
}
#endif

/**
 * @brief Pack a cmd_encoder_invert message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param encoder_invert  Encoder Invert
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_encoder_invert_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int8_t encoder_invert)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN];
    _mav_put_int8_t(buf, 0, encoder_invert);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN);
#else
    mavlink_cmd_encoder_invert_t packet;
    packet.encoder_invert = encoder_invert;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_ENCODER_INVERT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_MIN_LEN, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_CRC);
}

/**
 * @brief Pack a cmd_encoder_invert message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param encoder_invert  Encoder Invert
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_encoder_invert_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int8_t encoder_invert)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN];
    _mav_put_int8_t(buf, 0, encoder_invert);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN);
#else
    mavlink_cmd_encoder_invert_t packet;
    packet.encoder_invert = encoder_invert;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_ENCODER_INVERT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_MIN_LEN, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_CRC);
}

/**
 * @brief Encode a cmd_encoder_invert struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cmd_encoder_invert C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_encoder_invert_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cmd_encoder_invert_t* cmd_encoder_invert)
{
    return mavlink_msg_cmd_encoder_invert_pack(system_id, component_id, msg, cmd_encoder_invert->encoder_invert);
}

/**
 * @brief Encode a cmd_encoder_invert struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_encoder_invert C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_encoder_invert_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cmd_encoder_invert_t* cmd_encoder_invert)
{
    return mavlink_msg_cmd_encoder_invert_pack_chan(system_id, component_id, chan, msg, cmd_encoder_invert->encoder_invert);
}

/**
 * @brief Send a cmd_encoder_invert message
 * @param chan MAVLink channel to send the message
 *
 * @param encoder_invert  Encoder Invert
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cmd_encoder_invert_send(mavlink_channel_t chan, int8_t encoder_invert)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN];
    _mav_put_int8_t(buf, 0, encoder_invert);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_ENCODER_INVERT, buf, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_MIN_LEN, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_CRC);
#else
    mavlink_cmd_encoder_invert_t packet;
    packet.encoder_invert = encoder_invert;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_ENCODER_INVERT, (const char *)&packet, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_MIN_LEN, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_CRC);
#endif
}

/**
 * @brief Send a cmd_encoder_invert message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cmd_encoder_invert_send_struct(mavlink_channel_t chan, const mavlink_cmd_encoder_invert_t* cmd_encoder_invert)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cmd_encoder_invert_send(chan, cmd_encoder_invert->encoder_invert);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_ENCODER_INVERT, (const char *)cmd_encoder_invert, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_MIN_LEN, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_CRC);
#endif
}

#if MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cmd_encoder_invert_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int8_t encoder_invert)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int8_t(buf, 0, encoder_invert);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_ENCODER_INVERT, buf, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_MIN_LEN, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_CRC);
#else
    mavlink_cmd_encoder_invert_t *packet = (mavlink_cmd_encoder_invert_t *)msgbuf;
    packet->encoder_invert = encoder_invert;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_ENCODER_INVERT, (const char *)packet, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_MIN_LEN, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_CRC);
#endif
}
#endif

#endif

// MESSAGE CMD_ENCODER_INVERT UNPACKING


/**
 * @brief Get field encoder_invert from cmd_encoder_invert message
 *
 * @return  Encoder Invert
 */
static inline int8_t mavlink_msg_cmd_encoder_invert_get_encoder_invert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  0);
}

/**
 * @brief Decode a cmd_encoder_invert message into a struct
 *
 * @param msg The message to decode
 * @param cmd_encoder_invert C-struct to decode the message contents into
 */
static inline void mavlink_msg_cmd_encoder_invert_decode(const mavlink_message_t* msg, mavlink_cmd_encoder_invert_t* cmd_encoder_invert)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cmd_encoder_invert->encoder_invert = mavlink_msg_cmd_encoder_invert_get_encoder_invert(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN? msg->len : MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN;
        memset(cmd_encoder_invert, 0, MAVLINK_MSG_ID_CMD_ENCODER_INVERT_LEN);
    memcpy(cmd_encoder_invert, _MAV_PAYLOAD(msg), len);
#endif
}
