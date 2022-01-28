#include <xc.h>
#define _XTAL_FREQ 20000000 //Frequency for oscillator
void interrupt x()      //interrupt function pattern 
{
    if( INTCONbits.INTF == 1)   //condition to check interrupt flag
    {
        PORTCbits.RC0 = !RC0;  
    }
       INTCONbits.INTF = 0;		
}
    
void main()
{
    INTCONbits.GIE = 1;	//enabling global interrupt
    INTCONbits.INTE = 1;	//enabling external interrupt
    INTCONbits.PEIE = 1;	//enabling peripheral interrupt
    OPTION_REGbits.INTEDG = 0;	//enabling edge bit as rise edge
    TRISC0 = 0;
      PORTCbits.RC0 =0;
  
    while(1)		
    {
    }    
}

