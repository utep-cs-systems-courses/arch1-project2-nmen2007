#include "binary_count.h"
#include "led.h"

void binary_count(){
  static char state = 0;

  switch(state){
  case 0:
    led_state(0,0); // bianry rep of 0, no leds on
    state = 1;
    break;

  case 1:
    led_state(0,1); // bianry rep. of 1, green is on
    state = 2;
    break;

  case 2:
    led_state(1,0); // binary rep. of 2, red is on
    state = 3;
    break;

  case 3:
    led_state(1,1); // binary rep of 3, red and green are on
    state = 0; // go back to state 0 or interrupt somewhere
    break;
  }
}
