#include <stdio.h>

int main(){
    int sorteados[6], apostas[6];
    int qtd, i, i2, i3, k = 0, sena = 0, quina = 0, quadra = 0;
    for(i=0;i<6;i++){
        scanf("%d", &sorteados[i]);
    }
    scanf("%d", &qtd);
    for(i=0;i<qtd;i++){
        for(i2=0;i2<6;i2++){
            scanf("%d", &apostas[i2]);
            for(i3=0;i3<6;i3++){
                if(apostas[i2] == sorteados[i3]){
                    k++;
                }
            }
        }
        if(k==4) quadra++;
        if(k==5) quina++;
        if(k==6) sena++;
        k = 0;
    }
    if(sena > 0){
        printf("Houve %d acertador(es) da sena\n", sena);
    } else{
        printf("Nao houve acertador para sena\n");
    }
    if(quina > 0){
        printf("Houve %d acertador(es) da quina\n", quina);
    } else{
        printf("Nao houve acertador para quina\n");
    }
    if(quadra > 0){
        printf("Houve %d acertador(es) da quadra\n", quadra);
    } else{
        printf("Nao houve acertador para quadra\n");
    }
}