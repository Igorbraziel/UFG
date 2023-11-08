#include <iostream>
#include "ex1.hpp"

int main(){
    Cubo * c = NULL;
    int area, volume, perimetro;

    c = init_cubo(8);
    
    std::cout << "O tamanho do lado e " << tam_lado(c) << "\n";

    area = area_cubo(c);

    volume = volume_cubo(c);

    perimetro = perimetro_cubo(c);

    std::cout << "A area do cubo e " << area << "\n";

    std::cout << "O volume do cubo e " << volume << "\n";

    std::cout << "O perimetro do cubo e " << perimetro << "\n";

    delet_cubo(c);

    return 0;
}