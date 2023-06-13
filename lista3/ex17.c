#include <stdio.h>

void absoluto(double *p, int cont){
    if(p[cont] < 0){
        p[cont] = (p[cont]) * (-1);
    }
}

int main(){
    double v1[3], v2[3], v3[3];
    int qtd, i, i2;
    double maior = 0;
    scanf("%d", &qtd);
    for(i2=0;i2<qtd - 1;i2++){
        if(i2==0){
            for(i=0;i<3;i++){
                scanf("%lf", &v1[i]);
            }
        }
        for(i=0;i<3;i++){
            scanf("%lf", &v2[i]);
        }
        for(i=0;i<3;i++){
            v3[i] = v2[i] - v1[i];
            absoluto(v3, i);
            if(i==0){
                maior = v3[i];
            } else if(i>=1){
                if(v3[i] >= maior){
                    maior = v3[i];
                }
            }
        }
        printf("%.2lf\n", maior);
        maior = 0;
        for(i=0;i<3;i++){
            v1[i] = v2[i];
        }
    }
    return 0;
}