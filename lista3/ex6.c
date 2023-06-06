    #include <stdio.h>
     
    int main(){
        int qtd, i, i2 = 0, valor1 = 0, valor2 = 0, valor3 = 0;
        char p[5];
        scanf("%d", &qtd);
        for(i=0;i<qtd;i++){
            scanf("%s", p);
            if(p[3] == '\0'){
                    if(p[0] == 'o'){
                        valor1 += 1;
                    }
                    if(p[1] == 'n'){
                        valor1 += 1;
                    }
                    if(p[2] == 'e'){
                        valor1 += 1;
                    }
                    if(p[0] == 't'){
                        valor2 += 1;
                    }
                    if(p[1] == 'w'){
                        valor2 += 1;
                    }
                    if(p[2] == 'o'){
                        valor2 += 1;
                    }
            }
            if(valor1 >= 2){
                printf("1\n");
            }
            if(valor2 >= 2){
                printf("2\n");
            }
            if(p[5] == '\0'){
                    if(p[0] == 't'){
                        valor3 += 1;
                    }
                    if(p[1] == 'h'){
                        valor3 += 1;
                    }
                    if(p[2] == 'r'){
                        valor3 += 1;
                    }
                    if(p[3] == 'e'){
                        valor3 += 1;
                    }
                    if(p[4] == 'e'){
                        valor3 += 1;
                    }
            }
            if(valor3 >= 4){
                printf("3\n");
            }
            valor1 = 0;
            valor2 = 0;
            valor3 = 0;
        }
        return 0;
    }