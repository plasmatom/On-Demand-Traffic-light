/*
 * timer.c
 *
 * Created: 8/9/2022 4:17:28 PM
 *  Author: Discovery
 */ 
#include "timer.h"

void timer_init(volatile uint8_t *timerTCCR)
{
	// this function sets the timer control register to normal mode
	/*
	take the address of the timer control register
	assign the value 0 in the register
	*/
	*timerTCCR = 0x00;
}
void timer_starting_value(volatile uint8_t *timerTCNT, uint8_t stratingValue)
{
	/*
	timer register
	this function will assign a starting value in the timer register
	the input must be in hexadecimal
	*/
	*timerTCNT = stratingValue;
}
uint8_t timer_set_prescaler(volatile uint8_t *timerTCCR, uint8_t mode)
{
	
	/*
	this function sets a prescaler for the timer
	takes an input the address for timer control register and the mode specified in the header file
	1-set the timer control register to 0
	2-then modifies the register to the specified mode
	if the entered mode is not correct the function will return PRESCALER_ERROR(1)
	else will return OK (0)
	*/
	
	*timerTCCR = 0x00;
	
	switch(mode)
	{
		case NO_CLOCK_SOURCE:
			break;
		case NO_PRESCALING:
			*timerTCCR = 0x01;
			break;
		case CLK_8_PRESCALER:
			*timerTCCR = 0x02;
			break;
		case CLK_64_PRESCALER:
			*timerTCCR = 0x03;
			break;
		case CLK_256_PRESCALER:
			*timerTCCR = 0x04;
			break;
		case CLK_1024_PRESCALER:
			*timerTCCR = 0x05;
			break;
		case EX_CLOCK_SOURCE_T0_F:
			*timerTCCR = 0x06;
			break;
		case  EX_CLOCK_SOURCE_T0_R:
			*timerTCCR = 0x07;
			break;
		default:
			return PRESCALER_ERROR;		
	}
	return OK;
}
void set_flag(volatile uint8_t *timerTIFR)
{
	/*
	this function sets the flag of the timer when it is raised
	the function takes the timer interrupt flag register as an input and modifies it
	by setting the first bit(0) (timer over flow flag) to 1
	*/
	*timerTIFR |= (1 << 0);
}
uint8_t timerControl(volatile uint8_t *timerTIFR, volatile uint8_t *timerTCCR,uint8_t prescaler,uint32_t numberOfOverFlows, uint8_t *timerTCNT, uint8_t startingValue)
{
	/*
	this function uses the other functions in this module to control the timer
	1- first it sets the prescaler and initializes the timer
	2- it sets the starting value of the timer
	3- it restarts the timer to a certain number of overflows 
	*/
	
	uint8_t error = timer_set_prescaler(timerTCCR, prescaler);
	
	if(error)
	{
		return error;
	}
	
	
	timer_starting_value(timerTCNT, startingValue);
	for(int i = 0; i < numberOfOverFlows; i++)
	{
		while ((*timerTIFR &( 1<<0 )) == 0);
		set_flag(timerTIFR);
	}
	return error;
}