#include <msp430.h>
#include "switches.h"
#include "led.h"

extern char redraw_screen;
const char down = 1;
const char up = 0;

char switch1_state, switch2_state, switch_state_changed;

/* update he interrupt sense bits so 
   interrupts are fired when a switch changes
   position
   declared as static so it isn't visible
   outside switches.c
*/
static char 
switch_update_interrupt_sense(void)
{
  char p2val = P2IN;
  P2IES |= (p2val &  P2_SWITCHES);	// if switch up, sense down
  P2IES &= (p2val | ~P2_SWITCHES);	// if switch down, sense up
  return p2val;
}

/* setup switches */
void 
switch_p2_init(void)
{  
  P2REN |=  P2_SWITCHES;		// enables resistors for switches
  P2IE  |=  P2_SWITCHES;		// enable interrupts from switches
  //P2OUT |=  SWITCHES;		// turn on switches so we can read them
  P2DIR &= ~P2_SWITCHES;	 	// set switch pins to input
  switch_update_interrupt_sense();
}

void
check_p2_switches(void)
{
  char p2val = switch_update_interrupt_sense();
  // Switch reads 0 when down, we want to reverse
  // that so the state variable is 1 when down
  switch1_state = (p2val & SW1) ? 0 : 1;
  switch2_state = (p2val & SW2) ? 0 : 1;
  redraw_screen = 1;            // switch status changed, redraw
}
