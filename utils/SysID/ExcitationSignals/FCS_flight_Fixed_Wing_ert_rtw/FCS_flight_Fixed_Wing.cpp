//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_flight_Fixed_Wing.cpp
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
#include "rtwtypes.h"
#include "FCS_flight_Fixed_Wing_types.h"
#include "FCS_flight_Fixed_Wing_private.h"
#include <math.h>
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

// Block signals (default storage)
B_FCS_flight_Fixed_Wing_T FCS_flight_Fixed_Wing_B;

// Block states (default storage)
DW_FCS_flight_Fixed_Wing_T FCS_flight_Fixed_Wing_DW;

// Real-time model
RT_MODEL_FCS_flight_Fixed_Win_T FCS_flight_Fixed_Wing_M_ =
  RT_MODEL_FCS_flight_Fixed_Win_T();
RT_MODEL_FCS_flight_Fixed_Win_T *const FCS_flight_Fixed_Wing_M =
  &FCS_flight_Fixed_Wing_M_;

// Forward declaration for local functions
static void FCS_flig_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void FCS_flight_Fixed_Wing_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)FCS_flight_Fixed_Wing_M->StepTask(1));
}

//
//         This function updates active task flag for each subrate
//         and rate transition flags for tasks that exchange data.
//         The function assumes rate-monotonic multitasking scheduler.
//         The function must be called at model base rate so that
//         the generated code self-manages all its subrates and rate
//         transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // To ensure a deterministic data transfer between two rates,
  //  data is transferred at the priority of a fast task and the frequency
  //  of the slow task.  The following flags indicate when the data transfer
  //  happens.  That is, a rate interaction flag is set true when both rates
  //  will run, and false otherwise.


  // tid 0 shares data with slower tid rate: 1
  FCS_flight_Fixed_Wing_M->Timing.RateInteraction.TID0_1 =
    (FCS_flight_Fixed_Wing_M->Timing.TaskCounters.TID[1] == 0);

  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (FCS_flight_Fixed_Wing_M->Timing.TaskCounters.TID[1])++;
  if ((FCS_flight_Fixed_Wing_M->Timing.TaskCounters.TID[1]) > 199) {// Sample time: [1.0s, 0.0s] 
    FCS_flight_Fixed_Wing_M->Timing.TaskCounters.TID[1] = 0;
  }
}

//
// Output and update for atomic system:
//    '<S30>/MATLAB Function'
//    '<S30>/MATLAB Function1'
//    '<S30>/MATLAB Function2'
//    '<S30>/MATLAB Function3'
//    '<S30>/MATLAB Function4'
//    '<S30>/MATLAB Function5'
//    '<S30>/MATLAB Function6'
//    '<S30>/MATLAB Function7'
//
void FCS_flight_F_MATLABFunction(real_T rtu_u, real_T rtu_type, real_T *rty_y)
{
  if (rtu_type == 2.0) {
    *rty_y = (rtu_u <= -0.5);
  } else if (rtu_type == 3.0) {
    if (rtu_u <= -0.5) {
      *rty_y = 2.0;
    } else {
      *rty_y = ((rtu_u > -0.5) && (rtu_u <= 0.5));
    }
  } else if (rtu_type == 100.0) {
    if (rtu_u < -1.0) {
      *rty_y = 0.0;
    } else if (rtu_u > 1.0) {
      *rty_y = 1.0;
    } else {
      *rty_y = (rtu_u + 1.0) / 2.0;
    }
  } else {
    *rty_y = 0.0;
  }
}

static void FCS_flig_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj)
{
  int32_T n;
  int32_T n_0;
  obj->ValidMotorIdx[0] = true;
  obj->ValidServoIdx[0] = true;
  obj->ValidServoIdx[1] = true;
  obj->ValidServoIdx[2] = true;
  obj->ValidServoIdx[3] = true;
  obj->ValidServoIdx[4] = true;
  obj->ValidServoIdx[5] = true;
  n = 0;
  for (int32_T b_k = 0; b_k < 12; b_k++) {
    // Start for MATLABSystem: '<S71>/PX4 Actuator Write'
    if (obj->ValidMotorIdx[b_k]) {
      n++;
    }
  }

  n_0 = 0;
  for (int32_T b_k = 0; b_k < 8; b_k++) {
    // Start for MATLABSystem: '<S71>/PX4 Actuator Write'
    if (obj->ValidServoIdx[b_k]) {
      n_0++;
    }
  }

  // Start for MATLABSystem: '<S71>/PX4 Actuator Write'
  obj->QSize = static_cast<uint8_T>(n + n_0);
  MW_actuators_init(obj->QSize);
}

