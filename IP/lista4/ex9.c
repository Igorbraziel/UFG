#include <stdio.h>

int main(){
    int matriz[1000][1000];
    int i, j;
    int nc, nl, kmaior = 0, kmenor = 0;
    int maior = 0, menor = 1000;
    double porcentagem = 0;
    double denominador = 0, numerador = 0;
    char per;
    per = '%';
    scanf("%d %d", &nl, &nc);

    for(i=0;i<nl;i++){
        for(j=0;j<nc;j++){
            scanf("%d", &matriz[i][j]);  
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
            }
            if(matriz[i][j] < menor){
                menor = matriz[i][j];
            }
        }
    }

    for(i=0;i<nl;i++){
        for(j=0;j<nc;j++){
            if(matriz[i][j] == maior) kmaior++;
            if(matriz[i][j] == menor) kmenor++;
        }
    }

    /* N*M -- 100
       kmenor -- porcentagem*/
    numerador = 100.0*kmenor;
    denominador = nl*nc;
    porcentagem = numerador/denominador;

    printf("%d %.2lf%c\n", menor, porcentagem, per);

    numerador = 100.0*kmaior;
    denominador = nl*nc;
    porcentagem = numerador/denominador;

    printf("%d %.2lf%c\n", maior, porcentagem, per);

    return 0;
}