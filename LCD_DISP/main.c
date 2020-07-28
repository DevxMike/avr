#define F_CPU 8000000UL 
#include <avr/io.h>
#include <util/delay.h>
#include "LCD_LIB.h"


int main(void){
    init_display();

    write_instruction(DISP_CTRL & BLINK_OFF & CURSOR_OFF);
    write_string("first");
    locate(10, 1);
    write_string("second");
    locate(0, 1);
    write_string("third");
    locate(10, 0);
    write_string("fourth");
    while(1){

    }
    return 0;
}
