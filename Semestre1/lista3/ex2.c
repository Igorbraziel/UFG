    #include <stdio.h>
     
    int main(){
        int v[1000], x, i, k, valor=0;
        while(1){
            scanf("%d", &x);
            if(x >= 1 && x <=1000){
                break;
            }
        }
            for(i=0;i<x;i++){
                scanf("%d", &v[i]);
            }
            scanf("%d", &k);
            for(i=0;i<x;i++){
                if(v[i] >= k){
                    valor += 1;
                }
            }
            printf("%d\n", valor);
        
        return 0;
    }