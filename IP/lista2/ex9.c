#include <stdio.h>

void notas(int n, int *p1, int *p2, int *p3, int *p4){
    *p1 = (n/100);
    n = n%100; 
    *p2 = (n/50);
    n = n%50;
    *p3 = (n/10);
    n = n%10;
    *p4 = (n/1);
}

int main(){
    int cem, cinq, dez, um, x;
    scanf("%d", &x);
    notas(x, &cem, &cinq, &dez, &um);
    printf("NOTAS DE 100 = %d\n", cem);
    printf("NOTAS DE 50 = %d\n", cinq);
    printf("NOTAS DE 10 = %d\n", dez);
    printf("MOEDAS DE 1 = %d\n", um);
    return 0;
}