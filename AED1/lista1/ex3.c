#include <stdio.h>

int Fack(int m, int n){
    if(m == 0) return n + 1;
    if(n == 0 && m > 0) Fack(m - 1, 1);
    if(n > 0 && m > 0) Fack(m - 1, Fack(m, n - 1));
}

int main(){
    int n, m;

    scanf("%d %d", &m, &n);
    
    printf("%d\n", Fack(m, n));

    return 0;
}