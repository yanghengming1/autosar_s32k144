/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Flexcan3Asr Erzeugungsgangnummer: 120 */

/*        STARTSINGLE_OF_MULTIPLE_COMMENT      */

/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file     Can.h
 *  \brief    Interface header file of the CAN-Driver
 *  \details  Declaration of functions, variables, and constants as user API.
 *
 *********************************************************************************************************************/

/* ***************************************************************************
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
| Ht           Heike Honert              Vector Informatik GmbH
| Bir          Holger Birke              Vector Informatik GmbH
| Rse          Robert Schelkle           Vector Informatik GmbH
| Was          Andreas Weinrauch         Vector Informatik GmbH
| Zam          Artjom Zabirko            Vector Informatik GmbH
| Pl           Georg Pfluegel            Vector Informatik GmbH
| Rli          Roman Linder              Vector Informatik GmbH
| Bns          Benjamin Schuetterle      Vector Informatik GmbH
| Gaz          Carsten Gauglitz          Vector Informatik GmbH
| Yoe          Yacine Ouldboukhitine     Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date       Ver  Author  Description
| ---------  ---  ------ -- --------------------------------------------------
| 2012-01-09  1.00.00  Rse    - ESCAN00056163: Initial version: Hll - Flexcan3 - Imx6 - QCC - High-End - QNX
| 2012-09-20  1.01.00  Rse    - ESCAN00062414: Support workaround for erratum ERR005829
| 2013-01-30  1.02.00  Rse    - ESCAN00065347: Support platform MPC5700
|                             - ESCAN00064665: CANbedded only: CAN messages will not be sent any more
|                             - ESCAN00066667: Support workaround for erratum e5769
|                             - ESCAN00067035: Inconsistent combination of receive handle and receive information (id, dlc, data) is indicated to upper layer
| 2013-05-21  1.03.00  Rse    - ESCAN00067478: Support FlexCAN2 derivatives for RxFifo usage
|                             - ESCAN00067660: Support the feature Mirror Mode
| 2013-07-22  1.04.00  Rse    - ESCAN00069229: Support CAN message retransmit feature for FBL driver
|                             - ESCAN00070121: Support Vybrid with FlexCAN3
| 2013-11-21  1.05.00  Rse    - ESCAN00072129: ASR4 only: change BusOff behavior to ensure recovery time of 128x11 recessive bits
|                             - ESCAN00072322: AR4-328: Predefined Runtime Measurement Points
| 2013-12-09  1.06.00  Rse    - ESCAN00072515: AutoSar only: Can_SetControllerMode(controller, CAN_T_STOP) returns CAN_OK instead of CAN_NOT_OK
|                             - ESCAN00072597: CANbedded only: Retransmit does not work if more than 22 RxFullCAN objects are used
| 2014-01-08  1.07.00  Rse    - ESCAN00072828: CANbedded only: Compiler error: identifier "canCanInterruptCounter" is undefined
|                             - ESCAN00072863: Support Cancel in Hardware with Transmission Abort feature
|                             - ESCAN00072869: Support new interface for Bus Mirroring
| 2014-01-30  1.07.01  Rse    - ESCAN00073299: Parity check only available for Vybrid and MPC5700 derivatives
| 2014-02-06  1.07.02  Rse    - Some minor MISRA improvements
|                      Rse    - ESCAN00073889: CANbedded only: Compiler error: struct has unknown field
| 2014-03-24  1.07.03  Rse    - ESCAN00074424: Indication function is called twice for the reception of one BasicCAN message
| 2014-04-16  1.08.00  Rse    - ESCAN00075110: BusOff notification is called twice for one single BusOff event (FlexCAN2)
|                             - ESCAN00075955: Remove obsolete workaround implementation for e5769
|                             - ESCAN00075964: Delete unnecessary interrupt locks
|                             - ESCAN00075507: IAR Compiler warning: the order of volatile accesses is undefined
| 2014-06-24  1.09.00  Rse    - ESCAN00076588: CAN clock settings are invalid after reinitialization, error frames occur continuously on the bus
|                             - ESCAN00076653: Implement proper mode switch to init (FREEZE) mode in CAN controller initialization process
|                             - ESCAN00076657: MAXMB value is obsolete
|                             - ESCAN00077049: CANbedded only: Support Tx FullCAN Send Delay (External PIA)
|                             - ESCAN00077083: CANbedded only: LowLevel Message is not transmitted
|                             - ESCAN00077485: OS Exception when CAN driver is handled in User Mode
| 2014-08-13  1.10.00  Rse    - ESCAN00077825: Support derivative MPC5748G CUT2
| 2014-11-10  1.10.01  Rse    - ESCAN00079385: Compiler warning: argument of type "volatile uint32 *" is incompatible with parameter of type "volatile uint16 *"
| 2014-11-27  2.00.00  Rse    - ESCAN00078072: Support full functionality for CAN-FD (Mode 2)
|                             - ESCAN00079900: CANbedded only: Extended ID message with dominant SRR-Bit does not receive
|                             - ESCAN00079901: Support ComStackLib tables for ASR403 R11
|                             - ESCAN00079494: Add loop checks for mode switching in CAN Controller initialization process
| 2015-01-21  2.00.01  Rse    - ESCAN00080716: Standard CAN message is sent as CAN-FD message with baudrate switch
| 2015-04-09  2.00.02  Was    - ESCAN00082335: Update to Core 5.00.02, R11 (Vybrid)
| 2015-05-02  2.01.00  Rse    - ESCAN00082800: Support CANbedded compatibility
| 2015-09-02  2.02.00  Zam    - ESCAN00084930: Support Extended CAN RAM Check feature
| 2015-10-14  2.03.00  Pl     - ESCAN00085860: Support S32K with FlexCAN3
| 2015-12-03  3.00.00  Rse    - ESCAN00086974: Support R14 and process 3.0
| 2016-03-17  3.01.00  Rse    - ESCAN00088969: Support Extended RAM check for MSR403
| 2016-05-30  3.01.01  Rse    - ESCAN00090210: Compiler error: parse error near ';'
| 2016-06-20  3.01.02  Rse    - Update HL-ASR 5.04.01 for issue 89754
| 2016-08-03  3.01.03  Rse    - ESCAN00091088: Callback that indicates corrupt CAN Controller is called erroneously
| 2016-08-25  3.02.00  Rse    - ESCAN00091626: Support R14 for Arm32 platforms
|                             - ESCAN00092139: Support ISO CAN-FD
|                             - ESCAN00092218: Support possibility to use a non-CAN-FD baudrate on a CAN-FD channel
|                             - ESCAN00092333: Support asymmetric mailboxes
| 2016-10-26  3.02.01  Rse    - ESCAN00092531: Linker Error: undefined symbol found 'Can_GetCanNumberOfMaxMailboxes'
| 2016-12-12  3.02.02  Rli    - ESCAN00093255: CAN FD FULL support for Little Endian Architectures
| 2017-03-30  3.02.03  Rli    - ESCAN00094552: Compiler error: identifier Controller not declared
|                             - ESCAN00094764: MWCT101xS Support
| 2017-04-21  3.03.00  Rli    - ESCAN00094816: Support of Virtual Addressing
| 2017-09-05  3.03.03  Rli    - ESCAN00096527 Compiler warning: unused argument
| 2017-10-31  5.00.00  Rli    - ESCAN00097302 Support of SafeBSW for FlexCAN3
| 2018-03-08  5.00.01  Bns    - Update HL-ASR 5.07.02 for issue 96367
|                             - ESCAN00098678 Support Extended RAM Check for S32 
| 2018-03-12  5.01.00  Gaz    - ESCAN00098459 Update to Core 6.00.00
| 2018-06-19  5.02.00  Rli    - ESCAN00099727 Support of Virtual Addressing with CAN FD Mode 2
| 2018-08-02  5.03.00  Rli    - STORYC-6186: Support Silent Mode
|                             - ESCAN00100316 IMX8: Messages not received with CAN FD configuration
| 2018-10-19  5.04.00  Yoe    - STORYC-6683: Support SafeBsw for Asymmetric Mailboxes
| 2018-10-31  5.04.01  Yoe    - STORYC-6877: Support SafeBsw for S32k1xx derivatives
| 2018-11-22  5.04.02  Rli    - STORYC-7138: Update code due to Cfg5 bugfix
|************************************************************************** */

