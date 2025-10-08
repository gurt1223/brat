//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_flight_Fixed_Wing_types.h
//
// Code generated for Simulink model 'FCS_flight_Fixed_Wing'.
//
// Model version                  : 5.23
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Jun 11 10:44:46 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef FCS_flight_Fixed_Wing_types_h_
#define FCS_flight_Fixed_Wing_types_h_
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include <uORB/topics/actuator_motors.h>
#include <uORB/topics/actuator_servos.h>
#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/airspeed.h>
#include <uORB/topics/vehicle_air_data.h>
#include <uORB/topics/distance_sensor.h>
#include <uORB/topics/esc_report.h>
#include <uORB/topics/esc_status.h>
#include <uORB/topics/vehicle_status.h>
#include <uORB/topics/rc_channels.h>
#include <uORB/topics/debug_array.h>
#ifndef DEFINED_TYPEDEF_FOR_struct_EQLhJUJCEsv8jdQROctBmD_
#define DEFINED_TYPEDEF_FOR_struct_EQLhJUJCEsv8jdQROctBmD_

struct struct_EQLhJUJCEsv8jdQROctBmD
{
  real_T f[77];
  real_T ph[77];
  real_T pwr[77];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_btB5rqzdTbaFBR0C6aRWeH_
#define DEFINED_TYPEDEF_FOR_struct_btB5rqzdTbaFBR0C6aRWeH_

struct struct_btB5rqzdTbaFBR0C6aRWeH
{
  real_T samp_time;
};

#endif

#ifndef struct_d_px4_internal_block_SampleTi_T
#define struct_d_px4_internal_block_SampleTi_T

struct d_px4_internal_block_SampleTi_T
{
  int32_T __dummy;
};

#endif                                // struct_d_px4_internal_block_SampleTi_T

#ifndef struct_px4_internal_block_Subscriber_T
#define struct_px4_internal_block_Subscriber_T

struct px4_internal_block_Subscriber_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_px4_internal_block_SampleTi_T SampleTimeHandler;
  pollfd_t eventStructObj;
  orb_metadata_t * orbMetadataObj;
};

#endif                                // struct_px4_internal_block_Subscriber_T

// Custom Type definition for MATLABSystem: '<S49>/Read Parameter'
#include "MW_Parameter.h"
#ifndef struct_px4_internal_block_ParameterU_T
#define struct_px4_internal_block_ParameterU_T

struct px4_internal_block_ParameterU_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Param_Handle MW_PARAMHANDLE;
};

#endif                                // struct_px4_internal_block_ParameterU_T

#ifndef struct_px4_internal_block_Publisher__T
#define struct_px4_internal_block_Publisher__T

struct px4_internal_block_Publisher__T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  orb_advert_t orbAdvertiseObj;
  orb_metadata_t * orbMetadataObj;
};

#endif                                // struct_px4_internal_block_Publisher__T

#ifndef struct_px4_internal_block_PX4Actuato_T
#define struct_px4_internal_block_PX4Actuato_T

struct px4_internal_block_PX4Actuato_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  uint8_T QSize;
  boolean_T ValidMotorIdx[12];
  boolean_T ValidServoIdx[8];
};

#endif                                // struct_px4_internal_block_PX4Actuato_T

// Parameters (default storage)
typedef struct P_FCS_flight_Fixed_Wing_T_ P_FCS_flight_Fixed_Wing_T;

// Forward declaration for rtModel
typedef struct tag_RTM_FCS_flight_Fixed_Wing_T RT_MODEL_FCS_flight_Fixed_Win_T;

#endif                                 // FCS_flight_Fixed_Wing_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
