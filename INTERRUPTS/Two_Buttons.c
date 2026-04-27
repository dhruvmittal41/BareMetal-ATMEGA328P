#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t led_on = 0;
volatile uint8_t led_off = 0;

ISR(INT0_vect){
    EIMSK &= ~(1 << INT0);
    led_on = 1;
}

ISR(INT1_vect){
    EIMSK &= ~(1 << INT1);
    led_off = 1;
}

int main(void){
    DDRB |= (1 << PB5);
    DDRD &=  ~(1 << PD2);
    PORTD |= (1 << PD2);
    DDRD &=  ~(1 << PD3);
    PORTD |= (1 << PD3);

    EICRA |= (1 << ISC01);
    EICRA |= (1 << ISC10);
    EIMSK |= (1 << INT0);
    EIMSK |= (1 << INT1);
    sei();

    while(1){
        if(led_on){
            led_on = 0;
            _delay_ms(20);

            if(!(PIND & (1 << PD2))){
                PORTB |= (1 << PB5);
            }

            EIMSK |= (1 << INT0);
            
        }
        if(led_off){
            led_off = 0;
            _delay_ms(20);

            if(!(PIND & (1 << PD3))){
                PORTB &= ~(1 << PB5);
            }
            EIMSK |= (1 << INT1);
        }
    }

    return 0;
}