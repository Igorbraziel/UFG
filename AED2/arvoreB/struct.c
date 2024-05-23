#include <stdio.h>
#include <stdlib.h>

struct node {
    int chaves[4];
    int numero_chaves;
    struct node * pai;
    struct node * filhos[5]; 
};

typedef struct node Node;

int main(){
    Node * raiz = NULL;
    return 0;
}