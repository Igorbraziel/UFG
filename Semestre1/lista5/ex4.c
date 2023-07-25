#include <stdio.h>
#include <string.h>
#include <math.h>

struct pontos{
    float matriz[1000][4];
    float norma[1000];  
};

typedef struct pontos Pontos;

float calcula_norma(Pontos n1, int i){
    int j;
    float soma = 0;
    for(j=0;j<4;j++){
        soma += pow((n1.matriz[i][j]), 2);
    }

    return sqrt(soma);
}

void ordena_norma(Pontos *n1, int nl, int i){
    int k, indice = i, c, l;
    float menor = n1->norma[i];
    float t;
    for(k=i;k<nl;k++){
        if(k==i){
            menor = n1->norma[i];
            indice = k;
        }
        if(n1->norma[k] < menor){
            menor = n1->norma[k];
            indice = k;
        }
    }
    t = n1->norma[i];
    n1->norma[i] = menor;
    n1->norma[indice] = t;

        for(l=0;l<4;l++){
            t = n1->matriz[i][l];
            n1->matriz[i][l] = n1->matriz[indice][l];
            n1->matriz[indice][l] = t;
        }
}

void print_vetor(Pontos n1, int nl, int i){
    int j;

    printf("Vetor : ");
        for(j=0;j<4;j++){
            if(j==0){
                printf("(%.2f", n1.matriz[i][j]);
            } else{
                printf(", %.2f", n1.matriz[i][j]);
            }
        }
    printf(") Norma: %.2f\n", n1.norma[i]);
}

int main(){
    Pontos n1;
    int nl, i, j;
    int indice;

    scanf("%d", &nl);

    for(i=0;i<nl;i++){
        for(j=0;j<4;j++){
            scanf("%f", &n1.matriz[i][j]);
        }
    }

    for(i=0;i<nl;i++){
        n1.norma[i] = calcula_norma(n1, i); 
    }

    for(i=0;i<nl;i++){
        ordena_norma(&n1, nl, i);
        print_vetor(n1, nl, i);
    }

    memset(&n1, 0, sizeof(Pontos));

    return 0;
}