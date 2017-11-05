// Project 04: Image Suite
// Won Seok Chung, Lang Song
// CSC-161-02

#include <stdio.h>
#include <MyroC.h>
#include <math.h>
#include <stdlib.h>


// circleSelect takes a pointer to a picture, the radius of a circle and the x- and y-coordinates of its center (all given as integers), and turns each pixel within that circle to its corresponding grayscale value.

void circleSelect(Picture * pic, int r, int x, int y) {
  int width = pic->width;
  int height = pic->height;   
    for (int row = 0; row < height; row++) {
      for (int col = 0; col < width; col++) {
        if (sqrt(pow((col-x), 2) + pow((row-y), 2)) <= r) {
          double grey = (0.30 * pic->pix_array[row][col].R) + (0.59 * pic->pix_array[row][col].G) + (0.11 * pic->pix_array[row][col].B);
          pic->pix_array[row][col].R = grey;
          pic->pix_array[row][col].G = grey;
          pic->pix_array[row][col].B = grey;
          }
       }
    }
}

// tornEdges takes a pointer to a Picture and applies a torn edges effect to the image.

void tornEdges(Picture * pic) {
  int width = pic->width;
  int height = pic->height;
  int count = 0;
  int array[50000], num, val, x;

  // Creates an array 
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      int grey = (0.30 * pic->pix_array[row][col].R) + (0.59 * pic->pix_array[row][col].G) + (0.11 * pic->pix_array[row][col].B);
      array[count] = grey;
      count = count + 1;
    }
  }

  // Sorts greyscale values of pixels in an increasing order
  for (num = 1 ; num <= count - 1; num++) {
    val = num;
    while ( val > 0 && array[val] < array[val-1]) {
      x = array[val];
      array[val] = array[val-1];
      array[val-1] = x;
      val--;
    }
  }

  // Uses the middle value and transforms pixels based on the middle value  
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      int grey = (0.30 * pic->pix_array[row][col].R) + (0.59 * pic->pix_array[row][col].G) + (0.11 * pic->pix_array[row][col].B);
      if (grey < array[count/2]) {
        pic->pix_array[row][col].R = 255;
        pic->pix_array[row][col].G = 255;
        pic->pix_array[row][col].B = 255;
      } else {
        pic->pix_array[row][col].R = 0;
        pic->pix_array[row][col].G = 0;
        pic->pix_array[row][col].B = 0;
      }
    }
  }
}


//coloredDotXray takes a pointer to a picture and applies dotted effect with x-ray visuals. It uses random values to change the color of some pixels each time the program is run.

void coloredDotXray(Picture * pic) {
  int width = pic->width;
  int height = pic->height;
  int ran = rand() % 255;
    for (int row = 0; row < height; row++) {
      for (int col = 0; col < width; col++) {
        if ((col % 2 == 0) || (row % 2 == 0)) {
          double invR = 255 - pic->pix_array[row][col].R;
          double invG = 255 - pic->pix_array[row][col].G;
          double invB = 255 - pic->pix_array[row][col].B;
          pic->pix_array[row][col].R = invR;
          pic->pix_array[row][col].G = invG;
          pic->pix_array[row][col].B = invB; 
        }  else {pic->pix_array[row][col].R = ran;
          pic->pix_array[row][col].G = ran % 255;
          pic->pix_array[row][col].B = 255;}
        } 
    }
}

// Main

int main(){
  rConnect("/dev/rfcomm0");
  srand(time(NULL));
  Picture pic1 = rTakePicture();
  rTurnLeft(1.0, 0.7);
  Picture pic2 = rTakePicture();
  rTurnLeft(1.0, 0.7);
  Picture pic3 = rTakePicture();
  rDisplayPicture(&pic1, 5, "Picture 1 - Original");
  rDisplayPicture(&pic2, 5, "Picture 2 - Original");
  rDisplayPicture(&pic3, 5, "Picture 3 - Original");
  rSavePicture(&pic1, "Picture 1 - Original");
  rSavePicture(&pic2, "Picture 2 - Original");
  rSavePicture(&pic3, "Picture 3 - Original");
  circleSelect(&pic1, 5, 150, 150);
  tornEdges(&pic2);
  coloredDotXray(&pic3);
  rDisplayPicture(&pic1, 5, "Picture 1 with greyscaled circle selected");
  rDisplayPicture(&pic2, 5, "Picture 2 with torn edges effect");
  rDisplayPicture(&pic3, 5, "Picture 3 with colored dot x-ray effect");
  rSavePicture(&pic1, "Picture 1 with greyscaled circle selected");
  rSavePicture(&pic2, "Picture 2 with torn edges effect");
  rSavePicture(&pic3, "Picture 3 with colored dot x-ray effect"); 
  rDisconnect();
  return 0;
}
