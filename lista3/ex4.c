#include <stdio.h>
#include <math.h>

int main(){
    int qtd, i, i2, n, valor = 0;
    double p;
    int v[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    p = pow(10,100);
    scanf("%d", &qtd);
    for(i=0;i<qtd;i++){
        scanf("%d", &n);
        if(n<1 || n > p){
            return 0;
        }
        while(n>0){
            i2 = n%10;
            valor += v[i2];
            n /= 10;
        }
        printf("%d leds\n", valor);
        valor = 0;
        i2 = 0;
    }
    return 0;
}