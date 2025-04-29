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
 *              File: WdgM_StatusNotifications_Core0.c
 *   Generation Time: 2025-04-29 17:39:53
 *           Project: S32K144_Start - Version 1.0
 *          Delivery: CBD1800257_D01
 *      Tool Version: DaVinci Configurator  5.18.37 SP1
 *
 *
 *********************************************************************************************************************/

#define WDGM_STATUS_NOTIFICATIONS_CORE_0_C

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Rte_WdgM.h" 

#define WDGM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  WdgM_GlobalStatusChangeNotificationCore0
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the global status of core 0
 *              changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_GlobalStatusChangeNotificationCore0(WdgMMode status)
{
  (void) Rte_Switch_globalmode_Core0_currentMode(status);
}

/**********************************************************************************************************************
 *  WdgM_LocalStatusChangeNotificationSE0
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the local status of
 *              WdgMSupervisedEntity changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE0(WdgMMode status)
{
  (void) Rte_Switch_mode_WdgMSupervisedEntity_currentMode(status);
}

#define WDGM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: WdgM_StatusNotifications_Core0.h
 *********************************************************************************************************************/

