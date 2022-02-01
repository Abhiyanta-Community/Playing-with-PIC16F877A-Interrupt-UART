#include <xc.h>
#define _XTAL_FREQ 20000000   //Frequency for oscillator
#define baud_rate 9600         // definig Baud rate

void uart()                  //function for using UART
{
    
    TXSTA =0x24;
    SPEN=1;
    SPBRG = 129;   //(_XTAL_FREQ/(16*baud_rate)) - 1;
    /*
    TXEN = 1;
    BRGH = 1;
    SYNC = 0;  
    */
}

void send(char a)               //function for sending data
{
    TXREG = a ;
    while(!TXIF);
 
}
void main()
{  TRISB=0xff;                   //PORTB as input  
    uart();
    while(1)
    {
    send(PORTB);
    }
}
