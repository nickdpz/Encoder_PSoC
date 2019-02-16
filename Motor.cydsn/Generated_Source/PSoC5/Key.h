/*******************************************************************************
* File Name: Key.h  
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

#if !defined(CY_PINS_Key_H) /* Pins Key_H */
#define CY_PINS_Key_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Key_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Key__PORT == 15 && ((Key__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Key_Write(uint8 value);
void    Key_SetDriveMode(uint8 mode);
uint8   Key_ReadDataReg(void);
uint8   Key_Read(void);
void    Key_SetInterruptMode(uint16 position, uint16 mode);
uint8   Key_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Key_SetDriveMode() function.
     *  @{
     */
        #define Key_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Key_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Key_DM_RES_UP          PIN_DM_RES_UP
        #define Key_DM_RES_DWN         PIN_DM_RES_DWN
        #define Key_DM_OD_LO           PIN_DM_OD_LO
        #define Key_DM_OD_HI           PIN_DM_OD_HI
        #define Key_DM_STRONG          PIN_DM_STRONG
        #define Key_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Key_MASK               Key__MASK
#define Key_SHIFT              Key__SHIFT
#define Key_WIDTH              4u

/* Interrupt constants */
#if defined(Key__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Key_SetInterruptMode() function.
     *  @{
     */
        #define Key_INTR_NONE      (uint16)(0x0000u)
        #define Key_INTR_RISING    (uint16)(0x0001u)
        #define Key_INTR_FALLING   (uint16)(0x0002u)
        #define Key_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Key_INTR_MASK      (0x01u) 
#endif /* (Key__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Key_PS                     (* (reg8 *) Key__PS)
/* Data Register */
#define Key_DR                     (* (reg8 *) Key__DR)
/* Port Number */
#define Key_PRT_NUM                (* (reg8 *) Key__PRT) 
/* Connect to Analog Globals */                                                  
#define Key_AG                     (* (reg8 *) Key__AG)                       
/* Analog MUX bux enable */
#define Key_AMUX                   (* (reg8 *) Key__AMUX) 
/* Bidirectional Enable */                                                        
#define Key_BIE                    (* (reg8 *) Key__BIE)
/* Bit-mask for Aliased Register Access */
#define Key_BIT_MASK               (* (reg8 *) Key__BIT_MASK)
/* Bypass Enable */
#define Key_BYP                    (* (reg8 *) Key__BYP)
/* Port wide control signals */                                                   
#define Key_CTL                    (* (reg8 *) Key__CTL)
/* Drive Modes */
#define Key_DM0                    (* (reg8 *) Key__DM0) 
#define Key_DM1                    (* (reg8 *) Key__DM1)
#define Key_DM2                    (* (reg8 *) Key__DM2) 
/* Input Buffer Disable Override */
#define Key_INP_DIS                (* (reg8 *) Key__INP_DIS)
/* LCD Common or Segment Drive */
#define Key_LCD_COM_SEG            (* (reg8 *) Key__LCD_COM_SEG)
/* Enable Segment LCD */
#define Key_LCD_EN                 (* (reg8 *) Key__LCD_EN)
/* Slew Rate Control */
#define Key_SLW                    (* (reg8 *) Key__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Key_PRTDSI__CAPS_SEL       (* (reg8 *) Key__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Key_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Key__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Key_PRTDSI__OE_SEL0        (* (reg8 *) Key__PRTDSI__OE_SEL0) 
#define Key_PRTDSI__OE_SEL1        (* (reg8 *) Key__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Key_PRTDSI__OUT_SEL0       (* (reg8 *) Key__PRTDSI__OUT_SEL0) 
#define Key_PRTDSI__OUT_SEL1       (* (reg8 *) Key__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Key_PRTDSI__SYNC_OUT       (* (reg8 *) Key__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Key__SIO_CFG)
    #define Key_SIO_HYST_EN        (* (reg8 *) Key__SIO_HYST_EN)
    #define Key_SIO_REG_HIFREQ     (* (reg8 *) Key__SIO_REG_HIFREQ)
    #define Key_SIO_CFG            (* (reg8 *) Key__SIO_CFG)
    #define Key_SIO_DIFF           (* (reg8 *) Key__SIO_DIFF)
#endif /* (Key__SIO_CFG) */

/* Interrupt Registers */
#if defined(Key__INTSTAT)
    #define Key_INTSTAT            (* (reg8 *) Key__INTSTAT)
    #define Key_SNAP               (* (reg8 *) Key__SNAP)
    
	#define Key_0_INTTYPE_REG 		(* (reg8 *) Key__0__INTTYPE)
	#define Key_1_INTTYPE_REG 		(* (reg8 *) Key__1__INTTYPE)
	#define Key_2_INTTYPE_REG 		(* (reg8 *) Key__2__INTTYPE)
	#define Key_3_INTTYPE_REG 		(* (reg8 *) Key__3__INTTYPE)
#endif /* (Key__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Key_H */


/* [] END OF FILE */
