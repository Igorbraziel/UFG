#include <stdio.h>

int main(){
    int matriz[6][6] = {0, 63, 210, 190, -1, 190, 63, 0, 160, 150, 95, 10, 210, 160, 0, 10, 1, 10,
                        190, 150, 10, 0, 10, 20, 10, 95, 7, 21, 0, 80, 190, 2, -1, 41, 80, 0};
    int qtd, i = 0, j = 0, k = 0;
    int soma = 0;

    scanf("%d", &qtd);

    while(i<qtd){
        if(i==0){
            scanf("%d %d", &j, &k);
            i = 2; 
            if(matriz[j][k] == -1) break;
            soma += matriz[j][k];
        } else{
            j = k;
            scanf("%d", &k);
            i++;
            if(matriz[j][k] == -1) break;
            soma += matriz[j][k];
        }
    }

    if(matriz[j][k] == -1){
        printf("rota invalida!\n");
    } else{
        printf("%d\n", soma);
    }

    return 0;
}