    #include <stdio.h>
     
    int main(){
        int quantidade, n1, ti, tf, anterior, cont;
        scanf("%d", &quantidade);
        scanf("%d", &n1);
        ti = 1;
        tf = 1;
        for(cont = 2; cont <= quantidade; cont++){
                anterior = n1;
                scanf("%d", &n1);
                if(n1 > anterior){
                ti++;
            } else {
                ti = 1;
            }
                if(ti > tf){
                tf = ti;
            }
        }
            printf("O comprimento do segmento crescente maximo e: %d\n", tf);
        
            return 0;
    }
