# MICROCONTROLLER (PIC16F8774A)

Our Task_1 was mainly about blinking the LEDs in a given sequence by burning the code in the microcontroller   
We simply divided our task in 3 parts they are
1. Task_1_1
2. Task_1_2
3. Task_1_3
**Task_1_1**
* Our task_1_1 was about introduction of device and understanding PIC16F87XA with the help of Datasheet. Here we are using PIC16F877A because it's having 44 pin, 8 Input channels, Data memory of 368(bytes), Interrupts 15, I/O ports A B C D E.
* Now using all this things we blink 5 LEDs one after the other in 1sec. 
  **Task_1_2**
* Our task_1_2 was about to generate Hardware Interrupt by implementing a push button. As we discussed above there are 15 types of Interrupts here we are using external interrupt at RB0.
* Which contains a series of LED blinking one by one when push button is pressed after execution of interrupt our main series again begins which blinks two and three LEDs continuously.
  **Task_1_3**
* Our task_1_3 was about generating delays with timer interrupt. Here we are using Internal Interrupt Timer0 for creating delay.
* We are giving delay of 100ms for blinking of every LEDs and so in 1sec all 5 LEDs blink one by one. In this we have used logic of count and whenever the interrupt occurs the count increases and LEDs glow one by one. 
