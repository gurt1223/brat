//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_flight_Fixed_Wing.h
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
#ifndef FCS_flight_Fixed_Wing_h_
#define FCS_flight_Fixed_Wing_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_uORB_Read.h"
#include "MW_PX4_Parameter.h"
#include "MW_Parameter.h"
#include "MW_PX4_Actuators.h"
#include "MW_uORB_Write.h"
#include "FCS_flight_Fixed_Wing_types.h"
#include <uORB/topics/esc_status.h>
#include <uORB/topics/debug_array.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/rc_channels.h>
#include <uORB/topics/actuator_motors.h>
#include <uORB/topics/vehicle_status.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/distance_sensor.h>
#include <uORB/topics/actuator_servos.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/vehicle_air_data.h>
#include <uORB/topics/airspeed.h>
#include <uORB/topics/actuator_armed.h>

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <stddef.h>

// Block signals (default storage)
struct B_FCS_flight_Fixed_Wing_T {
  px4_Bus_esc_status r;
  px4_Bus_debug_array BusAssignment;   // '<S72>/Bus Assignment'
  px4_Bus_vehicle_local_position r1;
  real_T DataTypeConversion23[18];     // '<S30>/Data Type Conversion23'
  px4_Bus_rc_channels In1;             // '<S70>/In1'
  px4_Bus_rc_channels r2;
  real_T Manual_Actuator_Out[16];
  real_T Sum_l[16];                    // '<S5>/Sum'
  px4_Bus_actuator_motors In1_i;       // '<S25>/In1'
  px4_Bus_actuator_motors r3;
  px4_Bus_vehicle_status In1_k;        // '<S59>/In1'
  px4_Bus_vehicle_status r4;
  px4_Bus_vehicle_attitude r5;
  px4_Bus_distance_sensor In1_p;       // '<S57>/In1'
  px4_Bus_distance_sensor r6;
  real_T u[7];                         // '<S9>/MS'
  real_T Reshape3[7];                  // '<S72>/Reshape3'
  real32_T motorValues[12];
  real32_T motorValues_m[12];
  px4_Bus_actuator_servos In1_io;      // '<S26>/In1'
  px4_Bus_actuator_servos r7;
  real_T Product2[6];                  // '<S9>/Product2'
  px4_Bus_vehicle_angular_velocity r8;
  px4_Bus_vehicle_air_data In1_jb;     // '<S56>/In1'
  px4_Bus_vehicle_air_data r9;
  real32_T servoValues[8];
  px4_Bus_airspeed In1_e;              // '<S55>/In1'
  px4_Bus_airspeed r10;
  real32_T DataTypeConversion7[6];     // '<S71>/Data Type Conversion7'
  px4_Bus_actuator_armed In1_jq;       // '<S36>/In1'
  px4_Bus_actuator_armed r11;
  real_T RateTransition1;              // '<S51>/Rate Transition1'
  real_T y_h;                          // '<S30>/MATLAB Function'
  real_T Switch_m;                     // '<S5>/Switch'
  real_T Memory;                       // '<S10>/Memory'
  real_T y_c;                          // '<S30>/MATLAB Function3'
  real_T y_b;                          // '<S30>/MATLAB Function4'
  real_T y_g;                          // '<S30>/MATLAB Function5'
  real_T y_f;                          // '<S30>/MATLAB Function6'
  real_T CastToDouble_b;               // '<S51>/Cast To Double'
  real_T Sum;                          // '<S10>/Sum'
  real_T rtb_u_c;
};

