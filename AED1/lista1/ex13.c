#include <stdio.h>
#include <stdlib.h>

int Labirinto(int ***matriz, int inicio, int fim, int k, int NL, int NC){
    if(inicio == 0 && fim == 0){
        return 1;
    }

    if(k > NL * NC){
        return 0;
    }

    return Labirinto(matriz, matriz[inicio][fim][0], matriz[inicio][fim][1], k + 1, NL, NC);
}

int main(){
    int numLinhas, numColunas;
    int i, j;
    int ***matriz;
    int total = 0;

    scanf("%d %d", &numLinhas, &numColunas);

    matriz = (int ***) malloc(numLinhas * sizeof(int **)); //alocando a matriz

    for(i = 0; i < numLinhas; i++){
        matriz[i] = (int **) malloc(numColunas * sizeof(int *)); //alocando cada linha da matriz
    }

    for(i = 0; i < numLinhas; i++){
        for(j = 0; j < numColunas; j++){
            matriz[i][j] = (int *) malloc(2 * sizeof(int)); //alocando cada elemento da matriz para conter 2 int
        }
    }
    //============================================================//

    for(i = 0; i < numLinhas; i++){
        for(j = 0; j < numColunas; j++){
            scanf("%d %d", &matriz[i][j][0], &matriz[i][j][1]);
        }
    }

    for(i = 0; i < numLinhas; i++){
        for(j = 0; j < numColunas; j++){
            total += Labirinto(matriz, i, j, 0, numLinhas, numColunas); 
        }
    }

    printf("%d\n", total);

    //============================================================//
    for(i = 0; i < numLinhas; i++){
        for(j = 0; j < numColunas; j++){
            free(matriz[i][j]); //desalocando cada elemento que contém 2 int
        }
    }

    for(i = 0; i < numLinhas; i++){
        free(matriz[i]); //desalocando cada linha
    }

    free(matriz); //desalocando a matriz

    return 0;
}