    #include <stdio.h>
    int main(){
        int n, div=0, soma = 0, cont1=2, cont2=0, um=1, cont3=2;
        scanf("%d", &n);
        if(n<1){
            return 0;
        } else {
            printf("%d = ", n);
        }
     
        while(div < n){
            div++;
            cont2++;
            if(div == 1){
                printf("%d ", div);
                soma += div;
            }
            if(n%div == 0 && div > 1 && n != div){
                printf("+ %d ", div);
                soma += div;
            }
            if(cont2 == n){
                printf("=");
            }
        }
        if(n>1){
            printf(" %d", soma);
        }
        if(n==1){
            printf(" %d", um);
        }
        if(n==soma && n != 1){
            printf(" (NUMERO PERFEITO)\n");
        } else {
            printf(" (NUMERO NAO E PERFEITO)\n");
        }
        return 0;
    }