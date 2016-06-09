/*
 * trajectoryModel_data.c
 *
 * Code generation for model "trajectoryModel".
 *
 * Model version              : 1.84
 * Simulink Coder version : 8.7 (R2014b) 08-Sep-2014
 * C source code generated on : Sun May 29 20:16:58 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "trajectoryModel.h"
#include "trajectoryModel_private.h"

/* Block parameters (auto storage) */
P_trajectoryModel_T trajectoryModel_P = {
  /*  Variable: initialConditions
   * Referenced by:
   *   '<Root>/dx'
   *   '<Root>/dy'
   *   '<Root>/x'
   *   '<Root>/y '
   */
  { 0.3011, -0.8496, 0.0773, 1.5496 },
  0.012150548256445718,                /* Variable: mu
                                        * Referenced by:
                                        *   '<Root>/Earth_x'
                                        *   '<Root>/Moon mass'
                                        *   '<Root>/Moon_x Earth mass'
                                        */
  0.0,                                 /* Variable: stopRadius
                                        * Referenced by: '<Root>/stopRadius'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/0 '
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/terminate'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/2'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain1'
                                        */

  /* Start of '<Root>/If Action Subsystem1' */
  {
    0.0                                /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S2>/Out1'
                                        */
  }
  /* End of '<Root>/If Action Subsystem1' */
  ,

  /* Start of '<Root>/If Action Subsystem' */
  {
    0.0                                /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S1>/Out1'
                                        */
  }
  /* End of '<Root>/If Action Subsystem' */
};
