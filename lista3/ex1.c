    #include <stdio.h>
     
    int main(){
        int v[100000], qtd, b, i, n, i2;
        scanf("%d", &qtd);
        for(i=0;i<qtd;i++){
            scanf("%d", &v[i]);
        }
        scanf("%d", &b);
        for(i=0;i<b;i++){
            scanf("%d", &n);
            for(i2=0;i2<qtd;i2++){
                if(n==v[i2]){
                    printf("ACHEI\n");
                    break;
                }
            }
            if(i2==qtd){
                printf("NAO ACHEI\n");
            }
        }
        return 0;
    }