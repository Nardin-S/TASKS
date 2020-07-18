/*
 * LDE.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef LED_H_
#define LED_H_

#include "ATmega32_Registers.h"
#include "BitMath.h"
#include "DIO.h"

/******************************* LED 0 ********************************************/

void LED0_initial (void);
void LED0_ON (void);
void LED0_OFF (void);
void LED0_Toggle (void);
/**********************************************************************************/


/******************************* LED 1 ********************************************/

void LED1_initial(void);
void LED1_ON (void);
void LED1_OFF (void);
void LED1_Toggle (void);
/*********************************************************************************/

/******************************* LED 2 ********************************************/

void LED2_initial (void);
void LED2_ON (void);
void LED2_OFF (void);
void LED2_Toggle (void);
/**********************************************************************************/

#endif /* LED_H_ */

