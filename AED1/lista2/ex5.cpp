#include "complex.hpp"
#include <iostream>

int main(){
    Complexo * c = NULL;
    Numero * n1 = NULL;
    Numero * n2 = NULL;

    c = criaConjunto();

    n1 = criaNumero(2, 4);
    n2 = criaNumero(3, 7);

    insereElementoConjunto(n1, c);
    insereElementoConjunto(n2, c);

    showConjunto(c);

    freeConjunto(c);
    freeNumero(n1);
    freeNumero(n2);

    return 0;
}