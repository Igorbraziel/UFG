#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
struct curso{
    int *codigoc;
    float *credito;
    char **nomec;
};
 
typedef struct curso Curso;
 
struct aluno{
    char **nomeal;
    int *codigoal;
    int *ncredit;
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
        printf("Aluno(a): %s ", a1.nomeal[i]);
        printf("Curso: %s ", c1.nomec[indice]);
        printf("Num. Creditos: %d ", a1.ncredit[i]);
        printf("Valor Credito: %.2f ", c1.credito[indice]);
        printf("Mensalidade: %.2f\n", (float) (a1.ncredit[i] * c1.credito[indice]));
}
 
int main(){
    Aluno a1;
    Curso c1;
    int nc, i, j, m, indice;
    char str[1000];
 
    scanf("%d%*c", &nc);

    c1.codigoc = (int *) malloc(nc * sizeof(int));

    c1.credito = (float *) malloc(nc * sizeof(float));

    c1.nomec = (char **) malloc(nc * sizeof(char *));
 
    for(i=0;i<nc;i++){
        scanf("%d", &c1.codigoc[i]);
        scanf("%f%*c", &c1.credito[i]);
        scanf("%[^\n]%*c", str);
        for(j=0; str[j] != '\0'; j++){

        }
        c1.nomec[i] = (char *) malloc((j+1) * sizeof(char));
        for(j=0; str[j] != '\0'; j++){
            c1.nomec[i][j] = str[j];
        }
        c1.nomec[i][j] = '\0';
    }
 
    scanf("%d%*c", &m);

    a1.codigoal = (int *) malloc(m * sizeof(int));

    a1.ncredit = (int *) malloc(m * sizeof(int));

    a1.nomeal = (char **) malloc(m * sizeof(char *));
 
    for(i=0;i<m;i++){
        scanf("%[^\n]%*c", str);
        scanf("%d", &a1.codigoal[i]);
        scanf("%d%*c", &a1.ncredit[i]);
        for(j=0; str[j] != '\0'; j++){

        }
        a1.nomeal[i] = (char *) malloc((j+1) * sizeof(char));

        for(j=0; str[j] != '\0'; j++){
            a1.nomeal[i][j] = str[j]; 
        }
        a1.nomeal[i][j] = '\0';
    }
    for(i=0;i<m;i++){
        indice = procura_curso(a1, c1, nc, i);
        print_tabela(a1, c1, indice, i);
    }

    free(c1.codigoc);
    free(c1.credito);
    free(c1.nomec);

    free(a1.codigoal);
    free(a1.ncredit);
    free(a1.nomeal);
 
    return 0;
}