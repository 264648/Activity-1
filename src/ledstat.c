/**
 * @file ledstat.c
 * @author Sai Rishitha
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<avr/io.h>
#include "activity1.h"

/**
 * @brief Led change state
 * 
 * @param st 
 */
void led(uint8_t st)
{
    LED_PORT=(st<<LED_PIN);
}
