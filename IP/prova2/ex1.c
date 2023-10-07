#include <stdio.h>
 
void le_vetor(int *vetor, int N){
    int i = 0, k = 0, x = 0, i2 = 0;
    for(i=0;i<N;i++){
        if(i==0) scanf("%d", &vetor[i]);
        if(i>=1){
            while(1){
                scanf("%d", &x);
                for(k=0;k<i;k++){
                    if(x == vetor[k]){
                        i2++;
                    }
                }
                if(i2 == 0){
                    vetor[i] = x;
                    break;
                } else{
                        i2 = 0;
                    }
            }
        }
    }
}
 
void imprime_vetor(int *vetor, int N){
    int i = 0;
    for(i=0;i<N;i++){
        if(i==0){
            printf("(%d", vetor[i]);
        } else{
            printf(",%d", vetor[i]);
        } 
    }
    printf(")\n");
}
 
int A_B(int *vetorA, int *vetorB, int tA, int tB, int *vetorAB){
    int i = 0, i2 = 0, k = 0, j = 0;
 
    for(i=0;i<tA;i++){
        for(i2=0;i2<tB;i2++){
            if(vetorA[i] == vetorB[i2]){
                k++;
            }
        }
        if(k == 0){
            vetorAB[j] = vetorA[i];
            j++;
        } else{
            k = 0;
        }
    }
    return j;
}
 
 
int main(){
    int vetorA[100], vetorB[100], vetorAB[100];
    int tA, tB, tF;
    int i, j;
 
    while(1){
        scanf("%d", &tA);
        if(tA>=1 && tA<=100) break;
    }
 
    while(1){
        scanf("%d", &tB);
        if(tB>=1 && tB<=100) break;
    }
 
    le_vetor(vetorA, tA);
    
    le_vetor(vetorB, tB);
 
    imprime_vetor(vetorA, tA);
 
    imprime_vetor(vetorB, tB);
 
    tF = A_B(vetorA, vetorB, tA, tB, vetorAB);
 
    if(tF == 0){
        printf("()\n");
    } else{
        imprime_vetor(vetorAB, tF);
    }
 
    printf("(");
 
    for(i=0;i<tA;i++){
        for(j=0;j<tB;j++){
            if(i == 0 && j == 0){
                printf("(%dx%d)", vetorA[i], vetorB[j]);
            } else{
                printf(",(%dx%d)", vetorA[i], vetorB[j]);
            }
        }
    }
 
    printf(")\n");
 
 
    return 0;
}