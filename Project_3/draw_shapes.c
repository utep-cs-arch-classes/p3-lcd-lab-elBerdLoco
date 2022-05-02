#include "draw_shapes.h"    
#include "switches.h"

// axis zero for col, axis 1 for row
short drawPos[2] = {10,10}, controlPos[2] = {10,10};
short velocity[2] = {3,8}, limits[2] = {screenWidth-36, screenHeight-8};

short redrawScreen = 1;
u_int controlFontColor = COLOR_BLUE;


void
update_shape(void)
{
  static unsigned char row = screenHeight / 2, col = screenWidth / 2;
  static char blue = 31, green = 0, red = 31;
  static unsigned char step = 0;
  static unsigned char circle1 = 5;
  static unsigned char circle2 = 0;
  
  if (switches & SW4) return;
  if (step <= 80) {
    // a color in this BGR encoding is BBBB BGGG GGGR RRRR
    unsigned int color = (blue << 11) | (green << 5) | red;
    
    if(step <= 20){
      fillRectangle(15, 40+step, 10, 10, color);  //middle of T
      fillRectangle(40, 40+step, 10, 10, color);  //left side of o
      fillRectangle(60, 40+step, 10, 10, color);  //right side of o
      fillRectangle(5+step, 40, 10, 10, color);   //top of T 
      fillRectangle(40+step, 60, 10, 10, color);  //top of o 
      fillRectangle(40+step, 40, 10, 10, color);  //bottom of o
      fillRectangle(75, 40+step, 10, 10, color);  //left m column
      fillRectangle(95, 40+step, 10, 10, color); //midle m column
      fillRectangle(115, 40+step, 10, 10, color); //right m column
      fillRectangle(75+step, 40, 10, 10, color);  //top left row of m
      fillRectangle(95+step, 40, 10, 10, color); //top right row of m
    }
    if(step <= 50){
      fillRectangle(10 + step, 80, 5 + step, 5, color);
    }
    step++;
    if (switch1_down) {         //CAP A
      green = (green + 1) % 69;
      fillRectangle(0 + (step)*(2), 90, 40 + (step)*(2), 20 + step, color);
      if (switch2_down) {            //CAP B
	clearScreen(COLOR_YELLOW);
	drawString5x7(20, 40 + step, "This is YELLOW", COLOR_GREEN, COLOR_YELLOW);
	if (switch3_down){           //CAP C
	  clearScreen(COLOR_RED);
	  drawString5x7(20, 40 + step, "This is RED", COLOR_GREEN, COLOR_RED);
	}
      }
      else if (switch3_down) {       //CAP B
	clearScreen(COLOR_GREEN);
	drawString5x7(20, 40 + step, "This is GREEN", COLOR_RED, COLOR_GREEN);
      }
    }
    else if (switch2_down) {
      blue = (blue + 2) % 34;
      if(step <= 60){
	fillRectangle(0 + step, 150 - step, 1 + step , 1, color);
      }
      if(switch3_down) {
	clearScreen(COLOR_BLUE);
	drawString5x7(20, 40 + step, "This is BLUE", COLOR_RED, COLOR_BLUE);
      }
    }
    else if(switch3_down) {
      red = (red - 3) % 34;
      if(step <= 60){
	fillRectangle(60, 150 - step, 1 + step, 1, color);
      } 
    }
  }else {
    step = 0;
  }
}

