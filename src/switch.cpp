#include "switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PB3 and sets it into input mode
 */
void initSwitchPB0(){
    DDRB &= ~(1<<DDB0); //input
    PORTB |= (1<<PORTB0); //enable pullup
    PCMSK0 |= (1<<PCINT0); //enable int0
}
