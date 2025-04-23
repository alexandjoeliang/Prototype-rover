#include <Arduino.h>
#include <Servo.h>

Servo myservo;  // create Servo object to control a servo

void servoSetup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the Servo object
}

void servoLoop() {
  for (int pos = 114; pos <= 25 + 114; pos += 1) {
    myservo.write(pos);
    delay(15); 
  }
  for (int pos = 114 + 25; pos >= 114 - 25; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
  for (int pos = 114 - 25; pos <= 114; pos += 1) {
    myservo.write(pos);
    delay(15); 
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