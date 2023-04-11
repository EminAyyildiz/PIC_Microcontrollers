

#include <xc.h>
#pragma config FOSC = XT     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low Voltage In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = ON         // FLASH Program Memory Write Enable (Unprotected program memory may be written to by EECON control)
#define _XTAL_FREQ 4000000
#define sut1 RB2
#define sut2 RB1
#define sut3 RB0

int tus,sayi[11]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x6F,0x00};

void main(void) {
    
   TRISB=0x07;
   TRISD=0;
   PORTD=0;
   
   while(1){
       PORTB=8;
       if(sut1){tus=1;}
       if(sut2){tus=2;}
       if(sut3){tus=3;}
       PORTB=16;
       if(sut1){tus=4;}
       if(sut2){tus=5;}
       if(sut3){tus=6;}
       PORTB=32;
       if(sut1){tus=7;}
       if(sut2){tus=8;}
       if(sut3){tus=9;}
       PORTB=64;
       if(sut2){tus=0;}
       
       
       PORTD=sayi[tus];
       __delay_ms(20);
       tus=10;
   }
}
