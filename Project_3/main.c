#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
// #include "draw_shapes.h" /* This is for original project, note out Tetris.h to use this  */
#include "switches.h"
#include "libTimer.h"  /* This was added for buzzer */
#include "Tetris.h" /* This is for Tetris, note out draw_shapes.h to use this  */


// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

void main()
{
  
  P1DIR |= LED;		/**< Led on when CPU on */
  P1OUT |= LED;
  configureClocks();
  lcd_init();
  switch_init();
  
  // buzzer_init();             /* added for buzzer */
  // buzzer_set_period(1000);   /* added for buzzer */

  
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  
  clearScreen(COLOR_BLUE);
  while (1) { //val is 1			/* forever */
    if (redrawScreen) {
      redrawScreen = 0;
      update_shape();
    }
    P1OUT &= ~LED;	/* led off */
    or_sr(0x10);	/**< CPU OFF */
    P1OUT |= LED;	/* led on */
  }
}
