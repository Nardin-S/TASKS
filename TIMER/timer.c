/*
 * timer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */


#include "timer.h"
#include "BitMath.h"

#define Fosc_in_MEGA        16
#define PRESCALER           1024
#define Desired_Delay       0.01  //10ms
#define Register_Capacity   256

/*static*/ Uint8  Counter_Initial_value =0 ;
/*static */Uint32 Num_OverFlow = 0 ;


void TIMER_Initial(void)
{
/***** NORMAL MODE *******/
	TCCR0 |= 0x00 ;

	TIMSK |= 0x02 ;

	SREG  |= 0x80 ;
/***** CTC MODE ********/
	TCCR0 |= 0x08 ;



}

void START_COUNTING(void)
{
	//START TIMER WITH PRESCALER 1024

	TCCR0 |= 0x05 ;

}

void STOP_COUNTING(void)
{

	clr_bit(TCCR0,0);
	clr_bit(TCCR0,1);
	clr_bit(TCCR0,2);
}


//static Uint32 Num_OverFlow = 0 ;   // Global variable , it will be used by ISR (another function)


void GENERATE_DELAY(Uint32 delay_value_ms)
{
/*
	Uint32 Tick_Time_us   = PRESCALER/Fosc_in_MEGA ;

	Uint32 Ticks_number = (delay_value_ms*1000) / Tick_Time_us ;

	Num_OverFlow = Ticks_number /  Register_Capacity ;

	Counter_Initial_value = Register_Capacity - (Ticks_number % Register_Capacity) ;   //Register_Capacity - ((float)( Ticks_number /  Register_Capacity) - Num_OverFlow ) * Register_Capacity ;

	TCNT0 = Counter_Initial_value ;

	Num_OverFlow ++ ;
	*/
	/**** CTC MODE ******/

	Uint32 Tick_Time_us   = PRESCALER/Fosc_in_MEGA ;

	Uint32 Ticks_number = (delay_value_ms*1000) / Tick_Time_us ;

	TCNT0 = Counter_Initial_value ;
	OCR0 = Ticks_number - 0x01 ;

	//Num_OverFlow =
	if (TCNT0 == OCR0)
		Num_OverFlow++;


}

/*	ISR(){


}*/








