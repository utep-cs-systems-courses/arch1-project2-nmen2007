The Makefile in this directory contains all the rules to run the Makefile.
Use make in this directory to build the demo program and the timer
library. Once the program is built, you can load the program onto the MSP430
by being in the corresponding demo directory and using make load.

Once the program loads it will play a series of notes to mimic the Super Mario
Underworld Theme. SW1 & SW2 will interrupt and stop the tune of the song when
pressed.

SW3 will dim the green light when pressed.

SW4 will turn the leds on or off depending on what state it is in, the first
press wll be state zero and no lights will be on, one press will be in state
one and will be (0,1) so the green led will turn on, the next press itll be
state(1,0) so the red light will be on. and the final state and press of the
button will be (1,1) so both leds will be on, if you press once more it'll
turn both leds back off and return to state 0.

You may use mspdebug rf2500 "erase" to clear the program from the MSP430.
