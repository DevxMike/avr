#include "timer.h"
#include "LED_DISP.h"
#include "spi.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "shift_register.h"

uint8_t states[] = {
    0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90 //values that are going to be written to PORT_KATHODE reg to set 0 on certain pins
};
uint8_t disp_val[] = { //dig1 ... dig4 display value
    1, 2, 3, 4
};
uint8_t seg = 0x01; //starting value for PORT_DIG (0x01 writes 1 to dig1 pin)

int main(void){
    init_spi_MASTER(); //initialize SPI
    init_timer(); //initialize timer
    init_register(); //initialize register

    sei(); //global interrupt enable
    while(1){
        
    }
    return 0;
}

ISR(TIMER2_COMP_vect){
    
}