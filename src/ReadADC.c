/**
 * @file ReadADC.c
 * @author Sai Rishitha
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include "ReadADC.h"

void InitADC()
{
    ADMUX=(1<<REFS0); // For Aref=AVcc;
    ADCSRA=(1<<ADEN) | (7<<ADPS0);
}
uint16_t ReadADC(uint8_t ch)
{
    //SELECT ADC CHANNEL CH MUST BE 0-7
    ADMUX&=0Xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    // Start Single conversion
    ADCSRA|=(1<<ADSC);
    // Wait for conversion to complete
    while(!(ADCSRA & (1<<ADIF)));
    //Clear ADIF by writing one to it
    ADCSRA|=(1<<ADIF);
    return(ADC);
}
