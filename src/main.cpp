#include <Arduino.h>
#include <Servo.h>

Servo myservo;  // create Servo object to control a servo

void servoSetup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the Servo object
}

void servoLoop() {
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(pos);  // tell servo to go to position in variable 'pos'
    delay(15);  // waits 15 ms for the servo to reach the position
  }
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);  // tell servo to go to position in variable 'pos'
    delay(15);  // waits 15 ms for the servo to reach the position
  }
}

int main(){
  init();
  servoSetup();
  while(1){
    servoLoop();

  }
  return 0;
}