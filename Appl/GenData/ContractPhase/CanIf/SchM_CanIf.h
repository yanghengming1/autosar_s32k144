/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  SchM_CanIf.h
 *        Config:  C:/Vector/CBD1800257_D01_S32K1xx/Applications/S32K144_Start_new/S32K144_Start.dpa
 *    BSW Module:  CanIf
 *  Generated at:  Mon Jun  7 11:19:41 2021
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800257
 *
 *   Description:  Header of BSW Scheduler for BSW Module <CanIf> (Contract Phase)
 *********************************************************************************************************************/
#ifndef SCHM_CANIF_H
# define SCHM_CANIF_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_CanIf_Type.h"

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_0(void);
FUNC(void, RTE_CODE) SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_0(void);
FUNC(void, RTE_CODE) SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_1(void);
FUNC(void, RTE_CODE) SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_1(void);
FUNC(void, RTE_CODE) SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_2(void);
FUNC(void, RTE_CODE) SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_2(void);
FUNC(void, RTE_CODE) SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_3(void);
FUNC(void, RTE_CODE) SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_3(void);
FUNC(void, RTE_CODE) SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_4(void);
FUNC(void, RTE_CODE) SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_4(void);
FUNC(void, RTE_CODE) SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_5(void);
FUNC(void, RTE_CODE) SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_5(void);
FUNC(void, RTE_CODE) SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_6(void);
FUNC(void, RTE_CODE) SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_6(void);
FUNC(void, RTE_CODE) SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_7(void);
FUNC(void, RTE_CODE) SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_7(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_CANIF_H */
