/*
 * manupilate.c
 *
 * Created: 8/9/2022 1:48:48 PM
 *  Author: Discovery
 */ 
#include "manipulate.h"

void set_bit(uint8_t bitNumber,volatile uint8_t *Address)
{
	/*
	this function will take port address and pin number then set that bit to 1
	*/
	*Address |= (1 << bitNumber);
}


void clear_bit(uint8_t bitNumber,volatile uint8_t *Address)
{
	/*
	this function will take port address and pin number then set that bit to 0
	*/
	*Address &= ~(1 << bitNumber);
}


void flip_bit(uint8_t bitNumber,volatile uint8_t *Address)
{
	/*
	this function will take port address and pin number then flip this bit from 0 to 1 and from 1 to 0
	*/
	*Address ^= (1 << bitNumber);
}