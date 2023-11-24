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
int killBacterium (World * w, int n);
int killBacteriumXY (World * w, int x, int y);
World * jointWorlds (World * w1, World * w2);
World * warWorlds (World * w1, World * w2);
World * probabilisticWarWorlds (World * w1, World *w2, float p);
int sizeWorld (World * w);
int forceWorld (World * w);
void worldPrint(World * w);
int showWorld (World * w);

#endif
