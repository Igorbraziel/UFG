#include <stdio.h>

int main(){
    int matriz[1000][1000];
    int qtd, i, i2, k;
    
    scanf("%d", &qtd);

    k = qtd-1;

    for(i=0;i<qtd;i++){
        for(i2=0;i2<qtd;i2++){
            scanf("%d", &matriz[i][i2]);
        }
    }

    for(i=0;i<qtd;i++){
        for(i2=0;i2<qtd;i2++){
            if(k==i2){
                printf("%d\n", matriz[i][k]);
                k--;
            }
        }
    }
    return 0;
}