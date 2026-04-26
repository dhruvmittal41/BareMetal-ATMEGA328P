#include <avr/io.h>
#include <avr/interrupt.h>

uint16_t counter_R = 0;
uint16_t counter_G = 0;
uint16_t counter_Y = 0;

ISR(TIMER1_COMPA_vect){
    counter_G++;
    counter_R++;
    counter_Y++;

    if (counter_G >= 200){
        PORTB ^= (1 << PB5);
        counter_G = 0;
    }
    if (counter_Y >= 500){
        PORTB ^= (1 << PB4);
        counter_Y = 0;
    }
    if (counter_R >= 1000){
        PORTB ^= (1 << PB3);
        counter_R = 0;
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
DDRB |= (1 << PB4);
DDRB |= (1 << PB3);

timer_init();

while(1){
    
}
}