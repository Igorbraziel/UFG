#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int numJogo;
    int numero[6];
} CARTELA;
 
typedef struct{
    int concurso;
    int num[6];
} SORTEADOS;
 
int main(){
    int qtd, i, j, x, indice = 0, k = 0;
    CARTELA *vetor = NULL;
    SORTEADOS n1;
 
    scanf("%d", &qtd);
 
    vetor = (CARTELA *) malloc(qtd * sizeof(CARTELA));
 
    for(i = 0; i < qtd; i++){
        scanf("%d %d %d %d %d %d %d", &vetor[i].numJogo, &vetor[i].numero[0], &vetor[i].numero[1], &vetor[i].numero[2], &vetor[i].numero[3], &vetor[i].numero[4], &vetor[i].numero[5]);
    }
 
    scanf("%d %d %d %d %d %d %d", &n1.concurso, &n1.num[0], &n1.num[1], &n1.num[2], &n1.num[3], &n1.num[4], &n1.num[5]);
 
    for(i = 0; i < qtd; i++){
        for(j = 0; j < 6; j++){
            for(x = 0; x < 6; x++){            
                if(vetor[i].numero[j] == n1.num[x]) k++;
            }
        }
        if(k == 4){
            indice = 1;
            printf("QUADRA %d: ", vetor[i].numJogo);
            for(j = 0; j < 6; j++){
                for(x = 0; x < 6; x++){            
                    if(vetor[i].numero[j] == n1.num[x]) printf("%d ", vetor[i].numero[j]);
                }
            }
            printf("\n");
        } else if(k == 5){
            indice = 1;
            printf("QUINA %d: ", vetor[i].numJogo);
            for(j = 0; j < 6; j++){
                for(x = 0; x < 6; x++){            
                    if(vetor[i].numero[j] == n1.num[x]) printf("%d ", vetor[i].numero[j]);
                }
            }
            printf("\n");
        } else if(k == 6){
            indice = 1;
            printf("SENA %d: ", vetor[i].numJogo);
            for(j = 0; j < 6; j++){
                for(x = 0; x < 6; x++){            
                    if(vetor[i].numero[j] == n1.num[x]) printf("%d ", vetor[i].numero[j]);
                }
            }
            printf("\n");
        }
        k = 0;
    }
 
    if(indice == 0){
        printf("NENHUMA CARTELA PREMIADA PARA O CONCURSO %d\n", n1.concurso);
    }
 
    free(vetor);
 
    return 0;
}