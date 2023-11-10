#include "data.hpp"
#include <iostream>

int main(){
    Data * nine = NULL;
    data * igor = NULL;

    nine = criaData(27, 12, 2023);
    igor = criaData(27, 12, 2004);

    std::cout << numeroDiasDatas(igor, nine) << "\n";

    liberaData(nine);
    liberaData(igor);

    return 0;
}