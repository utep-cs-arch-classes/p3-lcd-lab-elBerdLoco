#include "draw_shapes.h"

/* the interupt handler for the watchdog timer */
void wdt_c_handler(void)
{
  static int secCount = 0;

  secCount ++;
  if (secCount >= 25) {		/* 10/sec */
    secCount = 0;
    redrawScreen = 1;
  }
}
  
