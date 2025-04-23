#include <avr/io.h>
#include <avr/interrupt.h>
#include <Arduino.h>

int speed = 9;
int dir = 8;
bool cw, ccw, pause;
unsigned long previousMillis = 0;
const long interval = 2000;

void setup(){
  pinMode(speed, OUTPUT);
  pinMode(dir, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;
  }

  if(cw){
    analogWrite(speed, 150); 
    digitalWrite(dir, LOW);

  }else if(pause){
    analogWrite(speed, 0);

  }else if(ccw){
    analogWrite(speed, 200); 
    digitalWrite(dir, LOW);


  }


}
