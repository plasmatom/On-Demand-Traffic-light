/*
 * manuplate.h
 *
 * Created: 8/9/2022 1:48:25 PM
 *  Author: Discovery
 */ 


#ifndef MANUPLATE_H_
#define MANUPLATE_H_
#include "../../utilities/types.h"

// function to set the bit to 1
void set_bit(uint8_t bitNumber,volatile uint8_t *Address);

// function to set the bit to 0
void clear_bit(uint8_t bitNumber,volatile uint8_t *Address);

// function to toggle the bit
void flip_bit(uint8_t bitNumber,volatile uint8_t *Address);


#endif /* MANUPLATE_H_ */