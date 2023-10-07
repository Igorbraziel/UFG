#include <stdio.h>
#include <stdlib.h>
 
struct cidade{
    int *mor;
    int *cons;
    float media;
};
 
typedef struct cidade Cidade;
 
float calc_media(Cidade n1, int qtd){
    int somam = 0, somac = 0, i;
    for(i = 0; i < qtd; i++){
        somam += n1.mor[i];
        somac += n1.cons[i]; 
    }
 
    return (float) somac/somam;
}
 
void soma_cons_igual(Cidade *n1, int qtd){
    int i, j;
    int new_cons = 0, new_soma = 0;
 
    for(i = 0; i < qtd; i++){
        new_soma = n1->mor[i];
        for(j = i; j < qtd; j++){
            if(i != j && n1->cons[i]/n1->mor[i] == n1->cons[j]/n1->mor[j]){
                new_soma += n1->mor[j];
                new_cons = n1->cons[i] / n1->mor[i];
                n1->mor[j] = -1;
                n1->cons[j] = -1;
            }
        }
        if(new_soma != n1->mor[i]){
            n1->mor[i] = new_soma;
            n1->cons[i] = new_cons;
        } else{
            n1->cons[i] /= n1->mor[i];
        }
    }
}
 
void ordena_cons(Cidade *n1, int qtd){
    int i, t, ordem = 0;
    while(1){
        for(i = 0; i < qtd - 1;i++){
            if(n1->cons[i] > n1->cons[i+1]){
                t = n1->cons[i];
                n1->cons[i] = n1->cons[i+1];
                n1->cons[i+1] = t;
                t = n1->mor[i];
                n1->mor[i] = n1->mor[i+1];
                n1->mor[i+1] = t;
            } else{
                ordem++;
            }
        }
        if(ordem == qtd - 1) break;
        ordem = 0;
    }
    
}
 
int main(){
    int qtd, n = 1, i;
    Cidade n1;
 
    while(1){
        scanf("%d", &qtd);
        if(qtd == 0) break;
        n1.mor = (int *) malloc(qtd * sizeof(int));
        n1.cons = (int *) malloc(qtd * sizeof(int));
 
        for(i = 0; i < qtd; i++){
            scanf("%d %d", &n1.mor[i], &n1.cons[i]);
        }
 
        printf("Cidade# %d:\n", n);
 
        n1.media = calc_media(n1, qtd);
 
        soma_cons_igual(&n1, qtd);
 
        ordena_cons(&n1, qtd);
 
        for(i = 0; i < qtd; i++){
            if(n1.cons[i] >= 0 && n1.mor[i] >= 0){
                if(i != qtd - 1){
                    printf("%d-%d ", n1.mor[i], n1.cons[i]);
                } else{
                    printf("%d-%d\n", n1.mor[i], n1.cons[i]);
                }
            }
        }
 
        printf("Consumo medio: %.2lf m3.\n", n1.media);
 
        printf("\n");
 
        n++;
    }
    return 0;
}