/*****************************************************************************
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| Bir          Holger Birke              Vector Informatik GmbH
| Wr           Hans Waaser               Vector Informatik GmbH
| Ces          Senol Cendere             Vector Informatik GmbH
| Pl           Georg Pfluegel            Vector Informatik GmbH
| Tvi          Timo Vanoni               Vector Informatik GmbH
|-----------------------------------------------------------------------------
|       C O R E    R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date       Ver  Author  Description
| ---------  ---  ------  ----------------------------------------------------
| 2005-09-15 0.01.00 Bir  - Creation
| 2005-11-17 1.00.00 Bir  - Finish CANoe, M32C
|                         - Change include structure and naming
| 2005-11-23 1.01.00 Bir  - some minor changes
| 2005-12-01 1.02.00 Bir  - Global Interrupt handling via OSEK supported
| 2006-01-19 1.03.00 Bir  - Wrong handle found and DET occur in CanFullCanMsgReceived
|                         - C_DISABLE_RESET_CAN_BUSOFF set (baud rate out of CANoe)
| 2006-03-16 1.04.00 Wr   - Added channel compatibility defines
|                         - Removed local parameter canHwChannels
|                         - Changed order of CanLL_TransmitLocalParameter
|                           and CanLL_TxTransmissionLocalParameter in Can_Write()
|                         - Rename CanWakeup() to CanHL_WakeupHandling()
|                         - Added support for NEC V850 aFCAN
|                         - Added CanLL_GeneratedStructureH for platform C_COMP_GHS_V85X  
|                         - Added general return value defines
|                         - Defined APPL_CAN_WAKEUP() to CanHL_WakeUpHandling()
|                         - Mapping of CanWakeUp() to Can_SetControllerMode(Controller, CAN_T_WAKEUP)
| 2006-04-19 1.05.00 Wr   - Added V850 specific handling for transition to SLEEP
|                         - Add switches to enable OSEK ISR handling for platform C_COMP_GHS_V85X
| 2006-05-22 2.00.00 Bir  - Support for AutoSar 2.0
|                         - Can.h and can_types.h connected
|                         - Include structure update
|                         - DET - switch change
|                         - API changes Can_Init(), Can_Write()
|                         - add Can_GetVersionInfo()
| 2006-06-06 2.01.00 Bir  - internal naming corrections for version defines
|                         - API for Det_ReportError changed (add parameter)
| 2006-06-12 2.02.00 Bir  - CaninitObject calculation changed
|                         - TriCore update for Interrupt priority defines
| 2006-06-12 2.03.00 Bir  - SetControllerMode return OK for unsupported STOP/START or SLEEP/WAKEUP
|                         - CaninitObject calculation changed
| 2006-06-12 2.04.00 Bir  - kCanNotSupported defined to 0x02 to avoid CAN_NOT_OK for that case
|                         - define for MEMORY_ROM (compatibility)
| 2006-07-05 2.05.00 Bir  - Can_HwHandleType as uint8
|                         - Review rework
| 2006-07-10 2.06.00 Bir  - Can_Write try/send also in case busy
| 2006-08-15 2.07.00 Bir  - mapping of CanSingleGlobalInterruptX changed
| 2006-09-04 2.08.00 Bir  - minor change in Can.h: ControllerName length expand to 20
| 2006-09-04 2.09.00 Bir  - minor change for MISRA compliance
|                         - add canStatus for initialization info
|                         - minor changes for MAC71xx
|                         - No interrupt lock inside "CanBasicCanMsgReceived"
|                         - Add FullCAN TX
|                         - Add TX Polling
|                         - Add Hardware Loop and DEM call
|                         - DET call for initialized call of Can_Init()
|                         - Add Can_InitMemory function
| 2006-11-06 2.10.00 Bir  - review rework
| 2006-11-08 2.11.00 Ces/Bir - Add Platform Mcs12x
|                         - Add local variable Controller in function Can_InitMemory()
|                         - Add define C_ENABLE_COPY_TX_DATA in header
| 2006-11-09 2.12.00 Bir  - Prepare for Post-build structure (ORGANI switch "C_HL_ENABLE_ASR_POSTBUILD_STRUCT" added)
| 2006-11-11 2.13.00 Pl   - Add Platform TMS470_DCAN
|                    Bir  - Move FullCAN Overrun notification token behind FullCAN Begin token
| 2006-11-15 2.14.00 Bir  - Post-build changes
|                         - Review changes
|                         - change CAN_HL_TX_OFFSET_HW_TO_LOG and logTxObjHandle value
|                         - ESCAN00018785: Send out of confirmation (TX Queue)
|                         - ESCAN00018915: Change multiple-include define
| 2007-01-15 2.15.00 Bir  - ESCAN00018896: wrong call to Dem_SetEventStatus
|                         - deactivate "CanOverrunNotification" due to no more need since ASR2.0
|                         - Support "Can_MainFunction_BusOff"
|                         - call Can_InitController in case of change mode from BUSOFF to START
|                         - Add Can_EnterCritical(), Can_LeaveCritical() / interrupt mapping over VStdLib or SchM
|                         - Change Version Scan Information
|                         - Remove V850 specific parts (shift to LL)
|                         - Remove Re-initialize DET report out of Can_InitController()
| 2007-02-20 2.16.00 Bir  - minor improvements
|                         - ESCAN00019720: WAKEUP does not appear after set SLEEP mode
| 2007-03-09 2.20.00 Bir  - ESCAN00019889: Update to ASR2.1
|                         - ESCAN00019889: change calculation of CAN_HL_TX_OFFSET_HW_TO_LOG (because multiplexed TX)
|                         - remove FullCAN switches to secure Post-build functionality without compile with FullCANs
|                         - ESCAN00020129: Compiler error: identifier "i" is undefined
|                         - Reduce BasicCAN logical mailbox to real BasicCAN (DLC_FIFO include size of Basic CAN)
|                         - Reduce Unused mailboxes logical mailbox to amount of sections (DLC_FIFO include size)
|                         - Move all version defines from Proto.h to Can.h (license scanning)
|                         - Add CAN_AR_*_VERSION
|                         - remove PduId out of mailbox (old from CANIf)
|                         - set "C_ENABLE_OSEK_OS_INTCAT2" if not defined "C_ENABLE_INT_OSCAT1"
|                         - set DLC also for FullCAN TX objects
|                         - generated Tables: CanActiveSendPdu,CanActiveSendState (size matter at link time)
|                         - return not OK for try to set SLEEP mode but failed in HW
|                         - move multichannel API define to Can.h
|                         - set "C_ENABLE_OSEK_OS_INTCAT2" if not defined "C_ENABLE_INT_OSCAT1"
|                         - do "CanLL_InitPowerOn" before "CanLL_InitPowerOnChannelSpecific"
|                         - move OSEK-switches out of irq.c
|                         - add CanLL_InitMemoryPowerOn token for special ll initialization
| 2007-08-28 2.21.00 Bir  - ESCAN00022112: RX Basic CAN used with wrong stop index
|                         - renaming "CaninitObject" to "Can_Init_CtrlIdx" (no runtime effect)
|                         - ESCAN00022168: Driver does not enter STOP mode for Sleep request (when SLEEP is not sup.)
|                         - ESCAN00022232: Add STOP-mode compatibility for FNOS-RP migration
|                         - ESCAN00022262: CanResetBusOffEnd() used with only one parameter
|                         - Add new Token "CanLL_RxFull_SearchHandle" for special HW-support (XGate)
|                         - ESCAN00022390: HW start-stop-index changed to RAM-table
| 2007-10-15 2.22.00 Bir  - ESCAN00022773: use of #ifndef instead of #if !defined
|                         - ESCAN00022774: improve runtime while change mode (STOP to SLEEP)
|                         - ESCAN00023040: minor improvements (add SPEC-1721, SPEC-1767, SPEC-1784, SPEC-1780, SPEC-1781)
|                         - ESCAN00023040: remove Interrupt locking in Can_Write() due to CanIf do this
|                         - ESCAN00023038: Multiple ECU
|                         - ESCAN00023047: Add version check
|                         - ESCAN00023049: change API of Can_Init() to one parameter, Add constant in Can_InitController() + Add Can_InitStruct API
|                         - ESCAN00023127: compiler warnings due to dummy assignments (used to satisfy other compilers)
|                         - ESCAN00023265: remove brackets around Can_EnterCritical
|                         - QAC / MISRA reworks
|                         - Add memory qualifiers
|                         - add v_def.h include (remove define of V_MEM..)
|                         - Review reworks
| 2007-12-14 2.23.00 Bir  - ESCAN00023442: Add extended Id support
|                         - some small changes for cancellation (cancel only less priority objects - more efficient)
|                         - protect Can_MainFunction_Read against re-entrant (ASR specification)
|                         - ESCAN00024354: Ignore API call with controller deactivated by identity
|                         - review rework
| 2008-02-06 3.00.00 Bir  - ESCAN00024406: ASR3.0
| 2008-03-25 3.01.00 Bir  - Add dummy assignment in "ResetBusOffEnd" avoid compiler warnings
|                         - ESCAN00025672: review reworks
|                         - ESCAN00025664: Message send with wrong ID type
|                         - ESCAN00026087: Case sensitive naming for all File names (and includes)
|                         - ESCAN00026186: Extension for MSR3.0 Link-time checks
|                         - ESCAN00025957: No access on "DEM-events" via DEM created and exported constant values
|                         - Move compatibility section (switches needed earlier)
| 2008-05-14 3.02.00 Bir  - ESCAN00026859: V_MEMRAM0 not allowed for type cast
|                         - ESCAN00026861: Token external declaration added
|                         - ESCAN00026990: Add LL-Token to reject Remote frames
|                         - (see ES_CAN00029839) Change naming: "INTERRUPT" and "POLLING" add prefix "CAN_*"
|                         - (see ES_CAN00029826) Remove include of v_cfg.h and v_def.h (will be generated)
|                         - ESCAN00030521: Linker error because of missing Interrupt service routine
|                         - Move include section to top of file (need before version defines)
| 2008-06-30 3.03.00 Bir  - ESCAN00027986 +(ESCAN00025773): Code optimization (save ROM and runtime)
|                           + Start/StopLoop as macro
|                           + Max Loop counter define move to LL
|                           + Add some FullCAN switches to ORGANI Basic CAN controllers
|                           + Multiple Search for Basic CAN HW object
|                           + CanInterrupt Lock only in nested interrupt case (CAN_NESTED_INTERRUPTS)
|                           + remove some HW-start/stop indexes and there calculation use instead info from mailbox-table
|                         - ESCAN00028069: change controller amount to library capable setting
|                         - ESCAN00026596: Extension for MSR3.0 generator version checks
| 2008-08-19 3.03.01 Bir  - minor review changes
|                         - ESCAN00029385: change naming finishFullCan to finishRxFullCan (CAN-bedded compliance)
| 2008-09-11 3.04.00 Bir  - ESCAN00029942: Generator Version Check failed
| 2008-09-18 3.05.00 Bir  - ESCAN00029830: Add Link-time/Post-build configure CRC check
|                         - ESCAN00029434: rename "INTERRUPT" and "POLLING" switch
| 2008-10-15 3.06.00 Bir  - remove CAN_HL_HW_x_STOPINDEX -> not used in HL and does not work for LL
|                         - ESCAN00029707: change transition from uninitialized->START->STOP to uninitialized->STOP
|                         - ESCAN00029129: Source of HW loop timer is not available to application
|                         - ESCAN00030728: move platform typedefs to Can.h
| 2008-10-28 3.06.01 Bir  - ESCAN00030926: lock interrupts while TX confirmation.
|                         - Add include protection for canproto.h
| 2008-10-28 3.07.00 Bir  - ESCAN00032401: CAN driver stays in an endless loop
|                         - ESCAN00032291: BUSOFF handling took some time with locked interrupts
|                         - ESCAN00032612: Support Individual Polling
|                         - ESCAN00032614: Add new memory qualifier V_MEMROM4_CFG for Post-build data access
| 2009-03-16 3.07.01 Bir  - ESCAN00033874: Add LL-token "CanLL_tCanRxInfoStruct" for structure tCanRxInfoStruct
| 2009-04-03 3.07.02 Bir  - ESCAN00034409: Add PRQA comments for MISRA justification
|                         - ESCAN00034551: Add support for reverse RX Basic CAN polling
|                         - ESCAN00034552: Optimize RX Basic CAN polling loop
|                         - ESCAN00034773: Add cancel TX in Hardware within TX polling task
| 2009-04-20 3.08.00 Bir  - ESCAN00034118: Add compiler abstraction
|                         - ESCAN00034119: Add memory abstraction
|                         - ESCAN00035606: Report DEM as DET "CAN_DEV_TIMEOUT_DETECT"
|                         - (see ES_CAN00035490) Report DEM as DET "CAN_DEV_TIMEOUT_DETECT"
|                         - ESCAN00036041: compiler warning label not referenced
| 2009-07-08 3.09.00 Bir  - ESCAN00034780: Confirmation without critical section
| 2009-07-22 3.09.01 Bir  - ESCAN00036593: compile error (variable declaration after assignment)
| 2009-08-03 3.09.02 Bir  - ESCAN00036822: TX data inconsistency
| 2009-08-24 3.09.03 Bir  - ESCAN00037276: Compiler warning "function declared implicitly"
| 2009-09-15 3.10.00 Bir  - ESCAN00037784: Add Generic Confirmation function
|                         - ESCAN00037789: Add feature RX Queue
|                         - change order of RX-DLC and "CanLL_RxBasicGetCANDataPtr" (support for mailbox in RAM)
|                         - ESCAN00038814: Wrong pointer class for TX data used
| 2010-01-19 3.11.00 Bir  - ESCAN00040258: Use Can_HwHandleType instead of uint8
|                         - ESCAN00040432: Code optimization for 1 controller systems
|                         - ESCAN00040433: Support dynamic FullCAN id
|                         - ESCAN00040234: remove v_cfg.h include (already done in can_cfg.h)
| 2010-03-03 3.11.01 Bir  - small review reworks
|                         - ESCAN00041364: Optimize Runtime of Can_SetControllerMode
|                         - ESCAN00041432: Declaration for ISRs missing in case of Full Polling with Individual Polling
| 2010-03-03 3.12.00 Bir  - ESCAN00041791: Suppress unexpected WAKEUP notification
|                         - ESCAN00041984: Support Common CAN
|                         - ESCAN00041996: Split Critical Sections
|                         - ESCAN00042333: Add Hardware assertion notification to DET
|                         - ESCAN00042459: Support WAKEUP-switch-off (no SLEEP mode - STOP mode instead)
|                         - ESCAN00043085: Compiler warnings due to missing cast
|                         - ESCAN00043224: New API Can_GetStatus()
|                         - ESCAN00043250: Add Application Interrupt lock functions
|                         - canWakeUp() call changed to CAN_WAKEUP() - used for LL
|                         - ESCAN00047602: compiler warning: "comparison between signed and unsigned"
|                         - ESCAN00044114: Stop sending messages after transition to STOP mode (and back to started)
| 2010-11-23 3.13.00 Bir  - ESCAN00043999: Support usage without v_def.h
|                         - ESCAN00044276: Reject unwanted ID types (software Filter)
|                         - ESCAN00045682: Compiler warning: dead assignment to "X" eliminated
|                         - ESCAN00045883: Can_SetControllerMode doesn't return CAN_NOT_OK when called with invalid Transition parameter
|                         - ESCAN00045884: Can_CheckWakeup doesn't raise the CAN_E_UNINIT development error
|                         - ESCAN00046363: Adapt AUTOSAR version check
|                         - rename "canInterruptCounter" to "canCanInterruptCounter" CBD compatibility
|                         - ESCAN00047875: Add support for partial network
|                         - ESCAN00047951: Compile error, if the feature "Optimize for one controller" is used
| 2011-03-11 4.00.00  Bir - ESCAN00043688: Support AUTOSAR 4.0 R1
|                         - ESCAN00043998: Add GenData checker
|                         - ESCAN00044010: Add Notification for Overrun detection
|                         - ESCAN00047111: Support RAM check
|                         - ESCAN00046778: Support Multiple Identity Configuration
| 2011-04-05 4.00.01  Bir - void cast DET call for MSR40 + review reworks (minors)
|                         - ESCAN00049572: RAM-check: communication is not deactivated
|                         - ESCAN00050862: EcuM_CheckWakeup is not called in case of WAKEUP Polling
|                         - ESCAN00051562: Remove the AUTOSAR Release Version Check
|                         - ESCAN00047929: Can_Init() does not initialize CAN controllers - but Can Interface do this
|                         - ESCAN00049613: AR Version is not correct (2.2.0 instead of 2.2.1)
| 2011-06-21 4.01.00  Bir - ESCAN00050960: Provide API for Generic Pretransmit (AR3-1654 )
|                         - ESCAN00051102: Compiler warning: narrowing or signed-to-unsigned type conversion found: int to unsigned char
|                         - ESCAN00052324: Compile error if the feature "Optimize for one controller" and "RX Queue" is used
|                         - ESCAN00054829: Fault tolerant API: Do not throw DET in case of MultipleEcuConfig inactive controller for 'Can_CheckWakeup'
|                         - ESCAN00053648: Wrong Define name used "CAN_DEACTIVATE_COMMUNICATION"
|                         - ESCAN00053270: AR3-1698: Add MISRA justifications in source code for automatic generation of MISRA reports
|                         - ESCAN00053263: AR3-2069: Remove non-SchM code for critical section handling
|                         - ESCAN00054038: Compiler warning: variable "canApiContext" was set but never used
|                         - ESCAN00054813: Add Mirror functionality
| 2011-11-21 4.01.01  Bir - ESCAN00055001: Support Transition HW-Loops for MSR30
|                         - ESCAN00055076: MISRA compliance
| 2011-12-14 4.01.02  Bir - ESCAN00055566: Include of DET with camel case spelling
| 2011-12-15 4.01.03  Bir - ESCAN00055589: SPEC-1761
|                         - ESCAN00056004: Add Code Trace ability to AutoSar SWS
|                         - Add explicit type casts to satisfy COSMIC compilers (MCS12x)
|                         - ESCAN00056185: Change Version Check
| 2012-01-20 4.02.00  Bir - ESCAN00055076: MISRA compliance
|                         - Use !CAN_USE_VECTOR_IF instead of VGEN_GENERATOR_GENY (also support CFG5 in mixed systems)
|                         - ESCAN00057438: AR3-2383: Implement handling of call to Dem_ReportErrorStatus
|                         - ESCAN00057164: WAKEUP while Re-Initialization ASR3.2.1
|                         - ESCAN00054830: Can_SetControllerMode() return failed
| 2012-05-31 4.02.01  Bir - ESCAN00059203: Compiler error: missing variable canHwChannel in Can_CleanUpSendState()
|                         - ESCAN00059265: Compiler error: hardware loop index is not available as define for API
| 2012-06-12 4.03.00  Bir - ESCAN00057437: AR3-2374: Implement Silent BSW
|                         - ESCAN00059412: AR4-135: support MSR 4 R5
|                         - ESCAN00059488: Compiler error: identifier "Can_ConfigDataPtr" is undefined
|                         - ESCAN00060494: Compiler error: SchM_Enter_Can((area)) causes Compiler Error with external SchM Usage
| 2012-09-03 4.03.01  Bir - Improve MISRA compliance
|                         - ESCAN00061352: Endless Loop
| 2012-09-03 4.04.00  Bir - ESCAN00061042: AR3-2378: Implement AMD time measurement support
|                         - ESCAN00060586: AR3-2446: Update Code analysis and change analysis UUIDs (like described in Silent design)
|                         - ESCAN00060554: AR3-2443: Implement Silent Checks in BSW module code
|                         - Add support for FullCAN TX cancellation only
|                         - ESCAN00062679: Add source defines according to MICROSAR template source file
| 2012-12-10 4.04.01  Bir - Rework Silent BSW
| 2013-01-28 4.04.02  Bir - ESCAN00064474: Modify Hook_On (code can be removed by integration ORGANI)
| 2013-02-02 4.05.00  Bir - optimize token StopReinit usage
|                         - move some global compatibility defines from proto.h to Can.h
|                         - ESCAN00063652: RxQueue extension to 16bit size
|                         - ESCAN00064324: AR4-325: Implement Post-Build Loadable
|                         - ESCAN00066278: Incorrect comment description for function Can_CheckWakeup / Can_Cbk_CheckWakeup
| 2013-06-11 4.05.01  Bir - ESCAN00067936: Can_GetStatus wrongly returns CAN_STATUS_INCONSISTENT
|                         - Add QAC deviations for 6010, 6030, 6050, 6080
| 2013-06-12 4.06.00  Tvi/Bir - ESCAN00069107: AR4-397: Implement support for CAN-FD according to ASR4.1.1
|                         - ESCAN00070197: Compiler warning: variable Can_ConfigDataPtr was declared but never referenced
|                         - ESCAN00068900: Compiler warning
|                         - ESCAN00067711: AR4-328 / RTM measurement R8
|                         - ESCAN00070625: Adapt usage of CanResetBusOffEnd
|                         - ESCAN00071048: Support null_ptr data in Can_Write() for DLC==0
|                         - Add DOXYGEN comments to be used by API scanner
|                         - move some global compatibility defines from proto.h to Can.h
| 2013-10-25 4.06.01  Bir - R9 version / some minor MISRA improvements
|                         - ESCAN00073272: Support Can_InitController() failure in LL
|                         - ESCAN00073676: Its not possible to switch off MIRROR mode for reception when using RxQueue
|                         - ESCAN00073516: MIRROR_MODE add CAN interrupt lock around confirmation
| 2014-06-23 4.06.02  Bir - ESCAN00076374: Add TX Request cancellation in case of HW-loop break
| 2014-06-23 4.07.00  Bir - R10 ComStackLibAbtraction
|                         - ESCAN00074371: AR4-457: Support CAN-FD mode 2
| 2014-07-01 5.00.00  Bir - R11
|                         - ESCAN00076631: Post-build selectable (+loadable)
|                         - ESCAN00076498: CAN FD mode2
|                         - ESCAN00076634: Multiple CAN driver support
|                         - ESCAN00078089: RAM Check also for emulated SLEEP
|                         - ESCAN00079232: rename canProto.h to Can_Local.h
| 2014-11-24 5.00.01  Bir - coverage improvements
|                         - ESCAN00079480: support GENy (ComStackLib abstraction)
| 2014-12-14 5.01.00  Bir - ESCAN00079794: CAN-FD configured padding
|                         - ESCAN00080453: mask out FD-Bit in GenericPrecopy
|                         - ESCAN00080757: Limit DLC to 8 for Classic CAN RX-Frames
|                         - Support TxIndirectionHwToLog and LogToHw (platforms that use hwHandles for TX shadow buffers)
|                         - ESCAN00081930: DET error (CAN_INITCTR_ID, CAN_E_PARAM_CONTROLLER) occur
|                         - ESCAN00082533: BasicCAN message cancelled out of hardware but is not configured
| 2015-01-19 5.02.00  Bir - ESCAN00080306: FEAT-427 SafeBSW
|                           ESCAN00081793: FEAT-1275 SafeBSW step2
|                           + Merge API and Core history and move it to Can.h
|                           + add code design comments / rework comments in general
|                           + rework DET and SilentDet handling (SilentDet is now DET, no more MACRO)
|                           + split large functions in INLINE functions to reduce CYC
|                           ESCAN00073798: disable CAN interrupts while polling
|                           ESCAN00082042: API description Appl_GenericPrecopy
|                           ESCAN00082274: FEAT-1379: Optimized copy operation for large data
|                           ESCAN00082688: DET error (CAN_MAINFCT_*_ID, CAN_E_PARAM_CONTROLLER) occur
| 2015-07-30 5.02.01  Bir - remove goto/labels for HL - add it for LL
|                           shift CanLL_DefinesDataTypesStructsUnions from Can.c to Can_Local.h
|                           typedef Can_ControllerConfigPtrType from Can_Cfg.h in case of postbuild
|                           include det.h only for report level not detection (from 5.02.00)
|                           ESCAN00084263, ESCAN00084264: reject illegal DLC
| 2015-11-09 5.02.02  Bir - ESCAN00086345: BasicCAN RX message not received
| 2015-10-27 5.03.00  Bir - ESCAN00085666: Gateway - multiple BasicCAN Tx
|                           Add CanHL_StopReinit, CanHL_RxBasicMsgReceivePolling, CanHL_RxFullMsgReceivePolling
|                           remove Copyright info from Core use LL Copyright instead
| 2015-12-21 5.03.01  Bir - ESCAN00087253: preprocessor directives error in CanHL_WakeupTransition() or CanHL_SleepTransition()
| 2016-01-15 5.03.02  Bir - ESCAN00087518: Illegal pointer access when driver is not initialized
|                           test coverage improvements / minor MISRA improvements
|                           remove some _COMMEN_T postfixes for ORGANI (HW-layout may be TOOL dependent)
| 2016-01-29 5.04.00  Bir - test coverage improvements / minor MISRA improvements
|                           ESCAN00088335: FEAT-598: Extended RAM Check / SelfDiag
|                           ESCAN00087810: FEAT-1688: SafeBSW Step 4
|                           ESCAN00089399: Compiler error: 0=0 assignment
| 2016-04-14 5.04.01  Bir - review rework from 5.04.00
|                           rework traceability, rework coverage comments
|                           ESCAN00089754: Compile error overrun notification by DET without DET enabled (MSR401 only)
| 2016-06-21 5.05.00  Bir - ESCAN00089632: FEAT-1908: Access to Interrupt Control Register via OS
|                           ESCAN00089592: FEAT-1513: Release of CAN-FD
|                           FEAT-1602: Release of MultiBasicCAN-Tx (Gateway)
| 2016-08-24 5.05.01  Bir - ESCAN00091600: support MultiBasicCanTx with HW size > 1
| 2016-08-25 5.05.02  Bir - minor design improvement because of SafetyCheck
|                           ESCAN00091764: mode transition will be fully synchronous
| 2016-10-13 5.05.03  Bir - Add infix for local data and code (test without static to stimulate internal interfaces)
|                         - some minor COV comment improvements
| 2017-02-17 5.05.04  Bir - ESCAN00094060: Define CAN_H renamed (linux reuse)
|                           add infix to CAN_DUMMY_STATEMENT
|                           add coverage comment for Flexcan2 usage
|                           split in Can_MainFunction_Write -> add CanHL_TxTaskConfPendingHandling and CanHL_TxTaskCancelationHandling
| 2017-02-23 5.05.05  Bir - Minor Improvements relating COV and MISRA deviations
| 2017-03-29 5.06.00  Bir - FEATC-382: remove saturation
|                           ESCAN00094638: MICROSAR3 only: No RAM Check during wakeup or explicite call of Can_RamCheckExecute()
|                           ESCAN00095298: No transmit cancellation when calling Can_CancelTx() / CanIf_TransmitCancellation()
| 2017-05-29 5.07.00  Bir - FEAT-2738: support silent mode
|                           FEAT-2888: selective MultiplexedTx
| 2017-08-22 5.07.01  Bir - ESCAN00096086: compiler error: undefined Symbol Can_GetMailbox*IdxOfControllerConfig
|                           ESCAN00096369: Can_Write() return CAN_NOT_OK instead of CAN_BUSY in case of BO
|                           ESCAN00096391: Compiler error: function "CanHL_WakeupProcessed" / "CanHL_SleepProcessed" was referenced but not defined
| 2017-09-04 6.00.00  Bir - FEAT-3167: Remove "Tracing" feature
|                           ESCAN00096367: CAN driver does not recover from BusOff and stop communication.
|                           ESCAN00097096: Compiler error calling VStdMemCpy
|                           FEAT: Compiler error calling VStdMemCpy
|                           STORYC-3057 / ESCAN00098096: GenericPrecopy with FD-bit, GenericConfirmation(API2) with Len (instead of DLC) and FD-bit
|                                         ESCAN00098095: GenericConfirmation(API2) with Len instead of DLC
|                           STORYC-3329: MICROSAR3 Core Adaptation
|                           ESCAN00098892: Compiler warning: transitionRequest
|****************************************************************************/

#if !defined(CAN_API_H)
#define CAN_API_H /* refer to ESCAN00094060 */

/***************************************************************************/
/* Include                                                                 */
/***************************************************************************/
/* \trace SPEC-1408 */
#include "Can_Cfg.h"

#if !defined(CAN_MIRROR_MODE) /* COV_CAN_COMPATIBILITY */
# define CAN_MIRROR_MODE STD_OFF
#else
# if (CAN_MIRROR_MODE == STD_ON) /* COV_CAN_COMPATIBILITY */
#  include "CDDMirror.h"
#  define C_ENABLE_MIRROR_MODE
# endif
#endif

/* PRQA  S 0828 QAC_Can_0828 */ /* MD_Can_0828 */
/* PRQA  S 0850 QAC_Can_0850 */ /* MD_Can_0850 */

/***************************************************************************/
/* Version                  (abcd: Main version ab Sub Version cd )        */
/***************************************************************************/
/* Vector module version */
/* ##V_CFG_MANAGEMENT ##CQProject : DrvCan_ImxFlexcan3Asr CQComponent : Implementation */
#define DRVCAN_IMXFLEXCAN3ASR_VERSION 0x0504u
#define DRVCAN_IMXFLEXCAN3ASR_RELEASE_VERSION 0x02u

/* internal Core Version */
#define CAN_COREVERSION           0x0600u
#define CAN_RELEASE_COREVERSION   0x00u

/* AutoSar Version for API */
/* BR:013, BR:014 */
#if !defined(CAN_MSR403) /* COV_CAN_COMPATIBILITY */
# define CAN_MSR403                       403u
#endif
#if (CAN_MICROSAR_VERSION == CAN_MSR40) /* COV_CAN_MICROSAR_VERSION */
# define CAN_AR_RELEASE_MAJOR_VERSION      4
# define CAN_AR_RELEASE_MINOR_VERSION      0
# define CAN_AR_RELEASE_REVISION_VERSION   1
# define CAN_ENABLE_MICROSAR_VERSION_MSR40
# define CAN_ENABLE_MICROSAR_VERSION_MSR40X
#endif
#if (CAN_MICROSAR_VERSION == CAN_MSR403) /* COV_CAN_MICROSAR_VERSION */
# define CAN_AR_RELEASE_MAJOR_VERSION      4
# define CAN_AR_RELEASE_MINOR_VERSION      0
# define CAN_AR_RELEASE_REVISION_VERSION   3
# define CAN_ENABLE_MICROSAR_VERSION_MSR403
# define CAN_ENABLE_MICROSAR_VERSION_MSR40X
#endif
#if (CAN_MICROSAR_VERSION == CAN_MSR30) /* COV_CAN_MICROSAR_VERSION */
# define CAN_AR_MAJOR_VERSION              2
# define CAN_AR_MINOR_VERSION              5
# define CAN_AR_PATCH_VERSION              0
# define CAN_ENABLE_MICROSAR_VERSION_MSR30
#endif

