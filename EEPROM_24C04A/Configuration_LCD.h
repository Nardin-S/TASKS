/*
 * Configuration_LCD.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */


// 4 bit Mode OR 8 bit Mode

#ifndef CONFIGURATION_LCD_H_
#define CONFIGURATION_LCD_H_

#include "DIO.h"

#define LCD_Mode  4   //Edited to be 4 in 4BIT MODE

/****************** LCD in 8 Bit Mode *********************/
#define LCD_8bit_CommandPort  DIO_PORTB
#define LCD_8bit_DataPort     DIO_PORTA

/****************** LCD in 4 Bit Mode *********************/
#define LCD_4bit_CommandPort  DIO_PORTB    // ayan kan el connections 3andel f el CONFIGURATION
#define LCD_4bit_DataPort     DIO_PORTA

/************ configure Pins ***************/
#define LCD_Rs_Pin  DIO_Pin1
#define LCD_RW_Pin  DIO_Pin2
#define LCD_E_Pin   DIO_Pin3

#define LCD_D0  DIO_Pin0
#define LCD_D1  DIO_Pin1
#define LCD_D2  DIO_Pin2
#define LCD_D3  DIO_Pin3
#define LCD_D4  DIO_Pin4
#define LCD_D5  DIO_Pin5
#define LCD_D6  DIO_Pin6
#define LCD_D7  DIO_Pin7


#endif /* CONFIGURATION_LCD_H_ */



