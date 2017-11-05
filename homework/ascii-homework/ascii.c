#include <stdio.h>
#define NUM_STEPS 3

void problem1(void) {
  for (int i = 0; i < 6; i++) {
    for (int j = 6; j > i; j--) {
      printf("*");
    }
    printf("\n");
  }}

void problem2(void) {
  for (int i = 0; i < 6; i++) {
    for (int j = 5; j > i; j--) {
      printf(".");
    }
    for (int j = 0; j < (2 * i + 1); j++) {
    printf("#");
    }
    for (int j = 5;  j > i; j--) {
     printf(".");
    }
    printf("\n");
  }}

void triangles(void) {
  for (int i = 0; i < 5; i++) {
    for (int j = 2 * NUM_STEPS + 7; j > i; j--){
      printf(" ");
    }
    printf("/");
    for (int j = 0; j < 2 * i; j++) {
      if ( j % 2 == 0 ) {
        printf("/");
      }
      else {
        printf("\\");
      }
    }
    printf("\\");
    printf("\n");
  }
}

void percent(void) {
  printf("| %%");
  for (int i = 0; i < 4; i++) {
    printf(" ");
  }
  printf("%% |");
}

void part1(void) {
  for (int i = 0; i < 2 * NUM_STEPS + 3; i++) {
    printf("-");
  }
  percent();
  for (int i = 0; i < 2 * NUM_STEPS + 3; i++) {
    printf("-");
  }
  printf("\n");
}

void part2(void) {
  for (int i = 0; i < 2 * NUM_STEPS + 3; i++) {
    if ( i % 2 == 0 ) {
      printf(" ");
        }
    else {
      printf("o");
        }
  }
  percent();
  for (int i = 0; i < 2 * NUM_STEPS + 3; i++) {
    if ( i % 2 == 0 ) {
      printf(" ");
        }
    else {
      printf("o");
        }
  }
  printf("\n");
}

void secondpart(void) {
  part1();
  part2();
  part1();
}

void thirdpart(void) {
  for (int i = 0; i < NUM_STEPS; i++) {
     for (int j = 0; j < 2; j++) {
        for (int k = 2 * NUM_STEPS + 3 - 2 * i - j; k > 0; k--) {
          if ( k % 2 == 1 ) {
            printf("~");
            }
          else {
            printf("^");
            }
        }
        printf("/");
        for (int k = 0; k < 2 * ( 2 * i + j + 4 ); k++) {
          printf("-");
        }
        printf("\\");
        for (int k = 2 * NUM_STEPS + 3 - 2 * i - j ; k > 0; k--) {
          if ( k % 2 == 1 ) {
            printf("~");
          }
          else {
            printf("^");
          }
        }
        printf("\n");
     }
     for (int j = 2 * NUM_STEPS + 2 - 2 * i; j > 0; j--) {
       printf(" ");
     }
     printf("|");
     for (int j = 0; j < 10 + 4 * i; j++) {
       printf("=");
     }
     printf("|");
     for (int j = 8 - 2 * i; j > 0; j--) {
       printf(" ");
     }
     printf("\n");
  }
}

void fourthpart(void) {
  for (int i = 0; i < 3; i++) {
    printf(" ");
  }
  printf("/");
  for (int i = 0; i < 4 * NUM_STEPS + 8; i++) {
    printf(" ");
  }
  printf("\\");
  printf("\n");
}

void fifthpart(void) {
  for (int i = 0; i < 2; i++) {
    printf(" ");
  }
  printf("/  ");
  for (int i = 0; i < 4 * NUM_STEPS + 6; i++) {
    printf("=");
  }
  printf("  \\");
  printf("\n");
}

void sixthpart(void) {
  printf(" /  / ");
  for (int i = 0; i < 4 * NUM_STEPS + 4; i++) {
    printf("\"");
  }
  printf(" \\  \\");
  printf("\n");
}

void seventhpart(void) {
  printf("|  | ");
  for (int i = 0; i < 4 * NUM_STEPS + 6; i++) {
    printf("\"");
  }
  printf(" |  |");
  printf("\n");
}

void eighthpart(void) {
  printf(" \\  \\ ");
  for (int i = 0; i < 4 * NUM_STEPS + 4; i++) {
    printf("\"");
  }
  printf(" /  /");
  printf("\n");
}

void ninthpart(void) {
  for (int i = 0; i < 2; i++) {
    printf(" ");
  }
  printf("\\  ");
  for (int i = 0; i < 4 * NUM_STEPS + 6; i++) {
    printf("=");
  }
  printf("  /");
  printf("\n");
}

void tenthpart(void) {
  for (int i = 0; i < 3; i++) {
    printf(" ");
  }
  printf("\\");
  for (int i = 0; i < 4 * NUM_STEPS + 8; i++) {
    printf("_");
  }
  printf("/");
  printf("\n");
}

void problem3(void) {
  triangles();
  secondpart();
  thirdpart();
  fourthpart();
  fifthpart();
  sixthpart();
  seventhpart();
  eighthpart();
  ninthpart();
  tenthpart();
}

int main(void) {
  problem1();
  problem2();
  problem3();
  return 0;
    } 
      
      
