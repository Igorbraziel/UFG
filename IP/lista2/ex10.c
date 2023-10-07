#include <stdio.h>

void funcaoPi(double *p1, double *p2){
    double num = 2, den = 1;
    int i;
    for(i=0;i < *p1; i++){
        if(i%2 == 0 && i != 0){
            num += 2;
        }
        if(i == 1){
            den += 2;
        }
        if(i != 1 && i%2 != 0){
            den += 2;
        }
        if(*p2 == 0) {
            *p2 = (num/den);
        } 
        if(*p2 > 0){
            *p2 = (*p2 * (num/den));
        }
        
    }
}

int main(){
    double x, pi=0;
    scanf("%lf", &x);
    funcaoPi(&x, &pi);
    printf("%.12lf\n", pi);
    return 0;
}