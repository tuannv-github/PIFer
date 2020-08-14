#pragma once
// MESSAGE RESPOND PACKING

#define MAVLINK_MSG_ID_RESPOND 0

MAVPACKED(
typedef struct __mavlink_respond_t {
 uint8_t respond; /*<  Respond*/
}) mavlink_respond_t;

#define MAVLINK_MSG_ID_RESPOND_LEN 1
#define MAVLINK_MSG_ID_RESPOND_MIN_LEN 1
#define MAVLINK_MSG_ID_0_LEN 1
#define MAVLINK_MSG_ID_0_MIN_LEN 1

#define MAVLINK_MSG_ID_RESPOND_CRC 164
#define MAVLINK_MSG_ID_0_CRC 164



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RESPOND { \
    0, \
    "RESPOND", \
    1, \
    {  { "respond", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_respond_t, respond) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RESPOND { \
    "RESPOND", \
    1, \
    {  { "respond", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_respond_t, respond) }, \
         } \
}
#endif

/**
 * @brief Pack a respond message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param respond  Respond
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_respond_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t respond)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RESPOND_LEN];
    _mav_put_uint8_t(buf, 0, respond);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RESPOND_LEN);
#else
    mavlink_respond_t packet;
    packet.respond = respond;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RESPOND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RESPOND;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RESPOND_MIN_LEN, MAVLINK_MSG_ID_RESPOND_LEN, MAVLINK_MSG_ID_RESPOND_CRC);
}

/**
 * @brief Pack a respond message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param respond  Respond
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_respond_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t respond)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RESPOND_LEN];
    _mav_put_uint8_t(buf, 0, respond);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RESPOND_LEN);
#else
    mavlink_respond_t packet;
    packet.respond = respond;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RESPOND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RESPOND;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RESPOND_MIN_LEN, MAVLINK_MSG_ID_RESPOND_LEN, MAVLINK_MSG_ID_RESPOND_CRC);
}

/**
 * @brief Encode a respond struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param respond C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_respond_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_respond_t* respond)
{
    return mavlink_msg_respond_pack(system_id, component_id, msg, respond->respond);
}

/**
 * @brief Encode a respond struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param respond C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_respond_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_respond_t* respond)
{
    return mavlink_msg_respond_pack_chan(system_id, component_id, chan, msg, respond->respond);
}

/**
 * @brief Send a respond message
 * @param chan MAVLink channel to send the message
 *
 * @param respond  Respond
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_respond_send(mavlink_channel_t chan, uint8_t respond)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RESPOND_LEN];
    _mav_put_uint8_t(buf, 0, respond);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RESPOND, buf, MAVLINK_MSG_ID_RESPOND_MIN_LEN, MAVLINK_MSG_ID_RESPOND_LEN, MAVLINK_MSG_ID_RESPOND_CRC);
#else
    mavlink_respond_t packet;
    packet.respond = respond;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RESPOND, (const char *)&packet, MAVLINK_MSG_ID_RESPOND_MIN_LEN, MAVLINK_MSG_ID_RESPOND_LEN, MAVLINK_MSG_ID_RESPOND_CRC);
#endif
}

/**
 * @brief Send a respond message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_respond_send_struct(mavlink_channel_t chan, const mavlink_respond_t* respond)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_respond_send(chan, respond->respond);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RESPOND, (const char *)respond, MAVLINK_MSG_ID_RESPOND_MIN_LEN, MAVLINK_MSG_ID_RESPOND_LEN, MAVLINK_MSG_ID_RESPOND_CRC);
#endif
}

#if MAVLINK_MSG_ID_RESPOND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_respond_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t respond)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, respond);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RESPOND, buf, MAVLINK_MSG_ID_RESPOND_MIN_LEN, MAVLINK_MSG_ID_RESPOND_LEN, MAVLINK_MSG_ID_RESPOND_CRC);
#else
    mavlink_respond_t *packet = (mavlink_respond_t *)msgbuf;
    packet->respond = respond;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RESPOND, (const char *)packet, MAVLINK_MSG_ID_RESPOND_MIN_LEN, MAVLINK_MSG_ID_RESPOND_LEN, MAVLINK_MSG_ID_RESPOND_CRC);
#endif
}
#endif

#endif

// MESSAGE RESPOND UNPACKING


/**
 * @brief Get field respond from respond message
 *
 * @return  Respond
 */
static inline uint8_t mavlink_msg_respond_get_respond(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a respond message into a struct
 *
 * @param msg The message to decode
 * @param respond C-struct to decode the message contents into
 */
static inline void mavlink_msg_respond_decode(const mavlink_message_t* msg, mavlink_respond_t* respond)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    respond->respond = mavlink_msg_respond_get_respond(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RESPOND_LEN? msg->len : MAVLINK_MSG_ID_RESPOND_LEN;
        memset(respond, 0, MAVLINK_MSG_ID_RESPOND_LEN);
    memcpy(respond, _MAV_PAYLOAD(msg), len);
#endif
}
