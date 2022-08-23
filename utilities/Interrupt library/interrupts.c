/*
 * interrupts.c
 *
 * Created: 8/11/2022 7:43:46 PM
 *  Author: Discovery
 */ 
#include "interrupts.h"


void interrupt_enable()
{
	/*
	this function will initialize  the interrupt at pin2 port D 
	1-Set global interrupts, Set the I-bit in status register to 1
	2-Set the interrupt to falling edge
	3- Enable external interrupt request 0
	*/
	sei();
	MCUCR |= (1 << 1);
	GICR |= (1 << 6);
}