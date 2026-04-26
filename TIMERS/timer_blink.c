#include <avr/io.h>
#include <avr/interrupt.h>


volatile uint32_t ms_ticks = 0;

ISR(TIMER1_COMPA_vect){
    ms_ticks++;
}

void timer1_init(void){
    TCCR1A = 0;
    TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10);
    OCR1A = 249;
    TIMSK1 = (1 << OCIE1A);
    sei();
}

void delay_ms(uint32_t ms){
    uint32_t start = ms_ticks;
    while((ms_ticks - start) < ms);
}

int main(void){
    DDRB |= (1 << PB5);
    timer1_init();

    while (1)
    {
        PORTB ^= (1 << PB5);
        delay_ms(500);
    }
    
    return 0;
}