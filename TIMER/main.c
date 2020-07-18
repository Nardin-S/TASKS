/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */


#include "timer.h"
#include "LED.h"
#include <avr/interrupt.h>

	extern Uint8  Counter_Initial_value ;
	extern Uint32 Num_OverFlow ;



int main (void)
{
	LED0_initial ();
	TIMER_Initial();
	GENERATE_DELAY(30);
	START_COUNTING();

	while(1)
	{

	}


}





/*
ISR (TIMER0_OVF_vect)
{
static Uint32 count =0 ;

count++;

if (count == Num_OverFlow)
{
	TCNT0 = Counter_Initial_value ;

	count = 0;

	LED0_Toggle (
	);


}*/
ISR (TIMER0_COMP_vect){

	static Uint32 count =0 ;

	count++;
if (count == Num_OverFlow)
{
	TCNT0 = Counter_Initial_value ;

	count = 0;

	LED0_Toggle ();
}}
