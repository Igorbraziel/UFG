#include <stdio.h>

#define MAX 10

void imprimeLinhas(int matriz[MAX][MAX], int N_COLUNAS, int i, int *k, int *j, int *c1){
    while(*j < N_COLUNAS - (*c1)){
        printf("%d ", matriz[i][*j]);
        (*k)++;
        (*j)++;
    }
    (*c1)++;
    (*j)--;
}

void imprimeLinhasInversas(int matriz[MAX][MAX], int i, int *k, int *j, int *c3){
    while(*j >= *c3){
        printf("%d ", matriz[i][*j]);
        (*k)++;
        (*j)--;
    }
    (*c3)++;
    (*j)++;
}

void imprimeColunas(int matriz[MAX][MAX], int N_LINHAS, int j, int *k, int *i, int *c2){
    while(*i < N_LINHAS - (*c2)){
        printf("%d ", matriz[*i][j]);
        (*k)++;
        (*i)++;
    }
    (*c2)++;    
    (*i)--;
}

void imprimeColunasInversas(int matriz[MAX][MAX], int j, int *k, int *i, int *c4){
    while(*i > *c4){
        printf("%d ", matriz[*i][j]);
        (*k)++;
        (*i)--;
    }
    (*c4)++;    
    (*i)++;
}

int main(){
    int matriz[MAX][MAX];
    int N_LINHAS, N_COLUNAS;
    int i, j, k = 0, k1 = 0;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

    scanf("%d %d", &N_LINHAS, &N_COLUNAS);

    if(N_LINHAS < 1 || N_LINHAS > 10 || N_COLUNAS > 10 || N_COLUNAS < 1){
        printf("Dimensao invalida\n");
        return 0;
    }

    for(i=0;i<N_LINHAS;i++){
        for(j=0;j<N_COLUNAS;j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    j = 0;
    i = 0;
    k = N_LINHAS * N_COLUNAS;
    while(1){
        imprimeLinhas(matriz, N_COLUNAS, i, &k1, &j, &c1);
        i++;
        if(k1 >= k) break;
        imprimeColunas(matriz, N_LINHAS, j, &k1, &i, &c2);
        j--;
        if(k1 >= k) break;
        imprimeLinhasInversas(matriz, i, &k1, &j, &c3);
        i--;
        if(k1 >= k) break;
        imprimeColunasInversas(matriz, j, &k1, &i, &c4);
        j++;
        if(k1 >= k) break;
    }
    printf("\n");

    return 0;
}