// Model step function for TID0
void FCS_flight_Fixed_Wing_step0(void) // Sample time: [0.005s, 0.0s]
{
  int32_T kk;
  static real_T b[16] = { -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  real_T rtb_t_out_idx_0;
  int32_T i;
  int32_T rtb_arm;
  int32_T rtb_reset_needed;
  int32_T rtb_u_tmp;
  real32_T ParamStep;
  real32_T ParamStep_0;
  real32_T ParamStep_1;
  real32_T ParamStep_2;
  real32_T ParamStep_3;
  real32_T ParamStep_4;
  uint32_T tmp_0;
  boolean_T b_varargout_1;
  boolean_T tmp;
  static const int8_T indicesForNan[8] = { 8, 9, 10, 11, 12, 13, 14, 15 };

  {                                    // Sample time: [0.005s, 0.0s]
    rate_monotonic_scheduler();
  }

  for (rtb_arm = 0; rtb_arm < 8; rtb_arm++) {
    b[indicesForNan[rtb_arm]] = (rtNaN);
  }

  // MATLABSystem: '<S35>/SourceBlock'
  b_varargout_1 = uORB_read_step(FCS_flight_Fixed_Wing_DW.obj_l.orbMetadataObj,
    &FCS_flight_Fixed_Wing_DW.obj_l.eventStructObj, &FCS_flight_Fixed_Wing_B.r11,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S35>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S36>/Enable'

  // Start for MATLABSystem: '<S35>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S36>/In1'
    FCS_flight_Fixed_Wing_B.In1_jq = FCS_flight_Fixed_Wing_B.r11;
  }

  // End of Outputs for SubSystem: '<S35>/Enabled Subsystem'

  // MATLABSystem: '<S69>/SourceBlock'
  b_varargout_1 = uORB_read_step(FCS_flight_Fixed_Wing_DW.obj_b.orbMetadataObj,
    &FCS_flight_Fixed_Wing_DW.obj_b.eventStructObj, &FCS_flight_Fixed_Wing_B.r2,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S69>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S70>/Enable'

  // Start for MATLABSystem: '<S69>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S70>/In1'
    FCS_flight_Fixed_Wing_B.In1 = FCS_flight_Fixed_Wing_B.r2;
  }

  // End of Outputs for SubSystem: '<S69>/Enabled Subsystem'

  // DataTypeConversion: '<S30>/Data Type Conversion23'
  for (i = 0; i < 18; i++) {
    FCS_flight_Fixed_Wing_B.DataTypeConversion23[i] =
      FCS_flight_Fixed_Wing_B.In1.channels[i];
  }

  // End of DataTypeConversion: '<S30>/Data Type Conversion23'

  // MATLAB Function: '<S30>/MATLAB Function' incorporates:
  //   Constant: '<S30>/Constant'

  FCS_flight_F_MATLABFunction(FCS_flight_Fixed_Wing_B.DataTypeConversion23[6],
    FCS_flight_Fixed_Wing_P.Constant_Value_jd, &FCS_flight_Fixed_Wing_B.y_h);

  // Product: '<S27>/Product' incorporates:
  //   Constant: '<S34>/Constant'
  //   DataTypeConversion: '<S31>/Cast To Double2'
  //   DataTypeConversion: '<S32>/Cast To Double'
  //   RelationalOperator: '<S34>/Compare'

  rtb_arm = (FCS_flight_Fixed_Wing_B.y_h <=
             FCS_flight_Fixed_Wing_P.CompareToConstant_const) *
    FCS_flight_Fixed_Wing_B.In1_jq.armed;

  // DiscreteIntegrator: '<S33>/Discrete-Time Integrator'
  if (((rtb_arm > 0) &&
       (FCS_flight_Fixed_Wing_DW.DiscreteTimeIntegrator_PrevRese <= 0)) ||
      ((rtb_arm <= 0) &&
       (FCS_flight_Fixed_Wing_DW.DiscreteTimeIntegrator_PrevRese == 1))) {
    FCS_flight_Fixed_Wing_DW.DiscreteTimeIntegrator_DSTATE =
      FCS_flight_Fixed_Wing_P.DiscreteTimeIntegrator_IC;
  }

  // MATLAB Function: '<S30>/MATLAB Function1' incorporates:
  //   Constant: '<S30>/Constant1'

  FCS_flight_F_MATLABFunction(FCS_flight_Fixed_Wing_B.DataTypeConversion23[11],
    FCS_flight_Fixed_Wing_P.Constant1_Value, &FCS_flight_Fixed_Wing_B.Switch_m);

  // MATLAB Function: '<S30>/MATLAB Function2' incorporates:
  //   Constant: '<S30>/Constant2'

  FCS_flight_F_MATLABFunction(FCS_flight_Fixed_Wing_B.DataTypeConversion23[5],
    FCS_flight_Fixed_Wing_P.Constant2_Value, &FCS_flight_Fixed_Wing_B.Memory);

  // MATLAB Function: '<S30>/MATLAB Function3' incorporates:
  //   Constant: '<S30>/Constant3'

  FCS_flight_F_MATLABFunction(FCS_flight_Fixed_Wing_B.DataTypeConversion23[9],
    FCS_flight_Fixed_Wing_P.Constant3_Value, &FCS_flight_Fixed_Wing_B.y_c);

  // MATLAB Function: '<S30>/MATLAB Function4' incorporates:
  //   Constant: '<S30>/Constant4'

  FCS_flight_F_MATLABFunction(FCS_flight_Fixed_Wing_B.DataTypeConversion23[10],
    FCS_flight_Fixed_Wing_P.Constant4_Value, &FCS_flight_Fixed_Wing_B.y_b);

  // MATLAB Function: '<S30>/MATLAB Function5' incorporates:
  //   Constant: '<S30>/Constant5'

  FCS_flight_F_MATLABFunction(FCS_flight_Fixed_Wing_B.DataTypeConversion23[7],
    FCS_flight_Fixed_Wing_P.Constant5_Value_a, &FCS_flight_Fixed_Wing_B.y_g);

  // MATLAB Function: '<S30>/MATLAB Function6' incorporates:
  //   Constant: '<S30>/Constant6'

  FCS_flight_F_MATLABFunction(FCS_flight_Fixed_Wing_B.DataTypeConversion23[8],
    FCS_flight_Fixed_Wing_P.Constant6_Value_g, &FCS_flight_Fixed_Wing_B.y_f);

  // MATLAB Function: '<S30>/MATLAB Function7' incorporates:
  //   Constant: '<S30>/Constant7'

  FCS_flight_F_MATLABFunction(FCS_flight_Fixed_Wing_B.DataTypeConversion23[4],
    FCS_flight_Fixed_Wing_P.Constant7_Value,
    &FCS_flight_Fixed_Wing_B.CastToDouble_b);

  // MATLABSystem: '<S46>/SourceBlock'
  b_varargout_1 = uORB_read_step(FCS_flight_Fixed_Wing_DW.obj_d.orbMetadataObj,
    &FCS_flight_Fixed_Wing_DW.obj_d.eventStructObj, &FCS_flight_Fixed_Wing_B.r6,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S46>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S57>/Enable'

  // Start for MATLABSystem: '<S46>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S57>/In1'
    FCS_flight_Fixed_Wing_B.In1_p = FCS_flight_Fixed_Wing_B.r6;
  }

  // End of Outputs for SubSystem: '<S46>/Enabled Subsystem'

  // MATLABSystem: '<S44>/SourceBlock'
  b_varargout_1 = uORB_read_step(FCS_flight_Fixed_Wing_DW.obj_n.orbMetadataObj,
    &FCS_flight_Fixed_Wing_DW.obj_n.eventStructObj, &FCS_flight_Fixed_Wing_B.r10,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S44>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S55>/Enable'

  // Start for MATLABSystem: '<S44>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S55>/In1'
    FCS_flight_Fixed_Wing_B.In1_e = FCS_flight_Fixed_Wing_B.r10;
  }

  // End of Outputs for SubSystem: '<S44>/Enabled Subsystem'

  // MATLABSystem: '<S45>/SourceBlock'
  b_varargout_1 = uORB_read_step(FCS_flight_Fixed_Wing_DW.obj_hm.orbMetadataObj,
    &FCS_flight_Fixed_Wing_DW.obj_hm.eventStructObj, &FCS_flight_Fixed_Wing_B.r9,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S45>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S56>/Enable'

  // Start for MATLABSystem: '<S45>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S56>/In1'
    FCS_flight_Fixed_Wing_B.In1_jb = FCS_flight_Fixed_Wing_B.r9;
  }

  // End of Outputs for SubSystem: '<S45>/Enabled Subsystem'

  // RateTransition: '<S51>/Rate Transition1' incorporates:
  //   RateTransition: '<S51>/Rate Transition'

  tmp = FCS_flight_Fixed_Wing_M->Timing.RateInteraction.TID0_1;
  if (tmp) {
    // RateTransition: '<S51>/Rate Transition1'
    FCS_flight_Fixed_Wing_B.RateTransition1 =
      FCS_flight_Fixed_Wing_DW.RateTransition1_Buffer0;
  }

  // End of RateTransition: '<S51>/Rate Transition1'

  // MATLABSystem: '<S49>/Read Parameter'
  b_varargout_1 = MW_ParamRead_Step
    (FCS_flight_Fixed_Wing_DW.obj_oh.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
  if (b_varargout_1) {
    ParamStep = 0.0F;
  }

  // MATLABSystem: '<S39>/Read Parameter'
  b_varargout_1 = MW_ParamRead_Step
    (FCS_flight_Fixed_Wing_DW.obj_j0.MW_PARAMHANDLE, MW_SINGLE, &ParamStep_0);
  if (b_varargout_1) {
    ParamStep_0 = 0.0F;
  }

  // MATLABSystem: '<S39>/Read Parameter1'
  b_varargout_1 = MW_ParamRead_Step
    (FCS_flight_Fixed_Wing_DW.obj_cf.MW_PARAMHANDLE, MW_SINGLE, &ParamStep_1);
  if (b_varargout_1) {
    ParamStep_1 = 0.0F;
  }

  // MATLABSystem: '<S39>/Read Parameter8'
  b_varargout_1 = MW_ParamRead_Step
    (FCS_flight_Fixed_Wing_DW.obj_e.MW_PARAMHANDLE, MW_SINGLE, &ParamStep_2);
  if (b_varargout_1) {
    ParamStep_2 = 0.0F;
  }

  // MATLABSystem: '<S23>/SourceBlock'
  b_varargout_1 = uORB_read_step(FCS_flight_Fixed_Wing_DW.obj_c.orbMetadataObj,
    &FCS_flight_Fixed_Wing_DW.obj_c.eventStructObj, &FCS_flight_Fixed_Wing_B.r3,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S23>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S25>/Enable'

  // Start for MATLABSystem: '<S23>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S25>/In1'
    FCS_flight_Fixed_Wing_B.In1_i = FCS_flight_Fixed_Wing_B.r3;
  }

  // End of Outputs for SubSystem: '<S23>/Enabled Subsystem'

  // MATLABSystem: '<S24>/SourceBlock'
  b_varargout_1 = uORB_read_step(FCS_flight_Fixed_Wing_DW.obj_jl.orbMetadataObj,
    &FCS_flight_Fixed_Wing_DW.obj_jl.eventStructObj, &FCS_flight_Fixed_Wing_B.r7,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S24>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S26>/Enable'

  // Start for MATLABSystem: '<S24>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S26>/In1'
    FCS_flight_Fixed_Wing_B.In1_io = FCS_flight_Fixed_Wing_B.r7;
  }

  // End of Outputs for SubSystem: '<S24>/Enabled Subsystem'

  // MATLABSystem: '<S48>/SourceBlock'
  b_varargout_1 = uORB_read_step(FCS_flight_Fixed_Wing_DW.obj_p.orbMetadataObj,
    &FCS_flight_Fixed_Wing_DW.obj_p.eventStructObj, &FCS_flight_Fixed_Wing_B.r4,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S48>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S59>/Enable'

  // Start for MATLABSystem: '<S48>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S59>/In1'
    FCS_flight_Fixed_Wing_B.In1_k = FCS_flight_Fixed_Wing_B.r4;
  }

  // End of Outputs for SubSystem: '<S48>/Enabled Subsystem'

  // MATLAB Function: '<S5>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<S29>/Cast To Double11'
  //   Delay: '<S5>/Delay'
  //   Delay: '<S5>/Delay1'

  i = 0;
  rtb_reset_needed = 0;
  if ((FCS_flight_Fixed_Wing_DW.Delay1_DSTATE[0U] == 1.0) &&
      (FCS_flight_Fixed_Wing_B.y_g == 1.0)) {
    rtb_reset_needed = 1;
  } else {
    if (FCS_flight_Fixed_Wing_B.y_g == 1.0) {
      i = 1;
    }

    if (FCS_flight_Fixed_Wing_B.In1_k.nav_state !=
        FCS_flight_Fixed_Wing_DW.Delay_DSTATE[0U]) {
      i = 0;
      rtb_reset_needed = 1;
    }
  }

  // End of MATLAB Function: '<S5>/MATLAB Function'

  // MATLABSystem: '<S38>/Read Parameter13'
  b_varargout_1 = MW_ParamRead_Step
    (FCS_flight_Fixed_Wing_DW.obj_jv.MW_PARAMHANDLE, MW_SINGLE, &ParamStep_3);
  if (b_varargout_1) {
    ParamStep_3 = 0.0F;
  }

  // Switch: '<S5>/Switch' incorporates:
  //   DataTypeConversion: '<S38>/Cast To Double13'
  //   MATLABSystem: '<S38>/Read Parameter13'
  //
  if (ParamStep_3 > FCS_flight_Fixed_Wing_P.Switch_Threshold) {
    FCS_flight_Fixed_Wing_B.Sum = i;
  } else {
    FCS_flight_Fixed_Wing_B.Sum = FCS_flight_Fixed_Wing_B.y_g;
  }

  // Switch: '<S10>/Switch' incorporates:
  //   Switch: '<S5>/Switch'

  if (!(FCS_flight_Fixed_Wing_B.Sum > FCS_flight_Fixed_Wing_P.Switch_Threshold_f))
  {
    // Gain: '<S10>/Gain1'
    FCS_flight_Fixed_Wing_B.Sum = FCS_flight_Fixed_Wing_P.FC.samp_time *
      5.49755813888E+11;
    rtb_t_out_idx_0 = fabs(FCS_flight_Fixed_Wing_B.Sum);
    if (rtb_t_out_idx_0 < 4.503599627370496E+15) {
      if (rtb_t_out_idx_0 >= 0.5) {
        FCS_flight_Fixed_Wing_B.Sum = floor(FCS_flight_Fixed_Wing_B.Sum + 0.5);
      } else {
        FCS_flight_Fixed_Wing_B.Sum *= 0.0;
      }
    }

    if (FCS_flight_Fixed_Wing_B.Sum < 4.294967296E+9) {
      if (FCS_flight_Fixed_Wing_B.Sum >= 0.0) {
        tmp_0 = static_cast<uint32_T>(FCS_flight_Fixed_Wing_B.Sum);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint32_T;
    }

    // Switch: '<S10>/Switch' incorporates:
    //   Gain: '<S10>/Gain1'
    //   UnitDelay: '<S17>/Output'

    FCS_flight_Fixed_Wing_DW.Memory_PreviousInput = static_cast<real_T>(tmp_0) *
      1.8189894035458565E-12 * static_cast<real_T>
      (FCS_flight_Fixed_Wing_DW.Output_DSTATE_k);
  }

  // End of Switch: '<S10>/Switch'

  // Gain: '<S10>/Gain'
  FCS_flight_Fixed_Wing_B.Sum = FCS_flight_Fixed_Wing_P.FC.samp_time *
    5.49755813888E+11;
  rtb_t_out_idx_0 = fabs(FCS_flight_Fixed_Wing_B.Sum);
  if (rtb_t_out_idx_0 < 4.503599627370496E+15) {
    if (rtb_t_out_idx_0 >= 0.5) {
      FCS_flight_Fixed_Wing_B.Sum = floor(FCS_flight_Fixed_Wing_B.Sum + 0.5);
    } else {
      FCS_flight_Fixed_Wing_B.Sum *= 0.0;
    }
  }

  if (FCS_flight_Fixed_Wing_B.Sum < 4.294967296E+9) {
    if (FCS_flight_Fixed_Wing_B.Sum >= 0.0) {
      tmp_0 = static_cast<uint32_T>(FCS_flight_Fixed_Wing_B.Sum);
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint32_T;
  }

  // Sum: '<S10>/Sum' incorporates:
  //   Gain: '<S10>/Gain'
  //   UnitDelay: '<S16>/Output'

  FCS_flight_Fixed_Wing_B.Sum = static_cast<real_T>(tmp_0) *
    1.8189894035458565E-12 * static_cast<real_T>
    (FCS_flight_Fixed_Wing_DW.Output_DSTATE) -
    FCS_flight_Fixed_Wing_DW.Memory_PreviousInput;

  // MATLAB Function: '<S5>/MATLAB Function2'
  if (FCS_flight_Fixed_Wing_B.y_b == 0.0) {
    rtb_t_out_idx_0 = FCS_flight_Fixed_Wing_B.Sum;
  } else {
    rtb_t_out_idx_0 = 0.0;
  }

  // MATLAB Function: '<S9>/MS' incorporates:
  //   Constant: '<S9>/Constant'
  //   Constant: '<S9>/Constant1'
  //   Constant: '<S9>/Constant7'

  for (i = 0; i < 7; i++) {
    FCS_flight_Fixed_Wing_B.rtb_u_c = 0.0;
    for (kk = 0; kk < 11; kk++) {
      rtb_u_tmp = 11 * i + kk;
      FCS_flight_Fixed_Wing_B.rtb_u_c += sin
        (FCS_flight_Fixed_Wing_P.MS.f[rtb_u_tmp] * 6.2831853071795862 *
         rtb_t_out_idx_0 + FCS_flight_Fixed_Wing_P.MS.ph[rtb_u_tmp]) * sqrt
        (FCS_flight_Fixed_Wing_P.MS.pwr[rtb_u_tmp]);
    }

    FCS_flight_Fixed_Wing_B.u[i] = FCS_flight_Fixed_Wing_B.rtb_u_c;
  }

  // End of MATLAB Function: '<S9>/MS'

  // MATLABSystem: '<S38>/Read Parameter7'
  b_varargout_1 = MW_ParamRead_Step
    (FCS_flight_Fixed_Wing_DW.obj_l0.MW_PARAMHANDLE, MW_SINGLE, &ParamStep_3);
  if (b_varargout_1) {
    ParamStep_3 = 0.0F;
  }

  // MATLABSystem: '<S38>/Read Parameter11'
  b_varargout_1 = MW_ParamRead_Step
    (FCS_flight_Fixed_Wing_DW.obj_az.MW_PARAMHANDLE, MW_SINGLE, &ParamStep_4);
  if (b_varargout_1) {
    ParamStep_4 = 0.0F;
  }

  // Switch: '<S9>/Switch1' incorporates:
  //   Constant: '<S9>/Constant5'
  //   DataTypeConversion: '<S38>/Cast To Double7'
  //   MATLABSystem: '<S38>/Read Parameter7'
  //   Product: '<S9>/Product1'
  //   Product: '<S9>/Product5'
  //   Reshape: '<S72>/Reshape3'
  //   Sum: '<S9>/Sum2'
  //
  if (rtb_t_out_idx_0 > FCS_flight_Fixed_Wing_P.Switch1_Threshold) {
    // Product: '<S9>/Divide' incorporates:
    //   Constant: '<S9>/Constant6'

    for (i = 0; i < 7; i++) {
      FCS_flight_Fixed_Wing_B.u[i] /= FCS_flight_Fixed_Wing_P.Constant6_Value;
    }

    // End of Product: '<S9>/Divide'

    // Product: '<S9>/Product3' incorporates:
    //   DataTypeConversion: '<S38>/Cast To Double11'
    //   MATLABSystem: '<S38>/Read Parameter11'
    //
    rtb_t_out_idx_0 = FCS_flight_Fixed_Wing_B.y_f * ParamStep_4;

    // Product: '<S9>/Product2'
    for (i = 0; i < 6; i++) {
      FCS_flight_Fixed_Wing_B.Product2[i] = FCS_flight_Fixed_Wing_B.u[i] *
        rtb_t_out_idx_0;
    }

    // End of Product: '<S9>/Product2'
    FCS_flight_Fixed_Wing_B.Reshape3[0] = FCS_flight_Fixed_Wing_B.u[6] *
      ParamStep_3;
    FCS_flight_Fixed_Wing_B.Reshape3[1] = FCS_flight_Fixed_Wing_B.Product2[0];
    FCS_flight_Fixed_Wing_B.Reshape3[2] = FCS_flight_Fixed_Wing_B.Product2[1];
    FCS_flight_Fixed_Wing_B.Reshape3[3] = FCS_flight_Fixed_Wing_B.Product2[2];
    FCS_flight_Fixed_Wing_B.Reshape3[4] = FCS_flight_Fixed_Wing_B.Product2[3];
    FCS_flight_Fixed_Wing_B.Reshape3[5] = FCS_flight_Fixed_Wing_B.Product2[4] -
      rtb_t_out_idx_0;
    FCS_flight_Fixed_Wing_B.Reshape3[6] = FCS_flight_Fixed_Wing_B.Product2[5] -
      rtb_t_out_idx_0;
  } else {
    for (i = 0; i < 7; i++) {
      FCS_flight_Fixed_Wing_B.Reshape3[i] =
        FCS_flight_Fixed_Wing_P.Constant5_Value[i];
    }
  }

  // End of Switch: '<S9>/Switch1'

  // Sum: '<S5>/Sum' incorporates:
  //   Constant: '<S5>/Constant1'
  //   Constant: '<S5>/Constant3'
  //   DataTypeConversion: '<S6>/Cast To Double'
  //   DataTypeConversion: '<S6>/Cast To Double1'

  FCS_flight_Fixed_Wing_B.Sum_l[0] = FCS_flight_Fixed_Wing_B.In1_i.control[0] +
    FCS_flight_Fixed_Wing_B.Reshape3[0];
  for (i = 0; i < 7; i++) {
    FCS_flight_Fixed_Wing_B.Sum_l[i + 1] =
      FCS_flight_Fixed_Wing_B.In1_i.control[i + 1] +
      FCS_flight_Fixed_Wing_P.Constant3_Value_e[i];
  }

  for (i = 0; i < 6; i++) {
    FCS_flight_Fixed_Wing_B.Sum_l[i + 8] = FCS_flight_Fixed_Wing_B.Reshape3[i +
      1] + FCS_flight_Fixed_Wing_B.In1_io.control[i];
  }

  FCS_flight_Fixed_Wing_B.Sum_l[14] = FCS_flight_Fixed_Wing_B.In1_io.control[6]
    + FCS_flight_Fixed_Wing_P.Constant1_Value_i[0];
  FCS_flight_Fixed_Wing_B.Sum_l[15] = FCS_flight_Fixed_Wing_B.In1_io.control[7]
    + FCS_flight_Fixed_Wing_P.Constant1_Value_i[1];

  // End of Sum: '<S5>/Sum'

  // MATLAB Function: '<S12>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S39>/Read Parameter'
  //   MATLABSystem: '<S39>/Read Parameter1'
  //   MATLABSystem: '<S39>/Read Parameter8'
  //
  rtb_t_out_idx_0 = ParamStep_1;
  FCS_flight_Fixed_Wing_B.rtb_u_c = ParamStep_2;
  memcpy(&FCS_flight_Fixed_Wing_B.Manual_Actuator_Out[0], &b[0], sizeof(real_T) <<
         4U);
  if ((ParamStep_2 < 0.0F) || (ParamStep_2 > 1.0F)) {
    FCS_flight_Fixed_Wing_B.rtb_u_c = 0.0;
  }

  if (ParamStep_0 == 1.0F) {
    if (ParamStep_1 == 0.0F) {
      for (i = 0; i < 8; i++) {
        FCS_flight_Fixed_Wing_B.Manual_Actuator_Out[i] =
          FCS_flight_Fixed_Wing_B.rtb_u_c;
        FCS_flight_Fixed_Wing_B.Manual_Actuator_Out[i + 8] =
          FCS_flight_Fixed_Wing_B.rtb_u_c;
      }
    } else {
      if ((ParamStep_1 < 1.0F) || (ParamStep_1 > 16.0F)) {
        rtb_t_out_idx_0 = 1.0;
      }

      FCS_flight_Fixed_Wing_B.Manual_Actuator_Out[static_cast<int32_T>
        (rtb_t_out_idx_0) - 1] = FCS_flight_Fixed_Wing_B.rtb_u_c;
    }

    memcpy(&FCS_flight_Fixed_Wing_B.Sum_l[0],
           &FCS_flight_Fixed_Wing_B.Manual_Actuator_Out[0], sizeof(real_T) << 4U);
  }

  // End of MATLAB Function: '<S12>/MATLAB Function'

  // MATLABSystem: '<S38>/Read Parameter3'
  b_varargout_1 = MW_ParamRead_Step
    (FCS_flight_Fixed_Wing_DW.obj_m.MW_PARAMHANDLE, MW_SINGLE, &ParamStep_0);
  if (b_varargout_1) {
    ParamStep_0 = 0.0F;
  }

  // MATLABSystem: '<S37>/Read Parameter'
  b_varargout_1 = MW_ParamRead_Step
    (FCS_flight_Fixed_Wing_DW.obj_kl.MW_PARAMHANDLE, MW_SINGLE, &ParamStep_1);
  if (b_varargout_1) {
    ParamStep_1 = 0.0F;
  }

  // MATLABSystem: '<S37>/Read Parameter1'
  MW_ParamRead_Step(FCS_flight_Fixed_Wing_DW.obj_ki.MW_PARAMHANDLE, MW_SINGLE,
                    &ParamStep_2);

  // MATLAB Function: '<S71>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S37>/Read Parameter'
  //
  for (i = 0; i < 6; i++) {
    FCS_flight_Fixed_Wing_B.Product2[i] = FCS_flight_Fixed_Wing_B.Sum_l[i + 8];
  }

  if (FCS_flight_Fixed_Wing_B.y_c == 0.0) {
    FCS_flight_Fixed_Wing_B.Product2[static_cast<int32_T>(ParamStep_1) - 1] =
      0.0;
  } else {
    for (i = 0; i < 6; i++) {
      FCS_flight_Fixed_Wing_B.Product2[i] = FCS_flight_Fixed_Wing_B.Sum_l[i + 8];
    }
  }

  // End of MATLAB Function: '<S71>/MATLAB Function'

  // DataTypeConversion: '<S71>/Data Type Conversion7'
  for (i = 0; i < 6; i++) {
    FCS_flight_Fixed_Wing_B.DataTypeConversion7[i] = static_cast<real32_T>
      (FCS_flight_Fixed_Wing_B.Product2[i]);
  }

  // End of DataTypeConversion: '<S71>/Data Type Conversion7'

  // MATLABSystem: '<S71>/PX4 Actuator Write' incorporates:
  //   DataTypeConversion: '<S71>/Cast To Boolean'
  //   DataTypeConversion: '<S71>/Data Type Conversion'

  for (i = 0; i < 12; i++) {
    FCS_flight_Fixed_Wing_B.motorValues[i] = (rtNaNF);
  }

  for (i = 0; i < 8; i++) {
    FCS_flight_Fixed_Wing_B.servoValues[i] = (rtNaNF);
  }

  FCS_flight_Fixed_Wing_B.motorValues[0] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.Sum_l[0]);
  FCS_flight_Fixed_Wing_B.servoValues[0] =
    FCS_flight_Fixed_Wing_B.DataTypeConversion7[0];
  FCS_flight_Fixed_Wing_B.servoValues[1] =
    FCS_flight_Fixed_Wing_B.DataTypeConversion7[1];
  FCS_flight_Fixed_Wing_B.servoValues[2] =
    FCS_flight_Fixed_Wing_B.DataTypeConversion7[2];
  FCS_flight_Fixed_Wing_B.servoValues[3] =
    FCS_flight_Fixed_Wing_B.DataTypeConversion7[3];
  FCS_flight_Fixed_Wing_B.servoValues[4] =
    FCS_flight_Fixed_Wing_B.DataTypeConversion7[4];
  FCS_flight_Fixed_Wing_B.servoValues[5] =
    FCS_flight_Fixed_Wing_B.DataTypeConversion7[5];
  MW_actuators_set(rtb_arm != 0, &FCS_flight_Fixed_Wing_B.motorValues[0],
                   &FCS_flight_Fixed_Wing_B.servoValues[0]);

  // End of MATLABSystem: '<S71>/PX4 Actuator Write'

  // BusAssignment: '<S72>/Bus Assignment' incorporates:
  //   Constant: '<S75>/Constant'

  FCS_flight_Fixed_Wing_B.BusAssignment =
    FCS_flight_Fixed_Wing_P.Constant_Value_j;

  // BusAssignment: '<S72>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S29>/Cast To Double10'
  //   DataTypeConversion: '<S29>/Cast To Double8'
  //   DataTypeConversion: '<S29>/Cast To Double9'
  //   DataTypeConversion: '<S72>/Cast To Single'
  //   DiscreteIntegrator: '<S33>/Discrete-Time Integrator'
  //   Gain: '<S29>/Gain'
  //   Reshape: '<S72>/Reshape1'

  FCS_flight_Fixed_Wing_B.BusAssignment.data[0] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_DW.DiscreteTimeIntegrator_DSTATE);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[1] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.DataTypeConversion23[0]);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[2] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.DataTypeConversion23[1]);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[3] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.DataTypeConversion23[3]);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[4] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.DataTypeConversion23[2]);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[5] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.y_h);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[6] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.Switch_m);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[7] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.Memory);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[8] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.y_c);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[9] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.y_b);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[10] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.y_g);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[11] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.y_f);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[12] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.CastToDouble_b);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[13] =
    FCS_flight_Fixed_Wing_B.In1_p.current_distance;
  FCS_flight_Fixed_Wing_B.BusAssignment.data[14] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_P.Gain_Gain *
     FCS_flight_Fixed_Wing_B.In1_e.true_airspeed_m_s);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[15] =
    FCS_flight_Fixed_Wing_B.In1_jb.rho;

  // MATLAB Function: '<S49>/MATLAB Function'
  if (FCS_flight_Fixed_Wing_B.RateTransition1 >= 0.5) {
    // BusAssignment: '<S72>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S29>/Cast To Double10'
    //   DataTypeConversion: '<S72>/Cast To Single'
    //   MATLABSystem: '<S49>/Read Parameter'
    //   RelationalOperator: '<S49>/LessThanOrEqual'
    //
    FCS_flight_Fixed_Wing_B.BusAssignment.data[16] =
      (FCS_flight_Fixed_Wing_B.In1_p.current_distance <= ParamStep);
  } else {
    // BusAssignment: '<S72>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S72>/Cast To Single'

    FCS_flight_Fixed_Wing_B.BusAssignment.data[16] = 0.0F;
  }

  // End of MATLAB Function: '<S49>/MATLAB Function'

  // BusAssignment: '<S72>/Bus Assignment' incorporates:
  //   Constant: '<S72>/Constant1'
  //   DataTypeConversion: '<S71>/Data Type Conversion'
  //   DataTypeConversion: '<S72>/Cast To Single'
  //   DataTypeConversion: '<S72>/Data Type Conversion'
  //   MATLAB Function: '<S5>/MATLAB Function2'
  //   MATLABSystem: '<S38>/Read Parameter11'
  //   MATLABSystem: '<S38>/Read Parameter3'
  //   Reshape: '<S72>/Reshape'
  //   Reshape: '<S72>/Reshape3'
  //
  FCS_flight_Fixed_Wing_B.BusAssignment.data[17] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.RateTransition1);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[18] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.Sum_l[0]);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[25] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.Sum);
  FCS_flight_Fixed_Wing_B.BusAssignment.data[26] = ParamStep_4;
  FCS_flight_Fixed_Wing_B.BusAssignment.data[27] = ParamStep_0;
  for (i = 0; i < 6; i++) {
    FCS_flight_Fixed_Wing_B.BusAssignment.data[i + 19] = static_cast<real32_T>
      (FCS_flight_Fixed_Wing_B.Sum_l[i + 8]);
    FCS_flight_Fixed_Wing_B.BusAssignment.data[i + 28] =
      FCS_flight_Fixed_Wing_B.DataTypeConversion7[i];
  }

  FCS_flight_Fixed_Wing_B.BusAssignment.data[34] = static_cast<real32_T>
    (FCS_flight_Fixed_Wing_B.Sum_l[0]);
  for (i = 0; i < 23; i++) {
    FCS_flight_Fixed_Wing_B.BusAssignment.data[i + 35] = static_cast<real32_T>
      (FCS_flight_Fixed_Wing_P.Constant1_Value_h[i]);
  }

  // MATLABSystem: '<S76>/SinkBlock' incorporates:
  //   BusAssignment: '<S72>/Bus Assignment'

  uORB_write_step(FCS_flight_Fixed_Wing_DW.obj_dy.orbMetadataObj,
                  &FCS_flight_Fixed_Wing_DW.obj_dy.orbAdvertiseObj,
                  &FCS_flight_Fixed_Wing_B.BusAssignment);

  // Sum: '<S20>/FixPt Sum1' incorporates:
  //   Constant: '<S20>/FixPt Constant'
  //   UnitDelay: '<S17>/Output'

  FCS_flight_Fixed_Wing_DW.Output_DSTATE_k +=
    FCS_flight_Fixed_Wing_P.FixPtConstant_Value;

  // Switch: '<S21>/FixPt Switch'
  if (FCS_flight_Fixed_Wing_DW.Output_DSTATE_k >
      FCS_flight_Fixed_Wing_P.WrapToZero_Threshold) {
    // Sum: '<S20>/FixPt Sum1' incorporates:
    //   Constant: '<S21>/Constant'

    FCS_flight_Fixed_Wing_DW.Output_DSTATE_k =
      FCS_flight_Fixed_Wing_P.Constant_Value_p;
  }

  // End of Switch: '<S21>/FixPt Switch'

  // Sum: '<S18>/FixPt Sum1' incorporates:
  //   Constant: '<S18>/FixPt Constant'
  //   UnitDelay: '<S16>/Output'

  FCS_flight_Fixed_Wing_DW.Output_DSTATE +=
    FCS_flight_Fixed_Wing_P.FixPtConstant_Value_i;

  // Switch: '<S19>/FixPt Switch'
  if (FCS_flight_Fixed_Wing_DW.Output_DSTATE >
      FCS_flight_Fixed_Wing_P.WrapToZero_Threshold_e) {
    // Sum: '<S18>/FixPt Sum1' incorporates:
    //   Constant: '<S19>/Constant'

    FCS_flight_Fixed_Wing_DW.Output_DSTATE =
      FCS_flight_Fixed_Wing_P.Constant_Value_c3;
  }

  // End of Switch: '<S19>/FixPt Switch'

  // RateTransition: '<S51>/Rate Transition' incorporates:
  //   DataTypeConversion: '<S51>/Cast To Double'

  if (tmp) {
    FCS_flight_Fixed_Wing_DW.RateTransition_Buffer = static_cast<real_T>
      (FCS_flight_Fixed_Wing_B.In1_p.timestamp);
  }

  // MATLABSystem: '<S41>/SourceBlock'
  uORB_read_step(FCS_flight_Fixed_Wing_DW.obj_nr.orbMetadataObj,
                 &FCS_flight_Fixed_Wing_DW.obj_nr.eventStructObj,
                 &FCS_flight_Fixed_Wing_B.r5, false, 1.0);

  // MATLABSystem: '<S42>/SourceBlock'
  uORB_read_step(FCS_flight_Fixed_Wing_DW.obj_o.orbMetadataObj,
                 &FCS_flight_Fixed_Wing_DW.obj_o.eventStructObj,
                 &FCS_flight_Fixed_Wing_B.r8, false, 1.0);

  // MATLABSystem: '<S43>/SourceBlock'
  uORB_read_step(FCS_flight_Fixed_Wing_DW.obj_j.orbMetadataObj,
                 &FCS_flight_Fixed_Wing_DW.obj_j.eventStructObj,
                 &FCS_flight_Fixed_Wing_B.r1, false, 1.0);

  // MATLABSystem: '<S47>/SourceBlock'
  uORB_read_step(FCS_flight_Fixed_Wing_DW.obj_h.orbMetadataObj,
                 &FCS_flight_Fixed_Wing_DW.obj_h.eventStructObj,
                 &FCS_flight_Fixed_Wing_B.r, false, 1.0);

  // MATLABSystem: '<S38>/Read Parameter'
  MW_ParamRead_Step(FCS_flight_Fixed_Wing_DW.obj_bq.MW_PARAMHANDLE, MW_SINGLE,
                    &ParamStep);

  // MATLABSystem: '<S38>/Read Parameter1'
  MW_ParamRead_Step(FCS_flight_Fixed_Wing_DW.obj_h0.MW_PARAMHANDLE, MW_SINGLE,
                    &ParamStep);

  // MATLABSystem: '<S38>/Read Parameter12'
  MW_ParamRead_Step(FCS_flight_Fixed_Wing_DW.obj_gw.MW_PARAMHANDLE, MW_SINGLE,
                    &ParamStep);

  // MATLABSystem: '<S38>/Read Parameter2'
  MW_ParamRead_Step(FCS_flight_Fixed_Wing_DW.obj_m2.MW_PARAMHANDLE, MW_SINGLE,
                    &ParamStep);

  // MATLABSystem: '<S38>/Read Parameter4'
  MW_ParamRead_Step(FCS_flight_Fixed_Wing_DW.obj_k.MW_PARAMHANDLE, MW_SINGLE,
                    &ParamStep);

  // MATLABSystem: '<S38>/Read Parameter5'
  MW_ParamRead_Step(FCS_flight_Fixed_Wing_DW.obj_j1.MW_PARAMHANDLE, MW_SINGLE,
                    &ParamStep);

  // MATLABSystem: '<S38>/Read Parameter6'
  MW_ParamRead_Step(FCS_flight_Fixed_Wing_DW.obj_a.MW_PARAMHANDLE, MW_SINGLE,
                    &ParamStep);

  // MATLABSystem: '<S38>/Read Parameter8'
  MW_ParamRead_Step(FCS_flight_Fixed_Wing_DW.obj_g.MW_PARAMHANDLE, MW_SINGLE,
                    &ParamStep);

  // Update for DiscreteIntegrator: '<S33>/Discrete-Time Integrator'
  FCS_flight_Fixed_Wing_DW.DiscreteTimeIntegrator_DSTATE +=
    FCS_flight_Fixed_Wing_P.DiscreteTimeIntegrator_gainval * static_cast<real_T>
    (rtb_arm);
  if (rtb_arm > 0) {
    FCS_flight_Fixed_Wing_DW.DiscreteTimeIntegrator_PrevRese = 1;
  } else {
    FCS_flight_Fixed_Wing_DW.DiscreteTimeIntegrator_PrevRese = 0;
  }

  // End of Update for DiscreteIntegrator: '<S33>/Discrete-Time Integrator'

  // Update for Delay: '<S5>/Delay' incorporates:
  //   DataTypeConversion: '<S29>/Cast To Double11'

  FCS_flight_Fixed_Wing_DW.Delay_DSTATE[0] =
    FCS_flight_Fixed_Wing_DW.Delay_DSTATE[1];
  FCS_flight_Fixed_Wing_DW.Delay_DSTATE[1] =
    FCS_flight_Fixed_Wing_B.In1_k.nav_state;

  // Update for Delay: '<S5>/Delay1'
  FCS_flight_Fixed_Wing_DW.Delay1_DSTATE[0] =
    FCS_flight_Fixed_Wing_DW.Delay1_DSTATE[1];
  FCS_flight_Fixed_Wing_DW.Delay1_DSTATE[1] = rtb_reset_needed;
}

