/*******************************************************************************
* File Name: Vaciar.h  
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

#if !defined(CY_PINS_Vaciar_H) /* Pins Vaciar_H */
#define CY_PINS_Vaciar_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Vaciar_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Vaciar__PORT == 15 && ((Vaciar__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Vaciar_Write(uint8 value);
void    Vaciar_SetDriveMode(uint8 mode);
uint8   Vaciar_ReadDataReg(void);
uint8   Vaciar_Read(void);
void    Vaciar_SetInterruptMode(uint16 position, uint16 mode);
uint8   Vaciar_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Vaciar_SetDriveMode() function.
     *  @{
     */
        #define Vaciar_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Vaciar_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Vaciar_DM_RES_UP          PIN_DM_RES_UP
        #define Vaciar_DM_RES_DWN         PIN_DM_RES_DWN
        #define Vaciar_DM_OD_LO           PIN_DM_OD_LO
        #define Vaciar_DM_OD_HI           PIN_DM_OD_HI
        #define Vaciar_DM_STRONG          PIN_DM_STRONG
        #define Vaciar_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Vaciar_MASK               Vaciar__MASK
#define Vaciar_SHIFT              Vaciar__SHIFT
#define Vaciar_WIDTH              1u

/* Interrupt constants */
#if defined(Vaciar__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Vaciar_SetInterruptMode() function.
     *  @{
     */
        #define Vaciar_INTR_NONE      (uint16)(0x0000u)
        #define Vaciar_INTR_RISING    (uint16)(0x0001u)
        #define Vaciar_INTR_FALLING   (uint16)(0x0002u)
        #define Vaciar_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Vaciar_INTR_MASK      (0x01u) 
#endif /* (Vaciar__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vaciar_PS                     (* (reg8 *) Vaciar__PS)
/* Data Register */
#define Vaciar_DR                     (* (reg8 *) Vaciar__DR)
/* Port Number */
#define Vaciar_PRT_NUM                (* (reg8 *) Vaciar__PRT) 
/* Connect to Analog Globals */                                                  
#define Vaciar_AG                     (* (reg8 *) Vaciar__AG)                       
/* Analog MUX bux enable */
#define Vaciar_AMUX                   (* (reg8 *) Vaciar__AMUX) 
/* Bidirectional Enable */                                                        
#define Vaciar_BIE                    (* (reg8 *) Vaciar__BIE)
/* Bit-mask for Aliased Register Access */
#define Vaciar_BIT_MASK               (* (reg8 *) Vaciar__BIT_MASK)
/* Bypass Enable */
#define Vaciar_BYP                    (* (reg8 *) Vaciar__BYP)
/* Port wide control signals */                                                   
#define Vaciar_CTL                    (* (reg8 *) Vaciar__CTL)
/* Drive Modes */
#define Vaciar_DM0                    (* (reg8 *) Vaciar__DM0) 
#define Vaciar_DM1                    (* (reg8 *) Vaciar__DM1)
#define Vaciar_DM2                    (* (reg8 *) Vaciar__DM2) 
/* Input Buffer Disable Override */
#define Vaciar_INP_DIS                (* (reg8 *) Vaciar__INP_DIS)
/* LCD Common or Segment Drive */
#define Vaciar_LCD_COM_SEG            (* (reg8 *) Vaciar__LCD_COM_SEG)
/* Enable Segment LCD */
#define Vaciar_LCD_EN                 (* (reg8 *) Vaciar__LCD_EN)
/* Slew Rate Control */
#define Vaciar_SLW                    (* (reg8 *) Vaciar__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Vaciar_PRTDSI__CAPS_SEL       (* (reg8 *) Vaciar__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Vaciar_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Vaciar__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Vaciar_PRTDSI__OE_SEL0        (* (reg8 *) Vaciar__PRTDSI__OE_SEL0) 
#define Vaciar_PRTDSI__OE_SEL1        (* (reg8 *) Vaciar__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Vaciar_PRTDSI__OUT_SEL0       (* (reg8 *) Vaciar__PRTDSI__OUT_SEL0) 
#define Vaciar_PRTDSI__OUT_SEL1       (* (reg8 *) Vaciar__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Vaciar_PRTDSI__SYNC_OUT       (* (reg8 *) Vaciar__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Vaciar__SIO_CFG)
    #define Vaciar_SIO_HYST_EN        (* (reg8 *) Vaciar__SIO_HYST_EN)
    #define Vaciar_SIO_REG_HIFREQ     (* (reg8 *) Vaciar__SIO_REG_HIFREQ)
    #define Vaciar_SIO_CFG            (* (reg8 *) Vaciar__SIO_CFG)
    #define Vaciar_SIO_DIFF           (* (reg8 *) Vaciar__SIO_DIFF)
#endif /* (Vaciar__SIO_CFG) */

/* Interrupt Registers */
#if defined(Vaciar__INTSTAT)
    #define Vaciar_INTSTAT            (* (reg8 *) Vaciar__INTSTAT)
    #define Vaciar_SNAP               (* (reg8 *) Vaciar__SNAP)
    
	#define Vaciar_0_INTTYPE_REG 		(* (reg8 *) Vaciar__0__INTTYPE)
#endif /* (Vaciar__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Vaciar_H */


/* [] END OF FILE */
