
#include <xc.h>

#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

void __interrupt() KESME(void){
    
    if(INTF){
        PORTA=1; //0b 0000 0001
        __delay_ms(2000);
    }
    
    INTF=0;
    PORTA=0;
}

void main(void) {
    
    GIE=1;
    INTE=1;
    TRISB=1; //0x01
    TRISA=0;
    PORTA=0;
    
    while(1){
        RB1=0;__delay_ms(1000);
        RB1=1;__delay_ms(1000);
        RB2=0;__delay_ms(1000);
        RB2=1;__delay_ms(1000);
    }
}
