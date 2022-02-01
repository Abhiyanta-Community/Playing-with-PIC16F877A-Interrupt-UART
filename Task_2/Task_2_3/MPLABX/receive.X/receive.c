#include <xc.h>
#define _XTAL_FREQ 20000000   //Frequency for oscillator
#define baud_rate 9600         // definig Baud rate

void uart()                  //function for using UART
{
    RCSTA =0x90;
    SPBRG = 129;   //(_XTAL_FREQ/(16*baud_rate)) - 1;
    /*
  
    SPEN = 1;
    CREN = 1;
    RX9 = 0;
    */
}
char get()                      //function for receiving data
{
    while(!RCIF)
        RCIF=0;
    return RCREG;
}   
void main()
{   TRISB = 0x00;
    PORTB=0x00;
    uart();
    while(1)
    {
            PORTB= get();
    }
}
