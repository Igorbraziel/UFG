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

int criaConjunto(Complexo * c);
int conjuntoVazio(Complexo * c);
int insereElementoConjunto(Numero * x, Complexo * c);
int excluirElementoConjunto(Numero * x, Complexo * c);
int tamanhoConjunto(Complexo * c);




#endif