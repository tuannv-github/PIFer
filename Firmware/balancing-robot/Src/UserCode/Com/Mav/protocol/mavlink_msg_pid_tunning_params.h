#pragma once
// MESSAGE PID_TUNNING_PARAMS PACKING

#define MAVLINK_MSG_ID_PID_TUNNING_PARAMS 11

MAVPACKED(
typedef struct __mavlink_pid_tunning_params_t {
 float whe_KP; /*<  Wheel velocity control KP*/
 float whe_KI; /*<  Wheel velocity control KI*/
 float whe_KD; /*<  Wheel velocity control KD*/
 float sta_KP; /*<  Stability control KP*/
 float sta_KI; /*<  Stability control KI*/
 float sta_KD; /*<  Stability control KD*/
 float rob_KP; /*<  Robot velocity control KP*/
 float rob_KI; /*<  Robot control KI*/
 float rob_KD; /*<  Robot control KD*/
}) mavlink_pid_tunning_params_t;

#define MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN 36
#define MAVLINK_MSG_ID_PID_TUNNING_PARAMS_MIN_LEN 36
#define MAVLINK_MSG_ID_11_LEN 36
#define MAVLINK_MSG_ID_11_MIN_LEN 36

#define MAVLINK_MSG_ID_PID_TUNNING_PARAMS_CRC 13
#define MAVLINK_MSG_ID_11_CRC 13



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PID_TUNNING_PARAMS { \
    11, \
    "PID_TUNNING_PARAMS", \
    9, \
    {  { "whe_KP", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_pid_tunning_params_t, whe_KP) }, \
         { "whe_KI", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_pid_tunning_params_t, whe_KI) }, \
         { "whe_KD", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_pid_tunning_params_t, whe_KD) }, \
         { "sta_KP", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_pid_tunning_params_t, sta_KP) }, \
         { "sta_KI", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_pid_tunning_params_t, sta_KI) }, \
         { "sta_KD", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_pid_tunning_params_t, sta_KD) }, \
         { "rob_KP", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_pid_tunning_params_t, rob_KP) }, \
         { "rob_KI", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_pid_tunning_params_t, rob_KI) }, \
         { "rob_KD", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_pid_tunning_params_t, rob_KD) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PID_TUNNING_PARAMS { \
    "PID_TUNNING_PARAMS", \
    9, \
    {  { "whe_KP", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_pid_tunning_params_t, whe_KP) }, \
         { "whe_KI", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_pid_tunning_params_t, whe_KI) }, \
         { "whe_KD", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_pid_tunning_params_t, whe_KD) }, \
         { "sta_KP", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_pid_tunning_params_t, sta_KP) }, \
         { "sta_KI", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_pid_tunning_params_t, sta_KI) }, \
         { "sta_KD", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_pid_tunning_params_t, sta_KD) }, \
         { "rob_KP", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_pid_tunning_params_t, rob_KP) }, \
         { "rob_KI", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_pid_tunning_params_t, rob_KI) }, \
         { "rob_KD", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_pid_tunning_params_t, rob_KD) }, \
         } \
}
#endif

