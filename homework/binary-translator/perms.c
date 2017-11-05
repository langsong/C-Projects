#include <stdio.h>
#include <sys/stat.h>
#include <math.h>


void writePermissionString(int perms, char str[9]){
  for (int i = 8; i >= 0; i--)
    {
      if ((perms&1)==1){
        if (i%3 == 2){
          str[i] = 'x';
          } else {
          if (i%3 == 1){
            str[i] = 'w';
            } else {
            str[i] = 'r';
          }
        }
      }
      else {
        str[i] = '-';
        }
      perms = perms >> 1;
    }
}


int generatePermissionBits(char str[9]){
  int ret = 0;
  int base = 1;
  for (int i = 8; i >= 0; i--)
    {
      if (str[i]!='-'){
        ret += base;
      }
      base *= 2;
    }
  return ret;
}


int main()
{
  char perms[10];
  perms[9] = '\0';
  writePermissionString(0755,perms);
  printf("%s\n",perms);

  int p=generatePermissionBits(perms);
  printf("%o\n",p);

  return 0;
}
