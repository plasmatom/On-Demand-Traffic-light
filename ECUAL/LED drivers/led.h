/*
 * led.h
 *
 * Created: 8/1/2022 7:48:01 AM
 *  Author: Discovery
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO drivers/dio.h"

// traffic light macros

// pedestrian and car ports
#define CAR_TRAFFIC PORT_A
#define PEDESTRIAN_TRAFFIC PORT_B

//LED pens
#define RED_LED PIN_0
#define YEllOW_LED PIN_1
#define GREEN_LED PIN_2



// functions to control the traffic lights
uint8_t LED_init(uint8_t pinNumber, uint8_t portNumber);
uint8_t LED_on(uint8_t pinNumber, uint8_t pertNumber);
uint8_t LED_off(uint8_t pinNumber, uint8_t portNumber);
uint8_t LED_toggel(uint8_t pinNumber, uint8_t portNumber);

#endif /* LED_H_ */