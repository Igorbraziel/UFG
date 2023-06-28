#include <stdio.h>
#define N 6


int main(){
    int matriz[N][N];
    int i, j, k = 0, v = 0;
    int soma = 0, maior = -63;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i=0;i<=N/2;i++){
        for(j=0;j<=N/2;j++){
            while(k<3){
                soma += matriz[i][j+k];
                if(k==1) v = j+k;
                k++;
            }
            k = 0;
            soma += matriz[i+1][v];
            while(k<3){
                soma += matriz[i+2][j+k];
                k++;
            }
            k = 0;
            if(soma > maior){
                maior = soma;
            }
            soma = 0;
            v = 0;
        }
    }

    printf("%d\n", maior);

    return 0;
}