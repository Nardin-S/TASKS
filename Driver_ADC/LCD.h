/*
 * LCD.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef LCD_H_
#define LCD_H_

#include "Configuration_LCD.h"
#include <util/delay.h>

void LCD_initial(void);

void LCD_WriteCmd(Uint8 cmd);

void LCD_WriteChar(Uint8 data);

void LCD_WriteString (Uint8* str);    //address awel char.

void LCD_GOTO (Uint8 row , Uint8 column);

void LCD_Clear (void);

void LCD_WriteInteger (Sint32 integer);    // task  //

/********************************************************************************/

#endif /* LCD_H_ */

