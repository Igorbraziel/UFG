#include <stdio.h>

unsigned long int fat(unsigned long int *n){
    unsigned long int fatorial = 1, y;
    y = *n;
    while(y > 0){
        fatorial *= y;
        y--;
    }
    return fatorial;
}

int main(){
    unsigned long int x, n1, n2;
    scanf("%lu", &x);
    n1 = x;
    n2 = fat(&x);
    printf("%lu!  = %lu\n", n1, n2);
    return 0;
}