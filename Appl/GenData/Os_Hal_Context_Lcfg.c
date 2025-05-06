/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Harman International (China) Holdings Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: FS32K148UAT0VLQR
 *    License Scope : The usage is restricted to CBD1800257_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Context_Lcfg.c
<<<<<<< HEAD
 *   Generation Time: 2025-05-05 15:26:15
=======
 *   Generation Time: 2025-04-29 17:39:53
>>>>>>> b7b035b69e0cb1b08d21bee52dc19eda703272f2
 *           Project: S32K144_Start - Version 1.0
 *          Delivery: CBD1800257_D01
 *      Tool Version: DaVinci Configurator  5.18.37 SP1
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0810, 0828, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_MSR_1.1_810, MD_MSR_1.1_828, MD_MSR_1.1_857 */

#define OS_HAL_CONTEXT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Context.h"

/* Os kernel module dependencies */
#include "OsInt.h"
#include "Os_Core.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os hal dependencies */
#include "Os_Hal_Core.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn;

/*! HAL dynamic ISR2 level context data: Level4 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn;

/*! HAL dynamic ISR2 level context data: Level5 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level5_Dyn;

/*! HAL dynamic ISR2 level context data: Level6 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn;

/*! HAL dynamic ISR2 level context data: Level7 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn;

/*! HAL dynamic task context data: Default_Init_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Init_Task_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore0_Dyn;

/*! HAL dynamic task context data: OsTask_APP */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_APP_Dyn;

/*! HAL dynamic task context data: OsTask_BSW_SCHM */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_BSW_SCHM_Dyn;

/*! HAL dynamic task context data: OsTask_CPUload_1s */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_CPUload_1s_Dyn;

/*! HAL dynamic task context data: OsTask_DLK_100ms */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_DLK_100ms_Dyn;

/*! HAL dynamic task context data: OsTask_EMC_PWL */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_EMC_PWL_Dyn;

/*! HAL exception context data: OsCore0 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_ExceptionContext;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Init_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (20uL),
  /* .Entry            = */ (uint32)&Os_HookWrapperOs_CoreInitHook,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Init_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Init_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL hook context configuration data: ErrorHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Error_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (20uL),
  /* .Entry            = */ (uint32)&Os_HookWrapperStatusHook,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Error_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Error_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL ISR2 context configuration data: CanIsr_0_BusOff */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_0_BusOff =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ 20uL,
  /* .Entry            = */ (uint32)&Os_Isr_CanBusOffIsr_0,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL ISR2 context configuration data: CanIsr_0_MB00To15 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_0_MB00To15 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ 20uL,
  /* .Entry            = */ (uint32)&Os_Isr_CanMailboxIsr_0,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL ISR2 context configuration data: CanIsr_0_MB16To31 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_0_MB16To31 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ 20uL,
  /* .Entry            = */ (uint32)&Os_Isr_CanMailboxIsr_0,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ 20uL,
  /* .Entry            = */ (uint32)&Os_Isr_Os_TimerPitIsr,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL ISR2 context configuration data: GptIsr_LpitChannel0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GptIsr_LpitChannel0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ 20uL,
  /* .Entry            = */ (uint32)&Os_Isr_LPIT_0_CH_0_ISR,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL ISR2 context configuration data: OsIsr_Ftm1Channel0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_Ftm1Channel0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ 20uL,
  /* .Entry            = */ (uint32)&Os_Isr_FTM_1_CH_0_CH_1_ISR,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL ISR2 context configuration data: OsIsr_WDG */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_WDG =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ 20uL,
  /* .Entry            = */ (uint32)&Os_Isr_Wdg_Wdog0_Isr,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL task context configuration data: Default_Init_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Init_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio100_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Default_Init_Task,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio100_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio100_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL task context configuration data: IdleTask_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Os_IdleTask,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL task context configuration data: OsTask_APP */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_APP =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_APP_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_OsTask_APP,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_APP_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_APP_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL task context configuration data: OsTask_BSW_SCHM */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_BSW_SCHM =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_BSW_SCHM_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_OsTask_BSW_SCHM,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_BSW_SCHM_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_BSW_SCHM_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL task context configuration data: OsTask_CPUload_1s */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_CPUload_1s =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio20_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_OsTask_CPUload_1s,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio20_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio20_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL task context configuration data: OsTask_DLK_100ms */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_DLK_100ms =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio25_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_OsTask_DLK_100ms,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio25_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio25_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL task context configuration data: OsTask_EMC_PWL */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_EMC_PWL =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_EMC_PWL_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_OsTask_EMC_PWL,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_EMC_PWL_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_EMC_PWL_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL kernel stack configuration data: OsCore0_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore0_Kernel =
{
  /* .StackRegionEnd   = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn)+1),  /* OsCore0_Kernel */   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for HAL exception context. */
CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1] =
{
  &OsCfg_Hal_Context_OsCore0_ExceptionContext,
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_Lcfg.c
 *********************************************************************************************************************/
