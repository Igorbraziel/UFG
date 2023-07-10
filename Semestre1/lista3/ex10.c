#include <stdio.h>

int main(){
    int v[1000], w[1000];
    int qtd, i, max = 0, min = 0, i2 = 0, i3 = 0, x, saida = 0;
    scanf("%d", &qtd);
    for(i=0;i<qtd;i++){
        scanf("%d", &x);
        if(i == 0){
            min = x;
        }
        v[i] = x;
        if(v[i] >= max){
            max = v[i];
        }
        if(v[i] <= min){
            min = v[i];
        }
    }
    for(i2 = 0; i2 < qtd; i2++){
        w[i2] = v[i-1];
        i--;
    }
    for(i3 = 0; i3 < qtd; i3++){
        printf("%d ", v[i3]);
    }
    printf("\n");
    for(i3 = 0; i3 < qtd; i3++){
        printf("%d ", w[i3]);
    }
    printf("\n");
    printf("%d\n", max);
    printf("%d\n", min);
    return 0;
}