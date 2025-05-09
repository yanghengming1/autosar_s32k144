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
 *              File: Os_Lcfg.h
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

#if !defined (OS_LCFG_H)                                                             /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"
# include "Os_Types.h"
# include "Os_Types_Lcfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Lcfg.h"

/* User file includes */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_Default_Init_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Default_Init_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_INIT_TASK_CODE) Os_Task_Default_Init_Task(void);

# define OS_STOP_SEC_Default_Init_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_APP_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_APP()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_APP_CODE) Os_Task_OsTask_APP(void);

# define OS_STOP_SEC_OsTask_APP_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_BSW_SCHM_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_BSW_SCHM()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_BSW_SCHM_CODE) Os_Task_OsTask_BSW_SCHM(void);

# define OS_STOP_SEC_OsTask_BSW_SCHM_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_CPUload_1s_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_CPUload_1s()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_CPULOAD_1S_CODE) Os_Task_OsTask_CPUload_1s(void);

# define OS_STOP_SEC_OsTask_CPUload_1s_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_DLK_100ms_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_DLK_100ms()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_DLK_100MS_CODE) Os_Task_OsTask_DLK_100ms(void);

# define OS_STOP_SEC_OsTask_DLK_100ms_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_EMC_PWL_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_EMC_PWL()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_EMC_PWL_CODE) Os_Task_OsTask_EMC_PWL(void);

# define OS_STOP_SEC_OsTask_EMC_PWL_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CanBusOffIsr_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  CanBusOffIsr_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANBUSOFFISR_0_CODE) Os_Isr_CanBusOffIsr_0(void);

# define OS_STOP_SEC_CanBusOffIsr_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CanMailboxIsr_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  CanMailboxIsr_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANMAILBOXISR_0_CODE) Os_Isr_CanMailboxIsr_0(void);

# define OS_STOP_SEC_CanMailboxIsr_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_FTM_1_CH_0_CH_1_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  FTM_1_CH_0_CH_1_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_FTM_1_CH_0_CH_1_ISR_CODE) Os_Isr_FTM_1_CH_0_CH_1_ISR(void);

# define OS_STOP_SEC_FTM_1_CH_0_CH_1_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_LPIT_0_CH_0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LPIT_0_CH_0_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_LPIT_0_CH_0_ISR_CODE) Os_Isr_LPIT_0_CH_0_ISR(void);

# define OS_STOP_SEC_LPIT_0_CH_0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Wdg_Wdog0_Isr_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Wdg_Wdog0_Isr()
 *********************************************************************************************************************/
extern FUNC(void, OS_WDG_WDOG0_ISR_CODE) Os_Isr_Wdg_Wdog0_Isr(void);

# define OS_STOP_SEC_Wdg_Wdog0_Isr_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#endif /* OS_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Lcfg.h
 *********************************************************************************************************************/
