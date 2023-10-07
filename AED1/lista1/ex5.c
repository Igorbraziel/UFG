#include <stdio.h>
#include <stdlib.h>

void intToBin(int num, int *i, int *vetor){
    if(num == 0) return;
    vetor[(*i)] = num % 2;
    //vetor = (int *) realloc(vetor, sizeof(int));
    (*i) = (*i) + 1;
    intToBin(num / 2, i, vetor);
}
int main(){
    int i, qtd, num, j, k = 0;
    int array[10000];

    scanf("%d", &qtd);

    //array = (int *) malloc(sizeof(int));

    for(i = 0; i < qtd; i++){
        scanf("%d", &num);
        intToBin(num, &k, array);
        for(j = k - 1; j >= 0; j--){
            printf("%d", array[j]);
        }
        k = 0;
        printf("\n");
    }

    //free(array);

    return 0;
}