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
  static unsigned char nameCounter = 0;
  
  
  //if (switches & SW4) return;
  if (step <= 60) {
    buzzer_init();
    buzzer_set_period(1000);
    
    // a color in this BGR encoding is BBBB BGGG GGGR RRRR
    unsigned int color = (blue << 11) | (green << 5) | red;
    if(step < 10) {
      buzzer_set_period(1000);
    }
    if(step > 30) {
      buzzer_init();
    }
    fillRectangle(15, 40+nameCounter, 10, 10, color);  //middle of T
    fillRectangle(40, 40+nameCounter, 10, 10, color);  //left side of o
    fillRectangle(60, 40+nameCounter, 10, 10, color);  //right side of o
    fillRectangle(5+nameCounter, 40, 10, 10, color);   //top of T 
    fillRectangle(40+nameCounter, 60, 10, 10, color);  //top of o 
    fillRectangle(40+nameCounter, 40, 10, 10, color);  //bottom of o
    fillRectangle(75, 40+nameCounter, 10, 10, color);  //left m column
    fillRectangle(95, 40+nameCounter, 10, 10, color); //midle m column
    fillRectangle(115, 40+nameCounter, 10, 10, color); //right m column
    fillRectangle(75+nameCounter, 40, 10, 10, color);  //top left row of m
    fillRectangle(95+nameCounter, 40, 10, 10, color); //top right row of m
    
    fillRectangle(10 + step, 80, 5 + step, 5, color); // line under name
    nameCounter++;
    if (nameCounter >= 20){
      nameCounter = 0;
    }
    step++;
    if (switch1_down) {         //CAP A
      // buzzer_init();
      // buzzer_set_period(1000);
      green = (green + 3) % 37;
      fillRectangle(0 + (step)*(2), 90, 40 + (step)*(2), 20 + step, color);
      if (switch2_down) {            //CAP B
	 step = 0;
	clearScreen(COLOR_YELLOW);
	drawString5x7(20, 10, "This is YELLOW", COLOR_GREEN, COLOR_YELLOW);
	if (switch3_down){           //CAP C
	   step = 0;
	  clearScreen(COLOR_RED);
	  drawString5x7(20, 10, "This is RED", COLOR_GREEN, COLOR_RED);
	}
      }
      else if (switch3_down) {       //CAP B
	 step = 0;
	clearScreen(COLOR_GREEN);
	drawString5x7(20, 10, "This is GREEN", COLOR_RED, COLOR_GREEN);
      }
    }
    else if (switch2_down) {         //CAP A
      // buzzer_set_period(1500);
      blue = (blue + 2) % 27;
      if(step <= 60){
	fillRectangle(step, 150 - step, 1 + step , 1, color);
      }
      if(switch3_down) {             //CAP B
	clearScreen(COLOR_BLUE);
	 step = 0;
	drawString5x7(20, 10, "This is BLUE", COLOR_RED, COLOR_BLUE);
      }
    }
    else if(switch3_down) {          //CAP A
      red = (red - 3) % 17;
      // buzzer_set_period(2000);
      if(step <= 60){
	fillRectangle(60, 150 - step, 1 + step, 1, color);
      } 
    }
    else if(switch4_down) {          //CAP A
      // buzzer_set_period(3000);
      if(step == 0 ){
	fillRectangle(9 + nameCounter, 9, 60, 20, COLOR_BLACK);
	fillRectangle(60, 9, 60, 20, COLOR_BLACK);
      }
      if(step >= 20){
	fillRectangle(60 + nameCounter, 9, 1, 20, COLOR_BLACK);
      }
      fillRectangle(5 + nameCounter, 5, 60, 20, COLOR_BLACK);
      drawString5x7(10 + nameCounter, 10, "SUCCESS!!!", COLOR_GREEN, COLOR_BLACK);
    }
  }else {
    step = 0;
  }
}

