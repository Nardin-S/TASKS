/*
 * BitMath.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef BITMATH_H_
#define BITMATH_H_


#define Set_bit(byte,bit)  (byte |= ( 1 << bit))
#define clr_bit(byte,bit)  (byte &= ~(1<<bit))
#define toggle(byte,bit)  (byte ^= (1<<bit))
#define get_bit(byte,bit) ((byte>>bit) & 1)


#endif /* BITMATH_H_ */
