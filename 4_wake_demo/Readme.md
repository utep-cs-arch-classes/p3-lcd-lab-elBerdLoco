# 4_wake_demo

This demo draws an hourglass shape. Unlike previous demos the interrupts
merely update a few state variables, the bulk of the update work is done by
the main driver funtion. Pressing the buttons changes the color of the
hourglass is drawn. Switch 1 removes red, switch 2 adds blue, and switch 3
adds green. This function only runs when the state has been
updated, the rest of the time it puts the CPU to sleep. It contains the
following files:

* wakedemo.c the main program loop, calls the update functions when there's
  work to do, the rest of the time puts the MSP430 to sleep
* draw_shapes.c draws the hourglass shape and changes colors based on button
  state
* p2_interrupt_handler.c handles port 2 interrupts
* switches.c handles updating when switch interrupts occur and updates switch
  state
* wdt_handler.s assembly code for handling timer interrupts, required to
  wakeup cpu, hands off rest of responsibility to c handler
* wdt_c_handler.c handles timer interrupts
