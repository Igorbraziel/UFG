    #include <stdio.h>
     
    int main(){
        int n, n1, div, mult=1, cont=0;
        while(1){
            scanf("%d", &n);
            if(n<=1){
                printf("Fatoracao nao e possivel para o numero %d!\n", n);
            } else{
                break;
            }
        }
        printf("%d = ", n);
        n1=n;
        for(div=1;div<=n1;div++){
            if(n1%div==0 && div>1){
                cont++;
                if(cont == 1){
                    printf("%d", div);
                } else{
                    printf(" x %d", div);
                }
                mult *= div;
                n1 /= div;
                div = 1;
     
            }
            if(mult == n){
                break;
            }
        }
        printf("\n");
        return 0;
    }