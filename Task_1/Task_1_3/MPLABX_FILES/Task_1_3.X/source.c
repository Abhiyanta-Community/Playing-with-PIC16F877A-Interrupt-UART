#include <xc.h>
#define _XTAL_FREQ 20000000 //Frequency for oscillator
unsigned char i=0;   //global variable i
void interrupt blink()  //defing interrupt function
{
    if( TMR1IF == 1)   //checking when timer flag becomes 1
    {     i++;}//incrementing value of i
         
        TMR1IF = 0;   //clearing timer flag
        TMR1H=0xDC;    // count for 100ms delay
        TMR1L=0x0B;
}   
void main()
{
    INTCONbits.GIE = 1;	//enabling global interrupt
    INTCONbits.PEIE = 1;	//enabling peripheral interrupt
    TMR1IE= 1;	//enabling timer 1 interrupt
    T1CONbits.T1CKPS1=1;	
    T1CONbits.T1CKPS0=1;    //assigning  prescaler rate 8
    T1CONbits.TMR1CS=0;     // selecting internal oscillator  
    
    TMR1H=0xDC;   
    TMR1L=0x0B;
     //assigning initial count value for 100ms delay = 65536-62500=3036(decimal)=101111011100(binary)=0x0BDC(hex)
   
    TRISB0=1;	//defing 1 input port for push-button
    TRISB1=0;	//defing 5 output ports for leds
    TRISB2=0;
    TRISB3=0;
    TRISB4=0;
    TRISB5=0;
    PORTB =0x00;	//turning all leds off
    T1CONbits.TMR1ON=1; //starting timer 1
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