#ifndef _PARADE_H_
#define _PARADE_H_

// moves the robot forward at speed 1.0 for the given number of seconds
void forward(double seconds);

// makes the robot turn for the given number of degrees in the given direction. Only 45 and 90 are valid values for degrees and left and right for direction
void turn(int degrees, char* direction);

// makes the robot rotate 360 degrees. direction can be one of left or right
void spin(char* direction);

// makes the robot beep at 698 Hz for 1 second
void beep();

// makes the robot play a short ditty that lasts for 1 second
void ditty();

// makes the robot play a song snippet that lasts for 3 seconds
void song();


#endif
