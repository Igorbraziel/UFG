#include <stdio.h>

void absoluto(double *p3){
    if(*p3<0) *p3 = (-1 * *p3);
}

void raiz (double n, double *p1, double *p2){
    *p1 = (*p2 + (n / *p2)) / 2;
    *p2 = *p1;
}

void interacao(double y, double z){
    printf("r: %.9lf, err: %.9lf\n", y, z);
}

int main(){
    double x, e, rk = 0, r0 = 1, e1 = 0;
    scanf("%lf", &x);
    scanf("%lf", &e);
    e1 = x - (rk*rk);
    while(e1 > e){
        raiz(x, &rk, &r0);
        e1 = x - (rk*rk);
        absoluto(&e1);
        interacao(rk, e1);
    }
    return 0;
}