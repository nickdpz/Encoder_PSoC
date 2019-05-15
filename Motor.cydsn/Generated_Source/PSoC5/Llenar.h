/*******************************************************************************
* File Name: Llenar.h  
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

#if !defined(CY_PINS_Llenar_H) /* Pins Llenar_H */
#define CY_PINS_Llenar_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Llenar_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Llenar__PORT == 15 && ((Llenar__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Llenar_Write(uint8 value);
void    Llenar_SetDriveMode(uint8 mode);
uint8   Llenar_ReadDataReg(void);
uint8   Llenar_Read(void);
void    Llenar_SetInterruptMode(uint16 position, uint16 mode);
uint8   Llenar_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Llenar_SetDriveMode() function.
     *  @{
     */
        #define Llenar_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Llenar_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Llenar_DM_RES_UP          PIN_DM_RES_UP
        #define Llenar_DM_RES_DWN         PIN_DM_RES_DWN
        #define Llenar_DM_OD_LO           PIN_DM_OD_LO
        #define Llenar_DM_OD_HI           PIN_DM_OD_HI
        #define Llenar_DM_STRONG          PIN_DM_STRONG
        #define Llenar_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Llenar_MASK               Llenar__MASK
#define Llenar_SHIFT              Llenar__SHIFT
#define Llenar_WIDTH              1u

/* Interrupt constants */
#if defined(Llenar__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Llenar_SetInterruptMode() function.
     *  @{
     */
        #define Llenar_INTR_NONE      (uint16)(0x0000u)
        #define Llenar_INTR_RISING    (uint16)(0x0001u)
        #define Llenar_INTR_FALLING   (uint16)(0x0002u)
        #define Llenar_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Llenar_INTR_MASK      (0x01u) 
#endif /* (Llenar__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Llenar_PS                     (* (reg8 *) Llenar__PS)
/* Data Register */
#define Llenar_DR                     (* (reg8 *) Llenar__DR)
/* Port Number */
#define Llenar_PRT_NUM                (* (reg8 *) Llenar__PRT) 
/* Connect to Analog Globals */                                                  
#define Llenar_AG                     (* (reg8 *) Llenar__AG)                       
/* Analog MUX bux enable */
#define Llenar_AMUX                   (* (reg8 *) Llenar__AMUX) 
/* Bidirectional Enable */                                                        
#define Llenar_BIE                    (* (reg8 *) Llenar__BIE)
/* Bit-mask for Aliased Register Access */
#define Llenar_BIT_MASK               (* (reg8 *) Llenar__BIT_MASK)
/* Bypass Enable */
#define Llenar_BYP                    (* (reg8 *) Llenar__BYP)
/* Port wide control signals */                                                   
#define Llenar_CTL                    (* (reg8 *) Llenar__CTL)
/* Drive Modes */
#define Llenar_DM0                    (* (reg8 *) Llenar__DM0) 
#define Llenar_DM1                    (* (reg8 *) Llenar__DM1)
#define Llenar_DM2                    (* (reg8 *) Llenar__DM2) 
/* Input Buffer Disable Override */
#define Llenar_INP_DIS                (* (reg8 *) Llenar__INP_DIS)
/* LCD Common or Segment Drive */
#define Llenar_LCD_COM_SEG            (* (reg8 *) Llenar__LCD_COM_SEG)
/* Enable Segment LCD */
#define Llenar_LCD_EN                 (* (reg8 *) Llenar__LCD_EN)
/* Slew Rate Control */
#define Llenar_SLW                    (* (reg8 *) Llenar__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Llenar_PRTDSI__CAPS_SEL       (* (reg8 *) Llenar__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Llenar_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Llenar__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Llenar_PRTDSI__OE_SEL0        (* (reg8 *) Llenar__PRTDSI__OE_SEL0) 
#define Llenar_PRTDSI__OE_SEL1        (* (reg8 *) Llenar__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Llenar_PRTDSI__OUT_SEL0       (* (reg8 *) Llenar__PRTDSI__OUT_SEL0) 
#define Llenar_PRTDSI__OUT_SEL1       (* (reg8 *) Llenar__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Llenar_PRTDSI__SYNC_OUT       (* (reg8 *) Llenar__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Llenar__SIO_CFG)
    #define Llenar_SIO_HYST_EN        (* (reg8 *) Llenar__SIO_HYST_EN)
    #define Llenar_SIO_REG_HIFREQ     (* (reg8 *) Llenar__SIO_REG_HIFREQ)
    #define Llenar_SIO_CFG            (* (reg8 *) Llenar__SIO_CFG)
    #define Llenar_SIO_DIFF           (* (reg8 *) Llenar__SIO_DIFF)
#endif /* (Llenar__SIO_CFG) */

/* Interrupt Registers */
#if defined(Llenar__INTSTAT)
    #define Llenar_INTSTAT            (* (reg8 *) Llenar__INTSTAT)
    #define Llenar_SNAP               (* (reg8 *) Llenar__SNAP)
    
	#define Llenar_0_INTTYPE_REG 		(* (reg8 *) Llenar__0__INTTYPE)
#endif /* (Llenar__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Llenar_H */


/* [] END OF FILE */
