#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t btn_flag = 0;

ISR(INT0_vect){
    EIMSK &= ~(1 << INT0);

    btn_flag = 1;
}


int main(void){

    DDRB |= (1 << PB5);
    DDRD &= ~(1 << PD2);
    PORTD |= ( 1 << PD2);

    EICRA |= (1 << ISC01);
    EIMSK |= ( 1 << INT0);
    sei();

    while(1){
        if(btn_flag){
            btn_flag = 0;
            _delay_ms(20);

            if(!(PIND & (1 << PD2))){
                PORTB ^= (1 << PB5);
            }

            EIMSK |= (1 << INT0);
        }
    }
}