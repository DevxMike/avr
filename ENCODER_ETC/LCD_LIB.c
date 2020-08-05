#include <util/delay.h>
#include "LCD_LIB.h"
#include "shift_register.h"


void init_display(void){
    DDR(PORT_E) |= (1 << E); //set E to output
    DDR(PORT_RS) |= (1 << RS); //set RS to output
    _delay_ms(15.0); //delay (wait till Ucc rises)
    clear_e(); //clear enable
    clear_rs(); //instruction register
    write_byte(0x30); //send command function enable
    _delay_ms(4.1); //wait
    write_byte(0x30); //send command function enable
    _delay_us(100); //wait
    write_byte(0x30); //send command function enable
    _delay_us(100); //wait
    write_byte(0x30); //send command function enable
    _delay_us(100); //wait
    write_instruction(CLEAR_DISP); //clear display
    _delay_us(100); //wait
    write_instruction(FUNCTION_SET & F_MASK);
}

void write_byte(uint8_t data){
    //need to go to docs and check timing and stuff
    set_e(); //set enable
    send_byte_to_reg(data);
    clear_e(); //clear enable
    _delay_us(100);
}

void write_data_byte(char byte){
    set_rs(); //data register
    write_byte(byte);
}
void write_instruction(uint8_t instruction){
    clear_rs(); //instruction register
    write_byte(instruction);
}
void write_string(char* string){
    while(*string){ //while *string != '\0'
        write_data_byte(*string++); //write byte of data to LCD
    }
}
void locate_ddram(uint8_t x, uint8_t y){ //y = 0 first line, y = 1 second line
    uint8_t location = 0x00; //primary location is 0x00 (beginning)
    location |= LOCATION_DDRAM | x | (y * SECOND_LINE); //sum location DDRAM first address (0x80) 
                                                        //with x coord and y multiplied by second line address (0x40)
    write_instruction(location); //send ddram address
}
void locate_cgram(uint8_t offset){
    uint8_t temp = LOCATION_CGRAM;

    offset &= ~(0x80); //lets make sure user is sending the right address
    temp |= offset; //sum location CGRAM first address (0x40) with offset
    write_instruction(temp); //send cgram address
}
void write_to_cgram(uint8_t cgram_address, const uint8_t* tab, uint8_t y){
    uint8_t temp;

    for(temp = 0x00; temp < y; ++temp){
        locate_cgram(cgram_address++); //locate address for row of data
        write_data_byte(*tab++); //write the data into cgram
    }
    locate_ddram(0, 0);
}