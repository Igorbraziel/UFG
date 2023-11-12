#include "texto.hpp"
#include <iostream>

int main(){
    Texto * txt = NULL;
    Texto * copia = NULL;
    Texto * concatena = NULL;
    char escrita[100] = {"eu estou concatenando this texto"};
    //char alteracao[100] = {"eu alterei o texto"};
    char concatenacao[100] = {"eu estou concatenando esse texto"};
    //char encontra[100] = {"noite"};

    txt = criarTexto(escrita);

    concatena = criarTexto(concatenacao);

    /*copia = copiarTexto(txt);

    substituirTexto(copia, alteracao);

    concatena = concatenarTextos(concatena, txt);*/



    std::cout << compararTextos(txt, concatena) << "\n";
    //mostrarTexto(txt, 4);
    //std::cout << encontrarSubtexto(txt, encontra, 1) << "\n";

    liberarTexto(txt);
    //liberarTexto(copia);
    liberarTexto(concatena);

    return 0;
}