#include "timer.h"

void initTimer0(){
    //enable timer0 for value compare
    TCCR0B &= ~(1<<WGM02);
    TCCR0A |= (1<<WGM01);
    TCCR0A &= ~(1<<WGM00);
}

void delayMs(unsigned int delay){
    //enable timer 0
    TCCR0B &= ~(1<<CS02);
    TCCR0B |= ((1<<CS01)|(1<<CS00));
    //250 counts at 16MHz is 1ms with prescaler of default 1
    unsigned int timeDelay = 249;
    unsigned int totalMScount = 0;
    //start at 0, go to timeDelay
    TCNT0 = 0;
    OCR0A = timeDelay;
    //use user defined value for flag
    TIFR0 |= (1<<OCF0A);

    while (totalMScount < delay) {
        //delay until flag raised
        while(!(TIFR0 & (1<<OCF0A)));
        //clear flag, add 1 ms to total count
        TIFR0 |= (1<<OCF0A);
        totalMScount++;
    } 
    //turn off timer when done
    TCCR0B &= ~(1<<CS02 | 1<<CS01 | 1<<CS00);
}

void initTimer1(){
    //enable timer1 for value compare and prescaler of 256
    TCCR1B &= ~(1<<WGM13);
    TCCR1B |= (1<<WGM12);
    TCCR1A &= ~(1<<WGM11);
    TCCR1A &= ~(1<<WGM10);
}

void delaySec(unsigned int delay){
    //start at zero, go to 62500, with prescalar of 256
    TCNT1 = 0;
    OCR1A = 62500;
    //start timer
    TCCR1B |= (1<<CS12);
    TCCR1B &= ((1<<CS11) | (1<<CS10));
    //initiate count value, put flag down
    unsigned int totalCount = 0;
    TIFR1 |= (1<<OCF1A);

    while(totalCount!=delay){
        while(!(TIFR1 & (1<<OCF1A)));
        //same as timer0
        TIFR1 |= (1<<OCF1A);
        totalCount++;
    }
    //stop timer
    TCCR1B &= ~((1<<CS12) | (1<<CS11) | (1<<CS10));
}
