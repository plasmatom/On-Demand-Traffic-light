/*
 * timer.h
 *
 * Created: 8/9/2022 4:17:10 PM
 *  Author: Discovery
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../utilities/types.h"
#include "../../utilities/registers.h"

// prescaler errors
#define PRESCALER_ERROR  1
#define OK 0

// clock select modes
#define NO_CLOCK_SOURCE 'A'
#define NO_PRESCALING 'B'
#define CLK_8_PRESCALER 'C'
#define CLK_64_PRESCALER 'D'
#define CLK_256_PRESCALER 'E'
#define CLK_1024_PRESCALER 'F'
#define EX_CLOCK_SOURCE_T0_F 'G'
#define EX_CLOCK_SOURCE_T0_R 'H'




// functions to control the timers
void timer_init(volatile uint8_t *timerTCCR);
void timer_starting_value(volatile uint8_t *timerTCNT, uint8_t stratingValue);
uint8_t timer_set_prescaler(volatile uint8_t *timerTCCR, uint8_t mode);
void set_flag(volatile uint8_t *timerTIFR);
uint8_t timerControl(volatile uint8_t *timerTIFR, volatile uint8_t *timerTCCR,uint8_t prescaler,uint32_t numberOfOverFlows, uint8_t *timerTCNT, uint8_t startingValue);



#endif /* TIMER_H_ */