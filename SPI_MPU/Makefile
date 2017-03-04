prog: main.c spi.c
	avr-gcc -mmcu=atmega644p -DFCPU=12000000 -Wall -Os main.c spi.c -o prog.elf
	avr-objcopy -O ihex prog.elf prog.hex
	avrdude -c usbasp -p m644p -U flash:w:prog.hex
