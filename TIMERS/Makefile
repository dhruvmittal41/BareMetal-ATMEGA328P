MCU    = atmega328p
F_CPU  = 16000000UL
CC     = avr-gcc
OBJCOPY= avr-objcopy
AVRDUDE= avrdude

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -std=c11

all: ISR_Multiblink.hex

ISR_Multiblink.elf: ISR_Multiblink.c
	$(CC) $(CFLAGS) -o $@ $^

ISR_Multiblink.hex: ISR_Multiblink.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: ISR_Multiblink.hex
	$(AVRDUDE) -c arduino -p $(MCU) -P /dev/ttyACM0 -b 115200 -U flash:w:$<:i

clean:
	rm -f *.elf *.hex