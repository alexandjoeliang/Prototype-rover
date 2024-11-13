#include "switch.h"
#include <avr/io.h>

void initSwitchPD0(){
    DDRD &= ~(1<<DDD0); //input
    PORTD |= (1<<PORTD0); //enable pullup
    EIMSK |= (0x00) | (1<<INT0); //enable int0
}

