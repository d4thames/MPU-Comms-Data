/*
	Petros Karydogiannis

	D4 Thames
	
	spi.h
	
	SPI initialisation and communication between AVR and MPU-9250
*/

#include <avr/io.h>

void init_spi_master(void);
void spi_tx(uint8_t address, uint8_t data);
uint16_t spi_rx(void);