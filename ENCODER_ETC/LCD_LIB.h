#include "common_macros.h"

#ifndef LCD_LIB_h_
#define LCD_LIB_h_

#define RS 0 //RS is pin no. 0
#define PORT_RS D //on PORTD
#define E 1
#define PORT_E D


#define CLEAR_DISP 0x01 //clear display command
#define HOME 0x02 //return home command
#define DISP_CTRL 0x0F //turn on display, turn on cursor, turn on it`s bilnikng
    #define DISP_OFF 0xF7 //i.e. DISP_CTRL & DISP_OFF -> turn off the display mask
    #define CURSOR_OFF 0xFD //turn off cursor mask
    #define BLINK_OFF 0xFE //turn off blinking mask
#define ENTRY_SET 0x07 //turn on increment, shift display
    #define DECREMENT_ENTRY 0xFD //shift to the left while writing to the display
    #define NO_DISPLAY_SHIFT 0xFE //dont shift to the left/right
#define LOCATION_DDRAM 0x80 //DDRAM (display data ram) first element location
#define SECOND_LINE 0x40 //address of the display`s second line
#define LOCATION_CGRAM 0x40 //CGRAM (character generator ram) first element location
#define FUNCTION_SET 0x3F //DL = 8bit,  N = 2lines, F = 5 x 10 dots
    #define DL_MASK 0xEF //4bit interface
    #define N_MASK 0xF7 //1 line
    #define F_MASK 0xFB //5x8dots


void init_display(void); //init I/O ports 
void write_byte(uint8_t); //writes 1 byte of data 
void write_data_byte(char); //writes user`s data
void write_instruction(uint8_t); //writes instruction
void write_string(char*); //write string to the display
void locate_ddram(uint8_t, uint8_t); //set location in ddram
void locate_cgram(uint8_t); //set location in cgram
void write_to_cgram(uint8_t,const uint8_t*, uint8_t); //write your own char pattern to cgram

inline void set_rs(void){
    PORT(PORT_RS) |= (1 << RS);
}
inline void set_e(void){
    PORT(PORT_E) |= (1 << E);
}
inline void clear_rs(void){
    PORT(PORT_RS) &= ~(1 << RS);
}
inline void clear_e(void){
    PORT(PORT_E) &= ~(1 << E);
}
#endif