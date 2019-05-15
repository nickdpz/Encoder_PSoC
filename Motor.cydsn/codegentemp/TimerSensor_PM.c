/*******************************************************************************
* File Name: TimerSensor_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "TimerSensor.h"

static TimerSensor_backupStruct TimerSensor_backup;


/*******************************************************************************
* Function Name: TimerSensor_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TimerSensor_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void TimerSensor_SaveConfig(void) 
{
    #if (!TimerSensor_UsingFixedFunction)
        TimerSensor_backup.TimerUdb = TimerSensor_ReadCounter();
        TimerSensor_backup.InterruptMaskValue = TimerSensor_STATUS_MASK;
        #if (TimerSensor_UsingHWCaptureCounter)
            TimerSensor_backup.TimerCaptureCounter = TimerSensor_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!TimerSensor_UDB_CONTROL_REG_REMOVED)
            TimerSensor_backup.TimerControlRegister = TimerSensor_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: TimerSensor_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TimerSensor_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void TimerSensor_RestoreConfig(void) 
{   
    #if (!TimerSensor_UsingFixedFunction)

        TimerSensor_WriteCounter(TimerSensor_backup.TimerUdb);
        TimerSensor_STATUS_MASK =TimerSensor_backup.InterruptMaskValue;
        #if (TimerSensor_UsingHWCaptureCounter)
            TimerSensor_SetCaptureCount(TimerSensor_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!TimerSensor_UDB_CONTROL_REG_REMOVED)
            TimerSensor_WriteControlRegister(TimerSensor_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: TimerSensor_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TimerSensor_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void TimerSensor_Sleep(void) 
{
    #if(!TimerSensor_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(TimerSensor_CTRL_ENABLE == (TimerSensor_CONTROL & TimerSensor_CTRL_ENABLE))
        {
            /* Timer is enabled */
            TimerSensor_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            TimerSensor_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    TimerSensor_Stop();
    TimerSensor_SaveConfig();
}


/*******************************************************************************
* Function Name: TimerSensor_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  TimerSensor_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void TimerSensor_Wakeup(void) 
{
    TimerSensor_RestoreConfig();
    #if(!TimerSensor_UDB_CONTROL_REG_REMOVED)
        if(TimerSensor_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                TimerSensor_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
