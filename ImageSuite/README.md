# CSC 161.02 Project 04: Image Suite

This is the repository for the fifth project of the spring 2017 semester of CSC 161 section 02. You can find the specifics of the project on the [course website](http://www.cs.grinnell.edu/~klingeti/courses/s2017/csc161/homeworks/05-image-suite.html).

## Project Information
Won Seok Chung, Lang Song
[chungwon], [songlang]

## Project Overview
The project is in three parts.

1a) circleSelect takes a pointer to a Picture, the radius of a circle and the x- and y-coordinates of its center (all given as integers), and turns each pixel within that circle to its corresponding grayscale value.

1b) tornEdges takes a pointer to a Picture and applies a torn edges effect to the image.

2 - Our filter) coloredDotXray takes a pointer to a picture and applies
x-ray resembling, but with dots colored effect. If the column value or row
value of pixel is even, RGB will be inverted by subtracting each RGB
component from 255, which is the maximum greyscale value. If not, the R
component will be randomly generated within 0-255 range and G component will
be randomly generated within 0-255 range and then modulo will
be applied so that the random value becomes equal to or less than its
origianl value. The B component will be fixed to 255. Because of the B
component, the picture is likely to be blue most time the program gets run. 

## Citations
CSC161 Reading, Header Files
