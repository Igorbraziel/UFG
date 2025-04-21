#include <stdio.h>

unsigned char rotate_left(unsigned char x, int n){
    unsigned char mask = 0x80;
    while(n){
        x = x & mask ? (x << 1) + 1 : x << 1;
        n--;
    }
    return x;
}

int main (){
    unsigned char value = 0x61;

    printf("0x%08X\n", rotate_left(value, 1));
    printf("0x%08X\n", rotate_left(value, 2));
    printf("0x%08X\n", rotate_left(value, 7));

    return 0;
}