#include <stdbool.h>

#ifndef LCD_LIB_h_
#define LCD_LIB_h_

#define RS 0 //RS is pin no. 0
#define PORT_RS D //on PORTD
#define RW 1 //and so on
#define PORT_RW D
#define E 2
#define PORT_E D
#define D7 5
#define PORT_D7 D
#define D6 6
#define PORT_D6 D
#define D5 7
#define PORT_D5 D
#define D4 0
#define PORT_D4 B
#define PORT(x) SPORT(x) //those macros let us use some
#define SPORT(x) (PORT##x) //convenient stuff like i.e. PORT(PORT_RS) |= (1 << RS) 
#define DDR(x) SDDR(x) //instead of PORTx |= (1 << RS)
#define SDDR(x) (DDR##x)
#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)


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

void init_display(void); //init I/O ports 
void set_to_output(void); //set data ports to output
void set_to_input(void); //set data ports to input
void write_byte(uint8_t); //writes 1 byte of data 
void write_half(uint8_t); //writes half of byte
void write_data_byte(char); //writes user`s data
void write_instruction(uint8_t); //writes instruction
uint8_t read_byte(void); //read data
uint8_t read_half(void); //read half of byte
void write_string(char*); //write string to the display
uint8_t busy_flag(void); //read busy flag val
uint8_t read_data(void); //read data
void locate_ddram(uint8_t, uint8_t); //set location in ddram
void locate_cgram(uint8_t); //set location in cgram
void demo(void);
void write_to_cgram(uint8_t,const uint8_t*, uint8_t); //write your own char pattern to cgram

inline void set_rs(void){
    PORT(PORT_RS) |= (1 << RS);
}
inline void set_rw(void){
    PORT(PORT_RW) |= (1 << RW);
}
inline void set_e(void){
    PORT(PORT_E) |= (1 << E);
}
inline void clear_rs(void){
    PORT(PORT_RS) &= ~(1 << RS);
}
inline void clear_rw(void){
    PORT(PORT_RW) &= ~(1 << RW);
}
inline void clear_e(void){
    PORT(PORT_E) &= ~(1 << E);
}
#endif