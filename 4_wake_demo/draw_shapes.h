#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_

#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"

extern short redrawScreen;

/* draws an hourglass shape */
void update_shape(void);

#endif // _DRAW_SHAPES_H_
