#include <stdio.h>

int main(){
    int qtd, i, i2 = 0, k = 0, valor = 0;
    char n[102];
    int v[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    scanf("%d", &qtd);
    for(i=0;i<qtd;i++){
        scanf("%s", n);
        while(n[k] != '\0'){
            i2 = n[k] - '0';
            valor += v[i2];
            k++;
        }
        printf("%d leds\n", valor);
        valor = 0;
        k = 0;
        i2 = 0;
    }
    return 0;
}