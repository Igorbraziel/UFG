    #include <stdio.h>
    int main(){
        float A, B, C, delta;
        
        scanf("%f", &A);
        scanf("%f", &B);
        scanf("%f", &C);
        
        delta = B*B - 4*A*C;
        
        printf("O VALOR DE DELTA E = %.2f\n", delta);
     
     
        return 0;
    }