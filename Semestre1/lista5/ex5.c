#include <stdio.h>
#include <string.h>

struct curso{
    int codigoc[30];
    float credito[30];
    char nomec[30][100];
};

typedef struct curso Curso;

struct aluno{
    char nomeal[1000][500];
    int codigoal[1000];
    int ncredit[1000];
};

typedef struct aluno Aluno;

int procura_curso(Aluno a1, Curso c1, int nc, int i){
    int j;
        for(j = 0; j < nc; j++){
            if(a1.codigoal[i] == c1.codigoc[j]){
                return j;
            }
        }
}

void print_tabela(Aluno a1, Curso c1, int indice, int i){
    if(i>0){
        printf("Aluno(a): %s ", a1.nomeal[i]);
        printf("Curso: %s ", c1.nomec[indice]);
        printf("Num. Creditos: %d ", a1.ncredit[i]);
        printf("Valor Credito: %.2f ", c1.credito[indice]);
        printf("Mensalidade: %.2f\n", (float) (a1.ncredit[i] * c1.credito[indice]));
    }
}

int main(){
    Aluno a1;
    Curso c1;
    int nc, i, m, indice;

    scanf("%d", &nc);

    for(i=0;i<nc;i++){
        scanf("%d", &c1.codigoc[i]);
        scanf("%f%*c", &c1.credito[i]);
        scanf("%[^\n]%*c", c1.nomec[i]);
    }

    scanf("%d", &m);

    for(i=0;i<m+1;i++){
        scanf("%[^\n]%*c", a1.nomeal[i]);
        scanf("%d", &a1.codigoal[i]);
        scanf("%d%*c", &a1.ncredit[i]);
    }
    for(i=0;i<m+1;i++){
        indice = procura_curso(a1, c1, nc, i);
        print_tabela(a1, c1, indice, i);
    }

    return 0;
}