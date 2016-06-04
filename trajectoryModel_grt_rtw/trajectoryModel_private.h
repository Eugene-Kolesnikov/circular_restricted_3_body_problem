/*
 * trajectoryModel_private.h
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
#ifndef RTW_HEADER_trajectoryModel_private_h_
#define RTW_HEADER_trajectoryModel_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern void traject_IfActionSubsystem_Start(B_IfActionSubsystem_trajector_T
  *localB, P_IfActionSubsystem_trajector_T *localP);
extern void trajectoryMod_IfActionSubsystem(real_T rtu_In1,
  B_IfActionSubsystem_trajector_T *localB);

/* private model entry point functions */
extern void trajectoryModel_derivatives(void);

#endif                                 /* RTW_HEADER_trajectoryModel_private_h_ */
