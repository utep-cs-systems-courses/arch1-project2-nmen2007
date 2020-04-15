#include <msp430.h>
#include "led.h"
#include "buzzer.h"
#include "timer.h"

// Super Mario underworld song
static int song[] = {C6, C7, A5, A6, AS5, AS6, 0, 0, C6, C7, A5, A6, AS5, AS6, 0, 0, F5, F6, D5, D6, DS5, DS6, 0, 0, F5, F6, D5, D6, DS5, DS6, 0, 0, DS6, CS6, D6, CS6, DS6, DS6, GS5, G5, CS6, C6, FS6, F6, E5, AS6, A6, GS6, DS6, B5, AS5, A5, GS5, 0, 0, 0 };

static int song_pace[] = {12, 12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6, 18, 18, 18, 6, 6, 6, 6, 6, 6, 18, 18, 18, 18, 18, 18, 10, 10, 10, 10, 10, 10, 3, 3, 3 };

static unsigned short duration = 500; // 500ms
static unsigned short current_note = 0;
static unsigned short tot_duration = 0; // total duration

char buzzer_state = 0;

void buzzer_init(){ //Initialize speaker and buzzer method

  timerAUpmode(); // used to drive speaker

  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR |= BIT6; //enable output to speaker(P2.6)

  tot_duration = (int)(duration / song_pace[0]);
  buzzer_state = BUZZER_OFF;
  current_note = 0;

}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1; //one half cycle
}

void buzzer_play(){

  buzzer_state = BUZZER_ON; // buzzer is playing set the state

  int note = song[current_note]; // set current note to song

  if(note < 0){ // if song ends
    buzzer_state = BUZZER_OFF;
    current_note = 0;
    return;
  }

  if(note == 0){
    led_state(1, 0); // Red Led on when song is off
  }

  else{
    led_state(0, 0); // turn off Leds
  }

  buzzer_set_period(note); // play current not

  tot_duration--; // decrement the duration

  if(tot_duration <= 1){ // check if end of the note
    current_note++; //increment to next note
    tot_duration = (int)(duration / song_pace[current_note]); // update song timing
  }
}

    
