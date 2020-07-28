#define F_CPU 8000000UL 
#include <avr/io.h>
#include <util/delay.h>
#include "LCD_LIB.h"


int main(void){
    init_display();
    write_string("HELLO :)");
    while(1){

    }
    return 0;
}
