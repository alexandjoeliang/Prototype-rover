//water level

#include <Arduino.h>

void setup()
{
  // Used to display information
  Serial.begin(115200);

  // Wait for Serial Monitor to be opened

}

void loop()
{

  int value = analogRead(A0);
  
  Serial.print("Value :");
  Serial.print(value);
  Serial.print("   ");
  Serial.print("W Level :");


  if (value == 0) {
    Serial.print("Empty ");
  } else if (value > 1 && value < 400) {
    Serial.print("LOW   ");
  } else if (value > 350 && value < 480) {
    Serial.print("Medium");
  } else if (value > 480){
    Serial.print("HIGH  ");
  }
  Serial.print("\n");
 delay(2000);
}