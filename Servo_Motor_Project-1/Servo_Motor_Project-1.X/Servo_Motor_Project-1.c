

#include <xc.h>
#pragma config FOSC = XT       
#pragma config WDTE = OFF        
#pragma config PWRTE = OFF      
#pragma config CP = OFF         
#define _XTAL_FREQ 4000000

int i;

void __interrupt() KESME(void){
    if((RB4==1)&&(i<10)){
        i++;
    }
    if((RB5==1)&&(i>0)){
        i--;
    }
    RBIF=0;
}

void main(void) {
    
    GIE=1;
    RBIE=1;
    TRISB=48; //0b 0011 0000
    i=0;
    while(1){
        RB0=1;
        switch(i){
            case 0: __delay_ms(1);
                    RB0=0;
                    __delay_ms(19);
                    break;
            case 1: __delay_ms(1.1);
                    RB0=0;
                    __delay_ms(18.9);
                    break;
            case 2: __delay_ms(1.2);
                    RB0=0;
                    __delay_ms(18.8);
                    break;
            case 3: __delay_ms(1.3);
                    RB0=0;
                    __delay_ms(18.7);
                    break;
            case 4: __delay_ms(1.4);
                    RB0=0;
                    __delay_ms(18.6);
                    break;
            case 5: __delay_ms(1.5);
                    RB0=0;
                    __delay_ms(18.5);
                    break;
            case 6: __delay_ms(1.6);
                    RB0=0;
                    __delay_ms(18.4);
                    break;
            case 7: __delay_ms(1.7);
                    RB0=0;
                    __delay_ms(18.3);
                    break;
            case 8: __delay_ms(1.8);
                    RB0=0;
                    __delay_ms(18.2);
                    break;
            case 9: __delay_ms(1.9);
                    RB0=0;
                    __delay_ms(18.1);
                    break;
            case 10: __delay_ms(2);
                    RB0=0;
                    __delay_ms(18);
                    break;
        }
    }
}
