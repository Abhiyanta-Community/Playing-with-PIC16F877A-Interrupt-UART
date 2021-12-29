#include <xc.h>
#define _XTAL_FREQ 20000000

void interrupt blink()
{
    if( INTCONbits.INTF == 1)
    {
         PORTB=0x02;
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
    INTCONbits.GIE = 1;
    INTCONbits.INTE = 1;
    INTCONbits.PEIE = 1;
    OPTION_REGbits.INTEDG = 0;
    TRISB1=0;
    TRISB2=0;
    TRISB3=0;
    TRISB4=0;
    TRISB5=0;
    PORTB =0x00;
    while(1)
    {
        PORTB=0x06;
        _delay(25000);
         PORTB=0x38;                
       _delay(25000);
       
    
       
    }    
}

