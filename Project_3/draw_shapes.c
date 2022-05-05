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
  static unsigned char songCounter = 0;
  static unsigned char bounce2 = 0;
  static unsigned char currentX = 0;
  static unsigned char currentY = 0;
  static unsigned char currentWidth = 0;
  static unsigned char currentHeight = 0;
  static unsigned int background = 0;
  static unsigned char state = 0;


  
  
  //if (switches & SW4) return;
  if (step <= 60) {
    buzzer_init();
    songCounter += step*11;
    
    // a color in this BGR encoding is BBBB BGGG GGGR RRRR
    unsigned int color = (blue << 11) | (green << 5) | red;
    fillRectangle(15, 15+nameCounter, 10, 10, color);  //middle of T
    fillRectangle(40, 15+nameCounter, 10, 10, color);  //left side of o
    fillRectangle(60, 15+nameCounter, 10, 10, color);  //right side of o
    fillRectangle(5+nameCounter, 15, 10, 10, color);   //top of T 
    fillRectangle(40+nameCounter, 35, 10, 10, color);  //top of o 
    fillRectangle(40+nameCounter, 15, 10, 10, color);  //bottom of o
    fillRectangle(75, 15+nameCounter, 10, 10, color);  //left m column
    fillRectangle(95, 15+nameCounter, 10, 10, color); //midle m column
    fillRectangle(115, 15+nameCounter, 10, 10, color); //right m column
    fillRectangle(75+nameCounter, 15, 10, 10, color);  //top left row of m
    fillRectangle(95+nameCounter, 15, 10, 10, color); //top right row of m
    
    fillRectangle(10 + step, 50, 5 + step, 10, color); // line under name
    nameCounter++;
    if (nameCounter >= 20){
      nameCounter = 0;
    }
    step++;

    if (switch1_down){
      buzzer_set_period(songCounter);
      drawString5x7(5, 125, "RADICAL", COLOR_RED, color);
      state = 1;
    }
    if (switch2_down){
      buzzer_set_period(songCounter + step*100);
      drawString5x7(30, 100, "GROOVY", COLOR_GREEN, color);
      state = 2;
    }
    if (switch3_down){
      buzzer_set_period(songCounter + step*300);
      drawString5x7(100, 75, "COOL", COLOR_BLUE, color);
      state = 3;
    }
    if (switch4_down){
      state = 4;
    }

    switch (state){
    case 1:
      fillRectangle(0 + (step)*(2), 70, (step)*(2), 20 + step, color);
      green = (green + 3) % 37;
      break;
    case 2:
      
      fillRectangle(75, 160 - step, 5 + step, 5, color);
      blue = (blue + 2) % 27;
      break;
    case 3:
      currentX += 1;
      currentY += 2;
      fillRectangle(75 - currentX, 140 - currentX, 1, 1 + currentY, color);
      red = (red - 3) % 17;
      break;
    case 4:
      clearScreen(color);
      break;
    default:
      buzzer_init();
      break;
    }

  }else {
    step = 0;
    bounce2 = 0;
    currentX = 0;
    currentY = 0;
    currentWidth = 0;
    currentHeight = 0;
  }
}

