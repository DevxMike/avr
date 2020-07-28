#include <avr/io.h>
#include "LCD_LIB.h"

void init_display(void){
    DDR(PORT_E) |= (1 << E); //set E to output
    DDR(PORT_RS) |= (1 << RS); //set RS to output
    DDR(PORT_RW) |= (1 << RW); //set RW to output
    set_to_output();
    
}
void set_to_output(void){
    DDR(PORT_D4) |= (1 << D4); //set D4 pin to output
    DDR(PORT_D5) |= (1 << D5); //set D5 pin to output
    DDR(PORT_D6) |= (1 << D6); //set D6 pin to output
    DDR(PORT_D7) |= (1 << D7); //set D7 pin to output
}
void set_to_input(void){
    DDR(PORT_D4) &= ~(1 << D4); //set D4 pin to intput 
    DDR(PORT_D5) &= ~(1 << D5); //set D5 pin to intput 
    DDR(PORT_D6) &= ~(1 << D6); //set D6 pin to intput 
    DDR(PORT_D7) &= ~(1 << D7); //set D7 pin to intput 
}