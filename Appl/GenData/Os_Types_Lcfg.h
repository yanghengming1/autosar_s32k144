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
 *              File: Os_Types_Lcfg.h
<<<<<<< HEAD
 *   Generation Time: 2025-05-05 16:57:09
=======
 *   Generation Time: 2025-04-29 17:39:53
>>>>>>> b7b035b69e0cb1b08d21bee52dc19eda703272f2
 *           Project: S32K144_Start - Version 1.0
 *          Delivery: CBD1800257_D01
 *      Tool Version: DaVinci Configurator  5.18.37 SP1
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_TYPES_LCFG_H)                                                       /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_TYPES_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* OS-Application identifiers. */
#define OsApplication_CPUMonitor OsApplication_CPUMonitor
#define SystemApplication_OsCore0 SystemApplication_OsCore0

/* Trusted function identifiers. */

/* Non-trusted function identifiers. */

/* Fast trusted function identifiers. */

/* Task identifiers. */
#define Default_Init_Task Default_Init_Task
#define IdleTask_OsCore0 IdleTask_OsCore0
#define OsTask_APP OsTask_APP
#define OsTask_BSW_SCHM OsTask_BSW_SCHM
#define OsTask_CPUload_1s OsTask_CPUload_1s
#define OsTask_DLK_100ms OsTask_DLK_100ms
#define OsTask_EMC_PWL OsTask_EMC_PWL

/* Category 2 ISR identifiers. */
#define CanIsr_0_BusOff CanIsr_0_BusOff
#define CanIsr_0_MB00To15 CanIsr_0_MB00To15
#define CanIsr_0_MB16To31 CanIsr_0_MB16To31
#define CounterIsr_SystemTimer CounterIsr_SystemTimer
#define GptIsr_LpitChannel0 GptIsr_LpitChannel0
#define OsIsr_Ftm1Channel0 OsIsr_Ftm1Channel0
#define OsIsr_WDG OsIsr_WDG

/* Alarm identifiers. */
#define Rte_Al_TE2_OsTask_BSW_SCHM_0_10ms Rte_Al_TE2_OsTask_BSW_SCHM_0_10ms
#define Rte_Al_TE2_OsTask_BSW_SCHM_0_20ms Rte_Al_TE2_OsTask_BSW_SCHM_0_20ms
<<<<<<< HEAD
#define Rte_Al_TE_CPUload_SWC_CPUload_Runnable_1s Rte_Al_TE_CPUload_SWC_CPUload_Runnable_1s
=======
#define Rte_Al_TE2_OsTask_BSW_SCHM_0_50ms Rte_Al_TE2_OsTask_BSW_SCHM_0_50ms
>>>>>>> b7b035b69e0cb1b08d21bee52dc19eda703272f2
#define Rte_Al_TE_CanTp_CanTp_MainFunction Rte_Al_TE_CanTp_CanTp_MainFunction
#define Rte_Al_TE_Cdd_SBC_UJA1169_Sbc_Test_Runnable Rte_Al_TE_Cdd_SBC_UJA1169_Sbc_Test_Runnable
#define Rte_Al_TE_CpLedTask_LedRunnable Rte_Al_TE_CpLedTask_LedRunnable
#define Rte_Al_TE_EMC_SWC_EMC_Runnable_10ms Rte_Al_TE_EMC_SWC_EMC_Runnable_10ms
#define Rte_Al_TE_LOCK_SWC_DLK_Runnable_100ms Rte_Al_TE_LOCK_SWC_DLK_Runnable_100ms
#define Rte_Al_TE_PWL_SWC_PWL_Runnable_20ms Rte_Al_TE_PWL_SWC_PWL_Runnable_20ms

/* Counter identifiers. */
#define SystemTimer SystemTimer

/* ScheduleTable identifiers. */

/* Resource identifiers. */
#define OsResource OsResource

/* Spinlock identifiers. */

/* Peripheral identifiers. */

/* Barrier identifiers. */

/* Trace thread identifiers (Tasks and ISRs inclusive system objects). */

/* Trace spinlock identifiers (All spinlocks inclusive system objects). */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! OS-Application identifiers. */
typedef enum
{
  OsApplication_CPUMonitor = 0, /* 0x00000001 */
  SystemApplication_OsCore0 = 1, /* 0x00000002 */
  OS_APPID_COUNT = 2,
  INVALID_OSAPPLICATION = OS_APPID_COUNT
} ApplicationType;

/*! Trusted function identifiers. */
typedef enum
{
  OS_TRUSTEDFUNCTIONID_COUNT = 0
} TrustedFunctionIndexType;

