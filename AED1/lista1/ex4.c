#include <stdio.h>

int pow1(int n, int exp){
    if(exp == 0) return 1;
    return n * pow1(n, exp - 1);
}

int reverso(int n, int k){
    if(n == 0) return 0;
    if(n % 10 != 0) return (n % 10) * pow1(10, k - 1) + reverso(n / 10, k - 1);
}

int contaExp(int n, int exp){
    if(n == 0) return 0;
    return exp + contaExp(n / 10, exp + 1);
}

void elimina0(int *n){
    if((*n) % 10 != 0) return;
    (*n) = (*n) / 10;
    elimina0(n);
}

int main(){
    int num, i = 0;

    scanf("%d", &num);

    elimina0(&num);

    i = contaExp(num, i);

    printf("%d\n", reverso(num, i));

    return 0;
}