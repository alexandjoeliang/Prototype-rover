// Author:  Alex Liang
// Net ID: 
// Date:    10/21/24
// Assignment:     Lab 3
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
// Requirements:
//----------------------------------------------------------------------//




#include <avr/interrupt.h>
#include <avr/io.h>
#include "led.h"
#include "switch.h"
#include "timer.h"
#include "lcd.h"

// defines


/*
 * Define a set of states that can be used in the state machine using an enum.
 */
// typedef enum .......
typedef enum speedEnum {fast_speed, slow_speed} speedEnum;
typedef enum stateEnum {wait_press, debounce_press, wait_release, debounce_release} stateType;


// Initialize states.  Remember to use volatile 
volatile speedEnum s = slow_speed;
volatile stateType state = wait_press;



int main(){

  initTimer1();
  initLCD();
  initSwitchPB3();
  initLED();
  initTimer0();
  sei(); // Enable global interrupts.
  moveCursor(0, 0); // moves the cursor to 0,0 position
  writeString("Current mode: ");
  moveCursor(1, 0);  // moves the cursor to 1,0 position
  writeString("Slow");

// while loop
  unsigned char led = 0;
  while(1) {
    switch(state){
      case wait_press:
      break;
      case debounce_press:
        delayMs(1);
        state = wait_release;
      break;
      case wait_release:
      break;
      case debounce_release:
        delayMs(1);
        state = wait_press;
      break;
    }
    if (led < 15) {
      led++;
    } else if (led == 15) {
      led = 0;
    }
    turnOnLEDWithChar(led);
    switch(s) {
      case fast_speed:
        moveCursor(1, 0);
        writeString("Fast");
        delayMs(100);
      break;
      case slow_speed:
      moveCursor(1, 0);
        writeString("Slow");
        delayMs(200);
      break;
    }
  }
  return 0;
}
/* Implement an Pin Change Interrupt which handles the switch being
* pressed and released. When the switch is pressed and released, the LEDs
* change at twice the original rate. If the LEDs are already changing at twice
* the original rate, it goes back to the original rate.
*/
ISR(PCINT0_vect){
  if (state == wait_press){
    state = debounce_press;
  } else if (state == wait_release){
    if (s == slow_speed){
      s = fast_speed;
    } else if (s == fast_speed){
      s = slow_speed;
    }
    state = debounce_release;
  }
}