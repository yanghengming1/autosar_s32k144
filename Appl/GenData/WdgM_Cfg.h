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
 *            Module: WdgM
 *           Program: MSR_Vector_SLP4
 *          Customer: Harman International (China) Holdings Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: FS32K148UAT0VLQR
 *    License Scope : The usage is restricted to CBD1800257_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WdgM_Cfg.h
 *   Generation Time: 2025-04-29 17:39:53
 *           Project: S32K144_Start - Version 1.0
 *          Delivery: CBD1800257_D01
 *      Tool Version: DaVinci Configurator  5.18.37 SP1
 *
 *
 *********************************************************************************************************************/

#if !defined (WDGM_CFG_H)
# define WDGM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "WdgM_Types.h"


/**********************************************************************************************************************
 *  VERSION INFORMATION AND CHECK
 *********************************************************************************************************************/

#define WDGM_CFG_MAJOR_VERSION (2u) 
#define WDGM_CFG_MINOR_VERSION (2u) 
#define WDGM_CFG_PATCH_VERSION (1u) 

/* Check the version of WdgM Types header file */
#if ( (WDGM_TYPES_MAJOR_VERSION != (5u)) \
   || (WDGM_TYPES_MINOR_VERSION != (3u)) )
# error "Version numbers of WdgM_Cfg.h and WdgM_Types.h are inconsistent!"
#endif

# define WDGM_NR_OF_CHECKPOINTS           (1u) 
# define WDGM_NR_OF_ENTITIES              (1u) 
# define WDGM_NR_OF_ALLOWED_CALLERS       (1u) 
# define WDGM_NR_OF_GLOBAL_TRANSITIONS    (0u) 
# define WDGM_NR_OF_LOCAL_TRANSITIONS     (0u) 
# define WDGM_NR_OF_WATCHDOGS_CORE0       (1u) 
# define WDGM_NR_OF_TRIGGER_MODES_CORE0   (1u) 

/* Checkpoints for supervised entity 'WdgMSupervisedEntity' */ 
# define WdgMConf_WdgMCheckpoint_WdgMCheckpoint (0u) 
 

# define WdgMConf_WdgMSupervisedEntity_WdgMSupervisedEntity (0u) 


#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(WdgM_ConfigType, WDGM_CONST) WdgMConfig_Mode0_core0; 

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*
 * Status reporting (WdgMStatusReportingMechanism) configured to WDGM_USE_MODE_SWITCH_PORTS
 */

#define WDGM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
 
/* 
 * Local callback routines for mode switch ports of core 0 
 */ 
/* Local state callback for supervised entity 'WdgMSupervisedEntity' */ 
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE0(WdgMMode Status); /* PRQA S 0777 */ /* MD_MSR_5.1_777 */ 
 
/* 
 * Global callback routine for mode switch ports of core0 
 */ 
FUNC(void, WDGM_CODE) WdgM_GlobalStatusChangeNotificationCore0(WdgMMode Status); /* PRQA S 0777 */ /* MD_MSR_5.1_777 */ 

#define WDGM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 

#endif /* WDGM_CFG_H*/

/**********************************************************************************************************************
 *  END OF FILE: WdgM_Cfg.h
 *********************************************************************************************************************/

