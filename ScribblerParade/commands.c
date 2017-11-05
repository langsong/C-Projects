#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <MyroC.h>
#include <time.h>
#include "commands.h"


// moves the robot forward at speed 1.0 for the given number of seconds
void forward(double seconds)
{
  rForward(1.0, seconds);
}

// makes the robot turn for the given number of degrees in the given direction. Only 45 and 90 are valid values for degrees and left and right for direction
void turn(int degrees, char* direction)
{
  char* str1 = "left";
  char* str2 = "right";
  if (strcmp(direction, str1) == 0){
    if (degrees == 45){
      rTurnLeft(1.0, 0.4);
    }else if(degrees == 90){
      rTurnLeft(1.0, 0.8);
    }else{
      printf("Please enter a valid degree!\n");
    }
  }
  else if (strcmp(direction, str2) == 0){
    if (degrees == 45){
      rTurnRight(1.0, 0.4);
    }
    else if(degrees == 90){
      rTurnRight(1.0, 0.8);
    }
    else{
      printf("Please enter a valid degree!\n");
    }
  }
  else{
    printf("Please enter either left or right for direction!\n");
  }
}

// makes the robot rotate 360 degrees. direction can be one of left or right
void spin(char* direction){
  char* str1 = "left";
  char* str2 = "right";
  if (strcmp(direction, str1) == 0){
    rTurnLeft(1.0, 3.2);
  }else if (strcmp(direction, str2) == 0){
    rTurnRight(1.0, 3.2);
  }else{
    printf("Please enter either left or right for direction!\n");
  }
}

// makes the robot beep at 698 Hz for 1 second
void beep(){
  rBeep(1.0, 698);
}

// makes the robot play a short ditty that lasts for 1 second
void ditty(){
  rBeep(0.3, 880);
  rBeep(0.4, 1209);
  rBeep(0.3, 975);
}

// makes the robot play a song snippet that lasts for 3 seconds
void song(){
  rBeep(0.3, 880);
  rBeep(0.4, 1209);
  rBeep(0.3, 975);
  rBeep(0.3, 880);
  rBeep(0.4, 1209);
  rBeep(0.3, 975);
  rBeep(0.3, 880);
  rBeep(0.4, 1209);
  rBeep(0.3, 975);
}
