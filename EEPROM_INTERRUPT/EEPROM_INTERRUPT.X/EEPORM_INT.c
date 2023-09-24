/*
 * File:   EEPORM_INT.c
 * Author: EminAYYILDIZ

 */


#include <xc.h>

// CONFIG
#pragma config FOSC = XT    // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF    


#define _XTAL_FREQ 4000000
int sayac;
void __interrupt() KESME(){
    
    if(EEIF){
        EEADR=0x1F;
        RD=1;
        PORTB=EEDATA;
    }
    EEIF=0;
}

void main(void) {
    EEIE=1;
    TRISB=0x00;
    TRISA=0x01; 
    sayac=0;
    PORTB=0;
    while(1){
        if(RA0){
            while(RA0){}
            sayac++;
            EEADR=0x1F;
            EEDATA=sayac;
            WREN=1;
            EECON2=0x55;
            EECON2=0xAA;
            WR=1;
            GIE=1;
        }
    }
}