// Block states (default storage) for system '<Root>'
struct DW_FCS_flight_Fixed_Wing_T {
  px4_internal_block_PX4Actuato_T obj; // '<S71>/PX4 Actuator Write'
  px4_internal_block_Subscriber_T obj_b;// '<S69>/SourceBlock'
  px4_internal_block_Subscriber_T obj_p;// '<S48>/SourceBlock'
  px4_internal_block_Subscriber_T obj_h;// '<S47>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S46>/SourceBlock'
  px4_internal_block_Subscriber_T obj_hm;// '<S45>/SourceBlock'
  px4_internal_block_Subscriber_T obj_n;// '<S44>/SourceBlock'
  px4_internal_block_Subscriber_T obj_j;// '<S43>/SourceBlock'
  px4_internal_block_Subscriber_T obj_o;// '<S42>/SourceBlock'
  px4_internal_block_Subscriber_T obj_nr;// '<S41>/SourceBlock'
  px4_internal_block_Subscriber_T obj_l;// '<S35>/SourceBlock'
  px4_internal_block_Subscriber_T obj_jl;// '<S24>/SourceBlock'
  px4_internal_block_Subscriber_T obj_c;// '<S23>/SourceBlock'
  px4_internal_block_ParameterU_T obj_oh;// '<S49>/Read Parameter'
  px4_internal_block_ParameterU_T obj_e;// '<S39>/Read Parameter8'
  px4_internal_block_ParameterU_T obj_cf;// '<S39>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_j0;// '<S39>/Read Parameter'
  px4_internal_block_ParameterU_T obj_g;// '<S38>/Read Parameter8'
  px4_internal_block_ParameterU_T obj_l0;// '<S38>/Read Parameter7'
  px4_internal_block_ParameterU_T obj_a;// '<S38>/Read Parameter6'
  px4_internal_block_ParameterU_T obj_j1;// '<S38>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_k;// '<S38>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_m;// '<S38>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_m2;// '<S38>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_jv;// '<S38>/Read Parameter13'
  px4_internal_block_ParameterU_T obj_gw;// '<S38>/Read Parameter12'
  px4_internal_block_ParameterU_T obj_az;// '<S38>/Read Parameter11'
  px4_internal_block_ParameterU_T obj_h0;// '<S38>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_bq;// '<S38>/Read Parameter'
  px4_internal_block_ParameterU_T obj_ki;// '<S37>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_kl;// '<S37>/Read Parameter'
  px4_internal_block_Publisher__T obj_dy;// '<S76>/SinkBlock'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S33>/Discrete-Time Integrator'
  real_T Delay_DSTATE[2];              // '<S5>/Delay'
  real_T Delay1_DSTATE[2];             // '<S5>/Delay1'
  real_T DelayOneStep_DSTATE;          // '<S51>/Delay One Step'
  real_T RateTransition1_Buffer0;      // '<S51>/Rate Transition1'
  real_T Memory_PreviousInput;         // '<S10>/Memory'
  real_T RateTransition_Buffer;        // '<S51>/Rate Transition'
  uint32_T Output_DSTATE;              // '<S16>/Output'
  uint32_T Output_DSTATE_k;            // '<S17>/Output'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S33>/Discrete-Time Integrator'
};

// Parameters (default storage)
struct P_FCS_flight_Fixed_Wing_T_ {
  struct_EQLhJUJCEsv8jdQROctBmD MS;    // Variable: MS
                                          //  Referenced by:
                                          //    '<S9>/Constant'
                                          //    '<S9>/Constant1'
                                          //    '<S9>/Constant7'

  struct_btB5rqzdTbaFBR0C6aRWeH FC;    // Variable: FC
                                          //  Referenced by:
                                          //    '<S10>/Gain'
                                          //    '<S10>/Gain1'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S34>/Constant'

  uint32_T WrapToZero_Threshold;       // Mask Parameter: WrapToZero_Threshold
                                          //  Referenced by: '<S21>/FixPt Switch'

  uint32_T WrapToZero_Threshold_e;     // Mask Parameter: WrapToZero_Threshold_e
                                          //  Referenced by: '<S19>/FixPt Switch'

  px4_Bus_esc_status Out1_Y0;          // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S58>/Out1'

  px4_Bus_esc_status Constant_Value;   // Computed Parameter: Constant_Value
                                          //  Referenced by: '<S47>/Constant'

  px4_Bus_debug_array Constant_Value_j;// Computed Parameter: Constant_Value_j
                                          //  Referenced by: '<S75>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                              //  Referenced by: '<S54>/Out1'

  px4_Bus_vehicle_local_position Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                     //  Referenced by: '<S43>/Constant'

  px4_Bus_rc_channels Out1_Y0_m;       // Computed Parameter: Out1_Y0_m
                                          //  Referenced by: '<S70>/Out1'

