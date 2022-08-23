/*
 * interrupts.h
 *
 * Created: 8/10/2022 4:20:07 PM
 *  Author: Discovery
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include "../../utilities/registers.h"

/************************************************************************/
/* Interrupt vectors                                                     */
/************************************************************************/

//External interrupt vectors
//External interrupt request 0
#define EXT_INT_0 __vector_1
//External interrupt request 1
#define EXT_INT_1 __vector_2
//External interrupt request 2
#define EXT_INT_2 __vector_3

//Set global interrupts, Set the I-bit in status register to 1
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

//Clear global interrupts, Set the I-bit in status register to 0
#define cli() __asm__ __volatile__ ("cli" ::: "memory")


#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)


// function to enable interrupt on INT0
void interrupt_enable();

#endif /* INTERRUPTS_H_ */