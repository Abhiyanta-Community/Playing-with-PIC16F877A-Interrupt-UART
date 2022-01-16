#include <xc.h>
#define _XTAL_FREQ 20000000   //Frequency for oscillator
#define baud_rate 9600

void uart()
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
 //   TXIF = RCIF = 0;
}

void send(char a)
{
    TXREG = a ;
    while(!TXIF);
    TXIF=0;
}
    
    
char get()
{
    RB3=1;
    while(!RCIF)
        RCIF=0;
    return RCREG;
}   

void send_data(char *x)
{
 while(*x)   
     send(*x++);
}

void main()
{    
    int p;
    TRISC6=0;                      
    TRISC7=1;
    uart();
    
    send_data("UART MODULE READY!!\n");
    while(1)
    {   p=get();  
        send(p);
        
        if(p==1)
            RB3=1;
        
        else
            RB3=0;
    }
}