  px4_Bus_rc_channels Constant_Value_h;// Computed Parameter: Constant_Value_h
                                          //  Referenced by: '<S69>/Constant'

  px4_Bus_actuator_motors Out1_Y0_l;   // Computed Parameter: Out1_Y0_l
                                          //  Referenced by: '<S25>/Out1'

  px4_Bus_actuator_motors Constant_Value_b;// Computed Parameter: Constant_Value_b
                                              //  Referenced by: '<S23>/Constant'

  px4_Bus_vehicle_status Out1_Y0_p;    // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S59>/Out1'

  px4_Bus_vehicle_status Constant_Value_n;// Computed Parameter: Constant_Value_n
                                             //  Referenced by: '<S48>/Constant'

  px4_Bus_distance_sensor Out1_Y0_pl;  // Computed Parameter: Out1_Y0_pl
                                          //  Referenced by: '<S57>/Out1'

  px4_Bus_distance_sensor Constant_Value_c;// Computed Parameter: Constant_Value_c
                                              //  Referenced by: '<S46>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S52>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_jh;// Computed Parameter: Constant_Value_jh
                                                //  Referenced by: '<S41>/Constant'

  px4_Bus_actuator_servos Out1_Y0_a;   // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S26>/Out1'

  px4_Bus_actuator_servos Constant_Value_n2;// Computed Parameter: Constant_Value_n2
                                               //  Referenced by: '<S24>/Constant'

  px4_Bus_vehicle_air_data Out1_Y0_pb; // Computed Parameter: Out1_Y0_pb
                                          //  Referenced by: '<S56>/Out1'

  px4_Bus_vehicle_air_data Constant_Value_b3;// Computed Parameter: Constant_Value_b3
                                                //  Referenced by: '<S45>/Constant'

  px4_Bus_vehicle_angular_velocity Out1_Y0_c;// Computed Parameter: Out1_Y0_c
                                                //  Referenced by: '<S53>/Out1'

  px4_Bus_vehicle_angular_velocity Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                       //  Referenced by: '<S42>/Constant'

  px4_Bus_airspeed Out1_Y0_b;          // Computed Parameter: Out1_Y0_b
                                          //  Referenced by: '<S55>/Out1'

  px4_Bus_airspeed Constant_Value_cn;  // Computed Parameter: Constant_Value_cn
                                          //  Referenced by: '<S44>/Constant'

  px4_Bus_actuator_armed Out1_Y0_n;    // Computed Parameter: Out1_Y0_n
                                          //  Referenced by: '<S36>/Out1'

  px4_Bus_actuator_armed Constant_Value_h1;// Computed Parameter: Constant_Value_h1
                                              //  Referenced by: '<S35>/Constant'

  real_T Constant6_Value;              // Expression: 1.423079
                                          //  Referenced by: '<S9>/Constant6'

  real_T Constant5_Value[7];           // Expression: zeros(7,1)
                                          //  Referenced by: '<S9>/Constant5'

  real_T Constant_Value_jd;            // Expression: 2
                                          //  Referenced by: '<S30>/Constant'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S33>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                          //  Referenced by: '<S33>/Discrete-Time Integrator'

  real_T Constant1_Value;              // Expression: 3
                                          //  Referenced by: '<S30>/Constant1'

  real_T Constant2_Value;              // Expression: 3
                                          //  Referenced by: '<S30>/Constant2'

  real_T Constant3_Value;              // Expression: 3
                                          //  Referenced by: '<S30>/Constant3'

  real_T Constant4_Value;              // Expression: 3
                                          //  Referenced by: '<S30>/Constant4'

  real_T Constant5_Value_a;            // Expression: 2
                                          //  Referenced by: '<S30>/Constant5'

  real_T Constant6_Value_g;            // Expression: 100
                                          //  Referenced by: '<S30>/Constant6'

  real_T Constant7_Value;              // Expression: 2
                                          //  Referenced by: '<S30>/Constant7'

  real_T Gain_Gain;                    // Expression: 1.943844
                                          //  Referenced by: '<S29>/Gain'

