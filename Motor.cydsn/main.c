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
volatile int16 rpm=0;
int16 rpmingresado=500;




CY_ISR(ISR_SW){
    cuenta++;
    SW_ClearInterrupt();
}

CY_ISR(ISR_Timer){
    rpm=cuenta*60;
    cuenta=0;
    LCD_ClearDisplay();
    LCD_PrintNumber(rpm);

}

CY_ISR(ISR_KEY){
    Control_Write(0);
switch(Key_Read()) {
        case 0b00001110:
            switch(P0_Read()) {
                    case 0xE:
                    break;
                    case 0xD:

                    break;
                     case 0xB:

                    break;
                    case 0x7:
                    break;
                    default:
                    break;
                }
                    break;
        case 0b00001101:
            switch(P0_Read()) {
                    case 0xE:
                    break;
                    case 0xD:
                    break;
                    case 0xB:
                    break;
                    case 0x7:
                    break;
                    default:
                    break;   
                }
                    break;
                case 0b00001011:            
                    switch(P0_Read()) {
                    case 0xE:
                        LCD_Position(1,15);
                        LCD_PrintString("7");
                    break;
                    case 0xD:

                    break;
                     case 0xB:

                    break;
                    case 0x7:

                    break;
                    default:
                    break;   
                }
                    break;
                case 0b000000111:
                    switch(P0_Read()) {
                    case 0xE:
                            LCD_Position(1,15);
                            LCD_PrintString("*");
                    break;
                    case 0xD:
                            LCD_Position(1,15);
                            LCD_PrintString("0");

                    break;
                    case 0xB:                            
                            LCD_Position(1,15);
                            LCD_PrintString("#");
                    break;
                    
                    case 0x7:
                            LCD_Position(1,15);
                            LCD_PrintString("D");
                            
                    break;
                    default:
                    break;   
                }
                    break;
                default:
                break;
    }
    
Control_Write(1);
Key_ClearInterrupt();
}



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    ISR_M_StartEx(ISR_SW);
    ISR_T_StartEx(ISR_Timer);
    IRS_key_StartEx(ISR_KEY);
    LCD_Start();
    Timer_Start();
    PWM_Start();
    
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
     
        if(rpmingresado<rpm){
        //Volverse mas lento
        PWM_WriteCompare(800);
        
        }else{
        
        PWM_WriteCompare(80);  
        //Volverse mas rapido
        }
        
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
