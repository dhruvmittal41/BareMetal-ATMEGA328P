MCU    = atmega328p
F_CPU  = 16000000UL
CC     = avr-gcc
OBJCOPY= avr-objcopy
AVRDUDE= avrdude

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -std=c11

all: button_press.hex

button_press.elf: button_press.c
	$(CC) $(CFLAGS) -o $@ $^

button_press.hex: button_press.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: button_press.hex
	$(AVRDUDE) -c arduino -p $(MCU) -P /dev/ttyACM0 -b 115200 -U flash:w:$<:i

clean:
	rm -f *.elf *.hex