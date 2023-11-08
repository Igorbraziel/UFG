#ifndef __CONJUNTO__
#define __CONJUNTO__

struct conjunto;

typedef struct conjunto Conjunto;

#define TRUE 1
#define FALSE 0

#define SUCESSO 1
#define FALHA 0

#define CRESCENTE 1
#define DECRESCENTE 0

Conjunto * cria_conjunto(Conjunto *c);
int conjuntoVazio(Conjunto *c);
int insereElementoConjunto(int x, Conjunto * c);
int excluirElementoConjunto(int x, Conjunto *c);
int tamanhoConjunto(Conjunto *c);
int maior(int x, Conjunto *c);
int menor(int x, Conjunto *c);
int pertenceConjunto(int x, Conjunto *c);
void conjunto_delete(Conjunto *c);
void conjunto_print(Conjunto *c);
int conjuntosIdenticos(Conjunto *c1, Conjunto *c2);
int subconjunto(Conjunto *c1, Conjunto *c2);
Conjunto * uniao(Conjunto *c1, Conjunto *c2); 
Conjunto * interseccao(Conjunto *c1, Conjunto *c2);
Conjunto * diferenca(Conjunto *c1, Conjunto *c2);
void mostraConjunto(Conjunto *c, int ordem);
void crescente(Conjunto * c);
void decrescente(Conjunto * c);

Conjunto * conjuntoPartes(Conjunto *c);

#endif