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
 *              File: Com_Cbk.h
 *   Generation Time: 2025-04-23 11:05:27
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

#if !defined (COM_CBK_H)
# define COM_CBK_H

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Com_Cot.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/



/**
 * \defgroup ComHandleIdsComRxPdu Handle IDs of handle space ComRxPdu.
 * \brief Rx Pdus
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_msg_Receive2_oCAN00_adb9646b_Rx               0u
#define ComConf_ComIPdu_msg_Receive_oCAN00_2b456e3f_Rx                1u
/**\} */

/**
 * \defgroup ComHandleIdsComTxPdu Handle IDs of handle space ComTxPdu.
 * \brief Tx Pdus
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_MyECU2_Com_CAN_Network                        0u
#define ComConf_ComIPdu_Rear_MyECU_oCAN00_ca7e15e0_Tx                 1u
#define ComConf_ComIPdu_msg_MyECU_Lamp_oCAN00_818e1651_Tx             2u
#define ComConf_ComIPdu_msg_Transmit_oCAN00_0723e95e_Tx               3u
/**\} */

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COM_START_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /*MD_MSR_MemMap */
/**********************************************************************************************************************
  Com_RxIndication
**********************************************************************************************************************/
/** \brief    This function is called by the lower layer after an I-PDU has been received.
    \param    RxPduId      ID of AUTOSAR COM I-PDU that has been received. Identifies the data that has been received.
                              Range: 0..(maximum number of I-PDU IDs received by AUTOSAR COM) - 1
    \param    PduInfoPtr      Payload information of the received I-PDU (pointer to data and data length).
    \return   none
    \context  The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used. 
    \synchronous TRUE
    \reentrant   TRUE, for different Handles
    \trace    SPEC-2737026
    \note     The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/**********************************************************************************************************************
  Com_TxConfirmation
**********************************************************************************************************************/
/** \brief    This function is called by the lower layer after the PDU has been transmitted on the network.
              A confirmation that is received for an I-PDU that does not require a confirmation is silently discarded.
    \param    TxPduId    ID of AUTOSAR COM I-PDU that has been transmitted.
                            Range: 0..(maximum number of I-PDU IDs transmitted by AUTOSAR COM) - 1
    \return   none
    \context  The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used. 
    \synchronous TRUE
    \reentrant   TRUE, for different Handles
    \trace    SPEC-2737028
    \note     The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_TxConfirmation(PduIdType TxPduId);



#define COM_STOP_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /* MD_MSR_MemMap */

#endif  /* COM_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cbk.h
**********************************************************************************************************************/

