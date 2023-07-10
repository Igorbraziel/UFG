#include <stdio.h>
#include <math.h>

void calcraiz(double a, double b, double c, double *p1, double *p2, double *p3){
    *p1 = ((-b) - sqrt(*p3)) / (2*a);
    *p2 = ((-b) + sqrt(*p3)) / (2*a);
}

int main(){
    double a, b, c, x1=0, x2=0, delta=0;
    scanf("%lf %lf %lf", &a, &b, &c);
    delta = (b*b) - (4*a*c);
    if(delta < 0){
        printf("RAIZES IMAGINARIAS\n");
        return 0;
    } else {
        calcraiz(a, b, c, &x1, &x2, &delta);
        if(delta == 0){
            printf("RAIZ UNICA\n");
            printf("X1 = %.2lf\n", x1);
        } else if(delta > 0 && x1 < x2){
            printf("RAIZES DISTINTAS\n");
            printf("X1 = %.2lf\n", x1);
            printf("X2 = %.2lf\n", x2);
        } else if(delta > 0 && x1 > x2){
            printf("RAIZES DISTINTAS\n");
            printf("X1 = %.2lf\n", x2);
            printf("X2 = %.2lf\n", x1);
        }
    }
    return 0;
}