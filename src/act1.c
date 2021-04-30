/**
 * @file act1.c
 * @author Sai Rishitha
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<avr/io.h>
#include "act1.h"

/**
 * @brief Led change state
 * 
 * @param st 
 */
void led(uint8_t st)
{
    LED_PORT=(st<<LED_PIN);
}
void InitLED(void)
{
	DDRB|=(1<<PB0);
    DDRD&=~(1<<PD0);
    PORTD|=(1<<PD0);
    PORTD|=(1<<PD1);
}
