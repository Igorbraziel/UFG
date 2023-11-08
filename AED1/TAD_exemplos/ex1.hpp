#include <stdlib.h>
#include <iostream>

typedef struct{
    int lado;
} Cubo;


Cubo * init_cubo(int a){
    Cubo * c = NULL;
    c = (Cubo *) calloc(1, sizeof(Cubo));
    c->lado = a;
    return c;
}

void delet_cubo(Cubo * c){
    free(c);
}

int tam_lado(Cubo * c){
    return c->lado;
}

int perimetro_cubo(Cubo * c){
    return c->lado * 12;
}

int volume_cubo(Cubo * c){
    return c->lado * c->lado * c->lado;
}

int area_cubo(Cubo * c){
    return 6 * c->lado * c->lado;
}
