#ifndef __LEDSTAT_H_
#define __LEDSTAT_H_
/**
 * @file ledstat.h
 * @author Sai Rishitha
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Include files
 */ 
#include <avr/io.h>
#include "ledstat.h"

 /**
 * @brief Macro definitions
 * 
 */
#define LED_ON 	(0x01)			/**< LED state HIGH */
#define LED_OFF	(0x00)			/**< LED state LOW */
#define LED_PORT (PORTB)
#define LED_PIN (PORT B1)
#define LED_ON_TIME     (1000)  /**< LED ON time in milli seconds  */
#define LED_OFF_TIME    (500)   /**< LED OFF time in milli seconds */
#define SENSOR_ON !(PIND&(1<<PD0)) // Switch1 ON
#define HEAT_ON !(PIND&(1<<PD1)) // Switch2 ON
/**
 * @brief Defining functions
 * 
 * @param st 
 */
void ledstat(uint8_t st);
#endif
/**
 * @brief End
 * 
 */
