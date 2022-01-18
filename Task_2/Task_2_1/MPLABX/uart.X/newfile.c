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
    //TXIF=0;
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
    TRISC6=0;                      
    TRISC7=1;
    TRISB=0x00;
     RB1=RB2=RB3=0;
    uart();
    
    send_data("Instructions:\n");
    send_data("Press 1-Green led.\n");
    send_data("Press 2-Yellow led.\n");
    send_data("Press 3-Blue led.\n");
    send_data("(Press 0 to reset)\n");
    while(1)
    {   p=get();  
        send(p);
        
        
        //conditions for checking pressed number
        if(p=='1')
        {    RB1=1;        
        }
        
        if(p=='2')
        {   RB2=1;
        }
        
        if(p=='3')
        {    RB3=1;
        }
        
        if(p=='0')
        {    RB1=RB2=RB3=0;
        } 
    }
}