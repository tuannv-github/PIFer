#pragma once
// MESSAGE PID_PARAMS PACKING

#define MAVLINK_MSG_ID_PID_PARAMS 13

MAVPACKED(
typedef struct __mavlink_pid_params_t {
 float KP; /*<  KP*/
 float KI; /*<  KI*/
 float KD; /*<  KD*/
 uint8_t pid_control; /*<  Object that PID control*/
}) mavlink_pid_params_t;

#define MAVLINK_MSG_ID_PID_PARAMS_LEN 13
#define MAVLINK_MSG_ID_PID_PARAMS_MIN_LEN 13
#define MAVLINK_MSG_ID_13_LEN 13
#define MAVLINK_MSG_ID_13_MIN_LEN 13

#define MAVLINK_MSG_ID_PID_PARAMS_CRC 2
#define MAVLINK_MSG_ID_13_CRC 2



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PID_PARAMS { \
    13, \
    "PID_PARAMS", \
    4, \
    {  { "pid_control", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_pid_params_t, pid_control) }, \
         { "KP", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_pid_params_t, KP) }, \
         { "KI", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_pid_params_t, KI) }, \
         { "KD", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_pid_params_t, KD) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PID_PARAMS { \
    "PID_PARAMS", \
    4, \
    {  { "pid_control", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_pid_params_t, pid_control) }, \
         { "KP", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_pid_params_t, KP) }, \
         { "KI", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_pid_params_t, KI) }, \
         { "KD", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_pid_params_t, KD) }, \
         } \
}
#endif

