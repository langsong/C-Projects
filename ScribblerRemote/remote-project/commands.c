#include <stdio.h>
#include <MyroC.h>
#include "commands.h"


void turnaround(void){
  rTurnLeft(1.0, 1.6);
}

void sing(void){
  rBeep(0.375, 880);
  rBeep(0.375, 1209);
  rBeep(0.50, 975);
}

void rightangleleft(void){
  rForward(1.0, 1.7);
  rTurnLeft(1.0, 0.8);
  rForward(1.0, 1.4);
}

void rightangleright(void){
  rForward(1.0, 1.7);
  rTurnRight(1.0, 0.8);
  rForward(1.0, 1.4);
}

void backandforth(void){
  rForward(1.0, 2.1);
  rBackward(1.0, 1.3);
  rForward(1.0, 0.7);
  rBackward(1.0, 2.9);
}

void forward(int a){
  rForward(1.0, (double)a);
}

void backward(int a){
  rBackward(1.0, (double)a);
}

void turnleft(int a){
  rTurnLeft(1.0, a);
}

void turnright(int a){
  rTurnRight(1.0, a);
}

void beep(int a){
  rBeep(a, 880);
}

void help(void){
  printf("turnaround - the car will turn 180 degrees\n");
  printf("sing - the car will sing beautifully\n");
  printf("rightangleleft - the car will make a 90 degree left turn\n");
  printf("rightangleright - the car will make a 90 degree right tur\n");
  printf("backandforth - the car will go back and forth\n");
  printf("forward a - the car will go forward for a seconds\n");
  printf("backward a - the car will go backward for a seconds\n");
  printf("turnleft a - the car will turn left for a seconds\n");
  printf("turnright a - the car will turn right for a seconds\n");
  printf("beep a - the car will beep a beautiful sound for a seconds\n");
}

void quit(void){

}
