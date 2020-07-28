#define F_CPU 8000000UL 
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "LCD_LIB.h"

int main(void){
    init_display();

    write_instruction(DISP_CTRL & BLINK_OFF & CURSOR_OFF);
    locate(2, 0);
    write_string("Hello World!");
    locate(0, 1);
    write_string("07.20");
    locate(5, 1);
    write_string("(C)DevxMike");
    while(1){

    }
    return 0;
}
