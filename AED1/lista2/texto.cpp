#include "texto.hpp"
#include <iostream>
#include <stdlib.h>

struct texto{
    char * palavras;
    int tamanho;
};

Texto * criarTexto (char * t){
    Texto * txt = NULL;
    int i = 0;

    txt = (Texto *) malloc(1 * sizeof(Texto));

    while(t[i] != '\0'){
        i++;
    }

    i++;

    txt->tamanho = i;
    txt->palavras = (char *) malloc(txt->tamanho * sizeof(char));

    for(i = 0; i < txt->tamanho; i++){
        txt->palavras[i] = t[i];
    }

    return txt;
}

void liberarTexto (Texto * t){
    free(t->palavras);
    free(t);
}

int tamanhoTexto (Texto * t){
    return t->tamanho - 1;
}

char * obterTexto (Texto * t){
    char * txt = NULL;
    int i;

    txt = (char *) malloc(t->tamanho * sizeof(char));

    for(i = 0; i < t->tamanho; i++){
        txt[i] = t->palavras[i];
    }

    return txt;
}

void mostrarTexto (Texto *t, int colunas){
    int i;

    for(i = 0; i < t->tamanho - 1; i++){
        if(t->palavras[i] == ' ' && colunas > 1){
            std::cout << "\n";
            colunas--;
        } else{
            std::cout << t->palavras[i];
        }
    }

    std::cout << "\n";
}

int spaceCount(Texto * t){
    int i, k = 0;

    for(i = 0; i < t->tamanho; i++){
        if(t->palavras[i] == ' ') k++;
    }

    return k;
}

Texto * copiarTexto (Texto * t){
    Texto * copia = NULL;
    int i;

    copia = (Texto *) malloc(1 * sizeof(Texto));
    copia->palavras = (char *) malloc(t->tamanho * sizeof(char));
    copia->tamanho = t->tamanho;

    for(i = 0; i < copia->tamanho; i++){
        copia->palavras[i] = t->palavras[i];
    }

    return copia;
}

void substituirTexto (Texto * t, char * alteracao){
    int i = 0, tamanho_alteracao = 0;

    while(alteracao[i] != '\0'){
        i++;
    }

    tamanho_alteracao = i + 1;

    t->tamanho = tamanho_alteracao;
    t->palavras = (char *) realloc(t->palavras, t->tamanho * sizeof(char));

    for(i = 0; i < t->tamanho; i++){
        t->palavras[i] = alteracao[i];
    }
}

Texto * concatenarTextos (Texto * t1, Texto * t2){
    Texto * concatena = NULL;
    int i, j;

    concatena = (Texto *) malloc(1 * sizeof(Texto));
    concatena->tamanho = t1->tamanho + t2->tamanho - 1;
    concatena->palavras = (char *) malloc(concatena->tamanho * sizeof(char));

    for(i = 0; i < t1->tamanho - 1; i++){
        concatena->palavras[i] = t1->palavras[i];
    }

    for(j = 0; j < t2->tamanho; j++){
        concatena->palavras[i] = t2->palavras[j];
        i++;
    }

    return concatena;
}

char * obterSubtexto (Texto * t, int inicio, int tamanho){
    char * sub = NULL;
    int i, j = 0;

    sub = (char *) malloc((tamanho + 1) * sizeof(char));

    for(i = inicio; i < t->tamanho - 1; i++){
        if(tamanho == 0) break;
        sub[j] = t->palavras[i];
        tamanho--;
        j++;
    }

    sub[j] = '\0';

    return sub;
}

int encontrarSubtexto (Texto * t, char * subtexto, int ocorrencia){
    int i, j = 0, primeira_aparicao = -1;

    for(i = 0; i < t->tamanho - 1; i++){
        if(t->palavras[i] == subtexto[j]){
            if(j == 0) primeira_aparicao = i;
            if(subtexto[j + 1] == '\0'){
                if(ocorrencia == 1){
                    break;
                } else{
                    ocorrencia--;
                    j = 0;
                    primeira_aparicao = -1;
                }
            }
            j++;
        } else{
            j = 0;
            primeira_aparicao = -1;
        }
    }

    return primeira_aparicao;
}

int compararTextos (Texto * t1, Texto * t2){
    if(t1->tamanho > t2->tamanho){
        return MAIOR;
    } else if (t1->tamanho < t2->tamanho){
        return MENOR;
    }

    return IGUAL;
}