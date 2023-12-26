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

bool NumeroInComplexo(Numero * x, Complexo * c){
    int i;

    for(i = 0; i < c->qtd; i++){
        if(c->num[i].real == x->real && c->num[i].imaginario == x->imaginario){
            return true;
        }
    }

    return false;
}

int insereElementoConjunto(Numero * x, Complexo * c){
    if(NumeroInComplexo(x, c) == true) return FALHA;

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

bool pertenceConjunto(Numero * x, Complexo * c){
    int i;

    for(i = 0; i < c->qtd; i++){
        if(c->num[i].real == x->real && c->num[i].imaginario == x->imaginario){
            return true;
        }
    }

    return false;
}

bool conjuntosIdenticos(Complexo * c1, Complexo * c2){
    int i;

    if(c1->qtd != c2->qtd) return false;

    for(i = 0; i < c1->qtd; i++){
        if(c1->num[i].real != c2->num[i].real || c1->num[i].imaginario != c2->num[i].imaginario){
            return false;
        }
    }


    return true;
}

bool subconjunto(Complexo * c1, Complexo * c2){
    int i, j, k = 0;

    for(i = 0; i < c1->qtd; i++){
        for(j = 0; j < c2->qtd; j++){
            if(c1->num[i].real == c2->num[j].real && c1->num[i].imaginario == c2->num[j].imaginario){
                k = 1;
            }
        }
        if(k == 0) return false;
        k = 0;
    }

    return true;
}

Complexo * complemento(Complexo * c1, Complexo * c2){
    Complexo * comp = NULL;
    int i, j, k = 0;

    comp = criaConjunto();

    for(i = 0; i < c2->qtd; i++){
        for(j = 0; j < c1->qtd; j++){
            if(c2->num[i].real == c1->num[j].real && c2->num[i].imaginario == c1->num[j].imaginario){
                k = 1;
            }
        }
        if(k == 0){
            insereElementoConjunto(criaNumero(c2->num[i].real, c2->num[i].imaginario), comp);
        }
        k = 0;
    }

    return comp;

}

Complexo * uniao(Complexo * c1, Complexo * c2){
    Complexo * uni = NULL;
    int i;

    uni = criaConjunto();

    for(i = 0; i < c1->qtd; i++){
        insereElementoConjunto(criaNumero(c1->num[i].real, c1->num[i].imaginario), uni);
    }

    for(i = 0; i < c2->qtd; i++){
        insereElementoConjunto(criaNumero(c2->num[i].real, c2->num[i].imaginario), uni);
    }

    return uni;
}

Complexo * interseccao(Complexo * c1, Complexo * c2){
    Complexo * inter = NULL;
    int i, j;

    inter = criaConjunto();

    for(i = 0; i < c1->qtd; i++){
        if(NumeroInComplexo( criaNumero(c1->num[i].real, c1->num[i].imaginario), c2) ){
            insereElementoConjunto(criaNumero(c1->num[i].real, c1->num[i].imaginario), inter);
        }
    }

    return inter;
}

Complexo * diferenca(Complexo * c1, Complexo * c2){
    Complexo * dif = NULL;
    int i;

    dif = criaConjunto();

    for(i = 0; i < c1->qtd; i++){
        if(NumeroInComplexo( criaNumero(c1->num[i].real, c1->num[i].imaginario), c2) == false){
            insereElementoConjunto(criaNumero(c1->num[i].real, c1->num[i].imaginario), dif);
        }
    }

    return dif;

}
