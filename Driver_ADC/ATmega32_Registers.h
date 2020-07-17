/*
 * ATmega32_Registers.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_

#include "STD.h"

/**************************************************** External REGISTERS *************************************************************/

/************************ ADC REGISTERS ************************************/

#define ADMUX      (*(volatile Uint8*)(0x27))

#define ADCSRA     (*(volatile Uint8*)(0x26))

#define ADCH       (*(volatile Uint8*)(0x25))

#define ADCL       (*(volatile Uint8*)(0x24))

#define ADC_adjust (*(volatile Uint16*)(0x24))

#define SFIOR      (*(volatile uint8 *)(0x50))



/********Interrupts *********/

#define SREG   (*(volatile Uint8*)(0x5F))

#define GICR   (*(volatile Uint8*)(0x5B))

#define GIFR   (*(volatile Uint8*)(0x5A))     // FLAG INTERRUPT "AUTOMATICALLY"

#define MCUCR  (*(volatile Uint8*)(0x55))   //ISC01 ISC00 --> High OR Low OR rising_edge OR falling_edge

#define MCUCSR (*(volatile Uint8*)(0x54))    // ISC02 0 INT2 FALLINGEDGE    ISC02 1 INT2 RaisingEDGE



/********************* DIO REGISTERS *******************/

/* __PORT A __ */

#define DDRA  (*(volatile Uint8*)(0x3A))
#define PORTA (*(volatile Uint8*)(0x3B))
#define PINA  (*(volatile Uint8*)(0x39))

/* __PORT B __ */

#define DDRB (*(volatile Uint8*)(0x37))
#define PORTB (*(volatile Uint8*)(0x38))
#define PINB (*(volatile Uint8*)(0x36))

/* __PORT C __ */

#define DDRC (*(volatile Uint8*)(0x34))
#define PORTC (*(volatile Uint8*)(0x35))
#define PINC (*(volatile Uint8*)(0x33))

/* __PORT D __ */

#define DDRD (*(volatile Uint8*)(0x31))
#define PORTD (*(volatile Uint8*)(0x32))
#define PIND (*(volatile Uint8*)(0x30))

#endif /* ATMEGA32_REGISTERS_H_ */
