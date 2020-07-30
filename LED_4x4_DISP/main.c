#include "timer.h"
#include "LED_DISP.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void){
    sei(); //global interrupt enable
    init_timer();

    while(1){

    }
    return 0;
}

ISR(TIMER2_COMP_vect ){
    static uint8_t i = 0;
    
    switch(i++){
        case 0:
        break;

        case 1:
        break;

        case 2:
        break;

        case 3:

        i = 0;
        break;
    }
}