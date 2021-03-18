#pragma once
// MESSAGE SLOT PACKING

#define MAVLINK_MSG_ID_SLOT 24


typedef struct __mavlink_slot_t {
 uint16_t uwb_address; /*<  */
 uint8_t slot; /*<  */
} mavlink_slot_t;

#define MAVLINK_MSG_ID_SLOT_LEN 3
#define MAVLINK_MSG_ID_SLOT_MIN_LEN 3
#define MAVLINK_MSG_ID_24_LEN 3
#define MAVLINK_MSG_ID_24_MIN_LEN 3

#define MAVLINK_MSG_ID_SLOT_CRC 177
#define MAVLINK_MSG_ID_24_CRC 177



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SLOT { \
    24, \
    "SLOT", \
    2, \
    {  { "uwb_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_slot_t, uwb_address) }, \
         { "slot", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_slot_t, slot) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SLOT { \
    "SLOT", \
    2, \
    {  { "uwb_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_slot_t, uwb_address) }, \
         { "slot", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_slot_t, slot) }, \
         } \
}
#endif

/**
 * @brief Pack a slot message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uwb_address  
 * @param slot  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_slot_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t uwb_address, uint8_t slot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SLOT_LEN];
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint8_t(buf, 2, slot);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SLOT_LEN);
#else
    mavlink_slot_t packet;
    packet.uwb_address = uwb_address;
    packet.slot = slot;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SLOT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SLOT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SLOT_MIN_LEN, MAVLINK_MSG_ID_SLOT_LEN, MAVLINK_MSG_ID_SLOT_CRC);
}

/**
 * @brief Pack a slot message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uwb_address  
 * @param slot  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_slot_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t uwb_address,uint8_t slot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SLOT_LEN];
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint8_t(buf, 2, slot);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SLOT_LEN);
#else
    mavlink_slot_t packet;
    packet.uwb_address = uwb_address;
    packet.slot = slot;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SLOT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SLOT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SLOT_MIN_LEN, MAVLINK_MSG_ID_SLOT_LEN, MAVLINK_MSG_ID_SLOT_CRC);
}

/**
 * @brief Encode a slot struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param slot C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_slot_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_slot_t* slot)
{
    return mavlink_msg_slot_pack(system_id, component_id, msg, slot->uwb_address, slot->slot);
}

/**
 * @brief Encode a slot struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param slot C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_slot_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_slot_t* slot)
{
    return mavlink_msg_slot_pack_chan(system_id, component_id, chan, msg, slot->uwb_address, slot->slot);
}

/**
 * @brief Send a slot message
 * @param chan MAVLink channel to send the message
 *
 * @param uwb_address  
 * @param slot  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_slot_send(mavlink_channel_t chan, uint16_t uwb_address, uint8_t slot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SLOT_LEN];
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint8_t(buf, 2, slot);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SLOT, buf, MAVLINK_MSG_ID_SLOT_MIN_LEN, MAVLINK_MSG_ID_SLOT_LEN, MAVLINK_MSG_ID_SLOT_CRC);
#else
    mavlink_slot_t packet;
    packet.uwb_address = uwb_address;
    packet.slot = slot;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SLOT, (const char *)&packet, MAVLINK_MSG_ID_SLOT_MIN_LEN, MAVLINK_MSG_ID_SLOT_LEN, MAVLINK_MSG_ID_SLOT_CRC);
#endif
}

/**
 * @brief Send a slot message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_slot_send_struct(mavlink_channel_t chan, const mavlink_slot_t* slot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_slot_send(chan, slot->uwb_address, slot->slot);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SLOT, (const char *)slot, MAVLINK_MSG_ID_SLOT_MIN_LEN, MAVLINK_MSG_ID_SLOT_LEN, MAVLINK_MSG_ID_SLOT_CRC);
#endif
}

#if MAVLINK_MSG_ID_SLOT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_slot_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t uwb_address, uint8_t slot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint8_t(buf, 2, slot);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SLOT, buf, MAVLINK_MSG_ID_SLOT_MIN_LEN, MAVLINK_MSG_ID_SLOT_LEN, MAVLINK_MSG_ID_SLOT_CRC);
#else
    mavlink_slot_t *packet = (mavlink_slot_t *)msgbuf;
    packet->uwb_address = uwb_address;
    packet->slot = slot;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SLOT, (const char *)packet, MAVLINK_MSG_ID_SLOT_MIN_LEN, MAVLINK_MSG_ID_SLOT_LEN, MAVLINK_MSG_ID_SLOT_CRC);
#endif
}
#endif

#endif

// MESSAGE SLOT UNPACKING


/**
 * @brief Get field uwb_address from slot message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_slot_get_uwb_address(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field slot from slot message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_slot_get_slot(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a slot message into a struct
 *
 * @param msg The message to decode
 * @param slot C-struct to decode the message contents into
 */
static inline void mavlink_msg_slot_decode(const mavlink_message_t* msg, mavlink_slot_t* slot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    slot->uwb_address = mavlink_msg_slot_get_uwb_address(msg);
    slot->slot = mavlink_msg_slot_get_slot(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SLOT_LEN? msg->len : MAVLINK_MSG_ID_SLOT_LEN;
        memset(slot, 0, MAVLINK_MSG_ID_SLOT_LEN);
    memcpy(slot, _MAV_PAYLOAD(msg), len);
#endif
}
