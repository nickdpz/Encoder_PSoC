/*******************************************************************************
* File Name: Key.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Key_ALIASES_H) /* Pins Key_ALIASES_H */
#define CY_PINS_Key_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Key_0			(Key__0__PC)
#define Key_0_INTR	((uint16)((uint16)0x0001u << Key__0__SHIFT))

#define Key_1			(Key__1__PC)
#define Key_1_INTR	((uint16)((uint16)0x0001u << Key__1__SHIFT))

#define Key_2			(Key__2__PC)
#define Key_2_INTR	((uint16)((uint16)0x0001u << Key__2__SHIFT))

#define Key_3			(Key__3__PC)
#define Key_3_INTR	((uint16)((uint16)0x0001u << Key__3__SHIFT))

#define Key_INTR_ALL	 ((uint16)(Key_0_INTR| Key_1_INTR| Key_2_INTR| Key_3_INTR))

#endif /* End Pins Key_ALIASES_H */


/* [] END OF FILE */
