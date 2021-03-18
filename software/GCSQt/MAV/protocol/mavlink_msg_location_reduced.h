#pragma once
// MESSAGE LOCATION_REDUCED PACKING

#define MAVLINK_MSG_ID_LOCATION_REDUCED 21


typedef struct __mavlink_location_reduced_t {
 float location_x; /*<  */
 float location_y; /*<  */
 uint16_t mesh_address; /*<  */
} mavlink_location_reduced_t;

#define MAVLINK_MSG_ID_LOCATION_REDUCED_LEN 10
#define MAVLINK_MSG_ID_LOCATION_REDUCED_MIN_LEN 10
#define MAVLINK_MSG_ID_21_LEN 10
#define MAVLINK_MSG_ID_21_MIN_LEN 10

#define MAVLINK_MSG_ID_LOCATION_REDUCED_CRC 244
#define MAVLINK_MSG_ID_21_CRC 244



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LOCATION_REDUCED { \
    21, \
    "LOCATION_REDUCED", \
    3, \
    {  { "mesh_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_location_reduced_t, mesh_address) }, \
         { "location_x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_location_reduced_t, location_x) }, \
         { "location_y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_location_reduced_t, location_y) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LOCATION_REDUCED { \
    "LOCATION_REDUCED", \
    3, \
    {  { "mesh_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_location_reduced_t, mesh_address) }, \
         { "location_x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_location_reduced_t, location_x) }, \
         { "location_y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_location_reduced_t, location_y) }, \
         } \
}
#endif

