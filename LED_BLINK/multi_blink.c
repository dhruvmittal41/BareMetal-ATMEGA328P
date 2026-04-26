#include <avr/io.h>
#include <util/delay.h>

int main(void){
    DDRB |= (1 << PB5);
    DDRB |= (1 << PB4);
    DDRB |= (1 << PB3);

    while(1){
        PORTB |= (1 << PB5);
        _delay_ms(500);
        PORTB &= ~(1 << PB5);
        _delay_ms(1000);
        PORTB |= (1 << PB4);
        _delay_ms(500);
        PORTB &= ~(1 << PB4);
        _delay_ms(1000);
        PORTB |= (1 << PB3);
        _delay_ms(500);
        PORTB &= ~(1 << PB3);
        _delay_ms(1000);
        
    }
}