/* AutoSar module version */
#define CAN_SW_MAJOR_VERSION   ((DRVCAN_IMXFLEXCAN3ASR_VERSION & 0xFF00u) >> 8)
#define CAN_SW_MINOR_VERSION   (DRVCAN_IMXFLEXCAN3ASR_VERSION & 0x00FFu)
#define CAN_SW_PATCH_VERSION   (DRVCAN_IMXFLEXCAN3ASR_RELEASE_VERSION & 0xFFu)

/***************************************************************************/
/* Defines and Macros                                                      */
/***************************************************************************/
#define CAN_VENDOR_ID   30u
#define CAN_MODULE_ID   80u
#if !defined(CAN_INSTANCE_ID) /* COV_CAN_COMPATIBILITY */
# define CAN_INSTANCE_ID  0u
#endif

#if !defined(CAN_30_GLOBAL_DEFINES) /* COV_CAN_USER_CONFIG */
# define CAN_30_GLOBAL_DEFINES
# if !defined(CAN_ENABLE_MICROSAR_VERSION_MSR403) /* otherwise enumeration in Can_GeneralTypes */ /* COV_CAN_MICROSAR_VERSION */
/* Can_SetControllerMode transient */
#  define CAN_T_START       0
#  define CAN_T_STOP        1
#  define CAN_T_SLEEP       2
#  define CAN_T_WAKEUP      3
/* return values (e.g. for Can_SetControllerMode) */
/* \trace SPEC-1397 */
#  define CAN_NOT_OK        (uint8)0x00
#  define CAN_OK            (uint8)0x01
#  define CAN_NOT_SUPPORTED ((uint8)0x02 | CAN_OK) /* not supported is OK + special bit for internal use -> used for SLEEP/WAKEUP mask out 0x02 to get CAN_OK */
#  define CAN_REQUESTED     (uint8)0x04
# endif
/* return values for Can_write */
# define CAN_FREE           CAN_OK              /* none AUTOSAR (used only internal) */
# define CAN_BUSY           CAN_NOT_SUPPORTED   /* none AUTOSAR (used only internal) */
#endif

#if !defined(kCanChannelNotUsed) /* COV_CAN_COMPATIBILITY */
# define kCanChannelNotUsed 0xFF
#endif

/* Module Id's */
#define CAN_INIT_ID            0x00
#define CAN_INITCTR_ID         0x02
#define CAN_SETCTR_ID          0x03
#define CAN_DIINT_ID           0x04
#define CAN_ENINT_ID           0x05
#define CAN_WRITE_ID           0x06
#define CAN_VERSION_ID         0x07
#define CAN_MAINFCT_WRITE_ID   0x01
#define CAN_MAINFCT_READ_ID    0x08
#define CAN_MAINFCT_BO_ID      0x09
#define CAN_MAINFCT_WU_ID      0x0A
#define CAN_MAINFCT_MODE_ID    0x0C
#define CAN_CKWAKEUP_ID        0x0B
#define CAN_CHANGE_BR_ID       0x0D
#define CAN_CHECK_BR_ID        0x0E
#define CAN_SET_BR_ID          0x0F

/* Internal Id's */
#define CAN_RXINDI_ID          0x10
#define CAN_TXCNF_ID           0x11
#define CAN_CTRWAKEUP_ID       0x12
#define CAN_CTRBUSOFF_ID       0x13
#define CAN_HW_ACCESS_ID       0x20

/* \trace SPEC-1702, SPEC-1401, SPEC-3780, SPEC-3839, SPEC-50568, SPEC-1568 */
/* Error Codes */
#define CAN_E_NO_ERROR              (uint8)0x00
#define CAN_E_PARAM_POINTER         (uint8)0x01
#define CAN_E_PARAM_HANDLE          (uint8)0x02
#define CAN_E_PARAM_DLC             (uint8)0x03
#define CAN_E_PARAM_CONTROLLER      (uint8)0x04
#define CAN_E_UNINIT                (uint8)0x05
#define CAN_E_TRANSITION            (uint8)0x06
#define CAN_E_DATALOST              (uint8)0x07   /* for MSR30 extension */
#define CAN_E_PARAM_BAUDRATE        (uint8)0x08   /* MRS403 only */
#define CAN_E_RXQUEUE               (uint8)0x10   /* extension */
#define CAN_E_TIMEOUT_DET           (uint8)0x11   /* extension */
#define CAN_E_GENDATA               (uint8)0x12   /* extension - used by LL to throw standardized issue for inconsistent generated data */

/* Return values Can_GetStatus() */
#define CAN_STATUS_UNINIT                       ((uint8)0x00) /* ASR extension */
#define CAN_STATUS_START                        ((uint8)0x01) /* ASR extension (kCanTxOn) */
#define CAN_STATUS_STOP                         ((uint8)0x02) /* STOP */
#define CAN_STATUS_INIT                         ((uint8)0x04) /* Initialized */
#define CAN_STATUS_INCONSISTENT                 ((uint8)0x08) /* Inconsistent      used for common CAN */
#define CAN_STATUS_WARNING                      ((uint8)0x10) /* WARNING */
#define CAN_STATUS_PASSIVE                      ((uint8)0x20) /* PASSIVE */
#define CAN_STATUS_BUSOFF                       ((uint8)0x40) /* BUSOFF */
#define CAN_STATUS_SLEEP                        ((uint8)0x80) /* SLEEP */
#define CAN_STATUS_MASK_NOMODE                  ((uint8)0x0C) /* Initialized & Inconsistent/DEACTIVATE */

#if defined(C_DRV_INTERNAL) /* just for internal usage */ /* COV_CAN_INTERNAL */
# define CAN_REQ_NONE                           ((uint8)0x00)
# define CAN_REQ_START                          ((uint8)0x01)
# define CAN_REQ_STOP                           ((uint8)0x02)
# define CAN_REQ_INIT_NO_STOP                   ((uint8)0x04)
# define CAN_REQ_WAKEUP                         ((uint8)0x08)
# define CAN_REQ_RAM_CHECK                      ((uint8)0x10)
# define CAN_REQ_SLEEP                          ((uint8)0x80)
#endif
/* Macros to use Can_GetStatus() */
#define CAN_HW_IS_OK(state)                     (((state) & (CAN_STATUS_WARNING |  \
                                                          CAN_STATUS_PASSIVE |  \
                                                          CAN_STATUS_BUSOFF) )    == 0) /* PRQA S 3453 */ /* MD_Can_3453 */
#define CAN_HW_IS_WARNING(state)                (((state) & CAN_STATUS_WARNING)      != 0) /* PRQA S 3453 */ /* MD_Can_3453 */
#define CAN_HW_IS_PASSIVE(state)                (((state) & CAN_STATUS_PASSIVE)      != 0) /* PRQA S 3453 */ /* MD_Can_3453 */
#define CAN_HW_IS_BUSOFF(state)                 (((state) & CAN_STATUS_BUSOFF)       != 0) /* PRQA S 3453 */ /* MD_Can_3453 */
#define CAN_HW_IS_WAKEUP(state)                 (((state) & CAN_STATUS_SLEEP)        == 0) /* PRQA S 3453 */ /* MD_Can_3453 */
#define CAN_HW_IS_SLEEP(state)                  (((state) & CAN_STATUS_SLEEP)        != 0) /* PRQA S 3453 */ /* MD_Can_3453 */
#define CAN_HW_IS_STOP(state)                   (((state) & CAN_STATUS_STOP)         != 0) /* PRQA S 3453 */ /* MD_Can_3453 */
#define CAN_HW_IS_START(state)                  (((state) & CAN_STATUS_START)        != 0) /* PRQA S 3453 */ /* MD_Can_3453 */
#define CAN_HW_IS_INCONSISTENT(state)           (((state) & CAN_STATUS_INCONSISTENT) != 0) /* PRQA S 3453 */ /* MD_Can_3453 */

/* Hardware Loop defines */
#if !defined(CAN_ENABLE_MICROSAR_VERSION_MSR30) /* COV_CAN_MICROSAR_VERSION */
# define kCanLoopStart        ((uint8)CAN_LOOP_MAX)  /* used by HL */ /* CM_CAN_HL23 */
# define kCanLoopStop         ((uint8)CAN_LOOP_MAX)  /* used by HL */ /* CM_CAN_HL23 */
# define kCanLoopSleep        ((uint8)CAN_LOOP_MAX)  /* used by HL */ /* CM_CAN_HL23 */
# define kCanLoopWakeup       ((uint8)CAN_LOOP_MAX)  /* used by HL */ /* CM_CAN_HL23 */
# define CAN_LOOP_AMOUNT   ((uint8)(CAN_LOOP_MAX + 1u))  /* used by HL */
#else
# define CAN_LOOP_AMOUNT   ((uint8)CAN_LOOP_MAX)  /* used by HL */
/* defined by LL */
#endif

/***************************************************************************/
/* LL return values                                                        */
/***************************************************************************/
/* return values of CanRxActualIdType */
#define kCanDLC               (0x0Fu)
#define kCanIdTypeStd         (0x00u)
#define kCanIdTypeExt         (0x20u) /* Attention: The SRR bit has to be considered for the transmission of Extended CAN frames, but must be without any effect on the reception side !
                                         ********** In Extended format it must be set to '1' for transmission.
                                                    For the Rx side it will be stored with the value received on the CAN bus, either recessive or dominant. */
#define kCanFdTypeFd          (0x80u)


/***************************************************************************/
/* LL parameter values                                                     */
/***************************************************************************/
/* parameter for ApplCanTimerStart(),-End(), -Loop() */
/* index has to start with 0, continues numbers have to be used. Gabs are not allowed! */
#define kCanLoopInit                  ((vuint8)0x00)
#define kCanLoopLeaveDisableMode      ((vuint8)0x01)
#define kCanLoopEnterDisableMode      ((vuint8)0x02)
#define kCanLoopMsgReception          ((vuint8)0x03)
#define kCanLoopEnterFreezeModeInit   ((vuint8)0x04)


# if (CAN_MICROSAR_VERSION == CAN_MSR30) /* COV_CAN_MICROSAR_VERSION */
#   define kCanLoopStart        ((vuint8)0x05U)  /* used by core */
#   define kCanLoopStop         ((vuint8)0x06U)  /* used by core */
# else
/* CAN_MSR40 use CAN_LOOP_MAX for internal loop index */
# endif

#define CAN_CHECK_DS_ID        0x30

/* compatibility (LL may need this for check against current status)  */
#define kCanHwIsInit CAN_STATUS_INIT
#define kCanHwIsSleep CAN_STATUS_SLEEP

/* results of CAN RAM check */
#define CAN_DEACTIVATE_CONTROLLER               CAN_STATUS_INCONSISTENT
#define CAN_ACTIVATE_CONTROLLER                 ((uint8)0x00)

/* compatibility to LL in can_irq.c / can.c */
#if !defined(CAN_DEV_ERROR_REPORT) /* COV_CAN_COMPATIBILITY */
# define CAN_DEV_ERROR_REPORT CAN_DEV_ERROR_DETECT
#endif
#if defined(V_OSTYPE_OSEK) || defined(V_OSTYPE_AUTOSAR) /* COV_CAN_OS_USAGE */
# if !defined(C_ENABLE_OSEK_OS) /* COV_CAN_OS_USAGE */
#  define C_ENABLE_OSEK_OS
# endif
# if !defined(C_ENABLE_OSEK_OS_INTCAT2) && !defined(C_DISABLE_OSEK_OS_INTCAT2) /* COV_CAN_OS_USAGE */
#  define C_ENABLE_OSEK_OS_INTCAT2
# endif
#endif
#if (CAN_TX_PROCESSING == CAN_POLLING) /* COV_CAN_TX_POLLING */
# define C_ENABLE_TX_POLLING
#endif
#if (CAN_RX_PROCESSING == CAN_POLLING) /* COV_CAN_RX_POLLING */
# define C_ENABLE_RX_BASICCAN_POLLING
# define C_ENABLE_RX_FULLCAN_POLLING
# define C_ENABLE_RX_POLLING
#endif
#if (CAN_BUSOFF_PROCESSING == CAN_POLLING) /* COV_CAN_ERROR_POLLING */
# define C_ENABLE_ERROR_POLLING
#endif
#if (CAN_WAKEUP_PROCESSING == CAN_POLLING) /* COV_CAN_WAKEUP_POLLING */
# define C_ENABLE_WAKEUP_POLLING
#endif
#if (CAN_INDIVIDUAL_PROCESSING == STD_ON) /* COV_CAN_INDIVIDUAL_POLLING */
# define C_ENABLE_INDIVIDUAL_POLLING
#endif
#if (CAN_MULTIPLE_BASICCAN == STD_ON) /* COV_CAN_MULTIPLE_BASICCAN */
# define C_ENABLE_MULTIPLE_BASICCAN
#endif
#if !defined(CAN_MULTIPLE_BASICCAN_TX) /* COV_CAN_COMPATIBILITY */
# define CAN_MULTIPLE_BASICCAN_TX STD_OFF
#else
# if (CAN_MULTIPLE_BASICCAN_TX == STD_ON) /* COV_CAN_MULTIPLE_BASICCAN_TX */
#  define C_ENABLE_MULTIPLE_BASICCAN_TX
# endif
#endif
#if (CAN_TX_FULLCAN_OBJECTS == STD_ON) /* COV_CAN_TX_FULLCAN_OBJECTS */
# define C_ENABLE_TX_FULLCAN_OBJECTS
#endif
#if (CAN_RX_FULLCAN_OBJECTS == STD_ON) /* COV_CAN_RX_FULLCAN_OBJECTS */
# define C_ENABLE_RX_FULLCAN_OBJECTS
#endif
#if (CAN_RX_BASICCAN_OBJECTS == STD_ON)
# define C_ENABLE_RX_BASICCAN_OBJECTS
#endif
#if (CAN_MULTI_ECU_CONFIG == STD_ON) /* COV_CAN_MULTI_ECU_CONFIG */
# define C_ENABLE_MULTI_ECU_CONFIG
#endif
#if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON) /* COV_CAN_HW_TRANSMIT_CANCELLATION */
# define C_ENABLE_CANCEL_IN_HW
#endif
#if defined(C_ENABLE_CANCEL_IN_HW) /* COV_CAN_CANCEL_IN_HW */
# define C_ENABLE_CANCEL_TX_IN_HW
#endif
#if (CAN_HARDWARE_CANCELLATION == STD_ON) /* COV_CAN_HARDWARE_CANCELLATION */
#define C_ENABLE_HW_LOOP_TIMER
#endif
#if (CAN_EXTENDED_ID == STD_ON) /* COV_CAN_EXTENDED_ID */
# define C_ENABLE_EXTENDED_ID
#endif
#if (CAN_MIXED_ID == STD_ON) /* COV_CAN_MIXED_ID */
# define C_ENABLE_MIXED_ID
#endif
#if (CAN_SECURE_TEMP_BUFFER == STD_ON) /* COV_CAN_SECURE_TEMP_BUFFER */
# define C_ENABLE_HWBUFFER
#endif
#if (CAN_SLEEP_SUPPORT == STD_ON) /* COV_CAN_SLEEP_SUPPORT */
# if (CAN_WAKEUP_SUPPORT == STD_ON) /* COV_CAN_WAKEUP_SUPPORT */
/* before version 3.12 this switches occur always synchronous both to ON or OFF (C_ENABLE_WAKEUP no more used) */
/* if CAN_WAKEUP_SUPPORT is switched off, STOP mode will be used instead of SLEEP (see AUTOSAR specification) */
# define C_ENABLE_SLEEP_WAKEUP
# endif
#endif
#if (CAN_COMMON_CAN == STD_ON) /* COV_CAN_COMMON_CAN */
# define C_ENABLE_COMMON_CAN
#else
# define C_DISABLE_COMMON_CAN
#endif
#if (CAN_OVERRUN_NOTIFICATION == CAN_APPL) /* COV_CAN_OVERRUN_NOTIFICATION */
# define C_ENABLE_OVERRUN
# define C_ENABLE_FULLCAN_OVERRUN
#endif
#if (CAN_OVERRUN_NOTIFICATION == CAN_DET) /* COV_CAN_OVERRUN_NOTIFICATION */
# if (CAN_DEV_ERROR_REPORT != STD_ON) /* COV_CAN_COMPATIBILITY */
#  if !defined(CAN_ENABLE_MICROSAR_VERSION_MSR40) /* MSR401: Tool always generate Overrun as DET */ /* COV_CAN_MICROSAR_VERSION */
#   error "CAN_OVERRUN_NOTIFICATION == CAN_DET need CAN_DEV_ERROR_REPORT == STD_ON"
#  endif
# else
#  define C_ENABLE_OVERRUN
#  define C_ENABLE_FULLCAN_OVERRUN
# endif
#endif
#if (CAN_MULTIPLEXED_TRANSMISSION == STD_ON) /* COV_CAN_MULTIPLEXED_TRANSMISSION */
# define C_ENABLE_MULTIPLEXED_TRANSMISSION
#endif
#if (CAN_EXTENDED_STATE_MACHINE == STD_ON) /* COV_CAN_EXTENDED_STATE_MACHINE */
# define CAN_ENABLE_EXTENDED_STATE_MACHINE
#endif
#if (CAN_BUSOFF_SUPPORT_API == STD_ON) /* COV_CAN_BUSOFF_SUPPORT_API */
# define CAN_ENABLE_BUSOFF_SUPPORT_API
#endif
#if (CAN_RX_QUEUE == STD_ON) /* COV_CAN_RX_QUEUE */
# define C_ENABLE_RX_QUEUE
#endif

/* compatibility to older baseAsr.dll */
#if !defined(CAN_API2) /* used for Appl_GenericConfirmation() to switch the API */ /* COV_CAN_COMPATIBILITY */
# define CAN_API2 2
#endif
#if !defined(CAN_GENERIC_CONFIRMATION) /* COV_CAN_COMPATIBILITY */
# define CAN_GENERIC_CONFIRMATION            STD_OFF
#endif
#if (CAN_GENERIC_CONFIRMATION == STD_ON)
# define CAN_ENABLE_GENERIC_CONFIRMATION_API1
#endif
#if (CAN_GENERIC_CONFIRMATION == CAN_API2) /* COV_CAN_GENERIC_CONFIRMATION_API2 */
# define CAN_ENABLE_GENERIC_CONFIRMATION_API2
#endif

