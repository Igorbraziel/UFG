#include <stdio.h>

int leading_zeros(unsigned short n){
    unsigned short mask = 0x8000;
    unsigned short count = 0;

    while((mask & n) == 0 && mask != 0){
        count++;
        mask = mask >> 1;
    }
    return count;
}

int main (){
    printf("%d\n", leading_zeros(0)); // 16 zeros

    printf("%d\n", leading_zeros(0x0083)); // 8

    printf("%d\n", leading_zeros(0x0607)); // 5

    printf("%d\n", leading_zeros(24432)); // 1

    printf("%d\n", leading_zeros(0xC2A4)); // 0

    return 0;
}