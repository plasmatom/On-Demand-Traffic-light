/*
 * dio.c
 *
 * Created: 8/1/2022 5:13:36 AM
 *  Author: Discovery
 */ 
#include "dio.h"

uint8_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	
	/*
	this function initializes the ports to output or input
	this function will take the pinNumber and portNumber and the direction wither input or output.
	and set the I/O pin to the direction specified.
	if portNumber is wrong it will return ADDRESS_ERROR(1)  	
	if the pinNumber largerThan 7  it will return PIN_ERROR(2)
	if not it will return OK(0)
	*/
	
	if(pinNumber > 7)
	{
		return PIN_ERROR;
	}
	
	switch(portNumber)
	{
		case PORT_A:
			if (direction == OUT)
				set_bit(pinNumber, &DDRA);
			else if (direction == IN)
				clear_bit(pinNumber, &DDRA);
			break;
		case PORT_B:
			if (direction == OUT)
				set_bit(pinNumber, &DDRB);
			else if (direction == IN)
				clear_bit(pinNumber, &DDRB);
			break;
		case PORT_C:
			if (direction == OUT)
				set_bit(pinNumber, &DDRC);
			else if (direction == IN)
				clear_bit(pinNumber, &DDRC);
			break;
		case PORT_D:
			if (direction == OUT)
				set_bit(pinNumber, &DDRD);
			else if (direction == IN)
				clear_bit(pinNumber, &DDRD);
			break;
		default:
			return ADDRESS_ERROR;
	}
	return OK;
}
uint8_t DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	
	/*
	this function will write to the pins.
	this function will take the pinNumber and portNumber and the value wither high or low.
	the in writes on the pin high or low.
	if portNumber is wrong it will return ADDRESS_ERROR(1)  	
	if the pinNumber largerThan 7  it will return PIN_ERROR(2)
	if not it will return OK(0)
	*/
	
	if(pinNumber > 7)
	{
		return PIN_ERROR;
	}
	
	switch(portNumber)
	{
		case PORT_A:
			if (value == HIGH)
				set_bit(pinNumber, &PORTA);
			else if (value == LOW)
				clear_bit(pinNumber, &PORTA);
			break;
		case PORT_B:
			if (value == HIGH)
				set_bit(pinNumber, &PORTB);
			else if (value == LOW)
				clear_bit(pinNumber, &PORTB);
			break;
		case PORT_C:
			if (value == HIGH)
				set_bit(pinNumber, &PORTC);
			else if (value == LOW)
				clear_bit(pinNumber, &PORTC);
			break;
		case PORT_D:
			if (value == HIGH)
				set_bit(pinNumber, &PORTD);
			else if (value == LOW)
				clear_bit(pinNumber, &PORTD);
			break;
		default:
			return ADDRESS_ERROR;
	}
	return OK;
}
uint8_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{
	
	/*
	this function will toggle the pin state.
	this function will take the pinNumber and portNumber and toggle value
	if portNumber is wrong it will return ADDRESS_ERROR(1)  	
	if the pinNumber largerThan 7  it will return PIN_ERROR(2)
	if not it will return OK(0)
	*/
	
	if(pinNumber > 7)
	{
		return PIN_ERROR;
	}
	
	switch(portNumber)
	{
		case PORT_A:
			flip_bit(pinNumber, &PORTA);
			break;
		case PORT_B:
			flip_bit(pinNumber, &PORTB);
			break;
		case PORT_C:
			flip_bit(pinNumber, &PORTC);
			break;
		case PORT_D:
			flip_bit(pinNumber, &PORTD);
			break;
		default:
			return ADDRESS_ERROR;
	}
	return OK;
}
uint8_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
	/*
	this function will read the pins
	if portNumber is wrong it will return ADDRESS_ERROR(1)  	
	if the pinNumber largerThan 7  it will return PIN_ERROR(2)
	if not it will return OK(0)
	*/
	if(pinNumber > 7)
	{
		return PIN_ERROR;
	}
	switch(portNumber)
	{
		case PORT_A:
			*value = (PINA & (1 << pinNumber) >> pinNumber);
			break;
		case PORT_B:
			*value = (PINB & (1 << pinNumber) >> pinNumber);
			break;
		case PORT_C:
			*value = (PINC & (1 << pinNumber) >> pinNumber);
			break;
		case PORT_D:
			*value = (PIND & (1 << pinNumber) >> pinNumber);
			break;
		default:
			return ADDRESS_ERROR;
	}
	return OK;
}