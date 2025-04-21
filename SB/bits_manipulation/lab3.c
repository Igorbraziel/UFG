#include <stdio.h>



unsigned int convertB2L(unsigned int x) {
    unsigned int firstByte = x >> 24;
    unsigned int secondByte = (x >> 8) & 0xFF00;
    unsigned int thirdByte = (x << 8) & 0XFF0000;
    unsigned int fourthByte = x << 24;
    return fourthByte | thirdByte | secondByte | firstByte;
}



int main() {

  unsigned int b = 0x12AB34CD;

  unsigned int l = convertB2L(b);



  printf("b = 0x%08X\n", b);

  printf("l = 0x%08X\n", l);



  return 0;

}