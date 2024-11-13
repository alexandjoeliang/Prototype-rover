#include <Arduino.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "timer.h"
#include <Servo.h>
  // create Servo object to control a servo
// twelve Servo objects can be created on most boards
   // variable to store the servo position


  // attaches the servo on pin 9 to the Servo object


int main(){
  Servo myservo;
  myservo.attach(9);
  initTimer0();
  int pos = 0; 
  while(1) {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delayMs(15);                       // waits 15 ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delayMs(15);                       // waits 15 ms for the servo to reach the position
    }
  }
  return 0;
}