  real_T RateTransition1_InitialConditio;// Expression: 0
                                            //  Referenced by: '<S51>/Rate Transition1'

  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S10>/Memory'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S5>/Delay'

  real_T Delay1_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S5>/Delay1'

  real_T Switch_Threshold;             // Expression: 0.5
                                          //  Referenced by: '<S5>/Switch'

  real_T Switch_Threshold_f;           // Expression: 0
                                          //  Referenced by: '<S10>/Switch'

  real_T Switch1_Threshold;            // Expression: 0
                                          //  Referenced by: '<S9>/Switch1'

  real_T Constant3_Value_e[7];         // Expression: NaN(7,1)
                                          //  Referenced by: '<S5>/Constant3'

  real_T Constant1_Value_i[2];         // Expression: NaN(2,1)
                                          //  Referenced by: '<S5>/Constant1'

  real_T Constant1_Value_h[23];        // Expression: NaN(23,1)
                                          //  Referenced by: '<S72>/Constant1'

  real_T DelayOneStep_InitialCondition;// Expression: 0.0
                                          //  Referenced by: '<S51>/Delay One Step'

  real32_T Constant_Value_m[9];        // Computed Parameter: Constant_Value_m
                                          //  Referenced by: '<S71>/Constant'

  uint32_T Constant_Value_c3;          // Computed Parameter: Constant_Value_c3
                                          //  Referenced by: '<S19>/Constant'

  uint32_T Constant_Value_p;           // Computed Parameter: Constant_Value_p
                                          //  Referenced by: '<S21>/Constant'

  uint32_T Output_InitialCondition;
                                  // Computed Parameter: Output_InitialCondition
                                     //  Referenced by: '<S16>/Output'

  uint32_T Output_InitialCondition_c;
                                // Computed Parameter: Output_InitialCondition_c
                                   //  Referenced by: '<S17>/Output'

  uint32_T FixPtConstant_Value;       // Computed Parameter: FixPtConstant_Value
                                         //  Referenced by: '<S20>/FixPt Constant'

  uint32_T FixPtConstant_Value_i;   // Computed Parameter: FixPtConstant_Value_i
                                       //  Referenced by: '<S18>/FixPt Constant'

};

// Real-time Model Data Structure
struct tag_RTM_FCS_flight_Fixed_Wing_T {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;

