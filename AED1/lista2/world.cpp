#include "world.hpp"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

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
            w->matriz[i][j] = (int *) calloc(3, sizeof(int));
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

int randomWorld (World * w, int n){
    int ordem = 0, forca = 0, vida = 0;

    while(1){
        if(n == 0) break;
        ordem = (std::rand() % (w->num_colunas * w->num_linhas)) + 1;
        forca = (std::rand() % 100) + 1;
        vida = (std::rand() % 100) + 1;
        if(addBacterium(w, ordem, forca, vida) == FALHA){
            return FALHA;
        }  else{
            n--;
        }
    }

    return SUCESSO;
}

int killBacterium (World * w, int n){
    int i, j;

    if(verificaBacteria(w, n) == TRUE) return FALHA;

    for(i = 0; i < w->num_linhas; i++){
        for(j = 0; j < w->num_colunas; j++){
            if(w->matriz[i][j][0] == n){
                w->matriz[i][j][0] = 0;
                w->matriz[i][j][1] = 0;
                w->matriz[i][j][2] = 0;
                return SUCESSO;
            }
        }
    }
}

int killBacteriumXY (World * w, int x, int y){
    if(x >= w->num_linhas || y >= w->num_colunas) return FALHA;

    w->matriz[x][y][0] = 0;
    w->matriz[x][y][1] = 0;
    w->matriz[x][y][2] = 0;

    return SUCESSO;
}

World * jointWorlds (World * w1, World * w2){
    World * uniao = NULL;
    int i, j;
    
    uniao = newWorld(w1->num_linhas + w2->num_linhas, w1->num_colunas + w2->num_colunas);

    for(i = 0; i < w1->num_linhas; i++){
        for(j = 0; j < w1->num_colunas; j++){
            addBacterium(uniao, w1->matriz[i][j][0], w1->matriz[i][j][1], w1->matriz[i][j][2]);
        }
    }

    for(i = 0; i < w2->num_linhas; i++){
        for(j = 0; j < w2->num_colunas; j++){
            addBacterium(uniao, w2->matriz[i][j][0], w2->matriz[i][j][1], w2->matriz[i][j][2]);
        }
    }

    return uniao;
}


