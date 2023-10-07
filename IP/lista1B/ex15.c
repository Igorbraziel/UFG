    #include <stdio.h>
     
    int somaDiv(int n){
        int d=1, soma=0;
        while(d<n){
            if(n%d == 0){
                soma += d;
            }
            d++;
        }
        return soma;
    }
     
    int main(){
        int n, n1=220, cont=1, soma1, soma2;
        scanf("%d", &n);
        while(cont<=n){
            soma1 = somaDiv(n1);
            soma2 = somaDiv(soma1);
            if(soma2 == n1 && n1 < soma1){
                printf("(%d,%d)\n", n1, soma1);
                cont++;
            }
            n1++;
        }
        return 0;
    }