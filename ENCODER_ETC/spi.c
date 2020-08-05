#include "spi.h"
void init_spi_MASTER(void){
    DDR(PORT_MOSI) |= (1 << MOSI); //set outputs
    DDR(PORT_SCK) |= (1 << SCK);
    DDR(PORT_SS) |= (1 << SS);

    SPCR |= (1 << MSTR) | (1 << SPE); //master mode, SPI enable
    SPSR |= (1 << SPI2X); //fosc / 64
    SPCR|= (1 << SPR0) | (1 << SPR1);

    set_OE(); //output disabled
}
void send_data(const uint8_t data){
    SPDR = data; //write data byte to SPDR register to start transfer
    while(!(SPSR & (1 << SPIF))); //while data is being transfered
}