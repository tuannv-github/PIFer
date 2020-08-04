#pragma once
// MESSAGE CMD_PARAMS PACKING

#define MAVLINK_MSG_ID_CMD_PARAMS 2

MAVPACKED(
typedef struct __mavlink_cmd_params_t {
 int8_t cmd_params; /*<  save or load params*/
}) mavlink_cmd_params_t;

#define MAVLINK_MSG_ID_CMD_PARAMS_LEN 1
#define MAVLINK_MSG_ID_CMD_PARAMS_MIN_LEN 1
#define MAVLINK_MSG_ID_2_LEN 1
#define MAVLINK_MSG_ID_2_MIN_LEN 1

#define MAVLINK_MSG_ID_CMD_PARAMS_CRC 245
#define MAVLINK_MSG_ID_2_CRC 245



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CMD_PARAMS { \
    2, \
    "CMD_PARAMS", \
    1, \
    {  { "cmd_params", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_cmd_params_t, cmd_params) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CMD_PARAMS { \
    "CMD_PARAMS", \
    1, \
    {  { "cmd_params", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_cmd_params_t, cmd_params) }, \
         } \
}
#endif

/**
 * @brief Pack a cmd_params message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param cmd_params  save or load params
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_params_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int8_t cmd_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_PARAMS_LEN];
    _mav_put_int8_t(buf, 0, cmd_params);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_PARAMS_LEN);
#else
    mavlink_cmd_params_t packet;
    packet.cmd_params = cmd_params;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_PARAMS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CMD_PARAMS_MIN_LEN, MAVLINK_MSG_ID_CMD_PARAMS_LEN, MAVLINK_MSG_ID_CMD_PARAMS_CRC);
}

/**
 * @brief Pack a cmd_params message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_params  save or load params
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_params_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int8_t cmd_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_PARAMS_LEN];
    _mav_put_int8_t(buf, 0, cmd_params);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_PARAMS_LEN);
#else
    mavlink_cmd_params_t packet;
    packet.cmd_params = cmd_params;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_PARAMS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CMD_PARAMS_MIN_LEN, MAVLINK_MSG_ID_CMD_PARAMS_LEN, MAVLINK_MSG_ID_CMD_PARAMS_CRC);
}

/**
 * @brief Encode a cmd_params struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cmd_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_params_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cmd_params_t* cmd_params)
{
    return mavlink_msg_cmd_params_pack(system_id, component_id, msg, cmd_params->cmd_params);
}

/**
 * @brief Encode a cmd_params struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_params_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cmd_params_t* cmd_params)
{
    return mavlink_msg_cmd_params_pack_chan(system_id, component_id, chan, msg, cmd_params->cmd_params);
}

/**
 * @brief Send a cmd_params message
 * @param chan MAVLink channel to send the message
 *
 * @param cmd_params  save or load params
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cmd_params_send(mavlink_channel_t chan, int8_t cmd_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_PARAMS_LEN];
    _mav_put_int8_t(buf, 0, cmd_params);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_PARAMS, buf, MAVLINK_MSG_ID_CMD_PARAMS_MIN_LEN, MAVLINK_MSG_ID_CMD_PARAMS_LEN, MAVLINK_MSG_ID_CMD_PARAMS_CRC);
#else
    mavlink_cmd_params_t packet;
    packet.cmd_params = cmd_params;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_PARAMS, (const char *)&packet, MAVLINK_MSG_ID_CMD_PARAMS_MIN_LEN, MAVLINK_MSG_ID_CMD_PARAMS_LEN, MAVLINK_MSG_ID_CMD_PARAMS_CRC);
#endif
}

/**
 * @brief Send a cmd_params message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cmd_params_send_struct(mavlink_channel_t chan, const mavlink_cmd_params_t* cmd_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cmd_params_send(chan, cmd_params->cmd_params);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_PARAMS, (const char *)cmd_params, MAVLINK_MSG_ID_CMD_PARAMS_MIN_LEN, MAVLINK_MSG_ID_CMD_PARAMS_LEN, MAVLINK_MSG_ID_CMD_PARAMS_CRC);
#endif
}

#if MAVLINK_MSG_ID_CMD_PARAMS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cmd_params_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int8_t cmd_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int8_t(buf, 0, cmd_params);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_PARAMS, buf, MAVLINK_MSG_ID_CMD_PARAMS_MIN_LEN, MAVLINK_MSG_ID_CMD_PARAMS_LEN, MAVLINK_MSG_ID_CMD_PARAMS_CRC);
#else
    mavlink_cmd_params_t *packet = (mavlink_cmd_params_t *)msgbuf;
    packet->cmd_params = cmd_params;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_PARAMS, (const char *)packet, MAVLINK_MSG_ID_CMD_PARAMS_MIN_LEN, MAVLINK_MSG_ID_CMD_PARAMS_LEN, MAVLINK_MSG_ID_CMD_PARAMS_CRC);
#endif
}
#endif

#endif

// MESSAGE CMD_PARAMS UNPACKING


/**
 * @brief Get field cmd_params from cmd_params message
 *
 * @return  save or load params
 */
static inline int8_t mavlink_msg_cmd_params_get_cmd_params(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  0);
}

/**
 * @brief Decode a cmd_params message into a struct
 *
 * @param msg The message to decode
 * @param cmd_params C-struct to decode the message contents into
 */
static inline void mavlink_msg_cmd_params_decode(const mavlink_message_t* msg, mavlink_cmd_params_t* cmd_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cmd_params->cmd_params = mavlink_msg_cmd_params_get_cmd_params(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CMD_PARAMS_LEN? msg->len : MAVLINK_MSG_ID_CMD_PARAMS_LEN;
        memset(cmd_params, 0, MAVLINK_MSG_ID_CMD_PARAMS_LEN);
    memcpy(cmd_params, _MAV_PAYLOAD(msg), len);
#endif
}
