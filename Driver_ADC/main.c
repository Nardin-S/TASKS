/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */


#define F_CPU  16000000
#include "LCD.h"
#include "Keypad.h"
#include "Temp_Sensor.h"
#include <util/delay.h>

#define SIZE 4
//#define NULL (void*(0))

int main (void) {


	const Uint8 PassWord[] ={1 , 2 , 3 , 4 } ;
	Uint8 INPUT_PASS[SIZE] ;
	Uint8 i =0;
	Uint8 Flag = 0;
	Uint8 Temp = 0;

	LCD_initial();
	KEYPAD_Initial ();
    TempSensor_Initial();

	while(1)
{
		for (i = 0 ; i < SIZE ; i++)
			{

			INPUT_PASS[i] = KEYPAD_GetValue();

				if(INPUT_PASS[i])
				{
					LCD_WriteChar('*');
				}

			}

		for (i=0 ; i <SIZE  ; i++)
		{
			if(INPUT_PASS[i] == PassWord[i])
			Flag = 0 ;
			else
			{
				 Flag= 1;
	         	 LCD_Clear ();
				 Uint8 Incorrect_Case[] = "incorrect";
				 LCD_WriteString(Incorrect_Case);
				 LCD_Clear ();
				 break;
			}
		}
		 if(Flag == 0){
			 LCD_Clear ();
			 Uint8 Correct_Case[] = "WELCOME!";
			 LCD_WriteString(Correct_Case);
			 TempSensor_Read(&Temp);
			 LCD_Clear();
			 LCD_WriteInteger(Temp);
		 }




}
}

