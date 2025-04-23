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
 *            Module: Com
 *           Program: MSR_Vector_SLP4
 *          Customer: Harman International (China) Holdings Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: FS32K148UAT0VLQR
 *    License Scope : The usage is restricted to CBD1800257_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Lcfg.h
 *   Generation Time: 2025-04-21 20:48:41
 *           Project: S32K144_Start - Version 1.0
 *          Delivery: CBD1800257_D01
 *      Tool Version: DaVinci Configurator  5.18.37 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] COM02205 - Inconsistent signal layout. 
 * - [Reduced Severity due to User-Defined Parameter] Overlapping ComSignals / ComGroupSignals / ComUpdateBitPositions exist in /ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx.
 * 
 * Overlapping signals:
 * /ActiveEcuC/Com/ComConfig/sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx, /ActiveEcuC/Com/ComConfig/MySignalGroup/ComGroupSignal
 * Erroneous configuration elements:
 * /ActiveEcuC/Com/ComConfig/sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx[0:ComBitPosition](value=0) (DefRef: /MICROSAR/Com/ComConfig/ComSignal/ComBitPosition)
 * /ActiveEcuC/Com/ComConfig/sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx[0:ComBitSize](value=8) (DefRef: /MICROSAR/Com/ComConfig/ComSignal/ComBitSize)
 * /ActiveEcuC/Com/ComConfig/MySignalGroup/ComGroupSignal[0:ComBitPosition](value=0) (DefRef: /MICROSAR/Com/ComConfig/ComSignalGroup/ComGroupSignal/ComBitPosition)
 * /ActiveEcuC/Com/ComConfig/MySignalGroup/ComGroupSignal[0:ComBitSize](value=8) (DefRef: /MICROSAR/Com/ComConfig/ComSignalGroup/ComGroupSignal/ComBitSize)
 * /ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx[0:ComIPduSignalGroupRef](value=/ActiveEcuC/Com/ComConfig/MySignalGroup) (DefRef: /MICROSAR/Com/ComConfig/ComIPdu/ComIPduSignalGroupRef)
 * /ActiveEcuC/Com/ComConfig/msg_Transmit_oCAN00_0723e95e_Tx[0:ComIPduSignalRef](value=/ActiveEcuC/Com/ComConfig/sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx) (DefRef: /MICROSAR/Com/ComConfig/ComIPdu/ComIPduSignalRef)
 * /ActiveEcuC/Com/ComConfig/sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx[0:ComSignalEndianness](value=LITTLE_ENDIAN) (DefRef: /MICROSAR/Com/ComConfig/ComSignal/ComSignalEndianness)
 * /ActiveEcuC/Com/ComConfig/sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx[0:ComSignalType](value=BOOLEAN) (DefRef: /MICROSAR/Com/ComConfig/ComSignal/ComSignalType)
 * /ActiveEcuC/Com/ComConfig/MySignalGroup/ComGroupSignal[0:ComSignalEndianness](value=LITTLE_ENDIAN) (DefRef: /MICROSAR/Com/ComConfig/ComSignalGroup/ComGroupSignal/ComSignalEndianness)
 * /ActiveEcuC/Com/ComConfig/MySignalGroup/ComGroupSignal[0:ComSignalType](value=UINT8) (DefRef: /MICROSAR/Com/ComConfig/ComSignalGroup/ComGroupSignal/ComSignalType)
 * 
 * [Warning] COM02300 - Invalid configuration of ComBitSize/ComSignalLength. 
 * - [Reduced Severity due to User-Defined Parameter] /ActiveEcuC/Com/ComConfig/sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx[0:ComBitSize](value=8) of /ActiveEcuC/Com/ComConfig/sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx must not extend size of BOOLEAN (size= 1)
 * Erroneous configuration elements:
 * /ActiveEcuC/Com/ComConfig/sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx[0:ComBitSize](value=8) (DefRef: /MICROSAR/Com/ComConfig/ComSignal/ComBitSize)
 *********************************************************************************************************************/

#if !defined (COM_LCFG_H)
# define COM_LCFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Com_Types.h"
# include "Com_Cfg.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComLTDataSwitches  Com Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define COM_LTCONFIG                                                  STD_OFF  /**< Deactivateable: 'Com_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/






#endif  /* COM_LCFG_H */
/**********************************************************************************************************************
  END OF FILE: Com_Lcfg.h
**********************************************************************************************************************/

