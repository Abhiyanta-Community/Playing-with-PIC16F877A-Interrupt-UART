#include <xc.h>
#define _XTAL_FREQ 20000000 //Frequency for oscillator
unsigned char i,j;

void interrupt x()  //defing interrupt function
{
    if( TMR0IF == 1)   //checking when timer flag becomes 1
    {     i=1;
    j++;
    }//assigning value of i
        TMR0IF = 0;   //clearing timer flag  
}


void main()
{
    
    INTCONbits.GIE = 1;	//enabling global interrupt
    INTCONbits.PEIE = 1;	//enabling peripheral interrupt
    OPTION_REGbits.PS2=0;
    OPTION_REGbits.PS1=0;
    OPTION_REGbits.PS0=0;       //assigning prescaler as 2
    OPTION_REGbits.PSA=0;
    OPTION_REGbits.T0CS=0;
    TMR0=0;
    TRISB0 = 1;
     TRISB1 = 0;
       TRISB2 = 1;
  
    while(1)
    {
    if(RB0==1)
        while(1)
    {    INTCONbits.TMR0IE=1;
            i=0;
            if(i==1)
            {RB1=1;
            i=0;}
        if(j==8)
        break;
    }
    }
}
