#include <avr/io.h>
#include <avr/interrupt.h>
#include <Arduino.h>

int speed = 9;

void setup(){
  
}

void loop() {

  analogWrite(speed, 100); 
  delay(5000);
  analogWrite(speed, 0);
  delay(60000);
  
}