#if !defined(CAN_DYNAMIC_FULLCAN_ID)  /* COV_CAN_COMPATIBILITY */
# define CAN_DYNAMIC_FULLCAN_ID              STD_ON
#endif
#if (CAN_DYNAMIC_FULLCAN_ID == STD_ON) /* COV_DYNAMIC_FULLCAN_ID */
# define CAN_ENABLE_DYNAMIC_FULLCAN_ID
#endif
#if !defined(CAN_ONE_CONTROLLER_OPTIMIZATION) /* COV_CAN_COMPATIBILITY */
#define CAN_ONE_CONTROLLER_OPTIMIZATION      STD_OFF
#endif
#if (CAN_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
# if defined(kCanNumberOfMaxUsedControllers) /* COV_CAN_COMPATIBILITY */
#  if (kCanNumberOfMaxUsedControllers != 1)
#   error "Using Optimization for one Controller does not work with more than 1 Controller (max) configured"
#  endif
# endif
# define C_SINGLE_RECEIVE_CHANNEL
# define C_DISABLE_MULTICHANNEL_API
# define CAN_CHANNEL_CANTYPE_ONLY         void   /* PRQA S 3460 */ /* MD_Can_3460 */
# define CAN_CHANNEL_CANTYPE_FIRST
# define CAN_CHANNEL_CANTYPE_LOCAL
# define CAN_CHANNEL_CANPARA_ONLY
# define CAN_CHANNEL_CANPARA_FIRST
# define CAN_HW_CHANNEL_CANTYPE_ONLY      void    /* PRQA S 3460 */ /* MD_Can_3460 */
# define CAN_HW_CHANNEL_CANTYPE_FIRST
# define CAN_HW_CHANNEL_CANTYPE_LOCAL
# define CAN_HW_CHANNEL_CANPARA_ONLY
# define CAN_HW_CHANNEL_CANPARA_FIRST
#else
# if defined(MISRA_CHECK) /* COV_CAN_MISRA */
#  pragma PRQA_MACRO_MESSAGES_OFF "CAN_CHANNEL_CANTYPE_LOCAL",781
#  pragma PRQA_MACRO_MESSAGES_OFF "CAN_HW_CHANNEL_CANTYPE_LOCAL",781
# endif
# define C_MULTIPLE_RECEIVE_CHANNEL
# define C_ENABLE_MULTICHANNEL_API
# define CAN_CHANNEL_CANTYPE_ONLY         CanChannelHandle  Controller
# define CAN_CHANNEL_CANTYPE_FIRST        CanChannelHandle  Controller,
# define CAN_CHANNEL_CANTYPE_LOCAL        CanChannelHandle  Controller; /* PRQA S 3412 */ /* MD_Can_3412 */
# define CAN_CHANNEL_CANPARA_ONLY        (CanChannelHandle) Controller
# define CAN_CHANNEL_CANPARA_FIRST       (CanChannelHandle) Controller,
#  define CAN_HW_CHANNEL_CANTYPE_ONLY     CanChannelHandle  Controller
#  define CAN_HW_CHANNEL_CANTYPE_FIRST    CanChannelHandle  Controller,
#  define CAN_HW_CHANNEL_CANTYPE_LOCAL    CanChannelHandle  Controller; /* PRQA S 3412 */ /* MD_Can_3412 */
#  define CAN_HW_CHANNEL_CANPARA_ONLY    (CanChannelHandle) Controller
#  define CAN_HW_CHANNEL_CANPARA_FIRST   (CanChannelHandle) Controller,
#endif
#if !defined(CAN_GET_STATUS) /* COV_CAN_COMPATIBILITY */
# define CAN_GET_STATUS STD_OFF
#endif
#if (CAN_GET_STATUS == STD_ON)
# define C_ENABLE_EXTENDED_STATUS
#endif
#if !defined(CAN_DRIVER) /* COV_CAN_COMPATIBILITY */
# define CAN_DRIVER 1
#endif
#if !defined(CAN_APPL) /* COV_CAN_COMPATIBILITY */
# define CAN_APPL 2
#endif
#if !defined(CAN_BOTH) /* COV_CAN_COMPATIBILITY */
# define CAN_BOTH 3
#endif
#if !defined(CAN_INTLOCK) /* COV_CAN_COMPATIBILITY */
# define CAN_INTLOCK CAN_DRIVER
#endif
#if !defined(CAN_PARTIAL_NETWORK) /* COV_CAN_COMPATIBILITY */
# define CAN_PARTIAL_NETWORK STD_OFF
#endif
#if (CAN_PARTIAL_NETWORK == STD_ON) /* COV_CAN_PARTIAL_NETWORK */
# define C_ENABLE_PARTIAL_NETWORK
#endif
#if !defined(CAN_EXTENDED) /* COV_CAN_COMPATIBILITY */
# define CAN_EXTENDED 3
#endif
#if !defined(CAN_RAM_CHECK) /* COV_CAN_COMPATIBILITY */
# define CAN_RAM_CHECK CAN_NONE
#else
# if (CAN_RAM_CHECK == CAN_NOTIFY_ISSUE) /* COV_CAN_RAM_CHECK */
#  define C_ENABLE_CAN_RAM_CHECK
#  define C_ENABLE_CAN_RAM_CHECK_WAKEUP
# endif
# if (CAN_RAM_CHECK == CAN_NOTIFY_MAILBOX) /* COV_CAN_RAM_CHECK */
#  define C_ENABLE_CAN_RAM_CHECK
#  define C_ENABLE_CAN_RAM_CHECK_WAKEUP
#  define C_ENABLE_NOTIFY_CORRUPT_MAILBOX
# endif
# if (CAN_RAM_CHECK == CAN_EXTENDED) /* COV_CAN_RAM_CHECK_EXTENDED */
#  define C_ENABLE_CAN_RAM_CHECK
#  define C_ENABLE_CAN_RAM_CHECK_EXTENDED
# endif
#endif

#if !defined(CAN_GENERIC_PRETRANSMIT) /* COV_CAN_COMPATIBILITY */
# define CAN_GENERIC_PRETRANSMIT STD_OFF
#endif

#if !defined(CAN_BRS) /* COV_CAN_COMPATIBILITY */
# define CAN_BRS 1u
#endif
#if !defined(CAN_FULL) /* COV_CAN_COMPATIBILITY */
# define CAN_FULL 2u
#endif
#if !defined(CAN_FD_SUPPORT) /* COV_CAN_COMPATIBILITY */
# define CAN_FD_SUPPORT CAN_NONE
#endif

#if (CAN_FD_SUPPORT != CAN_NONE) /* COV_CAN_FD_SUPPORT */
# define C_ENABLE_CAN_FD_USED
# if (CAN_FD_SUPPORT == CAN_BRS) /* COV_CAN_FD_SUPPORT */
#  define C_ENABLE_CAN_FD_BRS
# endif
# if (CAN_FD_SUPPORT == CAN_FULL) /* COV_CAN_FD_SUPPORT */
#  define C_ENABLE_CAN_FD_FULL
# endif
#endif

#if !defined(CAN_SET_BAUDRATE_API) /* COV_CAN_COMPATIBILITY */
# define CAN_SET_BAUDRATE_API STD_OFF
#endif

#if !defined(CAN_POSTBUILD_VARIANT_SUPPORT) /* COV_CAN_COMPATIBILITY */
# define CAN_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#if !defined(CAN_ENABLE_MICROSAR_VERSION_MSR403) /* !COM_STACK_LIB */ /* COV_CAN_MICROSAR_VERSION */
# define Can_GetPhysToLogChannel(Index)                 CanPhysToLogChannel[V_ACTIVE_IDENTITY_LOG][(Index)] /* PRQA S 3453 */ /* MD_Can_3453 */
#endif

#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR403) /* COM_STACK_LIB */ /* COV_CAN_MICROSAR_VERSION */
# if (CAN_USE_INIT_POINTER == STD_ON) /* InitPointer may not be used in variant system for symmetric configuration */
#  define CAN_ENABLE_USE_INIT_ROOT_POINTER
# endif
#else
# if defined(CAN_ENABLE_SELECTABLE_PB) || defined(C_ENABLE_MULTI_ECU_CONFIG)
#  define CAN_ENABLE_USE_INIT_ROOT_POINTER
# endif
#endif

#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR403) /* COM_STACK_LIB */ /* COV_CAN_MICROSAR_VERSION */
# if (CAN_USE_ECUM_BSW_ERROR_HOOK == STD_ON)
#  define CAN_ENABLE_USE_ECUM_BSW_ERROR_HOOK
# endif
#endif

#if !defined(CAN_DEV_TIMEOUT_DETECT) /* COV_CAN_COMPATIBILITY */
# define CAN_DEV_TIMEOUT_DETECT STD_OFF
#endif
#if (CAN_DEV_TIMEOUT_DETECT == STD_ON) /* COV_CAN_DEV_TIMEOUT_DETECT */
# define CAN_ENABLE_DEV_TIMEOUT_DETECT
#endif

#if !defined(CAN_USE_OS_INTERRUPT_CONTROL) /* COV_CAN_COMPATIBILITY */
# define CAN_USE_OS_INTERRUPT_CONTROL STD_OFF
#endif
#if (CAN_USE_OS_INTERRUPT_CONTROL == STD_ON) /* COV_CAN_COMPATIBILITY */
# define C_ENABLE_USE_OS_INTERRUPT_CONTROL
#endif

#if !defined(CAN_SILENT_MODE) /* COV_CAN_COMPATIBILITY */
# define CAN_SILENT_MODE STD_OFF
#endif
#if (CAN_SILENT_MODE == STD_ON) /* COV_CAN_COMPATIBILITY */
# define C_ENABLE_SILENT_MODE
#endif

/********************** compiler abstraction *******************************/
#if !defined(V_NULL) /* COV_CAN_COMPATIBILITY */
# define V_NULL          NULL_PTR
#endif
#if !defined(V_NONE) /* COV_CAN_COMPATIBILITY */
# define V_NONE       /* empty used instead of external, STATIC, volatile... */
# define CAN_AUTOMATIC    AUTOMATIC
# define CAN_TYPEDEF      TYPEDEF
#endif
#if !defined(CAN_STATIC) /* COV_CAN_COMPATIBILITY */
# if defined(STATIC) /* COV_CAN_COMPATIBILITY */
#  define CAN_STATIC  STATIC   /* standard by AutoSar 3.x */
# else
#  define CAN_STATIC  static   /* standard AutoSar 4.x define */
# endif
#endif
#if !defined(CAN_LOCAL_INLINE) /* COV_CAN_COMPATIBILITY */
# if defined(LOCAL_INLINE) /* COV_CAN_COMPATIBILITY */
#  define CAN_LOCAL_INLINE  LOCAL_INLINE
# else
#  define CAN_LOCAL_INLINE  
# endif
#endif

#define V_DEF_VAR(storage, vartype, memclass)                    storage VAR(vartype, CAN_##memclass)                                    /* PRQA S 0342,3410,3453 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453 */
#define V_DEF_VAR_FAR(storage, vartype)                          storage VAR(vartype, CAN_VAR_FAR)                                       /* PRQA S 0342,3410,3453 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453 */
#define V_DEF_VAR_NEAR(storage, vartype)                         storage VAR(vartype, CAN_VAR_NEAR)                                      /* PRQA S 0342,3410,3453 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453 */
#define V_DEF_VAR_TYPE(storage, vartype)                         typedef storage VAR(vartype, TYPEDEF)                                             /* PRQA S 0342,3410,3453 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453 */
#define V_DEF_P2VAR(storage, ptrtype, memclass, ptrclass)        storage P2VAR(ptrtype, CAN_##memclass, CAN_##ptrclass)        /* PRQA S 0342,3410,3453,0881 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453, MD_Can_Asr_0881_abstract */
#define V_DEF_P2VAR_TYPE(storage, ptrtype, ptrclass)             typedef storage P2VAR(ptrtype, TYPEDEF, CAN_##ptrclass )                /* PRQA S 0342,3410,3453,0881 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453, MD_Can_Asr_0881_abstract */
#define V_DEF_P2VAR_PARA(storage, ptrtype, memclass, ptrclass)   storage P2VAR(ptrtype, CAN_##memclass, CAN_##ptrclass)        /* PRQA S 0342,3410,3453,0881 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453, MD_Can_Asr_0881_abstract */
#define V_DEF_P2SFR_CAN(storage, ptrtype, memclass)              storage P2VAR(ptrtype, CAN_##memclass, CAN_REG_CANCELL)       /* PRQA S 0342,3410,3453 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453 */
#define V_DEF_P2SFR_CAN_TYPE(storage, ptrtype)                   typedef storage P2VAR(ptrtype, TYPEDEF, CAN_REG_CANCELL)                /* PRQA S 0342,3410,3453 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453 */
#define V_DEF_CONSTP2VAR(storage, ptrtype, memclass, ptrclass)   storage CONSTP2VAR(ptrtype, CAN_##memclass, CAN_##ptrclass)   /* PRQA S 0342,3410,3453,0881 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453, MD_Can_Asr_0881_abstract */
#define V_DEF_CONST(storage, type, memclass)                     storage CONST(type, CAN_##memclass)                                     /* PRQA S 0342,3410,3453 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453 */
#define V_DEF_CONST_TYPE(storage, type, memclass)                typedef storage CONST(type, TYPEDEF)                                              /* PRQA S 0342,3410,3453 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453 */
#define V_DEF_P2CONST(storage, ptrtype, memclass, ptrclass)      storage P2CONST(ptrtype, CAN_##memclass, CAN_##ptrclass)      /* PRQA S 0342,3410,3453,0881 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453, MD_Can_Asr_0881_abstract */
#define V_DEF_P2CONST_TYPE(storage, ptrtype, ptrclass)           typedef storage P2CONST(ptrtype, TYPEDEF, CAN_##ptrclass)               /* PRQA S 0342,3410,3453 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453 */
#define V_DEF_P2CONST_PARA(storage, ptrtype, memclass, ptrclass) storage P2CONST(ptrtype, CAN_##memclass, CAN_##ptrclass)      /* PRQA S 0342,3410,3453,0881 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453, MD_Can_Asr_0881_abstract */
#define V_DEF_CONSTP2CONST(storage, ptrtype, memclass, ptrclass) storage CONSTP2CONST(ptrtype, CAN_##memclass, CAN_##ptrclass) /* PRQA S 0342,3410,3453,0881 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453, MD_Can_Asr_0881_abstract */
#define V_DEF_CONSTP2CONST_TYPE(storage, ptrtype, ptrclass)      typedef storage CONSTP2CONST(ptrtype, TYPEDEF, CAN_##ptrclass)          /* PRQA S 0342,3410,3453 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453 */
#define V_DEF_FUNC(storage, rettype, memclass)                   storage FUNC(rettype, CAN_##memclass)                                   /* PRQA S 0342,3410,3453 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453 */
#define V_DEF_FUNC_API(storage, rettype, memclass)               storage FUNC(rettype, CAN_##memclass)                                   /* PRQA S 0342,3410,3453 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453 */
#define V_DEF_FUNC_CBK(storage, rettype, memclass)               storage FUNC(rettype, CAN_##memclass)                                   /* PRQA S 0342,3410,3453 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453 */
#define V_DEF_P2FUNC(storage, rettype, ptrclass, fctname)        storage P2FUNC(rettype, CAN_##ptrclass, fctname)                        /* PRQA S 0342,3410,3453 */ /* MD_Can_0342, MD_Can_3410, MD_Can_3453 */

/* only use internal when not defined before */
#if !defined(vuint8) /* COV_CAN_COMPATIBILITY */
# define CAN_HL_NO_V_DEF
# define vuint8 uint8 /* PRQA S 3436 */ /* MD_Can_3436 */
#endif
#if !defined(vsint8) /* COV_CAN_COMPATIBILITY */
# define vsint8 sint8 /* PRQA S 3436 */ /* MD_Can_3436 */
#endif
#if !defined(vuint16) /* COV_CAN_COMPATIBILITY */
# define vuint16 uint16 /* PRQA S 3436 */ /* MD_Can_3436 */
#endif
#if !defined(vsint16) /* COV_CAN_COMPATIBILITY */
# define vsint16 sint16 /* PRQA S 3436 */ /* MD_Can_3436 */
#endif
#if !defined(vuint32) /* COV_CAN_COMPATIBILITY */
# define vuint32 uint32 /* PRQA S 3436 */ /* MD_Can_3436 */
#endif
#if !defined(vsint32) /* COV_CAN_COMPATIBILITY */
# define vsint32 sint32 /* PRQA S 3436 */ /* MD_Can_3436 */
#endif


#if defined(C_DRV_INTERNAL) /* COV_CAN_INTERNAL */
/* PRQA S 0850 EOF */ /* MD_Can_0850 */
#endif

/* \trace SPEC-1399 */
/***************************************************************************/
/* data types need for API                                                 */
/***************************************************************************/
V_DEF_P2VAR_TYPE(V_NONE, Std_VersionInfoType, APPL_VAR) Can_VersionInfoPtrType;
V_DEF_P2CONST_TYPE(V_NONE, Can_ConfigType, CONST_PBCFG) Can_ConfigPtrType;
#if !defined(CAN_ENABLE_MICROSAR_VERSION_MSR403) || !defined(CAN_ENABLE_USE_INIT_ROOT_POINTER) /* COV_CAN_MICROSAR_VERSION */
V_DEF_P2CONST_TYPE(V_NONE, Can_ControllerConfigType, CONST_PBCFG) Can_ControllerConfigPtrType;
#endif
#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR40) /* COV_CAN_MICROSAR_VERSION */
V_DEF_P2CONST_TYPE(V_NONE, Can_ControllerBaudrateConfigType, APPL_VAR) Can_ControllerBaudrateConfigPtrType;
#endif
V_DEF_P2CONST_TYPE(V_NONE, Can_PduType, APPL_VAR) Can_PduInfoPtrType;
V_DEF_P2VAR_TYPE(V_NONE, Can_PduType, APPL_VAR)   Can_PduInfoPtrType_var;
V_DEF_P2CONST_TYPE(V_NONE, uint8, RX_TX_DATA)     Can_DataPtrType;


#if defined( C_ENABLE_ERROR_POLLING )
# define C_DISABLE_CAN_BUSOFF_INTERRUPT
#else
# define C_ENABLE_CAN_BUSOFF_INTERRUPT
#endif

#if (defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && !defined( C_ENABLE_RX_BASICCAN_POLLING )) || \
    (defined( C_ENABLE_RX_FULLCAN_OBJECTS ) && !defined( C_ENABLE_RX_FULLCAN_POLLING ))   || \
    (!defined( C_ENABLE_TX_POLLING )) || (defined( C_ENABLE_INDIVIDUAL_POLLING ))
# define C_ENABLE_CAN_RXTX_INTERRUPT
#else
# define C_DISABLE_CAN_RXTX_INTERRUPT
#endif



/* data types for driver function parameters */
/* the types of CanInitHandle, CanChannelHandle and CanObjectHandle depends
   on the compiler and controller - what generates effective code */
V_DEF_VAR_TYPE(V_NONE, vuint16) CanInitHandle;

#if !defined( CAN_GEN_COM_STACK_LIB ) /* COV_CAN_COMPATIBILITY */
V_DEF_VAR_TYPE(V_NONE, vuint16) CanChannelHandle;
#endif

/* CanObjectHandle has to be unsigned! */
# define CanObjectHandle  Can_HwHandleType

V_DEF_VAR_TYPE(V_NONE, vuint16) CanTransmitHandle;
V_DEF_VAR_TYPE(V_NONE, vuint16) CanReceiveHandle;

/* define datatype of local signed variables for message handles */


 /* ptr to msgObj & data may point to RAM or CAN cell depend on Rx or Tx and feature C_ENABLE_HWBUFFER */
 /*  so the pointers have to be the same for all (far or nothing / far also works for RAM) */
V_DEF_P2SFR_CAN_TYPE(volatile, tCanRxMsgBuffer)  tCanRxMsgBufferPtr;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint8)  CanChipDataPtr;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint8)  CanChipMsgPtr;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint8)  CanChipDataPtr8;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint8)  CanChipMsgPtr8;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint16) CanChipDataPtr16;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint16) CanChipMsgPtr16;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint32) CanChipDataPtr32;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint32) CanChipMsgPtr32;

