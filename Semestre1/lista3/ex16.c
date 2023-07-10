    #include <stdio.h>
     
    int main(){
        int qtd, i, n, unico = 0, unico2 = 0, i2;
        int v[5000];
        scanf("%d", &qtd);
        for(i=0;i<qtd;i++){
            scanf("%d", &n);
            v[i] = n;
        }
        for(i=0;i<qtd;i++){
            for(i2=0;i2<qtd;i2++){
                if(v[i] != v[i2]){
                    unico++;
                }
            }
            if(unico == qtd - 1){
                unico2++;
            }
            unico = 0;
        }
        printf("%d\n", unico2);
        return 0;
    }