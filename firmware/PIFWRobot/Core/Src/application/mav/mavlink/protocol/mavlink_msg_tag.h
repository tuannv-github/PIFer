#pragma once
// MESSAGE TAG PACKING

#define MAVLINK_MSG_ID_TAG 25


typedef struct __mavlink_tag_t {
 float a0x; /*<  */
 float a0y; /*<  */
 float a0z; /*<  */
 float a0r; /*<  */
 float a1x; /*<  */
 float a1y; /*<  */
 float a1z; /*<  */
 float a1r; /*<  */
 float a2x; /*<  */
 float a2y; /*<  */
 float a2z; /*<  */
 float a2r; /*<  */
 float a3x; /*<  */
 float a3y; /*<  */
 float a3z; /*<  */
 float a3r; /*<  */
 float t0x; /*<  */
 float t0y; /*<  */
 float t0z; /*<  */
 uint16_t a0; /*<  */
 uint16_t a1; /*<  */
 uint16_t a2; /*<  */
 uint16_t a3; /*<  */
 uint16_t t0; /*<  */
} mavlink_tag_t;

#define MAVLINK_MSG_ID_TAG_LEN 86
#define MAVLINK_MSG_ID_TAG_MIN_LEN 86
#define MAVLINK_MSG_ID_25_LEN 86
#define MAVLINK_MSG_ID_25_MIN_LEN 86

#define MAVLINK_MSG_ID_TAG_CRC 71
#define MAVLINK_MSG_ID_25_CRC 71



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TAG { \
    25, \
    "TAG", \
    24, \
    {  { "a0", NULL, MAVLINK_TYPE_UINT16_T, 0, 76, offsetof(mavlink_tag_t, a0) }, \
         { "a0x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_tag_t, a0x) }, \
         { "a0y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_tag_t, a0y) }, \
         { "a0z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_tag_t, a0z) }, \
         { "a0r", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_tag_t, a0r) }, \
         { "a1", NULL, MAVLINK_TYPE_UINT16_T, 0, 78, offsetof(mavlink_tag_t, a1) }, \
         { "a1x", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_tag_t, a1x) }, \
         { "a1y", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_tag_t, a1y) }, \
         { "a1z", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_tag_t, a1z) }, \
         { "a1r", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_tag_t, a1r) }, \
         { "a2", NULL, MAVLINK_TYPE_UINT16_T, 0, 80, offsetof(mavlink_tag_t, a2) }, \
         { "a2x", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_tag_t, a2x) }, \
         { "a2y", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_tag_t, a2y) }, \
         { "a2z", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_tag_t, a2z) }, \
         { "a2r", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_tag_t, a2r) }, \
         { "a3", NULL, MAVLINK_TYPE_UINT16_T, 0, 82, offsetof(mavlink_tag_t, a3) }, \
         { "a3x", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_tag_t, a3x) }, \
         { "a3y", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_tag_t, a3y) }, \
         { "a3z", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_tag_t, a3z) }, \
         { "a3r", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_tag_t, a3r) }, \
         { "t0", NULL, MAVLINK_TYPE_UINT16_T, 0, 84, offsetof(mavlink_tag_t, t0) }, \
         { "t0x", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_tag_t, t0x) }, \
         { "t0y", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_tag_t, t0y) }, \
         { "t0z", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_tag_t, t0z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TAG { \
    "TAG", \
    24, \
    {  { "a0", NULL, MAVLINK_TYPE_UINT16_T, 0, 76, offsetof(mavlink_tag_t, a0) }, \
         { "a0x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_tag_t, a0x) }, \
         { "a0y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_tag_t, a0y) }, \
         { "a0z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_tag_t, a0z) }, \
         { "a0r", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_tag_t, a0r) }, \
         { "a1", NULL, MAVLINK_TYPE_UINT16_T, 0, 78, offsetof(mavlink_tag_t, a1) }, \
         { "a1x", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_tag_t, a1x) }, \
         { "a1y", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_tag_t, a1y) }, \
         { "a1z", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_tag_t, a1z) }, \
         { "a1r", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_tag_t, a1r) }, \
         { "a2", NULL, MAVLINK_TYPE_UINT16_T, 0, 80, offsetof(mavlink_tag_t, a2) }, \
         { "a2x", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_tag_t, a2x) }, \
         { "a2y", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_tag_t, a2y) }, \
         { "a2z", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_tag_t, a2z) }, \
         { "a2r", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_tag_t, a2r) }, \
         { "a3", NULL, MAVLINK_TYPE_UINT16_T, 0, 82, offsetof(mavlink_tag_t, a3) }, \
         { "a3x", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_tag_t, a3x) }, \
         { "a3y", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_tag_t, a3y) }, \
         { "a3z", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_tag_t, a3z) }, \
         { "a3r", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_tag_t, a3r) }, \
         { "t0", NULL, MAVLINK_TYPE_UINT16_T, 0, 84, offsetof(mavlink_tag_t, t0) }, \
         { "t0x", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_tag_t, t0x) }, \
         { "t0y", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_tag_t, t0y) }, \
         { "t0z", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_tag_t, t0z) }, \
         } \
}
#endif

