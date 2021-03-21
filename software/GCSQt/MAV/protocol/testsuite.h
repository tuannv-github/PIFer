/** @file
 *    @brief MAVLink comm protocol testsuite generated from protocol.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef PROTOCOL_TESTSUITE_H
#define PROTOCOL_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_protocol(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_protocol(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_respond(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RESPOND >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_respond_t packet_in = {
        5
    };
    mavlink_respond_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.respond = packet_in.respond;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RESPOND_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RESPOND_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_respond_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_respond_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_respond_pack(system_id, component_id, &msg , packet1.respond );
    mavlink_msg_respond_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_respond_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.respond );
    mavlink_msg_respond_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_respond_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_respond_send(MAVLINK_COMM_1 , packet1.respond );
    mavlink_msg_respond_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cmd_change_mode(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CMD_CHANGE_MODE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cmd_change_mode_t packet_in = {
        5
    };
    mavlink_cmd_change_mode_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.cmd_change_mode = packet_in.cmd_change_mode;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CMD_CHANGE_MODE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CMD_CHANGE_MODE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_change_mode_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cmd_change_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_change_mode_pack(system_id, component_id, &msg , packet1.cmd_change_mode );
    mavlink_msg_cmd_change_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_change_mode_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.cmd_change_mode );
    mavlink_msg_cmd_change_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cmd_change_mode_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_change_mode_send(MAVLINK_COMM_1 , packet1.cmd_change_mode );
    mavlink_msg_cmd_change_mode_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cmd_params(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CMD_PARAMS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cmd_params_t packet_in = {
        5
    };
    mavlink_cmd_params_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.cmd_params = packet_in.cmd_params;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CMD_PARAMS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CMD_PARAMS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_params_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cmd_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_params_pack(system_id, component_id, &msg , packet1.cmd_params );
    mavlink_msg_cmd_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_params_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.cmd_params );
    mavlink_msg_cmd_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cmd_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_params_send(MAVLINK_COMM_1 , packet1.cmd_params );
    mavlink_msg_cmd_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cmd_velocity(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CMD_VELOCITY >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cmd_velocity_t packet_in = {
        17.0,45.0
    };
    mavlink_cmd_velocity_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.v = packet_in.v;
        packet1.omega = packet_in.omega;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CMD_VELOCITY_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CMD_VELOCITY_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_velocity_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cmd_velocity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_velocity_pack(system_id, component_id, &msg , packet1.v , packet1.omega );
    mavlink_msg_cmd_velocity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_velocity_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.v , packet1.omega );
    mavlink_msg_cmd_velocity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cmd_velocity_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_velocity_send(MAVLINK_COMM_1 , packet1.v , packet1.omega );
    mavlink_msg_cmd_velocity_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_evt_tilt(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_EVT_TILT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_evt_tilt_t packet_in = {
        17.0
    };
    mavlink_evt_tilt_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.tilt = packet_in.tilt;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_EVT_TILT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_EVT_TILT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_tilt_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_evt_tilt_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_tilt_pack(system_id, component_id, &msg , packet1.tilt );
    mavlink_msg_evt_tilt_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_tilt_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.tilt );
    mavlink_msg_evt_tilt_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_evt_tilt_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_tilt_send(MAVLINK_COMM_1 , packet1.tilt );
    mavlink_msg_evt_tilt_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_evt_rpy(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_EVT_RPY >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_evt_rpy_t packet_in = {
        17.0,45.0,73.0
    };
    mavlink_evt_rpy_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_EVT_RPY_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_EVT_RPY_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_rpy_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_evt_rpy_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_rpy_pack(system_id, component_id, &msg , packet1.roll , packet1.pitch , packet1.yaw );
    mavlink_msg_evt_rpy_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_rpy_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.roll , packet1.pitch , packet1.yaw );
    mavlink_msg_evt_rpy_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_evt_rpy_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_rpy_send(MAVLINK_COMM_1 , packet1.roll , packet1.pitch , packet1.yaw );
    mavlink_msg_evt_rpy_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_evt_sensor(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_EVT_SENSOR >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_evt_sensor_t packet_in = {
        5
    };
    mavlink_evt_sensor_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.imu_status = packet_in.imu_status;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_EVT_SENSOR_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_EVT_SENSOR_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_sensor_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_evt_sensor_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_sensor_pack(system_id, component_id, &msg , packet1.imu_status );
    mavlink_msg_evt_sensor_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_sensor_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.imu_status );
    mavlink_msg_evt_sensor_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_evt_sensor_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_sensor_send(MAVLINK_COMM_1 , packet1.imu_status );
    mavlink_msg_evt_sensor_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_motor_speed(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MOTOR_SPEED >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_motor_speed_t packet_in = {
        17235,17339
    };
    mavlink_motor_speed_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.motor_speed_0 = packet_in.motor_speed_0;
        packet1.motor_speed_1 = packet_in.motor_speed_1;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MOTOR_SPEED_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MOTOR_SPEED_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_motor_speed_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_motor_speed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_motor_speed_pack(system_id, component_id, &msg , packet1.motor_speed_0 , packet1.motor_speed_1 );
    mavlink_msg_motor_speed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_motor_speed_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.motor_speed_0 , packet1.motor_speed_1 );
    mavlink_msg_motor_speed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_motor_speed_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_motor_speed_send(MAVLINK_COMM_1 , packet1.motor_speed_0 , packet1.motor_speed_1 );
    mavlink_msg_motor_speed_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_hw_params(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_HW_PARAMS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_hw_params_t packet_in = {
        17235,17339,17443,17547,29,96,163,230,41
    };
    mavlink_hw_params_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.motor0_pos_deadband = packet_in.motor0_pos_deadband;
        packet1.motor0_neg_deadband = packet_in.motor0_neg_deadband;
        packet1.motor1_pos_deadband = packet_in.motor1_pos_deadband;
        packet1.motor1_neg_deadband = packet_in.motor1_neg_deadband;
        packet1.motor0_invert = packet_in.motor0_invert;
        packet1.motor1_invert = packet_in.motor1_invert;
        packet1.encoder0_invert = packet_in.encoder0_invert;
        packet1.encoder1_invert = packet_in.encoder1_invert;
        packet1.encoder_exchange = packet_in.encoder_exchange;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_HW_PARAMS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_HW_PARAMS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_hw_params_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_hw_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_hw_params_pack(system_id, component_id, &msg , packet1.motor0_invert , packet1.motor1_invert , packet1.encoder0_invert , packet1.encoder1_invert , packet1.encoder_exchange , packet1.motor0_pos_deadband , packet1.motor0_neg_deadband , packet1.motor1_pos_deadband , packet1.motor1_neg_deadband );
    mavlink_msg_hw_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_hw_params_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.motor0_invert , packet1.motor1_invert , packet1.encoder0_invert , packet1.encoder1_invert , packet1.encoder_exchange , packet1.motor0_pos_deadband , packet1.motor0_neg_deadband , packet1.motor1_pos_deadband , packet1.motor1_neg_deadband );
    mavlink_msg_hw_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_hw_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_hw_params_send(MAVLINK_COMM_1 , packet1.motor0_invert , packet1.motor1_invert , packet1.encoder0_invert , packet1.encoder1_invert , packet1.encoder_exchange , packet1.motor0_pos_deadband , packet1.motor0_neg_deadband , packet1.motor1_pos_deadband , packet1.motor1_neg_deadband );
    mavlink_msg_hw_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gyro_params(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GYRO_PARAMS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gyro_params_t packet_in = {
        17.0,45.0,73.0
    };
    mavlink_gyro_params_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.gyro_bias_x = packet_in.gyro_bias_x;
        packet1.gyro_bias_y = packet_in.gyro_bias_y;
        packet1.gyro_bias_z = packet_in.gyro_bias_z;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GYRO_PARAMS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GYRO_PARAMS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gyro_params_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gyro_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gyro_params_pack(system_id, component_id, &msg , packet1.gyro_bias_x , packet1.gyro_bias_y , packet1.gyro_bias_z );
    mavlink_msg_gyro_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gyro_params_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.gyro_bias_x , packet1.gyro_bias_y , packet1.gyro_bias_z );
    mavlink_msg_gyro_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gyro_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gyro_params_send(MAVLINK_COMM_1 , packet1.gyro_bias_x , packet1.gyro_bias_y , packet1.gyro_bias_z );
    mavlink_msg_gyro_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_accel_params(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ACCEL_PARAMS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_accel_params_t packet_in = {
        17.0,45.0,73.0
    };
    mavlink_accel_params_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.accel_bias_x = packet_in.accel_bias_x;
        packet1.accel_bias_y = packet_in.accel_bias_y;
        packet1.accel_bias_z = packet_in.accel_bias_z;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ACCEL_PARAMS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ACCEL_PARAMS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_accel_params_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_accel_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_accel_params_pack(system_id, component_id, &msg , packet1.accel_bias_x , packet1.accel_bias_y , packet1.accel_bias_z );
    mavlink_msg_accel_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_accel_params_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.accel_bias_x , packet1.accel_bias_y , packet1.accel_bias_z );
    mavlink_msg_accel_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_accel_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_accel_params_send(MAVLINK_COMM_1 , packet1.accel_bias_x , packet1.accel_bias_y , packet1.accel_bias_z );
    mavlink_msg_accel_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_mag_params(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MAG_PARAMS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mag_params_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0
    };
    mavlink_mag_params_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.mag_bias_x = packet_in.mag_bias_x;
        packet1.mag_bias_y = packet_in.mag_bias_y;
        packet1.mag_bias_z = packet_in.mag_bias_z;
        packet1.mag_scale_x = packet_in.mag_scale_x;
        packet1.mag_scale_y = packet_in.mag_scale_y;
        packet1.mag_scale_z = packet_in.mag_scale_z;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MAG_PARAMS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MAG_PARAMS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mag_params_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mag_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mag_params_pack(system_id, component_id, &msg , packet1.mag_bias_x , packet1.mag_bias_y , packet1.mag_bias_z , packet1.mag_scale_x , packet1.mag_scale_y , packet1.mag_scale_z );
    mavlink_msg_mag_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mag_params_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mag_bias_x , packet1.mag_bias_y , packet1.mag_bias_z , packet1.mag_scale_x , packet1.mag_scale_y , packet1.mag_scale_z );
    mavlink_msg_mag_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mag_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mag_params_send(MAVLINK_COMM_1 , packet1.mag_bias_x , packet1.mag_bias_y , packet1.mag_bias_z , packet1.mag_scale_x , packet1.mag_scale_y , packet1.mag_scale_z );
    mavlink_msg_mag_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_comp_filter_params(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_COMP_FILTER_PARAMS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_comp_filter_params_t packet_in = {
        17.0,45.0,29
    };
    mavlink_comp_filter_params_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.tilt_offset = packet_in.tilt_offset;
        packet1.g_believe = packet_in.g_believe;
        packet1.tilt_type = packet_in.tilt_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_COMP_FILTER_PARAMS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_COMP_FILTER_PARAMS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_comp_filter_params_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_comp_filter_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_comp_filter_params_pack(system_id, component_id, &msg , packet1.tilt_type , packet1.tilt_offset , packet1.g_believe );
    mavlink_msg_comp_filter_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_comp_filter_params_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.tilt_type , packet1.tilt_offset , packet1.g_believe );
    mavlink_msg_comp_filter_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_comp_filter_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_comp_filter_params_send(MAVLINK_COMM_1 , packet1.tilt_type , packet1.tilt_offset , packet1.g_believe );
    mavlink_msg_comp_filter_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_evt_gyro_accel_mag_raw(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_evt_gyro_accel_mag_raw_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0
    };
    mavlink_evt_gyro_accel_mag_raw_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.gx = packet_in.gx;
        packet1.gy = packet_in.gy;
        packet1.gz = packet_in.gz;
        packet1.ax = packet_in.ax;
        packet1.ay = packet_in.ay;
        packet1.az = packet_in.az;
        packet1.mx = packet_in.mx;
        packet1.my = packet_in.my;
        packet1.mz = packet_in.mz;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_gyro_accel_mag_raw_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_evt_gyro_accel_mag_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_gyro_accel_mag_raw_pack(system_id, component_id, &msg , packet1.gx , packet1.gy , packet1.gz , packet1.ax , packet1.ay , packet1.az , packet1.mx , packet1.my , packet1.mz );
    mavlink_msg_evt_gyro_accel_mag_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_gyro_accel_mag_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.gx , packet1.gy , packet1.gz , packet1.ax , packet1.ay , packet1.az , packet1.mx , packet1.my , packet1.mz );
    mavlink_msg_evt_gyro_accel_mag_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_evt_gyro_accel_mag_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_gyro_accel_mag_raw_send(MAVLINK_COMM_1 , packet1.gx , packet1.gy , packet1.gz , packet1.ax , packet1.ay , packet1.az , packet1.mx , packet1.my , packet1.mz );
    mavlink_msg_evt_gyro_accel_mag_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_evt_gyro_accel_mag_calibrated(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_CALIBRATED >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_evt_gyro_accel_mag_calibrated_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0
    };
    mavlink_evt_gyro_accel_mag_calibrated_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.gx = packet_in.gx;
        packet1.gy = packet_in.gy;
        packet1.gz = packet_in.gz;
        packet1.ax = packet_in.ax;
        packet1.ay = packet_in.ay;
        packet1.az = packet_in.az;
        packet1.mx = packet_in.mx;
        packet1.my = packet_in.my;
        packet1.mz = packet_in.mz;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_CALIBRATED_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_CALIBRATED_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_gyro_accel_mag_calibrated_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_evt_gyro_accel_mag_calibrated_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_gyro_accel_mag_calibrated_pack(system_id, component_id, &msg , packet1.gx , packet1.gy , packet1.gz , packet1.ax , packet1.ay , packet1.az , packet1.mx , packet1.my , packet1.mz );
    mavlink_msg_evt_gyro_accel_mag_calibrated_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_gyro_accel_mag_calibrated_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.gx , packet1.gy , packet1.gz , packet1.ax , packet1.ay , packet1.az , packet1.mx , packet1.my , packet1.mz );
    mavlink_msg_evt_gyro_accel_mag_calibrated_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_evt_gyro_accel_mag_calibrated_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_evt_gyro_accel_mag_calibrated_send(MAVLINK_COMM_1 , packet1.gx , packet1.gy , packet1.gz , packet1.ax , packet1.ay , packet1.az , packet1.mx , packet1.my , packet1.mz );
    mavlink_msg_evt_gyro_accel_mag_calibrated_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_pid_params(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_PID_PARAMS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_pid_params_t packet_in = {
        17.0,45.0,73.0,41
    };
    mavlink_pid_params_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.KP = packet_in.KP;
        packet1.KI = packet_in.KI;
        packet1.KD = packet_in.KD;
        packet1.pid_control = packet_in.pid_control;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_PID_PARAMS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_PID_PARAMS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pid_params_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_pid_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pid_params_pack(system_id, component_id, &msg , packet1.pid_control , packet1.KP , packet1.KI , packet1.KD );
    mavlink_msg_pid_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pid_params_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.pid_control , packet1.KP , packet1.KI , packet1.KD );
    mavlink_msg_pid_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_pid_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pid_params_send(MAVLINK_COMM_1 , packet1.pid_control , packet1.KP , packet1.KI , packet1.KD );
    mavlink_msg_pid_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_pid_report(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_PID_REPORT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_pid_report_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,77
    };
    mavlink_pid_report_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.sp = packet_in.sp;
        packet1.fb = packet_in.fb;
        packet1.P_Part = packet_in.P_Part;
        packet1.I_Part = packet_in.I_Part;
        packet1.D_Part = packet_in.D_Part;
        packet1.U = packet_in.U;
        packet1.pid_control = packet_in.pid_control;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_PID_REPORT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_PID_REPORT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pid_report_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_pid_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pid_report_pack(system_id, component_id, &msg , packet1.pid_control , packet1.sp , packet1.fb , packet1.P_Part , packet1.I_Part , packet1.D_Part , packet1.U );
    mavlink_msg_pid_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pid_report_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.pid_control , packet1.sp , packet1.fb , packet1.P_Part , packet1.I_Part , packet1.D_Part , packet1.U );
    mavlink_msg_pid_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_pid_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pid_report_send(MAVLINK_COMM_1 , packet1.pid_control , packet1.sp , packet1.fb , packet1.P_Part , packet1.I_Part , packet1.D_Part , packet1.U );
    mavlink_msg_pid_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_blink(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BLINK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_blink_t packet_in = {
        17235,139
    };
    mavlink_blink_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.uwb_address = packet_in.uwb_address;
        packet1.role = packet_in.role;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BLINK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BLINK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_blink_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_blink_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_blink_pack(system_id, component_id, &msg , packet1.uwb_address , packet1.role );
    mavlink_msg_blink_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_blink_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uwb_address , packet1.role );
    mavlink_msg_blink_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_blink_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_blink_send(MAVLINK_COMM_1 , packet1.uwb_address , packet1.role );
    mavlink_msg_blink_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ble_mesh(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BLE_MESH >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ble_mesh_t packet_in = {
        17235,17339
    };
    mavlink_ble_mesh_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.uwb_address = packet_in.uwb_address;
        packet1.mesh_address = packet_in.mesh_address;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BLE_MESH_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BLE_MESH_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ble_mesh_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ble_mesh_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ble_mesh_pack(system_id, component_id, &msg , packet1.uwb_address , packet1.mesh_address );
    mavlink_msg_ble_mesh_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ble_mesh_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uwb_address , packet1.mesh_address );
    mavlink_msg_ble_mesh_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ble_mesh_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ble_mesh_send(MAVLINK_COMM_1 , packet1.uwb_address , packet1.mesh_address );
    mavlink_msg_ble_mesh_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_onoff(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ONOFF >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_onoff_t packet_in = {
        17235,139
    };
    mavlink_onoff_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.uwb_address = packet_in.uwb_address;
        packet1.value = packet_in.value;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ONOFF_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ONOFF_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_onoff_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_onoff_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_onoff_pack(system_id, component_id, &msg , packet1.uwb_address , packet1.value );
    mavlink_msg_onoff_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_onoff_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uwb_address , packet1.value );
    mavlink_msg_onoff_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_onoff_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_onoff_send(MAVLINK_COMM_1 , packet1.uwb_address , packet1.value );
    mavlink_msg_onoff_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_location(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LOCATION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_location_t packet_in = {
        17.0,45.0,73.0,17859
    };
    mavlink_location_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.location_x = packet_in.location_x;
        packet1.location_y = packet_in.location_y;
        packet1.location_z = packet_in.location_z;
        packet1.uwb_address = packet_in.uwb_address;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LOCATION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LOCATION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_location_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_location_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_location_pack(system_id, component_id, &msg , packet1.uwb_address , packet1.location_x , packet1.location_y , packet1.location_z );
    mavlink_msg_location_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_location_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uwb_address , packet1.location_x , packet1.location_y , packet1.location_z );
    mavlink_msg_location_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_location_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_location_send(MAVLINK_COMM_1 , packet1.uwb_address , packet1.location_x , packet1.location_y , packet1.location_z );
    mavlink_msg_location_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_location_reduced(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LOCATION_REDUCED >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_location_reduced_t packet_in = {
        17.0,45.0,17651
    };
    mavlink_location_reduced_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.location_x = packet_in.location_x;
        packet1.location_y = packet_in.location_y;
        packet1.mesh_address = packet_in.mesh_address;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LOCATION_REDUCED_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LOCATION_REDUCED_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_location_reduced_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_location_reduced_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_location_reduced_pack(system_id, component_id, &msg , packet1.mesh_address , packet1.location_x , packet1.location_y );
    mavlink_msg_location_reduced_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_location_reduced_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mesh_address , packet1.location_x , packet1.location_y );
    mavlink_msg_location_reduced_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_location_reduced_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_location_reduced_send(MAVLINK_COMM_1 , packet1.mesh_address , packet1.location_x , packet1.location_y );
    mavlink_msg_location_reduced_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_distance(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DISTANCE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_distance_t packet_in = {
        17.0,17443,17547
    };
    mavlink_distance_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.distance = packet_in.distance;
        packet1.uwb_address = packet_in.uwb_address;
        packet1.anchor = packet_in.anchor;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DISTANCE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DISTANCE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_distance_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_distance_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_distance_pack(system_id, component_id, &msg , packet1.uwb_address , packet1.anchor , packet1.distance );
    mavlink_msg_distance_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_distance_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uwb_address , packet1.anchor , packet1.distance );
    mavlink_msg_distance_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_distance_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_distance_send(MAVLINK_COMM_1 , packet1.uwb_address , packet1.anchor , packet1.distance );
    mavlink_msg_distance_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_tof(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TOF >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_tof_t packet_in = {
        963497464,17443,17547
    };
    mavlink_tof_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.tof = packet_in.tof;
        packet1.uwb_address = packet_in.uwb_address;
        packet1.anchor = packet_in.anchor;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TOF_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TOF_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tof_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_tof_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tof_pack(system_id, component_id, &msg , packet1.uwb_address , packet1.anchor , packet1.tof );
    mavlink_msg_tof_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tof_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uwb_address , packet1.anchor , packet1.tof );
    mavlink_msg_tof_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_tof_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tof_send(MAVLINK_COMM_1 , packet1.uwb_address , packet1.anchor , packet1.tof );
    mavlink_msg_tof_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_slot(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SLOT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_slot_t packet_in = {
        17235,139
    };
    mavlink_slot_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.uwb_address = packet_in.uwb_address;
        packet1.slot = packet_in.slot;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SLOT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SLOT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_slot_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_slot_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_slot_pack(system_id, component_id, &msg , packet1.uwb_address , packet1.slot );
    mavlink_msg_slot_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_slot_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uwb_address , packet1.slot );
    mavlink_msg_slot_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_slot_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_slot_send(MAVLINK_COMM_1 , packet1.uwb_address , packet1.slot );
    mavlink_msg_slot_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_tag(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TAG >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_tag_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0,325.0,353.0,381.0,409.0,437.0,465.0,493.0,521.0,21187,21291,21395,21499,21603
    };
    mavlink_tag_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.a0x = packet_in.a0x;
        packet1.a0y = packet_in.a0y;
        packet1.a0z = packet_in.a0z;
        packet1.a0r = packet_in.a0r;
        packet1.a1x = packet_in.a1x;
        packet1.a1y = packet_in.a1y;
        packet1.a1z = packet_in.a1z;
        packet1.a1r = packet_in.a1r;
        packet1.a2x = packet_in.a2x;
        packet1.a2y = packet_in.a2y;
        packet1.a2z = packet_in.a2z;
        packet1.a2r = packet_in.a2r;
        packet1.a3x = packet_in.a3x;
        packet1.a3y = packet_in.a3y;
        packet1.a3z = packet_in.a3z;
        packet1.a3r = packet_in.a3r;
        packet1.t0x = packet_in.t0x;
        packet1.t0y = packet_in.t0y;
        packet1.t0z = packet_in.t0z;
        packet1.a0 = packet_in.a0;
        packet1.a1 = packet_in.a1;
        packet1.a2 = packet_in.a2;
        packet1.a3 = packet_in.a3;
        packet1.t0 = packet_in.t0;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TAG_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TAG_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tag_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_tag_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tag_pack(system_id, component_id, &msg , packet1.a0 , packet1.a0x , packet1.a0y , packet1.a0z , packet1.a0r , packet1.a1 , packet1.a1x , packet1.a1y , packet1.a1z , packet1.a1r , packet1.a2 , packet1.a2x , packet1.a2y , packet1.a2z , packet1.a2r , packet1.a3 , packet1.a3x , packet1.a3y , packet1.a3z , packet1.a3r , packet1.t0 , packet1.t0x , packet1.t0y , packet1.t0z );
    mavlink_msg_tag_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tag_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.a0 , packet1.a0x , packet1.a0y , packet1.a0z , packet1.a0r , packet1.a1 , packet1.a1x , packet1.a1y , packet1.a1z , packet1.a1r , packet1.a2 , packet1.a2x , packet1.a2y , packet1.a2z , packet1.a2r , packet1.a3 , packet1.a3x , packet1.a3y , packet1.a3z , packet1.a3r , packet1.t0 , packet1.t0x , packet1.t0y , packet1.t0z );
    mavlink_msg_tag_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_tag_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tag_send(MAVLINK_COMM_1 , packet1.a0 , packet1.a0x , packet1.a0y , packet1.a0z , packet1.a0r , packet1.a1 , packet1.a1x , packet1.a1y , packet1.a1z , packet1.a1r , packet1.a2 , packet1.a2x , packet1.a2y , packet1.a2z , packet1.a2r , packet1.a3 , packet1.a3x , packet1.a3y , packet1.a3z , packet1.a3r , packet1.t0 , packet1.t0x , packet1.t0y , packet1.t0z );
    mavlink_msg_tag_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CONTROL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_control_t packet_in = {
        17.0,45.0
    };
    mavlink_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.left = packet_in.left;
        packet1.right = packet_in.right;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_control_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_control_pack(system_id, component_id, &msg , packet1.left , packet1.right );
    mavlink_msg_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.left , packet1.right );
    mavlink_msg_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_control_send(MAVLINK_COMM_1 , packet1.left , packet1.right );
    mavlink_msg_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_measurement(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MEASUREMENT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_measurement_t packet_in = {
        17.0,45.0,73.0,101.0
    };
    mavlink_measurement_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.rx = packet_in.rx;
        packet1.ry = packet_in.ry;
        packet1.range = packet_in.range;
        packet1.yaw = packet_in.yaw;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MEASUREMENT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MEASUREMENT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_measurement_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_measurement_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_measurement_pack(system_id, component_id, &msg , packet1.rx , packet1.ry , packet1.range , packet1.yaw );
    mavlink_msg_measurement_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_measurement_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.rx , packet1.ry , packet1.range , packet1.yaw );
    mavlink_msg_measurement_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_measurement_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_measurement_send(MAVLINK_COMM_1 , packet1.rx , packet1.ry , packet1.range , packet1.yaw );
    mavlink_msg_measurement_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_control_measurement(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CONTROL_MEASUREMENT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_control_measurement_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0
    };
    mavlink_control_measurement_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.left = packet_in.left;
        packet1.right = packet_in.right;
        packet1.rx = packet_in.rx;
        packet1.ry = packet_in.ry;
        packet1.range = packet_in.range;
        packet1.yaw = packet_in.yaw;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CONTROL_MEASUREMENT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CONTROL_MEASUREMENT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_control_measurement_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_control_measurement_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_control_measurement_pack(system_id, component_id, &msg , packet1.left , packet1.right , packet1.rx , packet1.ry , packet1.range , packet1.yaw );
    mavlink_msg_control_measurement_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_control_measurement_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.left , packet1.right , packet1.rx , packet1.ry , packet1.range , packet1.yaw );
    mavlink_msg_control_measurement_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_control_measurement_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_control_measurement_send(MAVLINK_COMM_1 , packet1.left , packet1.right , packet1.rx , packet1.ry , packet1.range , packet1.yaw );
    mavlink_msg_control_measurement_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_protocol(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_respond(system_id, component_id, last_msg);
    mavlink_test_cmd_change_mode(system_id, component_id, last_msg);
    mavlink_test_cmd_params(system_id, component_id, last_msg);
    mavlink_test_cmd_velocity(system_id, component_id, last_msg);
    mavlink_test_evt_tilt(system_id, component_id, last_msg);
    mavlink_test_evt_rpy(system_id, component_id, last_msg);
    mavlink_test_evt_sensor(system_id, component_id, last_msg);
    mavlink_test_motor_speed(system_id, component_id, last_msg);
    mavlink_test_hw_params(system_id, component_id, last_msg);
    mavlink_test_gyro_params(system_id, component_id, last_msg);
    mavlink_test_accel_params(system_id, component_id, last_msg);
    mavlink_test_mag_params(system_id, component_id, last_msg);
    mavlink_test_comp_filter_params(system_id, component_id, last_msg);
    mavlink_test_evt_gyro_accel_mag_raw(system_id, component_id, last_msg);
    mavlink_test_evt_gyro_accel_mag_calibrated(system_id, component_id, last_msg);
    mavlink_test_pid_params(system_id, component_id, last_msg);
    mavlink_test_pid_report(system_id, component_id, last_msg);
    mavlink_test_blink(system_id, component_id, last_msg);
    mavlink_test_ble_mesh(system_id, component_id, last_msg);
    mavlink_test_onoff(system_id, component_id, last_msg);
    mavlink_test_location(system_id, component_id, last_msg);
    mavlink_test_location_reduced(system_id, component_id, last_msg);
    mavlink_test_distance(system_id, component_id, last_msg);
    mavlink_test_tof(system_id, component_id, last_msg);
    mavlink_test_slot(system_id, component_id, last_msg);
    mavlink_test_tag(system_id, component_id, last_msg);
    mavlink_test_control(system_id, component_id, last_msg);
    mavlink_test_measurement(system_id, component_id, last_msg);
    mavlink_test_control_measurement(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // PROTOCOL_TESTSUITE_H
