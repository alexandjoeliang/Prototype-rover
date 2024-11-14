#include <avr/interrupt.h>
#include <avr/io.h>
#include <Arduino.h>

//#include "HX711.h"


// HX711 circuit wiring
// Calibrating the load cell
#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  delay(1000);
    scale.set_scale();    
    Serial.println("Tare... remove any weights from the scale.");
    delay(1500);
    scale.tare();
    Serial.println("Tare done...");
}



void loop() {
delay(1000);
  if (scale.is_ready()) {
    
    Serial.print("Place a known weight on the scale...");
    delay(3000);
    long reading = scale.get_units(10);
    reading = reading / -88.10;
    Serial.print("Result: ");
    Serial.print(reading);
    Serial.println("g");
  } 
  else {
    Serial.println("HX711 not found.");
  }
  
}

//calibration factor will be the (reading)/(known weight)
//calibration factor found -88.10