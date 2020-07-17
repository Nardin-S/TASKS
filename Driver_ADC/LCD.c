/*
 * LCD.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#define F_CPU 16000000
#include "LCD.h"
#include <util/delay.h>

void LCD_initial (void)
{
#if LCD_Mode == 8

	void DIO_SetPinDir(LCD_8bit_CommandPort , LCD_Rs_Pin , DIO_Pin_OUTPUT );

	void DIO_SetPinDir(LCD_8bit_CommandPort , LCD_RW_Pin , DIO_Pin_OUTPUT );

	void DIO_SetPinDir(LCD_8bit_CommandPort , LCD_E_Pin , DIO_Pin_OUTPUT );

	void DIO_SetPortDir(LCD_8bit_DataPort, DIO_Pin_OUTPUT);

	_delay_ms(100);

	LCD_WriteCmd(0x38);  //Initialize 8bit Mode , 5 X 7  Matrix
	LCD_WriteCmd(0x0E);  // cursor blinking
	LCD_WriteCmd(0x01);  // clear display screen

	_delay_ms(20);

	LCD_WriteCmd(0x06);  // Increment cursor to right

	_delay_ms(5);

#elif LCD_Mode == 4

	//COMMANDS
	 DIO_SetPinDir(LCD_4bit_CommandPort , LCD_Rs_Pin , DIO_Pin_OUTPUT );

	 DIO_SetPinDir(LCD_4bit_CommandPort , LCD_RW_Pin , DIO_Pin_OUTPUT );

	 DIO_SetPinDir(LCD_4bit_CommandPort , LCD_E_Pin , DIO_Pin_OUTPUT );

	//DATA
	 DIO_SetPinDir(LCD_4bit_DataPort , LCD_D4  , DIO_Pin_OUTPUT );

	 DIO_SetPinDir(LCD_4bit_DataPort , LCD_D5  , DIO_Pin_OUTPUT );

	 DIO_SetPinDir(LCD_4bit_DataPort , LCD_D6  , DIO_Pin_OUTPUT );

	 DIO_SetPinDir(LCD_4bit_DataPort , LCD_D7  , DIO_Pin_OUTPUT );

	_delay_ms(100);


	// FOR 4Bit Mode initialization
	LCD_WriteCmd(0x33);
	LCD_WriteCmd(0x32);
	LCD_WriteCmd(0x28);

	LCD_WriteCmd(0x0C);  //Displayon,Cursor off
	LCD_WriteCmd(0x01); // clear screen

	LCD_WriteCmd(0x06); // increment cursor
	LCD_WriteCmd(0x02); //Return home

	_delay_ms(5);

#endif
}

void LCD_WriteCmd (Uint8 cmd)
{
#if LCD_Mode == 8
      DIO_WritePin(LCD_8bit_CommandPort , LCD_Rs_Pin , DIO_Pin_LOW );
      DIO_WritePin(LCD_8bit_CommandPort , LCD_E_Pin  , DIO_Pin_LOW );
      DIO_WritePin(LCD_8bit_CommandPort , LCD_RW_Pin , DIO_Pin_LOW );

      DIO_WritePort( LCD_8bit_DataPort , cmd);

    	DIO_WritePin(LCD_8bit_CommandPort  ,LCD_E_Pin, DIO_Pin_High);
    	_delay_ms(3);
    	DIO_WritePin( LCD_8bit_CommandPort  ,LCD_E_Pin, DIO_Pin_LOW);


	_delay_ms(5);

#elif LCD_Mode == 4

      DIO_WritePin(LCD_4bit_CommandPort , LCD_Rs_Pin , DIO_Pin_LOW );
      DIO_WritePin(LCD_4bit_CommandPort , LCD_E_Pin  , DIO_Pin_LOW );
      DIO_WritePin(LCD_4bit_CommandPort , LCD_RW_Pin , DIO_Pin_LOW );

      // han2el el command 3la mareteen
      PORTA = (cmd & 0xF0) | (PORTA & 0x0F);      // a5adna el higher part

 	 DIO_WritePin( LCD_4bit_CommandPort ,LCD_E_Pin, DIO_Pin_High);
 		_delay_ms(3);
    DIO_WritePin( LCD_4bit_CommandPort ,LCD_E_Pin, DIO_Pin_LOW);

  	PORTA = (cmd << 4) | (PORTA & 0x0F);    // w keda a5adna el lower part

	 DIO_WritePin( LCD_4bit_CommandPort ,LCD_E_Pin, DIO_Pin_High);
		_delay_ms(1);
  	 DIO_WritePin( LCD_4bit_CommandPort ,LCD_E_Pin, DIO_Pin_LOW);

  	_delay_ms(5);

#endif
}

void LCD_WriteChar (Uint8 data)
{
#if LCD_Mode == 8

    DIO_WritePin(LCD_8bit_CommandPort , LCD_Rs_Pin , DIO_Pin_High);
    DIO_WritePin(LCD_8bit_CommandPort , LCD_E_Pin  , DIO_Pin_LOW );
    DIO_WritePin(LCD_8bit_CommandPort , LCD_RW_Pin , DIO_Pin_LOW );

    DIO_WritePort( LCD_4bit_DataPort , data );

  	DIO_WritePin(LCD_8bit_CommandPort  ,LCD_E_Pin, DIO_Pin_High);
  	_delay_ms(3);
  	DIO_WritePin( LCD_8bit_CommandPort  ,LCD_E_Pin, DIO_Pin_LOW);

	_delay_ms(5);

#elif LCD_Mode == 4

	 DIO_WritePin(LCD_4bit_CommandPort , LCD_Rs_Pin , DIO_Pin_High);
	 DIO_WritePin(LCD_4bit_CommandPort , LCD_E_Pin  , DIO_Pin_LOW );
	 DIO_WritePin(LCD_4bit_CommandPort , LCD_RW_Pin , DIO_Pin_LOW );

	 PORTA = (data & 0xF0);

	  	DIO_WritePin( LCD_4bit_CommandPort ,LCD_E_Pin,DIO_Pin_High);
	  	_delay_ms(3);
	  	DIO_WritePin( LCD_4bit_CommandPort ,LCD_E_Pin, DIO_Pin_LOW);

	 PORTA = (data << 4 );

	 DIO_WritePin( LCD_4bit_CommandPort ,LCD_E_Pin, DIO_Pin_High);
		_delay_ms(100);
   	 DIO_WritePin( LCD_4bit_CommandPort ,LCD_E_Pin, DIO_Pin_LOW);

   	_delay_ms(2);
#endif
}

void LCD_WriteString (Uint8* str)    //address awel char.
{
   Uint8 i = 0 ;
   while ( str[i] != '\0' )
   {

	   LCD_WriteChar (str[i]);
	   i++;
   }

}

void LCD_GOTO (Uint8 row , Uint8 column)
{

	Uint8 Positions[2] = {0x80 , 0xC0};

	LCD_WriteCmd(Positions[row]+column);

}

void LCD_Clear (void)
{
	LCD_WriteCmd(0x01);
}

void LCD_WriteInteger (Sint32 integer){

	Uint8 TheDigit , digit_pos= 1 ;

	if (integer < 0 ){
			LCD_WriteChar(45);
			integer = -integer ;
	}

	Sint32 val = integer ;

	while (val ){

		val = val /10 ;
		digit_pos = digit_pos * 10 ;

	}

	while (digit_pos > 1){

		digit_pos = digit_pos /10 ;

		TheDigit = integer / digit_pos ;

	LCD_WriteChar(TheDigit + 48);
	integer = integer % digit_pos ;
}



}
