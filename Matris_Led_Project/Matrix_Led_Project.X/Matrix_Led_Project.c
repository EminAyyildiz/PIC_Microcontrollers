

#include <xc.h>

#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 4000000

int i,j,k;

int satir[2][5]={0x00,0xB6,0xB6,0xB6,0xBE
                 ,0x03,0x75,0x76,0x75,0x03};
//int sutun[]={0x01,0x02,0x04,0x08,0x10};

void main(void) {
    
    TRISB=0;
    TRISC=0;
    
    while(1){
        for(k=0;k<2;k++){
           for(j=0;j<100;j++){
               PORTC=1;
               for(i=0;i<5;i++){
                   PORTB=satir[k][i];
                   __delay_ms(5);
                   PORTC=PORTC<<1;
               }
           } 
        }
    }
        
        
}
