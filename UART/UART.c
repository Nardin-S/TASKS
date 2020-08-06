/*
 * UART.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */


#include "UART.h"


void UART_InIT (void)
{
	Uint32 BR_VALUE = 0 ;  //save result of BR IN THAT variable

    DIO_SetPinDir(DIO_PORTD ,DIO_Pin0  ,DIO_Pin_INPUT );
	DIO_SetPinDir(DIO_PORTD ,DIO_Pin1  ,DIO_Pin_OUTPUT);

	UCSRB |= 0x18 ;    /*ENABLE Receiving w Transmit */
	UCSRC |= 0x85 ;      /* num of bits */

	BR_VALUE = (160000 / (96 * 16)) - 1   ; // Fosc = 16M , BR =9600

	UBRRL = BR_VALUE ;
}

void UART_TX_Byte (Uint8   transmitted_data)
{

	while (get_bit(UCSRA,5) == 0);
	UDR = transmitted_data ;
}


void UART_TX_String (Uint8* str )
{
	Uint8 i = 0 ;

	while( str[i] !=  '\0')
	{
		UART_TX_Byte (str[i] );
		i++;

	}

}


Uint8 UART_RX_Byte (void)
{
	Uint8 data = 0 ;

	while(get_bit(UCSRA,7) == 0);

	data = UDR ;

	return  data ;

}



void UART_RX_String (void)
{
	SREG  |= 0x80 ;
	UCSRB |= 0x80 ;

}


ISR (USART_RXC_vect)
{
	Uint8* str ;
	int i = 0 ;
/*	while (UDR !=  '\0')
	{
		str[i] = UDR ;
		i++ ;
	}*/
	while( UDR !=  '\0')
	{
		str[i] = UART_RX_Byte ();
		i++;
	}
}

