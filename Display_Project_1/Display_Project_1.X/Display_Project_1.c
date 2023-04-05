


#include <xc.h>

#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

int i, dizi[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x6F};

void main(void) {
    TRISB=0x00;
    PORTB=0x00;
    TRISA=0x00; // 0b0000 0000
    PORTA=0x01; // 0b0000 0001
    
    while(1){
        for(i=0;i<10;i++){
            PORTB=dizi[i];
            __delay_ms(500);
        }
    }
}
