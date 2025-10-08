//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_flight_Fixed_Wing_data.cpp
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
#include "FCS_flight_Fixed_Wing.h"

// Block parameters (default storage)
P_FCS_flight_Fixed_Wing_T FCS_flight_Fixed_Wing_P = {
  // Variable: MS
  //  Referenced by:
  //    '<S9>/Constant'
  //    '<S9>/Constant1'
  //    '<S9>/Constant7'

  {
    { 0.083333333333333343, 0.48333333333333334, 0.81666666666666665,
      1.0166666666666666, 1.2166666666666668, 1.4166666666666667,
      1.6166666666666667, 1.8166666666666667, 0.0, 0.0, 0.0, 0.15000000000000002,
      0.55, 0.85000000000000009, 1.05, 1.25, 1.4500000000000002,
      1.6500000000000001, 1.85, 0.0, 0.0, 0.0, 0.21666666666666667,
      0.6166666666666667, 0.88333333333333341, 1.0833333333333335,
      1.2833333333333334, 1.4833333333333334, 1.6833333333333333,
      1.8833333333333333, 0.0, 0.0, 0.0, 0.28333333333333333,
      0.68333333333333335, 0.91666666666666674, 1.1166666666666667,
      1.3166666666666669, 1.5166666666666666, 1.7166666666666668,
      1.9166666666666667, 0.0, 0.0, 0.0, 0.35, 0.75, 0.95000000000000007, 1.15,
      1.35, 1.55, 1.75, 1.95, 0.0, 0.0, 0.0, 0.41666666666666663,
      0.78333333333333333, 0.98333333333333339, 1.1833333333333333,
      1.3833333333333333, 1.5833333333333335, 1.7833333333333334,
      1.9833333333333334, 0.0, 0.0, 0.0, 0.05, 0.11666666666666667,
      0.18333333333333335, 0.25, 0.31666666666666665, 0.3833333333333333, 0.45,
      0.51666666666666672, 0.58333333333333337, 0.65, 0.71666666666666667 },

    { 1.0749405300654535, 0.061743084807822868, -0.77384611850035867,
      -0.56756500963651746, 0.79512468684644944, 2.1323654581678824,
      -0.70926872211881431, -2.4818217974475303, 0.0, 0.0, 0.0,
      -2.9816091007511023, 2.8438144496639595, -3.049928463713961,
      -1.8737251366903322, 2.2229568092960506, 0.81452124235670453,
      -2.8970002017949454, -2.7636393409643105, 0.0, 0.0, 0.0,
      1.7849237061192333, -0.32187266736183062, 3.0773165808055936,
      -0.78007346128003263, -2.4951799107495631, 0.76249669412089816,
      -0.25154772106285606, 0.14008980576217311, 0.0, 0.0, 0.0,
      2.9308317914111726, 1.7056483907184585, 0.49845660628720623,
      1.3556047140591687, -2.05510552034972, -2.8151997721215807,
      -0.54548421994359586, -1.9445394441444463, 0.0, 0.0, 0.0,
      0.598151763288179, 1.4582073493560372, -2.5596268848009984,
      -2.5948035916387866, 0.23571166177505631, -2.5424368337030572,
      -2.5356069634901743, 2.7191246231267314, 0.0, 0.0, 0.0, 2.0097327464780506,
      -2.8918688071976888, -2.170218133535549, -2.2557223548046395,
      1.7155229939300369, 2.4887579273015206, -0.91818029526555023,
      3.0040989346667146, 0.0, 0.0, 0.0, -3.1134841847195851,
      0.29651144899872151, -0.28026559746236757, 2.8363304909596039,
      -0.29218481031913512, 1.1831736387227494, 0.991382106447432,
      1.8836387172667912, -1.0589550744649827, -1.0049402368117555,
      -1.6384512230380537 },

    { 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.0, 0.0, 0.0,
      0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.0, 0.0, 0.0,
      0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.0, 0.0, 0.0,
      0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.0, 0.0, 0.0,
      0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.0, 0.0, 0.0,
      0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.0, 0.0, 0.0,
      0.090909090909090912, 0.090909090909090912, 0.090909090909090912,
      0.090909090909090912, 0.090909090909090912, 0.090909090909090912,
      0.090909090909090912, 0.090909090909090912, 0.090909090909090912,
      0.090909090909090912, 0.090909090909090912 }
  },

  // Variable: FC
  //  Referenced by:
  //    '<S10>/Gain'
  //    '<S10>/Gain1'

  {
    0.005
  },

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S34>/Constant'

  0.5,

  // Mask Parameter: WrapToZero_Threshold
  //  Referenced by: '<S21>/FixPt Switch'

  4294967295U,

  // Mask Parameter: WrapToZero_Threshold_e
  //  Referenced by: '<S19>/FixPt Switch'

  4294967295U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S58>/Out1'

  {
    (0ULL),                            // timestamp
    0U,                                // counter
    0U,                                // esc_count
    0U,                                // esc_connectiontype
    0U,                                // esc_online_flags
    0U,                                // esc_armed_flags

    {
      0U, 0U }
    ,                                  // _padding0

    {
      {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      } }
    // esc
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S47>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // counter
    0U,                                // esc_count
    0U,                                // esc_connectiontype
    0U,                                // esc_online_flags
    0U,                                // esc_armed_flags

    {
      0U, 0U }
    ,                                  // _padding0

    {
      {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp
        0U,                            // esc_errorcount
        0,                             // esc_rpm
        0.0F,                          // esc_voltage
        0.0F,                          // esc_current
        0.0F,                          // esc_temperature
        0U,                            // failures
        0U,                            // esc_address
        0U,                            // esc_cmdcount
        0U,                            // esc_state
        0U,                            // actuator_function
        0,                             // esc_power

        {
          0U, 0U, 0U, 0U, 0U }
        // _padding0
      } }
    // esc
  },

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S75>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // data
    0U,                                // id

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // name

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_e
  //  Referenced by: '<S54>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // heading_good_for_control
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield
    false,                             // dead_reckoning
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S43>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // heading_good_for_control
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield
    false,                             // dead_reckoning
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_m
  //  Referenced by: '<S70>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_valid

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // channels
    0U,                                // frame_drop_count
    0U,                                // channel_count

    {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0 }
    ,                                  // function
    0U,                                // rssi
    false,                             // signal_lost

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S69>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_valid

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // channels
    0U,                                // frame_drop_count
    0U,                                // channel_count

    {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0 }
    ,                                  // function
    0U,                                // rssi
    false,                             // signal_lost

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_l
  //  Referenced by: '<S25>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // control
    0U,                                // reversible_flags

    {
      0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S23>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // control
    0U,                                // reversible_flags

    {
      0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S59>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // armed_time
    (0ULL),                            // takeoff_time
    (0ULL),                            // nav_state_timestamp
    0U,                                // failure_detector_status
    0U,                                // arming_state
    0U,                                // latest_arming_reason
    0U,                                // latest_disarming_reason
    0U,                                // nav_state_user_intention
    0U,                                // nav_state
    0U,                                // hil_state
    0U,                                // vehicle_type
    false,                             // failsafe
    false,                             // failsafe_and_user_took_over
    false,                             // gcs_connection_lost
    0U,                                // gcs_connection_lost_counter
    false,                             // high_latency_data_link_lost
    false,                             // is_vtol
    false,                             // is_vtol_tailsitter
    false,                             // in_transition_mode
    false,                             // in_transition_to_fw
    0U,                                // system_type
    0U,                                // system_id
    0U,                                // component_id
    false,                             // safety_button_available
    false,                             // safety_off
    false,                             // power_input_valid
    false,                             // usb_connected
    false,                             // open_drone_id_system_present
    false,                             // open_drone_id_system_healthy
    false,                             // parachute_system_present
    false,                             // parachute_system_healthy
    false,                             // avoidance_system_required
    false,                             // avoidance_system_valid
    false,                             // rc_calibration_in_progress
    false,                             // calibration_enabled
    false,                             // pre_flight_checks_pass

    {
      0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S48>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // armed_time
    (0ULL),                            // takeoff_time
    (0ULL),                            // nav_state_timestamp
    0U,                                // failure_detector_status
    0U,                                // arming_state
    0U,                                // latest_arming_reason
    0U,                                // latest_disarming_reason
    0U,                                // nav_state_user_intention
    0U,                                // nav_state
    0U,                                // hil_state
    0U,                                // vehicle_type
    false,                             // failsafe
    false,                             // failsafe_and_user_took_over
    false,                             // gcs_connection_lost
    0U,                                // gcs_connection_lost_counter
    false,                             // high_latency_data_link_lost
    false,                             // is_vtol
    false,                             // is_vtol_tailsitter
    false,                             // in_transition_mode
    false,                             // in_transition_to_fw
    0U,                                // system_type
    0U,                                // system_id
    0U,                                // component_id
    false,                             // safety_button_available
    false,                             // safety_off
    false,                             // power_input_valid
    false,                             // usb_connected
    false,                             // open_drone_id_system_present
    false,                             // open_drone_id_system_healthy
    false,                             // parachute_system_present
    false,                             // parachute_system_healthy
    false,                             // avoidance_system_required
    false,                             // avoidance_system_valid
    false,                             // rc_calibration_in_progress
    false,                             // calibration_enabled
    false,                             // pre_flight_checks_pass

    {
      0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_pl
  //  Referenced by: '<S57>/Out1'

  {
    (0ULL),                            // timestamp
    0U,                                // device_id
    0.0F,                              // min_distance
    0.0F,                              // max_distance
    0.0F,                              // current_distance
    0.0F,                              // variance
    0.0F,                              // h_fov
    0.0F,                              // v_fov

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q
    0,                                 // signal_quality
    0U,                                // type
    0U,                                // orientation
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S46>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // device_id
    0.0F,                              // min_distance
    0.0F,                              // max_distance
    0.0F,                              // current_distance
    0.0F,                              // variance
    0.0F,                              // h_fov
    0.0F,                              // v_fov

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q
    0,                                 // signal_quality
    0U,                                // type
    0U,                                // orientation
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S52>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_jh
  //  Referenced by: '<S41>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_a
  //  Referenced by: '<S26>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    // control
  },

  // Computed Parameter: Constant_Value_n2
  //  Referenced by: '<S24>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    // control
  },

  // Computed Parameter: Out1_Y0_pb
  //  Referenced by: '<S56>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // baro_device_id
    0.0F,                              // baro_alt_meter
    0.0F,                              // baro_temp_celcius
    0.0F,                              // baro_pressure_pa
    0.0F,                              // rho
    0U,                                // calibration_count

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_b3
  //  Referenced by: '<S45>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // baro_device_id
    0.0F,                              // baro_alt_meter
    0.0F,                              // baro_temp_celcius
    0.0F,                              // baro_pressure_pa
    0.0F,                              // rho
    0U,                                // calibration_count

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S53>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // xyz

    {
      0.0F, 0.0F, 0.0F }
    // xyz_derivative
  },

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<S42>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // xyz

    {
      0.0F, 0.0F, 0.0F }
    // xyz_derivative
  },

  // Computed Parameter: Out1_Y0_b
  //  Referenced by: '<S55>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Computed Parameter: Constant_Value_cn
  //  Referenced by: '<S44>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S36>/Out1'

  {
    (0ULL),                            // timestamp
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_h1
  //  Referenced by: '<S35>/Constant'

  {
    (0ULL),                            // timestamp
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    0U                                 // _padding0
  },

  // Expression: 1.423079
  //  Referenced by: '<S9>/Constant6'

  1.423079,

  // Expression: zeros(7,1)
  //  Referenced by: '<S9>/Constant5'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 2
  //  Referenced by: '<S30>/Constant'

  2.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S33>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S33>/Discrete-Time Integrator'

  0.0,

  // Expression: 3
  //  Referenced by: '<S30>/Constant1'

  3.0,

  // Expression: 3
  //  Referenced by: '<S30>/Constant2'

  3.0,

  // Expression: 3
  //  Referenced by: '<S30>/Constant3'

  3.0,

  // Expression: 3
  //  Referenced by: '<S30>/Constant4'

  3.0,

  // Expression: 2
  //  Referenced by: '<S30>/Constant5'

  2.0,

  // Expression: 100
  //  Referenced by: '<S30>/Constant6'

  100.0,

  // Expression: 2
  //  Referenced by: '<S30>/Constant7'

  2.0,

  // Expression: 1.943844
  //  Referenced by: '<S29>/Gain'

  1.943844,

  // Expression: 0
  //  Referenced by: '<S51>/Rate Transition1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S10>/Memory'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S5>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S5>/Delay1'

  0.0,

  // Expression: 0.5
  //  Referenced by: '<S5>/Switch'

  0.5,

  // Expression: 0
  //  Referenced by: '<S10>/Switch'

  0.0,

  // Expression: 0
  //  Referenced by: '<S9>/Switch1'

  0.0,

  // Expression: NaN(7,1)
  //  Referenced by: '<S5>/Constant3'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: NaN(2,1)
  //  Referenced by: '<S5>/Constant1'

  { 0.0, 0.0 },

  // Expression: NaN(23,1)
  //  Referenced by: '<S72>/Constant1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0.0
  //  Referenced by: '<S51>/Delay One Step'

  0.0,

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S71>/Constant'

  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant_Value_c3
  //  Referenced by: '<S19>/Constant'

  0U,

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S21>/Constant'

  0U,

  // Computed Parameter: Output_InitialCondition
  //  Referenced by: '<S16>/Output'

  0U,

  // Computed Parameter: Output_InitialCondition_c
  //  Referenced by: '<S17>/Output'

  0U,

  // Computed Parameter: FixPtConstant_Value
  //  Referenced by: '<S20>/FixPt Constant'

  1U,

  // Computed Parameter: FixPtConstant_Value_i
  //  Referenced by: '<S18>/FixPt Constant'

  1U
};

//
// File trailer for generated code.
//
// [EOF]
//
