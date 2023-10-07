#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arq = NULL;
    int x = 1, b = 1, b1 = 1, k = 0;
    int vetor[10000];

    arq = fopen("dados2.txt", "wb");

    if(arq == NULL){
        printf("ERRO\n");
        return 1;
    }

    fprintf(arq, "%d\n", x);
    x++;

    while(x <= 100){
        b = x;
        b1 = x;
        while(b1 > 0){
            b = b1 % 2;

            vetor[k] = b;

            k++;

            b1 = b1/2;
        }
        k--;
        while(k>=0){
            fprintf(arq, "%d", vetor[k]);
            k--;
        }
        fprintf(arq, "\n");
        k = 0;
        x++;
    }

    fclose(arq);

    return 0;
}