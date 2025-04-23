#include <Arduino.h>
#include <Servo.h>

Servo myservo;  // create Servo object to control a servo

void servoSetup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the Servo object
}

void servoLoop() {

  for (int pos = 67; pos <= 20 + 67; pos += 1) {
    myservo.write(pos);
    delay(15); 
  }
  delay(1000);
  for (int pos = 67 + 20; pos >= 67 - 22; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
  delay(1000);
  for (int pos = 67 - 20; pos <= 67; pos += 1) {
    myservo.write(pos);
    delay(15); 
  }
  delay(1000);
}

int main(){
  init();
  servoSetup();
  while(1){
    servoLoop();

  }
  return 0;
}