/* up to 5 tables can be defined for the transmission ID. The type and how 
   many tables are needed depends on the CPU bus type and on the ID registers 
   of the CAN controller. E.g. a CPU with a 16-Bit bus and 2 byte ID registers 
   for standard ID needs 1 table and tCanRxId0 of type vuint16. The same CPU
   with 5 byte ID registers for extended ID needs in this case 3 tables and
   tCanRxId0 = vuint16, tCanRxId1 = vuint16 and tCanRxId2 = vuint16. */
#if defined( C_ENABLE_EXTENDED_ID )
V_DEF_VAR_TYPE(V_NONE, vuint32) tCanTxId0;
/* unused by this driver: 
typedef vuint8          tCanTxId1;
typedef vuint8          tCanTxId2;
typedef vuint8          tCanTxId3;
typedef vuint8          tCanTxId4;
*/
#else
V_DEF_VAR_TYPE(V_NONE, vuint16) tCanTxId0;
/* unused by this driver: 
typedef vuint8          tCanTxId1;
typedef vuint8          tCanTxId2;
typedef vuint8          tCanTxId3;
typedef vuint8          tCanTxId4;
*/
#endif

/* type of variable for ID type kCanIdTypeExt or kCanIdTypeStd will be assigned to 
   a variable of this type */
V_DEF_VAR_TYPE(V_NONE, vuint8) tCanIdType;

/* up to 3 tables can be defined for the reception ID. The type and how many
   tables are needed depends on the CPU bus type and on the ID registers of
   the CAN controller. E.g. a CPU with a 16-Bit bus and 2 byte ID registers 
   for standard ID needs 1 table and tCanRxId0 of type vuint16. The same CPU
   with 5 byte ID registers for extended ID needs in this case 3 tables and 
   tCanRxId0 = vuint16, tCanRxId1 = vuint16 and tCanRxId2 = vuint16. */
# if defined C_ENABLE_EXTENDED_ID
V_DEF_VAR_TYPE(V_NONE, vuint32) tCanRxId0;
# else
V_DEF_VAR_TYPE(V_NONE, vuint16) tCanRxId0;
# endif
/* unused by this driver: 
typedef vuint16          tCanRxId1;
typedef vuint16          tCanRxId2;
typedef vuint16          tCanRxId3;
typedef vuint16          tCanRxId4;
*/

#if defined( C_ENABLE_CAN_RXTX_INTERRUPT )   || \
    defined( C_ENABLE_CAN_BUSOFF_INTERRUPT ) || \
    defined( C_ENABLE_CAN_WAKEUP_INTERRUPT ) /* COV_CAN_INTERRUPT_SUPPORT */
V_DEF_VAR_TYPE(V_NONE, tCanLLCanIntOld)              tCanIntOld;
V_DEF_P2VAR_TYPE(V_NONE, tCanLLCanIntOld, V_NONE)  tCanIntOldPtr;
#endif

typedef volatile struct
{
#if defined( C_CPUTYPE_LITTLEENDIAN ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
  vuint16  timestamp; /* timestamp: reading timestamp unlocks the current locked mailbox */
  vuint16  control;   /* control, status and DLC */
#endif
  vuint32  msgID;     /* message ID */
#if defined( C_ENABLE_CAN_FD_FULL )
  vuint32  data[16];  /* message data */ 
#else
  vuint32  data[2];   /* message data */
#endif
}tCanMsgObj;
typedef volatile struct
{
#if defined( C_CPUTYPE_LITTLEENDIAN ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
  vuint16  canmaxmb;       /* 00 Maximum Message Buffer */
  vuint16  canmcr;         /* 02 Module Configuration Register */
#endif  
  vuint32  control1;       /* 04 CAN Control 1: PRESDIV, RJW, PSEG1, PSEG2, BOFF_MSK, ERR_MSK, CLK_SRC, LPB, TWRN_MSK, RWRN_MSK, SMP, BOFF_REC, T_SYNC, LBUF, LOM and PROPSEG */
  vuint32  timer;          /* 08 Timer */
  vuint32  rsv1;           /* 0C Reserved */
  vuint32  rxmgmask;       /* 10 Rx Global Mask */
  vuint32  rx14mask;       /* 14 Rx 14 Mask */
  vuint32  rx15mask;       /* 18 Rx 15 Mask */
  vuint32  ecr;            /* 1C Error Counter */
  vuint32  estat;          /* 20 Error / Status */
  vuint32  imask2;         /* 24 Interrupt Mask 2 (MB 32 - 63) Register */
  vuint32  imask1;         /* 28 Interrupt Mask 1 (MB  0 - 31) Register */
  vuint32  iflag2;         /* 2C Interrupt Flag 2 (MB 32 - 63) Register */
  vuint32  iflag1;         /* 30 Interrupt Flag 1 (MB  0 - 31) Register */
  vuint32  ctrl2;          /* 34 CAN Control 2: WRMFRZ, RFEN, TASD, MRP, RRS, EACEN */
  vuint32  esr2;           /* 38 IMB, VPS, LPTM */
  vuint32  rsv4[2];        /* 3C - 44 Reserved */
  vuint32  crcr;           /* 44 TXCRC, MBCRC */
  vuint32  rxfgmask;       /* 48 Rx FiFo global mask */
  vuint32  rxfir;          /* 4C Rx FiFo information Register */
  vuint32  cbt;            /* 50 CAN Bit Timing Register */
  vuint32  rsv5[5];        /* 54 - 68 Reserved */
  vuint32  imask4;         /* 68 Interrupt Mask 4 (MB 96 - 127) Register */
  vuint32  imask3;         /* 6C Interrupt Mask 3 (MB 64 -  95) Register */
  vuint32  iflag4;         /* 70 Interrupt Flag 4 (MB 96 - 127) Register */
  vuint32  iflag3;         /* 74 Interrupt Flag 3 (MB 64 -  95) Register */
  vuint32  rsv6[2];        /* 78 - 80 Reserved */
#if defined ( C_ENABLE_MB96TO127 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
  tCanMsgObj canObject[128];  /* Buffer for 128 messages */
#elif defined ( C_ENABLE_MB64TO95 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
  tCanMsgObj canObject[96];  /* Buffer for 96 messages */
#elif defined ( C_ENABLE_MB32TO63 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
  tCanMsgObj canObject[64];  /* Buffer for 64 messages */
#else
  tCanMsgObj canObject[32];  /* Buffer for 32 messages */
#endif
}tFlexCAN;

V_DEF_P2SFR_CAN_TYPE(V_NONE, tCanMsgObj)  tCanMsgObjPtr;
V_DEF_P2SFR_CAN_TYPE(V_NONE, tFlexCAN) tFlexCANPtr;

#if defined( C_SINGLE_RECEIVE_CHANNEL )
# if defined( C_ENABLE_UPDATE_BASE_ADDRESS ) /* COV_CAN_ENABLE_UPDATE_BASE_ADDRESS */
#  define pFlexCAN(x)     ((tFlexCANPtr)((vuint32)canLL_VirtualPtrField[0])) /* PRQA S 3453 */ /* MD_Can_3453 */
# else
#   define pFlexCAN(x)     ((tFlexCANPtr)((vuint32)Can_GetBaseAddressOfControllerConfig(0))) /* PRQA S 3453 */ /* MD_Can_3453 */
# endif
#else
#  if defined( C_ENABLE_UPDATE_BASE_ADDRESS ) /* COV_CAN_ENABLE_UPDATE_BASE_ADDRESS */
#   define pFlexCAN(x)     ((tFlexCANPtr)((vuint32)canLL_VirtualPtrField[(x)])) /* PRQA S 3453 */ /* MD_Can_3453 */
#  else
#   define pFlexCAN(x)    ((tFlexCANPtr)((vuint32)Can_GetBaseAddressOfControllerConfig(x))) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
#endif

typedef volatile struct
{
#if defined ( C_ENABLE_MB96TO127 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
  vuint32 indivRxMask[128]; /* Individual Receive Masks */  
#elif defined ( C_ENABLE_MB64TO95 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
  vuint32 indivRxMask[96]; /* Individual Receive Masks */  
#else
  vuint32 indivRxMask[64]; /* Individual Receive Masks */  
#endif
}tCanRxMask;
V_DEF_P2SFR_CAN_TYPE(V_NONE, tCanRxMask) tCanRxMaskPtr;

typedef volatile struct
{
  vuint32  rxCODE;
  vuint32  rxID;     
  vuint32  rxDATA[2];
  vuint32  rxRSVD[20];
  vuint32  rxIDTAB[128]; 
}tRXFIFO;

typedef volatile struct
{
  vuint32  gfwR;
}tGlitchFilter;

typedef volatile struct
{
  vuint32  mecr;
  vuint32  errIaR;
  vuint32  errIdpR;
  vuint32  errIppR;
  vuint32  rErrAddressR;
  vuint32  rErrDataR;
  vuint32  rErrSyndromR;
  vuint32  errStatusR;
}tParityCheck;

typedef volatile struct
{
  vuint32  dbg1;
  vuint32  dbg2;
}tDebugRegister;

typedef volatile struct
{
  vuint32  fdctrl;
  vuint32  fdcbt;
  vuint32  fdcrc;
}tCanFDRegister;

V_DEF_P2SFR_CAN_TYPE(V_NONE, tRXFIFO) tRXFIFOPtr;
V_DEF_P2SFR_CAN_TYPE(V_NONE, tGlitchFilter) tGlitchFilterPtr;
V_DEF_P2SFR_CAN_TYPE(V_NONE, tParityCheck) tParityCheckPtr;
V_DEF_P2SFR_CAN_TYPE(V_NONE, tDebugRegister) tDebugRegisterPtr;
V_DEF_P2SFR_CAN_TYPE(V_NONE, tCanFDRegister) tCanFDRegisterPtr;

#if defined( C_SINGLE_RECEIVE_CHANNEL )
# if defined( C_ENABLE_UPDATE_BASE_ADDRESS ) /* COV_CAN_ENABLE_UPDATE_BASE_ADDRESS */
#  define pRXFIFO(x)           ((tRXFIFOPtr)((vuint32)canLL_VirtualPtrField[0] + (vuint32)0x0080)) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define pCanRxMask(x)        ((tCanRxMaskPtr)((vuint32)canLL_VirtualPtrField[0] + (vuint32)0x0880)) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define pCanGlitchFilter(x)  ((tGlitchFilterPtr)((vuint32)canLL_VirtualPtrField[0] + (vuint32)0x09E0)) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define pCanParityCheck(x)   ((tParityCheckPtr)((vuint32)canLL_VirtualPtrField[0] + (vuint32)0x0AE0)) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define pDebugRegister(x)    ((tDebugRegisterPtr)((vuint32)canLL_VirtualPtrField[0] + (vuint32)0x0058)) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define pCanFDRegister(x)    ((tCanFDRegisterPtr)((vuint32)canLL_VirtualPtrField[0] + (vuint32)0x0C00)) /* PRQA S 3453 */ /* MD_Can_3453 */
# else
#   define pRXFIFO(x)           ((tRXFIFOPtr)((vuint32)Can_GetBaseAddressOfControllerConfig(0) + (vuint32)0x0080)) /* PRQA S 3453 */ /* MD_Can_3453 */
#   define pCanRxMask(x)        ((tCanRxMaskPtr)((vuint32)Can_GetBaseAddressOfControllerConfig(0) + (vuint32)0x0880)) /* PRQA S 3453 */ /* MD_Can_3453 */
#   define pCanGlitchFilter(x)  ((tGlitchFilterPtr)((vuint32)Can_GetBaseAddressOfControllerConfig(0) + (vuint32)0x09E0)) /* PRQA S 3453 */ /* MD_Can_3453 */
#   define pCanParityCheck(x)   ((tParityCheckPtr)((vuint32)Can_GetBaseAddressOfControllerConfig(0) + (vuint32)0x0AE0)) /* PRQA S 3453 */ /* MD_Can_3453 */
#   define pDebugRegister(x)    ((tDebugRegisterPtr)((vuint32)Can_GetBaseAddressOfControllerConfig(0) + (vuint32)0x0058)) /* PRQA S 3453 */ /* MD_Can_3453 */
#   define pCanFDRegister(x)    ((tCanFDRegisterPtr)((vuint32)Can_GetBaseAddressOfControllerConfig(0) + (vuint32)0x0C00)) /* PRQA S 3453 */ /* MD_Can_3453 */
# endif
#else /* C_SINGLE_RECEIVE_CHANNEL */
# if defined( C_ENABLE_UPDATE_BASE_ADDRESS ) /* COV_CAN_ENABLE_UPDATE_BASE_ADDRESS */
#  define pRXFIFO(x)           ((tRXFIFOPtr)((vuint32)canLL_VirtualPtrField[(x)] + (vuint32)0x0080)) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define pCanRxMask(x)        ((tCanRxMaskPtr)((vuint32)canLL_VirtualPtrField[(x)] + (vuint32)0x0880)) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define pCanGlitchFilter(x)  ((tGlitchFilterPtr)((vuint32)canLL_VirtualPtrField[(x)] + (vuint32)0x09E0)) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define pCanParityCheck(x)   ((tParityCheckPtr)((vuint32)canLL_VirtualPtrField[(x)] + (vuint32)0x0AE0)) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define pDebugRegister(x)    ((tDebugRegisterPtr)((vuint32)canLL_VirtualPtrField[(x)] + (vuint32)0x0058)) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define pCanFDRegister(x)    ((tCanFDRegisterPtr)((vuint32)canLL_VirtualPtrField[(x)] + (vuint32)0x0C00)) /* PRQA S 3453 */ /* MD_Can_3453 */
# else
#  define pRXFIFO(x)           ((tRXFIFOPtr)((vuint32)Can_GetBaseAddressOfControllerConfig(x) + (vuint32)0x0080)) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define pCanRxMask(x)        ((tCanRxMaskPtr)((vuint32)Can_GetBaseAddressOfControllerConfig(x) + (vuint32)0x0880)) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define pCanGlitchFilter(x)  ((tGlitchFilterPtr)((vuint32)Can_GetBaseAddressOfControllerConfig(x) + (vuint32)0x09E0)) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define pCanParityCheck(x)   ((tParityCheckPtr)((vuint32)Can_GetBaseAddressOfControllerConfig(x) + (vuint32)0x0AE0)) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define pDebugRegister(x)    ((tDebugRegisterPtr)((vuint32)Can_GetBaseAddressOfControllerConfig(x) + (vuint32)0x0058)) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define pCanFDRegister(x)    ((tCanFDRegisterPtr)((vuint32)Can_GetBaseAddressOfControllerConfig(x) + (vuint32)0x0C00)) /* PRQA S 3453 */ /* MD_Can_3453 */
# endif
#endif /* C_SINGLE_RECEIVE_CHANNEL */

#if defined ( C_SINGLE_RECEIVE_CHANNEL )
#  define CAN_INT_MASK1(x) Can_GetInterruptMask1OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#   if defined ( C_ENABLE_MB32TO63 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#    define CAN_INT_MASK2(x) Can_GetInterruptMask2OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#   endif
#  if defined ( C_ENABLE_MB64TO95 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#   define CAN_INT_MASK3(x) Can_GetInterruptMask3OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
#  if defined ( C_ENABLE_MB96TO127 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#   define CAN_INT_MASK4(x) Can_GetInterruptMask4OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
#  if defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && defined( C_ENABLE_RX_BASICCAN_POLLING )
#   define CAN_RXBASIC_POLL_MASK1(x) Can_GetRxBasicPollingMask1OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#   if defined ( C_ENABLE_MB32TO63 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#    define CAN_RXBASIC_POLL_MASK2(x) Can_GetRxBasicPollingMask2OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#   endif
#   if defined ( C_ENABLE_MB64TO95 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#    define CAN_RXBASIC_POLL_MASK3(x) Can_GetRxBasicPollingMask3OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#   endif
#   if defined ( C_ENABLE_MB96TO127 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#    define CAN_RXBASIC_POLL_MASK4(x) Can_GetRxBasicPollingMask4OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#   endif
#  endif
#  if defined( C_ENABLE_RX_FULLCAN_OBJECTS ) && defined( C_ENABLE_RX_FULLCAN_POLLING )
#   define CAN_RXFULL_POLL_MASK1(x) Can_GetRxFullPollingMask1OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#   if defined ( C_ENABLE_MB32TO63 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#    define CAN_RXFULL_POLL_MASK2(x) Can_GetRxFullPollingMask2OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#   endif
#   if defined ( C_ENABLE_MB64TO95 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#    define CAN_RXFULL_POLL_MASK3(x) Can_GetRxFullPollingMask3OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#   endif
#   if defined ( C_ENABLE_MB96TO127 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#    define CAN_RXFULL_POLL_MASK4(x) Can_GetRxFullPollingMask4OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#   endif
#  endif
#  if defined( C_ENABLE_TX_POLLING )
#   define CAN_TX_POLL_MASK1(x) Can_GetTxPollingMask1OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#   if defined ( C_ENABLE_MB32TO63 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#    define CAN_TX_POLL_MASK2(x) Can_GetTxPollingMask2OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#   endif
#   if defined ( C_ENABLE_MB64TO95 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#    define CAN_TX_POLL_MASK3(x) Can_GetTxPollingMask3OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#   endif
#   if defined ( C_ENABLE_MB96TO127 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#    define CAN_TX_POLL_MASK4(x) Can_GetTxPollingMask4OfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#   endif
#  endif
#  define RFFN_VALUE(x) Can_GetRFFNOfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define NUMBER_OF_FILTERS(x) Can_GetNumberOfFiltersOfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#  define NUMBER_OF_FULL_CONFIGURABLE_FILTERS(x) Can_GetNumberOfFullConfigurableFiltersOfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#  if defined( C_ENABLE_GLITCH_FILTER ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#   define GLITCH_FILTER_WIDTH(x) (vuint32)Can_GetGlitchFilterOfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
#  if defined ( C_ENABLE_CAN_FD_FULL )
#   define CANFD_MAILBOX_MAX_WORD_LENGTH(x) Can_GetFDMailboxMaxWordLengthOfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
#  if defined( C_ENABLE_WORKAROUND_ERR005829 )
#   define INDEX_RSVD_MB(x) Can_GetReservedMBOfControllerConfig(0) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
#  if defined ( C_ENABLE_ASYM_MAILBOXES ) /* COV_CAN_FLEXCAN3_DERIVATIVE_ASYM_MAILBOXES */
#   define NUMBER_OF_MAX_MAILBOXES(x) Can_GetNumberOfMaxMailboxesOfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
#else /* C_SINGLE_RECEIVE_CHANNEL */
# define CAN_INT_MASK1(x) Can_GetInterruptMask1OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
# if defined ( C_ENABLE_MB32TO63 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#  define CAN_INT_MASK2(x) Can_GetInterruptMask2OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
# endif
# if defined ( C_ENABLE_MB64TO95 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#  define CAN_INT_MASK3(x) Can_GetInterruptMask3OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
# endif
# if defined ( C_ENABLE_MB96TO127 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#  define CAN_INT_MASK4(x) Can_GetInterruptMask4OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
# endif
# if defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && defined( C_ENABLE_RX_BASICCAN_POLLING )
#  define CAN_RXBASIC_POLL_MASK1(x) Can_GetRxBasicPollingMask1OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
#  if defined ( C_ENABLE_MB32TO63 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#   define CAN_RXBASIC_POLL_MASK2(x) Can_GetRxBasicPollingMask2OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
#  if defined ( C_ENABLE_MB64TO95 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#   define CAN_RXBASIC_POLL_MASK3(x) Can_GetRxBasicPollingMask3OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
#  if defined ( C_ENABLE_MB96TO127 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#   define CAN_RXBASIC_POLL_MASK4(x) Can_GetRxBasicPollingMask4OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
# endif
# if defined( C_ENABLE_RX_FULLCAN_OBJECTS ) && defined( C_ENABLE_RX_FULLCAN_POLLING )
#  define CAN_RXFULL_POLL_MASK1(x) Can_GetRxFullPollingMask1OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
#  if defined ( C_ENABLE_MB32TO63 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#   define CAN_RXFULL_POLL_MASK2(x) Can_GetRxFullPollingMask2OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
#  if defined ( C_ENABLE_MB64TO95 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#   define CAN_RXFULL_POLL_MASK3(x) Can_GetRxFullPollingMask3OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
#  if defined ( C_ENABLE_MB96TO127 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#   define CAN_RXFULL_POLL_MASK4(x) Can_GetRxFullPollingMask4OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
# endif
# if defined( C_ENABLE_TX_POLLING )
#  define CAN_TX_POLL_MASK1(x) Can_GetTxPollingMask1OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
#  if defined ( C_ENABLE_MB32TO63 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#  define CAN_TX_POLL_MASK2(x) Can_GetTxPollingMask2OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
#  if defined ( C_ENABLE_MB64TO95 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#   define CAN_TX_POLL_MASK3(x) Can_GetTxPollingMask3OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
#  if defined ( C_ENABLE_MB96TO127 ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#   define CAN_TX_POLL_MASK4(x) Can_GetTxPollingMask4OfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
#  endif
# endif
# define RFFN_VALUE(x) Can_GetRFFNOfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
# define NUMBER_OF_FILTERS(x) Can_GetNumberOfFiltersOfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
# define NUMBER_OF_FULL_CONFIGURABLE_FILTERS(x) Can_GetNumberOfFullConfigurableFiltersOfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
# if defined( C_ENABLE_GLITCH_FILTER ) /* COV_CAN_FLEXCAN3_DERIVATIVE */
#  define GLITCH_FILTER_WIDTH(x) (vuint32)Can_GetGlitchFilterOfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
# endif
# if defined ( C_ENABLE_CAN_FD_FULL )
#  define CANFD_MAILBOX_MAX_WORD_LENGTH(x) Can_GetFDMailboxMaxWordLengthOfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
# endif
# if defined( C_ENABLE_WORKAROUND_ERR005829 )
#  define INDEX_RSVD_MB(x) Can_GetReservedMBOfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
# endif
# if defined ( C_ENABLE_ASYM_MAILBOXES ) /* COV_CAN_FLEXCAN3_DERIVATIVE_ASYM_MAILBOXES */
#  define NUMBER_OF_MAX_MAILBOXES(x) Can_GetNumberOfMaxMailboxesOfControllerConfig(x) /* PRQA S 3453 */ /* MD_Can_3453 */
# endif
#endif /* C_SINGLE_RECEIVE_CHANNEL */

