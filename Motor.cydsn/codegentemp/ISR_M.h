/*******************************************************************************
* File Name: ISR_M.h
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
#if !defined(CY_ISR_ISR_M_H)
#define CY_ISR_ISR_M_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void ISR_M_Start(void);
void ISR_M_StartEx(cyisraddress address);
void ISR_M_Stop(void);

CY_ISR_PROTO(ISR_M_Interrupt);

void ISR_M_SetVector(cyisraddress address);
cyisraddress ISR_M_GetVector(void);

void ISR_M_SetPriority(uint8 priority);
uint8 ISR_M_GetPriority(void);

void ISR_M_Enable(void);
uint8 ISR_M_GetState(void);
void ISR_M_Disable(void);

void ISR_M_SetPending(void);
void ISR_M_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ISR_M ISR. */
#define ISR_M_INTC_VECTOR            ((reg32 *) ISR_M__INTC_VECT)

/* Address of the ISR_M ISR priority. */
#define ISR_M_INTC_PRIOR             ((reg8 *) ISR_M__INTC_PRIOR_REG)

/* Priority of the ISR_M interrupt. */
#define ISR_M_INTC_PRIOR_NUMBER      ISR_M__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ISR_M interrupt. */
#define ISR_M_INTC_SET_EN            ((reg32 *) ISR_M__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ISR_M interrupt. */
#define ISR_M_INTC_CLR_EN            ((reg32 *) ISR_M__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ISR_M interrupt state to pending. */
#define ISR_M_INTC_SET_PD            ((reg32 *) ISR_M__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ISR_M interrupt. */
#define ISR_M_INTC_CLR_PD            ((reg32 *) ISR_M__INTC_CLR_PD_REG)


#endif /* CY_ISR_ISR_M_H */


/* [] END OF FILE */
