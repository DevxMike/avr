#include "timer.h"
#include "spi.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "shift_register.h"
#include "LCD_LIB.h"
#include "encoder.h"

uint8_t a, b;

int main(void){
    uint8_t temp;
    
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
    write_data_byte(ddram_custom_addresses[4]);
    locate_ddram(3, 0);
    write_string("Bazan Micha");
    write_data_byte(ddram_custom_addresses[3]);
    
    //locate_ddram(0, 1);
    //write_string("STATES: A: , B: ");

    while(1){
        a = (PIND & (1 << EN_A)) ? 1 : 0;
        b = (PIND & (1 << EN_B)) ? 1 : 0;

        _delay_us(10);
        locate_ddram(0xA, 1);
        write_data_byte(a + '0');
        locate_ddram(0xF, 1);
        write_data_byte(b + '0');
    }
    return 0;
}

ISR(INT0_vect){

}
ISR(INT1_vect){

}