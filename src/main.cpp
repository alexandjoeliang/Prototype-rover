#include <avr/interrupt.h>
#include <avr/io.h>
#include "loadcell.h"
#include "timer.h"
#include "ADC.h"
#include <Arduino.h>

int main(){
  initADC0();
  Serial.begin(9600);
  unsigned int result = 0;
  float voltage = 0;

  while(1){
      // print out ADC value
	// read in ADCL first then read ADCH
      result = ADCL;
      result += (ADCH) << 8;
      //Voltage_k = k * (VHigh/# of levels)
      voltage = result * (5/1024.0); // 5 v from your kit reads~4.586
      Serial.println(voltage,2);
      delayMs(500);
  }

  return 0;
}





/*
ISR(){

}
*/