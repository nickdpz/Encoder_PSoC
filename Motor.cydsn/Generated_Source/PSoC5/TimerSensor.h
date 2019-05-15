/*******************************************************************************
* File Name: TimerSensor.h
* Version 2.80
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_TIMER_TimerSensor_H)
#define CY_TIMER_TimerSensor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 TimerSensor_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_80 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define TimerSensor_Resolution                 8u
#define TimerSensor_UsingFixedFunction         1u
#define TimerSensor_UsingHWCaptureCounter      0u
#define TimerSensor_SoftwareCaptureMode        0u
#define TimerSensor_SoftwareTriggerMode        0u
#define TimerSensor_UsingHWEnable              0u
#define TimerSensor_EnableTriggerMode          0u
#define TimerSensor_InterruptOnCaptureCount    0u
#define TimerSensor_RunModeUsed                0u
#define TimerSensor_ControlRegRemoved          0u

#if defined(TimerSensor_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define TimerSensor_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (TimerSensor_UsingFixedFunction)
    #define TimerSensor_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define TimerSensor_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End TimerSensor_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!TimerSensor_UsingFixedFunction)

        uint8 TimerUdb;
        uint8 InterruptMaskValue;
        #if (TimerSensor_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!TimerSensor_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}TimerSensor_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    TimerSensor_Start(void) ;
void    TimerSensor_Stop(void) ;

void    TimerSensor_SetInterruptMode(uint8 interruptMode) ;
uint8   TimerSensor_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define TimerSensor_GetInterruptSource() TimerSensor_ReadStatusRegister()

#if(!TimerSensor_UDB_CONTROL_REG_REMOVED)
    uint8   TimerSensor_ReadControlRegister(void) ;
    void    TimerSensor_WriteControlRegister(uint8 control) ;
#endif /* (!TimerSensor_UDB_CONTROL_REG_REMOVED) */

uint8  TimerSensor_ReadPeriod(void) ;
void    TimerSensor_WritePeriod(uint8 period) ;
uint8  TimerSensor_ReadCounter(void) ;
void    TimerSensor_WriteCounter(uint8 counter) ;
uint8  TimerSensor_ReadCapture(void) ;
void    TimerSensor_SoftwareCapture(void) ;

#if(!TimerSensor_UsingFixedFunction) /* UDB Prototypes */
    #if (TimerSensor_SoftwareCaptureMode)
        void    TimerSensor_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!TimerSensor_UsingFixedFunction) */

    #if (TimerSensor_SoftwareTriggerMode)
        void    TimerSensor_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (TimerSensor_SoftwareTriggerMode) */

    #if (TimerSensor_EnableTriggerMode)
        void    TimerSensor_EnableTrigger(void) ;
        void    TimerSensor_DisableTrigger(void) ;
    #endif /* (TimerSensor_EnableTriggerMode) */


    #if(TimerSensor_InterruptOnCaptureCount)
        void    TimerSensor_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (TimerSensor_InterruptOnCaptureCount) */

    #if (TimerSensor_UsingHWCaptureCounter)
        void    TimerSensor_SetCaptureCount(uint8 captureCount) ;
        uint8   TimerSensor_ReadCaptureCount(void) ;
    #endif /* (TimerSensor_UsingHWCaptureCounter) */

    void TimerSensor_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void TimerSensor_Init(void)          ;
void TimerSensor_Enable(void)        ;
void TimerSensor_SaveConfig(void)    ;
void TimerSensor_RestoreConfig(void) ;
void TimerSensor_Sleep(void)         ;
void TimerSensor_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define TimerSensor__B_TIMER__CM_NONE 0
#define TimerSensor__B_TIMER__CM_RISINGEDGE 1
#define TimerSensor__B_TIMER__CM_FALLINGEDGE 2
#define TimerSensor__B_TIMER__CM_EITHEREDGE 3
#define TimerSensor__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define TimerSensor__B_TIMER__TM_NONE 0x00u
#define TimerSensor__B_TIMER__TM_RISINGEDGE 0x04u
#define TimerSensor__B_TIMER__TM_FALLINGEDGE 0x08u
#define TimerSensor__B_TIMER__TM_EITHEREDGE 0x0Cu
#define TimerSensor__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define TimerSensor_INIT_PERIOD             254u
#define TimerSensor_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << TimerSensor_CTRL_CAP_MODE_SHIFT))
#define TimerSensor_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << TimerSensor_CTRL_TRIG_MODE_SHIFT))
#if (TimerSensor_UsingFixedFunction)
    #define TimerSensor_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << TimerSensor_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << TimerSensor_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define TimerSensor_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << TimerSensor_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << TimerSensor_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << TimerSensor_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (TimerSensor_UsingFixedFunction) */
