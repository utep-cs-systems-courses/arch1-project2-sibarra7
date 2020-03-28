#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

char play_song = 0;

int notes[34] = {B5, B5, C6, B5, G5, D5, E5, A5, G5, F5, F5, G5, A5, D5, F5, G5, Bb5, D5, D5,
		 D6, C6, B5, A5, G6, A5, B5, B5, G5, E5, B5, G5, D5, A5, G5};

int note_duration[34] = {100, 100, 200, 100, 100, 200, 200, 100, 100, 100, 100, 100, 100, 200,
			 200, 100, 100, 100, 200, 200, 100, 100, 100, 100, 100, 200, 100, 100,
			 200, 200, 100, 100, 100};

int delay_time[34] = {4, 4, 12, 4, 4, 12, 10, 15, 4, 4, 4, 4, 15, 5, 5, 5,
		      5, 25, 5, 5, 5, 5, 25, 4, 4, 12, 4, 4, 12, 10, 5, 4,
		      4};

void buzzer_init()
{
  /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
  */
  timerAUpmode();/* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;/* one half cycle */
}


