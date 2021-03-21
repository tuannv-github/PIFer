#pragma once
// MESSAGE TOF PACKING

#define MAVLINK_MSG_ID_TOF 24


typedef struct __mavlink_tof_t {
 uint32_t tof; /*<  */
 uint16_t uwb_address; /*<  */
 uint16_t anchor; /*<  */
} mavlink_tof_t;

#define MAVLINK_MSG_ID_TOF_LEN 8
#define MAVLINK_MSG_ID_TOF_MIN_LEN 8
#define MAVLINK_MSG_ID_24_LEN 8
#define MAVLINK_MSG_ID_24_MIN_LEN 8

#define MAVLINK_MSG_ID_TOF_CRC 4
#define MAVLINK_MSG_ID_24_CRC 4



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TOF { \
    24, \
    "TOF", \
    3, \
    {  { "uwb_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_tof_t, uwb_address) }, \
         { "anchor", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_tof_t, anchor) }, \
         { "tof", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_tof_t, tof) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TOF { \
    "TOF", \
    3, \
    {  { "uwb_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_tof_t, uwb_address) }, \
         { "anchor", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_tof_t, anchor) }, \
         { "tof", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_tof_t, tof) }, \
         } \
}
#endif

/**
 * @brief Pack a tof message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uwb_address  
 * @param anchor  
 * @param tof  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tof_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t uwb_address, uint16_t anchor, uint32_t tof)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TOF_LEN];
    _mav_put_uint32_t(buf, 0, tof);
    _mav_put_uint16_t(buf, 4, uwb_address);
    _mav_put_uint16_t(buf, 6, anchor);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TOF_LEN);
#else
    mavlink_tof_t packet;
    packet.tof = tof;
    packet.uwb_address = uwb_address;
    packet.anchor = anchor;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TOF_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TOF;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TOF_MIN_LEN, MAVLINK_MSG_ID_TOF_LEN, MAVLINK_MSG_ID_TOF_CRC);
}

/**
 * @brief Pack a tof message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uwb_address  
 * @param anchor  
 * @param tof  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tof_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t uwb_address,uint16_t anchor,uint32_t tof)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TOF_LEN];
    _mav_put_uint32_t(buf, 0, tof);
    _mav_put_uint16_t(buf, 4, uwb_address);
    _mav_put_uint16_t(buf, 6, anchor);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TOF_LEN);
#else
    mavlink_tof_t packet;
    packet.tof = tof;
    packet.uwb_address = uwb_address;
    packet.anchor = anchor;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TOF_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TOF;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TOF_MIN_LEN, MAVLINK_MSG_ID_TOF_LEN, MAVLINK_MSG_ID_TOF_CRC);
}

/**
 * @brief Encode a tof struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tof C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tof_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tof_t* tof)
{
    return mavlink_msg_tof_pack(system_id, component_id, msg, tof->uwb_address, tof->anchor, tof->tof);
}

/**
 * @brief Encode a tof struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tof C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tof_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tof_t* tof)
{
    return mavlink_msg_tof_pack_chan(system_id, component_id, chan, msg, tof->uwb_address, tof->anchor, tof->tof);
}

/**
 * @brief Send a tof message
 * @param chan MAVLink channel to send the message
 *
 * @param uwb_address  
 * @param anchor  
 * @param tof  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tof_send(mavlink_channel_t chan, uint16_t uwb_address, uint16_t anchor, uint32_t tof)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TOF_LEN];
    _mav_put_uint32_t(buf, 0, tof);
    _mav_put_uint16_t(buf, 4, uwb_address);
    _mav_put_uint16_t(buf, 6, anchor);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TOF, buf, MAVLINK_MSG_ID_TOF_MIN_LEN, MAVLINK_MSG_ID_TOF_LEN, MAVLINK_MSG_ID_TOF_CRC);
#else
    mavlink_tof_t packet;
    packet.tof = tof;
    packet.uwb_address = uwb_address;
    packet.anchor = anchor;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TOF, (const char *)&packet, MAVLINK_MSG_ID_TOF_MIN_LEN, MAVLINK_MSG_ID_TOF_LEN, MAVLINK_MSG_ID_TOF_CRC);
#endif
}

/**
 * @brief Send a tof message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tof_send_struct(mavlink_channel_t chan, const mavlink_tof_t* tof)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tof_send(chan, tof->uwb_address, tof->anchor, tof->tof);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TOF, (const char *)tof, MAVLINK_MSG_ID_TOF_MIN_LEN, MAVLINK_MSG_ID_TOF_LEN, MAVLINK_MSG_ID_TOF_CRC);
#endif
}

#if MAVLINK_MSG_ID_TOF_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tof_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t uwb_address, uint16_t anchor, uint32_t tof)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, tof);
    _mav_put_uint16_t(buf, 4, uwb_address);
    _mav_put_uint16_t(buf, 6, anchor);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TOF, buf, MAVLINK_MSG_ID_TOF_MIN_LEN, MAVLINK_MSG_ID_TOF_LEN, MAVLINK_MSG_ID_TOF_CRC);
#else
    mavlink_tof_t *packet = (mavlink_tof_t *)msgbuf;
    packet->tof = tof;
    packet->uwb_address = uwb_address;
    packet->anchor = anchor;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TOF, (const char *)packet, MAVLINK_MSG_ID_TOF_MIN_LEN, MAVLINK_MSG_ID_TOF_LEN, MAVLINK_MSG_ID_TOF_CRC);
#endif
}
#endif

#endif

// MESSAGE TOF UNPACKING


/**
 * @brief Get field uwb_address from tof message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_tof_get_uwb_address(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field anchor from tof message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_tof_get_anchor(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field tof from tof message
 *
 * @return  
 */
static inline uint32_t mavlink_msg_tof_get_tof(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a tof message into a struct
 *
 * @param msg The message to decode
 * @param tof C-struct to decode the message contents into
 */
static inline void mavlink_msg_tof_decode(const mavlink_message_t* msg, mavlink_tof_t* tof)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    tof->tof = mavlink_msg_tof_get_tof(msg);
    tof->uwb_address = mavlink_msg_tof_get_uwb_address(msg);
    tof->anchor = mavlink_msg_tof_get_anchor(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TOF_LEN? msg->len : MAVLINK_MSG_ID_TOF_LEN;
        memset(tof, 0, MAVLINK_MSG_ID_TOF_LEN);
    memcpy(tof, _MAV_PAYLOAD(msg), len);
#endif
}
