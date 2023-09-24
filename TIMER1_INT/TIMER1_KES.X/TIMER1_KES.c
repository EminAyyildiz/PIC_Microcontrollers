/*
 * File:   TIMER1_KES.c
 * Author: EminAYYILDIZ
 *
 * Created on September 24, 2023, 1:55 PM
 */


#include <xc.h>

#pragma config FOSC = XT        // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low Voltage In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = ON   


#define __XTAL_FREQ 4000000

int say;

void __interrupt() KESME(void){
    
    if(TMR1IF){
        say++;
        if(say==5){
            say =0;
            RB0=RB0 ^ 1; 
            
        }
        TMR1IF=0;
        TMR1=15536;
        
    }
}

void main(void) {
    say=0;
    
    GIE=1;
    PEIE=1;
    TMR1IE=1;
    T1CKPS1=0;
    T1CKPS0=0;
    TMR1CS=0;
    TMR1ON=1;
    TMR1=15536;
    TRISB=0;
    PORTB=0;
    
    while(1){
        
    }
    
    
}