/*! Non-trusted function identifiers. */
typedef enum
{
  OS_NONTRUSTEDFUNCTIONID_COUNT = 0
} Os_NonTrustedFunctionIndexType;

/*! Fast trusted function identifiers. */
typedef enum
{
  OS_FASTTRUSTEDFUNCTIONID_COUNT = 0
} Os_FastTrustedFunctionIndexType;

/*! Task identifiers. */
typedef enum
{
  Default_Init_Task = 0,
  IdleTask_OsCore0 = 1,
  OsTask_APP = 2,
  OsTask_BSW_SCHM = 3,
  OsTask_CPUload_1s = 4,
  OsTask_DLK_100ms = 5,
  OsTask_EMC_PWL = 6,
  OS_TASKID_COUNT = 7,
  INVALID_TASK = OS_TASKID_COUNT
} TaskType;

/*! Category 2 ISR identifiers. */
typedef enum
{
  CanIsr_0_BusOff = 0,
  CanIsr_0_MB00To15 = 1,
  CanIsr_0_MB16To31 = 2,
  CounterIsr_SystemTimer = 3,
  GptIsr_LpitChannel0 = 4,
  OsIsr_Ftm1Channel0 = 5,
  OsIsr_WDG = 6,
  OS_ISRID_COUNT = 7,
  INVALID_ISR = OS_ISRID_COUNT
} ISRType;

/*! Alarm identifiers. */
typedef enum
{
  Rte_Al_TE2_OsTask_BSW_SCHM_0_10ms = 0,
  Rte_Al_TE2_OsTask_BSW_SCHM_0_20ms = 1,
<<<<<<< HEAD
  Rte_Al_TE_CPUload_SWC_CPUload_Runnable_1s = 2,
  Rte_Al_TE_CanTp_CanTp_MainFunction = 3,
  Rte_Al_TE_Cdd_SBC_UJA1169_Sbc_Test_Runnable = 4,
  Rte_Al_TE_CpLedTask_LedRunnable = 5,
  Rte_Al_TE_EMC_SWC_EMC_Runnable_10ms = 6,
  Rte_Al_TE_LOCK_SWC_DLK_Runnable_100ms = 7,
  Rte_Al_TE_PWL_SWC_PWL_Runnable_20ms = 8,
  OS_ALARMID_COUNT = 9
=======
  Rte_Al_TE2_OsTask_BSW_SCHM_0_50ms = 2,
  Rte_Al_TE_CanTp_CanTp_MainFunction = 3,
  Rte_Al_TE_Cdd_SBC_UJA1169_Sbc_Test_Runnable = 4,
  Rte_Al_TE_CpLedTask_LedRunnable = 5,
  OS_ALARMID_COUNT = 6
>>>>>>> b7b035b69e0cb1b08d21bee52dc19eda703272f2
} AlarmType;

/*! Counter identifiers. */
typedef enum
{
  SystemTimer = 0,
  OS_COUNTERID_COUNT = 1
} CounterType;

/*! ScheduleTable identifiers. */
typedef enum
{
  OS_SCHTID_COUNT = 0
} ScheduleTableType;

/*! Resource identifiers. */
typedef enum
{
  OsResource = 0,
  OS_RESOURCEID_COUNT = 1
} ResourceType;

/*! Spinlock identifiers. */
typedef enum
{
  OS_SPINLOCKID_COUNT = 0,
  INVALID_SPINLOCK = OS_SPINLOCKID_COUNT
} SpinlockIdType;

/*! Peripheral identifiers. */
typedef enum
{
  OS_PERIPHERALID_COUNT = 0
} Os_PeripheralIdType;

/*! Barrier identifiers. */
typedef enum
{
  OS_BARRIERID_COUNT = 0
} Os_BarrierIdType;

/*! Trace thread identifiers (Tasks and ISRs inclusive system objects). */
typedef enum
{
  OS_TRACE_THREADID_COUNT = 0,
  OS_TRACE_INVALID_THREAD = OS_TRACE_THREADID_COUNT + 1
} Os_TraceThreadIdType;

/*! Trace spinlock identifiers (All spinlocks inclusive system objects). */
typedef enum
{
  OS_TRACE_NUMBER_OF_CONFIGURED_SPINLOCKS = OS_SPINLOCKID_COUNT,
  OS_TRACE_NUMBER_OF_ALL_SPINLOCKS = OS_SPINLOCKID_COUNT + 0,
  OS_TRACE_INVALID_SPINLOCK = OS_TRACE_NUMBER_OF_ALL_SPINLOCKS + 1
} Os_TraceSpinlockIdType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TYPES_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Types_Lcfg.h
 *********************************************************************************************************************/
