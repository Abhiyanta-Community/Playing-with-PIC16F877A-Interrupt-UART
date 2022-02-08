
**-Task_2_1**

* Our task_2_1 was about establishing a communication between the transmitter and reciever without using the inbuild pins.
* To handel the data received from the serial monitor we have matched the baud rate by sympling the tx pin using timer.
* To recive the data we have to control the pon according to start and stop condition, which is done by the hardware interrupt.
* Now using all this things we blink 3 LEDs where 1st LED will blink when you press 8 likewise 2nd when you press 1 and 3rd when you press 4.<br/> 

**-Task_2_2**
  
* Our task_2_2 was about UART using internal Hardware.
* For transmitting data we have used TXSTA register of PIC16F877A and for receiving data we have used RCSTA register of PIC16F877A.
* In TXSTA register we have setten TXEN and BRGH bits as 1 and UART as 0. 
* In RCSTA register we have setten SPEN bits as 1. We have define get() function for receiving data using flag bit RCIF, in this it reads 8bit data from the receive register and then again sets flag bit for next data.<br/>

**-Task_2_3**
  
* Our task_2_3 was about Communicating two PIC conrollers.
* From this we learnt how to communicate two MCUs using UART. Here, we have used two PICs : MCU1 for transmitting data and MCU2 for receiving data.
* In MCU1, we are transmitting state of PORTB where push buttons are available to MCU2 for controlling LEDs. In this we have setted PORTB as input and initially all are at off state but when push button is pressed it makes that PIN as on and so it's respective LED is on.
* In MCU2, we are receiving data of PORTB from MCU1 and as per that LEDs of MCU2 will respond respectively. Here we are receiving data using get() function which is continuously reading state of PORTB of MCU1 and so whenever any Pin is setted high that LED will glow. 