// Model step function for TID1
void FCS_flight_Fixed_Wing_step1(void) // Sample time: [1.0s, 0.0s]
{
  real_T rtb_DelayOneStep;
  int32_T rtb_CastToDouble1_m;

  // Delay: '<S51>/Delay One Step'
  rtb_DelayOneStep = FCS_flight_Fixed_Wing_DW.DelayOneStep_DSTATE;

  // RateTransition: '<S51>/Rate Transition' incorporates:
  //   Delay: '<S51>/Delay One Step'

  FCS_flight_Fixed_Wing_DW.DelayOneStep_DSTATE =
    FCS_flight_Fixed_Wing_DW.RateTransition_Buffer;

  // DataTypeConversion: '<S51>/Cast To Double1' incorporates:
  //   Delay: '<S51>/Delay One Step'
  //   RelationalOperator: '<S51>/Relational Operator'

  rtb_CastToDouble1_m = (FCS_flight_Fixed_Wing_DW.DelayOneStep_DSTATE >
    rtb_DelayOneStep);

  // RateTransition: '<S51>/Rate Transition1'
  FCS_flight_Fixed_Wing_DW.RateTransition1_Buffer0 = rtb_CastToDouble1_m;
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void FCS_flight_Fixed_Wing_step(int_T tid)
{
  switch (tid) {
   case 0 :
    FCS_flight_Fixed_Wing_step0();
    break;

   case 1 :
    FCS_flight_Fixed_Wing_step1();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void FCS_flight_Fixed_Wing_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  FCS_flight_Fixed_Wing_P.Constant3_Value_e[0] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant3_Value_e[1] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant3_Value_e[2] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant3_Value_e[3] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant3_Value_e[4] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant3_Value_e[5] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant3_Value_e[6] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_i[0] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_i[1] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[0] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[1] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[2] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[3] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[4] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[5] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[6] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[7] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[8] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[9] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[10] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[11] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[12] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[13] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[14] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[15] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[16] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[17] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[18] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[19] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[20] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[21] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant1_Value_h[22] = rtNaN;
  FCS_flight_Fixed_Wing_P.Constant_Value_m[0] = rtNaNF;
  FCS_flight_Fixed_Wing_P.Constant_Value_m[1] = rtNaNF;
  FCS_flight_Fixed_Wing_P.Constant_Value_m[2] = rtNaNF;
  FCS_flight_Fixed_Wing_P.Constant_Value_m[3] = rtNaNF;
  FCS_flight_Fixed_Wing_P.Constant_Value_m[4] = rtNaNF;
  FCS_flight_Fixed_Wing_P.Constant_Value_m[5] = rtNaNF;
  FCS_flight_Fixed_Wing_P.Constant_Value_m[6] = rtNaNF;
  FCS_flight_Fixed_Wing_P.Constant_Value_m[7] = rtNaNF;
  FCS_flight_Fixed_Wing_P.Constant_Value_m[8] = rtNaNF;

  {
    static const char_T ParameterNameStr[13] = "EKF2_MIN_RNG";
    static const char_T ParameterNameStr_0[15] = "MANUAL_ACT_CHK";
    static const char_T ParameterNameStr_1[15] = "MANUAL_ACT_IDX";
    static const char_T ParameterNameStr_2[15] = "MANUAL_ACT_VAL";
    static const char_T ParameterNameStr_3[13] = "PTI_MODE_CHG";
    static const char_T ParameterNameStr_4[14] = "PTI_MOTOR_AMP";
    static const char_T ParameterNameStr_5[11] = "PTI_MS_AMP";
    static const char_T ParameterNameStr_6[9] = "PTI_MS_T";
    static const char_T ParameterNameStr_7[14] = "FAULT_SURFACE";
    static const char_T ParameterNameStr_8[13] = "FAULT_ENGAGE";
    static const char_T ParameterNameStr_9[13] = "PTI_DOUB_AMP";
    static const char_T ParameterNameStr_a[11] = "PTI_DOUB_T";
    static const char_T ParameterNameStr_b[12] = "PTI_SWP_AMP";
    static const char_T ParameterNameStr_c[12] = "PTI_SWP_SEL";
    static const char_T ParameterNameStr_d[16] = "PTI_SWP_F_START";
    static const char_T ParameterNameStr_e[15] = "PTI_SWP_F_STOP";
    static const char_T ParameterNameStr_f[10] = "PTI_SWP_T";
    static const char_T ParameterNameStr_g[13] = "PTI_DOUB_SEL";
    int32_T i;

    // Start for RateTransition: '<S51>/Rate Transition1'
    FCS_flight_Fixed_Wing_B.RateTransition1 =
      FCS_flight_Fixed_Wing_P.RateTransition1_InitialConditio;

    // InitializeConditions for DiscreteIntegrator: '<S33>/Discrete-Time Integrator' 
    FCS_flight_Fixed_Wing_DW.DiscreteTimeIntegrator_DSTATE =
      FCS_flight_Fixed_Wing_P.DiscreteTimeIntegrator_IC;
    FCS_flight_Fixed_Wing_DW.DiscreteTimeIntegrator_PrevRese = 2;

    // InitializeConditions for RateTransition: '<S51>/Rate Transition1'
    FCS_flight_Fixed_Wing_DW.RateTransition1_Buffer0 =
      FCS_flight_Fixed_Wing_P.RateTransition1_InitialConditio;

    // InitializeConditions for Sum: '<S18>/FixPt Sum1' incorporates:
    //   UnitDelay: '<S16>/Output'

    FCS_flight_Fixed_Wing_DW.Output_DSTATE =
      FCS_flight_Fixed_Wing_P.Output_InitialCondition;

    // InitializeConditions for Switch: '<S10>/Switch' incorporates:
    //   Memory: '<S10>/Memory'

    FCS_flight_Fixed_Wing_DW.Memory_PreviousInput =
      FCS_flight_Fixed_Wing_P.Memory_InitialCondition;

    // InitializeConditions for Delay: '<S5>/Delay'
    FCS_flight_Fixed_Wing_DW.Delay_DSTATE[0] =
      FCS_flight_Fixed_Wing_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S5>/Delay1'
    FCS_flight_Fixed_Wing_DW.Delay1_DSTATE[0] =
      FCS_flight_Fixed_Wing_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S5>/Delay'
    FCS_flight_Fixed_Wing_DW.Delay_DSTATE[1] =
      FCS_flight_Fixed_Wing_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S5>/Delay1'
    FCS_flight_Fixed_Wing_DW.Delay1_DSTATE[1] =
      FCS_flight_Fixed_Wing_P.Delay1_InitialCondition;

    // InitializeConditions for Sum: '<S20>/FixPt Sum1' incorporates:
    //   UnitDelay: '<S17>/Output'

    FCS_flight_Fixed_Wing_DW.Output_DSTATE_k =
      FCS_flight_Fixed_Wing_P.Output_InitialCondition_c;

    // InitializeConditions for Delay: '<S51>/Delay One Step'
    FCS_flight_Fixed_Wing_DW.DelayOneStep_DSTATE =
      FCS_flight_Fixed_Wing_P.DelayOneStep_InitialCondition;

    // SystemInitialize for Enabled SubSystem: '<S23>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S25>/In1' incorporates:
    //   Outport: '<S25>/Out1'

    FCS_flight_Fixed_Wing_B.In1_i = FCS_flight_Fixed_Wing_P.Out1_Y0_l;

    // End of SystemInitialize for SubSystem: '<S23>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S24>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S26>/In1' incorporates:
    //   Outport: '<S26>/Out1'

    FCS_flight_Fixed_Wing_B.In1_io = FCS_flight_Fixed_Wing_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S24>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S35>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S36>/In1' incorporates:
    //   Outport: '<S36>/Out1'

    FCS_flight_Fixed_Wing_B.In1_jq = FCS_flight_Fixed_Wing_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S35>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S69>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S70>/In1' incorporates:
    //   Outport: '<S70>/Out1'

    FCS_flight_Fixed_Wing_B.In1 = FCS_flight_Fixed_Wing_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S69>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S44>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S55>/In1' incorporates:
    //   Outport: '<S55>/Out1'

    FCS_flight_Fixed_Wing_B.In1_e = FCS_flight_Fixed_Wing_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S44>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S45>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S56>/In1' incorporates:
    //   Outport: '<S56>/Out1'

    FCS_flight_Fixed_Wing_B.In1_jb = FCS_flight_Fixed_Wing_P.Out1_Y0_pb;

    // End of SystemInitialize for SubSystem: '<S45>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S46>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S57>/In1' incorporates:
    //   Outport: '<S57>/Out1'

    FCS_flight_Fixed_Wing_B.In1_p = FCS_flight_Fixed_Wing_P.Out1_Y0_pl;

    // End of SystemInitialize for SubSystem: '<S46>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S48>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S59>/In1' incorporates:
    //   Outport: '<S59>/Out1'

    FCS_flight_Fixed_Wing_B.In1_k = FCS_flight_Fixed_Wing_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S48>/Enabled Subsystem'

    // Start for MATLABSystem: '<S35>/SourceBlock'
    FCS_flight_Fixed_Wing_DW.obj_l.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_l.isSetupComplete = false;
    FCS_flight_Fixed_Wing_DW.obj_l.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_l.orbMetadataObj = ORB_ID(actuator_armed);
    uORB_read_initialize(FCS_flight_Fixed_Wing_DW.obj_l.orbMetadataObj,
                         &FCS_flight_Fixed_Wing_DW.obj_l.eventStructObj);
    FCS_flight_Fixed_Wing_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: '<S69>/SourceBlock'
    FCS_flight_Fixed_Wing_DW.obj_b.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_b.isSetupComplete = false;
    FCS_flight_Fixed_Wing_DW.obj_b.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_b.orbMetadataObj = ORB_ID(rc_channels);
    uORB_read_initialize(FCS_flight_Fixed_Wing_DW.obj_b.orbMetadataObj,
                         &FCS_flight_Fixed_Wing_DW.obj_b.eventStructObj);
    FCS_flight_Fixed_Wing_DW.obj_b.isSetupComplete = true;

    // Start for MATLABSystem: '<S46>/SourceBlock'
    FCS_flight_Fixed_Wing_DW.obj_d.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_d.isSetupComplete = false;
    FCS_flight_Fixed_Wing_DW.obj_d.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_d.orbMetadataObj = ORB_ID(distance_sensor);
    uORB_read_initialize(FCS_flight_Fixed_Wing_DW.obj_d.orbMetadataObj,
                         &FCS_flight_Fixed_Wing_DW.obj_d.eventStructObj);
    FCS_flight_Fixed_Wing_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S44>/SourceBlock'
    FCS_flight_Fixed_Wing_DW.obj_n.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_n.isSetupComplete = false;
    FCS_flight_Fixed_Wing_DW.obj_n.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_n.orbMetadataObj = ORB_ID(airspeed);
    uORB_read_initialize(FCS_flight_Fixed_Wing_DW.obj_n.orbMetadataObj,
                         &FCS_flight_Fixed_Wing_DW.obj_n.eventStructObj);
    FCS_flight_Fixed_Wing_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S45>/SourceBlock'
    FCS_flight_Fixed_Wing_DW.obj_hm.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_hm.isSetupComplete = false;
    FCS_flight_Fixed_Wing_DW.obj_hm.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_hm.orbMetadataObj = ORB_ID(vehicle_air_data);
    uORB_read_initialize(FCS_flight_Fixed_Wing_DW.obj_hm.orbMetadataObj,
                         &FCS_flight_Fixed_Wing_DW.obj_hm.eventStructObj);
    FCS_flight_Fixed_Wing_DW.obj_hm.isSetupComplete = true;

    // Start for MATLABSystem: '<S49>/Read Parameter'
    FCS_flight_Fixed_Wing_DW.obj_oh.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_oh.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_oh.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_oh.isSetupComplete = true;

    // Start for MATLABSystem: '<S39>/Read Parameter'
    FCS_flight_Fixed_Wing_DW.obj_j0.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_j0.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_j0.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_j0.isSetupComplete = true;

    // Start for MATLABSystem: '<S39>/Read Parameter1'
    FCS_flight_Fixed_Wing_DW.obj_cf.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_cf.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_cf.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_cf.isSetupComplete = true;

    // Start for MATLABSystem: '<S39>/Read Parameter8'
    FCS_flight_Fixed_Wing_DW.obj_e.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_e.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_e.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S23>/SourceBlock'
    FCS_flight_Fixed_Wing_DW.obj_c.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_c.isSetupComplete = false;
    FCS_flight_Fixed_Wing_DW.obj_c.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_c.orbMetadataObj = ORB_ID(actuator_motors);
    uORB_read_initialize(FCS_flight_Fixed_Wing_DW.obj_c.orbMetadataObj,
                         &FCS_flight_Fixed_Wing_DW.obj_c.eventStructObj);
    FCS_flight_Fixed_Wing_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<S24>/SourceBlock'
    FCS_flight_Fixed_Wing_DW.obj_jl.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_jl.isSetupComplete = false;
    FCS_flight_Fixed_Wing_DW.obj_jl.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_jl.orbMetadataObj = ORB_ID(actuator_servos);
    uORB_read_initialize(FCS_flight_Fixed_Wing_DW.obj_jl.orbMetadataObj,
                         &FCS_flight_Fixed_Wing_DW.obj_jl.eventStructObj);
    FCS_flight_Fixed_Wing_DW.obj_jl.isSetupComplete = true;

    // Start for MATLABSystem: '<S48>/SourceBlock'
    FCS_flight_Fixed_Wing_DW.obj_p.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_p.isSetupComplete = false;
    FCS_flight_Fixed_Wing_DW.obj_p.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_p.orbMetadataObj = ORB_ID(vehicle_status);
    uORB_read_initialize(FCS_flight_Fixed_Wing_DW.obj_p.orbMetadataObj,
                         &FCS_flight_Fixed_Wing_DW.obj_p.eventStructObj);
    FCS_flight_Fixed_Wing_DW.obj_p.isSetupComplete = true;

    // Start for MATLABSystem: '<S38>/Read Parameter13'
    FCS_flight_Fixed_Wing_DW.obj_jv.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_jv.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_jv.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_jv.isSetupComplete = true;

    // Start for MATLABSystem: '<S38>/Read Parameter7'
    FCS_flight_Fixed_Wing_DW.obj_l0.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_l0.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_l0.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_l0.isSetupComplete = true;

    // Start for MATLABSystem: '<S38>/Read Parameter11'
    FCS_flight_Fixed_Wing_DW.obj_az.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_az.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_az.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_az.isSetupComplete = true;

    // Start for MATLABSystem: '<S38>/Read Parameter3'
    FCS_flight_Fixed_Wing_DW.obj_m.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_m.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_m.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_6[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S37>/Read Parameter'
    FCS_flight_Fixed_Wing_DW.obj_kl.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_kl.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_kl.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_7[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_kl.isSetupComplete = true;

    // Start for MATLABSystem: '<S37>/Read Parameter1'
    FCS_flight_Fixed_Wing_DW.obj_ki.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_ki.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_ki.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_8[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_ki.isSetupComplete = true;

    // Start for MATLABSystem: '<S71>/PX4 Actuator Write'
    for (i = 0; i < 12; i++) {
      FCS_flight_Fixed_Wing_DW.obj.ValidMotorIdx[i] = false;
    }

    for (i = 0; i < 8; i++) {
      FCS_flight_Fixed_Wing_DW.obj.ValidServoIdx[i] = false;
    }

    FCS_flight_Fixed_Wing_DW.obj.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj.isSetupComplete = false;
    FCS_flight_Fixed_Wing_DW.obj.isInitialized = 1;
    FCS_flig_PX4Actuators_setupImpl(&FCS_flight_Fixed_Wing_DW.obj);
    FCS_flight_Fixed_Wing_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S71>/PX4 Actuator Write'

    // Start for MATLABSystem: '<S76>/SinkBlock' incorporates:
    //   BusAssignment: '<S72>/Bus Assignment'

    FCS_flight_Fixed_Wing_DW.obj_dy.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_dy.isSetupComplete = false;
    FCS_flight_Fixed_Wing_DW.obj_dy.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_dy.orbMetadataObj = ORB_ID(debug_array);
    uORB_write_initialize(FCS_flight_Fixed_Wing_DW.obj_dy.orbMetadataObj,
                          &FCS_flight_Fixed_Wing_DW.obj_dy.orbAdvertiseObj,
                          &FCS_flight_Fixed_Wing_B.BusAssignment, 1);
    FCS_flight_Fixed_Wing_DW.obj_dy.isSetupComplete = true;

    // Start for MATLABSystem: '<S41>/SourceBlock'
    FCS_flight_Fixed_Wing_DW.obj_nr.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_nr.isSetupComplete = false;
    FCS_flight_Fixed_Wing_DW.obj_nr.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_nr.orbMetadataObj = ORB_ID(vehicle_attitude);
    uORB_read_initialize(FCS_flight_Fixed_Wing_DW.obj_nr.orbMetadataObj,
                         &FCS_flight_Fixed_Wing_DW.obj_nr.eventStructObj);
    FCS_flight_Fixed_Wing_DW.obj_nr.isSetupComplete = true;

    // Start for MATLABSystem: '<S42>/SourceBlock'
    FCS_flight_Fixed_Wing_DW.obj_o.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_o.isSetupComplete = false;
    FCS_flight_Fixed_Wing_DW.obj_o.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_o.orbMetadataObj = ORB_ID
      (vehicle_angular_velocity);
    uORB_read_initialize(FCS_flight_Fixed_Wing_DW.obj_o.orbMetadataObj,
                         &FCS_flight_Fixed_Wing_DW.obj_o.eventStructObj);
    FCS_flight_Fixed_Wing_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<S43>/SourceBlock'
    FCS_flight_Fixed_Wing_DW.obj_j.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_j.isSetupComplete = false;
    FCS_flight_Fixed_Wing_DW.obj_j.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_j.orbMetadataObj = ORB_ID
      (vehicle_local_position);
    uORB_read_initialize(FCS_flight_Fixed_Wing_DW.obj_j.orbMetadataObj,
                         &FCS_flight_Fixed_Wing_DW.obj_j.eventStructObj);
    FCS_flight_Fixed_Wing_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S47>/SourceBlock'
    FCS_flight_Fixed_Wing_DW.obj_h.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_h.isSetupComplete = false;
    FCS_flight_Fixed_Wing_DW.obj_h.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_h.orbMetadataObj = ORB_ID(esc_status);
    uORB_read_initialize(FCS_flight_Fixed_Wing_DW.obj_h.orbMetadataObj,
                         &FCS_flight_Fixed_Wing_DW.obj_h.eventStructObj);
    FCS_flight_Fixed_Wing_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<S38>/Read Parameter'
    FCS_flight_Fixed_Wing_DW.obj_bq.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_bq.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_bq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_9[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_bq.isSetupComplete = true;

    // Start for MATLABSystem: '<S38>/Read Parameter1'
    FCS_flight_Fixed_Wing_DW.obj_h0.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_h0.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_h0.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_a[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_h0.isSetupComplete = true;

    // Start for MATLABSystem: '<S38>/Read Parameter12'
    FCS_flight_Fixed_Wing_DW.obj_gw.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_gw.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_gw.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_b[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_gw.isSetupComplete = true;

    // Start for MATLABSystem: '<S38>/Read Parameter2'
    FCS_flight_Fixed_Wing_DW.obj_m2.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_m2.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_m2.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_c[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_m2.isSetupComplete = true;

    // Start for MATLABSystem: '<S38>/Read Parameter4'
    FCS_flight_Fixed_Wing_DW.obj_k.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_k.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_d[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S38>/Read Parameter5'
    FCS_flight_Fixed_Wing_DW.obj_j1.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_j1.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_j1.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_e[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_j1.isSetupComplete = true;

    // Start for MATLABSystem: '<S38>/Read Parameter6'
    FCS_flight_Fixed_Wing_DW.obj_a.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_a.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_f[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: '<S38>/Read Parameter8'
    FCS_flight_Fixed_Wing_DW.obj_g.matlabCodegenIsDeleted = false;
    FCS_flight_Fixed_Wing_DW.obj_g.isInitialized = 1;
    FCS_flight_Fixed_Wing_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_g[0], true, 200.0);
    FCS_flight_Fixed_Wing_DW.obj_g.isSetupComplete = true;
  }
}

// Model terminate function
void FCS_flight_Fixed_Wing_terminate(void)
{
  real32_T servoValues[8];

  // Terminate for MATLABSystem: '<S35>/SourceBlock'
  if (!FCS_flight_Fixed_Wing_DW.obj_l.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((FCS_flight_Fixed_Wing_DW.obj_l.isInitialized == 1) &&
        FCS_flight_Fixed_Wing_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&FCS_flight_Fixed_Wing_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S35>/SourceBlock'

  // Terminate for MATLABSystem: '<S69>/SourceBlock'
  if (!FCS_flight_Fixed_Wing_DW.obj_b.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((FCS_flight_Fixed_Wing_DW.obj_b.isInitialized == 1) &&
        FCS_flight_Fixed_Wing_DW.obj_b.isSetupComplete) {
      uORB_read_terminate(&FCS_flight_Fixed_Wing_DW.obj_b.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S69>/SourceBlock'

  // Terminate for MATLABSystem: '<S46>/SourceBlock'
  if (!FCS_flight_Fixed_Wing_DW.obj_d.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((FCS_flight_Fixed_Wing_DW.obj_d.isInitialized == 1) &&
        FCS_flight_Fixed_Wing_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&FCS_flight_Fixed_Wing_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S46>/SourceBlock'

  // Terminate for MATLABSystem: '<S44>/SourceBlock'
  if (!FCS_flight_Fixed_Wing_DW.obj_n.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((FCS_flight_Fixed_Wing_DW.obj_n.isInitialized == 1) &&
        FCS_flight_Fixed_Wing_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&FCS_flight_Fixed_Wing_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S44>/SourceBlock'

  // Terminate for MATLABSystem: '<S45>/SourceBlock'
  if (!FCS_flight_Fixed_Wing_DW.obj_hm.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_hm.matlabCodegenIsDeleted = true;
    if ((FCS_flight_Fixed_Wing_DW.obj_hm.isInitialized == 1) &&
        FCS_flight_Fixed_Wing_DW.obj_hm.isSetupComplete) {
      uORB_read_terminate(&FCS_flight_Fixed_Wing_DW.obj_hm.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S45>/SourceBlock'

  // Terminate for MATLABSystem: '<S49>/Read Parameter'
  if (!FCS_flight_Fixed_Wing_DW.obj_oh.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_oh.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S49>/Read Parameter'

  // Terminate for MATLABSystem: '<S39>/Read Parameter'
  if (!FCS_flight_Fixed_Wing_DW.obj_j0.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_j0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S39>/Read Parameter'

  // Terminate for MATLABSystem: '<S39>/Read Parameter1'
  if (!FCS_flight_Fixed_Wing_DW.obj_cf.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_cf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S39>/Read Parameter1'

  // Terminate for MATLABSystem: '<S39>/Read Parameter8'
  if (!FCS_flight_Fixed_Wing_DW.obj_e.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S39>/Read Parameter8'

  // Terminate for MATLABSystem: '<S23>/SourceBlock'
  if (!FCS_flight_Fixed_Wing_DW.obj_c.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((FCS_flight_Fixed_Wing_DW.obj_c.isInitialized == 1) &&
        FCS_flight_Fixed_Wing_DW.obj_c.isSetupComplete) {
      uORB_read_terminate(&FCS_flight_Fixed_Wing_DW.obj_c.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S23>/SourceBlock'

  // Terminate for MATLABSystem: '<S24>/SourceBlock'
  if (!FCS_flight_Fixed_Wing_DW.obj_jl.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_jl.matlabCodegenIsDeleted = true;
    if ((FCS_flight_Fixed_Wing_DW.obj_jl.isInitialized == 1) &&
        FCS_flight_Fixed_Wing_DW.obj_jl.isSetupComplete) {
      uORB_read_terminate(&FCS_flight_Fixed_Wing_DW.obj_jl.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S24>/SourceBlock'

  // Terminate for MATLABSystem: '<S48>/SourceBlock'
  if (!FCS_flight_Fixed_Wing_DW.obj_p.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((FCS_flight_Fixed_Wing_DW.obj_p.isInitialized == 1) &&
        FCS_flight_Fixed_Wing_DW.obj_p.isSetupComplete) {
      uORB_read_terminate(&FCS_flight_Fixed_Wing_DW.obj_p.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S48>/SourceBlock'

  // Terminate for MATLABSystem: '<S38>/Read Parameter13'
  if (!FCS_flight_Fixed_Wing_DW.obj_jv.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_jv.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S38>/Read Parameter13'

  // Terminate for MATLABSystem: '<S38>/Read Parameter7'
  if (!FCS_flight_Fixed_Wing_DW.obj_l0.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_l0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S38>/Read Parameter7'

  // Terminate for MATLABSystem: '<S38>/Read Parameter11'
  if (!FCS_flight_Fixed_Wing_DW.obj_az.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_az.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S38>/Read Parameter11'

  // Terminate for MATLABSystem: '<S38>/Read Parameter3'
  if (!FCS_flight_Fixed_Wing_DW.obj_m.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S38>/Read Parameter3'

  // Terminate for MATLABSystem: '<S37>/Read Parameter'
  if (!FCS_flight_Fixed_Wing_DW.obj_kl.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_kl.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S37>/Read Parameter'

  // Terminate for MATLABSystem: '<S37>/Read Parameter1'
  if (!FCS_flight_Fixed_Wing_DW.obj_ki.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_ki.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S37>/Read Parameter1'

  // Terminate for MATLABSystem: '<S71>/PX4 Actuator Write'
  if (!FCS_flight_Fixed_Wing_DW.obj.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj.matlabCodegenIsDeleted = true;
    if ((FCS_flight_Fixed_Wing_DW.obj.isInitialized == 1) &&
        FCS_flight_Fixed_Wing_DW.obj.isSetupComplete) {
      for (int32_T i = 0; i < 12; i++) {
        FCS_flight_Fixed_Wing_B.motorValues_m[i] = (rtNaNF);
      }

      for (int32_T i = 0; i < 8; i++) {
        servoValues[i] = (rtNaNF);
      }

      for (int32_T i = 0; i < 12; i++) {
        if (FCS_flight_Fixed_Wing_DW.obj.ValidMotorIdx[i]) {
          FCS_flight_Fixed_Wing_B.motorValues_m[i] = 0.0F;
        }
      }

      for (int32_T i = 0; i < 8; i++) {
        if (FCS_flight_Fixed_Wing_DW.obj.ValidServoIdx[i]) {
          servoValues[i] = 0.0F;
        }
      }

      MW_actuators_set(false, &FCS_flight_Fixed_Wing_B.motorValues_m[0],
                       &servoValues[0]);
      MW_actuators_terminate();
    }
  }

  // End of Terminate for MATLABSystem: '<S71>/PX4 Actuator Write'

  // Terminate for MATLABSystem: '<S76>/SinkBlock'
  if (!FCS_flight_Fixed_Wing_DW.obj_dy.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_dy.matlabCodegenIsDeleted = true;
    if ((FCS_flight_Fixed_Wing_DW.obj_dy.isInitialized == 1) &&
        FCS_flight_Fixed_Wing_DW.obj_dy.isSetupComplete) {
      uORB_write_terminate(&FCS_flight_Fixed_Wing_DW.obj_dy.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S76>/SinkBlock'

  // Terminate for MATLABSystem: '<S41>/SourceBlock'
  if (!FCS_flight_Fixed_Wing_DW.obj_nr.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_nr.matlabCodegenIsDeleted = true;
    if ((FCS_flight_Fixed_Wing_DW.obj_nr.isInitialized == 1) &&
        FCS_flight_Fixed_Wing_DW.obj_nr.isSetupComplete) {
      uORB_read_terminate(&FCS_flight_Fixed_Wing_DW.obj_nr.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S41>/SourceBlock'

  // Terminate for MATLABSystem: '<S42>/SourceBlock'
  if (!FCS_flight_Fixed_Wing_DW.obj_o.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((FCS_flight_Fixed_Wing_DW.obj_o.isInitialized == 1) &&
        FCS_flight_Fixed_Wing_DW.obj_o.isSetupComplete) {
      uORB_read_terminate(&FCS_flight_Fixed_Wing_DW.obj_o.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S42>/SourceBlock'

  // Terminate for MATLABSystem: '<S43>/SourceBlock'
  if (!FCS_flight_Fixed_Wing_DW.obj_j.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((FCS_flight_Fixed_Wing_DW.obj_j.isInitialized == 1) &&
        FCS_flight_Fixed_Wing_DW.obj_j.isSetupComplete) {
      uORB_read_terminate(&FCS_flight_Fixed_Wing_DW.obj_j.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S43>/SourceBlock'

  // Terminate for MATLABSystem: '<S47>/SourceBlock'
  if (!FCS_flight_Fixed_Wing_DW.obj_h.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((FCS_flight_Fixed_Wing_DW.obj_h.isInitialized == 1) &&
        FCS_flight_Fixed_Wing_DW.obj_h.isSetupComplete) {
      uORB_read_terminate(&FCS_flight_Fixed_Wing_DW.obj_h.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S47>/SourceBlock'

  // Terminate for MATLABSystem: '<S38>/Read Parameter'
  if (!FCS_flight_Fixed_Wing_DW.obj_bq.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_bq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S38>/Read Parameter'

  // Terminate for MATLABSystem: '<S38>/Read Parameter1'
  if (!FCS_flight_Fixed_Wing_DW.obj_h0.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_h0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S38>/Read Parameter1'

  // Terminate for MATLABSystem: '<S38>/Read Parameter12'
  if (!FCS_flight_Fixed_Wing_DW.obj_gw.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_gw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S38>/Read Parameter12'

  // Terminate for MATLABSystem: '<S38>/Read Parameter2'
  if (!FCS_flight_Fixed_Wing_DW.obj_m2.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_m2.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S38>/Read Parameter2'

  // Terminate for MATLABSystem: '<S38>/Read Parameter4'
  if (!FCS_flight_Fixed_Wing_DW.obj_k.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S38>/Read Parameter4'

  // Terminate for MATLABSystem: '<S38>/Read Parameter5'
  if (!FCS_flight_Fixed_Wing_DW.obj_j1.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_j1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S38>/Read Parameter5'

  // Terminate for MATLABSystem: '<S38>/Read Parameter6'
  if (!FCS_flight_Fixed_Wing_DW.obj_a.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S38>/Read Parameter6'

  // Terminate for MATLABSystem: '<S38>/Read Parameter8'
  if (!FCS_flight_Fixed_Wing_DW.obj_g.matlabCodegenIsDeleted) {
    FCS_flight_Fixed_Wing_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S38>/Read Parameter8'
}

const char_T* RT_MODEL_FCS_flight_Fixed_Win_T::getErrorStatus() const
{
  return (errorStatus);
}

void RT_MODEL_FCS_flight_Fixed_Win_T::setErrorStatus(const char_T* const
  volatile aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

boolean_T RT_MODEL_FCS_flight_Fixed_Win_T::StepTask(int32_T idx) const
{
  return (Timing.TaskCounters.TID[(idx)] == 0);
}

uint16_T &RT_MODEL_FCS_flight_Fixed_Win_T::TaskCounter(int32_T idx)
{
  return (Timing.TaskCounters.TID[(idx)]);
}

//
// File trailer for generated code.
//
// [EOF]
//
