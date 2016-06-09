/*
 * trajectoryModel.c
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

/* Block signals (auto storage) */
B_trajectoryModel_T trajectoryModel_B;

/* Continuous states */
X_trajectoryModel_T trajectoryModel_X;

/* Block states (auto storage) */
DW_trajectoryModel_T trajectoryModel_DW;

/* Real-time model */
RT_MODEL_trajectoryModel_T trajectoryModel_M_;
RT_MODEL_trajectoryModel_T *const trajectoryModel_M = &trajectoryModel_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  trajectoryModel_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  trajectoryModel_step();
  trajectoryModel_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  trajectoryModel_step();
  trajectoryModel_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Start for action system:
 *    '<Root>/If Action Subsystem'
 *    '<Root>/If Action Subsystem1'
 */
void traject_IfActionSubsystem_Start(B_IfActionSubsystem_trajector_T *localB,
  P_IfActionSubsystem_trajector_T *localP)
{
  /* VirtualOutportStart for Outport: '<S1>/Out1' */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for action system:
 *    '<Root>/If Action Subsystem'
 *    '<Root>/If Action Subsystem1'
 */
void trajectoryMod_IfActionSubsystem(real_T rtu_In1,
  B_IfActionSubsystem_trajector_T *localB)
{
  /* Inport: '<S1>/In1' */
  localB->In1 = rtu_In1;
}

/* Model step function */
void trajectoryModel_step(void)
{
  /* local block i/o variables */
  real_T rtb_Sqrt;
  real_T rtb_Divide1;
  int8_T rtAction;
  real_T rtb_Divide;
  real_T rtb_Add1;
  if (rtmIsMajorTimeStep(trajectoryModel_M)) {
    /* set solver stop time */
    if (!(trajectoryModel_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&trajectoryModel_M->solverInfo,
                            ((trajectoryModel_M->Timing.clockTickH0 + 1) *
        trajectoryModel_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&trajectoryModel_M->solverInfo,
                            ((trajectoryModel_M->Timing.clockTick0 + 1) *
        trajectoryModel_M->Timing.stepSize0 +
        trajectoryModel_M->Timing.clockTickH0 *
        trajectoryModel_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(trajectoryModel_M)) {
    trajectoryModel_M->Timing.t[0] = rtsiGetT(&trajectoryModel_M->solverInfo);
  }

  /* Integrator: '<Root>/x' */
  trajectoryModel_B.x = trajectoryModel_X.x_CSTATE;

  /* Sum: '<S3>/x-Planet_x' incorporates:
   *  Constant: '<Root>/0 '
   */
  rtb_Divide1 = trajectoryModel_B.x - trajectoryModel_P._Value;

  /* Integrator: '<Root>/y ' */
  trajectoryModel_B.y = trajectoryModel_X.y_CSTATE;

  /* Sqrt: '<S3>/Sqrt' incorporates:
   *  Product: '<S3>/(x-Planet_x)^2'
   *  Product: '<S3>/y^2'
   *  Sum: '<S3>/(x-Planet_x)^2+y^2'
   */
  rtb_Sqrt = sqrt(rtb_Divide1 * rtb_Divide1 + trajectoryModel_B.y *
                  trajectoryModel_B.y);

  /* If: '<Root>/If' incorporates:
   *  Constant: '<Root>/stopRadius'
   *  Constant: '<Root>/terminate'
   */
  if (rtmIsMajorTimeStep(trajectoryModel_M)) {
    if (rtb_Sqrt < trajectoryModel_P.stopRadius) {
      rtAction = 0;
    } else {
      rtAction = 1;
    }

    trajectoryModel_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = trajectoryModel_DW.If_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    trajectoryMod_IfActionSubsystem(rtb_Sqrt,
      &trajectoryModel_B.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    trajectoryMod_IfActionSubsystem(trajectoryModel_P.terminate_Value,
      &trajectoryModel_B.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */
    break;
  }

  /* End of If: '<Root>/If' */
  if (rtmIsMajorTimeStep(trajectoryModel_M)) {
    /* Stop: '<Root>/Stop Simulation' */
    if (trajectoryModel_B.IfActionSubsystem1.In1 != 0.0) {
      rtmSetStopRequested(trajectoryModel_M, 1);
    }

    /* End of Stop: '<Root>/Stop Simulation' */
  }

  /* Integrator: '<Root>/dx' */
  trajectoryModel_B.x_dot = trajectoryModel_X.dx_CSTATE;

  /* Integrator: '<Root>/dy' */
  trajectoryModel_B.y_dot = trajectoryModel_X.dy_CSTATE;
  if (rtmIsMajorTimeStep(trajectoryModel_M)) {
  }

  /* Sum: '<S4>/x-Planet_x' incorporates:
   *  Constant: '<Root>/Earth_x'
   */
  rtb_Divide1 = trajectoryModel_B.x - (-trajectoryModel_P.mu);

  /* Sqrt: '<S4>/Sqrt' incorporates:
   *  Product: '<S4>/(x-Planet_x)^2'
   *  Product: '<S4>/y^2'
   *  Sum: '<S4>/(x-Planet_x)^2+y^2'
   */
  rtb_Divide1 = sqrt(rtb_Divide1 * rtb_Divide1 + trajectoryModel_B.y *
                     trajectoryModel_B.y);

  /* Product: '<Root>/Divide1' incorporates:
   *  Constant: '<Root>/Moon_x Earth mass'
   *  Product: '<Root>/Divide2'
   */
  rtb_Divide1 = (1.0 - trajectoryModel_P.mu) / (rtb_Divide1 * rtb_Divide1 *
    rtb_Divide1);

  /* Sum: '<S5>/x-Planet_x' incorporates:
   *  Constant: '<Root>/Moon_x Earth mass'
   */
  rtb_Divide = trajectoryModel_B.x - (1.0 - trajectoryModel_P.mu);

  /* Sqrt: '<S5>/Sqrt' incorporates:
   *  Product: '<S5>/(x-Planet_x)^2'
   *  Product: '<S5>/y^2'
   *  Sum: '<S5>/(x-Planet_x)^2+y^2'
   */
  rtb_Divide = sqrt(rtb_Divide * rtb_Divide + trajectoryModel_B.y *
                    trajectoryModel_B.y);

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/Moon mass'
   *  Product: '<Root>/Divide3'
   */
  rtb_Divide = trajectoryModel_P.mu / (rtb_Divide * rtb_Divide * rtb_Divide);

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<Root>/2'
   */
  rtb_Add1 = (trajectoryModel_P._Value_f - rtb_Divide1) - rtb_Divide;

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<Root>/Gain'
   *  Product: '<Root>/Product'
   */
  trajectoryModel_B.Add = trajectoryModel_B.y * rtb_Add1 -
    trajectoryModel_P.Gain_Gain * trajectoryModel_B.x_dot;

  /* Sum: '<Root>/Add6' incorporates:
   *  Constant: '<Root>/Earth_x'
   *  Constant: '<Root>/Moon_x Earth mass'
   *  Gain: '<Root>/Gain1'
   *  Product: '<Root>/Product5'
   *  Product: '<Root>/Product6'
   *  Product: '<Root>/Product7'
   *  Sum: '<Root>/Add7'
   */
  trajectoryModel_B.Add6 = (((1.0 - trajectoryModel_P.mu) * rtb_Divide +
    -trajectoryModel_P.mu * rtb_Divide1) + trajectoryModel_B.x * rtb_Add1) +
    trajectoryModel_P.Gain1_Gain * trajectoryModel_B.y_dot;
  if (rtmIsMajorTimeStep(trajectoryModel_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(trajectoryModel_M->rtwLogInfo,
                        (trajectoryModel_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(trajectoryModel_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(trajectoryModel_M)!=-1) &&
          !((rtmGetTFinal(trajectoryModel_M)-
             (((trajectoryModel_M->Timing.clockTick1+
                trajectoryModel_M->Timing.clockTickH1* 4294967296.0)) * 0.01)) >
            (((trajectoryModel_M->Timing.clockTick1+
               trajectoryModel_M->Timing.clockTickH1* 4294967296.0)) * 0.01) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(trajectoryModel_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&trajectoryModel_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++trajectoryModel_M->Timing.clockTick0)) {
      ++trajectoryModel_M->Timing.clockTickH0;
    }

    trajectoryModel_M->Timing.t[0] = rtsiGetSolverStopTime
      (&trajectoryModel_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      trajectoryModel_M->Timing.clockTick1++;
      if (!trajectoryModel_M->Timing.clockTick1) {
        trajectoryModel_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void trajectoryModel_derivatives(void)
{
  XDot_trajectoryModel_T *_rtXdot;
  _rtXdot = ((XDot_trajectoryModel_T *) trajectoryModel_M->ModelData.derivs);

  /* Derivatives for Integrator: '<Root>/x' */
  _rtXdot->x_CSTATE = trajectoryModel_B.x_dot;

  /* Derivatives for Integrator: '<Root>/y ' */
  _rtXdot->y_CSTATE = trajectoryModel_B.y_dot;

  /* Derivatives for Integrator: '<Root>/dx' */
  _rtXdot->dx_CSTATE = trajectoryModel_B.Add6;

  /* Derivatives for Integrator: '<Root>/dy' */
  _rtXdot->dy_CSTATE = trajectoryModel_B.Add;
}

/* Model initialize function */
void trajectoryModel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  trajectoryModel_P.stopRadius = rtInf;

  /* initialize real-time model */
  (void) memset((void *)trajectoryModel_M, 0,
                sizeof(RT_MODEL_trajectoryModel_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&trajectoryModel_M->solverInfo,
                          &trajectoryModel_M->Timing.simTimeStep);
    rtsiSetTPtr(&trajectoryModel_M->solverInfo, &rtmGetTPtr(trajectoryModel_M));
    rtsiSetStepSizePtr(&trajectoryModel_M->solverInfo,
                       &trajectoryModel_M->Timing.stepSize0);
    rtsiSetdXPtr(&trajectoryModel_M->solverInfo,
                 &trajectoryModel_M->ModelData.derivs);
    rtsiSetContStatesPtr(&trajectoryModel_M->solverInfo, (real_T **)
                         &trajectoryModel_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&trajectoryModel_M->solverInfo,
      &trajectoryModel_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&trajectoryModel_M->solverInfo, (&rtmGetErrorStatus
      (trajectoryModel_M)));
    rtsiSetRTModelPtr(&trajectoryModel_M->solverInfo, trajectoryModel_M);
  }

  rtsiSetSimTimeStep(&trajectoryModel_M->solverInfo, MAJOR_TIME_STEP);
  trajectoryModel_M->ModelData.intgData.y = trajectoryModel_M->ModelData.odeY;
  trajectoryModel_M->ModelData.intgData.f[0] = trajectoryModel_M->
    ModelData.odeF[0];
  trajectoryModel_M->ModelData.intgData.f[1] = trajectoryModel_M->
    ModelData.odeF[1];
  trajectoryModel_M->ModelData.intgData.f[2] = trajectoryModel_M->
    ModelData.odeF[2];
  trajectoryModel_M->ModelData.contStates = ((X_trajectoryModel_T *)
    &trajectoryModel_X);
  rtsiSetSolverData(&trajectoryModel_M->solverInfo, (void *)
                    &trajectoryModel_M->ModelData.intgData);
  rtsiSetSolverName(&trajectoryModel_M->solverInfo,"ode3");
  rtmSetTPtr(trajectoryModel_M, &trajectoryModel_M->Timing.tArray[0]);
  rtmSetTFinal(trajectoryModel_M, 12.0);
  trajectoryModel_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    trajectoryModel_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(trajectoryModel_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(trajectoryModel_M->rtwLogInfo, (NULL));
    rtliSetLogT(trajectoryModel_M->rtwLogInfo, "tout");
    rtliSetLogX(trajectoryModel_M->rtwLogInfo, "");
    rtliSetLogXFinal(trajectoryModel_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(trajectoryModel_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(trajectoryModel_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(trajectoryModel_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(trajectoryModel_M->rtwLogInfo, 1);
    rtliSetLogY(trajectoryModel_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(trajectoryModel_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(trajectoryModel_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &trajectoryModel_B), 0,
                sizeof(B_trajectoryModel_T));

  /* states (continuous) */
  {
    (void) memset((void *)&trajectoryModel_X, 0,
                  sizeof(X_trajectoryModel_T));
  }

  /* states (dwork) */
  (void) memset((void *)&trajectoryModel_DW, 0,
                sizeof(DW_trajectoryModel_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(trajectoryModel_M->rtwLogInfo, 0.0,
    rtmGetTFinal(trajectoryModel_M), trajectoryModel_M->Timing.stepSize0,
    (&rtmGetErrorStatus(trajectoryModel_M)));

  /* Start for If: '<Root>/If' */
  trajectoryModel_DW.If_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<Root>/If Action Subsystem' */
  traject_IfActionSubsystem_Start(&trajectoryModel_B.IfActionSubsystem,
    (P_IfActionSubsystem_trajector_T *)&trajectoryModel_P.IfActionSubsystem);

  /* End of Start for SubSystem: '<Root>/If Action Subsystem' */

  /* Start for IfAction SubSystem: '<Root>/If Action Subsystem1' */
  traject_IfActionSubsystem_Start(&trajectoryModel_B.IfActionSubsystem1,
    (P_IfActionSubsystem_trajector_T *)&trajectoryModel_P.IfActionSubsystem1);

  /* End of Start for SubSystem: '<Root>/If Action Subsystem1' */

  /* InitializeConditions for Integrator: '<Root>/x' */
  trajectoryModel_X.x_CSTATE = trajectoryModel_P.initialConditions[0];

  /* InitializeConditions for Integrator: '<Root>/y ' */
  trajectoryModel_X.y_CSTATE = trajectoryModel_P.initialConditions[2];

  /* InitializeConditions for Integrator: '<Root>/dx' */
  trajectoryModel_X.dx_CSTATE = trajectoryModel_P.initialConditions[1];

  /* InitializeConditions for Integrator: '<Root>/dy' */
  trajectoryModel_X.dy_CSTATE = trajectoryModel_P.initialConditions[3];
}

/* Model terminate function */
void trajectoryModel_terminate(void)
{
  /* (no terminate code required) */
}
