/*
 * button.c
 *
 * Created: 8/4/2022 11:15:06 AM
 *  Author: Discovery
 */ 
#include "button.h"

uint8_t BUTTON_init(uint8_t pinNumber, uint8_t portNumber)
{
	/*
	this function will take the button pin number and port number and initialize it 
	*/
	return DIO_init(pinNumber, portNumber, IN);
}