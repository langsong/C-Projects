#include <stdio.h>

void slash(int n){
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++){
      printf(" ");
    }
    printf("\\");
    printf("*");
    printf("\\");
    printf("\n");
  }
}

void num_square(int n, int m){
  for (int i = 0; i <= m - n; i++){
    for (int j = n + i; j <= m; j++){
      printf("%d", j);
    }
    for (int j = n; j < n + i; j++){
      printf("%d", j);
    }
    printf("\n");
  }
}

int calculate_whole(int n, int m){
  return n / m;
}

int calculate_remainder(int n, int m){
  return n % m;
}

void make_change(int n){
  printf("dollars  = %d\n", calculate_whole(n, 100));
  n = calculate_remainder(n, 100);
  printf("quarters = %d\n", calculate_whole(n, 25));
  n = calculate_remainder(n, 25);
  printf("dimes    = %d\n", calculate_whole(n, 10));
  n = calculate_remainder(n, 10);
  printf("nickels  = %d\n", calculate_whole(n, 5));
  n = calculate_remainder(n, 5);
  printf("cents    = %d\n", n);
}

int main(void){
  slash(3);
  slash(7);
  num_square(4, 9);
  num_square(3, 7);
  make_change(157);
  make_change(141);
  return 0;
}
