#include <stdio.h>

int main(){
    int qtd, i, z, i2 = 0, i3 = 0, max = 0, n = 0, ordem = 0, x = 0, y = 0, a = 0;
    int v[1000000], w[1000000];
    double b = 0;
    scanf("%d", &qtd);
    for(i=0;i<qtd;i++){
        scanf("%d", &z);
        v[i] = z;
        if(v[i] >= max){
            max = v[i];
        }
    }
    while(1){
        for(i = 0; i < qtd - 1; i++){
            if(v[i] > v[i + 1]){
                n = v[i];
                v[i] = v[i+1];
                v[i+1] = n;
            } else if(v[i] <= v[i + 1]) ordem++;
        }
        if(ordem == (qtd - 1)) break;
        ordem = 0;
    }
    if(qtd%2==0){
        x = qtd/2;
        y = v[x];
        a = v[x - 1];
        b = (double) (a + y) / 2;
        printf("%.2lf\n", b);
    } else if(qtd%2!=0){
        x = qtd/2;
        double y = v[x];
        printf("%.2lf\n", y);
    }
    return 0;
}