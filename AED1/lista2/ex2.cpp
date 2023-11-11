#include "data.hpp"
#include <iostream>

int main(){
    Data * igor = NULL;
    char formato[10] = "mm";

    igor = criaData(27, 7, 2023);

    std::cout << imprimeData(igor, formato) << "\n";

    liberaData(igor);

    return 0;
}