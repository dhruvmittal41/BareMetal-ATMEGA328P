#include <avr/io.h>

int main(void){
    DDRB |= (1 << PB5);
    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);
    int toggle;
    toggle = 0;


    
     while(1){
        if(!(PIND & (1 << PD2))){
            toggle = !(toggle);
        }
        if(toggle == 1){
            PORTB ^= (1 << PB5);
        }
    }
}

