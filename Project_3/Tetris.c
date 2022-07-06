#include "draw_shapes.h"    
#include "switches.h"
#include <stdlib.h>

// axis zero for col, axis 1 for row
short drawPos[2] = {10,10}, controlPos[2] = {10,10};
short velocity[2] = {3,8}, limits[2] = {screenWidth-36, screenHeight-8};

short redrawScreen = 1;
u_int controlFontColor = COLOR_BLUE;



typedef struct{
  char currentX; 
  char currentY;
} player;

void
update_shape(void)
{
  static unsigned char row = screenHeight / 2, col = screenWidth / 2;
  static char blue = 31, green = 0, red = 31;
  static unsigned char step = 0;
  static unsigned char xAxis = 0;
  static unsigned char yAxis = 0;
  static unsigned char yCounter = 0;
  static unsigned char songCounter = 0;
  static unsigned char clean_switch = 0;
  static unsigned char currentWidth = 0;
  static unsigned char currentHeight = 0;
  static unsigned int background = 0;
  static unsigned char state = 1;
  static unsigned char game_on = 1;
  static unsigned char astRem = 0; // Counter used for erasing asteroid from GAME OVER screen. 
  static player p1 = {55, 0, 3, 0};
  static char systemTetris [7][9];
  
  // The bottom code was included in the original. 
  // if (switches & SW4) return;
  
  if (1) {
    
    buzzer_init();
    // songCounter += step*9; //Original songCounter. 

    songCounter += 9;
    
    // a color in this bgr encoding is bbbb bggg gggr rrrr
    unsigned int color = (blue << 11) | (green << 5) | red;
    fillRectangle(p1.currentX, p1.currentY, 18, 18, color);

    fillRectangle(p1.currentX, p1.currentY++, 18, 18, color);
    fillRectangle(p1.currentX, (p1.currentY - 1), 18, 1, COLOR_BLUE);
    
    // REMINDER!!! Need to fix this, can be implemented better. REMINDER!!!
    
    if (p1.currentY == 34){
      yAxis = 1;
    }
    
    if (p1.currentY == 52){
      yAxis = 2;
    }
    
    if (p1.currentY == 70){
      yAxis = 3;
    }
    
    if (p1.currentY == 88){
      yAxis = 4;
    }
    
    if (p1.currentY == 106){
      yAxis = 5;
    }
    
    if (p1.currentY == 124){
      yAxis = 6;
    }
    
    if (p1.currentY == 142){
      yAxis = 7;
      systemTetris[xAxis][yAxis] = 1;
      p1.currentY = 0;
      yAxis = 0;
      yCounter = 0;
    }
    
    if (switch1_down){
      green = (green + 2) % 27;
      if(p1.currentX > 1 && systemTetris[xAxis][yAxis] != 1){
	fillRectangle(p1.currentX, p1.currentY, 1, 18, COLOR_BLUE);
	p1.currentX -= 18;
	xAxis--;
      }
    }
    if (switch2_down){
      blue = (blue - 2) % 19;
      fillRectangle(p1.currentX, p1.currentY--, 18, 1, color);
      fillRectangle(p1.currentX, (p1.currentY + 18), 18, 1, COLOR_BLUE);
      
    }
    if (switch3_down){

      red = (red + 2) % 9;
    }
    if (switch4_down){
      if (p1.currentX < 107){
	fillRectangle(p1.currentX, p1.currentY, 1, 18, COLOR_BLUE);
	p1.currentX += 18;
	xAxis++;
      }
    }

    
    
    if (1){
      switch (state){
      case 1:
	// buzzer_set_period(songCounter + step*2);
	// drawString5x7(30, 100, "groovy", color, COLOR_BLUE);
	// drawString5x7(5, 125, "radical", color, COLOR_BLUE);
	// drawString5x7(100, 75, "cool", color, COLOR_BLUE);
	
	if (systemTetris [xAxis][(yAxis + 1)] == 1){
	  systemTetris[xAxis][yAxis] = 1;
	  p1.currentY = 0;
	  yAxis = 0;
	  yCounter = 0;
	}
	
	break;
	
      case 2:
	
	if (!game_on){
	  
	  drawString5x7(40, 10, "GAME OVER", color, COLOR_BLUE);
	  drawString5x7(30, 30, "TRY AGAIN ?", color, COLOR_BLUE);
	  drawString5x7(55, 140, "YES", color, COLOR_BLUE);
	}
	
	if (game_on == 0 && p1.currentX >= 45 && p1.currentX <= 65 && p1.currentY >= 125){
	  clearScreen(COLOR_BLUE);
	  
	  game_on = 1;
	  
	  state = 1;
	}
	break;
	
      case 3:
	// currentX += 1;
	clearScreen(COLOR_BLUE);
	state = 2;
	break;
	
      case 4:
	// clearScreen(color);
	break;
	
      default:
	buzzer_init();
	break;
      }
    }
    step++;
    
  }else {
    step = 0;
    songCounter = 0;
  }
}

