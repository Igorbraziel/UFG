    #include <stdio.h>
     
    int main(){
        int qtd, i, k = 0, n;
        char v[1000];
        scanf("%d%*c", &qtd);
        for(i=0;i<qtd;i++){
            scanf("%[^\n]%*c", v); //"%[^\n]%*c"
            while(v[k] != '\0'){
                if(v[k] >= 'A' && v[k] <= 'Z'){
                    v[k] += 3;
                } else if(v[k] >= 'a' && v[k] <= 'z'){
                    v[k] += 3;
                }
                k++;
            }
            //k = 3
            //n = 1
            // 0 1 2
             if(k%2==0) n = k/2 - 1;
             if(k%2!=0) n = k/2;
            while(n >= 0){
                v[n] = v[n] - 1;
                n--;
            }
            while(k > 0){
                printf("%c", v[k - 1]);
                k--;
            }
            printf("\n");
        }
        return 0;
    }