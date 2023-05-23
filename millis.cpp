#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

typedef unsigned int millis_t;
millis_t milliseconds = 0;

void millis_init(){
	TCCR0A = _BV(WGM01);  // timer0 in CTC mode
    TCCR0B = (_BV(CS01) | _BV(CS00));  // prescaler 64
    TIMSK0 = _BV(OCIE0A);  // enable timer compare interrupt
    OCR0A = ((F_CPU / 64) / 1000) - 1; // 1000Hz frequency == 1ms period
	sei();
}

millis_t millis_get(){
    millis_t ms;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
        ms = milliseconds;
    return ms;
}

ISR(TIMER0_COMPA_vect){
	++milliseconds;
}
