
#include <xc.h>
#pragma config FOSC = XT        // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low Voltage In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = ON         // FLASH Program Memory Write Enable (Unprotected program memory may be written to by EECON control)
#define _XTAL_FREQ 4000000

void __interrupt() KESME(void){
    
    if(RB6==0){
        PORTD=5;
    }
    else{
        PORTD=10;
    }
    if(RB5){
        if(CCPR1L > 245){
            CCPR1L=1;
        }
        CCPR1L = CCPR1L + 20;
    }
    if(RB4){
        if(CCPR1L==0){
            CCPR1L=245;
        }
        CCPR1L = CCPR1L - 20;
    }
    RBIF=0;
    
}


void main(void) {
    
    GIE=1;
    RBIE=1;
    CCP1M3=1;
    CCP1M2=1;
    PR2=249;
    CCPR1L=125;
    T2CKPS1=0;
    T2CKPS0=1;
    TMR2ON=1;
    TRISB=255;
    TRISD=0;
    TRISC=0;
    PORTD=5;
    while(1){}
}
