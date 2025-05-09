/**
*   @file           Gpt_Ftm_Types.h
*   @version        1.0.1
*
*   @brief          AUTOSAR Gpt - Ftm data types header file.
*   @details        Ftm defines, types used by GPT driver.
*
*   @addtogroup     PWM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Ftm
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef GPT_FTM_TYPES_H
#define GPT_FTM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section [global]
*       Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*       on the significance of more than 31 characters. The used compilers use more than 31 chars
*       for identifiers
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Ftm_Common_Types.h"

#include "Reg_eSys_Ftm.h"

#include "Gpt_EnvCfg.h"
#include "Gpt_Cfg.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/

#define GPT_FTM_TYPES_VENDOR_ID                       43
#define GPT_FTM_TYPES_MODULE_ID                       100
#define GPT_FTM_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define GPT_FTM_TYPES_AR_RELEASE_MINOR_VERSION        2
#define GPT_FTM_TYPES_AR_RELEASE_REVISION_VERSION     2
#define GPT_FTM_TYPES_SW_MAJOR_VERSION                1
#define GPT_FTM_TYPES_SW_MINOR_VERSION                0
#define GPT_FTM_TYPES_SW_PATCH_VERSION                1

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* GPT_FTM_TYPES_H */

/** @} */
