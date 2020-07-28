#include <stdbool.h>

#ifndef LCD_LIB_h_
#define LCD_LIB_h_
#define RS 0
#define PORT_RS D
#define RW 1
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
#define PORT(x) SPORT(x)
#define SPORT(x) (PORT##x)
#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)
#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)


#define CLEAR_DISP 0x01
#define HOME 0x02
#define DISP_CTRL 0x0F 
    #define DISP_OFF 0xF7 //masks
    #define CURSOR_OFF 0xFD
    #define BLINK_OFF 0xFE
#define LOCATION_DDRAM 0x80
#define SECOND_LINE 0x40

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
void locate(uint8_t x, uint8_t y); //change location of cursor

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