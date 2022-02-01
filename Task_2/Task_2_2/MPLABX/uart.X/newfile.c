#include <xc.h>
#define _XTAL_FREQ 20000000   //Frequency for oscillator
#define baud_rate 9600         // definig Baud rate

void uart()                  //function for using UART
{
    
    TXSTA =0x24;
    RCSTA =0x90;
    SPBRG = 129;   //(_XTAL_FREQ/(16*baud_rate)) - 1;
    /*
    TXEN = 1;
    BRGH = 1;
    SYNC = 0;
    TX9 = 0;
    
    SPEN = 1;
    CREN = 1;
    RX9 = 0;
    */

}

void send(char a)               //function for sending data
{
    TXREG = a ;
    while(!TXIF);
 
}
    
    
char get()                      //function for receiving data
{
    while(!RCIF)
        RCIF=0;
    return RCREG;
}   

void send_data(char *x)         //function for sending string as character
{
 while(*x)   
     send(*x++);
}

void main()
{    
    int p;
    TRISC6=0;                     // assigning RC6 as output
    TRISC7=1;                     //assigning RC7 as input
    TRISB=0x00;                     //PORTB as output
     PORTB=0;                      //initialing all output off
    uart();
    
    send_data("INPUT:\n");
    while(1)
    {   p=get();  //receiving data from user
        send(p);    //displaying data received 
        
        
        //conditions for checking pressed number
        if(p=='1')
        {    PORTB=0x02; 
          send_data(" OUTPUT:LED 1 IS ON\n");
        }
        
        if(p=='2')
        {    PORTB=0x04;     
          send_data(" OUTPUT:LED 2 IS ON\n");
        }
        
        if(p=='3')
        {     PORTB=0x08;       
          send_data(" OUTPUT:LED 3 IS ON\n");
        }
        
        if(p=='0')
        {    PORTB=0;
          send_data("OUTPUT: LEDS OFF\n");
        } 
    }
}