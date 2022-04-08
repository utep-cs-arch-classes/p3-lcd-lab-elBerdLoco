#include <msp430.h>
#include "switches.h"

void
port2_c_handler(void){
  if (P2IFG & P2_SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~P2_SWITCHES;	      /* clear pending sw interrupts */
    check_p2_switches();	      /* single handler for all port 2 switches */
  }
}
