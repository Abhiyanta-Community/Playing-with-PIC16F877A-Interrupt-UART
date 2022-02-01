#include <xc.h>
#define _XTAL_FREQ 20000000 //Frequency for oscillator
signed char c[10];
void interrupt blink()      //interrupt function pattern 
{
    if( INTCONbits.INTF == 1)   //condition to check interrupt flag
    {   int i;
        int g;
        TMR0=126;
       
        c[0]=0;
            INTCONbits.TMR0IE=1;
         if( TMR0IF == 1)   //checking when timer flag becomes 1
    { 
            for (i=8;i>0;i--)
        
        {
                
            c[i]=PORTBbits.RB0;
           // INTCONbits.TMR0IE=0;
            
        }
        c[9]=1;
        
         
        TMR0IF = 0;  
         }
        
        
        if (c[6]==1)
    {
         PORTB=0x02;		//pattern to blink leds one by one
        _delay(25000);
    }
    else if(c[8]==1)
    {
    PORTB=0x04;                
       _delay(25000);
    }
    else if(c[5]==1)
    {
    PORTB=0x08;                
       _delay(25000);
    }
    /*
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
     */ 
       INTCONbits.INTF = 0;		
    }
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
    TRISB0=1;
    TRISC0=1;
    OPTION_REGbits.PS2=0;
    OPTION_REGbits.PS1=0;
    OPTION_REGbits.PS0=1;       //assigning prescaler as 4
    OPTION_REGbits.PSA=0;
    OPTION_REGbits.T0CS=0;
    
   // OPTION_REGbits.T0SE=1;
    PORTB =0x00;	//turning all leds off
    while(1)		//endless loop with blinking pattern
    {
        PORTB=0x00;
      
            
    }    
}