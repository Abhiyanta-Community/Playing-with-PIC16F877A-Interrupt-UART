/*
 * File:   task_1_1.c
 * Author: Arth Gandhi
 *
 * Created on 12 December, 2021, 11:50 PM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000

void main()
{
    TRISB0=0;
    TRISB1=0;
    TRISB2=0;
    TRISB3=0;
    TRISB4=0;
    TRISB5=1;
    
    while(1)
    {
        if(PORTBbits.RB5 == 1)
        {
        PORTB=0x01;
        _delay(25000);
         PORTB=0x02;                
       _delay(25000);
        PORTB=0x04;                
       _delay(25000);
        PORTB=0x08;                
       _delay(25000);
        PORTB=0x10;                
       _delay(25000);
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
        PORTB=0x00;    
        }
    
}

