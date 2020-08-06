#include "timer.h"
#include "spi.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "shift_register.h"
#include "LCD_LIB.h"
#include "encoder.h"


uint8_t states[] = {
    0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90 //values that are going to be written to PORT_KATHODE reg to set 0 on certain pins
};
uint8_t disp_val[] = { //dig1 ... dig4 display value
    1, 2, 3, 4
};
uint8_t seg = 0x01; //starting value for PORT_DIG (0x01 writes 1 to dig1 pin)
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
enum ddram_custom_addresses {
    o_dash = 0x00, z_dot = 0x01, z_line = 0x02, l_line = 0x04, cpyright = 0x06
};
int main(void){
    uint8_t temp;
    uint8_t a = 0, b = 0;
    init_spi_MASTER(); //initialize SPI
    init_register(); //initialize register
    init_display(); //initialize display
    init_encoder();
    write_instruction(DISP_CTRL & BLINK_OFF & CURSOR_OFF); //turn on the display
    sei();

    for(temp = 0x00; temp < 0x05; ++temp){ //write custom chars into cgram
        write_to_cgram(cg_ram_addresses[temp], custom_chars[temp], 8);
    }
    locate_ddram(1, 0);
    write_data_byte(cpyright);
    locate_ddram(3, 0);
    write_string("Bazan Micha");
    write_data_byte(l_line);
    //locate_ddram(0, 1);
    //write_string("STATES: A: , B: ");

    while(1){
        
        a = (PIN(PORT_EN_A) & (1 << EN_A)) ? 1 : 0;
        b = (PIN(PORT_EN_B) & (1 << EN_B)) ? 1 : 0;
        locate_ddram(0xA, 1);
        write_data_byte(a + '0');
        locate_ddram(0xF, 1);
        write_data_byte(b + '0');
        _delay_us(10);
    }
    return 0;
}

ISR(INT0_vect){
    //write_string("int0");
}
ISR(INT1_vect){
    //write_string("int1");

}