/**
 * @brief Pack a tag message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param a0  
 * @param a0x  
 * @param a0y  
 * @param a0z  
 * @param a0r  
 * @param a1  
 * @param a1x  
 * @param a1y  
 * @param a1z  
 * @param a1r  
 * @param a2  
 * @param a2x  
 * @param a2y  
 * @param a2z  
 * @param a2r  
 * @param a3  
 * @param a3x  
 * @param a3y  
 * @param a3z  
 * @param a3r  
 * @param t0  
 * @param t0x  
 * @param t0y  
 * @param t0z  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tag_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t a0, float a0x, float a0y, float a0z, float a0r, uint16_t a1, float a1x, float a1y, float a1z, float a1r, uint16_t a2, float a2x, float a2y, float a2z, float a2r, uint16_t a3, float a3x, float a3y, float a3z, float a3r, uint16_t t0, float t0x, float t0y, float t0z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TAG_LEN];
    _mav_put_float(buf, 0, a0x);
    _mav_put_float(buf, 4, a0y);
    _mav_put_float(buf, 8, a0z);
    _mav_put_float(buf, 12, a0r);
    _mav_put_float(buf, 16, a1x);
    _mav_put_float(buf, 20, a1y);
    _mav_put_float(buf, 24, a1z);
    _mav_put_float(buf, 28, a1r);
    _mav_put_float(buf, 32, a2x);
    _mav_put_float(buf, 36, a2y);
    _mav_put_float(buf, 40, a2z);
    _mav_put_float(buf, 44, a2r);
    _mav_put_float(buf, 48, a3x);
    _mav_put_float(buf, 52, a3y);
    _mav_put_float(buf, 56, a3z);
    _mav_put_float(buf, 60, a3r);
    _mav_put_float(buf, 64, t0x);
    _mav_put_float(buf, 68, t0y);
    _mav_put_float(buf, 72, t0z);
    _mav_put_uint16_t(buf, 76, a0);
    _mav_put_uint16_t(buf, 78, a1);
    _mav_put_uint16_t(buf, 80, a2);
    _mav_put_uint16_t(buf, 82, a3);
    _mav_put_uint16_t(buf, 84, t0);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TAG_LEN);
#else
    mavlink_tag_t packet;
    packet.a0x = a0x;
    packet.a0y = a0y;
    packet.a0z = a0z;
    packet.a0r = a0r;
    packet.a1x = a1x;
    packet.a1y = a1y;
    packet.a1z = a1z;
    packet.a1r = a1r;
    packet.a2x = a2x;
    packet.a2y = a2y;
    packet.a2z = a2z;
    packet.a2r = a2r;
    packet.a3x = a3x;
    packet.a3y = a3y;
    packet.a3z = a3z;
    packet.a3r = a3r;
    packet.t0x = t0x;
    packet.t0y = t0y;
    packet.t0z = t0z;
    packet.a0 = a0;
    packet.a1 = a1;
    packet.a2 = a2;
    packet.a3 = a3;
    packet.t0 = t0;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TAG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TAG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TAG_MIN_LEN, MAVLINK_MSG_ID_TAG_LEN, MAVLINK_MSG_ID_TAG_CRC);
}

/**
 * @brief Pack a tag message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param a0  
 * @param a0x  
 * @param a0y  
 * @param a0z  
 * @param a0r  
 * @param a1  
 * @param a1x  
 * @param a1y  
 * @param a1z  
 * @param a1r  
 * @param a2  
 * @param a2x  
 * @param a2y  
 * @param a2z  
 * @param a2r  
 * @param a3  
 * @param a3x  
 * @param a3y  
 * @param a3z  
 * @param a3r  
 * @param t0  
 * @param t0x  
 * @param t0y  
 * @param t0z  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tag_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t a0,float a0x,float a0y,float a0z,float a0r,uint16_t a1,float a1x,float a1y,float a1z,float a1r,uint16_t a2,float a2x,float a2y,float a2z,float a2r,uint16_t a3,float a3x,float a3y,float a3z,float a3r,uint16_t t0,float t0x,float t0y,float t0z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TAG_LEN];
    _mav_put_float(buf, 0, a0x);
    _mav_put_float(buf, 4, a0y);
    _mav_put_float(buf, 8, a0z);
    _mav_put_float(buf, 12, a0r);
    _mav_put_float(buf, 16, a1x);
    _mav_put_float(buf, 20, a1y);
    _mav_put_float(buf, 24, a1z);
    _mav_put_float(buf, 28, a1r);
    _mav_put_float(buf, 32, a2x);
    _mav_put_float(buf, 36, a2y);
    _mav_put_float(buf, 40, a2z);
    _mav_put_float(buf, 44, a2r);
    _mav_put_float(buf, 48, a3x);
    _mav_put_float(buf, 52, a3y);
    _mav_put_float(buf, 56, a3z);
    _mav_put_float(buf, 60, a3r);
    _mav_put_float(buf, 64, t0x);
    _mav_put_float(buf, 68, t0y);
    _mav_put_float(buf, 72, t0z);
    _mav_put_uint16_t(buf, 76, a0);
    _mav_put_uint16_t(buf, 78, a1);
    _mav_put_uint16_t(buf, 80, a2);
    _mav_put_uint16_t(buf, 82, a3);
    _mav_put_uint16_t(buf, 84, t0);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TAG_LEN);
#else
    mavlink_tag_t packet;
    packet.a0x = a0x;
    packet.a0y = a0y;
    packet.a0z = a0z;
    packet.a0r = a0r;
    packet.a1x = a1x;
    packet.a1y = a1y;
    packet.a1z = a1z;
    packet.a1r = a1r;
    packet.a2x = a2x;
    packet.a2y = a2y;
    packet.a2z = a2z;
    packet.a2r = a2r;
    packet.a3x = a3x;
    packet.a3y = a3y;
    packet.a3z = a3z;
    packet.a3r = a3r;
    packet.t0x = t0x;
    packet.t0y = t0y;
    packet.t0z = t0z;
    packet.a0 = a0;
    packet.a1 = a1;
    packet.a2 = a2;
    packet.a3 = a3;
    packet.t0 = t0;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TAG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TAG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TAG_MIN_LEN, MAVLINK_MSG_ID_TAG_LEN, MAVLINK_MSG_ID_TAG_CRC);
}

/**
 * @brief Encode a tag struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tag C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tag_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tag_t* tag)
{
    return mavlink_msg_tag_pack(system_id, component_id, msg, tag->a0, tag->a0x, tag->a0y, tag->a0z, tag->a0r, tag->a1, tag->a1x, tag->a1y, tag->a1z, tag->a1r, tag->a2, tag->a2x, tag->a2y, tag->a2z, tag->a2r, tag->a3, tag->a3x, tag->a3y, tag->a3z, tag->a3r, tag->t0, tag->t0x, tag->t0y, tag->t0z);
}

/**
 * @brief Encode a tag struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tag C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tag_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tag_t* tag)
{
    return mavlink_msg_tag_pack_chan(system_id, component_id, chan, msg, tag->a0, tag->a0x, tag->a0y, tag->a0z, tag->a0r, tag->a1, tag->a1x, tag->a1y, tag->a1z, tag->a1r, tag->a2, tag->a2x, tag->a2y, tag->a2z, tag->a2r, tag->a3, tag->a3x, tag->a3y, tag->a3z, tag->a3r, tag->t0, tag->t0x, tag->t0y, tag->t0z);
}

/**
 * @brief Send a tag message
 * @param chan MAVLink channel to send the message
 *
 * @param a0  
 * @param a0x  
 * @param a0y  
 * @param a0z  
 * @param a0r  
 * @param a1  
 * @param a1x  
 * @param a1y  
 * @param a1z  
 * @param a1r  
 * @param a2  
 * @param a2x  
 * @param a2y  
 * @param a2z  
 * @param a2r  
 * @param a3  
 * @param a3x  
 * @param a3y  
 * @param a3z  
 * @param a3r  
 * @param t0  
 * @param t0x  
 * @param t0y  
 * @param t0z  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tag_send(mavlink_channel_t chan, uint16_t a0, float a0x, float a0y, float a0z, float a0r, uint16_t a1, float a1x, float a1y, float a1z, float a1r, uint16_t a2, float a2x, float a2y, float a2z, float a2r, uint16_t a3, float a3x, float a3y, float a3z, float a3r, uint16_t t0, float t0x, float t0y, float t0z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TAG_LEN];
    _mav_put_float(buf, 0, a0x);
    _mav_put_float(buf, 4, a0y);
    _mav_put_float(buf, 8, a0z);
    _mav_put_float(buf, 12, a0r);
    _mav_put_float(buf, 16, a1x);
    _mav_put_float(buf, 20, a1y);
    _mav_put_float(buf, 24, a1z);
    _mav_put_float(buf, 28, a1r);
    _mav_put_float(buf, 32, a2x);
    _mav_put_float(buf, 36, a2y);
    _mav_put_float(buf, 40, a2z);
    _mav_put_float(buf, 44, a2r);
    _mav_put_float(buf, 48, a3x);
    _mav_put_float(buf, 52, a3y);
    _mav_put_float(buf, 56, a3z);
    _mav_put_float(buf, 60, a3r);
    _mav_put_float(buf, 64, t0x);
    _mav_put_float(buf, 68, t0y);
    _mav_put_float(buf, 72, t0z);
    _mav_put_uint16_t(buf, 76, a0);
    _mav_put_uint16_t(buf, 78, a1);
    _mav_put_uint16_t(buf, 80, a2);
    _mav_put_uint16_t(buf, 82, a3);
    _mav_put_uint16_t(buf, 84, t0);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TAG, buf, MAVLINK_MSG_ID_TAG_MIN_LEN, MAVLINK_MSG_ID_TAG_LEN, MAVLINK_MSG_ID_TAG_CRC);
#else
    mavlink_tag_t packet;
    packet.a0x = a0x;
    packet.a0y = a0y;
    packet.a0z = a0z;
    packet.a0r = a0r;
    packet.a1x = a1x;
    packet.a1y = a1y;
    packet.a1z = a1z;
    packet.a1r = a1r;
    packet.a2x = a2x;
    packet.a2y = a2y;
    packet.a2z = a2z;
    packet.a2r = a2r;
    packet.a3x = a3x;
    packet.a3y = a3y;
    packet.a3z = a3z;
    packet.a3r = a3r;
    packet.t0x = t0x;
    packet.t0y = t0y;
    packet.t0z = t0z;
    packet.a0 = a0;
    packet.a1 = a1;
    packet.a2 = a2;
    packet.a3 = a3;
    packet.t0 = t0;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TAG, (const char *)&packet, MAVLINK_MSG_ID_TAG_MIN_LEN, MAVLINK_MSG_ID_TAG_LEN, MAVLINK_MSG_ID_TAG_CRC);
#endif
}

/**
 * @brief Send a tag message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tag_send_struct(mavlink_channel_t chan, const mavlink_tag_t* tag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tag_send(chan, tag->a0, tag->a0x, tag->a0y, tag->a0z, tag->a0r, tag->a1, tag->a1x, tag->a1y, tag->a1z, tag->a1r, tag->a2, tag->a2x, tag->a2y, tag->a2z, tag->a2r, tag->a3, tag->a3x, tag->a3y, tag->a3z, tag->a3r, tag->t0, tag->t0x, tag->t0y, tag->t0z);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TAG, (const char *)tag, MAVLINK_MSG_ID_TAG_MIN_LEN, MAVLINK_MSG_ID_TAG_LEN, MAVLINK_MSG_ID_TAG_CRC);
#endif
}

#if MAVLINK_MSG_ID_TAG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tag_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t a0, float a0x, float a0y, float a0z, float a0r, uint16_t a1, float a1x, float a1y, float a1z, float a1r, uint16_t a2, float a2x, float a2y, float a2z, float a2r, uint16_t a3, float a3x, float a3y, float a3z, float a3r, uint16_t t0, float t0x, float t0y, float t0z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, a0x);
    _mav_put_float(buf, 4, a0y);
    _mav_put_float(buf, 8, a0z);
    _mav_put_float(buf, 12, a0r);
    _mav_put_float(buf, 16, a1x);
    _mav_put_float(buf, 20, a1y);
    _mav_put_float(buf, 24, a1z);
    _mav_put_float(buf, 28, a1r);
    _mav_put_float(buf, 32, a2x);
    _mav_put_float(buf, 36, a2y);
    _mav_put_float(buf, 40, a2z);
    _mav_put_float(buf, 44, a2r);
    _mav_put_float(buf, 48, a3x);
    _mav_put_float(buf, 52, a3y);
    _mav_put_float(buf, 56, a3z);
    _mav_put_float(buf, 60, a3r);
    _mav_put_float(buf, 64, t0x);
    _mav_put_float(buf, 68, t0y);
    _mav_put_float(buf, 72, t0z);
    _mav_put_uint16_t(buf, 76, a0);
    _mav_put_uint16_t(buf, 78, a1);
    _mav_put_uint16_t(buf, 80, a2);
    _mav_put_uint16_t(buf, 82, a3);
    _mav_put_uint16_t(buf, 84, t0);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TAG, buf, MAVLINK_MSG_ID_TAG_MIN_LEN, MAVLINK_MSG_ID_TAG_LEN, MAVLINK_MSG_ID_TAG_CRC);
#else
    mavlink_tag_t *packet = (mavlink_tag_t *)msgbuf;
    packet->a0x = a0x;
    packet->a0y = a0y;
    packet->a0z = a0z;
    packet->a0r = a0r;
    packet->a1x = a1x;
    packet->a1y = a1y;
    packet->a1z = a1z;
    packet->a1r = a1r;
    packet->a2x = a2x;
    packet->a2y = a2y;
    packet->a2z = a2z;
    packet->a2r = a2r;
    packet->a3x = a3x;
    packet->a3y = a3y;
    packet->a3z = a3z;
    packet->a3r = a3r;
    packet->t0x = t0x;
    packet->t0y = t0y;
    packet->t0z = t0z;
    packet->a0 = a0;
    packet->a1 = a1;
    packet->a2 = a2;
    packet->a3 = a3;
    packet->t0 = t0;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TAG, (const char *)packet, MAVLINK_MSG_ID_TAG_MIN_LEN, MAVLINK_MSG_ID_TAG_LEN, MAVLINK_MSG_ID_TAG_CRC);
#endif
}
#endif

#endif

// MESSAGE TAG UNPACKING


/**
 * @brief Get field a0 from tag message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_tag_get_a0(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  76);
}

/**
 * @brief Get field a0x from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a0x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field a0y from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a0y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field a0z from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a0z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field a0r from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a0r(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field a1 from tag message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_tag_get_a1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  78);
}

/**
 * @brief Get field a1x from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a1x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field a1y from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a1y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field a1z from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a1z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field a1r from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a1r(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field a2 from tag message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_tag_get_a2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  80);
}

/**
 * @brief Get field a2x from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a2x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field a2y from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a2y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field a2z from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a2z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field a2r from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a2r(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field a3 from tag message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_tag_get_a3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  82);
}

/**
 * @brief Get field a3x from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a3x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field a3y from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a3y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field a3z from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a3z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field a3r from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_a3r(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field t0 from tag message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_tag_get_t0(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  84);
}

/**
 * @brief Get field t0x from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_t0x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field t0y from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_t0y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field t0z from tag message
 *
 * @return  
 */