/**
 * @brief Pack a pid_tunning_params message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param whe_KP  Wheel velocity control KP
 * @param whe_KI  Wheel velocity control KI
 * @param whe_KD  Wheel velocity control KD
 * @param sta_KP  Stability control KP
 * @param sta_KI  Stability control KI
 * @param sta_KD  Stability control KD
 * @param rob_KP  Robot velocity control KP
 * @param rob_KI  Robot control KI
 * @param rob_KD  Robot control KD
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_tunning_params_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float whe_KP, float whe_KI, float whe_KD, float sta_KP, float sta_KI, float sta_KD, float rob_KP, float rob_KI, float rob_KD)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN];
    _mav_put_float(buf, 0, whe_KP);
    _mav_put_float(buf, 4, whe_KI);
    _mav_put_float(buf, 8, whe_KD);
    _mav_put_float(buf, 12, sta_KP);
    _mav_put_float(buf, 16, sta_KI);
    _mav_put_float(buf, 20, sta_KD);
    _mav_put_float(buf, 24, rob_KP);
    _mav_put_float(buf, 28, rob_KI);
    _mav_put_float(buf, 32, rob_KD);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN);
#else
    mavlink_pid_tunning_params_t packet;
    packet.whe_KP = whe_KP;
    packet.whe_KI = whe_KI;
    packet.whe_KD = whe_KD;
    packet.sta_KP = sta_KP;
    packet.sta_KI = sta_KI;
    packet.sta_KD = sta_KD;
    packet.rob_KP = rob_KP;
    packet.rob_KI = rob_KI;
    packet.rob_KD = rob_KD;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PID_TUNNING_PARAMS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_MIN_LEN, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_CRC);
}

/**
 * @brief Pack a pid_tunning_params message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param whe_KP  Wheel velocity control KP
 * @param whe_KI  Wheel velocity control KI
 * @param whe_KD  Wheel velocity control KD
 * @param sta_KP  Stability control KP
 * @param sta_KI  Stability control KI
 * @param sta_KD  Stability control KD
 * @param rob_KP  Robot velocity control KP
 * @param rob_KI  Robot control KI
 * @param rob_KD  Robot control KD
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_tunning_params_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float whe_KP,float whe_KI,float whe_KD,float sta_KP,float sta_KI,float sta_KD,float rob_KP,float rob_KI,float rob_KD)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN];
    _mav_put_float(buf, 0, whe_KP);
    _mav_put_float(buf, 4, whe_KI);
    _mav_put_float(buf, 8, whe_KD);
    _mav_put_float(buf, 12, sta_KP);
    _mav_put_float(buf, 16, sta_KI);
    _mav_put_float(buf, 20, sta_KD);
    _mav_put_float(buf, 24, rob_KP);
    _mav_put_float(buf, 28, rob_KI);
    _mav_put_float(buf, 32, rob_KD);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN);
#else
    mavlink_pid_tunning_params_t packet;
    packet.whe_KP = whe_KP;
    packet.whe_KI = whe_KI;
    packet.whe_KD = whe_KD;
    packet.sta_KP = sta_KP;
    packet.sta_KI = sta_KI;
    packet.sta_KD = sta_KD;
    packet.rob_KP = rob_KP;
    packet.rob_KI = rob_KI;
    packet.rob_KD = rob_KD;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PID_TUNNING_PARAMS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_MIN_LEN, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_CRC);
}

/**
 * @brief Encode a pid_tunning_params struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pid_tunning_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pid_tunning_params_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pid_tunning_params_t* pid_tunning_params)
{
    return mavlink_msg_pid_tunning_params_pack(system_id, component_id, msg, pid_tunning_params->whe_KP, pid_tunning_params->whe_KI, pid_tunning_params->whe_KD, pid_tunning_params->sta_KP, pid_tunning_params->sta_KI, pid_tunning_params->sta_KD, pid_tunning_params->rob_KP, pid_tunning_params->rob_KI, pid_tunning_params->rob_KD);
}

/**
 * @brief Encode a pid_tunning_params struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pid_tunning_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pid_tunning_params_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pid_tunning_params_t* pid_tunning_params)
{
    return mavlink_msg_pid_tunning_params_pack_chan(system_id, component_id, chan, msg, pid_tunning_params->whe_KP, pid_tunning_params->whe_KI, pid_tunning_params->whe_KD, pid_tunning_params->sta_KP, pid_tunning_params->sta_KI, pid_tunning_params->sta_KD, pid_tunning_params->rob_KP, pid_tunning_params->rob_KI, pid_tunning_params->rob_KD);
}

/**
 * @brief Send a pid_tunning_params message
 * @param chan MAVLink channel to send the message
 *
 * @param whe_KP  Wheel velocity control KP
 * @param whe_KI  Wheel velocity control KI
 * @param whe_KD  Wheel velocity control KD
 * @param sta_KP  Stability control KP
 * @param sta_KI  Stability control KI
 * @param sta_KD  Stability control KD
 * @param rob_KP  Robot velocity control KP
 * @param rob_KI  Robot control KI
 * @param rob_KD  Robot control KD
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pid_tunning_params_send(mavlink_channel_t chan, float whe_KP, float whe_KI, float whe_KD, float sta_KP, float sta_KI, float sta_KD, float rob_KP, float rob_KI, float rob_KD)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN];
    _mav_put_float(buf, 0, whe_KP);
    _mav_put_float(buf, 4, whe_KI);
    _mav_put_float(buf, 8, whe_KD);
    _mav_put_float(buf, 12, sta_KP);
    _mav_put_float(buf, 16, sta_KI);
    _mav_put_float(buf, 20, sta_KD);
    _mav_put_float(buf, 24, rob_KP);
    _mav_put_float(buf, 28, rob_KI);
    _mav_put_float(buf, 32, rob_KD);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_TUNNING_PARAMS, buf, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_MIN_LEN, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_CRC);
#else
    mavlink_pid_tunning_params_t packet;
    packet.whe_KP = whe_KP;
    packet.whe_KI = whe_KI;
    packet.whe_KD = whe_KD;
    packet.sta_KP = sta_KP;
    packet.sta_KI = sta_KI;
    packet.sta_KD = sta_KD;
    packet.rob_KP = rob_KP;
    packet.rob_KI = rob_KI;
    packet.rob_KD = rob_KD;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_TUNNING_PARAMS, (const char *)&packet, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_MIN_LEN, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_CRC);
#endif
}

/**
 * @brief Send a pid_tunning_params message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pid_tunning_params_send_struct(mavlink_channel_t chan, const mavlink_pid_tunning_params_t* pid_tunning_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pid_tunning_params_send(chan, pid_tunning_params->whe_KP, pid_tunning_params->whe_KI, pid_tunning_params->whe_KD, pid_tunning_params->sta_KP, pid_tunning_params->sta_KI, pid_tunning_params->sta_KD, pid_tunning_params->rob_KP, pid_tunning_params->rob_KI, pid_tunning_params->rob_KD);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_TUNNING_PARAMS, (const char *)pid_tunning_params, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_MIN_LEN, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_CRC);
#endif
}

#if MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pid_tunning_params_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float whe_KP, float whe_KI, float whe_KD, float sta_KP, float sta_KI, float sta_KD, float rob_KP, float rob_KI, float rob_KD)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, whe_KP);
    _mav_put_float(buf, 4, whe_KI);
    _mav_put_float(buf, 8, whe_KD);
    _mav_put_float(buf, 12, sta_KP);
    _mav_put_float(buf, 16, sta_KI);
    _mav_put_float(buf, 20, sta_KD);
    _mav_put_float(buf, 24, rob_KP);
    _mav_put_float(buf, 28, rob_KI);
    _mav_put_float(buf, 32, rob_KD);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_TUNNING_PARAMS, buf, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_MIN_LEN, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_CRC);
#else
    mavlink_pid_tunning_params_t *packet = (mavlink_pid_tunning_params_t *)msgbuf;
    packet->whe_KP = whe_KP;
    packet->whe_KI = whe_KI;
    packet->whe_KD = whe_KD;
    packet->sta_KP = sta_KP;
    packet->sta_KI = sta_KI;
    packet->sta_KD = sta_KD;
    packet->rob_KP = rob_KP;
    packet->rob_KI = rob_KI;
    packet->rob_KD = rob_KD;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_TUNNING_PARAMS, (const char *)packet, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_MIN_LEN, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_CRC);
#endif
}
#endif

#endif

// MESSAGE PID_TUNNING_PARAMS UNPACKING


/**
 * @brief Get field whe_KP from pid_tunning_params message
 *
 * @return  Wheel velocity control KP
 */
