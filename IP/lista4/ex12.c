#include <stdio.h>

#define L_MAX 1000
#define C_MAX 1000

void andador(char *str, int *i){
    int indice = 0, k = 0;
    (*i)++;
    while(1){
        if(str[(*i)] == '\0') break;
        if(str[(*i)] >= 'a' && str[(*i)] <= 'z') break;
        if(str[(*i)] >= 'A' && str[(*i)] <= 'Z') break;
        (*i)++;
    }
}

int str_split(char * str, char m[][C_MAX], char * sep){
    int i, i2, indice = 0, l = 0, c = 0;

    for(i=0;str[i] != '\0';i++){
        for(i2=0;sep[i2] != '\0';i2++){
            if(str[i] == sep[i2]) indice = 1;
        }
        if(str[i+1] == '\0'){
            if(indice == 1){
                m[l][c] = '\0';
                l++;
                break;
            } else{
                m[l][c] = str[i];
                m[l][c+1] = '\0';
                l++;
                break;
            }
        }
        if(indice == 1 && str[i+1] != '\0'){
            m[l][c] = '\0';
            l++;
            andador(str, &i);
            indice = 0;
            c = 0;
        }
        if(indice == 0 && str[i] != '\0' && str[i+1] != '\0'){
            m[l][c] = str[i];
            m[l][c+1] = '\0';
            c++;
        }
    }

    return l;
}

int main(){
    char matriz[L_MAX][C_MAX];
    char separador[C_MAX];
    char frase[C_MAX];
    int qtd, i, j = 0, maior = 0, k = 0;

    scanf("%[^\n]%*c", frase);
    scanf("%[^\n]%*c", separador);

    qtd = str_split(frase, matriz, separador);

    if(qtd == 0) return 0;
    for(i=0;i<qtd;i++){
        while(matriz[i][j] != '\0'){
            j++;
        }
        if(maior < j) maior = j;
        if(j > 0)printf("(%d)%s\n", j, matriz[i]);
        j = 0;
    }

    for(i=0;i<qtd;i++){
        while(matriz[i][j] != '\0'){
            j++;
        }
        if(j == maior){
            k++;
        }
        j = 0;
    }

    printf("%d\n", k);

    return 0;
}