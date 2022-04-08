#ifndef switches_included
#define switches_included

#define SW1 BIT0		/* switch 1 is p2.0 */
#define SW2 BIT1                /* switch 2 is p2.1 */
#define P2_SWITCHES (SW1 | SW2) /* Using left 2 switches on upper board */

void switch_p2_init(void);         /* Initializes the port 2 switches */
void check_p2_switches(void);      /* Checks the port 2 switches */

extern const char down;
extern const char up;

extern char switch1_state, switch2_state;

#endif // included