static inline float mavlink_msg_pid_tunning_params_get_whe_KP(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field whe_KI from pid_tunning_params message
 *
 * @return  Wheel velocity control KI
 */
static inline float mavlink_msg_pid_tunning_params_get_whe_KI(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field whe_KD from pid_tunning_params message
 *
 * @return  Wheel velocity control KD
 */
static inline float mavlink_msg_pid_tunning_params_get_whe_KD(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field sta_KP from pid_tunning_params message
 *
 * @return  Stability control KP
 */
static inline float mavlink_msg_pid_tunning_params_get_sta_KP(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field sta_KI from pid_tunning_params message
 *
 * @return  Stability control KI
 */
static inline float mavlink_msg_pid_tunning_params_get_sta_KI(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field sta_KD from pid_tunning_params message
 *
 * @return  Stability control KD
 */
static inline float mavlink_msg_pid_tunning_params_get_sta_KD(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field rob_KP from pid_tunning_params message
 *
 * @return  Robot velocity control KP
 */
static inline float mavlink_msg_pid_tunning_params_get_rob_KP(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field rob_KI from pid_tunning_params message
 *
 * @return  Robot control KI
 */
static inline float mavlink_msg_pid_tunning_params_get_rob_KI(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field rob_KD from pid_tunning_params message
 *
 * @return  Robot control KD
 */
static inline float mavlink_msg_pid_tunning_params_get_rob_KD(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Decode a pid_tunning_params message into a struct
 *
 * @param msg The message to decode
 * @param pid_tunning_params C-struct to decode the message contents into
 */
static inline void mavlink_msg_pid_tunning_params_decode(const mavlink_message_t* msg, mavlink_pid_tunning_params_t* pid_tunning_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pid_tunning_params->whe_KP = mavlink_msg_pid_tunning_params_get_whe_KP(msg);
    pid_tunning_params->whe_KI = mavlink_msg_pid_tunning_params_get_whe_KI(msg);
    pid_tunning_params->whe_KD = mavlink_msg_pid_tunning_params_get_whe_KD(msg);
    pid_tunning_params->sta_KP = mavlink_msg_pid_tunning_params_get_sta_KP(msg);
    pid_tunning_params->sta_KI = mavlink_msg_pid_tunning_params_get_sta_KI(msg);
    pid_tunning_params->sta_KD = mavlink_msg_pid_tunning_params_get_sta_KD(msg);
    pid_tunning_params->rob_KP = mavlink_msg_pid_tunning_params_get_rob_KP(msg);
    pid_tunning_params->rob_KI = mavlink_msg_pid_tunning_params_get_rob_KI(msg);
    pid_tunning_params->rob_KD = mavlink_msg_pid_tunning_params_get_rob_KD(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN? msg->len : MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN;
        memset(pid_tunning_params, 0, MAVLINK_MSG_ID_PID_TUNNING_PARAMS_LEN);
    memcpy(pid_tunning_params, _MAV_PAYLOAD(msg), len);
#endif
}
