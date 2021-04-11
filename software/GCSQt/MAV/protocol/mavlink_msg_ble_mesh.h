#pragma once
// MESSAGE BLE_MESH PACKING

#define MAVLINK_MSG_ID_BLE_MESH 20


typedef struct __mavlink_ble_mesh_t {
 uint16_t uwb_address; /*<  */
 uint16_t mesh_address; /*<  */
} mavlink_ble_mesh_t;

#define MAVLINK_MSG_ID_BLE_MESH_LEN 4
#define MAVLINK_MSG_ID_BLE_MESH_MIN_LEN 4
#define MAVLINK_MSG_ID_20_LEN 4
#define MAVLINK_MSG_ID_20_MIN_LEN 4

#define MAVLINK_MSG_ID_BLE_MESH_CRC 91
#define MAVLINK_MSG_ID_20_CRC 91



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BLE_MESH { \
    20, \
    "BLE_MESH", \
    2, \
    {  { "uwb_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_ble_mesh_t, uwb_address) }, \
         { "mesh_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_ble_mesh_t, mesh_address) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BLE_MESH { \
    "BLE_MESH", \
    2, \
    {  { "uwb_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_ble_mesh_t, uwb_address) }, \
         { "mesh_address", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_ble_mesh_t, mesh_address) }, \
         } \
}
#endif

/**
 * @brief Pack a ble_mesh message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uwb_address  
 * @param mesh_address  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ble_mesh_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t uwb_address, uint16_t mesh_address)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BLE_MESH_LEN];
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint16_t(buf, 2, mesh_address);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BLE_MESH_LEN);
#else
    mavlink_ble_mesh_t packet;
    packet.uwb_address = uwb_address;
    packet.mesh_address = mesh_address;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BLE_MESH_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BLE_MESH;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BLE_MESH_MIN_LEN, MAVLINK_MSG_ID_BLE_MESH_LEN, MAVLINK_MSG_ID_BLE_MESH_CRC);
}

/**
 * @brief Pack a ble_mesh message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uwb_address  
 * @param mesh_address  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ble_mesh_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t uwb_address,uint16_t mesh_address)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BLE_MESH_LEN];
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint16_t(buf, 2, mesh_address);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BLE_MESH_LEN);
#else
    mavlink_ble_mesh_t packet;
    packet.uwb_address = uwb_address;
    packet.mesh_address = mesh_address;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BLE_MESH_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BLE_MESH;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BLE_MESH_MIN_LEN, MAVLINK_MSG_ID_BLE_MESH_LEN, MAVLINK_MSG_ID_BLE_MESH_CRC);
}

/**
 * @brief Encode a ble_mesh struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ble_mesh C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ble_mesh_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ble_mesh_t* ble_mesh)
{
    return mavlink_msg_ble_mesh_pack(system_id, component_id, msg, ble_mesh->uwb_address, ble_mesh->mesh_address);
}

/**
 * @brief Encode a ble_mesh struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ble_mesh C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ble_mesh_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ble_mesh_t* ble_mesh)
{
    return mavlink_msg_ble_mesh_pack_chan(system_id, component_id, chan, msg, ble_mesh->uwb_address, ble_mesh->mesh_address);
}

/**
 * @brief Send a ble_mesh message
 * @param chan MAVLink channel to send the message
 *
 * @param uwb_address  
 * @param mesh_address  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ble_mesh_send(mavlink_channel_t chan, uint16_t uwb_address, uint16_t mesh_address)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BLE_MESH_LEN];
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint16_t(buf, 2, mesh_address);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BLE_MESH, buf, MAVLINK_MSG_ID_BLE_MESH_MIN_LEN, MAVLINK_MSG_ID_BLE_MESH_LEN, MAVLINK_MSG_ID_BLE_MESH_CRC);
#else
    mavlink_ble_mesh_t packet;
    packet.uwb_address = uwb_address;
    packet.mesh_address = mesh_address;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BLE_MESH, (const char *)&packet, MAVLINK_MSG_ID_BLE_MESH_MIN_LEN, MAVLINK_MSG_ID_BLE_MESH_LEN, MAVLINK_MSG_ID_BLE_MESH_CRC);
#endif
}

/**
 * @brief Send a ble_mesh message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ble_mesh_send_struct(mavlink_channel_t chan, const mavlink_ble_mesh_t* ble_mesh)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ble_mesh_send(chan, ble_mesh->uwb_address, ble_mesh->mesh_address);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BLE_MESH, (const char *)ble_mesh, MAVLINK_MSG_ID_BLE_MESH_MIN_LEN, MAVLINK_MSG_ID_BLE_MESH_LEN, MAVLINK_MSG_ID_BLE_MESH_CRC);
#endif
}

#if MAVLINK_MSG_ID_BLE_MESH_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ble_mesh_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t uwb_address, uint16_t mesh_address)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, uwb_address);
    _mav_put_uint16_t(buf, 2, mesh_address);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BLE_MESH, buf, MAVLINK_MSG_ID_BLE_MESH_MIN_LEN, MAVLINK_MSG_ID_BLE_MESH_LEN, MAVLINK_MSG_ID_BLE_MESH_CRC);
#else
    mavlink_ble_mesh_t *packet = (mavlink_ble_mesh_t *)msgbuf;
    packet->uwb_address = uwb_address;
    packet->mesh_address = mesh_address;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BLE_MESH, (const char *)packet, MAVLINK_MSG_ID_BLE_MESH_MIN_LEN, MAVLINK_MSG_ID_BLE_MESH_LEN, MAVLINK_MSG_ID_BLE_MESH_CRC);
#endif
}
#endif

#endif

// MESSAGE BLE_MESH UNPACKING


/**
 * @brief Get field uwb_address from ble_mesh message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_ble_mesh_get_uwb_address(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field mesh_address from ble_mesh message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_ble_mesh_get_mesh_address(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Decode a ble_mesh message into a struct
 *
 * @param msg The message to decode
 * @param ble_mesh C-struct to decode the message contents into
 */
static inline void mavlink_msg_ble_mesh_decode(const mavlink_message_t* msg, mavlink_ble_mesh_t* ble_mesh)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ble_mesh->uwb_address = mavlink_msg_ble_mesh_get_uwb_address(msg);
    ble_mesh->mesh_address = mavlink_msg_ble_mesh_get_mesh_address(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_BLE_MESH_LEN? msg->len : MAVLINK_MSG_ID_BLE_MESH_LEN;
        memset(ble_mesh, 0, MAVLINK_MSG_ID_BLE_MESH_LEN);
    memcpy(ble_mesh, _MAV_PAYLOAD(msg), len);
#endif
}
