#include <stdio.h>

void crescente(int *p){
    int ordem = 0, t = 0, i = 0;
    while(77){
        for(i=0;i<8;i++){
            if(p[i] > p[i+1]){
                t = p[i];
                p[i] = p[i+1];
                p[i+1] = t;
            } else{
                ordem++;
            }
        }
        if(ordem == 8){
            break;
        } else{
            ordem = 0;
        }

    }
}

int main(){
    int v[100];
    int qtd, i, i2, soma = 0, cont1 = 0, cont2 = 0, cont3 = 0, imp1 = 0, imp2 = 0;
    scanf("%d", &qtd);
    for(i=0;i<qtd;i++){
        for(i2=0;i2<9;i2++){
            scanf("%d", &v[i2]);
        }
        crescente(v);
        for(cont1=0;cont1<9;cont1++){
            soma += v[cont1];
        }
        soma -= 100;
        for(cont1=0;cont1<9;cont1++){
            for(cont2=cont1+1;cont2<9;cont2++){
                if(v[cont1] + v[cont2] == soma){
                    imp1 = cont1;
                    imp2 = cont2;
                    cont1 = 10;
                    cont2 = 10;
                    break;
                }
            }
        }
        for(cont3=0;cont3<9;cont3++){
            if(v[cont3] != v[imp1] && v[cont3] != v[imp2]){
                printf("%d\n", v[cont3]);
            }
        }
        imp1 = 0;
        imp2 = 0;
        cont1 = 0;
        cont2 = 0;
        soma = 0;
    }
    return 0;
}