/**
 * @brief Pack a pid_params message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param pid_control  Object that PID control
 * @param KP  KP
 * @param KI  KI
 * @param KD  KD
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_params_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t pid_control, float KP, float KI, float KD)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PID_PARAMS_LEN];
    _mav_put_float(buf, 0, KP);
    _mav_put_float(buf, 4, KI);
    _mav_put_float(buf, 8, KD);
    _mav_put_uint8_t(buf, 12, pid_control);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PID_PARAMS_LEN);
#else
    mavlink_pid_params_t packet;
    packet.KP = KP;
    packet.KI = KI;
    packet.KD = KD;
    packet.pid_control = pid_control;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PID_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PID_PARAMS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PID_PARAMS_MIN_LEN, MAVLINK_MSG_ID_PID_PARAMS_LEN, MAVLINK_MSG_ID_PID_PARAMS_CRC);
}

/**
 * @brief Pack a pid_params message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pid_control  Object that PID control
 * @param KP  KP
 * @param KI  KI
 * @param KD  KD
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_params_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t pid_control,float KP,float KI,float KD)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PID_PARAMS_LEN];
    _mav_put_float(buf, 0, KP);
    _mav_put_float(buf, 4, KI);
    _mav_put_float(buf, 8, KD);
    _mav_put_uint8_t(buf, 12, pid_control);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PID_PARAMS_LEN);
#else
    mavlink_pid_params_t packet;
    packet.KP = KP;
    packet.KI = KI;
    packet.KD = KD;
    packet.pid_control = pid_control;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PID_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PID_PARAMS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PID_PARAMS_MIN_LEN, MAVLINK_MSG_ID_PID_PARAMS_LEN, MAVLINK_MSG_ID_PID_PARAMS_CRC);
}

/**
 * @brief Encode a pid_params struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pid_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pid_params_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pid_params_t* pid_params)
{
    return mavlink_msg_pid_params_pack(system_id, component_id, msg, pid_params->pid_control, pid_params->KP, pid_params->KI, pid_params->KD);
}

/**
 * @brief Encode a pid_params struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pid_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pid_params_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pid_params_t* pid_params)
{
    return mavlink_msg_pid_params_pack_chan(system_id, component_id, chan, msg, pid_params->pid_control, pid_params->KP, pid_params->KI, pid_params->KD);
}

/**
 * @brief Send a pid_params message
 * @param chan MAVLink channel to send the message
 *
 * @param pid_control  Object that PID control
 * @param KP  KP
 * @param KI  KI
 * @param KD  KD
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pid_params_send(mavlink_channel_t chan, uint8_t pid_control, float KP, float KI, float KD)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PID_PARAMS_LEN];
    _mav_put_float(buf, 0, KP);
    _mav_put_float(buf, 4, KI);
    _mav_put_float(buf, 8, KD);
    _mav_put_uint8_t(buf, 12, pid_control);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_PARAMS, buf, MAVLINK_MSG_ID_PID_PARAMS_MIN_LEN, MAVLINK_MSG_ID_PID_PARAMS_LEN, MAVLINK_MSG_ID_PID_PARAMS_CRC);
#else
    mavlink_pid_params_t packet;
    packet.KP = KP;
    packet.KI = KI;
    packet.KD = KD;
    packet.pid_control = pid_control;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_PARAMS, (const char *)&packet, MAVLINK_MSG_ID_PID_PARAMS_MIN_LEN, MAVLINK_MSG_ID_PID_PARAMS_LEN, MAVLINK_MSG_ID_PID_PARAMS_CRC);
#endif
}

/**
 * @brief Send a pid_params message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pid_params_send_struct(mavlink_channel_t chan, const mavlink_pid_params_t* pid_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pid_params_send(chan, pid_params->pid_control, pid_params->KP, pid_params->KI, pid_params->KD);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_PARAMS, (const char *)pid_params, MAVLINK_MSG_ID_PID_PARAMS_MIN_LEN, MAVLINK_MSG_ID_PID_PARAMS_LEN, MAVLINK_MSG_ID_PID_PARAMS_CRC);
#endif
}

#if MAVLINK_MSG_ID_PID_PARAMS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pid_params_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t pid_control, float KP, float KI, float KD)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, KP);
    _mav_put_float(buf, 4, KI);
    _mav_put_float(buf, 8, KD);
    _mav_put_uint8_t(buf, 12, pid_control);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_PARAMS, buf, MAVLINK_MSG_ID_PID_PARAMS_MIN_LEN, MAVLINK_MSG_ID_PID_PARAMS_LEN, MAVLINK_MSG_ID_PID_PARAMS_CRC);
#else
    mavlink_pid_params_t *packet = (mavlink_pid_params_t *)msgbuf;
    packet->KP = KP;
    packet->KI = KI;
    packet->KD = KD;
    packet->pid_control = pid_control;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_PARAMS, (const char *)packet, MAVLINK_MSG_ID_PID_PARAMS_MIN_LEN, MAVLINK_MSG_ID_PID_PARAMS_LEN, MAVLINK_MSG_ID_PID_PARAMS_CRC);
#endif
}
#endif

#endif

// MESSAGE PID_PARAMS UNPACKING


/**
 * @brief Get field pid_control from pid_params message
 *
 * @return  Object that PID control
 */
static inline uint8_t mavlink_msg_pid_params_get_pid_control(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field KP from pid_params message
 *
 * @return  KP
 */
static inline float mavlink_msg_pid_params_get_KP(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field KI from pid_params message
 *
 * @return  KI
 */
static inline float mavlink_msg_pid_params_get_KI(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field KD from pid_params message
 *
 * @return  KD
 */
static inline float mavlink_msg_pid_params_get_KD(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a pid_params message into a struct
 *
 * @param msg The message to decode
 * @param pid_params C-struct to decode the message contents into
 */
static inline void mavlink_msg_pid_params_decode(const mavlink_message_t* msg, mavlink_pid_params_t* pid_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pid_params->KP = mavlink_msg_pid_params_get_KP(msg);
    pid_params->KI = mavlink_msg_pid_params_get_KI(msg);
    pid_params->KD = mavlink_msg_pid_params_get_KD(msg);
    pid_params->pid_control = mavlink_msg_pid_params_get_pid_control(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PID_PARAMS_LEN? msg->len : MAVLINK_MSG_ID_PID_PARAMS_LEN;
        memset(pid_params, 0, MAVLINK_MSG_ID_PID_PARAMS_LEN);
    memcpy(pid_params, _MAV_PAYLOAD(msg), len);
#endif
}
