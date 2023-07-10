    #include <stdio.h>
     
    int main(){
        int qtd, alunos, i, n, k = 0, i2;
        int tempo[1000];
        scanf("%d %d", &qtd, &alunos);
        for(i=0;i<qtd;i++){
            scanf("%d", &n);
            tempo[i] = n;
            if(tempo[i] <= 0){
                k++;
            }
        }
        if(k >= alunos){
            printf("NAO\n");
            for(i2=i-1;i2>=0;i2--){
                if(tempo[i2] <= 0){
                    printf("%d\n", i2 + 1);
                }
            }
        } else{
            printf("SIM\n");
        }
     
        return 0;
    }