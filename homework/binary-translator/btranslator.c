#include <stdio.h>


// convert binary string to integral value
unsigned char binaryStringToValue(char digits[8])
{
  int ret = 0;
  ret = ret + (digits[0] - '0') * 128 + (digits[1] - '0') * 64 + (digits[2] - '0') * 32 + (digits[3] - '0') * 16 + (digits[4] - '0') * 8 + (digits[5] - '0') * 4 + (digits[6] - '0') * 2 + (digits[7] - '0') * 1;
  return ret;
}


// convert an integral value to a binary string
void writeValueAsBinaryString(unsigned char val, char digits[8])
{
  int divider = 128;
  for(int i = 0; i < 8; i++)
    {
      digits[i] = val / divider + '0'; 
      val %= divider;
      divider /= 2;
    }
}


// convert a two-digit hexadeximal string to integral value
unsigned char hexStringToValue(char digits[2])
{
  int ret = 0;
  ret = ret + (digits[0] - '0') * 8 + (digits[1] - '0') * 1;
  return ret;
}


// convert an intergral value to a two-digit hexadecimal string
void writeValueAsHexString(unsigned char val, char digits[2])
{
  int divider = 8;
  for(int i = 0; i < 2; i++)
    {
      digits[i] = val / divider + '0'; 
      val %= divider;
      divider /= 8;
    }
}

int main()
{
  char bin[8] = "00000010";
  char hex[2] = "63";
  printf("%d\n", binaryStringToValue(bin));
  printf("%d\n", hexStringToValue(hex));
  unsigned char a = 194;
  unsigned char b = 21;
  writeValueAsBinaryString(a, bin);
  printf("%s\n", bin);
  writeValueAsHexString(b, hex);
  printf("%s\n", hex);
  return 0;
}
