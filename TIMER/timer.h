/*
 * timer.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "ATmega32_Registers.h"


void TIMER_Initial(void);

void START_COUNTING(void);

void STOP_COUNTING(void);

void GENERATE_DELAY(Uint32 delay_value_ms);

#endif /* TIMER_H_ */
