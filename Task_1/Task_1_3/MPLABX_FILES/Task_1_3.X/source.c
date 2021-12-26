#include <xc.h>
#define _XTAL_FREQ 200000000
unsigned char i=0;
void interrupt blink()
{
    if( INTCONbits.TMR0IF == 1)
    {     i++;}
       INTCONbits.TMR0IF = 0;
    }
    
void main()
{
    INTCONbits.GIE = 1;
    INTCONbits.TMR0IE = 1;
    INTCONbits.PEIE = 1;
    OPTION_REG = 0x07;
    TRISB0=1;
    TRISB1=0;
    TRISB2=0;
    TRISB3=0;
    TRISB4=0;
    TRISB5=0;
    PORTB =0x00;
    
    if(PORTBbits.RB0==1)
    while(1)
    {
        if(i==0)
        PORTB=0x00;
        if(i==1)
        PORTB=0x02;
        if(i==2)
        PORTB=0x04;
        if(i==3)
        PORTB=0x08;    
        if(i==4)
        PORTB=0x10;
        if(i==5)
        PORTB=0x20;
        if(i==6)
        PORTB=0x20;
        if(i==7)
        PORTB=0x10;
        if(i==8)
        PORTB=0x08;
        if(i==9)
        PORTB=0x04;
        if(i==10)
        PORTB=0x02;
        if(i==11)
            break;
    }    
}