#include <avr/io.h>
#include <avr/interrupt.h>
#include <Arduino.h>

int speed = 8;
int in1 = 9;
int in2 = 10;
bool cw, ccw, pause;
unsigned long previousMillis = 0;
const long interval = 5000;

void setup(){
  pinMode(speed, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(115200);
  cw = true;
}

void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    if(pause){
      cw = !cw;
      ccw = !ccw;
      pause = false;
    }else if(cw){
      pause = true;
    }else if(ccw){
      pause = true;
    }
    Serial.println("complete");
    previousMillis = currentMillis;
  }


  if(pause){
    analogWrite(speed, 0);
    Serial.println("pause");
    delay(100);
  }else if(cw){
    analogWrite(speed, 150); 
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    Serial.println("cw");
  }else if(ccw){
    analogWrite(speed, 150); 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    Serial.println("ccw");
  }


}
