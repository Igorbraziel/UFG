#ifndef __COMPLEX_HPP__
#define __COMPLEX_HPP__

struct complexo;
struct numero;

typedef struct complexo Complexo;

typedef struct numero Numero;

#define SUCESSO 1
#define FALHA 0

#define TRUE 1
#define FALSE 0

Complexo * criaConjunto();
void freeConjunto(Complexo * c);
void freeNumero(Numero * c);
bool conjuntoVazio(Complexo * c);
int insereElementoConjunto(Numero * x, Complexo * c);
int excluirElementoConjunto(Numero * x, Complexo * c);
int tamanhoConjunto(Complexo * c);
void showConjunto(Complexo * c);
Numero * criaNumero(int real, int imaginario);
bool pertenceConjunto(Numero * x, Complexo * c);
bool conjuntosIdenticos(Complexo * c1, Complexo * c2);
bool subconjunto(Complexo * c1, Complexo * c2);
Complexo * complemento(Complexo * c1, Complexo * c2);
Complexo * uniao(Complexo * c1, Complexo * c2);
Complexo * interseccao(Complexo * c1, Complexo * c2);
Complexo * diferenca(Complexo * c1, Complexo * c2);
bool isElementIn(Complexo * c);


#endif