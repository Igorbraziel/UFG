#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int matricula;
    int idade;
    int numFilhos;
    char sexo;
    double salario;
} FUNCIONARIO;
 
int main(){
    int qtd, i;
    int k1 = 0, k2 = 0, k3 = 0, k4 = 0;
    float mediaIdade = 0, mediaFilhos = 0;
    FUNCIONARIO *vetor;
 
    scanf("%d", &qtd);
 
    vetor = (FUNCIONARIO *) malloc(qtd * sizeof(FUNCIONARIO));
 
    for(i = 0; i < qtd; i++){
        scanf("%d %d %d %c %lf", &vetor[i].matricula, &vetor[i].idade, &vetor[i].numFilhos, &vetor[i].sexo, &vetor[i].salario);
    }
 
    for(i = 0; i < qtd; i++){
        mediaIdade += vetor[i].idade;
        mediaFilhos += vetor[i].numFilhos;        
    }
 
    mediaIdade = mediaIdade / qtd;
    mediaFilhos = mediaFilhos / qtd;
 
    for(i = 0; i < qtd; i++){
        if(vetor[i].idade > mediaIdade && vetor[i].salario > 3600) k1++;
        if(vetor[i].sexo == 'F' && vetor[i].numFilhos > mediaFilhos) k2++;
        if(vetor[i].sexo == 'M' && vetor[i].numFilhos > mediaFilhos) k3++;
        if(vetor[i].idade > 47 && vetor[i].salario / (vetor[i].numFilhos + 1) < 2400) k4++;        
    }
 
    printf("%d %d %d %d\n", k1, k2, k3, k4);                                                
 
    free(vetor);
 
    return 0;
}