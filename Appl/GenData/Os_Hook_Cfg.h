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
 *              File: Os_Hook_Cfg.h
 *   Generation Time: 2021-04-09 15:46:07
 *           Project: S32K144_Start - Version 1.0
 *          Delivery: CBD1800257_D01
 *      Tool Version: DaVinci Configurator  5.18.37 SP1
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_HOOK_CFG_H)                                                         /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_HOOK_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether the OS shall call startup hooks (STD_ON) or not (STD_OFF). */
# define OS_CFG_STARTUPHOOKS                     (STD_OFF)

/*! Defines whether the OS shall call shutdown hooks (STD_ON) or not (STD_OFF). */
# define OS_CFG_SHUTDOWNHOOKS                    (STD_OFF)

/*! Defines whether the OS shall call error hooks (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERRORHOOKS                       (STD_ON)

/*! Defines whether the OS shall call the protection hook (STD_ON) or not (STD_OFF). */
# define OS_CFG_PROTECTIONHOOK                   (STD_OFF)

/*! Number of all configured Hooks. */
# define OS_CFG_NUM_HOOKS                        (2uL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_HOOK_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hook_Cfg.h
 *********************************************************************************************************************/
