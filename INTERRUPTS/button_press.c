#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint32_t ms_ticks   = 0;
volatile uint32_t press_start = 0;   
volatile uint8_t  press_flag  = 0;   
volatile uint32_t press_dur   = 0;  


ISR(TIMER1_COMPA_vect) {
    ms_ticks++;
}


ISR(INT0_vect) {

    if (!(PIND & (1 << PD2))) {
        press_start = ms_ticks;          

        EICRA |=  (1 << ISC00);        
    }
  
    else {
        press_dur  = ms_ticks - press_start;   
        press_flag = 1;                         

        
        EICRA &= ~(1 << ISC00);        
    }
}


void timer1_init(void) {
    TCCR1A = 0;
    TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10);
    OCR1A  = 249;                   
    TIMSK1 = (1 << OCIE1A);
}

void led_on(void)  { PORTB |=  (1 << PB5); }
void led_off(void) { PORTB &= ~(1 << PB5); }


void led_blink(void) {
    for (uint8_t i = 0; i < 3; i++) {
        led_on();
        uint32_t t = ms_ticks;
        while ((ms_ticks - t) < 150); 

        led_off();
        t = ms_ticks;
        while ((ms_ticks - t) < 150);
    }
}


int main(void) {
    
    DDRB  |=  (1 << PB5);

   
    DDRD  &= ~(1 << PD2);
    PORTD |=  (1 << PD2);

   
    EICRA |=  (1 << ISC01);    
    EICRA &= ~(1 << ISC00);    
    EIMSK |=  (1 << INT0);     

    timer1_init();
    sei();

    while (1) {
      
        if (press_flag) {
            press_flag = 0;

            if (press_dur < 500) {
                led_blink();
            } else {
                led_on();
            }
        }
    }
}