#if defined ( C_ENABLE_CAN_FD_FULL )
# if defined C_ENABLE_UPDATE_BASE_ADDRESS
#  define LOCAL_MAILBOX_ACCESS(hwCh, hwObjHandle, structMember)     ((tCanMsgObj*)(((vuint32)(Can_GetFDMailboxMapping(Can_GetFDHwChannelIndirectionOfControllerConfig((hwCh))+(hwObjHandle))) - (vuint32)(Can_GetBaseAddressOfControllerConfig(hwCh))) + (vuint32)(canLL_VirtualPtrField[(hwCh)])))->structMember /* PRQA S 3410,3453 */ /* MD_Can_3410, MD_Can_3453 */
#  define GLOBAL_MAILBOX_ACCESS(hwCh, hwObjHandle, structMember)    ((tCanMsgObj*)(((vuint32)(Can_GetFDMailboxMapping(Can_GetFDHwChannelIndirectionOfControllerConfig((hwCh))+(hwObjHandle))) - (vuint32)(Can_GetBaseAddressOfControllerConfig(hwCh))) + (vuint32)(canLL_VirtualPtrField[(hwCh)])))->structMember /* PRQA S 3410,3453 */ /* MD_Can_3410, MD_Can_3453 */
# else
#  define LOCAL_MAILBOX_ACCESS(hwCh, hwObjHandle, structMember)     ((tCanMsgObj*)(Can_GetFDMailboxMapping(Can_GetFDHwChannelIndirectionOfControllerConfig((hwCh))+(hwObjHandle))))->structMember /* PRQA S 3410,3453 */ /* MD_Can_3410, MD_Can_3453 */
#  define GLOBAL_MAILBOX_ACCESS(hwCh, hwObjHandle, structMember)    ((tCanMsgObj*)(Can_GetFDMailboxMapping(Can_GetFDHwChannelIndirectionOfControllerConfig((hwCh))+(hwObjHandle))))->structMember /* PRQA S 3410,3453 */ /* MD_Can_3410, MD_Can_3453 */
# endif
#else
# define LOCAL_MAILBOX_ACCESS(hwCh, hwObjHandle, structMember)      pFlexCANLocal->canObject[(hwObjHandle)].structMember /* PRQA S 3410,3453 */ /* MD_Can_3410, MD_Can_3453 */
# define GLOBAL_MAILBOX_ACCESS(hwCh, hwObjHandle, structMember)     pFlexCAN((hwCh))->canObject[(hwObjHandle)].structMember /* PRQA S 3410,3453 */ /* MD_Can_3410, MD_Can_3453 */
#endif



#define CANSFR_TYPE        vuint32

/* \trace SPEC-1400 */
/***************************************************************************/
/* function prototypes / API                                               */
/***************************************************************************/
#define CAN_START_SEC_CODE  /*---------------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/************************************************************************************************************
 *  Can_InitMemory()
 ***********************************************************************************************************/
/*! \brief         Power-up memory initialization
 *  \details       Initializes component variables in *_INIT_* sections at power up. \n
 *                 Use this to re-run the system without performing a new start from power on. \n
 *                 (E.g.: used to support an ongoing debug session without a complete re-initialization.) \n
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Use this function in case these variables are not initialized by the 
 *                 start up code. \n
 *                 Must be followed by a call to "Can_Init()".
 *  \trace         CREQ-970
************************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_InitMemory( void );

/************************************************************************************************************
 *  Can_Init()
 ***********************************************************************************************************/
/*! \brief         Initializes component
 *  \details       Initializes all component variables and sets the component state to initialized.
 *  \param[in]     ConfigPtr          Component configuration structure
 *  \pre           Interrupts are disabled.
 *  \pre           Module is uninitialized.
 *  \pre           Can_InitMemory() has been called unless CAN Module is initialized by start up code.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Parameter "ConfigPtr" will be taken into account only for "Multiple ECU Configuration" and in Post-Build variant. \n
 *  \trace         CREQ-969
************************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_Init( Can_ConfigPtrType ConfigPtr );

#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR40) /* COV_CAN_MICROSAR_VERSION */
/************************************************************************************************************
 *  Can_InitController()
 ***********************************************************************************************************/
/*! \brief         Initialization of controller specific CAN hardware.
 *  \details       The CAN driver registers and variables are initialized. \n
 *                 The CAN controller is fully initialized and left back within the state "STOP Mode", ready to change to "Running Mode".
 *  \param[in]     Controller    CAN controller
 *  \param[in]     Config        Pointer to baud rate configuration structure
 *  \pre           Disabled Interrupts.
 *  \pre           Can_Init() has to be called.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_ENABLE_MICROSAR_VERSION_MSR40
 *  \notes         Has to be called during the start up sequence before CAN communication takes place. \n
 *                 Must not be called while in "SLEEP Mode".
 *  \trace         CREQ-969, CREQ-994
************************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_InitController( uint8 Controller, Can_ControllerBaudrateConfigPtrType Config );
#endif

#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR30) /* COV_CAN_MICROSAR_VERSION */
/************************************************************************************************************
 *  Can_InitController()
 ***********************************************************************************************************/
/*! \brief         Initialization of controller specific CAN hardware.
 *  \details       The CAN driver registers and variables are initialized. \n
 *                 The CAN controller is fully initialized and left back within the state "STOP Mode", ready to change to "Running Mode".
 *  \param[in]     Controller           CAN controller
 *  \param[in]     ControllerConfigPtr  Pointer to baud rate configuration structure
 *  \pre           Disabled Interrupts.
 *  \pre           Can_Init() has to be called.
 *  \pre           Controller is in STOP mode.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_ENABLE_MICROSAR_VERSION_MSR30
 *  \notes         Has to be called during the start up sequence before CAN communication takes place ". \n
 *                 Must not be called while in "SLEEP Mode".
 *  \trace         CREQ-969, CREQ-994
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_InitController( uint8 Controller, Can_ControllerConfigPtrType ControllerConfigPtr );
#endif

#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR403) /* COV_CAN_MICROSAR_VERSION */
# if ((CAN_CHANGE_BAUDRATE_API == STD_ON) || (CAN_SET_BAUDRATE_API == STD_OFF))
/************************************************************************************************************
 *  Can_ChangeBaudrate()
 ***********************************************************************************************************/
/*! \brief         Change baud rate
 *  \details       This service shall change the baud rate and reinitialize the CAN controller.
 *  \param[in]     Controller    CAN controller to be changed
 *  \param[in]     Baudrate      Baud rate to be set
 *  \return        E_NOT_OK      Baud rate is not set
 *  \return        E_OK          Baud rate is set
 *  \pre           The CAN controller must be in "STOP Mode".
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_ENABLE_MICROSAR_VERSION_MSR403 && ((CAN_CHANGE_BAUDRATE_API == STD_ON) || (CAN_SET_BAUDRATE_API == STD_OFF))
 *  \notes         Has to be called during the start up sequence before CAN communication takes place but after calling "Can_Init()".
 *  \trace         CREQ-995
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_ChangeBaudrate( uint8 Controller, V_DEF_CONST(V_NONE, uint16, APPL_CONST) Baudrate );
# endif
#endif

#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR403) /* COV_CAN_MICROSAR_VERSION */
# if (CAN_CHANGE_BAUDRATE_API == STD_ON)
/************************************************************************************************************
 *  Can_CheckBaudrate()
 ***********************************************************************************************************/
/*! \brief         Checks baud rate
 *  \details       This service shall check if the given baud rate is supported of the CAN controller.
 *  \param[in]     Controller    CAN controller to be checked
 *  \param[in]     Baudrate      Baud rate to be checked
 *  \return        E_NOT_OK      Baud rate is not available
 *  \return        E_OK          Baud rate is available
 *  \pre           The CAN controller must be initialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_ENABLE_MICROSAR_VERSION_MSR403 && (CAN_CHANGE_BAUDRATE_API == STD_ON)
 *  \trace         CREQ-995
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_CheckBaudrate( uint8 Controller, V_DEF_CONST(V_NONE, uint16, APPL_CONST) Baudrate );
# endif
#endif

#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR403) /* COV_CAN_MICROSAR_VERSION */
# if (CAN_SET_BAUDRATE_API == STD_ON)
/************************************************************************************************************
 *  Can_SetBaudrate()
 ***********************************************************************************************************/
/*! \brief         Set baud rate
 *  \details       This service shall change the baud rate and reinitialize the CAN controller. \n
 *                 (Similar to Can_ChangeBaudrate() but used when identical baud rates are used for different CAN FD settings).
 *  \param[in]     Controller        CAN controller to be set
 *  \param[in]     BaudRateConfigID  Identity of the configured baud rate (available as Symbolic Name)
 *  \return        E_NOT_OK      Baud rate is not set
 *  \return        E_OK          Baud rate is set
 *  \pre           The CAN controller must be in "STOP Mode".
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_ENABLE_MICROSAR_VERSION_MSR403 && (CAN_SET_BAUDRATE_API == STD_ON)
 *  \trace         CREQ-995
***********************************************************************************************************/
/* \trace SPEC-50605 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_SetBaudrate( uint8 Controller, uint16 BaudRateConfigID );
# endif
#endif


#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR30) /* COV_CAN_MICROSAR_VERSION */
/************************************************************************************************************
 *  Can_InitStruct()
 ***********************************************************************************************************/
/*! \brief         Set active initialization structure
 *  \details       Set content of the initialization structure (before calling Can_InitController()).   \n
 *                 Service function to change the initialization structure set up left behind by the Generation Tool.  \n
 *                 The structure contains information about baud rate and filter settings.  \n
 *                 Subsequent Can_InitController() must be called to activate these settings.
 *  \param[in]     Controller   CAN controller to be changed 
 *  \param[in]     Index        Index of the initialization structure to be used for baud rate and mask settings
 *  \pre           Can_Init() was called.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_ENABLE_MICROSAR_VERSION_MSR30
 *  \notes         Call this function between calling "Can_Init()" and "Can_InitController()".\n
 *                 None AUTOSAR API
 *  \trace         CREQ-995
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_InitStruct( uint8 Controller, uint8 Index );
#endif

#if (CAN_VERSION_INFO_API == STD_ON) /* BR:007 */
/************************************************************************************************************
 *  Can_GetVersionInfo()
 ***********************************************************************************************************/
/*! \brief         Returns the version information
 *  \details       Returns version information (MICROSAR3: BCD coded), vendor ID and AUTOSAR module ID 
 *                 ( MICROSAR3: instance ID) of the component.
 *  \param[out]    VersionInfo    Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        CAN_VERSION_INFO_API == STD_ON
 *  \trace         CREQ-991
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_GetVersionInfo( Can_VersionInfoPtrType VersionInfo );
#endif

#if (CAN_GET_STATUS == STD_ON)
/************************************************************************************************************
 *  Can_GetStatus()
 ***********************************************************************************************************/
/*! \brief         Get status/mode of the given controller
 *  \details       Delivers the status of the hardware, as a bit coded value where multiple bits may be set.
 *  \param[in]     Controller   CAN controller requested for status information
 *  \return        CAN_STATUS_START            START mode
 *  \return        CAN_STATUS_STOP             STOP mode
 *  \return        CAN_STATUS_INIT             Initialized controller
 *  \return        CAN_STATUS_INCONSISTENT     STOP or SLEEP are inconsistent over common CAN controllers
 *  \return        CAN_DEACTIVATE_CONTROLLER   RAM check failed CAN controller is deactivated
 *  \return        CAN_STATUS_WARNING          WARNING state
 *  \return        CAN_STATUS_PASSIVE          PASSIVE state
 *  \return        CAN_STATUS_BUSOFF           BUSOFF mode
 *  \return        CAN_STATUS_SLEEP            SLEEP mode
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        CAN_GET_STATUS == STD_ON
 *  \notes         the return value can be analysed using the provided API macros: \n
                   CAN_HW_IS_OK(), CAN_HW_IS_WARNING(), CAN_HW_IS_PASSIVE() \n
                   CAN_HW_IS_BUSOFF(), CAN_HW_IS_WAKEUP(), CAN_HW_IS_SLEEP()\n
                   CAN_HW_IS_STOP(), CAN_HW_IS_START(), CAN_HW_IS_INCONSISTENT()\n
                   None AUTOSAR API
 *  \trace         CREQ-978
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, uint8, CODE) Can_GetStatus( uint8 Controller );
#endif

/************************************************************************************************************
 *  Can_SetControllerMode()
 ***********************************************************************************************************/
/*! \brief         Change the controller mode
 *  \details       Request a mode transition witch processed synchronous for MICROSAR3 and return the success. \n
 *                 Or do it asynchronous for MICROSAR4 and call a notification when successful. BUSOFF, WAKEUP and \n
 *                 RAM check will be handled as well.
 *  \param[in]     Controller    CAN controller to be set
 *  \param[in]     Transition    Requested transition to destination mode CAN_T_START, CAN_T_STOP, CAN_T_SLEEP, CAN_T_WAKEUP
 *  \return        CAN_NOT_OK    MICROSAR3: mode change unsuccessful - MICROSAR4: transition request rejected
 *  \return        CAN_OK        MICROSAR3: mode change successful - MICROSAR4: transition request accepted
 *  \pre           Interrupts locked
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   FALSE - MICROSAR3: synchronous
 *  \notes         Must not be called within CAN driver context like RX, TX or BUSOFF call out.
 *  \trace         CREQ-978
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Can_ReturnType, CODE) Can_SetControllerMode( uint8 Controller, Can_StateTransitionType Transition );

/************************************************************************************************************
 *  Can_ResetBusOffStart()
 ***********************************************************************************************************/
/*! \brief         Start BUSOFF handling
 *  \details       This is a compatibility function (for a CANbedded protocol stack) used during the start of the \n
 *                 BUSOFF handling to remove the BUSOFF state.
 *  \param[in]     Controller   CAN controller
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_BUSOFF_SUPPORT_API == STD_ON
 *  \notes         Has to be called inside BUSOFF notification. \n
 *                 Empty function when not configured. \n
 *                 None AUTOSAR API
 *  \trace         CREQ-984
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_ResetBusOffStart( uint8 Controller );

/************************************************************************************************************
 *  Can_ResetBusOffEnd()
 ***********************************************************************************************************/
/*! \brief         Finish BUSOFF handling
 *  \details       This is a compatibility function (for a CANbedded protocol stack) used during the end of the \n
 *                 BUSOFF handling to remove the BUSOFF state.
 *  \param[in]     Controller   CAN controller
 *  \pre           Has to be called after Can_ResetBusOffStart().
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_BUSOFF_SUPPORT_API == STD_ON
 *  \notes         The call should be done 128*11 recessive CAN bit times later because the call may wait this time to handle BUSOFF. \n
 *                 No nesting of Can_SetControllerMode() and  Can_ResetBusOffEnd() is allowed. \n
 *                 Empty function when not configured. \n
 *                 None AUTOSAR API
 *  \trace         CREQ-984
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_ResetBusOffEnd( uint8 Controller );

/************************************************************************************************************
 *  Can_Write()
 ***********************************************************************************************************/
/*! \brief         Send a CAN message
 *  \details       copy data, DLC and ID to the send mailbox and request a transmission.
 *  \param[in]     Hth           Handle of the mailbox intended to send the message
 *  \param[in]     PduInfo       Information about the outgoing message (ID, dataLength, data)
 *  \return        CAN_NOT_OK    transmit request rejected
 *  \return        CAN_OK        transmit request successful
 *  \return        CAN_BUSY      transmit request could not be accomplished due to the controller is busy.
 *  \pre           disabled CAN interrupts / interrupts locked (Refer to critical section).
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \trace         CREQ-971
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Can_ReturnType, CODE) Can_Write( Can_HwHandleType Hth, Can_PduInfoPtrType PduInfo );

/************************************************************************************************************
 *  Can_CancelTx()
 ***********************************************************************************************************/
/*! \brief         Cancel TX message
 *  \details       Cancel the TX message in the hardware buffer (if possible) or mark the message as not to be confirmed \n
 *                 in case of the cancellation is unsuccessful.
 *  \param[in]     Hth     Handle of the mailbox intended to be cancelled.
 *  \param[in]     PduId   PDU identifier
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Do not call this API within TX confirmation context. Otherwise confirmation will occur for already
 *                 cancelled messages. Only one message will be cancelled, if there are multiple requests also multiple cancellations expected.\n
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_CancelTx( Can_HwHandleType Hth, PduIdType PduId );

#if defined(C_ENABLE_MIRROR_MODE)
/************************************************************************************************************
 *  Can_SetMirrorMode()
 ***********************************************************************************************************/
