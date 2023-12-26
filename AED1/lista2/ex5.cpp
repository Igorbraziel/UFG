#include "complex.hpp"
#include <iostream>

int main(){
    Complexo * c1 = NULL;
    Complexo * c2 = NULL;
    Numero * n1 = NULL;
    Numero * n2 = NULL;
    Numero * n3 = NULL;
    Numero * n4 = NULL;
    Numero * n5 = NULL;
    Numero * n6 = NULL;
    Numero * n7 = NULL;
    Numero * n8 = NULL;

    c1 = criaConjunto();
    c2 = criaConjunto();

    n1 = criaNumero(2, 4);
    n2 = criaNumero(3, 7);
    n3 = criaNumero(7, 8);
    n4 = criaNumero(22, 34);

    insereElementoConjunto(n1, c1);
    insereElementoConjunto(n2, c1);
    insereElementoConjunto(n3, c1);
    insereElementoConjunto(n4, c1);

    n5 = criaNumero(7, 99);
    n6 = criaNumero(3, 7);
    n7 = criaNumero(2, 4);
    n8 = criaNumero(220, 46);

    insereElementoConjunto(n5, c2);
    insereElementoConjunto(n6, c2);
    insereElementoConjunto(n7, c2);
    insereElementoConjunto(n8, c2);

    showConjunto(c1);
    showConjunto(c2);
    showConjunto(diferenca(c1, c2));

    freeConjunto(c1);
    freeConjunto(c2);
    freeNumero(n1);
    freeNumero(n2);
    freeNumero(n3);
    freeNumero(n4);
    freeNumero(n5);
    freeNumero(n6);
    freeNumero(n7);
    freeNumero(n8);

    return 0;
}