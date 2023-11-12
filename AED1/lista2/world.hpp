#ifndef __WORLD__
#define __WORLD__

struct world;

typedef struct world World;

#define FALHA 0
#define SUCESSO 1

#define FALSE 0
#define TRUE 1

World * newWorld (int linhas, int colunas);
World * cloneWorld (World * w);
void freeWorld (World * w);
int addBacterium (World * w, int n, int f, int e);
int addBacteriumXY (World * w,  int n, int f, int e, int x, int y);
int verificaBacteria(World * w, int n);

int randomWorld (World * w, int n);



#endif