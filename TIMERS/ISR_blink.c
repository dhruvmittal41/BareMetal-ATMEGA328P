#include <avr/io.h>
#include <avr/interrupt.h>

uint16_t counter = 0;

ISR(TIMER1_COMPA_vect){
    counter++;
    if (counter >= 500){
        PORTB ^= (1 << PB5);
        counter = 0;
    }
}

void timer_init(void){
    TCCR1A = 0;
    TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10);
    OCR1A = 249;
    TIMSK1 = (1 << OCIE1A);
    sei();
}

int main(void){
    DDRB |= (1 << PB5);
    timer_init();

    while(1){

    }
}