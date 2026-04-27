MCU    = atmega328p
F_CPU  = 16000000UL
CC     = avr-gcc
OBJCOPY= avr-objcopy
AVRDUDE= avrdude

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -std=c11

all: external_interrupt.hex

external_interrupt.elf: external_interrupt.c
	$(CC) $(CFLAGS) -o $@ $^

external_interrupt.hex: external_interrupt.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: external_interrupt.hex
	$(AVRDUDE) -c arduino -p $(MCU) -P /dev/ttyACM0 -b 115200 -U flash:w:$<:i

clean:
	rm -f *.elf *.hex