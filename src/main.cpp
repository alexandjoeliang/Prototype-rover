#include <Arduino.h>

#include <Servo.h>

Servo myservo;  // create Servo object to control a servo

void servoSetup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the Servo object
}

void servoLoop(int* pos) {
  myservo.write(*pos);
}

int main(){
  init();
  servoSetup();
  int pos = 0;
  while(1){
    servoLoop(&pos);
    delay(10);
    pos++;
    if(pos>270){
      pos = 0;
    }
  }
  return 0;
}