/**
 * @brief Pack a location_reduced message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mesh_address  
 * @param location_x  
 * @param location_y  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_location_reduced_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t mesh_address, float location_x, float location_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LOCATION_REDUCED_LEN];
    _mav_put_float(buf, 0, location_x);
    _mav_put_float(buf, 4, location_y);
    _mav_put_uint16_t(buf, 8, mesh_address);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LOCATION_REDUCED_LEN);
#else
    mavlink_location_reduced_t packet;
    packet.location_x = location_x;
    packet.location_y = location_y;
    packet.mesh_address = mesh_address;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LOCATION_REDUCED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LOCATION_REDUCED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LOCATION_REDUCED_MIN_LEN, MAVLINK_MSG_ID_LOCATION_REDUCED_LEN, MAVLINK_MSG_ID_LOCATION_REDUCED_CRC);
}

/**
 * @brief Pack a location_reduced message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mesh_address  
 * @param location_x  
 * @param location_y  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_location_reduced_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t mesh_address,float location_x,float location_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LOCATION_REDUCED_LEN];
    _mav_put_float(buf, 0, location_x);
    _mav_put_float(buf, 4, location_y);
    _mav_put_uint16_t(buf, 8, mesh_address);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LOCATION_REDUCED_LEN);
#else
    mavlink_location_reduced_t packet;
    packet.location_x = location_x;
    packet.location_y = location_y;
    packet.mesh_address = mesh_address;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LOCATION_REDUCED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LOCATION_REDUCED;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LOCATION_REDUCED_MIN_LEN, MAVLINK_MSG_ID_LOCATION_REDUCED_LEN, MAVLINK_MSG_ID_LOCATION_REDUCED_CRC);
}

/**
 * @brief Encode a location_reduced struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param location_reduced C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_location_reduced_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_location_reduced_t* location_reduced)
{
    return mavlink_msg_location_reduced_pack(system_id, component_id, msg, location_reduced->mesh_address, location_reduced->location_x, location_reduced->location_y);
}

/**
 * @brief Encode a location_reduced struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param location_reduced C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_location_reduced_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_location_reduced_t* location_reduced)
{
    return mavlink_msg_location_reduced_pack_chan(system_id, component_id, chan, msg, location_reduced->mesh_address, location_reduced->location_x, location_reduced->location_y);
}

/**
 * @brief Send a location_reduced message
 * @param chan MAVLink channel to send the message
 *
 * @param mesh_address  
 * @param location_x  
 * @param location_y  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_location_reduced_send(mavlink_channel_t chan, uint16_t mesh_address, float location_x, float location_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LOCATION_REDUCED_LEN];
    _mav_put_float(buf, 0, location_x);
    _mav_put_float(buf, 4, location_y);
    _mav_put_uint16_t(buf, 8, mesh_address);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LOCATION_REDUCED, buf, MAVLINK_MSG_ID_LOCATION_REDUCED_MIN_LEN, MAVLINK_MSG_ID_LOCATION_REDUCED_LEN, MAVLINK_MSG_ID_LOCATION_REDUCED_CRC);
#else
    mavlink_location_reduced_t packet;
    packet.location_x = location_x;
    packet.location_y = location_y;
    packet.mesh_address = mesh_address;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LOCATION_REDUCED, (const char *)&packet, MAVLINK_MSG_ID_LOCATION_REDUCED_MIN_LEN, MAVLINK_MSG_ID_LOCATION_REDUCED_LEN, MAVLINK_MSG_ID_LOCATION_REDUCED_CRC);
#endif
}

/**
 * @brief Send a location_reduced message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_location_reduced_send_struct(mavlink_channel_t chan, const mavlink_location_reduced_t* location_reduced)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_location_reduced_send(chan, location_reduced->mesh_address, location_reduced->location_x, location_reduced->location_y);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LOCATION_REDUCED, (const char *)location_reduced, MAVLINK_MSG_ID_LOCATION_REDUCED_MIN_LEN, MAVLINK_MSG_ID_LOCATION_REDUCED_LEN, MAVLINK_MSG_ID_LOCATION_REDUCED_CRC);
#endif
}

#if MAVLINK_MSG_ID_LOCATION_REDUCED_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_location_reduced_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t mesh_address, float location_x, float location_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, location_x);
    _mav_put_float(buf, 4, location_y);
    _mav_put_uint16_t(buf, 8, mesh_address);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LOCATION_REDUCED, buf, MAVLINK_MSG_ID_LOCATION_REDUCED_MIN_LEN, MAVLINK_MSG_ID_LOCATION_REDUCED_LEN, MAVLINK_MSG_ID_LOCATION_REDUCED_CRC);
#else
    mavlink_location_reduced_t *packet = (mavlink_location_reduced_t *)msgbuf;
    packet->location_x = location_x;
    packet->location_y = location_y;
    packet->mesh_address = mesh_address;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LOCATION_REDUCED, (const char *)packet, MAVLINK_MSG_ID_LOCATION_REDUCED_MIN_LEN, MAVLINK_MSG_ID_LOCATION_REDUCED_LEN, MAVLINK_MSG_ID_LOCATION_REDUCED_CRC);
#endif
}
#endif

#endif

// MESSAGE LOCATION_REDUCED UNPACKING


/**
 * @brief Get field mesh_address from location_reduced message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_location_reduced_get_mesh_address(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field location_x from location_reduced message
 *
 * @return  
 */
static inline float mavlink_msg_location_reduced_get_location_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field location_y from location_reduced message
 *
 * @return  
 */
static inline float mavlink_msg_location_reduced_get_location_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a location_reduced message into a struct
 *
 * @param msg The message to decode
 * @param location_reduced C-struct to decode the message contents into
 */
static inline void mavlink_msg_location_reduced_decode(const mavlink_message_t* msg, mavlink_location_reduced_t* location_reduced)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    location_reduced->location_x = mavlink_msg_location_reduced_get_location_x(msg);
    location_reduced->location_y = mavlink_msg_location_reduced_get_location_y(msg);
    location_reduced->mesh_address = mavlink_msg_location_reduced_get_mesh_address(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LOCATION_REDUCED_LEN? msg->len : MAVLINK_MSG_ID_LOCATION_REDUCED_LEN;
        memset(location_reduced, 0, MAVLINK_MSG_ID_LOCATION_REDUCED_LEN);
    memcpy(location_reduced, _MAV_PAYLOAD(msg), len);
#endif
}
