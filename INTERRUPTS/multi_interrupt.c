#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint32_t ms_ticks = 0;
volatile uint8_t btn_press = 0;
volatile uint32_t press_time = 0;

ISR(TIMER1_COMPA_vect){
    ms_ticks++;
}

ISR(INT0_vect){
    btn_press=1;
    press_time=ms_ticks;
}

void timer1_init(void) {
    TCCR1A = 0;
    TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10);
    OCR1A  = 249;
    TIMSK1 = (1 << OCIE1A);
}


int main(void){

    DDRB |= (1 << PB5);
    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);

    EICRA |= (1 << ISC01);
    EIMSK |= (1 << INT0);

    timer1_init();
    sei();

    while(1){
        if(btn_press){
            btn_press = 0;
            PORTB |= (1 << PB5);
            while((ms_ticks - press_time) < 500);
            PORTB &= ~(1 << PB5);
        }
    }
}