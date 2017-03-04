/*

	Petros Karydogiannis

	D4 Thames

	spi.c

	SPI initialisation and communication between AVR and MPU-9250
*/

#include "spi.h"

/*
		   	AVR	  MPU-9250
--------------------------
	SCK	 |  PB7	| SCLK
	MISO |  PB6	| SDO
	MOSI |  PB5	| SDI
	nSS	 |  PB4	| nCS
*/


void init_spi_master(void)
{
	DDRB = _BV(PB4) | _BV(PB5) | _BV(PB7); 		//Output pins (MOSI SCK nSS)
	SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPR0); 	//SPI enable | Master config | F_cpu/16 = 750k

}

void spi_tx(uint8_t address, uint8_t data)	
{
	//Frame: R/W | 7bit address | 8bit data

	//TODO concatinate (?) address and data
	address += 0x8;
	SPDR = (address<<8) | data;

	while(!(SPSR & _BV(SPIF)))	//Check if transfer is complete
}

int16_t spi_rx(void)
{
	while(!(SPSR & _BV(SPIF)));	
	return SPDR;
}