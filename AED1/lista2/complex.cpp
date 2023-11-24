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

Complexo * criaConjunto(){
    Complexo * c = NULL;
    c = (Complexo *) malloc(1 * sizeof(Complexo));
    c->num = (Numero *) malloc(1 * sizeof(Numero));
    c->qtd = 0;

    return c;
}

bool conjuntoVazio(Complexo * c){
    if(c->qtd == 0) return true;
    return false;
}

int insereElementoConjunto(Numero * x, Complexo * c){
    c->qtd++;
    if(c->qtd != 1){
        c->num = (Numero *) realloc(c->num, c->qtd * sizeof(Numero));
    }
    c->num[c->qtd - 1].real = x->real;
    c->num[c->qtd - 1].imaginario = x->imaginario;
    
    return SUCESSO;
}

int excluirElementoConjunto(Numero * x, Complexo * c){
    int i, j, temp_real, temp_imaginario;

    if(c->qtd == 0) return FALHA;

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
            c->qtd--;
            c->num = (Numero *) realloc(c->num, c->qtd * sizeof(Numero));
            return SUCESSO;
        }
    }

    return FALHA;
}

int tamanhoConjunto(Complexo * c){
    return c->qtd;
}

void showConjunto(Complexo * c){
    int i;

    std::cout << "(";

    for(i = 0; i < c->qtd; i++){
        if(i == 0) {
            std::cout << c->num[i].real << "+" << c->num[i].imaginario << "i";
        } else{
            std::cout << ", " <<c->num[i].real << "+" << c->num[i].imaginario << "i";
        }
    }

    std::cout << ")\n";
}

Numero * criaNumero(int real, int imaginario){
    Numero * n = NULL;
    n = (Numero *) malloc(1 * sizeof(Numero));
    n->real = real;
    n->imaginario = imaginario;

    return n;
}

void freeConjunto(Complexo * c){
    free(c->num);
    free(c);
}

void freeNumero(Numero * n){
    free(n);
}