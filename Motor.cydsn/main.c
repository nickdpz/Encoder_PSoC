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
volatile char cont=0;
volatile int16 rpm=0;
float d=0;
float seleccion=0;


void timer(){
  if(cont==3){
        cont=0;
    }else{
        cont=cont+1;
    }
    switch(cont){
         case 0:
            P0_Write(0b00001110);
         break;
         case 1:
            P0_Write(0b00001101);
         break;
         case 2:
            P0_Write(0b00001101);
        break;
        default:
            P0_Write(0b00000111);
        break;            
    }   
}

CY_ISR(ISR_Timer){
    if(cont==3){
        cont=0;
    }else{
        cont=cont+1;
    }
    switch(cont){
         case 0:
            P0_Write(0b00001110);
         break;
         case 1:
            P0_Write(0b00001101);
         break;
         case 2:
            P0_Write(0b00001101);
        break;
        default:
            P0_Write(0b00000111);
        break;            
    }   
}

CY_ISR(ISR_KEY){
    Timer_Stop();//Detiene el timer para que no vuelva a entrar
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
Timer_Start();
Key_ClearInterrupt();
}



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    ISR_T_StartEx(ISR_Timer);
    IRS_key_StartEx(ISR_KEY);
    LCD_Start();
    Timer_Start();
     /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
     //Leer dato de sensor y compararlo con el nivel 
        while(Pin_HC_Read()==0);//Espera hasta que llega 1
        TimerSensor_Start();
        //A andar el timer 
        while(Pin_HC_Read()==1);
        //Toma el valor del timer
        d=5*TimerSensor_ReadCounter();
        TimerSensor_Stop();
        LCD_PrintNumber(d);
        if(d>seleccion){
        //Llena 
            Llenar_Write(1);
            
        }else{
         //Vacia
            Vaciar_Write(1);
            
        }
        
        //timer();
    }
}

/* [] END OF FILE */
