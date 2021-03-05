#pragma once
// MESSAGE FUEL_STATUS PACKING

#define MAVLINK_MSG_ID_FUEL_STATUS 10088


typedef struct __mavlink_fuel_status_t {
 float starting_fuel_level; /*< [L] float*/
 float current_fuel_level; /*< [L] float*/
 float max_flight_distance_remaining; /*< [km] float*/
 float avg_burn_rate; /*< [mL/m] float*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
} mavlink_fuel_status_t;

#define MAVLINK_MSG_ID_FUEL_STATUS_LEN 18
#define MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN 18
#define MAVLINK_MSG_ID_10088_LEN 18
#define MAVLINK_MSG_ID_10088_MIN_LEN 18

#define MAVLINK_MSG_ID_FUEL_STATUS_CRC 216
#define MAVLINK_MSG_ID_10088_CRC 216



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FUEL_STATUS { \
    10088, \
    "FUEL_STATUS", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_fuel_status_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_fuel_status_t, target_component) }, \
         { "starting_fuel_level", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_fuel_status_t, starting_fuel_level) }, \
         { "current_fuel_level", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_fuel_status_t, current_fuel_level) }, \
         { "max_flight_distance_remaining", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_fuel_status_t, max_flight_distance_remaining) }, \
         { "avg_burn_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_fuel_status_t, avg_burn_rate) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FUEL_STATUS { \
    "FUEL_STATUS", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_fuel_status_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_fuel_status_t, target_component) }, \
         { "starting_fuel_level", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_fuel_status_t, starting_fuel_level) }, \
         { "current_fuel_level", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_fuel_status_t, current_fuel_level) }, \
         { "max_flight_distance_remaining", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_fuel_status_t, max_flight_distance_remaining) }, \
         { "avg_burn_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_fuel_status_t, avg_burn_rate) }, \
         } \
}
#endif

/**
 * @brief Pack a fuel_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param starting_fuel_level [L] float
 * @param current_fuel_level [L] float
 * @param max_flight_distance_remaining [km] float
 * @param avg_burn_rate [mL/m] float
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fuel_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, float starting_fuel_level, float current_fuel_level, float max_flight_distance_remaining, float avg_burn_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FUEL_STATUS_LEN];
    _mav_put_float(buf, 0, starting_fuel_level);
    _mav_put_float(buf, 4, current_fuel_level);
    _mav_put_float(buf, 8, max_flight_distance_remaining);
    _mav_put_float(buf, 12, avg_burn_rate);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FUEL_STATUS_LEN);
#else
    mavlink_fuel_status_t packet;
    packet.starting_fuel_level = starting_fuel_level;
    packet.current_fuel_level = current_fuel_level;
    packet.max_flight_distance_remaining = max_flight_distance_remaining;
    packet.avg_burn_rate = avg_burn_rate;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FUEL_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FUEL_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN, MAVLINK_MSG_ID_FUEL_STATUS_LEN, MAVLINK_MSG_ID_FUEL_STATUS_CRC);
}

/**
 * @brief Pack a fuel_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param starting_fuel_level [L] float
 * @param current_fuel_level [L] float
 * @param max_flight_distance_remaining [km] float
 * @param avg_burn_rate [mL/m] float
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fuel_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,float starting_fuel_level,float current_fuel_level,float max_flight_distance_remaining,float avg_burn_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FUEL_STATUS_LEN];
    _mav_put_float(buf, 0, starting_fuel_level);
    _mav_put_float(buf, 4, current_fuel_level);
    _mav_put_float(buf, 8, max_flight_distance_remaining);
    _mav_put_float(buf, 12, avg_burn_rate);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FUEL_STATUS_LEN);
#else
    mavlink_fuel_status_t packet;
    packet.starting_fuel_level = starting_fuel_level;
    packet.current_fuel_level = current_fuel_level;
    packet.max_flight_distance_remaining = max_flight_distance_remaining;
    packet.avg_burn_rate = avg_burn_rate;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FUEL_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FUEL_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN, MAVLINK_MSG_ID_FUEL_STATUS_LEN, MAVLINK_MSG_ID_FUEL_STATUS_CRC);
}

/**
 * @brief Encode a fuel_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param fuel_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fuel_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_fuel_status_t* fuel_status)
{
    return mavlink_msg_fuel_status_pack(system_id, component_id, msg, fuel_status->target_system, fuel_status->target_component, fuel_status->starting_fuel_level, fuel_status->current_fuel_level, fuel_status->max_flight_distance_remaining, fuel_status->avg_burn_rate);
}

/**
 * @brief Encode a fuel_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param fuel_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fuel_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_fuel_status_t* fuel_status)
{
    return mavlink_msg_fuel_status_pack_chan(system_id, component_id, chan, msg, fuel_status->target_system, fuel_status->target_component, fuel_status->starting_fuel_level, fuel_status->current_fuel_level, fuel_status->max_flight_distance_remaining, fuel_status->avg_burn_rate);
}

/**
 * @brief Send a fuel_status message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param starting_fuel_level [L] float
 * @param current_fuel_level [L] float
 * @param max_flight_distance_remaining [km] float
 * @param avg_burn_rate [mL/m] float
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_fuel_status_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, float starting_fuel_level, float current_fuel_level, float max_flight_distance_remaining, float avg_burn_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FUEL_STATUS_LEN];
    _mav_put_float(buf, 0, starting_fuel_level);
    _mav_put_float(buf, 4, current_fuel_level);
    _mav_put_float(buf, 8, max_flight_distance_remaining);
    _mav_put_float(buf, 12, avg_burn_rate);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, target_component);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FUEL_STATUS, buf, MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN, MAVLINK_MSG_ID_FUEL_STATUS_LEN, MAVLINK_MSG_ID_FUEL_STATUS_CRC);
#else
    mavlink_fuel_status_t packet;
    packet.starting_fuel_level = starting_fuel_level;
    packet.current_fuel_level = current_fuel_level;
    packet.max_flight_distance_remaining = max_flight_distance_remaining;
    packet.avg_burn_rate = avg_burn_rate;
    packet.target_system = target_system;
    packet.target_component = target_component;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FUEL_STATUS, (const char *)&packet, MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN, MAVLINK_MSG_ID_FUEL_STATUS_LEN, MAVLINK_MSG_ID_FUEL_STATUS_CRC);
#endif
}

/**
 * @brief Send a fuel_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_fuel_status_send_struct(mavlink_channel_t chan, const mavlink_fuel_status_t* fuel_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_fuel_status_send(chan, fuel_status->target_system, fuel_status->target_component, fuel_status->starting_fuel_level, fuel_status->current_fuel_level, fuel_status->max_flight_distance_remaining, fuel_status->avg_burn_rate);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FUEL_STATUS, (const char *)fuel_status, MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN, MAVLINK_MSG_ID_FUEL_STATUS_LEN, MAVLINK_MSG_ID_FUEL_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_FUEL_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_fuel_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, float starting_fuel_level, float current_fuel_level, float max_flight_distance_remaining, float avg_burn_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, starting_fuel_level);
    _mav_put_float(buf, 4, current_fuel_level);
    _mav_put_float(buf, 8, max_flight_distance_remaining);
    _mav_put_float(buf, 12, avg_burn_rate);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, target_component);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FUEL_STATUS, buf, MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN, MAVLINK_MSG_ID_FUEL_STATUS_LEN, MAVLINK_MSG_ID_FUEL_STATUS_CRC);
#else
    mavlink_fuel_status_t *packet = (mavlink_fuel_status_t *)msgbuf;
    packet->starting_fuel_level = starting_fuel_level;
    packet->current_fuel_level = current_fuel_level;
    packet->max_flight_distance_remaining = max_flight_distance_remaining;
    packet->avg_burn_rate = avg_burn_rate;
    packet->target_system = target_system;
    packet->target_component = target_component;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FUEL_STATUS, (const char *)packet, MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN, MAVLINK_MSG_ID_FUEL_STATUS_LEN, MAVLINK_MSG_ID_FUEL_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE FUEL_STATUS UNPACKING


/**
 * @brief Get field target_system from fuel_status message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_fuel_status_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field target_component from fuel_status message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_fuel_status_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field starting_fuel_level from fuel_status message
 *
 * @return [L] float
 */
static inline float mavlink_msg_fuel_status_get_starting_fuel_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field current_fuel_level from fuel_status message
 *
 * @return [L] float
 */
static inline float mavlink_msg_fuel_status_get_current_fuel_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field max_flight_distance_remaining from fuel_status message
 *
 * @return [km] float
 */
static inline float mavlink_msg_fuel_status_get_max_flight_distance_remaining(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field avg_burn_rate from fuel_status message
 *
 * @return [mL/m] float
 */
static inline float mavlink_msg_fuel_status_get_avg_burn_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a fuel_status message into a struct
 *
 * @param msg The message to decode
 * @param fuel_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_fuel_status_decode(const mavlink_message_t* msg, mavlink_fuel_status_t* fuel_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    fuel_status->starting_fuel_level = mavlink_msg_fuel_status_get_starting_fuel_level(msg);
    fuel_status->current_fuel_level = mavlink_msg_fuel_status_get_current_fuel_level(msg);
    fuel_status->max_flight_distance_remaining = mavlink_msg_fuel_status_get_max_flight_distance_remaining(msg);
    fuel_status->avg_burn_rate = mavlink_msg_fuel_status_get_avg_burn_rate(msg);
    fuel_status->target_system = mavlink_msg_fuel_status_get_target_system(msg);
    fuel_status->target_component = mavlink_msg_fuel_status_get_target_component(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FUEL_STATUS_LEN? msg->len : MAVLINK_MSG_ID_FUEL_STATUS_LEN;
        memset(fuel_status, 0, MAVLINK_MSG_ID_FUEL_STATUS_LEN);
    memcpy(fuel_status, _MAV_PAYLOAD(msg), len);
#endif
}
