#include <msp430.h>
#include <stdlib.h>
#include "state_machine.h"
#include "led.h"


/*void toggle() {

  static char state = 0;

  switch (state) {

  case 0:
    red_on   = 0;
    green_on = 0;
    state    = 1;
    break;

  case 1:
    red_on   = 0;
    green_on = 1;
    state    = 2;
    break;

  case 2:
    red_on   = 1;
    green_on = 0;
    state    = 3;
    break;

  case 3:
    red_on   = 1;
    green_on = 1;
    state    = 0;
    break;
  }
  }*/

void reset_state() {
  red_on = 0;
  green_on = 0;
  led_update();
}

void led_state(unsigned char g, unsigned char r) {
  green_on = g;
  red_on = r;
  led_changed = 1;
  led_update();
}

void delay(unsigned int a)
{
  unsigned int i;
  for(i = a; i > 0; i--)
    __delay_cycles(1);
}

void dim(){

  while (dim_on) {

    unsigned int i;

    for (i = 1; i < 1200; i++) {

      led_state(1,0);

      delay(i);



      led_state(0,1);

      delay(1200-i);

    }

    for (i = 1200; i > 1; i--) {

      led_state(1,0);

      delay(i);



      led_state(0,1);

      delay(1200-i);

    }



  }

}

