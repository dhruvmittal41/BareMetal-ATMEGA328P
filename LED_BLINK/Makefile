MCU    = atmega328p
F_CPU  = 16000000UL
CC     = avr-gcc
OBJCOPY= avr-objcopy
AVRDUDE= avrdude

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -std=c11

all: multi_blink.hex

multi_blink.elf: multi_blink.c
	$(CC) $(CFLAGS) -o $@ $^

multi_blink.hex: multi_blink.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: multi_blink.hex
	$(AVRDUDE) -c arduino -p $(MCU) -P /dev/ttyACM0 -b 115200 -U flash:w:$<:i

clean:
	rm -f *.elf *.hex