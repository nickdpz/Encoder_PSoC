/*******************************************************************************
* File Name: timerclock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_timerclock_H)
#define CY_CLOCK_timerclock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void timerclock_Start(void) ;
void timerclock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void timerclock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void timerclock_StandbyPower(uint8 state) ;
void timerclock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 timerclock_GetDividerRegister(void) ;
void timerclock_SetModeRegister(uint8 modeBitMask) ;
void timerclock_ClearModeRegister(uint8 modeBitMask) ;
uint8 timerclock_GetModeRegister(void) ;
void timerclock_SetSourceRegister(uint8 clkSource) ;
uint8 timerclock_GetSourceRegister(void) ;
#if defined(timerclock__CFG3)
void timerclock_SetPhaseRegister(uint8 clkPhase) ;
uint8 timerclock_GetPhaseRegister(void) ;
#endif /* defined(timerclock__CFG3) */

#define timerclock_Enable()                       timerclock_Start()
#define timerclock_Disable()                      timerclock_Stop()
#define timerclock_SetDivider(clkDivider)         timerclock_SetDividerRegister(clkDivider, 1u)
#define timerclock_SetDividerValue(clkDivider)    timerclock_SetDividerRegister((clkDivider) - 1u, 1u)
#define timerclock_SetMode(clkMode)               timerclock_SetModeRegister(clkMode)
#define timerclock_SetSource(clkSource)           timerclock_SetSourceRegister(clkSource)
#if defined(timerclock__CFG3)
#define timerclock_SetPhase(clkPhase)             timerclock_SetPhaseRegister(clkPhase)
#define timerclock_SetPhaseValue(clkPhase)        timerclock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(timerclock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define timerclock_CLKEN              (* (reg8 *) timerclock__PM_ACT_CFG)
#define timerclock_CLKEN_PTR          ((reg8 *) timerclock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define timerclock_CLKSTBY            (* (reg8 *) timerclock__PM_STBY_CFG)
#define timerclock_CLKSTBY_PTR        ((reg8 *) timerclock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define timerclock_DIV_LSB            (* (reg8 *) timerclock__CFG0)
#define timerclock_DIV_LSB_PTR        ((reg8 *) timerclock__CFG0)
#define timerclock_DIV_PTR            ((reg16 *) timerclock__CFG0)

/* Clock MSB divider configuration register. */
#define timerclock_DIV_MSB            (* (reg8 *) timerclock__CFG1)
#define timerclock_DIV_MSB_PTR        ((reg8 *) timerclock__CFG1)

/* Mode and source configuration register */
#define timerclock_MOD_SRC            (* (reg8 *) timerclock__CFG2)
#define timerclock_MOD_SRC_PTR        ((reg8 *) timerclock__CFG2)

#if defined(timerclock__CFG3)
/* Analog clock phase configuration register */
#define timerclock_PHASE              (* (reg8 *) timerclock__CFG3)
#define timerclock_PHASE_PTR          ((reg8 *) timerclock__CFG3)
#endif /* defined(timerclock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define timerclock_CLKEN_MASK         timerclock__PM_ACT_MSK
#define timerclock_CLKSTBY_MASK       timerclock__PM_STBY_MSK

/* CFG2 field masks */
#define timerclock_SRC_SEL_MSK        timerclock__CFG2_SRC_SEL_MASK
#define timerclock_MODE_MASK          (~(timerclock_SRC_SEL_MSK))

#if defined(timerclock__CFG3)
/* CFG3 phase mask */
#define timerclock_PHASE_MASK         timerclock__CFG3_PHASE_DLY_MASK
#endif /* defined(timerclock__CFG3) */

#endif /* CY_CLOCK_timerclock_H */


/* [] END OF FILE */
