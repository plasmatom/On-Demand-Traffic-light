/*
 * Project 1.c
 * This project will experiment with Led and buttons
 * Created: 7/31/2022 1:22:06 AM
 * Author: Discovery
 */ 



#include "Application/app.h"

uint8_t LEDId = 'r';
int main(void)
{
	
	app_intit();
	
    while (1) 
    {
		app_start(&LEDId);
	}
}

ISR(EXT_INT_0)
{
	/*
	this is the interrupt function
	*/
	
	if(LEDId == 'g')
	{
		LED_on(GREEN_LED, CAR_TRAFFIC);
		LED_on(RED_LED, PEDESTRIAN_TRAFFIC);
		for(uint8_t i = 0; i < 5; i++)
		{
			LED_toggel(YEllOW_LED, CAR_TRAFFIC);
			LED_toggel(YEllOW_LED, PEDESTRIAN_TRAFFIC);
			timerControl(&TIFR, &TCCR0, CLK_1024_PRESCALER, 4, &TCNT0, 0x00);
			
		}
		LED_off(YEllOW_LED, CAR_TRAFFIC);
		LED_off(YEllOW_LED, PEDESTRIAN_TRAFFIC);
		LED_off(GREEN_LED, CAR_TRAFFIC);
		LED_off(RED_LED, PEDESTRIAN_TRAFFIC);
		
		
		LED_on(GREEN_LED, PEDESTRIAN_TRAFFIC);
		LED_on(RED_LED, CAR_TRAFFIC);
		timerControl(&TIFR, &TCCR0, CLK_1024_PRESCALER, 20, &TCNT0, 0xF4);
		
		
		for(uint8_t i = 0; i < 5; i++)
		{
			LED_toggel(YEllOW_LED, CAR_TRAFFIC);
			LED_toggel(YEllOW_LED, PEDESTRIAN_TRAFFIC);
			timerControl(&TIFR, &TCCR0, CLK_1024_PRESCALER, 4, &TCNT0, 0x00);
			
		}
		LED_off(GREEN_LED, PEDESTRIAN_TRAFFIC);
		LED_off(RED_LED, CAR_TRAFFIC);
		LED_off(YEllOW_LED, CAR_TRAFFIC);
		LED_off(YEllOW_LED, PEDESTRIAN_TRAFFIC);
		LED_on(GREEN_LED, CAR_TRAFFIC);
		LED_on(RED_LED, PEDESTRIAN_TRAFFIC);
		
	}
	
	else
	{
		LED_on(GREEN_LED, PEDESTRIAN_TRAFFIC);
		LED_off(RED_LED, PEDESTRIAN_TRAFFIC);
		timerControl(&TIFR, &TCCR0, CLK_1024_PRESCALER, 20, &TCNT0, 0xF4);
		
		for(uint8_t i = 0; i < 5; i++)
		{
			LED_toggel(YEllOW_LED, CAR_TRAFFIC);
			LED_toggel(YEllOW_LED, PEDESTRIAN_TRAFFIC);
			timerControl(&TIFR, &TCCR0, CLK_1024_PRESCALER, 4, &TCNT0, 0x00);
			
		}
		LED_off(GREEN_LED, PEDESTRIAN_TRAFFIC);
		LED_off(RED_LED, CAR_TRAFFIC);
		LED_off(YEllOW_LED, CAR_TRAFFIC);
		LED_off(YEllOW_LED, PEDESTRIAN_TRAFFIC);
		LED_on(GREEN_LED, CAR_TRAFFIC);
		LED_on(RED_LED, PEDESTRIAN_TRAFFIC);
	}
	asm volatile ("  jmp 0");
}