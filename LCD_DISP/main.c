#define F_CPU 8000000UL 
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "LCD_LIB.h"

int main(void){
    init_display(); //initialize display
    write_instruction(DISP_CTRL & BLINK_OFF & CURSOR_OFF); //turn on the display
    
    while(1){

    }
    return 0;
}
