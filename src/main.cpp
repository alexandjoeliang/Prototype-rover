#include <avr/io.h>
#include <avr/interrupt.h>

void setupTimer1() {
    // Set CTC mode
    TCCR1B |= (1 << WGM12);

    // Set prescaler to 64
    TCCR1B |= (1 << CS11) | (1 << CS10);

    // Set compare match value for 1kHz
    OCR1A = 249;

    // Enable compare match interrupt
    TIMSK1 |= (1 << OCIE1A);

    // Enable global interrupts
    sei();
}

ISR(TIMER1_COMPA_vect) {
    // Code to execute on every timer interrupt
}

int main() {
    // Initialize Timer1
    setupTimer1();

    while (1) {
        // Main loop
    }
}
