#include <stdio.h>

void imprimeNatural(int num, int k){
    if(k == num){
        printf("%d\n", num);
        return;
    }
    printf("%d ", k);
    imprimeNatural(num, k + 1);
}

int main(){
    int n;
    scanf("%d", &n);
    imprimeNatural(n, 1);
    return 0;
}