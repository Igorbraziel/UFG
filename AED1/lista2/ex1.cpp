#include <iostream>
#include "conjunto.hpp"

int main(){
    Conjunto * c1 = NULL;
    Conjunto * c2 = NULL;
    Conjunto * inter = NULL;
    int i, x;

    c1 = cria_conjunto(c1);
    c2 = cria_conjunto(c2);
    inter = cria_conjunto(inter);

    for(i = 0; i < 5; i++){
        std::cin >> x;
        insereElementoConjunto(x, c1);
        std::cin >> x;
        insereElementoConjunto(x, c2);
    }

    inter = interseccao(c1, c2);

    mostraConjunto(inter, DECRESCENTE);

    conjunto_delete(c1);
    conjunto_delete(c2);
    conjunto_delete(inter);

    return 0;
}
