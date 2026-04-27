MCU    = atmega328p
F_CPU  = 16000000UL
CC     = avr-gcc
OBJCOPY= avr-objcopy
AVRDUDE= avrdude

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -std=c11

all: Two_Buttons.hex

Two_Buttons.elf: Two_Buttons.c
	$(CC) $(CFLAGS) -o $@ $^

Two_Buttons.hex: Two_Buttons.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: Two_Buttons.hex
	$(AVRDUDE) -c arduino -p $(MCU) -P /dev/ttyACM0 -b 115200 -U flash:w:$<:i

clean:
	rm -f *.elf *.hex