#include <stdio.h>

int baloes(int n, int k){
    int valor, media;
    if(n % k == 0){
        valor = n / k;
    } else{
        valor = ((int) n / k) + 1;
    }
    if((k + valor) % 2 == 0){
        media = (k + valor) / 2;
    } else{
        media = ((int) ((k + valor) / 2)) + 1;
    }

    return media;

}


int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    printf("%d\n", baloes(n, k));

    return 0;
}