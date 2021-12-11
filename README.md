# Tr2-Task-Bin-Oct-2021

##This task will act as an Introduction to PIC16F877A with the help of Timers and Interrupts. 

*Task 1.1 Introduction with PIC Controller (13 Dec ‘21)

	*Introduction of device and understanding with the help of Datasheet
 		Refer to the datasheet of PIC16F87XA (where X represents a set of numbers and each set of numbers refers to a different IC). Try to understand why we will be using PIC16F877A IC. 
	*Interfacing Push Button and LEDs
		Interface a push button and five leds in such a way that when push button gets pressed at every 100 millisec the next LED gets turned on and the previous LED gets turned off and thus in 1sec all five LEDs blinks one by one. (Hint: Make separate user defined functions for monitoring push button and controlling LEDs)

*Task 1.2 Implementing Hardware Interrupts (19 Dec ‘21)

	*Getting started with Hardware Interrupts 
		Understand the Hardware(External) Interrupts available in PIC16F877A with the help of datasheet and list out the registers to be modified in order to setup External Interrupt. 
	*Implement a push button to generate Hardware Interrupt
		Modify the program to use the interrupt for triggering the LED pattern instead of continuously monitoring the Push Button. 



Task 1.3 Implementing Timer Interrupts  (24 Dec ‘21)
Getting started with Timers
Understand Timers specifications of PIC16F877A (preferred source Datasheet). List out the register which needs to be configured while using a Timer 1. 
Generating delays with timer interrupt
Modify the program to use the Timer Interrupts to toggle the LEDs instead of the builtin delay function. With this modification when push button gets pressed at every 100 millisec the next LED gets turned on and the previous LED gets turned off and thus in 1sec all five LEDs blinks one by one.

Extension Task (Optional) 
Interface an array of 3 LEDs that must be continuously toggling as 
1→2→3→3→2→1. 
Implement 2 push buttons to generate individual hardware interrupts to toggle the state of two different LEDs.
Generate 2 square waves of time period of 400ms and 200ms using only one interrupt i.e Timer 1 interrupt.
