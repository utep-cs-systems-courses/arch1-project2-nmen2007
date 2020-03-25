#ifndef led_included
#define led_included

#define LED_RED BIT0 //p1.0
#define LED_GREEN BIT6 //p1.6
#define LEDS (BIT0 | BIT6)

void led_init(); //Initialize led

int led_state(int red_state, int green_state);

#endif // end led_included
