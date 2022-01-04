#include <xc.h>
#define _XTAL_FREQ 20000000 //Frequency for oscillator

void interrupt blink()      //interrupt function pattern 
{
    if( INTCONbits.INTF == 1)   //condition to check interrupt flag
    {
         PORTB=0x02;		//pattern to blink leds one by one
        _delay(25000);
         PORTB=0x04;                
       _delay(25000);
        PORTB=0x08;                
       _delay(25000);
        PORTB=0x10;                
       _delay(25000);
        PORTB=0x20;                
       _delay(25000);
       PORTB=0x20;
        _delay(25000);
         PORTB=0x10;                
       _delay(25000);
        PORTB=0x08;                
       _delay(25000);
        PORTB=0x04;                
       _delay(25000);
        PORTB=0x02;                
       _delay(25000);
        }
       INTCONbits.INTF = 0;		
        }
    
void main()
{
    INTCONbits.GIE = 1;	//enabling global interrupt
    INTCONbits.INTE = 1;	//enabling external interrupt
    INTCONbits.PEIE = 1;	//enabling peripheral interrupt
    OPTION_REGbits.INTEDG = 0;	//enabling edge bit as rise edge
    TRISB1=0;	//defing 5 output ports for leds
    TRISB2=0;
    TRISB3=0;
    TRISB4=0;
    TRISB5=0;
    PORTB =0x00;	//turning all leds off
    while(1)		//endless loop with blinking pattern
    {
        PORTB=0x06;
        _delay(25000);
         PORTB=0x38;                
       _delay(25000);
       
    
       
    }    
}

