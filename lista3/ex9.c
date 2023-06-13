#include <stdio.h>

int main(){
    int qtd, i, i2 = 0, n, vezes = 0, max = 0, i3 = 0, posicao = 0;
    int v[10000];
    scanf("%d", &qtd);
    for(i=0;i<qtd;i++){
        scanf("%d", &n);
        v[i] = n;
        if(v[i] >= max){
            max = v[i];
        }
    }
    while(i2 < qtd){
        if(v[i2] == v[i -1]){
            vezes += 1;
        }
        i2++;
    }
    while(i3 < qtd){
        if(v[i3] == max){
            posicao = i3;
            break;
        }
        i3++;
    }
    printf("Nota %d, %d vezes\n", v[i -1], vezes);
    printf("Nota %d, indice %d\n", max, posicao);
    return 0;
}