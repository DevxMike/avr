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
void write_byte(uint8_t data){
    set_to_output();
    //need to go to docs and check timing and stuff
    write_half(data);
    write_half(data >> 4);
}
void write_half(uint8_t data){ //function used to write half a byte to our display
    if(data & (1 << 0)){ //if LSB equals to 1
        PORT(PORT_D4) |= (1 << D4); ///set first data pin
    }
    else{
        PORT(PORT_D4) &= ~(1 << D4); //else clear first data pin
    }
    if(data & (1 << 1)){ //if second bit equals to 1
        PORT(PORT_D5) |= (1 << D5); //set second data pin
    }
    else{
        PORT(PORT_D5) &= ~(1 << D5); //else clear it
    }
    if(data & (1 << 2)){ //if third bit equals to 1
        PORT(PORT_D6) |= (1 << D6); //set third data bit
    }
    else{
        PORT(PORT_D6) &= ~(1 << D6); //else clear it
    }
    if(data & (1 << 3)){ //if fourth (MSB) equals to 1
        PORT(PORT_D7) |= (1 << D7); //set last data pin
    }
    else{
        PORT(PORT_D7) &= ~(1 << D7); //else clear it
    }
}