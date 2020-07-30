#include "timer.h"
#include "LED_DISP.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

led_display_t display; //struct that holds info about the display

int main(void){
    sei(); //global interrupt enable
    
    init_timer(); //initialize timer
    init_led(&display); //initialize display

    while(1){

    }
    return 0;
}

ISR(TIMER2_COMP_vect ){
    static uint8_t i = 0;
    
    switch(i++){
        case 0:
        clr_dig4(); //turn on the right segment
        set_dig1();
        break;

        case 1:
        clr_dig1();
        set_dig2();
        break;

        case 2:
        clr_dig2();
        set_dig3();
        break;

        case 3:
        clr_dig3();
        set_dig4();
        i = 0;
        break;
    }
}