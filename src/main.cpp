
#include <Arduino.h>

int ledPin = 9;

int main(){


TCCR1A = (1 << WGM11) | (1 << COM1A1); // Fast PWM, non-inverting mode
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Fast PWM, prescaler = 8
  ICR1 = 1999; // Set TOP value for 1 kHz
  OCR1A = 1999;


while(1){



}


}
