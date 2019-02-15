/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

volatile int16 cuenta=0;




CY_ISR(ISR_SW){
    cuenta++;
    LCD_Position(0,0);
    LCD_PrintInt16(cuenta);
    SW_ClearInterrupt();
}

CY_ISR(ISR_Timer){
    
LED_Write(~LED_Read());

}



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    ISR_M_StartEx(ISR_SW);
    ISR_T_StartEx(ISR_Timer);
    LCD_Start();
    Timer_Start();
    
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
