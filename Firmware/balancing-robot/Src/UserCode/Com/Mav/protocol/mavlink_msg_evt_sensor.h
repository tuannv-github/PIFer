#pragma once
// MESSAGE EVT_SENSOR PACKING

#define MAVLINK_MSG_ID_EVT_SENSOR 6

MAVPACKED(
typedef struct __mavlink_evt_sensor_t {
 int8_t imu_status; /*<  IMU status*/
}) mavlink_evt_sensor_t;

#define MAVLINK_MSG_ID_EVT_SENSOR_LEN 1
#define MAVLINK_MSG_ID_EVT_SENSOR_MIN_LEN 1
#define MAVLINK_MSG_ID_6_LEN 1
#define MAVLINK_MSG_ID_6_MIN_LEN 1

#define MAVLINK_MSG_ID_EVT_SENSOR_CRC 54
#define MAVLINK_MSG_ID_6_CRC 54



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EVT_SENSOR { \
    6, \
    "EVT_SENSOR", \
    1, \
    {  { "imu_status", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_evt_sensor_t, imu_status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EVT_SENSOR { \
    "EVT_SENSOR", \
    1, \
    {  { "imu_status", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_evt_sensor_t, imu_status) }, \
         } \
}
#endif

/**
 * @brief Pack a evt_sensor message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param imu_status  IMU status
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_evt_sensor_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int8_t imu_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_SENSOR_LEN];
    _mav_put_int8_t(buf, 0, imu_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EVT_SENSOR_LEN);
#else
    mavlink_evt_sensor_t packet;
    packet.imu_status = imu_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EVT_SENSOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EVT_SENSOR;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EVT_SENSOR_MIN_LEN, MAVLINK_MSG_ID_EVT_SENSOR_LEN, MAVLINK_MSG_ID_EVT_SENSOR_CRC);
}

/**
 * @brief Pack a evt_sensor message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param imu_status  IMU status
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_evt_sensor_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int8_t imu_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_SENSOR_LEN];
    _mav_put_int8_t(buf, 0, imu_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EVT_SENSOR_LEN);
#else
    mavlink_evt_sensor_t packet;
    packet.imu_status = imu_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EVT_SENSOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EVT_SENSOR;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EVT_SENSOR_MIN_LEN, MAVLINK_MSG_ID_EVT_SENSOR_LEN, MAVLINK_MSG_ID_EVT_SENSOR_CRC);
}

/**
 * @brief Encode a evt_sensor struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param evt_sensor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_evt_sensor_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_evt_sensor_t* evt_sensor)
{
    return mavlink_msg_evt_sensor_pack(system_id, component_id, msg, evt_sensor->imu_status);
}

/**
 * @brief Encode a evt_sensor struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param evt_sensor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_evt_sensor_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_evt_sensor_t* evt_sensor)
{
    return mavlink_msg_evt_sensor_pack_chan(system_id, component_id, chan, msg, evt_sensor->imu_status);
}

/**
 * @brief Send a evt_sensor message
 * @param chan MAVLink channel to send the message
 *
 * @param imu_status  IMU status
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_evt_sensor_send(mavlink_channel_t chan, int8_t imu_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EVT_SENSOR_LEN];
    _mav_put_int8_t(buf, 0, imu_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_SENSOR, buf, MAVLINK_MSG_ID_EVT_SENSOR_MIN_LEN, MAVLINK_MSG_ID_EVT_SENSOR_LEN, MAVLINK_MSG_ID_EVT_SENSOR_CRC);
#else
    mavlink_evt_sensor_t packet;
    packet.imu_status = imu_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_SENSOR, (const char *)&packet, MAVLINK_MSG_ID_EVT_SENSOR_MIN_LEN, MAVLINK_MSG_ID_EVT_SENSOR_LEN, MAVLINK_MSG_ID_EVT_SENSOR_CRC);
#endif
}

/**
 * @brief Send a evt_sensor message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_evt_sensor_send_struct(mavlink_channel_t chan, const mavlink_evt_sensor_t* evt_sensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_evt_sensor_send(chan, evt_sensor->imu_status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_SENSOR, (const char *)evt_sensor, MAVLINK_MSG_ID_EVT_SENSOR_MIN_LEN, MAVLINK_MSG_ID_EVT_SENSOR_LEN, MAVLINK_MSG_ID_EVT_SENSOR_CRC);
#endif
}

#if MAVLINK_MSG_ID_EVT_SENSOR_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_evt_sensor_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int8_t imu_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int8_t(buf, 0, imu_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_SENSOR, buf, MAVLINK_MSG_ID_EVT_SENSOR_MIN_LEN, MAVLINK_MSG_ID_EVT_SENSOR_LEN, MAVLINK_MSG_ID_EVT_SENSOR_CRC);
#else
    mavlink_evt_sensor_t *packet = (mavlink_evt_sensor_t *)msgbuf;
    packet->imu_status = imu_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EVT_SENSOR, (const char *)packet, MAVLINK_MSG_ID_EVT_SENSOR_MIN_LEN, MAVLINK_MSG_ID_EVT_SENSOR_LEN, MAVLINK_MSG_ID_EVT_SENSOR_CRC);
#endif
}
#endif

#endif

// MESSAGE EVT_SENSOR UNPACKING


/**
 * @brief Get field imu_status from evt_sensor message
 *
 * @return  IMU status
 */
static inline int8_t mavlink_msg_evt_sensor_get_imu_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  0);
}

/**
 * @brief Decode a evt_sensor message into a struct
 *
 * @param msg The message to decode
 * @param evt_sensor C-struct to decode the message contents into
 */
static inline void mavlink_msg_evt_sensor_decode(const mavlink_message_t* msg, mavlink_evt_sensor_t* evt_sensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    evt_sensor->imu_status = mavlink_msg_evt_sensor_get_imu_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EVT_SENSOR_LEN? msg->len : MAVLINK_MSG_ID_EVT_SENSOR_LEN;
        memset(evt_sensor, 0, MAVLINK_MSG_ID_EVT_SENSOR_LEN);
    memcpy(evt_sensor, _MAV_PAYLOAD(msg), len);
#endif
}
