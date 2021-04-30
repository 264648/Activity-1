/**
 * @file act3.c
 * @author Sai Rishitha
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include "act3.h"
#include<util/delay.h>
/**
 * @file outPWM.c
 * @author Sai Rishitha
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<avr/io.h>
#include "act3.h"
/**
 * @brief Port initialization
 * 
 */
void InitP()
{
    TCCR1A |=(1<<COM1A1)|(1<<WGM11) | (1<<WGM10);
TCCR1B|=(1<<WGM12) | (1<<CS12) | (1<<CS10);
DDRB |=1<<PB1;
}
