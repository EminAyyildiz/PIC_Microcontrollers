/*
 * File:   led_uygulamasi.c
 * Author: User
 *
 * Created on 5 September 2019, 10:43 AM
 */


#include <xc.h>

#pragma config FOSC = XT        // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = ON        // Watchdog Timer (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000


void main(void) {
    
    TRISB=0x00;
    TRISA = 0b00000001;
    
    
    while(1){
        if(RAO == 1) PORTB = 0x0F;
        if (RA0 == 0) PORTB = 0xF0;
        

      
    }
    
}
