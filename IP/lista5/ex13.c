#include <stdio.h>
#include <math.h>

struct RaizEqu2{
    float x1, x2;
    float delta;
};

typedef struct RaizEqu2 Raiz;

Raiz calcRaiz(float a, float b, float c){
    Raiz n1;
    float delta1;

    delta1 = (b*b) - (4*a*c);

    if(delta1 < 0){
        n1.x1 = (-b) / (2 * a);
        n1.x2 = n1.x1;
        n1.delta = delta1;
    } else{
        n1.x1 = ((-b) + sqrt(delta1))/(2 * a);
        n1.x2 = ((-b) - sqrt(delta1))/(2 * a);
        n1.delta = delta1;
    }

    return n1;
}

void complex_print(Raiz n){
    
    if(n.x1 != 0){
        printf("x1 = %.2f+i\n", n.x1);
    } else{
        printf("x1 = i\n");
    }
    if(n.x2 != 0){
        printf("x2 = %.2f-i\n", n.x2);
    } else{
        printf("x2 = -i\n");
    }

}

int main(){
    float a, b, c;
    float delta;
    Raiz n;

    scanf("%f %f %f", &a, &b, &c);

    n = calcRaiz(a, b, c);

    if(n.delta < 0){
        complex_print(n);
    } else if(n.delta > 0){
        printf("x1 = %.2f\n", n.x1);
        printf("x2 = %.2f\n", n.x2);
    } else{
        printf("x1 = %.2f\n", n.x1);
        printf("x2 = %.2f\n", n.x1);
    }

    return 0;
}