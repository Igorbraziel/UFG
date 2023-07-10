#include <stdio.h>
#include <math.h>

int main(){
    char numero[100000];
    int v1[100000], vn[100000];
    int n, d, i = 0, i2 = 0, t = 0, i3 = 0, indice = 0, k = 0, maior = 0;
    while(1){
        scanf("%d %d", &n, &d);
        if(n == 0 && d == 0){
            break;
        }
        scanf("%s", numero);
        while(numero[i] != '\0'){
            v1[i] = numero[i] - '0';
            i++;
        }
        i3 = i;
        k = n - d;
        for(i=0;i<=k;i++){
            if(k==n) break;
            if(v1[i] > maior){
                maior = v1[i];
                indice = i;
            }
            if(i==k){
                printf("%d", maior);
                i = indice;
                k++;
                maior = 0;
            }
        }
        for(i2=0;i2<13;i2++){
            v1[i2] = 0;
        }
        i = 0;
        maior = 0;
        indice = 0;
        printf("\n");
    }
    return 0;
}