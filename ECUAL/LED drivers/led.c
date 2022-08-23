/*
 * led.c
 *
 * Created: 8/1/2022 7:47:41 AM
 *  Author: Discovery
 */ 
#include "led.h"

uint8_t LED_init(uint8_t pinNumber, uint8_t portNumber)
{
	
	/*
	this function will initialize the LED
	it takes the pinNumber of the LED
	and the port number
	*/
	return DIO_init(pinNumber, portNumber, OUT);
}

uint8_t LED_on(uint8_t pinNumber, uint8_t portNumber)
{
	/*
	this function will turn on the LED
	it takes the pinNumber of the LED
	and the port number
	*/
	return DIO_write(pinNumber, portNumber, HIGH);
}

uint8_t LED_off(uint8_t pinNumber, uint8_t portNumber)
{
	/*
	this function will turn off the LED
	it takes the pinNumber of the LED
	and the port number
	*/
	return DIO_write(pinNumber, portNumber, LOW);
}

uint8_t LED_toggel(uint8_t pinNumber, uint8_t portNumber)
{
	/*
	this function will toggle the LED
	it takes the pinNumber of the LED
	and the port number
	*/
	return DIO_toggle(pinNumber, portNumber);	
}