  const char_T* getErrorStatus() const;
  void setErrorStatus(const char_T* const volatile aErrorStatus);
  boolean_T StepTask(int32_T idx) const;
  uint16_T &TaskCounter(int32_T idx);
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_FCS_flight_Fixed_Wing_T FCS_flight_Fixed_Wing_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_FCS_flight_Fixed_Wing_T FCS_flight_Fixed_Wing_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_FCS_flight_Fixed_Wing_T FCS_flight_Fixed_Wing_DW;

// External function called from main
#ifdef __cplusplus

extern "C"
{

#endif

  extern void FCS_flight_Fixed_Wing_SetEventsForThisBaseStep(boolean_T
    *eventFlags);

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void FCS_flight_Fixed_Wing_initialize(void);
  extern void FCS_flight_Fixed_Wing_step0(void);// Sample time: [0.005s, 0.0s]
  extern void FCS_flight_Fixed_Wing_step1(void);// Sample time: [1.0s, 0.0s]
  extern void FCS_flight_Fixed_Wing_step(int_T tid);
  extern void FCS_flight_Fixed_Wing_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_FCS_flight_Fixed_Win_T *const FCS_flight_Fixed_Wing_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S5>/Constant2' : Unused code path elimination
//  Block '<S9>/Scope3' : Unused code path elimination
//  Block '<S16>/FixPt Data Type Propagation' : Unused code path elimination
//  Block '<S18>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S19>/FixPt Data Type Duplicate1' : Unused code path elimination
//  Block '<S17>/FixPt Data Type Propagation' : Unused code path elimination
//  Block '<S20>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S21>/FixPt Data Type Duplicate1' : Unused code path elimination
//  Block '<S5>/Scope' : Unused code path elimination
//  Block '<S5>/Scope1' : Unused code path elimination
//  Block '<S5>/Scope2' : Unused code path elimination
//  Block '<S5>/Scope4' : Unused code path elimination
//  Block '<S5>/Scope5' : Unused code path elimination
//  Block '<S23>/NOT' : Unused code path elimination
//  Block '<S24>/NOT' : Unused code path elimination
//  Block '<S35>/NOT' : Unused code path elimination
//  Block '<S38>/Cast To Double' : Unused code path elimination
//  Block '<S38>/Cast To Double1' : Unused code path elimination
//  Block '<S38>/Cast To Double12' : Unused code path elimination
//  Block '<S38>/Cast To Double2' : Unused code path elimination
//  Block '<S38>/Cast To Double4' : Unused code path elimination
//  Block '<S38>/Cast To Double5' : Unused code path elimination
//  Block '<S38>/Cast To Double6' : Unused code path elimination
//  Block '<S38>/Cast To Double8' : Unused code path elimination
//  Block '<S29>/Cast To Double1' : Unused code path elimination
//  Block '<S29>/Cast To Double2' : Unused code path elimination
//  Block '<S29>/Cast To Double3' : Unused code path elimination
//  Block '<S29>/Cast To Double4' : Unused code path elimination
//  Block '<S29>/Cast To Double5' : Unused code path elimination
//  Block '<S29>/Cast To Double6' : Unused code path elimination
//  Block '<S29>/Cast To Double7' : Unused code path elimination
//  Block '<S41>/NOT' : Unused code path elimination
//  Block '<S42>/NOT' : Unused code path elimination
//  Block '<S43>/NOT' : Unused code path elimination
//  Block '<S44>/NOT' : Unused code path elimination
//  Block '<S45>/NOT' : Unused code path elimination
//  Block '<S46>/NOT' : Unused code path elimination
//  Block '<S47>/NOT' : Unused code path elimination
//  Block '<S48>/NOT' : Unused code path elimination
//  Block '<S50>/Cast To Double' : Unused code path elimination
//  Block '<S50>/Cast To Double1' : Unused code path elimination
//  Block '<S50>/Cast To Double10' : Unused code path elimination
//  Block '<S50>/Cast To Double11' : Unused code path elimination
//  Block '<S50>/Cast To Double12' : Unused code path elimination
//  Block '<S50>/Cast To Double13' : Unused code path elimination
//  Block '<S50>/Cast To Double14' : Unused code path elimination
//  Block '<S50>/Cast To Double15' : Unused code path elimination
//  Block '<S50>/Cast To Double16' : Unused code path elimination
//  Block '<S50>/Cast To Double17' : Unused code path elimination
//  Block '<S50>/Cast To Double18' : Unused code path elimination
//  Block '<S50>/Cast To Double19' : Unused code path elimination
//  Block '<S50>/Cast To Double2' : Unused code path elimination
//  Block '<S50>/Cast To Double20' : Unused code path elimination
//  Block '<S50>/Cast To Double21' : Unused code path elimination
//  Block '<S50>/Cast To Double22' : Unused code path elimination
//  Block '<S50>/Cast To Double23' : Unused code path elimination
//  Block '<S50>/Cast To Double3' : Unused code path elimination
//  Block '<S50>/Cast To Double4' : Unused code path elimination
//  Block '<S50>/Cast To Double5' : Unused code path elimination
//  Block '<S50>/Cast To Double6' : Unused code path elimination
//  Block '<S50>/Cast To Double7' : Unused code path elimination
//  Block '<S50>/Cast To Double8' : Unused code path elimination
//  Block '<S50>/Cast To Double9' : Unused code path elimination
//  Block '<S30>/Display' : Unused code path elimination
//  Block '<S30>/Display1' : Unused code path elimination
//  Block '<S30>/Display2' : Unused code path elimination
//  Block '<S30>/Display3' : Unused code path elimination
//  Block '<S30>/Display4' : Unused code path elimination
//  Block '<S30>/Display5' : Unused code path elimination
//  Block '<S30>/Display6' : Unused code path elimination
//  Block '<S30>/Display7' : Unused code path elimination
//  Block '<S30>/Display8' : Unused code path elimination
//  Block '<S69>/NOT' : Unused code path elimination
//  Block '<S71>/Scope1' : Unused code path elimination
//  Block '<S5>/Cast To Double' : Eliminate redundant data type conversion
//  Block '<S5>/Cast To Double1' : Eliminate redundant data type conversion
//  Block '<S31>/Cast To Double1' : Eliminate redundant data type conversion
//  Block '<S33>/Cast To Double' : Eliminate redundant data type conversion
//  Block '<S71>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S71>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S71>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S71>/Data Type Conversion4' : Eliminate redundant data type conversion
//  Block '<S71>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<S71>/Data Type Conversion6' : Eliminate redundant data type conversion
//  Block '<S72>/Reshape2' : Reshape block reduction


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'FCS_flight_Fixed_Wing'
//  '<S1>'   : 'FCS_flight_Fixed_Wing/FCS'
//  '<S2>'   : 'FCS_flight_Fixed_Wing/FCS In'
//  '<S3>'   : 'FCS_flight_Fixed_Wing/FCS Out'
//  '<S4>'   : 'FCS_flight_Fixed_Wing/Model Info'
//  '<S5>'   : 'FCS_flight_Fixed_Wing/FCS/OL PTI'
//  '<S6>'   : 'FCS_flight_Fixed_Wing/FCS/PX4 Control'
//  '<S7>'   : 'FCS_flight_Fixed_Wing/FCS/OL PTI/MATLAB Function'
//  '<S8>'   : 'FCS_flight_Fixed_Wing/FCS/OL PTI/MATLAB Function2'
//  '<S9>'   : 'FCS_flight_Fixed_Wing/FCS/OL PTI/Multisine'
//  '<S10>'  : 'FCS_flight_Fixed_Wing/FCS/OL PTI/PTI Clock1'
//  '<S11>'  : 'FCS_flight_Fixed_Wing/FCS/OL PTI/Subsystem'
//  '<S12>'  : 'FCS_flight_Fixed_Wing/FCS/OL PTI/Subsystem1'
//  '<S13>'  : 'FCS_flight_Fixed_Wing/FCS/OL PTI/Subsystem2'
//  '<S14>'  : 'FCS_flight_Fixed_Wing/FCS/OL PTI/Subsystem3'
//  '<S15>'  : 'FCS_flight_Fixed_Wing/FCS/OL PTI/Multisine/MS'
//  '<S16>'  : 'FCS_flight_Fixed_Wing/FCS/OL PTI/PTI Clock1/Counter Free-Running'
//  '<S17>'  : 'FCS_flight_Fixed_Wing/FCS/OL PTI/PTI Clock1/Counter Free-Running1'
//  '<S18>'  : 'FCS_flight_Fixed_Wing/FCS/OL PTI/PTI Clock1/Counter Free-Running/Increment Real World'
//  '<S19>'  : 'FCS_flight_Fixed_Wing/FCS/OL PTI/PTI Clock1/Counter Free-Running/Wrap To Zero'
//  '<S20>'  : 'FCS_flight_Fixed_Wing/FCS/OL PTI/PTI Clock1/Counter Free-Running1/Increment Real World'
//  '<S21>'  : 'FCS_flight_Fixed_Wing/FCS/OL PTI/PTI Clock1/Counter Free-Running1/Wrap To Zero'
//  '<S22>'  : 'FCS_flight_Fixed_Wing/FCS/OL PTI/Subsystem1/MATLAB Function'
//  '<S23>'  : 'FCS_flight_Fixed_Wing/FCS/PX4 Control/PX4 uORB Read'
//  '<S24>'  : 'FCS_flight_Fixed_Wing/FCS/PX4 Control/PX4 uORB Read1'
//  '<S25>'  : 'FCS_flight_Fixed_Wing/FCS/PX4 Control/PX4 uORB Read/Enabled Subsystem'
//  '<S26>'  : 'FCS_flight_Fixed_Wing/FCS/PX4 Control/PX4 uORB Read1/Enabled Subsystem'
//  '<S27>'  : 'FCS_flight_Fixed_Wing/FCS In/Arm'
//  '<S28>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Params'
//  '<S29>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors'
//  '<S30>'  : 'FCS_flight_Fixed_Wing/FCS In/Read RC'
//  '<S31>'  : 'FCS_flight_Fixed_Wing/FCS In/Arm/Subsystem'
//  '<S32>'  : 'FCS_flight_Fixed_Wing/FCS In/Arm/Subsystem1'
//  '<S33>'  : 'FCS_flight_Fixed_Wing/FCS In/Arm/Subsystem2'
//  '<S34>'  : 'FCS_flight_Fixed_Wing/FCS In/Arm/Subsystem/Compare To Constant'
//  '<S35>'  : 'FCS_flight_Fixed_Wing/FCS In/Arm/Subsystem1/PX4 uORB Read'
//  '<S36>'  : 'FCS_flight_Fixed_Wing/FCS In/Arm/Subsystem1/PX4 uORB Read/Enabled Subsystem'
//  '<S37>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Params/Subsystem1'
//  '<S38>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Params/Subsystem2'
//  '<S39>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Params/Subsystem3'
//  '<S40>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/MATLAB Function'
//  '<S41>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read'
//  '<S42>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read1'
//  '<S43>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read2'
//  '<S44>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read3'
//  '<S45>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read4'
//  '<S46>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read5'
//  '<S47>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read6'
//  '<S48>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read7'
//  '<S49>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/Subsystem'
//  '<S50>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/Subsystem1'
//  '<S51>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/Subsystem2'
//  '<S52>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read/Enabled Subsystem'
//  '<S53>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read1/Enabled Subsystem'
//  '<S54>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read2/Enabled Subsystem'
//  '<S55>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read3/Enabled Subsystem'
//  '<S56>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read4/Enabled Subsystem'
//  '<S57>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read5/Enabled Subsystem'
//  '<S58>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read6/Enabled Subsystem'
//  '<S59>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/PX4 uORB Read7/Enabled Subsystem'
//  '<S60>'  : 'FCS_flight_Fixed_Wing/FCS In/Read PX4 Sensors/Subsystem/MATLAB Function'
//  '<S61>'  : 'FCS_flight_Fixed_Wing/FCS In/Read RC/MATLAB Function'
//  '<S62>'  : 'FCS_flight_Fixed_Wing/FCS In/Read RC/MATLAB Function1'
//  '<S63>'  : 'FCS_flight_Fixed_Wing/FCS In/Read RC/MATLAB Function2'
//  '<S64>'  : 'FCS_flight_Fixed_Wing/FCS In/Read RC/MATLAB Function3'
//  '<S65>'  : 'FCS_flight_Fixed_Wing/FCS In/Read RC/MATLAB Function4'
//  '<S66>'  : 'FCS_flight_Fixed_Wing/FCS In/Read RC/MATLAB Function5'
//  '<S67>'  : 'FCS_flight_Fixed_Wing/FCS In/Read RC/MATLAB Function6'
//  '<S68>'  : 'FCS_flight_Fixed_Wing/FCS In/Read RC/MATLAB Function7'
//  '<S69>'  : 'FCS_flight_Fixed_Wing/FCS In/Read RC/PX4 uORB Read'
//  '<S70>'  : 'FCS_flight_Fixed_Wing/FCS In/Read RC/PX4 uORB Read/Enabled Subsystem'
//  '<S71>'  : 'FCS_flight_Fixed_Wing/FCS Out/Send Actuator Cmds'
//  '<S72>'  : 'FCS_flight_Fixed_Wing/FCS Out/Send GCS Data'
//  '<S73>'  : 'FCS_flight_Fixed_Wing/FCS Out/Write ULOG Data'
//  '<S74>'  : 'FCS_flight_Fixed_Wing/FCS Out/Send Actuator Cmds/MATLAB Function'
//  '<S75>'  : 'FCS_flight_Fixed_Wing/FCS Out/Send GCS Data/PX4 uORB Message'
//  '<S76>'  : 'FCS_flight_Fixed_Wing/FCS Out/Send GCS Data/PX4 uORB Write'

#endif                                 // FCS_flight_Fixed_Wing_h_

//
// File trailer for generated code.
//
// [EOF]
//
