#ifndef _SWITCHES_H_
#define _SWITCHES_H_

#include <msp430.h>

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

#define LED BIT6		/* note that bit zero req'd for display */

#define SW1 1                   /* BIT0 */
#define SW2 2                   /* BIT1 */
#define SW3 4                   /* BIT2 */
#define SW4 8                   /* BIT3 */

#define SWITCHES 15             /* 1 + 2 + 4 + 8 */

extern int switches;            /* current state of switches */
extern char switch1_down;
extern char switch2_down;
extern char switch3_down;


/* initializes the switches  */
void switch_init(void);
/* Handles switch interrupts */
void switch_interrupt_handler(void);

#endif // _SWITCHES_H_
