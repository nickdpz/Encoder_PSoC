/*******************************************************************************
* File Name: timerclock2.h
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

#if !defined(CY_CLOCK_timerclock2_H)
#define CY_CLOCK_timerclock2_H

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

void timerclock2_Start(void) ;
void timerclock2_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void timerclock2_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void timerclock2_StandbyPower(uint8 state) ;
void timerclock2_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 timerclock2_GetDividerRegister(void) ;
void timerclock2_SetModeRegister(uint8 modeBitMask) ;
void timerclock2_ClearModeRegister(uint8 modeBitMask) ;
uint8 timerclock2_GetModeRegister(void) ;
void timerclock2_SetSourceRegister(uint8 clkSource) ;
uint8 timerclock2_GetSourceRegister(void) ;
#if defined(timerclock2__CFG3)
void timerclock2_SetPhaseRegister(uint8 clkPhase) ;
uint8 timerclock2_GetPhaseRegister(void) ;
#endif /* defined(timerclock2__CFG3) */

#define timerclock2_Enable()                       timerclock2_Start()
#define timerclock2_Disable()                      timerclock2_Stop()
#define timerclock2_SetDivider(clkDivider)         timerclock2_SetDividerRegister(clkDivider, 1u)
#define timerclock2_SetDividerValue(clkDivider)    timerclock2_SetDividerRegister((clkDivider) - 1u, 1u)
#define timerclock2_SetMode(clkMode)               timerclock2_SetModeRegister(clkMode)
#define timerclock2_SetSource(clkSource)           timerclock2_SetSourceRegister(clkSource)
#if defined(timerclock2__CFG3)
#define timerclock2_SetPhase(clkPhase)             timerclock2_SetPhaseRegister(clkPhase)
#define timerclock2_SetPhaseValue(clkPhase)        timerclock2_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(timerclock2__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define timerclock2_CLKEN              (* (reg8 *) timerclock2__PM_ACT_CFG)
#define timerclock2_CLKEN_PTR          ((reg8 *) timerclock2__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define timerclock2_CLKSTBY            (* (reg8 *) timerclock2__PM_STBY_CFG)
#define timerclock2_CLKSTBY_PTR        ((reg8 *) timerclock2__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define timerclock2_DIV_LSB            (* (reg8 *) timerclock2__CFG0)
#define timerclock2_DIV_LSB_PTR        ((reg8 *) timerclock2__CFG0)
#define timerclock2_DIV_PTR            ((reg16 *) timerclock2__CFG0)

/* Clock MSB divider configuration register. */
#define timerclock2_DIV_MSB            (* (reg8 *) timerclock2__CFG1)
#define timerclock2_DIV_MSB_PTR        ((reg8 *) timerclock2__CFG1)

/* Mode and source configuration register */
#define timerclock2_MOD_SRC            (* (reg8 *) timerclock2__CFG2)
#define timerclock2_MOD_SRC_PTR        ((reg8 *) timerclock2__CFG2)

#if defined(timerclock2__CFG3)
/* Analog clock phase configuration register */
#define timerclock2_PHASE              (* (reg8 *) timerclock2__CFG3)
#define timerclock2_PHASE_PTR          ((reg8 *) timerclock2__CFG3)
#endif /* defined(timerclock2__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define timerclock2_CLKEN_MASK         timerclock2__PM_ACT_MSK
#define timerclock2_CLKSTBY_MASK       timerclock2__PM_STBY_MSK

/* CFG2 field masks */
#define timerclock2_SRC_SEL_MSK        timerclock2__CFG2_SRC_SEL_MASK
#define timerclock2_MODE_MASK          (~(timerclock2_SRC_SEL_MSK))

#if defined(timerclock2__CFG3)
/* CFG3 phase mask */
#define timerclock2_PHASE_MASK         timerclock2__CFG3_PHASE_DLY_MASK
#endif /* defined(timerclock2__CFG3) */

#endif /* CY_CLOCK_timerclock2_H */


/* [] END OF FILE */
