#include <avr/interrupt.h>
#include <avr/io.h>
#include "switch.h"
#include "timer.h"

// defines


/*
 * Define a set of states that can be used in the state machine using an enum.
 */
// typedef enum .......

//slow speed - stepper motor off
//fast speed - stepper motor on
typedef enum speedEnum {fast_speed, slow_speed} speedEnum;
typedef enum stateEnum {wait_press, debounce_press, wait_release, debounce_release} stateType;


// Initialize states.  Remember to use volatile 
volatile speedEnum speed = slow_speed;
volatile stateType state = wait_press;



int main(){

  initTimer1();
  initSwitchPB0();
  initTimer0();

  sei(); // Enable global interrupts.

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
    if (speed == slow_speed){
      speed = fast_speed;
    } else if (speed == fast_speed){
      speed = slow_speed;
    }
    state = debounce_release;
  }
}