#include <stdio.h>
 
#define MAX 30
 
struct turma{
    int mat[MAX];
    int dia[MAX];
    int mes[MAX];
    int ano[MAX];
    char nome[MAX][200];
};
 
typedef struct turma Turma;
 
void ComparaDataNasc(Turma *n1, int n){
    int i, j, t, t1, c, ordem = 0;
    char str[200];
    while(1){
        for(i = 0; i < n - 1; i++){
            if(n1->ano[i] < n1->ano[i+1]){
                t = n1->ano[i];
                n1->ano[i] = n1->ano[i+1];
                n1->ano[i+1] = t;
 
                t = n1->mes[i];
                n1->mes[i] = n1->mes[i+1];
                n1->mes[i+1] = t;
 
                t = n1->dia[i];
                n1->dia[i] = n1->dia[i+1];
                n1->dia[i+1] = t;
 
                t1 = n1->mat[i];
                n1->mat[i] = n1->mat[i+1];
                n1->mat[i+1] = t1;
 
                for(c = 0; n1->nome[i][c] != '\0'; c++){
                    str[c] = n1->nome[i][c];
                    str[c+1] = '\0';
                }
 
                for(c = 0; n1->nome[i+1][c] != '\0'; c++){
                    n1->nome[i][c] = n1->nome[i+1][c];
                    n1->nome[i][c+1] = '\0'; 
                }
 
                for(c = 0; str[c] != '\0'; c++){
                    n1->nome[i+1][c] = str[c];
                    n1->nome[i+1][c+1] = '\0'; 
                }
            } else if(n1->ano[i] == n1->ano[i+1]){
                if(n1->mes[i] < n1->mes[i+1]){
                    t = n1->ano[i];
                    n1->ano[i] = n1->ano[i+1];
                    n1->ano[i+1] = t;
 
                    t = n1->mes[i];
                    n1->mes[i] = n1->mes[i+1];
                    n1->mes[i+1] = t;
 
                    t = n1->dia[i];
                    n1->dia[i] = n1->dia[i+1];
                    n1->dia[i+1] = t;
 
                    t1 = n1->mat[i];
                    n1->mat[i] = n1->mat[i+1];
                    n1->mat[i+1] = t1;
 
                    for(c = 0; n1->nome[i][c] != '\0'; c++){
                        str[c] = n1->nome[i][c];
                        str[c+1] = '\0';
                    }
 
                    for(c = 0; n1->nome[i+1][c] != '\0'; c++){
                        n1->nome[i][c] = n1->nome[i+1][c];
                        n1->nome[i][c+1] = '\0'; 
                    }
 
                    for(c = 0; str[c] != '\0'; c++){
                        n1->nome[i+1][c] = str[c];
                        n1->nome[i+1][c+1] = '\0'; 
                    }
                } else if(n1->mes[i] == n1->mes[i+1]){
                    if(n1->dia[i] < n1->dia[i+1]){
                        t = n1->ano[i];
                        n1->ano[i] = n1->ano[i+1];
                        n1->ano[i+1] = t;
 
                        t = n1->mes[i];
                        n1->mes[i] = n1->mes[i+1];
                        n1->mes[i+1] = t;
 
                        t = n1->dia[i];
                        n1->dia[i] = n1->dia[i+1];
                        n1->dia[i+1] = t;
 
                        t1 = n1->mat[i];
                        n1->mat[i] = n1->mat[i+1];
                        n1->mat[i+1] = t1;
 
                        for(c = 0; n1->nome[i][c] != '\0'; c++){
                            str[c] = n1->nome[i][c];
                            str[c+1] = '\0';
                        }
 
                    for(c = 0; n1->nome[i+1][c] != '\0'; c++){
                        n1->nome[i][c] = n1->nome[i+1][c];
                        n1->nome[i][c+1] = '\0'; 
                    }
 
                    for(c = 0; str[c] != '\0'; c++){
                        n1->nome[i+1][c] = str[c];
                        n1->nome[i+1][c+1] = '\0'; 
                    }
                    } else{
                        ordem++;
                    }
                } else{
                    ordem++;
                }
            } else{
                ordem++;
            }
        }
        if(ordem == n - 1) break;
        ordem = 0;
    }
}
 
int main(){
    Turma n1;
    int n, i;
 
    scanf("%d", &n);
 
    for(i = 0; i < n; i++){
        scanf("%d", &n1.mat[i]);
        scanf("%d %d %d%*c", &n1.dia[i], &n1.mes[i], &n1.ano[i]);
        scanf("%[^\n]", n1.nome[i]);
    }
 
    ComparaDataNasc(&n1, n);
 
    for(i = 0; i < n; i++){
        printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n", n1.mat[i], n1.nome[i], n1.dia[i], n1.mes[i], n1.ano[i]);
    }
 
    return 0;
}