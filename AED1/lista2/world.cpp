#include "world.hpp"
#include <stdlib.h>
#include <iostream>

struct world{
    int num_linhas;
    int num_colunas;
    int ***matriz;
};

World * newWorld (int linhas, int colunas){
    World * w = NULL;
    int i, j;

    w = (World *) malloc(1 * sizeof(World));

    w->num_linhas = linhas;
    w->num_colunas = colunas;

    w->matriz = (int ***) malloc(w->num_linhas * sizeof(int **));

    for(i = 0; i < w->num_linhas; i++){
        w->matriz[i] = (int **) malloc(w->num_colunas * sizeof(int *));
    }

    for(i = 0; i < w->num_linhas; i++){
        for(j = 0; j < w->num_colunas; j++){
            w->matriz[i][j] = (int *) malloc(3 * sizeof(int));
        }
    }

    return w;

}

World * cloneWorld (World * w){
    World * copia = NULL;
    int i, j;

    copia = (World *) malloc(1 * sizeof(World));

    copia->num_linhas = w->num_linhas;
    copia->num_colunas = w->num_colunas;

    copia->matriz = (int ***) malloc(copia->num_linhas * sizeof(int **));

    for(i = 0; i < copia->num_linhas; i++){
        copia->matriz[i] = (int **) malloc(copia->num_colunas * sizeof(int *));
    }

    for(i = 0; i < copia->num_linhas; i++){
        for(j = 0; j < copia->num_colunas; j++){
            copia->matriz[i][j] = (int *) malloc(3 * sizeof(int));
            copia->matriz[i][j][0] = w->matriz[i][j][0];
            copia->matriz[i][j][1] = w->matriz[i][j][1];
            copia->matriz[i][j][2] = w->matriz[i][j][2];
        }
    }

    return copia;
}

void freeWorld (World * w){
    int i, j;

    for(i = 0; i < w->num_linhas; i++){
        for(j = 0; j < w->num_colunas; j++){
            free(w->matriz[i][j]);
        }
    }

    for(i = 0; i < w->num_linhas; i++){
        free(w->matriz[i]);
    }

    free(w->matriz);
    free(w);
}

int addBacterium (World * w, int n, int f, int e){
    int i, j;

    if(verificaBacteria(w, n) == TRUE) return FALHA;

    for(i = 0; i < w->num_linhas; i++){
        for(j = 0; j < w->num_colunas; j++){
            if(w->matriz[i][j][0] == 0 && w->matriz[i][j][1] == 0 && w->matriz[i][j][2] == 0){
                w->matriz[i][j][0] = n; 
                w->matriz[i][j][1] = f;
                w->matriz[i][j][2] = e;
                return SUCESSO;
            }
        }
    }

    return FALHA;
}

int verificaBacteria(World * w, int n){
    int i, j;

    for(i = 0; i < w->num_linhas; i++){
        for(j = 0; j < w->num_colunas; j++){
            if(w->matriz[i][j][0] == n) return TRUE;
        }
    }

    return FALSE;
}

int addBacteriumXY (World * w,  int n, int f, int e, int x, int y){
    int i, j;

    if(verificaBacteria(w, n) == TRUE) return FALHA;

    if(w->matriz[x][y][0] == 0 && w->matriz[x][y][1] == 0 && w->matriz[x][y][2] == 0){
        w->matriz[x][y][0] = n; 
        w->matriz[x][y][1] = f;
        w->matriz[x][y][2] = e;
    }

    return SUCESSO;
}