/*! \brief         Activate mirror mode 
 *  \details       Switch the Appl_GenericPreCopy/Confirmation function ON or OFF.
 *  \param[in]     Controller   CAN controller
 *  \param[in]     mirrorMode   Activate or deactivate the mirror mode.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        C_ENABLE_MIRROR_MODE (user configuration file)
 *  \notes         Called by "Mirror Mode" CDD.\n
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_SetMirrorMode( uint8 Controller, CddMirror_MirrorModeType mirrorMode );
#endif

#if defined(C_ENABLE_SILENT_MODE)
/************************************************************************************************************
 *  Can_SetSilentMode()
 ***********************************************************************************************************/
/*! \brief         Activate and deactivate the silent mode
 *  \details       Switch to silent mode, as a listen only mode without ACK. Also deactivate this mode again.
 *  \param[in]     Controller   CAN controller
 *  \param[in]     silentMode   Activate or deactivate the silent mode CAN_SILENT_INACTIVE, CAN_SILENT_ACTIVE (Enumaration).
 *  \return        E_OK         mode change successful
 *  \return        CAN_OK       mode change failed
 *  \pre           The CAN controller must be in "STOP Mode".
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_SILENT_MODE == STD_ON
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_SetSilentMode( uint8 Controller, Can_SilentModeType silentMode );
#endif

/************************************************************************************************************
 *  Can_CheckWakeup()
 ***********************************************************************************************************/
/*! \brief         Check WAKEUP occur
 *  \details       Check the occurrence of WAKEUP events for the given controller \n
 *                 (used as WAKEUP callback for higher layers).
 *  \param[in]     Controller    CAN controller to be checked for WAKEUP events.
 *  \return        E_OK      the given controller caused a WAKEUP before.
 *  \return        E_NOT_OK  the given controller caused no WAKEUP before.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         MICROSAR3: Can_Cbk_CheckWakeup() will be mapped to this function.
 *  \trace         CREQ-983
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_CheckWakeup( uint8 Controller );
#define Can_Cbk_CheckWakeup Can_CheckWakeup /* compatibility to AutoSar3 */

/************************************************************************************************************
 *  Can_DisableControllerInterrupts()
 ***********************************************************************************************************/
/*! \brief         Disable CAN interrupts
 *  \details       Disable the CAN interrupt for the given controller (e.g. due to data consistency reasons).
 *  \param[in]     Controller    CAN controller to disable interrupts for.
 *  \pre           Must not be called while CAN controller is in SLEEP mode.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Called within Critical Area handling or out of Application code.
 *  \trace         CREQ-988
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_DisableControllerInterrupts( uint8 Controller );

/************************************************************************************************************
 *  Can_EnableControllerInterrupts()
 ***********************************************************************************************************/
/*! \brief         Enable CAN interrupts
 *  \details       Re-enable the CAN interrupt for the given controller (e.g. due to data consistency reasons).
 *  \param[in]     Controller    CAN controller to enable interrupts for.
 *  \pre           Must not be called while CAN controller is in SLEEP mode.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Called within Critical Area handling or out of Application code.
 *  \trace         CREQ-988
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_EnableControllerInterrupts( uint8 Controller );

/* polling functions (always available for non polled systems also) */
#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR30) || defined(CAN_API_SCAN) /* MICROSAR4: prototype by SchM-header */ /* COV_CAN_MICROSAR_VERSION */
/************************************************************************************************************
 *  Can_MainFunction_Write()
 ***********************************************************************************************************/
/*! \brief         TX message observation
 *  \details       Polling TX events (confirmation, cancellation) for all controllers and all TX mailboxes \n
 *                 to accomplish the TX confirmation handling (like CanInterface notification).
 *  \pre           Must not interrupt the call of Can_Write(). CAN driver has to be initialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Empty function in case no polling is active.
 *  \trace         CREQ-979
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Write( void );

/************************************************************************************************************
 *  Can_MainFunction_Read()
 ***********************************************************************************************************/
/*! \brief         RX message observation
 *  \details       Polling RX events for all controllers and all RX mailboxes to accomplish the \n
 *                 RX indication handling (like CanInterface notification). \n
 *                 Also used for a delayed read (from task level) of the RX Queue messages which were queued from interrupt context.
 *  \pre           CAN driver has to be initialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Empty function in case no polling is active.
 *  \trace         CREQ-979
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Read( void );

/************************************************************************************************************
 *  Can_MainFunction_BusOff()
 ***********************************************************************************************************/
/*! \brief         BUSOFF observation
 *  \details       Polling of BUSOFF events to accomplish the BUSOFF handling.
 *                 Service function to poll BUSOFF events for all controllers to accomplish the BUSOFF handling \n
 *                 (like calling of CanIf_ControllerBusOff() in case of BUSOFF occurrence).
 *  \pre           CAN driver has to be initialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Empty function in case no polling is active.
 *  \trace         CREQ-979
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_BusOff( void );

/************************************************************************************************************
 *  Can_MainFunction_Wakeup()
 ***********************************************************************************************************/
/*! \brief         WAKEUP observation
 *  \details       Polling WAKEUP events for all controllers to accomplish the WAKEUP handling \n
 *                 (like calling of "CanIf_SetWakeupEvent()" in case of WAKEUP occurrence).
 *  \pre           CAN driver has to be initialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Empty function in case no polling is active.
 *  \trace         CREQ-983
 *  \trace         CREQ-979
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Wakeup( void );
#endif

#if defined(CAN_API_SCAN) /* MICROSAR4: prototype by SchM-header */ /* COV_CAN_INTERNAL */
/************************************************************************************************************
 *  Can_MainFunction_Mode()
 ***********************************************************************************************************/
/*! \brief         Mode transition observation
 *  \details       Polling Mode changes over all controllers. \n
                   (This is handled asynchronous if not accomplished in "Can_SetControllerMode()")
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        MICROSAR4x only
 *  \trace         CREQ-978
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Mode( void );
#endif

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
/************************************************************************************************************
 *  Can_RamCheckExecute()
 ***********************************************************************************************************/
/*! \brief         Start checking the CAN cells RAM
 *  \details       Check all controller specific and mailbox specific registers by write patterns and read back.
 *                 Issue notification will appear in this context.
 *  \param[in]     Controller    CAN controller to be checked.
 *  \pre           Has to be called within STOP mode.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_RAM_CHECK == CAN_EXTENDED
 *  \trace         CREQ-106641
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckExecute( uint8 Controller );

/************************************************************************************************************
 *  Can_RamCheckEnableMailbox()
 ***********************************************************************************************************/
/*! \brief         Reactivate a mailbox after RamCheck failed.
 *  \details       Mailbox will be reactivated by clear deactivation flag.
 *  \param[in]     htrh    CAN mailbox to be reactivated.
 *  \pre           Has to be called within STOP mode after RamCheck failed (controller is deactivated).
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         must be followed by Can_RamCheckEnableController() to activate mailbox and controller.
 *  \config        CAN_RAM_CHECK == CAN_EXTENDED
 *  \trace         CREQ-106641
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckEnableMailbox( Can_HwHandleType htrh );

/************************************************************************************************************
 *  Can_RamCheckEnableController()
 ***********************************************************************************************************/
/*! \brief         Reactivate CAN cells after RamCheck failed.
 *  \details       CAN cell will be reactivated by execute reinitialization.
 *  \param[in]     Controller    CAN controller to be reactivated.
 *  \pre           Has to be called within STOP mode after RamCheck failed (controller is deactivated).
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_RAM_CHECK == CAN_EXTENDED
 *  \trace         CREQ-106641
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckEnableController( uint8 Controller );
#endif

/* Platform specific API */

/* ISR prototypes (see can_irq.c) */

/* Possibility to disable the prototypes of interrupt service routines in the driver configuration header file.  */
# if !(defined( C_ENABLE_ISR_PROTOTYPE) || defined( C_DISABLE_ISR_PROTOTYPE ))
#  define C_ENABLE_ISR_PROTOTYPE
# endif


#if defined (C_ENABLE_ISR_PROTOTYPE)
# if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2) /* COV_CAN_OS_USAGE */
/* ISR prototypes must be provided by OSEK header file */
# else

#if defined( V_CPU_IMX ) || defined( V_CPU_VYBRID ) /* COV_CAN_FLEXCAN3_ARM32_DERIVATIVE */
# if defined( kCanPhysToLogChannelIndex_0 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
#  if defined( C_ENABLE_CAN_RXTX_INTERRUPT )   || \
      defined( C_ENABLE_CAN_BUSOFF_INTERRUPT ) || \
      defined( C_ENABLE_CAN_WAKEUP_INTERRUPT ) /* COV_CAN_INTERRUPT_SUPPORT */
/* CODE CATEGORY 1 START */
/************************************************************************************************************
 *  CanIsr_0()
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for events on CAN_0.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        C_ENABLE_CAN_RXTX_INTERRUPT || C_ENABLE_CAN_BUSOFF_INTERRUPT || C_ENABLE_CAN_WAKEUP_INTERRUPT
 *  \pre           -
 ***********************************************************************************************************/
V_DEF_FUNC_API(V_NONE, void, CODE) CanIsr_0( void );
/* CODE CATEGORY 1 END */
#  endif
# endif /* kCanPhysToLogChannelIndex_0 */ 
# if defined( kCanPhysToLogChannelIndex_1 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
#  if defined( C_ENABLE_CAN_RXTX_INTERRUPT )   || \
      defined( C_ENABLE_CAN_BUSOFF_INTERRUPT ) || \
      defined( C_ENABLE_CAN_WAKEUP_INTERRUPT ) /* COV_CAN_INTERRUPT_SUPPORT */
/* CODE CATEGORY 1 START */
/************************************************************************************************************
 *  CanIsr_1()
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for events on CAN_1.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        C_ENABLE_CAN_RXTX_INTERRUPT || C_ENABLE_CAN_BUSOFF_INTERRUPT || C_ENABLE_CAN_WAKEUP_INTERRUPT
 *  \pre           -
 ***********************************************************************************************************/
V_DEF_FUNC_API(V_NONE, void, CODE) CanIsr_1( void );
/* CODE CATEGORY 1 END */
#  endif
# endif /* kCanPhysToLogChannelIndex_1 */ 
# if defined( kCanPhysToLogChannelIndex_2 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
#  if defined( C_ENABLE_CAN_RXTX_INTERRUPT )   || \
      defined( C_ENABLE_CAN_BUSOFF_INTERRUPT ) || \
      defined( C_ENABLE_CAN_WAKEUP_INTERRUPT ) /* COV_CAN_INTERRUPT_SUPPORT */
/* CODE CATEGORY 1 START */
/************************************************************************************************************
 *  CanIsr_2()
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for events on CAN_2.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        C_ENABLE_CAN_RXTX_INTERRUPT || C_ENABLE_CAN_BUSOFF_INTERRUPT || C_ENABLE_CAN_WAKEUP_INTERRUPT
 *  \pre           -
 ***********************************************************************************************************/
V_DEF_FUNC_API(V_NONE, void, CODE) CanIsr_2( void );
/* CODE CATEGORY 1 END */
#  endif
# endif /* kCanPhysToLogChannelIndex_2 */ 
# if defined( kCanPhysToLogChannelIndex_3 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
#  if defined( C_ENABLE_CAN_RXTX_INTERRUPT )   || \
      defined( C_ENABLE_CAN_BUSOFF_INTERRUPT ) || \
      defined( C_ENABLE_CAN_WAKEUP_INTERRUPT ) /* COV_CAN_INTERRUPT_SUPPORT */
/* CODE CATEGORY 1 START */
/************************************************************************************************************
 *  CanIsr_3()
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for events on CAN_3.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        C_ENABLE_CAN_RXTX_INTERRUPT || C_ENABLE_CAN_BUSOFF_INTERRUPT || C_ENABLE_CAN_WAKEUP_INTERRUPT
 *  \pre           -
 ***********************************************************************************************************/
V_DEF_FUNC_API(V_NONE, void, CODE) CanIsr_3( void );
/* CODE CATEGORY 1 END */
#  endif
# endif /* kCanPhysToLogChannelIndex_3 */ 
#endif /* V_CPU_IMX */

#if defined( V_CPU_S32 ) /* COV_CAN_FLEXCAN3_ARM32_DERIVATIVE */
# if defined( kCanPhysToLogChannelIndex_0 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
#  if defined( C_ENABLE_CAN_BUSOFF_INTERRUPT )
/* CODE CATEGORY 1 START */
/************************************************************************************************************
 *  CanBusOffIsr_0()
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for BUSOFF event on CAN_0.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        C_ENABLE_CAN_BUSOFF_INTERRUPT
 *  \pre           -
 ***********************************************************************************************************/
V_DEF_FUNC_API(V_NONE, void, CODE) CanBusOffIsr_0( void );
/* CODE CATEGORY 1 END */
#  endif
#  if defined( C_ENABLE_CAN_RXTX_INTERRUPT )
/* CODE CATEGORY 1 START */
/************************************************************************************************************
 *  CanMailboxIsr_0()
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for transmission and reception events on CAN_0.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        C_ENABLE_CAN_RXTX_INTERRUPT
 *  \pre           -
 ***********************************************************************************************************/
V_DEF_FUNC_API(V_NONE, void, CODE) CanMailboxIsr_0( void );
/* CODE CATEGORY 1 END */
#  endif
# endif /* kCanPhysToLogChannelIndex_0 */ 
# if defined( kCanPhysToLogChannelIndex_1 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
#  if defined( C_ENABLE_CAN_BUSOFF_INTERRUPT )
/* CODE CATEGORY 1 START */
/************************************************************************************************************
 *  CanBusOffIsr_1()
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for BUSOFF event on CAN_1.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        C_ENABLE_CAN_BUSOFF_INTERRUPT
 *  \pre           -
 ***********************************************************************************************************/
V_DEF_FUNC_API(V_NONE, void, CODE) CanBusOffIsr_1( void );
/* CODE CATEGORY 1 END */
#  endif
#  if defined( C_ENABLE_CAN_RXTX_INTERRUPT )
/* CODE CATEGORY 1 START */
/************************************************************************************************************
 *  CanMailboxIsr_1()
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for transmission and reception events on CAN_1.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        C_ENABLE_CAN_RXTX_INTERRUPT
 *  \pre           -
 ***********************************************************************************************************/
V_DEF_FUNC_API(V_NONE, void, CODE) CanMailboxIsr_1( void );
/* CODE CATEGORY 1 END */
#  endif
# endif /* kCanPhysToLogChannelIndex_1 */ 
# if defined( kCanPhysToLogChannelIndex_2 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
#  if defined( C_ENABLE_CAN_BUSOFF_INTERRUPT )
/* CODE CATEGORY 1 START */
/************************************************************************************************************
 *  CanBusOffIsr_2()
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for BUSOFF event on CAN_2.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        C_ENABLE_CAN_BUSOFF_INTERRUPT
 *  \pre           -
 ***********************************************************************************************************/
V_DEF_FUNC_API(V_NONE, void, CODE) CanBusOffIsr_2( void );
/* CODE CATEGORY 1 END */
#  endif
#  if defined( C_ENABLE_CAN_RXTX_INTERRUPT )
/* CODE CATEGORY 1 START */
/************************************************************************************************************
 *  CanMailboxIsr_2()
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for transmission and reception events on CAN_2.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        C_ENABLE_CAN_RXTX_INTERRUPT
 *  \pre           -
 ***********************************************************************************************************/
V_DEF_FUNC_API(V_NONE, void, CODE) CanMailboxIsr_2( void );
/* CODE CATEGORY 1 END */
#  endif
# endif /* kCanPhysToLogChannelIndex_2 */ 
# if defined( kCanPhysToLogChannelIndex_3 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
#  if defined( C_ENABLE_CAN_BUSOFF_INTERRUPT )
/* CODE CATEGORY 1 START */
/************************************************************************************************************
 *  CanBusOffIsr_3()
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for BUSOFF event on CAN_3.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        C_ENABLE_CAN_BUSOFF_INTERRUPT
 *  \pre           -
 ***********************************************************************************************************/
V_DEF_FUNC_API(V_NONE, void, CODE) CanBusOffIsr_3( void );
/* CODE CATEGORY 1 END */
#  endif
#  if defined( C_ENABLE_CAN_RXTX_INTERRUPT )
/* CODE CATEGORY 1 START */
/************************************************************************************************************
 *  CanMailboxIsr_3()
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for transmission and reception events on CAN_3.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        C_ENABLE_CAN_RXTX_INTERRUPT
 *  \pre           -
 ***********************************************************************************************************/
V_DEF_FUNC_API(V_NONE, void, CODE) CanMailboxIsr_3( void );
/* CODE CATEGORY 1 END */
#  endif
# endif /* kCanPhysToLogChannelIndex_3 */ 
#endif /* V_CPU_MPC5700 */

# endif
#endif /* C_ENABLE_ISR_PROTOTYPE */


#if defined( V_CPU_IMX ) || defined ( V_CPU_VYBRID ) /* COV_CAN_FLEXCAN3_ARM32_DERIVATIVE */
#if defined( C_ENABLE_CAN_RXTX_INTERRUPT )   || \
    defined( C_ENABLE_CAN_BUSOFF_INTERRUPT ) || \
    defined( C_ENABLE_CAN_WAKEUP_INTERRUPT ) /* COV_CAN_INTERRUPT_SUPPORT */
/* CODE CATEGORY 1 START */
/************************************************************************************************************
 *  CanInterrupt()
 ***********************************************************************************************************/
/*! \brief         Handles all interrupt events.
 *  \details       Checks interrupt events and calls the indication or confirmation function.
 *  \param[in]     Controller          CAN controller (configuration dependent)
 *  \context       ISR1|ISR2
 *  \reentrant     TRUE for different handles
 *  \synchronous   TRUE
 *  \config        C_ENABLE_CAN_RXTX_INTERRUPT || C_ENABLE_CAN_BUSOFF_INTERRUPT || C_ENABLE_CAN_WAKEUP_INTERRUPT
 *  \pre           -
 ***********************************************************************************************************/
