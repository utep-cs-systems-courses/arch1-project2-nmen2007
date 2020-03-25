The Makefile in this directory contains all the rules to run the Makefile.
Use make in this directory to build the demo program and the timer
library. Once the program is built, you can load the program onto the MSP430
by being in the corresponding demo directory and using make load.

Once the program loads it will play a series of notes to mimic the Super Mario
Underworld Theme. Any Switch will stop the tune when pressed 

You may use mspdebug rf2500 "erase" to clear the program from the MSP430.
