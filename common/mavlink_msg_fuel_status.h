#pragma once
// MESSAGE FUEL_STATUS PACKING

#define MAVLINK_MSG_ID_FUEL_STATUS 344


typedef struct __mavlink_fuel_status_t {
 uint64_t time_boot_ms; /*< [ms] float*/
 float starting_fuel_level; /*< [L] float*/
 float current_fuel_level; /*< [L] float*/
 float max_flight_distance_remaining; /*< [km] float*/
 float avg_burn_rate; /*< [mL/m] float*/
} mavlink_fuel_status_t;

#define MAVLINK_MSG_ID_FUEL_STATUS_LEN 24
#define MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN 24
#define MAVLINK_MSG_ID_344_LEN 24
#define MAVLINK_MSG_ID_344_MIN_LEN 24

#define MAVLINK_MSG_ID_FUEL_STATUS_CRC 67
#define MAVLINK_MSG_ID_344_CRC 67



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FUEL_STATUS { \
    344, \
    "FUEL_STATUS", \
    5, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_fuel_status_t, time_boot_ms) }, \
         { "starting_fuel_level", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_fuel_status_t, starting_fuel_level) }, \
         { "current_fuel_level", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_fuel_status_t, current_fuel_level) }, \
         { "max_flight_distance_remaining", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_fuel_status_t, max_flight_distance_remaining) }, \
         { "avg_burn_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_fuel_status_t, avg_burn_rate) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FUEL_STATUS { \
    "FUEL_STATUS", \
    5, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_fuel_status_t, time_boot_ms) }, \
         { "starting_fuel_level", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_fuel_status_t, starting_fuel_level) }, \
         { "current_fuel_level", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_fuel_status_t, current_fuel_level) }, \
         { "max_flight_distance_remaining", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_fuel_status_t, max_flight_distance_remaining) }, \
         { "avg_burn_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_fuel_status_t, avg_burn_rate) }, \
         } \
}
#endif