#define TimerSensor_INIT_CAPTURE_COUNT      (2u)
#define TimerSensor_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << TimerSensor_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (TimerSensor_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define TimerSensor_STATUS         (*(reg8 *) TimerSensor_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define TimerSensor_STATUS_MASK    (*(reg8 *) TimerSensor_TimerHW__SR0 )
    #define TimerSensor_CONTROL        (*(reg8 *) TimerSensor_TimerHW__CFG0)
    #define TimerSensor_CONTROL2       (*(reg8 *) TimerSensor_TimerHW__CFG1)
    #define TimerSensor_CONTROL2_PTR   ( (reg8 *) TimerSensor_TimerHW__CFG1)
    #define TimerSensor_RT1            (*(reg8 *) TimerSensor_TimerHW__RT1)
    #define TimerSensor_RT1_PTR        ( (reg8 *) TimerSensor_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define TimerSensor_CONTROL3       (*(reg8 *) TimerSensor_TimerHW__CFG2)
        #define TimerSensor_CONTROL3_PTR   ( (reg8 *) TimerSensor_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define TimerSensor_GLOBAL_ENABLE  (*(reg8 *) TimerSensor_TimerHW__PM_ACT_CFG)
    #define TimerSensor_GLOBAL_STBY_ENABLE  (*(reg8 *) TimerSensor_TimerHW__PM_STBY_CFG)

    #define TimerSensor_CAPTURE_LSB         (* (reg16 *) TimerSensor_TimerHW__CAP0 )
    #define TimerSensor_CAPTURE_LSB_PTR       ((reg16 *) TimerSensor_TimerHW__CAP0 )
    #define TimerSensor_PERIOD_LSB          (* (reg16 *) TimerSensor_TimerHW__PER0 )
    #define TimerSensor_PERIOD_LSB_PTR        ((reg16 *) TimerSensor_TimerHW__PER0 )
    #define TimerSensor_COUNTER_LSB         (* (reg16 *) TimerSensor_TimerHW__CNT_CMP0 )
    #define TimerSensor_COUNTER_LSB_PTR       ((reg16 *) TimerSensor_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define TimerSensor_BLOCK_EN_MASK                     TimerSensor_TimerHW__PM_ACT_MSK
    #define TimerSensor_BLOCK_STBY_EN_MASK                TimerSensor_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define TimerSensor_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define TimerSensor_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define TimerSensor_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define TimerSensor_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define TimerSensor_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define TimerSensor_CTRL_ENABLE                        ((uint8)((uint8)0x01u << TimerSensor_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define TimerSensor_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define TimerSensor_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << TimerSensor_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define TimerSensor_CTRL_MODE_SHIFT                 0x01u
        #define TimerSensor_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << TimerSensor_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define TimerSensor_CTRL_RCOD_SHIFT        0x02u
        #define TimerSensor_CTRL_ENBL_SHIFT        0x00u
        #define TimerSensor_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define TimerSensor_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << TimerSensor_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define TimerSensor_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << TimerSensor_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define TimerSensor_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << TimerSensor_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define TimerSensor_CTRL_RCOD       ((uint8)((uint8)0x03u << TimerSensor_CTRL_RCOD_SHIFT))
        #define TimerSensor_CTRL_ENBL       ((uint8)((uint8)0x80u << TimerSensor_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define TimerSensor_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define TimerSensor_RT1_MASK                        ((uint8)((uint8)0x03u << TimerSensor_RT1_SHIFT))
    #define TimerSensor_SYNC                            ((uint8)((uint8)0x03u << TimerSensor_RT1_SHIFT))
    #define TimerSensor_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define TimerSensor_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << TimerSensor_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define TimerSensor_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << TimerSensor_SYNCDSI_SHIFT))

    #define TimerSensor_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << TimerSensor_CTRL_MODE_SHIFT))
    #define TimerSensor_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << TimerSensor_CTRL_MODE_SHIFT))
    #define TimerSensor_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << TimerSensor_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define TimerSensor_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define TimerSensor_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define TimerSensor_STATUS_TC_INT_MASK_SHIFT        (TimerSensor_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define TimerSensor_STATUS_CAPTURE_INT_MASK_SHIFT   (TimerSensor_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define TimerSensor_STATUS_TC                       ((uint8)((uint8)0x01u << TimerSensor_STATUS_TC_SHIFT))
    #define TimerSensor_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << TimerSensor_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define TimerSensor_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << TimerSensor_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define TimerSensor_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << TimerSensor_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define TimerSensor_STATUS              (* (reg8 *) TimerSensor_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define TimerSensor_STATUS_MASK         (* (reg8 *) TimerSensor_TimerUDB_rstSts_stsreg__MASK_REG)
    #define TimerSensor_STATUS_AUX_CTRL     (* (reg8 *) TimerSensor_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define TimerSensor_CONTROL             (* (reg8 *) TimerSensor_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(TimerSensor_Resolution <= 8u) /* 8-bit Timer */
        #define TimerSensor_CAPTURE_LSB         (* (reg8 *) TimerSensor_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define TimerSensor_CAPTURE_LSB_PTR       ((reg8 *) TimerSensor_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define TimerSensor_PERIOD_LSB          (* (reg8 *) TimerSensor_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define TimerSensor_PERIOD_LSB_PTR        ((reg8 *) TimerSensor_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define TimerSensor_COUNTER_LSB         (* (reg8 *) TimerSensor_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define TimerSensor_COUNTER_LSB_PTR       ((reg8 *) TimerSensor_TimerUDB_sT8_timerdp_u0__A0_REG )
    #elif(TimerSensor_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define TimerSensor_CAPTURE_LSB         (* (reg16 *) TimerSensor_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define TimerSensor_CAPTURE_LSB_PTR       ((reg16 *) TimerSensor_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define TimerSensor_PERIOD_LSB          (* (reg16 *) TimerSensor_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define TimerSensor_PERIOD_LSB_PTR        ((reg16 *) TimerSensor_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define TimerSensor_COUNTER_LSB         (* (reg16 *) TimerSensor_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define TimerSensor_COUNTER_LSB_PTR       ((reg16 *) TimerSensor_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define TimerSensor_CAPTURE_LSB         (* (reg16 *) TimerSensor_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define TimerSensor_CAPTURE_LSB_PTR       ((reg16 *) TimerSensor_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define TimerSensor_PERIOD_LSB          (* (reg16 *) TimerSensor_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define TimerSensor_PERIOD_LSB_PTR        ((reg16 *) TimerSensor_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define TimerSensor_COUNTER_LSB         (* (reg16 *) TimerSensor_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
            #define TimerSensor_COUNTER_LSB_PTR       ((reg16 *) TimerSensor_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(TimerSensor_Resolution <= 24u)/* 24-bit Timer */
        #define TimerSensor_CAPTURE_LSB         (* (reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define TimerSensor_CAPTURE_LSB_PTR       ((reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define TimerSensor_PERIOD_LSB          (* (reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define TimerSensor_PERIOD_LSB_PTR        ((reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define TimerSensor_COUNTER_LSB         (* (reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define TimerSensor_COUNTER_LSB_PTR       ((reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define TimerSensor_CAPTURE_LSB         (* (reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define TimerSensor_CAPTURE_LSB_PTR       ((reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define TimerSensor_PERIOD_LSB          (* (reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define TimerSensor_PERIOD_LSB_PTR        ((reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define TimerSensor_COUNTER_LSB         (* (reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define TimerSensor_COUNTER_LSB_PTR       ((reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define TimerSensor_CAPTURE_LSB         (* (reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define TimerSensor_CAPTURE_LSB_PTR       ((reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define TimerSensor_PERIOD_LSB          (* (reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define TimerSensor_PERIOD_LSB_PTR        ((reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define TimerSensor_COUNTER_LSB         (* (reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
            #define TimerSensor_COUNTER_LSB_PTR       ((reg32 *) TimerSensor_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define TimerSensor_COUNTER_LSB_PTR_8BIT       ((reg8 *) TimerSensor_TimerUDB_sT8_timerdp_u0__A0_REG )
    
    #if (TimerSensor_UsingHWCaptureCounter)
        #define TimerSensor_CAP_COUNT              (*(reg8 *) TimerSensor_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define TimerSensor_CAP_COUNT_PTR          ( (reg8 *) TimerSensor_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define TimerSensor_CAPTURE_COUNT_CTRL     (*(reg8 *) TimerSensor_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define TimerSensor_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) TimerSensor_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (TimerSensor_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define TimerSensor_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define TimerSensor_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define TimerSensor_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define TimerSensor_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define TimerSensor_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define TimerSensor_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << TimerSensor_CTRL_INTCNT_SHIFT))
    #define TimerSensor_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << TimerSensor_CTRL_TRIG_MODE_SHIFT))
    #define TimerSensor_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << TimerSensor_CTRL_TRIG_EN_SHIFT))
    #define TimerSensor_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << TimerSensor_CTRL_CAP_MODE_SHIFT))
    #define TimerSensor_CTRL_ENABLE                    ((uint8)((uint8)0x01u << TimerSensor_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define TimerSensor_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define TimerSensor_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define TimerSensor_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define TimerSensor_STATUS_TC_INT_MASK_SHIFT       TimerSensor_STATUS_TC_SHIFT
    #define TimerSensor_STATUS_CAPTURE_INT_MASK_SHIFT  TimerSensor_STATUS_CAPTURE_SHIFT
    #define TimerSensor_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define TimerSensor_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define TimerSensor_STATUS_FIFOFULL_INT_MASK_SHIFT TimerSensor_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define TimerSensor_STATUS_TC                      ((uint8)((uint8)0x01u << TimerSensor_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define TimerSensor_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << TimerSensor_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define TimerSensor_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << TimerSensor_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define TimerSensor_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << TimerSensor_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define TimerSensor_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << TimerSensor_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define TimerSensor_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << TimerSensor_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define TimerSensor_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << TimerSensor_STATUS_FIFOFULL_SHIFT))

    #define TimerSensor_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define TimerSensor_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define TimerSensor_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define TimerSensor_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define TimerSensor_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define TimerSensor_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_TIMER_TimerSensor_H */


/* [] END OF FILE */
