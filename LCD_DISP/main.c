#define F_CPU 8000000UL 
#include <avr/io.h>
#include <util/delay.h>
#include "LCD_LIB.h"

const uint8_t custom_chars[][8] = {
    {0x02, 0x04, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x0E}, // 'ó' char
    {0x00, 0x04, 0x00, 0x1F, 0x02, 0x04, 0x08, 0x1F}, // 'ż' char
    {0x02, 0x04, 0x00, 0x1F, 0x02, 0x04, 0x08, 0x1F}, // 'ź' char
    {0x0C, 0x04, 0x06, 0x04, 0x0C, 0x04, 0x04, 0x03}, // 'ł' char
    {0x0E, 0x11, 0x17, 0x19, 0x19, 0x17, 0x11, 0x0E} // "copyright" char
};
const uint8_t cg_ram_addresses[] = {
    0x00, 0x08, 0x10, 0x20, 0x30
};
const uint8_t dd_ram_custom_addresses[] = {
    0x00, // 'ó'
    0x01, // 'ż'
    0x02, // 'ź'
    0x04, // 'ł'
    0x06 // "copyright"
};
enum ddram_custom_addresses {
    o_dash = 0x00, z_dot = 0x01, z_line = 0x02, l_line = 0x04, cpyright = 0x06
};
int main(void){
    uint8_t temp;
    init_display(); //initialize display
    write_instruction(DISP_CTRL & BLINK_OFF & CURSOR_OFF); //turn on the display
    
    for(temp = 0x00; temp < 0x05; ++temp){ //write custom chars into cgram
        write_to_cgram(cg_ram_addresses[temp], custom_chars[temp], 8);
    }
    locate_ddram(1, 0);
    write_data_byte(cpyright);
    locate_ddram(3, 0);
    write_string("Bazan Micha");
    write_data_byte(l_line);
    locate_ddram(3, 1);
    write_string("29.07.2020");
    
    while(1){

    }
    return 0;
}
