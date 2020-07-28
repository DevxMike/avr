#include <avr/io.h>
#include <util/delay.h>
#include "LCD_LIB.h"

#define CLEAR_DISP 0x01
#define HOME 0x02
#define DISP_CTRL 0x0F 
    #define DISP_OFF 0xF7 //masks
    #define CURSOR_OFF 0xFD
    #define BLINK_OFF 0xFE

void init_display(void){
    DDR(PORT_E) |= (1 << E); //set E to output
    DDR(PORT_RS) |= (1 << RS); //set RS to output
    DDR(PORT_RW) |= (1 << RW); //set RW to output
    set_to_output();
    _delay_ms(15.0);
    clear_e();
    clear_rs();
    clear_rw();
    set_e();
    write_half(0x03);
    clear_e();
    _delay_ms(4.1);
    set_e();
    write_half(0x03);
    clear_e();
    _delay_us(100);
    set_e();
    write_half(0x03);
    clear_e();
    _delay_us(100);
    set_e();
    write_half(0x02);
    clear_e();
    _delay_us(100);
    write_instruction(CLEAR_DISP);
    write_instruction(DISP_CTRL & BLINK_OFF);
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
    clear_rw(); //write
    set_e(); //set enable
    write_half(data >> 4); //send half a byte
    clear_e(); //clear enable

    set_e(); //set enable
    write_half(data); //send last half
    clear_e(); //clear enable
    while(busy_flag() & (1 << 7)){
            continue;
    }
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

void write_data_byte(char byte){
    set_rs(); //data register
    write_byte(byte);
}
void write_instruction(uint8_t instruction){
    clear_rs(); //instruction register
    write_byte(instruction);
}
uint8_t read_byte(){
    uint8_t temp = 0x00;

    set_to_input();
    set_rw(); //read
    set_e(); //enable
    temp = read_half(); //read half
    clear_e(); //clear enable
    temp = temp << 4; // move bits to the left 
    set_e();
    temp |= read_half();
    clear_e();
    return temp;
}
uint8_t read_half(void){
    uint8_t temp = 0x00;

    if((1 << D4) & (PIN(PORT_D4))){
        temp |= 1 << 0;
    }
    if((1 << D5) & (PIN(PORT_D5))){
        temp |= 1 << 1;
    }
    if((1 << D6) & (PIN(PORT_D6))){
        temp |= 1 << 2;
    }
    if((1 << D7) & (PIN(PORT_D7))){
        temp |= 1 << 3;
    }

    return temp;
}
uint8_t busy_flag(void){
    clear_rs();
    return read_byte();
}
uint8_t read_data(void){
    set_rs();
    return read_byte();
}
void write_string(char* string){
    while(*string){
        write_data_byte(*string++);
    }
}