/**
 * @brief Pack a fuel_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] float
 * @param starting_fuel_level [L] float
 * @param current_fuel_level [L] float
 * @param max_flight_distance_remaining [km] float
 * @param avg_burn_rate [mL/m] float
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fuel_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_boot_ms, float starting_fuel_level, float current_fuel_level, float max_flight_distance_remaining, float avg_burn_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FUEL_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, starting_fuel_level);
    _mav_put_float(buf, 12, current_fuel_level);
    _mav_put_float(buf, 16, max_flight_distance_remaining);
    _mav_put_float(buf, 20, avg_burn_rate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FUEL_STATUS_LEN);
#else
    mavlink_fuel_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.starting_fuel_level = starting_fuel_level;
    packet.current_fuel_level = current_fuel_level;
    packet.max_flight_distance_remaining = max_flight_distance_remaining;
    packet.avg_burn_rate = avg_burn_rate;

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
 * @param time_boot_ms [ms] float
 * @param starting_fuel_level [L] float
 * @param current_fuel_level [L] float
 * @param max_flight_distance_remaining [km] float
 * @param avg_burn_rate [mL/m] float
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fuel_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_boot_ms,float starting_fuel_level,float current_fuel_level,float max_flight_distance_remaining,float avg_burn_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FUEL_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, starting_fuel_level);
    _mav_put_float(buf, 12, current_fuel_level);
    _mav_put_float(buf, 16, max_flight_distance_remaining);
    _mav_put_float(buf, 20, avg_burn_rate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FUEL_STATUS_LEN);
#else
    mavlink_fuel_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.starting_fuel_level = starting_fuel_level;
    packet.current_fuel_level = current_fuel_level;
    packet.max_flight_distance_remaining = max_flight_distance_remaining;
    packet.avg_burn_rate = avg_burn_rate;

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
    return mavlink_msg_fuel_status_pack(system_id, component_id, msg, fuel_status->time_boot_ms, fuel_status->starting_fuel_level, fuel_status->current_fuel_level, fuel_status->max_flight_distance_remaining, fuel_status->avg_burn_rate);
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
    return mavlink_msg_fuel_status_pack_chan(system_id, component_id, chan, msg, fuel_status->time_boot_ms, fuel_status->starting_fuel_level, fuel_status->current_fuel_level, fuel_status->max_flight_distance_remaining, fuel_status->avg_burn_rate);
}

/**
 * @brief Send a fuel_status message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] float
 * @param starting_fuel_level [L] float
 * @param current_fuel_level [L] float
 * @param max_flight_distance_remaining [km] float
 * @param avg_burn_rate [mL/m] float
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_fuel_status_send(mavlink_channel_t chan, uint64_t time_boot_ms, float starting_fuel_level, float current_fuel_level, float max_flight_distance_remaining, float avg_burn_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FUEL_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, starting_fuel_level);
    _mav_put_float(buf, 12, current_fuel_level);
    _mav_put_float(buf, 16, max_flight_distance_remaining);
    _mav_put_float(buf, 20, avg_burn_rate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FUEL_STATUS, buf, MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN, MAVLINK_MSG_ID_FUEL_STATUS_LEN, MAVLINK_MSG_ID_FUEL_STATUS_CRC);
#else
    mavlink_fuel_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.starting_fuel_level = starting_fuel_level;
    packet.current_fuel_level = current_fuel_level;
    packet.max_flight_distance_remaining = max_flight_distance_remaining;
    packet.avg_burn_rate = avg_burn_rate;

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
    mavlink_msg_fuel_status_send(chan, fuel_status->time_boot_ms, fuel_status->starting_fuel_level, fuel_status->current_fuel_level, fuel_status->max_flight_distance_remaining, fuel_status->avg_burn_rate);
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
static inline void mavlink_msg_fuel_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_boot_ms, float starting_fuel_level, float current_fuel_level, float max_flight_distance_remaining, float avg_burn_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, starting_fuel_level);
    _mav_put_float(buf, 12, current_fuel_level);
    _mav_put_float(buf, 16, max_flight_distance_remaining);
    _mav_put_float(buf, 20, avg_burn_rate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FUEL_STATUS, buf, MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN, MAVLINK_MSG_ID_FUEL_STATUS_LEN, MAVLINK_MSG_ID_FUEL_STATUS_CRC);
#else
    mavlink_fuel_status_t *packet = (mavlink_fuel_status_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->starting_fuel_level = starting_fuel_level;
    packet->current_fuel_level = current_fuel_level;
    packet->max_flight_distance_remaining = max_flight_distance_remaining;
    packet->avg_burn_rate = avg_burn_rate;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FUEL_STATUS, (const char *)packet, MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN, MAVLINK_MSG_ID_FUEL_STATUS_LEN, MAVLINK_MSG_ID_FUEL_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE FUEL_STATUS UNPACKING


/**
 * @brief Get field time_boot_ms from fuel_status message
 *
 * @return [ms] float
 */
static inline uint64_t mavlink_msg_fuel_status_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field starting_fuel_level from fuel_status message
 *
 * @return [L] float
 */
static inline float mavlink_msg_fuel_status_get_starting_fuel_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field current_fuel_level from fuel_status message
 *
 * @return [L] float
 */
static inline float mavlink_msg_fuel_status_get_current_fuel_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field max_flight_distance_remaining from fuel_status message
 *
 * @return [km] float
 */
static inline float mavlink_msg_fuel_status_get_max_flight_distance_remaining(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field avg_burn_rate from fuel_status message
 *
 * @return [mL/m] float
 */
static inline float mavlink_msg_fuel_status_get_avg_burn_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
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
    fuel_status->time_boot_ms = mavlink_msg_fuel_status_get_time_boot_ms(msg);
    fuel_status->starting_fuel_level = mavlink_msg_fuel_status_get_starting_fuel_level(msg);
    fuel_status->current_fuel_level = mavlink_msg_fuel_status_get_current_fuel_level(msg);
    fuel_status->max_flight_distance_remaining = mavlink_msg_fuel_status_get_max_flight_distance_remaining(msg);
    fuel_status->avg_burn_rate = mavlink_msg_fuel_status_get_avg_burn_rate(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FUEL_STATUS_LEN? msg->len : MAVLINK_MSG_ID_FUEL_STATUS_LEN;
        memset(fuel_status, 0, MAVLINK_MSG_ID_FUEL_STATUS_LEN);
    memcpy(fuel_status, _MAV_PAYLOAD(msg), len);
#endif
}
