#include <stdio.h>

int main(){
    int matriz[10][10];
    int nl, nc;
    int i, i2, linha = 1;

    while(1){
        scanf("%d", &nl);
        if(nl > 0 && nl <= 10) break;
    }

    while(1){
        scanf("%d", &nc);
        if(nc > 0 && nc <= 10) break;
    }

    for(i=0;i<nl;i++){
        for(i2=0;i2<nc;i2++){
            scanf("%d", &matriz[i][i2]);
        }
    }

    i = 0;

    while(linha<=nl){
        printf("linha %d: ", linha);
            for(i2=0;i2<nc;i2++){
                if(i2 != nc-1) printf("%d,", matriz[i][i2]);
                if(i2 == nc-1) printf("%d\n", matriz[i][i2]);
            }
        linha++;
        i++;
    }
    return 0;
}