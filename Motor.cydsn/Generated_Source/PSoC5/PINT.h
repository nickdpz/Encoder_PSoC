/*******************************************************************************
* File Name: PINT.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PINT_H) /* Pins PINT_H */
#define CY_PINS_PINT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PINT_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PINT__PORT == 15 && ((PINT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PINT_Write(uint8 value);
void    PINT_SetDriveMode(uint8 mode);
uint8   PINT_ReadDataReg(void);
uint8   PINT_Read(void);
void    PINT_SetInterruptMode(uint16 position, uint16 mode);
uint8   PINT_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PINT_SetDriveMode() function.
     *  @{
     */
        #define PINT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PINT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PINT_DM_RES_UP          PIN_DM_RES_UP
        #define PINT_DM_RES_DWN         PIN_DM_RES_DWN
        #define PINT_DM_OD_LO           PIN_DM_OD_LO
        #define PINT_DM_OD_HI           PIN_DM_OD_HI
        #define PINT_DM_STRONG          PIN_DM_STRONG
        #define PINT_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PINT_MASK               PINT__MASK
#define PINT_SHIFT              PINT__SHIFT
#define PINT_WIDTH              1u

/* Interrupt constants */
#if defined(PINT__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PINT_SetInterruptMode() function.
     *  @{
     */
        #define PINT_INTR_NONE      (uint16)(0x0000u)
        #define PINT_INTR_RISING    (uint16)(0x0001u)
        #define PINT_INTR_FALLING   (uint16)(0x0002u)
        #define PINT_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PINT_INTR_MASK      (0x01u) 
#endif /* (PINT__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PINT_PS                     (* (reg8 *) PINT__PS)
/* Data Register */
#define PINT_DR                     (* (reg8 *) PINT__DR)
/* Port Number */
#define PINT_PRT_NUM                (* (reg8 *) PINT__PRT) 
/* Connect to Analog Globals */                                                  
#define PINT_AG                     (* (reg8 *) PINT__AG)                       
/* Analog MUX bux enable */
#define PINT_AMUX                   (* (reg8 *) PINT__AMUX) 
/* Bidirectional Enable */                                                        
#define PINT_BIE                    (* (reg8 *) PINT__BIE)
/* Bit-mask for Aliased Register Access */
#define PINT_BIT_MASK               (* (reg8 *) PINT__BIT_MASK)
/* Bypass Enable */
#define PINT_BYP                    (* (reg8 *) PINT__BYP)
/* Port wide control signals */                                                   
#define PINT_CTL                    (* (reg8 *) PINT__CTL)
/* Drive Modes */
#define PINT_DM0                    (* (reg8 *) PINT__DM0) 
#define PINT_DM1                    (* (reg8 *) PINT__DM1)
#define PINT_DM2                    (* (reg8 *) PINT__DM2) 
/* Input Buffer Disable Override */
#define PINT_INP_DIS                (* (reg8 *) PINT__INP_DIS)
/* LCD Common or Segment Drive */
#define PINT_LCD_COM_SEG            (* (reg8 *) PINT__LCD_COM_SEG)
/* Enable Segment LCD */
#define PINT_LCD_EN                 (* (reg8 *) PINT__LCD_EN)
/* Slew Rate Control */
#define PINT_SLW                    (* (reg8 *) PINT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PINT_PRTDSI__CAPS_SEL       (* (reg8 *) PINT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PINT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PINT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PINT_PRTDSI__OE_SEL0        (* (reg8 *) PINT__PRTDSI__OE_SEL0) 
#define PINT_PRTDSI__OE_SEL1        (* (reg8 *) PINT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PINT_PRTDSI__OUT_SEL0       (* (reg8 *) PINT__PRTDSI__OUT_SEL0) 
#define PINT_PRTDSI__OUT_SEL1       (* (reg8 *) PINT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PINT_PRTDSI__SYNC_OUT       (* (reg8 *) PINT__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PINT__SIO_CFG)
    #define PINT_SIO_HYST_EN        (* (reg8 *) PINT__SIO_HYST_EN)
    #define PINT_SIO_REG_HIFREQ     (* (reg8 *) PINT__SIO_REG_HIFREQ)
    #define PINT_SIO_CFG            (* (reg8 *) PINT__SIO_CFG)
    #define PINT_SIO_DIFF           (* (reg8 *) PINT__SIO_DIFF)
#endif /* (PINT__SIO_CFG) */

/* Interrupt Registers */
#if defined(PINT__INTSTAT)
    #define PINT_INTSTAT            (* (reg8 *) PINT__INTSTAT)
    #define PINT_SNAP               (* (reg8 *) PINT__SNAP)
    
	#define PINT_0_INTTYPE_REG 		(* (reg8 *) PINT__0__INTTYPE)
#endif /* (PINT__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PINT_H */


/* [] END OF FILE */
