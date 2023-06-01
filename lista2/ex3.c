#include <stdio.h>

void invertido(int *n){
    int u, d, c;
    u = (*n % 10);
    d = (*n % 100) - u;
    c = (*n) - (u + d);

    *n = (c/100) + (d) + (u*100);
}

int main(){
    int x;
    scanf("%d", &x);
    if(x < 100 || x > 999 || x%10 == 0){
        return 0;
    } else {
        invertido(&x);
        printf("%d\n", x);
    }
    return 0;
}