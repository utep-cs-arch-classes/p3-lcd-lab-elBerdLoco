# 3_moving_shapes

This demo shows several shapes moving on screen. The timer interrupt is used
to update and redraw shape positions once per second. To keep shapes from
ghosting all of the old shapes are removed before drawing them at their new
positions.

This demo contains the following files:
* moving_demo.c the driver code that initializes everything
* wdtInterruptHandler.c the timer interrupt that calls the function to update
shape locations
* draw_shapes.c The code that draws the shapes and updates their positions
