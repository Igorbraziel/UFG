#include <stdio.h>
#include <string.h>

#define MAX 50

struct fracao {
    int den[MAX];
    int num[MAX];
};

typedef struct fracao Frac;

void le_fracao(Frac *n, int t){
    int i = 0;
    for(i=0;i<t;i++){
        scanf("%d/%d", &(*n).num[i], &(*n).den[i]);
    }
}

void compara_fracao(Frac n, int t, int *indice){
    int i, j;
    for(i=0;i<t;i++){
        for(j=i;j<t;j++){
            if((float) n.num[i] / n.den[i] == (float) n.num[j] / n.den[j] && i != j){
                printf("%d/%d equivalente a %d/%d\n", n.num[i], n.den[i], n.num[j], n.den[j]);
                *indice = 1;
            }
        }
    }
}



int main(){
    Frac n1;
    int qtd, i = 1, t, indice = 0;

    scanf("%d", &qtd);

    while(i<=qtd){
        scanf("%d", &t);
        le_fracao(&n1, t);
        printf("Caso de teste %d\n", i);
        compara_fracao(n1, t, &indice);
        if(indice == 0){
            printf("Nao ha fracoes equivalentes na sequencia\n");
        }
        memset(&n1, 0, sizeof(struct fracao));
        indice = 0;
        i++;
    }

    return 0;
}