#include <stdio.h>

int main(){
    int matriz[50][50];
    int caso = 1, testes;
    int qtd, i, i2, k = 0;
    
    scanf("%d", &testes);

    while(caso<=testes){
        scanf("%d", &qtd);
            for(i2=0;i2<qtd;i2++){
                scanf("%d/%d", &matriz[0][i2], &matriz[1][i2]);
            }

        printf("Caso de teste %d\n", caso);

            for(i=0;i<qtd;i++){
                for(i2=i;i2<qtd;i2++){
                    if((double) matriz[0][i] / matriz[1][i] == (double) matriz[0][i2] / matriz[1][i2] && i < i2){
                        printf("%d/%d equivalente a %d/%d\n", matriz[0][i], matriz[1][i], matriz[0][i2], matriz[1][i2]);
                        k++;
                    }
                }
            }
            if(k==0) printf("Nao ha fracoes equivalentes na sequencia\n");
            k = 0;
        caso++;
    }
    return 0;
}