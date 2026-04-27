#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t led_state = 0;

ISR(INT0_vect){
    led_state ^= 1;
    if(led_state){
        PORTB |= (1 << PB5);
    }
    else {
        PORTB &= ~(1 << PB5);
    }
}

int main(void){

    DDRB |= (1 << PB5);
    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);


    EICRA |= (1 << ISC01);
    EICRA &= ~(1 << ISC00);

    EIMSK |= (1 << INT0);

    sei();

    while(1){
        
    }


}