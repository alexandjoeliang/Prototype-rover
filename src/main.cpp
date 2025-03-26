#include <avr/io.h>
#include <avr/interrupt.h>
#include <Arduino.h>

int delayTime = 60UL * 60UL * 1000UL; //1 hour delay
//int delayTime = 5000; //5 seconds delay (for testing only)

int RelayPin1 = 11; //connect relay module's pin 1 to pin 11 of Arduino
int RelayPin2 = 12; //connect relay module's pin 2 to pin 12 of Arduino

void forward() {
  digitalWrite(RelayPin1, LOW); //normally, giving LOW to relay will make it turn off
  digitalWrite(RelayPin2, HIGH); //and giving HIGH will make it turn on (active low)
}

void reverse() {
  digitalWrite(RelayPin2, LOW);
  digitalWrite(RelayPin1, HIGH);
}

void stopmotor() {
  digitalWrite(RelayPin1, LOW);  //so giving HIGH to both relays will make the relays turn off, and stop the motor
  digitalWrite(RelayPin2, LOW);
}

void setup() {
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  Serial.begin(115200);
}

void loop() {

    forward(); //motor turns forward
    Serial.print("forward");
      delay(5000);

    stopmotor(); //motor turns reverse
    Serial.print("backwards");
      delay(5000);
  
}
