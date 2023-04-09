

#include <xc.h>
#pragma config FOSC = XT        // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 4000000

int sayac=0,adim=3;


int gecikme=0;



void __interrupt() KESME(void){
if(T0IF){
      gecikme++;
      if(gecikme>5000){
          gecikme=0;
          if(adim>8){
              adim=2;}
          adim++;
      }
      sayac++;
      if (sayac<=adim){
          RB0=1;}
      else if (sayac>adim){
          RB0=0;
      }
      
    
    if (sayac==100){
        sayac=0;
    }
    

         
  
}
TMR0=231;
T0IF=0;
}


void main(void) {
    GIE=1;
    T0IE=1;
    TRISB=0;
    OPTION_REG=0x02;
    TMR0=231;
    

    
    while(1){}
}

