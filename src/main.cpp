#include <Arduino.h>

// put function declarations here:
int motor = 5;
int led = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
  if (!Serial);
  Serial.println("Speed up to 0 to 255");
}

void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available()) {
    int speed = Serial.parseInt();
    if (speed >= 0 && speed <= 255) {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
    analogWrite(motor, speed);
  }
}

