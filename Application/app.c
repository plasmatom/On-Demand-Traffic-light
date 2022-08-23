/*
 * app.c
 *
 * Created: 8/11/2022 6:56:07 PM
 *  Author: Discovery
 */ 
#include "app.h"

void app_intit()
{
	/*
	this function initializes the app
	*/
	
	
	//initializing cars traffic light LEDs
	LED_init(RED_LED, CAR_TRAFFIC);
	LED_init(YEllOW_LED, CAR_TRAFFIC);
	LED_init(GREEN_LED, CAR_TRAFFIC);
	
	//initializing pedestrian traffic light LEDs
	LED_init(RED_LED, PEDESTRIAN_TRAFFIC);
	LED_init(YEllOW_LED, PEDESTRIAN_TRAFFIC);
	LED_init(GREEN_LED, PEDESTRIAN_TRAFFIC);
	
	// enabling Interrupts
	interrupt_enable();
	
}
void app_start(uint8_t *LEDId)
{
	/*
	this function starts the app
	and modifies the LEDId variables to see at which stage the app is
	*/
	
	LED_on(RED_LED, PEDESTRIAN_TRAFFIC);
	// turn on the cars traffic green light
	*LEDId = 'g'; 
	LED_on(GREEN_LED, CAR_TRAFFIC);
	timerControl(&TIFR, &TCCR0, CLK_1024_PRESCALER, 20, &TCNT0, 0xF4);
	
	//toggle the yellow light
	for(uint8_t i = 0; i < 5; i++)
	{
		LED_toggel(YEllOW_LED, CAR_TRAFFIC);
		timerControl(&TIFR, &TCCR0, CLK_1024_PRESCALER, 4, &TCNT0, 0x00);
		
	}
	LED_off(YEllOW_LED, CAR_TRAFFIC);
	LED_off(GREEN_LED, CAR_TRAFFIC);
	
	
	// turn on the cars traffic red light
	*LEDId = 'r';
	LED_on(RED_LED, CAR_TRAFFIC);
	timerControl(&TIFR, &TCCR0, CLK_1024_PRESCALER, 20, &TCNT0, 0xF4);
	
	//toggle the yellow light
	for(uint8_t i = 0; i < 5; i++)
	{
		LED_toggel(YEllOW_LED, CAR_TRAFFIC);
		timerControl(&TIFR, &TCCR0, CLK_1024_PRESCALER, 4, &TCNT0, 0x00);
		
	}
	LED_off(YEllOW_LED, CAR_TRAFFIC);
	LED_off(RED_LED, CAR_TRAFFIC);
}