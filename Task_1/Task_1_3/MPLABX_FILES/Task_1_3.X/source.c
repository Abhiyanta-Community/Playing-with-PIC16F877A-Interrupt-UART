#include <xc.h>
#define _XTAL_FREQ 200000000 //Frequency for oscillator
unsigned char i=0;   //global variable i
void interrupt blink()  //defing interrupt function
{
    if( INTCONbits.TMR0IF == 1)   //checking when timer flag becomes 1
    {     i++;}            //incrementing value of i
       INTCONbits.TMR0IF = 0;      //clearing timer flag
    }
    
void main()
{
    INTCONbits.GIE = 1;	//enabling global interrupt
    INTCONbits.TMR0IE = 1;	//enabling timer 0 overflow interrupt
    INTCONbits.PEIE = 1;	//enabling peripheral interrupt
    OPTION_REG = 0x07;	//assigning PS2,PS1,PS0 as 1 for prescaler rate 256
    TRISB0=1;	//defing 1 input port for push-button
    TRISB1=0;	//defing 5 output ports for leds
    TRISB2=0;
    TRISB3=0;
    TRISB4=0;
    TRISB5=0;
    PORTB =0x00;	//turning all leds off
    
    if(PORTBbits.RB0==1)	//condition to check when push-button is pressed
    while(1)			//endless loop for blinking in pattern
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
            break;		//after pattern completes loop stops
    }    
}