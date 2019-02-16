/*******************************************************************************
* File Name: IRS_key.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_IRS_key_H)
#define CY_ISR_IRS_key_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void IRS_key_Start(void);
void IRS_key_StartEx(cyisraddress address);
void IRS_key_Stop(void);

CY_ISR_PROTO(IRS_key_Interrupt);

void IRS_key_SetVector(cyisraddress address);
cyisraddress IRS_key_GetVector(void);

void IRS_key_SetPriority(uint8 priority);
uint8 IRS_key_GetPriority(void);

void IRS_key_Enable(void);
uint8 IRS_key_GetState(void);
void IRS_key_Disable(void);

void IRS_key_SetPending(void);
void IRS_key_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the IRS_key ISR. */
#define IRS_key_INTC_VECTOR            ((reg32 *) IRS_key__INTC_VECT)

/* Address of the IRS_key ISR priority. */
#define IRS_key_INTC_PRIOR             ((reg8 *) IRS_key__INTC_PRIOR_REG)

/* Priority of the IRS_key interrupt. */
#define IRS_key_INTC_PRIOR_NUMBER      IRS_key__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable IRS_key interrupt. */
#define IRS_key_INTC_SET_EN            ((reg32 *) IRS_key__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the IRS_key interrupt. */
#define IRS_key_INTC_CLR_EN            ((reg32 *) IRS_key__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the IRS_key interrupt state to pending. */
#define IRS_key_INTC_SET_PD            ((reg32 *) IRS_key__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the IRS_key interrupt. */
#define IRS_key_INTC_CLR_PD            ((reg32 *) IRS_key__INTC_CLR_PD_REG)


#endif /* CY_ISR_IRS_key_H */


/* [] END OF FILE */
