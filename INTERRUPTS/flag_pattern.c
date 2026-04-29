#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint32_t ms_ticks = 0;


volatile uint8_t flag_100ms = 0;
volatile uint8_t flag_500ms = 0;
volatile uint8_t flag_1s    = 0;


ISR(TIMER1_COMPA_vect) {
    ms_ticks++;

    if (ms_ticks % 100 == 0) flag_100ms = 1;

    if (ms_ticks % 500 == 0) flag_500ms = 1;

    if (ms_ticks % 1000 == 0) flag_1s = 1;
}

void timer1_init(void) {
    TCCR1A = 0;
    TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10);
    OCR1A  = 249;
    TIMSK1 = (1 << OCIE1A);
}

int main(void) {

    DDRB |= (1 << PB5) | (1 << PB4) | (1 << PB3);

    timer1_init();
    sei();

    while (1) {

     
        if (flag_100ms) {
            flag_100ms = 0;          
            PORTB ^= (1 << PB3);  
        }

        if (flag_500ms) {
            flag_500ms = 0;
            PORTB ^= (1 << PB4);   
        }

        if (flag_1s) {
            flag_1s = 0;
            PORTB ^= (1 << PB5);    
        }

    }
}