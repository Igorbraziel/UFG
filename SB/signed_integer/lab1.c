#include <stdio.h>

#include <stdlib.h>



int xbyte(unsigned int word, int bytenum) {

  unsigned char byte = (word >> (bytenum * 8)) & 0xFF;

  if(byte & 0x80){
    if(byte & 0x40){
        return ((word | 0xFFFFFFFF) & (0xFF00FFFF)) | (byte << 16);
    } else {
        return (byte << 8); 
    }
  } else {
    return 0xFFFFFF00 | byte;
  }

}



int main(int argc, char **argv) {

  int x;



  x = xbyte(0x01ABCD02, 0);

  printf ("0x%08X\n", x);    // 0xFFFFFF02 (caso 1)



  x = xbyte(0x01ABCD02, 1);

  printf ("0x%08X\n", x);    // 0xFFCDFFFF (caso 3)



  x = xbyte(0x01ABCD02, 2);

  printf ("0x%08X\n", x);    // 0x0000AB00 (caso 2)



  x = xbyte(0x11E032A5, 0);

  printf ("0x%08X\n", x);    // 0x0000A500 (caso 2)



  x = xbyte(0x11E032A5, 1);

  printf ("0x%08X\n", x);    // 0xFFFFFF32 (caso 1)



  x = xbyte(0x11E032A5, 2);

  printf ("0x%08X\n", x);    // 0xFFE0FFFF (caso 3)



  x = xbyte(0x11E032A5, 3);

  printf ("0x%08X\n", x);    // 0xFFFFFF11 (caso 1)



  x = xbyte(0xABCD, 3);

  printf ("0x%08X\n", x);    // 0xFFFFFF00 (caso 1)



  x = xbyte(0xABCD, 1);

  printf ("0x%08X\n", x);    // 0x0000AB00 (caso 2)



  return 0;

}