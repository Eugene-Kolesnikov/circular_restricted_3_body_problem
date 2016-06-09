/*
 * trajectoryModel.h
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
#ifndef RTW_HEADER_trajectoryModel_h_
#define RTW_HEADER_trajectoryModel_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef trajectoryModel_COMMON_INCLUDES_
# define trajectoryModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* trajectoryModel_COMMON_INCLUDES_ */

#include "trajectoryModel_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals for system '<Root>/If Action Subsystem' */
typedef struct {
  real_T In1;                          /* '<S1>/In1' */
} B_IfActionSubsystem_trajector_T;

/* Block signals (auto storage) */
typedef struct {
  real_T x;                            /* '<Root>/x' */
  real_T y;                            /* '<Root>/y ' */
  real_T x_dot;                        /* '<Root>/dx' */
  real_T y_dot;                        /* '<Root>/dy' */
  real_T Add;                          /* '<Root>/Add' */
  real_T Add6;                         /* '<Root>/Add6' */
  B_IfActionSubsystem_trajector_T IfActionSubsystem1;/* '<Root>/If Action Subsystem1' */
  B_IfActionSubsystem_trajector_T IfActionSubsystem;/* '<Root>/If Action Subsystem' */
} B_trajectoryModel_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } rt_PWORK;                          /* '<Root>/r(t)' */

  struct {
    void *LoggedData;
  } xydxdy_PWORK;                      /* '<Root>/x-y-dx-dy' */

  int8_T If_ActiveSubsystem;           /* '<Root>/If' */
} DW_trajectoryModel_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T x_CSTATE;                     /* '<Root>/x' */
  real_T y_CSTATE;                     /* '<Root>/y ' */
  real_T dx_CSTATE;                    /* '<Root>/dx' */
  real_T dy_CSTATE;                    /* '<Root>/dy' */
} X_trajectoryModel_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T x_CSTATE;                     /* '<Root>/x' */
  real_T y_CSTATE;                     /* '<Root>/y ' */
  real_T dx_CSTATE;                    /* '<Root>/dx' */
  real_T dy_CSTATE;                    /* '<Root>/dy' */
} XDot_trajectoryModel_T;

/* State disabled  */
typedef struct {
  boolean_T x_CSTATE;                  /* '<Root>/x' */
  boolean_T y_CSTATE;                  /* '<Root>/y ' */
  boolean_T dx_CSTATE;                 /* '<Root>/dx' */
  boolean_T dy_CSTATE;                 /* '<Root>/dy' */
} XDis_trajectoryModel_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters for system: '<Root>/If Action Subsystem' */
struct P_IfActionSubsystem_trajector_T_ {
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S1>/Out1'
                                        */
};

/* Parameters (auto storage) */
struct P_trajectoryModel_T_ {
  real_T initialConditions[4];         /* Variable: initialConditions
                                        * Referenced by:
                                        *   '<Root>/dx'
                                        *   '<Root>/dy'
                                        *   '<Root>/x'
                                        *   '<Root>/y '
                                        */
  real_T mu;                           /* Variable: mu
                                        * Referenced by:
                                        *   '<Root>/Earth_x'
                                        *   '<Root>/Moon mass'
                                        *   '<Root>/Moon_x Earth mass'
                                        */
  real_T stopRadius;                   /* Variable: stopRadius
                                        * Referenced by: '<Root>/stopRadius'
                                        */
  real_T _Value;                       /* Expression: 0
                                        * Referenced by: '<Root>/0 '
                                        */
  real_T terminate_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/terminate'
                                        */
  real_T _Value_f;                     /* Expression: 1
                                        * Referenced by: '<Root>/2'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<Root>/Gain1'
                                        */
  P_IfActionSubsystem_trajector_T IfActionSubsystem1;/* '<Root>/If Action Subsystem1' */
  P_IfActionSubsystem_trajector_T IfActionSubsystem;/* '<Root>/If Action Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_trajectoryModel_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_trajectoryModel_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[4];
    real_T odeF[3][4];
    ODE3_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_trajectoryModel_T trajectoryModel_P;

/* Block signals (auto storage) */
extern B_trajectoryModel_T trajectoryModel_B;

/* Continuous states (auto storage) */
extern X_trajectoryModel_T trajectoryModel_X;

/* Block states (auto storage) */
extern DW_trajectoryModel_T trajectoryModel_DW;

/* Model entry point functions */
extern void trajectoryModel_initialize(void);
extern void trajectoryModel_step(void);
extern void trajectoryModel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_trajectoryModel_T *const trajectoryModel_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'trajectoryModel'
 * '<S1>'   : 'trajectoryModel/If Action Subsystem'
 * '<S2>'   : 'trajectoryModel/If Action Subsystem1'
 * '<S3>'   : 'trajectoryModel/r(t)_'
 * '<S4>'   : 'trajectoryModel/r1'
 * '<S5>'   : 'trajectoryModel/r2'
 */
#endif                                 /* RTW_HEADER_trajectoryModel_h_ */
