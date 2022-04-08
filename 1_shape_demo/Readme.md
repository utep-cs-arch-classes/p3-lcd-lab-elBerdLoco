# 1_shape_demo

This is a simple shape drawing demo. It shows how to draw a few simple
shapes. It contains the following files:

* shape_demo.c the driver code that calls the shape drawing functions
* draw_shapes.c contains the functions that draw the shapes

A triangle is drawn by drawing a series of lines, with each line being wider
than the previous line

The circle uses Bresenham's algorithm, for reference:

https://iq.opengenus.org/bresenhams-circle-drawing-algorithm/

https://www.javatpoint.com/computer-graphics-bresenhams-circle-algorithm

https://arcade.makecode.com/graphics-math/bresenham-circle
