#include "conjunto.hpp"
#include <stdlib.h>
#include <iostream>

struct conjunto{
    int *vetor;
    int tam_vetor;
};

Conjunto * cria_conjunto(Conjunto *c){
    c = (Conjunto *) calloc(1, sizeof(Conjunto));
    c->vetor = (int *) calloc(1, sizeof(int));
    c->tam_vetor = 0;
    (*c).tam_vetor = 0;
    return c;
}

int conjuntoVazio(Conjunto *c){
    if(c->tam_vetor == 0){
        return TRUE;
    } else{
        return FALSE;
    }
}

int insereElementoConjunto(int x, Conjunto * c){
    int i, k = 0;

    for(i = 0; i < c->tam_vetor; i++){
        if(x == c->vetor[i]) k++;
    }

    if(k > 0) return FALHA;

    c->tam_vetor++;
    c->vetor = (int *) realloc(c->vetor, (c->tam_vetor) * sizeof(int));
    c->vetor[c->tam_vetor - 1] = x;

    return SUCESSO;
}

int excluirElementoConjunto(int x, Conjunto *c){
    int i, t = 0;

    for(i = 0; i < c->tam_vetor; i++){
        if(c->vetor[i] == x){
            t = c->vetor[c->tam_vetor - 1];
            c->vetor[c->tam_vetor - 1] = x;
            c->vetor[i] = t;
            //
            c->tam_vetor--;
            c->vetor = (int *) realloc(c->vetor, (c->tam_vetor) * sizeof(int));
            return SUCESSO;
        }
    }

    return FALHA;
}

int tamanhoConjunto(Conjunto *c){
    return c->tam_vetor; 
}

int maior(int x, Conjunto *c){
    int i, k = 0;

    for(i = 0; i < c->tam_vetor; i++){
        if(x > c->vetor[i]) k++;
    }

    return k;
}

int menor(int x, Conjunto *c){
    int i, k = 0;

    for(i = 0; i < c->tam_vetor; i++){
        if(x < c->vetor[i]) k++;
    }

    return k;
}

int pertenceConjunto(int x, Conjunto *c){
    int i;

    for(i = 0; i < c->tam_vetor; i++){
        if(x == c->vetor[i]) return TRUE;
    }

    return FALSE;
}

void conjunto_delete(Conjunto *c){
    free(c->vetor);
    free(c);
}

void conjunto_print(Conjunto *c){
    int i;

    std::cout << "(";

    for(i = 0; i < c->tam_vetor; i++){
        if(i == 0){
            std::cout << c->vetor[i];
        } else{
            std::cout << ", " << c->vetor[i];
        }
    } 

    std::cout << ")" << "\n";
}

int conjuntosIdenticos(Conjunto *c1, Conjunto *c2){
    int i, j, k = 0;

    if(c1->tam_vetor != c2->tam_vetor) return FALSE;

    for(i = 0; i < c1->tam_vetor; i++){
        for(j = 0; j < c2->tam_vetor; j++){
            if(c1->vetor[i] == c1->vetor[j]){
                k = 1;
                break;
            }
        }
        if(k == 0) return FALSE;
        k = 0;
    }

    return TRUE;
}

int subconjunto(Conjunto *c1, Conjunto *c2){
    int i, j, k = 0;

    if(c1->tam_vetor > c2->tam_vetor) return FALSE;

    for(i = 0; i < c1->tam_vetor; i++){
        for(j = 0; j < c2->tam_vetor; j++){
            if(c1->vetor[i] == c2->vetor[j]){
                k = 1;
                break;
            }
        }
        if(k == 0) return FALSE;
        k = 0;
    }

    return TRUE;
}

Conjunto * uniao(Conjunto *c1, Conjunto *c2){
    Conjunto * c = NULL;
    int i, j, k = 0;
    c = cria_conjunto(c);

    for(i = 0; i < c1->tam_vetor; i++){
        insereElementoConjunto(c1->vetor[i], c);
    }

    for(i = 0; i < c2->tam_vetor; i++){
        for(j = 0; j < c1->tam_vetor; j++){
            if(c2->vetor[i] == c1->vetor[j]){
                k = 1;
                break;
            }
        }
        if(k == 0) insereElementoConjunto(c2->vetor[i], c);
        k = 0;
    }

    return c;
}

Conjunto * interseccao(Conjunto *c1, Conjunto *c2){
    Conjunto * intersec = NULL;
    int i, j;
    intersec = cria_conjunto(intersec);

    for(i = 0; i < c1->tam_vetor; i++){
        for(j = 0; j < c2->tam_vetor; j++){
            if(c1->vetor[i] == c2->vetor[j]){
                insereElementoConjunto(c1->vetor[i], intersec);
                break;
            }
        }
    }

    return intersec;
}

Conjunto * diferenca(Conjunto *c1, Conjunto *c2){
    Conjunto * dif = NULL;
    int i, j, k = 0;

    dif = cria_conjunto(dif);

    for(i = 0; i < c1->tam_vetor; i++){
        for(j = 0; j < c2->tam_vetor; j++){
            if(c1->vetor[i] == c2->vetor[j]){
                k = 1;
                break;
            }
        }
        if(k == 0) insereElementoConjunto(c1->vetor[i], dif);
        k = 0;
    }

    return dif;
}

Conjunto * conjuntoPartes(Conjunto *c);

void mostraConjunto(Conjunto *c, int ordem){
    if(ordem == 1){
        crescente(c);
        conjunto_print(c);
    } else if(ordem == 0){
        decrescente(c);
        conjunto_print(c);
    }
}

void crescente(Conjunto * c){
    int i, t, ordem = 0;
    while(1){
        for(i = 0; i < c->tam_vetor - 1; i++){
            if(c->vetor[i] <= c->vetor[i + 1]){
                ordem++;
            } else{
                t = c->vetor[i];
                c->vetor[i] = c->vetor[i + 1];
                c->vetor[i + 1] = t;
            }
        }
        if(ordem == c->tam_vetor - 1) break;
        ordem = 0;
    }
}

void decrescente(Conjunto * c){
    int i, t, ordem = 0;

    while(1){
        for(i = 0; i < c->tam_vetor - 1; i++){
            if(c->vetor[i] >= c->vetor[i + 1]){
                ordem++;
            } else{
                t = c->vetor[i];
                c->vetor[i] = c->vetor[i + 1];
                c->vetor[i + 1] = t;
            }
        }
        if(ordem == c->tam_vetor - 1) break;
        ordem = 0;
    }
}   

int copiarConjunto(Conjunto * c1, Conjunto * c2){
    int i;

    for(i = 0; i < c1->tam_vetor; i++){
        insereElementoConjunto(c1->vetor[i], c2);
    }

    return SUCESSO;
}
