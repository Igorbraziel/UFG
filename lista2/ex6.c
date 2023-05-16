#include <stdio.h>
     
int main(){
int n, n1, k, t, i;
        scanf("%d", &n);
        k = 1;
        for(i = 0; i < n; i++){
            scanf("%d", &n1);
            if( i >= 1 ){
                if(t < n1){
                k++;
            }
            }
            t = n1;
        }
     
        printf("O comprimento do segmento crescente maximo e: %d\n", k);
     
     
     
     
        return 0;
    }
