#include <stdio.h>

int fibonacci(int *t1, int *t2, int *n){
    int termo = 0, soma = 0, post = 0, n1 = *n, n2 = *n, ant1 = *t1, ant2 = *t2;
    if(n1 == 1){
            termo = ant1;
        } else if(n1 == 2){
            termo = ant2;
        }
    while(n1>1){
        if(n1 == 2 && n2 > 2){
            termo = post;
        }
        post = ant1 + ant2;
        soma += ant1 + ant2 + post;
        ant1 = ant2;
        ant2 = post;
        n1--;
    }   
    return termo;
}

int main(){
    int pt, st, ter, x;
    scanf("%d %d %d", &pt, &st, &ter);
    x = fibonacci(&pt, &st, &ter);
    printf("%d\n", x);
    return 0;
}