static inline float mavlink_msg_tag_get_t0z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Decode a tag message into a struct
 *
 * @param msg The message to decode
 * @param tag C-struct to decode the message contents into
 */
static inline void mavlink_msg_tag_decode(const mavlink_message_t* msg, mavlink_tag_t* tag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    tag->a0x = mavlink_msg_tag_get_a0x(msg);
    tag->a0y = mavlink_msg_tag_get_a0y(msg);
    tag->a0z = mavlink_msg_tag_get_a0z(msg);
    tag->a0r = mavlink_msg_tag_get_a0r(msg);
    tag->a1x = mavlink_msg_tag_get_a1x(msg);
    tag->a1y = mavlink_msg_tag_get_a1y(msg);
    tag->a1z = mavlink_msg_tag_get_a1z(msg);
    tag->a1r = mavlink_msg_tag_get_a1r(msg);
    tag->a2x = mavlink_msg_tag_get_a2x(msg);
    tag->a2y = mavlink_msg_tag_get_a2y(msg);
    tag->a2z = mavlink_msg_tag_get_a2z(msg);
    tag->a2r = mavlink_msg_tag_get_a2r(msg);
    tag->a3x = mavlink_msg_tag_get_a3x(msg);
    tag->a3y = mavlink_msg_tag_get_a3y(msg);
    tag->a3z = mavlink_msg_tag_get_a3z(msg);
    tag->a3r = mavlink_msg_tag_get_a3r(msg);
    tag->t0x = mavlink_msg_tag_get_t0x(msg);
    tag->t0y = mavlink_msg_tag_get_t0y(msg);
    tag->t0z = mavlink_msg_tag_get_t0z(msg);
    tag->a0 = mavlink_msg_tag_get_a0(msg);
    tag->a1 = mavlink_msg_tag_get_a1(msg);
    tag->a2 = mavlink_msg_tag_get_a2(msg);
    tag->a3 = mavlink_msg_tag_get_a3(msg);
    tag->t0 = mavlink_msg_tag_get_t0(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TAG_LEN? msg->len : MAVLINK_MSG_ID_TAG_LEN;
        memset(tag, 0, MAVLINK_MSG_ID_TAG_LEN);
    memcpy(tag, _MAV_PAYLOAD(msg), len);
#endif
}
