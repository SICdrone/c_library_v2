/** @file
 *    @brief MAVLink comm protocol testsuite generated from sicdrone.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef SICDRONE_TESTSUITE_H
#define SICDRONE_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_sicdrone(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_sicdrone(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_fuel_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_FUEL_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_fuel_status_t packet_in = {
        17.0,45.0,73.0,101.0,53,120
    };
    mavlink_fuel_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.starting_fuel_level = packet_in.starting_fuel_level;
        packet1.current_fuel_level = packet_in.current_fuel_level;
        packet1.max_flight_distance_remaining = packet_in.max_flight_distance_remaining;
        packet1.avg_burn_rate = packet_in.avg_burn_rate;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fuel_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_fuel_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fuel_status_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.starting_fuel_level , packet1.current_fuel_level , packet1.max_flight_distance_remaining , packet1.avg_burn_rate );
    mavlink_msg_fuel_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fuel_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.starting_fuel_level , packet1.current_fuel_level , packet1.max_flight_distance_remaining , packet1.avg_burn_rate );
    mavlink_msg_fuel_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_fuel_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fuel_status_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.starting_fuel_level , packet1.current_fuel_level , packet1.max_flight_distance_remaining , packet1.avg_burn_rate );
    mavlink_msg_fuel_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_sicdrone(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_fuel_status(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // SICDRONE_TESTSUITE_H
