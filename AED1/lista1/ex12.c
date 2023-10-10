#include <stdio.h>
#include <stdlib.h>

void Labirinto(int ***matriz, int inicio, int fim, int k, int NL, int NC){
    if(inicio == 0 && fim == 0){
        printf("VENCE\n");
        return;
    }

    if(k > NL * NC){
        printf("PRESO\n");
        return;
    }

    Labirinto(matriz, matriz[inicio][fim][0], matriz[inicio][fim][1], k + 1, NL, NC);
}

int main(){
    int numLinhas, numColunas;
    int i, j, x, y;
    int ***matriz;

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

    scanf("%d %d", &x, &y);

    Labirinto(matriz, x, y, 0, numLinhas, numColunas);

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