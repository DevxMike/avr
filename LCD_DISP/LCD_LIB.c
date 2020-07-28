#include <avr/io.h>
#include <util/delay.h>
#include "LCD_LIB.h"

void init_display(void){
    DDR(PORT_E) |= (1 << E); //set E to output
    DDR(PORT_RS) |= (1 << RS); //set RS to output
    DDR(PORT_RW) |= (1 << RW); //set RW to output
    set_to_output(); //set Dn pins to output
    _delay_ms(15.0); //delay (wait till Ucc rises)
    clear_e(); //clear enable
    clear_rs(); //instruction register
    clear_rw(); //write
    set_e(); //set enable
    write_half(0x03); //send command function enable
    clear_e(); //clear enable
    _delay_ms(4.1); //wait
    set_e();
    write_half(0x03); //function enable
    clear_e();
    _delay_us(100); //wait
    set_e();
    write_half(0x03); //function enable 
    clear_e();
    _delay_us(100); //wait
    set_e();
    write_half(0x02); //4bit interface set, 
    clear_e();
    _delay_us(100); //wait
    write_instruction(CLEAR_DISP); //clear display
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
    while(busy_flag() & (1 << 7)){ //continue this loop while some internal operation is being performed
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
    set_e(); //set enable
    temp |= read_half(); //add second call`s result
    clear_e(); //clear enable
    return temp; //return result
}
uint8_t read_half(void){
    uint8_t temp = 0x00;

    if((1 << D4) & (PIN(PORT_D4))){ //if value on pin D4 equals 1, add 1 
        temp |= 1 << 0;
    }
    if((1 << D5) & (PIN(PORT_D5))){ //if value on pin D5 equals 1, add 2
        temp |= 1 << 1;
    }
    if((1 << D6) & (PIN(PORT_D6))){ //if value on pin D6 equals 1, add 4
        temp |= 1 << 2;
    }
    if((1 << D7) & (PIN(PORT_D7))){ //if value on pin D7 equals 1, add 8
        temp |= 1 << 3;
    }

    return temp; //return result
}
uint8_t busy_flag(void){
    clear_rs(); //instruction register
    return read_byte(); //read and return byte
}
uint8_t read_data(void){
    set_rs(); //data register
    return read_byte(); //read and return byte
}
void write_string(char* string){
    while(*string){ //while *string != '\0'
        write_data_byte(*string++); //write byte of data to LCD
    }
}
void locate(uint8_t x, uint8_t y){ //y = 0 first line, y = 1 second line
    uint8_t location = 0x00; //primary location is 0x00 (beginning)
    location |= LOCATION_DDRAM | x | (y * SECOND_LINE); //sum location DDRAM first address (0x80) 
                                                        //with x coord and y multiplied by second line address (0x40)
    write_instruction(location); //send instruction
}
