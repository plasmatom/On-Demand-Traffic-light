/*
 * app.h
 *
 * Created: 8/11/2022 6:55:44 PM
 *  Author: Discovery
 */ 


#ifndef APP_H_
#define APP_H_

// Includes to be used
#include "../ECUAL/LED drivers/led.h"
#include "../ECUAL/BUTTON drivers/button.h"
#include "../utilities/Timer/timer.h"
#include "../utilities/Interrupt library/interrupts.h"

// APP functions
void app_intit();
void app_start(uint8_t *LEDId);

#endif /* APP_H_ */