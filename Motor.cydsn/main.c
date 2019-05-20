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
#include <stdio.h>
#include <stdbool.h>

volatile uint16 contd=0;
volatile char cont=0;
uint16 d=0;
float seleccion=5.5;//medida en cm
volatile bool dec=1;
volatile float dising=100;//Distancia Ingresada
volatile uint16 disingaux=0;//distancia tempotal
volatile uint8 de=0;


void visual(uint8 numero){
    if(numero==10){  
        //Enter
    if(de==0){
        dising=disingaux;
        disingaux=0;
        de=1;
        LCD_Position(1,10);
        LCD_PrintString("    ");
        LCD_Position(1,10);
        LCD_PrintNumber((int)dising);
        }
    }else{
        de=0;
            if(disingaux==0){
                disingaux=numero;
            }else{
                disingaux=disingaux*10+numero;
                    if((disingaux>100)&(disingaux>1000)){
                        dising=1000;
                        disingaux=0;
                        de=1;
                    }
                }
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
CY_ISR(ISR_Timer2){
    contd++;//cuenta cada 100us -- la señal va de 100us a 25 ms es decir que el contador debe estar de 0 a 250 pero se pone la condicion en 500 por silas moscas
}



CY_ISR(ISR_KEY){
   dec=0;//Detiene el timer para que no vuelva a entrar
switch(Key_Read()) {
        case 0b00001110:
            switch(P0_Read()) {
                    case 0xE:
                    visual(4);
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
dec=0;
Key_ClearInterrupt();
}



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    ISR_T_1_StartEx(ISR_Timer);
    ISR_T_2_StartEx(ISR_Timer2);
    IRS_key_StartEx(ISR_KEY);
    LCD_Start();
    Timer_Start();
    Timer2_Start();
    P0_Write(0b00001111);
     /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
     //Leer dato de sensor y compararlo con el nivel 
        POUT_Write(0); //para generar un pulso limpio ponemos a LOW 4us
        CyDelayUs(4);
        POUT_Write(1);  //generamos Trigger (disparo) de 10us
        CyDelayUs(10);
        POUT_Write(0);
        while(PINT_Read()==0x0);//Espera hasta que llega 1
        contd=0;
        while(PINT_Read()==0x1);
        LCD_Position(1,6);
        LCD_PrintString("S");
        //Toma el valor del timer
        d=contd;//25 ms son 423cm --> cuantas veces 100 us son 25ms, serian 250: entonces 250 equivale a 423 cm --> distancia(cm)=423*cont(cuenta)/250
        LCD_Position(0,0);
        LCD_PrintNumber(d);
        LCD_Position(1,0);
        CyDelay(500);
                /*
        if(d>seleccion){
        //Llena 
            Llenar_Write(1);
            
        }else{
         //Vacia
            Vaciar_Write(1);
            
        }*/
        //timer();
    }
}

/* [] END OF FILE */
