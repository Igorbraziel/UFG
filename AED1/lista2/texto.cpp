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
    return t->tamanho;
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