V_DEF_FUNC_API(V_NONE, void, CODE) CanInterrupt( CAN_HW_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 1 END */
#endif
#endif

#if defined ( V_CPU_S32 ) /* COV_CAN_FLEXCAN3_ARM32_DERIVATIVE */
#if defined( C_ENABLE_CAN_BUSOFF_INTERRUPT )
/* CODE CATEGORY 1 START */
/************************************************************************************************************
 *  CanBusOffInterrupt()
 ***********************************************************************************************************/
/*! \brief         Handles BUSOFF interrupt events.
 *  \details       Calls error handling.
 *  \param[in]     Controller          CAN controller (configuration dependent)
 *  \context       ISR1|ISR2
 *  \reentrant     TRUE for different handles
 *  \synchronous   TRUE
 *  \config        C_ENABLE_CAN_BUSOFF_INTERRUPT
 *  \pre           -
 ***********************************************************************************************************/
V_DEF_FUNC_API(V_NONE, void, CODE) CanBusOffInterrupt( CAN_HW_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 1 END */
#endif
#if defined( C_ENABLE_CAN_RXTX_INTERRUPT )
/* CODE CATEGORY 1 START */
/************************************************************************************************************
 *  CanMailboxInterrupt()
 ***********************************************************************************************************/
/*! \brief         Handles transmission and reception interrupt events.
 *  \details       Checks interrupt events and calls the indication or confirmation function.
 *  \param[in]     Controller          CAN controller (configuration dependent)
 *  \context       ISR1|ISR2
 *  \reentrant     TRUE for different handles
 *  \synchronous   TRUE
 *  \config        C_ENABLE_CAN_RXTX_INTERRUPT
 *  \pre           -
 ***********************************************************************************************************/
V_DEF_FUNC_API(V_NONE, void, CODE) CanMailboxInterrupt( CAN_HW_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 1 END */
#endif
#endif

#if !defined( C_ENABLE_PROTECTED_RX_PROCESS ) && !defined( C_DISABLE_PROTECTED_RX_PROCESS )
# define C_ENABLE_PROTECTED_RX_PROCESS
#endif


#define CAN_STOP_SEC_CODE  /*------------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define CAN_START_SEC_CODE_APPL  /*----------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (CAN_GENERIC_PRECOPY == STD_ON)
/************************************************************************************************************
 *  Appl_GenericPrecopy()
 ***********************************************************************************************************/
/*! \brief         Common RX indication callback that will be called before message specific callback will be called.
 *  \details       Application callback function which informs about all incoming RX messages including the contained data. \n
 *                 It can be used to block notification to upper layer. E.g. to filter incoming messages or route it for special handling.
 *  \param[in]     Controller   CAN controller which received the message.
 *  \param[in]     ID           ID of the received message (include IDE,FD). \n
 *                              In case of extended or mixed ID systems the highest bit (bit 31) is set to mark an extended ID. \n
 *                              FD-bit (bit 30) can be masked out with user define CAN_ID_MASK_IN_GENERIC_CALLOUT.
 *  \param[in]     DataLength   Data length of the received message.
 *  \param[in]     pData        Pointer to the data of the received message (read only).
 *  \return        CAN_OK       Higher layer indication will be called afterwards (CanIf_RxIndication()).
 *  \return        CAN_NOT_OK   Higher layer indication will not be called afterwards.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_GENERIC_PRECOPY == STD_ON
 *  \notes         "pData" is read only and must not be accessed for further write operations. \n
 *                 The parameter DataLength refers to the received data length by the CAN controller hardware.\n
 *                 Note, that the CAN protocol allows the usage of data length values greater than eight (CAN-FD).\n
 *                 Depending on the implementation of this callback it may be necessary to consider this special case (e.g. if the data length is used as index value in a buffer write access).
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, Can_ReturnType, APPL_CODE) Appl_GenericPrecopy( uint8 Controller, Can_IdType ID, uint8 DataLength, Can_DataPtrType DataPtr );
#endif

#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API1)
/************************************************************************************************************
 *  Appl_GenericConfirmation()
 ***********************************************************************************************************/
/*! \brief         Common TX notification callback that will be called before message specific callback will be called.
 *  \details       Application callback function which informs about TX messages being sent to the CAN bus.
 *                 It can be used to block confirmation or route the information to other layer as well.
 *  \param[in]     PduId       Handle of the PDU specifying the message.
 *  \return        CAN_OK      Higher layer confirmation will be called afterwards (CanIf_TxConfirmation()).
 *  \return        CAN_NOT_OK  Higher layer confirmation will not be called afterwards.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_GENERIC_CONFIRMATION == STD_ON
 *  \notes         "PduId" is read only and must not be accessed for further write operations. \n
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, Can_ReturnType, APPL_CODE) Appl_GenericConfirmation( PduIdType PduId );
#endif

#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
/************************************************************************************************************
 *  Appl_GenericConfirmation()
 ***********************************************************************************************************/
/*! \brief         Common TX notification callback that will be called before message specific callback will be called.
 *  \details       Application callback function which informs about TX messages being sent to the CAN bus.
 *                 It can be used to block confirmation or route the information to other layer as well.
 *  \param[in]     Controller  CAN controller which send the message.
 *  \param[in]     DataPtr     Pointer to a Can_PduType structure including ID (include IDE,FD), DataLength, PDU and data pointer.
 *  \return        CAN_OK      Higher layer (CanInterface) confirmation will be called.
 *  \return        CAN_NOT_OK  No further higher layer (CanInterface) confirmation will be called.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_GENERIC_CONFIRMATION == CAN_API2
 *  \notes         A new transmission within this call out will corrupt the DataPtr context. \n
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, Can_ReturnType, APPL_CODE) Appl_GenericConfirmation( uint8 Controller, Can_PduInfoPtrType DataPtr );
#endif

#if (CAN_GENERIC_PRETRANSMIT == STD_ON)
/************************************************************************************************************
 *  Appl_GenericPreTransmit()
 ***********************************************************************************************************/
/*! \brief         Common transmit callback.
 *  \details       Application callback function allowing the modification of the data to be transmitted (e.g.: add CRC).
 *  \param[in]     Controller  CAN controller on which the message will be send.
 *  \param[in]     DataPtr     Pointer to a Can_PduType structure including ID (include IDE,FD), DataLength, PDU and data pointer.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_GENERIC_PRETRANSMIT == STD_ON
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, void, APPL_CODE) Appl_GenericPreTransmit( uint8 Controller, Can_PduInfoPtrType_var DataPtr );
#endif

#if (defined(CAN_ENABLE_MICROSAR_VERSION_MSR40X) ) || defined(C_ENABLE_HW_LOOP_TIMER) /* always used for sync mode */ /* COV_CAN_MICROSAR_VERSION */
# if (CAN_HW_LOOP_SUPPORT_API == STD_ON)
/************************************************************************************************************
 *  ApplCanTimerStart()
 ***********************************************************************************************************/
/*! \brief         Start time out monitoring
 *  \details       Service function to start an observation timer.
 *  \param[in]     Controller  CAN controller on which the hardware observation takes place. \n
 *                             (only if not using "Optimize for one controller")
 *  \param[in]     source      Source for the hardware observation.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        (CAN_HW_LOOP_SUPPORT_API == STD_ON) && ((CAN_HARDWARE_CANCELLATION == STD_ON) || MICROSAR4)
 *  \notes         Please refer to chapter "Hardware Loop Check". \n
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, APPL_CODE) ApplCanTimerStart( CAN_CHANNEL_CANTYPE_FIRST uint8 source );

/************************************************************************************************************
 *  ApplCanTimerLoop()
 ***********************************************************************************************************/
/*! \brief         Time out monitoring
 *  \details       Service function to check (against generated maximum loop value) whether a hardware loop shall be continued or broken.
 *  \param[in]     Controller  CAN controller on which the hardware observation takes place. \n
 *                             (only if not using "Optimize for one controller")
 *  \param[in]     source      Source for the hardware observation.
 *  \return        CAN_NOT_OK  when loop shall be broken (observation stops) \n
 *                             CAN_NOT_OK should only be used in case of a time out occurs due to a hardware issue. \n
 *                             After this an appropriate error handling is needed (see chapter Hardware Loop Check / Time out Monitoring).
 *  \return        CAN_OK      when loop shall be continued (observation continues)
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        (CAN_HW_LOOP_SUPPORT_API == STD_ON) && ((CAN_HARDWARE_CANCELLATION == STD_ON) || MICROSAR4)
 *  \notes         Please refer to chapter "Hardware Loop Check". \n
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Can_ReturnType, APPL_CODE) ApplCanTimerLoop( CAN_CHANNEL_CANTYPE_FIRST uint8 source );

/************************************************************************************************************
 *  ApplCanTimerEnd()
 ***********************************************************************************************************/
/*! \brief         Stop time out monitoring
 *  \details       Service function to to end an observation timer.
 *  \param[in]     Controller  CAN controller on which the hardware observation takes place. \n
 *                             (only if not using "Optimize for one controller")
 *  \param[in]     source      Source for the hardware observation.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        (CAN_HW_LOOP_SUPPORT_API == STD_ON) && ((CAN_HARDWARE_CANCELLATION == STD_ON) || MICROSAR4)
 *  \notes         Please refer to chapter "Hardware Loop Check". \n
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, APPL_CODE) ApplCanTimerEnd( CAN_CHANNEL_CANTYPE_FIRST uint8 source );
# endif
#endif

#if (CAN_INTLOCK != CAN_DRIVER)
/************************************************************************************************************
 *  ApplCanInterruptDisable()
 ***********************************************************************************************************/
/*! \brief         CAN interrupt disabling by application
 *  \details       Disabling of CAN Interrupts by the application. \n
 *                 E.g.: the CAN driver itself should not access the common Interrupt Controller due to application \n
 *                 specific restrictions (like security level). Or the application like to be informed because of \n
 *                 an CAN interrupt lock. called by Can_DisableControllerInterrupts().
 *  \param[in]     Controller   CAN controller for the CAN interrupt lock.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_INTLOCK == CAN_APPL || CAN_INTLOCK == CAN_BOTH
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, void, APPL_CODE) ApplCanInterruptDisable( uint8 Controller );

/************************************************************************************************************
 *  ApplCanInterruptRestore()
 ***********************************************************************************************************/
/*! \brief         CAN interrupt restore by application
 *  \details       Re-enabling of CAN Interrupts by the application. \n
                   E.g.: the CAN driver itself should not access the common Interrupt Controller due to application \n
                   specific restrictions (like security level). Or the application like to be informed because of \n
                   an CAN interrupt lock. called by Can_EnableControllerInterrupts().
 *  \param[in]     Controller   CAN controller for the CAN interrupt unlock.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_INTLOCK == CAN_APPL || CAN_INTLOCK == CAN_BOTH
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, void, APPL_CODE) ApplCanInterruptRestore( uint8 Controller );
#endif

#if (CAN_OVERRUN_NOTIFICATION == CAN_APPL)
/************************************************************************************************************
 *  Appl_CanOverrun()
 ***********************************************************************************************************/
/*! \brief         Overrun detection
 *  \details       Called when an overrun is detected for a BasicCAN mailbox. \n
 *                 Alternatively a DET call can be selected instead of ("CanOverrunNotification" is set to "DET").
 *  \param[in]     Controller   CAN controller for which the overrun was detected.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_OVERRUN_NOTIFICATION == CAN_APPL
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, void, APPL_CODE) Appl_CanOverrun ( uint8 Controller );

/************************************************************************************************************
 *  Appl_CanFullCanOverrun()
 ***********************************************************************************************************/
/*! \brief         Overrun detection
 *  \details       Called when an overrun is detected for a FullCAN mailbox. \n
 *                 Alternatively a DET call can be selected instead of ("CanOverrunNotification" is set to "DET").
 *  \param[in]     Controller   CAN controller for which the overrun was detected.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_OVERRUN_NOTIFICATION == CAN_APPL
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, void, APPL_CODE) Appl_CanFullCanOverrun ( uint8 Controller );
#endif

#if defined(C_ENABLE_CAN_RAM_CHECK)
# if !defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED) /* standard RAM_CHECK */
#  if defined(C_ENABLE_NOTIFY_CORRUPT_MAILBOX)
/************************************************************************************************************
 *  Appl_CanCorruptMailbox()
 ***********************************************************************************************************/
/*! \brief         Mailbox notification in case of RAM check failure.
 *  \details       Will notify the application (during Can_InitController()) about a defect mailbox within the CAN cell.
 *  \param[in]     Controller   CAN controller for which the check failed.
 *  \param[in]     hwObjHandle  Hardware handle of the defect mailbox.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_RAM_CHECK == CAN_NOTIFY_MAILBOX
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, void, APPL_CODE) Appl_CanCorruptMailbox(uint8 Controller, Can_HwHandleType hwObjHandle);
#  endif

/************************************************************************************************************
 *  Appl_CanRamCheckFailed()
 ***********************************************************************************************************/
/*! \brief         CAN controller notification in case of RAM check failure
 *  \details       will notify the application (during Can_InitController()) about a defect CAN controller \n
 *                 due to a previous failed mailbox check. The return value decide how to proceed with the initialization.
 *  \param[in]     Controller   CAN controller for which the check failed.
 *  \return        CAN_DEACTIVATE_CONTROLLER   deactivate the controller
 *  \return        CAN_ACTIVATE_CONTROLLER     activate the controller
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_RAM_CHECK == CAN_NOTIFY_MAILBOX / CAN_NOTIFY_ISSUE
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, uint8, APPL_CODE) Appl_CanRamCheckFailed(uint8 Controller);
# endif /* standard RAM_CHECK */
#endif

# if defined ( C_ENABLE_USER_MODE_APPL )
/************************************************************************************************************
 *  ApplCanWriteProtectedRegister()
 ***********************************************************************************************************/
/*! \brief         Callback to write protected registers.
 *  \details       Application function which is called by the CAN driver to write special protected registers,
 *                 when CAN driver runs in user mode. 
 *  \param[in]     regPtr   Pointer to the register which has to be written.
 *  \param[in]     mask     The mask specifies the bits of the register to be written.
 *  \param[in]     value    The value which has to be written to the register.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        define C_ENABLE_USER_MODE_APPL via user configuration file
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, void, APPL_CODE) ApplCanWriteProtectedRegister8(CanChipMsgPtr8 regPtr, uint8 mask, uint8 value);
V_DEF_FUNC(extern, void, APPL_CODE) ApplCanWriteProtectedRegister16(CanChipMsgPtr16 regPtr, uint16 mask, uint16 value);
V_DEF_FUNC(extern, void, APPL_CODE) ApplCanWriteProtectedRegister32(CanChipMsgPtr32 regPtr, uint32 mask, uint32 value);
/************************************************************************************************************
 *  ApplCanReadProtectedRegister()
 ***********************************************************************************************************/
/*! \brief         Callback to read protected registers.
 *  \details       Application function which is called by the CAN driver to read special protected registers,
 *                 when CAN driver runs in user mode.
 *  \return        value    Returns the value of the register that was read
 *  \param[in]     regPtr   Pointer to the register which has to be written.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        define C_ENABLE_USER_MODE_APPL via user configuration file
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, uint8, APPL_CODE) ApplCanReadProtectedRegister8(CanChipMsgPtr8 regPtr);
V_DEF_FUNC(extern, uint16, APPL_CODE) ApplCanReadProtectedRegister16(CanChipMsgPtr16 regPtr);
V_DEF_FUNC(extern, uint32, APPL_CODE) ApplCanReadProtectedRegister32(CanChipMsgPtr32 regPtr);
# endif


/* \trace SPEC-1588 */
#if defined( C_ENABLE_UPDATE_BASE_ADDRESS ) /* COV_CAN_ENABLE_UPDATE_BASE_ADDRESS */
/************************************************************************************************************
 *  ApplCanPowerOnGetBaseAddress()
 ***********************************************************************************************************/
/*! \brief         Callback to read and save the 32bit virtual base address of a FlexCAN controller.
 *  \details       Application function which is called by the CAN driver to read and save the 32bit address 
 *                 of a FlexCAN controller during power-on in order to use it further on.
 *  \param[in]     physAddr   physical address of a FlexCAN controller
 *  \param[in]     size       size of FlexCAN memory area
 *  \return        Returns the virtual address of the FlexCAN controller matching physAddr
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        VGEN_ENABLE_MDWRAP || VGEN_ENABLE_QWRAP || C_ENABLE_UPDATE_BASE_ADDRESS
 *                 (defined via user configuration file)
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC_CBK(V_NONE, void*, APPL_CODE) ApplCanPowerOnGetBaseAddress(vuint32 physAddr, vuint16 size);
/* CODE CATEGORY 4 END */

#endif




#define CAN_STOP_SEC_CODE_APPL  /*-----------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if !defined(C_DRV_INTERNAL) /* COV_CAN_INTERNAL */
# if defined(CAN_HL_NO_V_DEF) /* COV_CAN_INTERNAL */
/* only use internal when not defined before - undef to get no conflict in CBD - MSR mixed systems */
#  undef vuint8 /* PRQA S 0841 */ /* MD_Can_0841 */
#  undef vsint8 /* PRQA S 0841 */ /* MD_Can_0841 */
#  undef vuint16 /* PRQA S 0841 */ /* MD_Can_0841 */
#  undef vsint16 /* PRQA S 0841 */ /* MD_Can_0841 */
#  undef vuint32 /* PRQA S 0841 */ /* MD_Can_0841 */
#  undef vsint32 /* PRQA S 0841 */ /* MD_Can_0841 */
# endif
#endif

/*!
 * \exclusivearea CAN_EXCLUSIVE_AREA_1
 * Ensures consistency while modifying the interrupt counter and CAN interrupt lock registers.
 * \protects canCanInterruptCounter, CAN interrupt registers
 * \usedin Can_EnableControllerInterrupts, Can_DisableControllerInterrupts
 * \exclude All functions provided by Can.
 * \length SHORT The interrupt registers and a counter variable are modified.
 * \endexclusivearea
 *
 * \exclusivearea CAN_EXCLUSIVE_AREA_2
 * Ensures consistency while modifying the TX mailbox states and lock registers.
 * \protects Can_ActiveSendState, CAN mailbox registers
 * \usedin Can_Write
 * \exclude Can_Write, Can_Mainfunction_Write, Can TX Interrupt
 * \length MEDIUM Multiplexed TX and cancellation handling. Cancellation handling by CAN Interface triggered. CAN TX mailbox registers and semaphore for locked mailbox modified.
 * \endexclusivearea
 *
 * \exclusivearea CAN_EXCLUSIVE_AREA_3
 * Ensures consistency while modifying the TX mailbox states and lock registers in case of cancellation or generic confirmation used.
 * \protects Can_ActiveSendState, CAN mailbox registers
 * \usedin Can_Mainfunction_Write, Can TX Interrupt
 * \exclude Can_Write, Can_Mainfunction_Write, Can TX Interrupt
 * \length MEDIUM Confirmation TX and cancellation handling. Cancellation handling by CAN Interface triggered. CAN TX mailbox registers and states modified.
 * \endexclusivearea
 *
 * \exclusivearea CAN_EXCLUSIVE_AREA_4
 * Ensures consistency of RX Queue.
 * \protects RX Queue counter and data
 * \usedin Can_Mainfunction_Read, Can RX Interrupt
 * \exclude Can_Mainfunction_Read, Can RX Interrupt
 * \length SHORT Modify queue counter and copy data to queue.
 * \endexclusivearea
 *
 * \exclusivearea CAN_EXCLUSIVE_AREA_5
 * Ensures atomic wakeup mode transition. Do not use CAN interrupt locks because CAN interrupt status may be changed within.
 * \protects wakeup transition
 * \usedin Can_Mainfunction_Wakeup
 * \exclude Can_SetControllerMode, Can BusOff Interrupt, Can Wakeup, Can_Mainfunction_Wakeup.
 * \length MEDIUM wakeup mode transition will be performed.
 * \endexclusivearea
 *
 * \exclusivearea CAN_EXCLUSIVE_AREA_6
 * Ensures atomic mode transition.
 * \protects mode transition
 * \usedin Can_Mainfunction_Mode, Can_SetControllerMode, Can_MainFunction_BusOff, Can BusOff Interrupt
 * \exclude Can_Mainfunction_Mode, Can_SetControllerMode, Can_MainFunction_BusOff, Can BusOff Interrupt, Can_Mainfunction_Wakeup.
 * \length MEDIUM mode transition will be performed.
 * \endexclusivearea
 *
 */

/* PRQA  L:QAC_Can_0828 */
/* PRQA  L:QAC_Can_0850 */

#endif /* end file */
/*  STOPSINGLE_OF_MULTIPLE_COMMENT  */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Flexcan3Asr Erzeugungsgangnummer: 120 */


/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Flexcan3Asr Erzeugungsgangnummer: 120 */


/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Flexcan3Asr Erzeugungsgangnummer: 120 */


/************   Organi, Version 3.9.2 Vector-Informatik GmbH  ************/
