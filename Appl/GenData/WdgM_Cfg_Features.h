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
 *              File: WdgM_Cfg_Features.h
 *   Generation Time: 2025-04-29 17:39:53
 *           Project: S32K144_Start - Version 1.0
 *          Delivery: CBD1800257_D01
 *      Tool Version: DaVinci Configurator  5.18.37 SP1
 *
 *
 *********************************************************************************************************************/

#if !defined (WDGM_CFG_FEATURES_H)
# define WDGM_CFG_FEATURES_H

/**********************************************************************************************************************
 *  VERSION INFORMATION
 *********************************************************************************************************************/
#define WDGM_CFG_FEATURE_MAJOR_VERSION (2u) 
#define WDGM_CFG_FEATURE_MINOR_VERSION (2u) 
#define WDGM_CFG_FEATURE_PATCH_VERSION (1u) 


/**********************************************************************************************************************
 *  AUTOSAR feature defines
 *********************************************************************************************************************/
# define WDGM_VERSION_INFO_API                STD_OFF 
# define WDGM_DEV_ERROR_DETECT                STD_ON 
# define WDGM_DEFENSIVE_BEHAVIOR              STD_OFF 
# define WDGM_IMMEDIATE_RESET                 STD_ON 
# define WDGM_OFF_MODE_ENABLED                STD_OFF 



/**********************************************************************************************************************
 *  WDGM-specific feature defines (user-defined)
 *********************************************************************************************************************/
# define WDGM_USE_OS_SUSPEND_INTERRUPT        STD_ON 
# define WDGM_TIMEBASE_SOURCE         WDGM_INTERNAL_SOFTWARE_TICK 
# define WDGM_SECOND_RESET_PATH               STD_ON 
# define WDGM_TICK_OVERRUN_CORRECTION         STD_OFF 
# define WDGM_ENTITY_DEACTIVATION_ENABLED     STD_OFF 
# define WDGM_STATUS_REPORTING_MECHANISM WDGM_USE_MODE_SWITCH_PORTS 
# define WDGM_USE_RTE                         STD_ON 
# define WDGM_DEM_SUPERVISION_REPORT          STD_OFF 
# define WDGM_FIRSTCYCLE_ALIVECOUNTER_RESET   STD_OFF 
# define WDGM_AUTOSAR_DEBUGGING               STD_OFF 
# define WDGM_DEM_REPORT                      STD_OFF 


/**********************************************************************************************************************
 *  WDGM-specific feature defines (automatically computed)
 *********************************************************************************************************************/
# define WDGM_GLOBAL_TRANSITIONS              STD_OFF 
# define WDGM_MULTIPLE_TRIGGER_MODES          STD_OFF 


/**********************************************************************************************************************
 *  WDGM-specific feature defines for multi-core systems
 *  (all automatically computed except for OS core identification usage)
 *********************************************************************************************************************/
# define WDGM_MULTICORE_USAGE                 STD_OFF 


/**********************************************************************************************************************
 *  INCLUDES for Dem
 *********************************************************************************************************************/
/* Intentionally left empty. Preprocessor switch WDGM_DEM_REPORT is STD_OFF */ 



#endif /* WDGM_CFG_FEATURES_H */

/**********************************************************************************************************************
 *  END OF FILE: WdgM_Cfg_Features.h
 *********************************************************************************************************************/

