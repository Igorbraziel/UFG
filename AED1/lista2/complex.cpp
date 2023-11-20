#include "complex.hpp"
#include <iostream>
#include <stdlib.h>

struct complexo{
    int qtd;
    Numero * num;
};

struct numero{
    int real;
    int imaginario;
};

int criaConjunto(Complexo * c){
    c = (Complexo *) malloc(1 * sizeof(Complexo));
    c->num = (Numero *) malloc(1 * sizeof(Numero));
    c->qtd = 0;

    return SUCESSO;
}

int conjuntoVazio(Complexo * c){
    if(c->qtd == 0) return TRUE;
    return FALSE;
}

int insereElementoConjunto(Numero * x, Complexo * c){
    c->qtd++;
    c->num = (Numero *) realloc(c->num, c->qtd * sizeof(Numero));
    c->num[c->qtd - 1].real = x->real;
    c->num[c->qtd - 1].imaginario = x->imaginario;
    
    return SUCESSO;
}

int excluirElementoConjunto(Numero * x, Complexo * c){
    int i, j, temp_real, temp_imaginario;

    for(i = 0; i < c->qtd; i++){
        if(c->num[i].real == x->real && c->num[i].imaginario == x->imaginario){
            for(j = i; j < c->qtd - 1; j++){
                temp_real = c->num[j].real;
                temp_imaginario = c->num[j].imaginario;
                c->num[j].real = c->num[j + 1].real;
                c->num[j].imaginario = c->num[j + 1].imaginario;
                c->num[j + 1].real = temp_real;
                c->num[j + 1].imaginario = temp_imaginario;
            }
        }
    }
}