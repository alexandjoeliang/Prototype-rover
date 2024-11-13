#include <avr/io.h>
#include <math.h>
#include <Arduino.h>

void initPWMTimer3(){
    DDRE |= (1<<DDE3); //pin 5 for OC module A for Timer3
    //set PWM to 10-bit mode, noninverting
    DDRB |= (1<<DDB0) | (1<<DDB1); // pin 52 and 53 on board used for direction1 and direction2 respectively 
    // B0 is direction 1 pin, and B1 is direction 2 pin where dir1 is clockwise and dir2 is counterclockwise

    TCCR3A |= (1 << COM3A1) | (1 << WGM31) | (1 << WGM30); //COM3A1 specifies non-inverting
    TCCR3A &= ~(1 << COM3A0);
    TCCR3B |= (1 << WGM33) | (1 << WGM32) | (1<< CS30);                   //CS30 sets Prescaler of 1
    TCCR3B &= ~((1 << CS32) | (1 << CS31));  
    OCR3A = 0;                                           //Duty cycle of 0%
    
}

void changeDutyCycle(unsigned int num){ //data type for argument?? (needs to be a 10 bit binary number)
     // this changes our duty cycle 
    if (0 < num && num <= 512){
       //clockwise
       OCR3A = (int) (num/0x3FF);
       PORTB |= (1 << DDB0);
       PORTB &= ~(1 << DDB1);
    }
    else if (512 < num && num <= 1024){
        //counterclockwise
        OCR3A = (int) ((1023-num)/0x3FF);
        PORTB &= ~(1 << DDB0);
        PORTB |= (1 << DDB1);
    }
    else {
        OCR3A = 0;
        PORTB &= ~(1 << DDB0);
        PORTB &= ~(1 << DDB1);
    }
}