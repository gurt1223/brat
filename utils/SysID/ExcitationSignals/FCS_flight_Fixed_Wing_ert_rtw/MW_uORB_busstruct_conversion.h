#ifndef _MW_UORB_BUSSTRUCT_CONVERSION_H_
#define _MW_UORB_BUSSTRUCT_CONVERSION_H_

#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/actuator_motors.h>
#include <uORB/topics/actuator_servos.h>
#include <uORB/topics/airspeed.h>
#include <uORB/topics/debug_array.h>
#include <uORB/topics/distance_sensor.h>
#include <uORB/topics/esc_report.h>
#include <uORB/topics/esc_status.h>
#include <uORB/topics/rc_channels.h>
#include <uORB/topics/vehicle_air_data.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_status.h>

typedef struct actuator_armed_s  px4_Bus_actuator_armed ;
typedef struct actuator_motors_s  px4_Bus_actuator_motors ;
typedef struct actuator_servos_s  px4_Bus_actuator_servos ;
typedef struct airspeed_s  px4_Bus_airspeed ;
typedef struct debug_array_s  px4_Bus_debug_array ;
typedef struct distance_sensor_s  px4_Bus_distance_sensor ;
typedef struct esc_report_s  px4_Bus_esc_report ;
typedef struct esc_status_s  px4_Bus_esc_status ;
typedef struct rc_channels_s  px4_Bus_rc_channels ;
typedef struct vehicle_air_data_s  px4_Bus_vehicle_air_data ;
typedef struct vehicle_angular_velocity_s  px4_Bus_vehicle_angular_velocity ;
typedef struct vehicle_attitude_s  px4_Bus_vehicle_attitude ;
typedef struct vehicle_local_position_s  px4_Bus_vehicle_local_position ;
typedef struct vehicle_status_s  px4_Bus_vehicle_status ;

#endif
