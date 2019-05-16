/*******************************************************************************
* File Name: PINT.h  
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

#if !defined(CY_PINS_PINT_ALIASES_H) /* Pins PINT_ALIASES_H */
#define CY_PINS_PINT_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define PINT_0			(PINT__0__PC)
#define PINT_0_INTR	((uint16)((uint16)0x0001u << PINT__0__SHIFT))

#define PINT_INTR_ALL	 ((uint16)(PINT_0_INTR))

#endif /* End Pins PINT_ALIASES_H */


/* [] END OF FILE */
