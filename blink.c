#include "msp430fr4133.h"
//Define a second at 1MHz
#define BLINK_CYCLES 500000L

int main(void){

    //Stop the WDT Module 
    WDTCTL = WDTPW |WDTHOLD;

    //Enable Output from PMM
    PM5CTL0 &= ~LOCKLPM5;

    //Set Pin 1.0 as output
    P1DIR |= BIT0; 
    //Set Port 1 Pin 0 to low
    P1OUT &= ~BIT0;

    //Set Pin 4.0 as output
    P4DIR |= BIT0; 
    //Set Port 1 Pin 0 to low
    P4OUT &= ~BIT0;

    while(1){
        //Toggle every second
        __delay_cycles(BLINK_CYCLES);
        P1OUT ^= BIT0;
        P4OUT ^= BIT0;
    }

    return 0;
}
