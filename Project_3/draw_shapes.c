#include "draw_shapes.h"    
#include "switches.h"
#include <stdlib.h>

// axis zero for col, axis 1 for row
short drawPos[2] = {10,10}, controlPos[2] = {10,10};
short velocity[2] = {3,8}, limits[2] = {screenWidth-36, screenHeight-8};

short redrawScreen = 1;
u_int controlFontColor = COLOR_BLUE;

typedef struct{
  char locationX;
  char locationY;
} asteroid;

typedef struct{
  char currentX; 
  char currentY;
  char alive;
} player;

void
update_shape(void)
{
  static unsigned char row = screenHeight / 2, col = screenWidth / 2;
  static char blue = 31, green = 0, red = 31;
  static unsigned char step = 0;
  static unsigned char nameCounter = 0;
  static unsigned char songCounter = 0;
  static unsigned char clean_OX;
  static unsigned char clean_OY;
  static unsigned char clean_switch = 0;
  static unsigned char currentWidth = 0;
  static unsigned char currentHeight = 0;
  static unsigned int background = 0;
  static unsigned char state = 1;
  static unsigned char game_on = 1;
  static unsigned char astRem = 0; // Counter used for erasing asteroid from GAME OVER screen. 
  static asteroid n1 = {55, 0};
  static asteroid n2 = {25, 0};
  static asteroid n3 = {0, 120};
  static asteroid n4 = {108, 95};
  static asteroid n5 = {0, 60};
  static asteroid n6 = {108, 40};
  static player p1 = {55, 120, 1};
  
  // The bottom code was included in the original. 
  // if (switches & SW4) return;
  
  if (1) {
     
    buzzer_init();
    // songCounter += step*9; //Original songCounter. 

    songCounter += 9;
    
    // a color in this bgr encoding is bbbb bggg gggr rrrr
    unsigned int color = (blue << 11) | (green << 5) | red;
    fillRectangle(p1.currentX, p1.currentY, 20, 20, color);

    // need to fix the cleaning for the object
    
    if (n1.locationY == 160){
      fillRectangle(n1.locationX, n1.locationY, 20, 20, COLOR_BLUE);
      fillRectangle(n2.locationX, n2.locationY, 20, 20, COLOR_BLUE);
      char r1 = rand() % 108;
      char r2 = rand() % 108;
      n1.locationX = r1;
      n2.locationX = r2;
      n1.locationY = 0;
      n2.locationY = 0;
    }

    if(n3.locationX == 128 || n4.locationX == 0){
      fillRectangle(n3.locationX, n3.locationY, 20, 20, COLOR_BLUE);
      fillRectangle(n4.locationX, n4.locationY, 20, 20, COLOR_BLUE);
      fillRectangle(n5.locationX, n5.locationY, 20, 20, COLOR_BLUE);
      fillRectangle(n6.locationX, n6.locationY, 20, 20, COLOR_BLUE);
      char r3 = rand() % 140;
      char r4 = rand() % 140;
      char r5 = rand() % 140;
      char r6 = rand() % 140;
      n3.locationY = r3;
      n4.locationY = r4;
      n5.locationY = r5;
      n6.locationY = r6;
      n3.locationX = 0;
      n4.locationX = 108;
      n5.locationX = 0;
      n6.locationX = 108;
    }
     
    if (switch1_down){
      buzzer_set_period(songCounter);
      green = (green + 2) % 27;
      fillRectangle(p1.currentX--, p1.currentY, 1, 20, color);
      fillRectangle((p1.currentX + 20), p1.currentY, 1, 20, COLOR_BLUE);
      
    }
    if (switch2_down){
      buzzer_set_period(songCounter + step*50);
      blue = (blue - 2) % 19;
      fillRectangle(p1.currentX, p1.currentY--, 20, 1, color);
      fillRectangle(p1.currentX, (p1.currentY + 20), 20, 1, COLOR_BLUE);
      
    }
    if (switch3_down){
      buzzer_set_period(songCounter + step*100);
      red = (red + 2) % 9;
      fillRectangle(p1.currentX, p1.currentY++, 20, 1, color);
      fillRectangle(p1.currentX, (p1.currentY - 1), 20, 1, COLOR_BLUE);
      
    }
    if (switch4_down){
      buzzer_set_period(songCounter + step*150);
      fillRectangle(p1.currentX++, p1.currentY, 1, 20, color);
      fillRectangle((p1.currentX - 1), p1.currentY, 1, 20, COLOR_BLUE);
      
    }
    
    if (1){
      switch (state){
      case 1:
	drawString5x7(30, 100, "groovy", color, COLOR_BLUE);
	drawString5x7(5, 125, "radical", color, COLOR_BLUE);
	drawString5x7(100, 75, "cool", color, COLOR_BLUE);
	
	if (game_on){      
	  fillRectangle(n1.locationX, n1.locationY++, 20, 20, COLOR_BLACK);
	  fillRectangle(n1.locationX, (n1.locationY - 1), 20, 1, COLOR_BLUE);
	  
	  fillRectangle(n2.locationX, n2.locationY++, 20, 20, COLOR_BLACK);
	  fillRectangle(n2.locationX, (n2.locationY - 1), 20, 1, COLOR_BLUE);
	  
	  fillRectangle(n3.locationX++, n3.locationY, 20, 20, COLOR_BLACK);
	  fillRectangle((n3.locationX - 1), n3.locationY, 1, 20, COLOR_BLUE);
	  
	  fillRectangle(n4.locationX--, n4.locationY, 20, 20, COLOR_BLACK);
	  fillRectangle((n4.locationX + 20), n4.locationY, 1, 20, COLOR_BLUE);

	  fillRectangle(n5.locationX++, n5.locationY, 20, 20, COLOR_BLACK);
	  fillRectangle((n5.locationX - 1), n5.locationY, 1, 20, COLOR_BLUE);

	  fillRectangle(n6.locationX--, n6.locationY, 20, 20, COLOR_BLACK);
	  fillRectangle((n6.locationX + 20), n6.locationY, 1, 20, COLOR_BLUE); 
	}
	
	if(n1.locationX - p1.currentX <= 20 && p1.currentX - n1.locationX <= 20 && n1.locationY - p1.currentY <= 20 && p1.currentY - n1.locationY <= 20){
	  game_on = 0;
	  p1.alive = 0;
	  state = 3;
	}
	
	if (n2.locationX - p1.currentX <= 20 && p1.currentX - n2.locationX <= 20 && n2.locationY - p1.currentY <= 20 && p1.currentY - n2.locationY <= 20){
	  game_on = 0;
	  p1.alive = 0;
	  state = 3;
	}
	
	if(n3.locationX - p1.currentX <= 20 && p1.currentX - n3.locationX <= 20 && n3.locationY - p1.currentY <= 20 && p1.currentY - n3.locationY <= 20){
	  game_on = 0;
	  p1.alive = 0;
	  state = 3;
	}
	
	if(n4.locationX - p1.currentX <= 20 && p1.currentX - n4.locationX <= 20 && n4.locationY - p1.currentY <= 20 && p1.currentY - n4.locationY <= 20){
	  game_on = 0;
	  p1.alive = 0;
	  state = 3;
	}

	if(n5.locationX - p1.currentX <= 20 && p1.currentX - n5.locationX <= 20 && n5.locationY - p1.currentY <= 20 && p1.currentY - n5.locationY <= 20){
	  game_on = 0;
	  p1.alive = 0;
	  state = 3;
	}
	  if(n6.locationX - p1.currentX <= 20 && p1.currentX - n6.locationX <= 20 && n6.locationY - p1.currentY <= 20 && p1.currentY - n6.locationY <= 20){
	  game_on = 0;
	  p1.alive = 0;
	  state = 3;
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
	  n1.locationX = 25;
	  n1.locationY = 0;
	  n2.locationX = 55;
	  n2.locationY = 0;
	  n3.locationX = 0;
	  n3.locationY = 80; 
	  n4.locationX = 108;
	  n4.locationY = 80;
	  n5.locationX = 0;
	  n5.locationY = 60;
	  n6.locationX = 100;
	  n6.locationY = 40;
	  game_on = 1;
	  p1.alive = 1;
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
    fillRectangle(n1.locationX, (n1.locationY - 1), 20, 1, COLOR_BLUE);
    fillRectangle(n2.locationX, (n2.locationY - 1), 20, 1, COLOR_BLUE);
    step = 0;
    n1.locationY = 0;
    n2.locationY = 128;
    songCounter = 0;
  }
}

