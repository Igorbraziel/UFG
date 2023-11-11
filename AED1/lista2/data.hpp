#ifndef __DATA__
#define __DATA__

struct data;

typedef struct data Data;

#define TRUE 1
#define FALSE 0

#define MENOR -1
#define IGUAL 0
#define MAIOR 1

Data * criaData (int dia, int mes, int ano);
Data * copiaData (Data * d);
void liberaData (Data * d);
Data * somaDiasData (Data * d, int dias);
void mostraData(Data * d);
Data * subtrairDiasData (Data * d, int dias);
void atribuirData (Data * d, int dia, int mes, int ano);
int obtemDiaData (Data * d);
int obtemMesData (Data * d);
int obtemAnoData (Data * d);
int bissextoData (Data * d);
int comparaData (Data * d1, Data * d2);
int numeroDiasDatas (Data * d1, Data * d2);
int numeroMesesDatas (Data * d1, Data * d2);
int numeroAnosDatas (Data * d1, Data * d2);
char * imprimeData (Data * d, char * formato);

int obtemDiaSemanaData (Data * d);

#endif