#ifndef __TEXTO__
#define __TEXTO__

struct texto;

typedef struct texto Texto;

#define MAIOR 1
#define MENOR -1 
#define IGUAL 0

Texto * criarTexto (char * t);
void liberarTexto (Texto * t);
int tamanhoTexto (Texto * t);
char * obterTexto (Texto * t);
void mostrarTexto (Texto * t, int colunas);
Texto * copiarTexto (Texto * t);
void substituirTexto (Texto * t, char * alteracao);
Texto * concatenarTextos (Texto * t1, Texto * t2);
char * obterSubtexto (Texto * t, int inicio, int tamanho);
int encontrarSubtexto (Texto * t, char * subtexto, int ocorrencia);
int compararTextos (Texto * t1, Texto * t2);

#endif