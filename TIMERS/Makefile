MCU    = atmega328p
F_CPU  = 16000000UL
CC     = avr-gcc
OBJCOPY= avr-objcopy
AVRDUDE= avrdude

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -std=c11

all: StopWatch_Blink.hex

StopWatch_Blink.elf: StopWatch_Blink.c
	$(CC) $(CFLAGS) -o $@ $^

StopWatch_Blink.hex: StopWatch_Blink.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: StopWatch_Blink.hex
	$(AVRDUDE) -c arduino -p $(MCU) -P /dev/ttyACM0 -b 115200 -U flash:w:$<:i

clean:
	rm -f *.elf *.hex