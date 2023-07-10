#include <stdio.h>

int somaDivisores(int *n){
    int n1 = *n;
    int div = 1, soma = 0;
    while(div < n1){
        if(n1 % div == 0){
            soma += div;
        }
        div++;
    }
    return soma;
}
void divisores(int *n){
    int n1 = *n;
    int div = 1;
    if(n1 == div) printf(" 0 ");
    while(div < n1){
        if(n1 % div == 0 && div == 1){
            printf(" %d ", div);
        }
        if(n1 % div == 0 && div != 1){
            printf("+ %d ", div);
        }
        div++;
    }
}

int main(){
    int x, somadiv;
    scanf("%d", &x);
    printf("%d =", x);
    divisores(&x);
    somadiv = somaDivisores(&x);
    printf("= %d ", somadiv);
    if(somadiv == x){
        printf("(NUMERO PERFEITO)\n");
    } else {
        printf("(NUMERO NAO E PERFEITO)\n");
    }
    return 0;
}