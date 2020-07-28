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

void init_display(void); //init I/O ports 
void set_to_output(void); //set data ports to output
void set_to_input(void); //set data ports to input
void write_byte(uint8_t); //writes 1 byte of data 
void write_half(uint8_t); //writes half of byte

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