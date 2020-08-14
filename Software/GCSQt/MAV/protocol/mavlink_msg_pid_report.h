#pragma once
// MESSAGE PID_REPORT PACKING

#define MAVLINK_MSG_ID_PID_REPORT 14

MAVPACKED(
typedef struct __mavlink_pid_report_t {
 float sp; /*<  Set point*/
 float fb; /*<  Feed back*/
 float P_Part; /*<  P part*/
 float I_Part; /*<  I part*/
 float D_Part; /*<  D part*/
 float U; /*<  Output*/
 uint8_t pid_control; /*<  Object that PID control*/
}) mavlink_pid_report_t;

#define MAVLINK_MSG_ID_PID_REPORT_LEN 25
#define MAVLINK_MSG_ID_PID_REPORT_MIN_LEN 25
#define MAVLINK_MSG_ID_14_LEN 25
#define MAVLINK_MSG_ID_14_MIN_LEN 25

#define MAVLINK_MSG_ID_PID_REPORT_CRC 198
#define MAVLINK_MSG_ID_14_CRC 198



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PID_REPORT { \
    14, \
    "PID_REPORT", \
    7, \
    {  { "pid_control", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_pid_report_t, pid_control) }, \
         { "sp", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_pid_report_t, sp) }, \
         { "fb", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_pid_report_t, fb) }, \
         { "P_Part", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_pid_report_t, P_Part) }, \
         { "I_Part", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_pid_report_t, I_Part) }, \
         { "D_Part", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_pid_report_t, D_Part) }, \
         { "U", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_pid_report_t, U) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PID_REPORT { \
    "PID_REPORT", \
    7, \
    {  { "pid_control", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_pid_report_t, pid_control) }, \
         { "sp", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_pid_report_t, sp) }, \
         { "fb", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_pid_report_t, fb) }, \
         { "P_Part", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_pid_report_t, P_Part) }, \
         { "I_Part", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_pid_report_t, I_Part) }, \
         { "D_Part", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_pid_report_t, D_Part) }, \
         { "U", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_pid_report_t, U) }, \
         } \
}
#endif

