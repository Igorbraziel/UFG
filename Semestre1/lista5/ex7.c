#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct pontos{
    float **matriz;
};

typedef struct pontos Pontos;

void le_matriz(Pontos *n, int qtd){
    int i, j;

    for(i=0;i<qtd;i++){
        for(j=0;j<4;j++){
            scanf("%f", &n->matriz[i][j]);
        }
    }
}

float calc_dist(Pontos *n, int qtd, int i){
    float dist = 0;
    int j;

    for(j=0;j<4;j++){
        dist += pow((n->matriz[i][j] - n->matriz[i+1][j]), 2); 
    }

    return sqrt(dist);
}

int main(){
    Pontos n;
    int qtd, i;
    float dist;

    scanf("%d", &qtd);

    n.matriz = (float **) malloc(qtd * sizeof(float *)); //alocando matriz

    for(i=0;i<qtd;i++){
        n.matriz[i] = (float *) malloc(4 * sizeof(float)); //alocando matriz
    }

    le_matriz(&n, qtd);

    for(i=0;i<qtd-1;i++){
        dist = calc_dist(&n, qtd, i); //calcula distância entre 2 pnts 
        printf("%.2f\n", dist);
    }


    free(n.matriz); //liberando memoria alocada...

    return 0;
}