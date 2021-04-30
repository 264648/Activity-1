/**
 * @file main.c
 * @author Sai Rishitha
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "act1.h"
#include "act2.h"
#include "act3.h"
#include "act4.h"
#include<avr/io.h>
/**
 * @brief Functions
 * 
 */
void p_1(void){
    DDRB|=(1<<PB0);// SET B0=1
  DDRD&=~(1<<PD2);// CLEAR BIT
  PORTD|=(1<<PD2);// SET BIT
  DDRD&=~(1<<PD1);// CLEAR BIT
  PORTD|=(1<<PD1);// SET BIT
  
  InitADC();
  InitP();
  InitUART(103);
}
int main(void){
    uint16_t temp=0;
    uint16_t i;
    p_1();
    while(1){
        if(sw1 && sw2){
            led(LED_ON);//LED is ON
            temp=ReadADC(0);
            OCR1A=temp;
            if(OCR1A>=0 && OCR1A<=200){
                unsigned char d1[]="Temp:20\n";
        i=0;
        while(d1[i]!=0){
           while(!(UCSR0A & (1<<UDRE0)));
           UDR0=d1[i];
           i++;
        }
        delay_ms(LED_ON_TIME);
        }
        else if(OCR1A>=210 && OCR1A<=500){

       unsigned char d1[]="Temp:25\n";
        i=0;
        while(d1[i]!=0){
           while(!(UCSR0A & (1<<UDRE0)));
           UDR0=d1[i];
           i++;
        }
         delay_ms(LED_ON_TIME);
        }
        else if(OCR1A>=510 && OCR1A<=700){

        unsigned char d1[]="Temp:29\n";
        i=0;
        while(d1[i]!=0){
           while(!(UCSR0A & (1<<UDRE0)));
           UDR0=d1[i];
           i++;
        }
        delay_ms(LED_ON_TIME);
        }
        else if(OCR1A>=710 && OCR1A<=1024){
       unsigned char d1[]="Temp:33\n";
        i=0;
        while(d1[i]!=0){
           while(!(UCSR0A & (1<<UDRE0)));
           UDR0=d1[i];
           i++;
        }
            delay_ms(LED_ON_TIME);
        }
        }
    
    else{
        led(LED_OFF); //LED is OFF
        delay_ms(LED_OFF_TIME);
                }
}
return 0;
}
