
#include <xc.h>
#define _XTAL_FREQ 20000000   //Frequency for oscillator

void main()
{
    TRISB0=0;   //defing 5 output ports for leds
    TRISB1=0;
    TRISB2=0;
    TRISB3=0;
    TRISB4=0;
    TRISB5=1;  //defing 1 input port for push-button
    
    while(1)   
    {
        if(PORTBbits.RB5 == 1)  //condition to check when push-button is pressed
        {
        PORTB=0x01;   //glowing 1st led
        _delay(25000);   // delay for led
         PORTB=0x02;  //glowing 2nd led                
       _delay(25000); 	// delay for led
        PORTB=0x04;   //glowing 3rd led             
       _delay(25000);	// delay for led
        PORTB=0x08;  //glowing 4th led              
       _delay(25000);	// delay for led
        PORTB=0x10;  //glowing 5th led              
       _delay(25000);	// delay for led
        PORTB=0x10;
       _delay(25000);
        PORTB=0x08;
       _delay(25000);
       PORTB=0x04;
        _delay(25000);
         PORTB=0x02;                
       _delay(25000);
        PORTB=0x01;                
       _delay(25000);
        }
        else
        PORTB=0x00;    //if push-button is not pressed all leds off
        }
    
}

