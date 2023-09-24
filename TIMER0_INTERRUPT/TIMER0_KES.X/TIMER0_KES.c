

#include <xc.h>

#pragma config FOSC = XT        // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define __XTAL_FREQ 4000000

int sayac;

void __interrupt() KESME(void){
    
    if(T0IF){
        
        sayac++;
        if(sayac==10){
            sayac=0;
            RB0=RB0 ^ 1; // 0000 0001
        }
        TMR0=61;
        T0IF=0;
    }
    
}

void main(void) {
    
    GIE=1;
    T0IE=1;
    OPTION_REG=0x07; //0b 0000 0111
    TRISB=0x00;
    TMR0=61;
    sayac=0;
    PORTB=0;
    
    while(1){}
    
}