/**
 * @brief Pack a pid_report message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param pid_control  Object that PID control
 * @param sp  Set point
 * @param fb  Feed back
 * @param P_Part  P part
 * @param I_Part  I part
 * @param D_Part  D part
 * @param U  Output
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_report_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t pid_control, float sp, float fb, float P_Part, float I_Part, float D_Part, float U)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PID_REPORT_LEN];
    _mav_put_float(buf, 0, sp);
    _mav_put_float(buf, 4, fb);
    _mav_put_float(buf, 8, P_Part);
    _mav_put_float(buf, 12, I_Part);
    _mav_put_float(buf, 16, D_Part);
    _mav_put_float(buf, 20, U);
    _mav_put_uint8_t(buf, 24, pid_control);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PID_REPORT_LEN);
#else
    mavlink_pid_report_t packet;
    packet.sp = sp;
    packet.fb = fb;
    packet.P_Part = P_Part;
    packet.I_Part = I_Part;
    packet.D_Part = D_Part;
    packet.U = U;
    packet.pid_control = pid_control;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PID_REPORT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PID_REPORT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PID_REPORT_MIN_LEN, MAVLINK_MSG_ID_PID_REPORT_LEN, MAVLINK_MSG_ID_PID_REPORT_CRC);
}

/**
 * @brief Pack a pid_report message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pid_control  Object that PID control
 * @param sp  Set point
 * @param fb  Feed back
 * @param P_Part  P part
 * @param I_Part  I part
 * @param D_Part  D part
 * @param U  Output
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_report_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t pid_control,float sp,float fb,float P_Part,float I_Part,float D_Part,float U)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PID_REPORT_LEN];
    _mav_put_float(buf, 0, sp);
    _mav_put_float(buf, 4, fb);
    _mav_put_float(buf, 8, P_Part);
    _mav_put_float(buf, 12, I_Part);
    _mav_put_float(buf, 16, D_Part);
    _mav_put_float(buf, 20, U);
    _mav_put_uint8_t(buf, 24, pid_control);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PID_REPORT_LEN);
#else
    mavlink_pid_report_t packet;
    packet.sp = sp;
    packet.fb = fb;
    packet.P_Part = P_Part;
    packet.I_Part = I_Part;
    packet.D_Part = D_Part;
    packet.U = U;
    packet.pid_control = pid_control;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PID_REPORT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PID_REPORT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PID_REPORT_MIN_LEN, MAVLINK_MSG_ID_PID_REPORT_LEN, MAVLINK_MSG_ID_PID_REPORT_CRC);
}

/**
 * @brief Encode a pid_report struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pid_report C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pid_report_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pid_report_t* pid_report)
{
    return mavlink_msg_pid_report_pack(system_id, component_id, msg, pid_report->pid_control, pid_report->sp, pid_report->fb, pid_report->P_Part, pid_report->I_Part, pid_report->D_Part, pid_report->U);
}

/**
 * @brief Encode a pid_report struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pid_report C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pid_report_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pid_report_t* pid_report)
{
    return mavlink_msg_pid_report_pack_chan(system_id, component_id, chan, msg, pid_report->pid_control, pid_report->sp, pid_report->fb, pid_report->P_Part, pid_report->I_Part, pid_report->D_Part, pid_report->U);
}

/**
 * @brief Send a pid_report message
 * @param chan MAVLink channel to send the message
 *
 * @param pid_control  Object that PID control
 * @param sp  Set point
 * @param fb  Feed back
 * @param P_Part  P part
 * @param I_Part  I part
 * @param D_Part  D part
 * @param U  Output
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pid_report_send(mavlink_channel_t chan, uint8_t pid_control, float sp, float fb, float P_Part, float I_Part, float D_Part, float U)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PID_REPORT_LEN];
    _mav_put_float(buf, 0, sp);
    _mav_put_float(buf, 4, fb);
    _mav_put_float(buf, 8, P_Part);
    _mav_put_float(buf, 12, I_Part);
    _mav_put_float(buf, 16, D_Part);
    _mav_put_float(buf, 20, U);
    _mav_put_uint8_t(buf, 24, pid_control);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_REPORT, buf, MAVLINK_MSG_ID_PID_REPORT_MIN_LEN, MAVLINK_MSG_ID_PID_REPORT_LEN, MAVLINK_MSG_ID_PID_REPORT_CRC);
#else
    mavlink_pid_report_t packet;
    packet.sp = sp;
    packet.fb = fb;
    packet.P_Part = P_Part;
    packet.I_Part = I_Part;
    packet.D_Part = D_Part;
    packet.U = U;
    packet.pid_control = pid_control;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_REPORT, (const char *)&packet, MAVLINK_MSG_ID_PID_REPORT_MIN_LEN, MAVLINK_MSG_ID_PID_REPORT_LEN, MAVLINK_MSG_ID_PID_REPORT_CRC);
#endif
}

/**
 * @brief Send a pid_report message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pid_report_send_struct(mavlink_channel_t chan, const mavlink_pid_report_t* pid_report)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pid_report_send(chan, pid_report->pid_control, pid_report->sp, pid_report->fb, pid_report->P_Part, pid_report->I_Part, pid_report->D_Part, pid_report->U);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_REPORT, (const char *)pid_report, MAVLINK_MSG_ID_PID_REPORT_MIN_LEN, MAVLINK_MSG_ID_PID_REPORT_LEN, MAVLINK_MSG_ID_PID_REPORT_CRC);
#endif
}

#if MAVLINK_MSG_ID_PID_REPORT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pid_report_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t pid_control, float sp, float fb, float P_Part, float I_Part, float D_Part, float U)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, sp);
    _mav_put_float(buf, 4, fb);
    _mav_put_float(buf, 8, P_Part);
    _mav_put_float(buf, 12, I_Part);
    _mav_put_float(buf, 16, D_Part);
    _mav_put_float(buf, 20, U);
    _mav_put_uint8_t(buf, 24, pid_control);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_REPORT, buf, MAVLINK_MSG_ID_PID_REPORT_MIN_LEN, MAVLINK_MSG_ID_PID_REPORT_LEN, MAVLINK_MSG_ID_PID_REPORT_CRC);
#else
    mavlink_pid_report_t *packet = (mavlink_pid_report_t *)msgbuf;
    packet->sp = sp;
    packet->fb = fb;
    packet->P_Part = P_Part;
    packet->I_Part = I_Part;
    packet->D_Part = D_Part;
    packet->U = U;
    packet->pid_control = pid_control;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_REPORT, (const char *)packet, MAVLINK_MSG_ID_PID_REPORT_MIN_LEN, MAVLINK_MSG_ID_PID_REPORT_LEN, MAVLINK_MSG_ID_PID_REPORT_CRC);
#endif
}
#endif

#endif

// MESSAGE PID_REPORT UNPACKING


/**
 * @brief Get field pid_control from pid_report message
 *
 * @return  Object that PID control
 */
static inline uint8_t mavlink_msg_pid_report_get_pid_control(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field sp from pid_report message
 *
 * @return  Set point
 */
static inline float mavlink_msg_pid_report_get_sp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field fb from pid_report message
 *
 * @return  Feed back
 */
static inline float mavlink_msg_pid_report_get_fb(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field P_Part from pid_report message
 *
 * @return  P part
 */
static inline float mavlink_msg_pid_report_get_P_Part(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field I_Part from pid_report message
 *
 * @return  I part
 */
static inline float mavlink_msg_pid_report_get_I_Part(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field D_Part from pid_report message
 *
 * @return  D part
 */
static inline float mavlink_msg_pid_report_get_D_Part(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field U from pid_report message
 *
 * @return  Output
 */
static inline float mavlink_msg_pid_report_get_U(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a pid_report message into a struct
 *
 * @param msg The message to decode
 * @param pid_report C-struct to decode the message contents into
 */
static inline void mavlink_msg_pid_report_decode(const mavlink_message_t* msg, mavlink_pid_report_t* pid_report)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pid_report->sp = mavlink_msg_pid_report_get_sp(msg);
    pid_report->fb = mavlink_msg_pid_report_get_fb(msg);
    pid_report->P_Part = mavlink_msg_pid_report_get_P_Part(msg);
    pid_report->I_Part = mavlink_msg_pid_report_get_I_Part(msg);
    pid_report->D_Part = mavlink_msg_pid_report_get_D_Part(msg);
    pid_report->U = mavlink_msg_pid_report_get_U(msg);
    pid_report->pid_control = mavlink_msg_pid_report_get_pid_control(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PID_REPORT_LEN? msg->len : MAVLINK_MSG_ID_PID_REPORT_LEN;
        memset(pid_report, 0, MAVLINK_MSG_ID_PID_REPORT_LEN);
    memcpy(pid_report, _MAV_PAYLOAD(msg), len);
#endif
}
