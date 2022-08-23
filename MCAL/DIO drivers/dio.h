/*
 * dio.h
 *
 * Created: 8/1/2022 5:13:11 AM
 *  Author: Discovery
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../utilities/registers.h"
#include "../../utilities/bit manupliation/manipulate.h"
 /************************************************************************/
 /* DRIVER MACROS                                                         */
 /************************************************************************/
 // DRIVERs Ports MACROS
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//DRIVERS pins MACROS
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2

// DRIVER Direction MACROS
#define OUT 1
#define IN 0

// DRIVERs Value MACROS
#define HIGH 1
#define LOW 0

// DRIVERs Error handling MACROS
#define PIN_ERROR 2
#define ADDRESS_ERROR  1
#define OK 0

// Driver function prototypes
uint8_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);
uint8_t DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);
uint8_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber);
uint8_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);



#endif /* DIO_H_ */