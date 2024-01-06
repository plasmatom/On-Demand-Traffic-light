# Traffic Control System for ATMega32A Microcontroller

This project implements a traffic control system using an ATMega32A microcontroller. The system manages traffic signals for both vehicles and pedestrians.

## Overview

The main functionality of the system involves controlling LED traffic signals for both vehicle and pedestrian traffic. The program defines an interrupt service routine (ISR) triggered by an external interrupt (EXT_INT_0). Upon interrupt, the system alternates between controlling traffic for vehicles and pedestrians.

## Main Functionality

The `main()` function initializes the application and continuously runs a loop to handle traffic signal switching between vehicles and pedestrians.

The ISR (`EXT_INT_0`) function is responsible for managing traffic signal changes based on the current traffic mode (`LEDId`). When in 'g' mode (representing vehicle traffic), the system switches traffic signals from red to green for vehicles and initiates a pedestrian stop signal. It then toggles yellow lights for a brief period, transitions pedestrian lights to green, and halts vehicle traffic. Finally, it alternates yellow lights again before reverting to the initial state for vehicle traffic.

Alternatively, when not in 'g' mode, the system handles pedestrian traffic, switching the lights accordingly.

## Components Used

- **ATMega32A Microcontroller**: Used to control and manage the traffic signals.
- **LEDs**: Green, red, and yellow LEDs used to represent different traffic signals.
- **Timers**: Utilized for controlling the timing of traffic signal changes.

## Hardware Setup

The project is designed for an ATMega32A microcontroller board connected to LED traffic lights and timers for signal timing control.

## Usage

This code snippet serves as a demonstration of the traffic control system's logic. Ensure proper hardware connections and setup before deploying it to the microcontroller.

## Note

This description provides an overview and requires integration with the specific microcontroller board, LEDs, and timers for proper functionality.

