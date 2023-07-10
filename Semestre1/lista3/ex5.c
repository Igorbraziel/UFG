#include <stdio.h>

int main(){
    int qtd, i, k, cons = 0, vog = 0, letras = 0;
    char p[10001];
    scanf("%d%*c", &qtd);
    for(i=0;i<qtd;i++){
        scanf("%[^\n]%*c", p); //"%[^\n]%*c", txt
        k = 0;
        while(p[k] != '\0'){
            if(p[k] >= 'a' && p[k] <= 'z'){
                letras += 1;
            } else if(p[k] >= 'A' && p[k] <= 'Z'){
                letras += 1;
            }
            if(p[k] == 'a' || p[k] == 'e' || p[k] == 'i' || p[k] == 'o' || p[k] == 'u'){
                vog += 1;
            } else if(p[k] == 'A' || p[k] == 'E' || p[k] == 'I' || p[k] == 'O' || p[k] == 'U'){
                vog += 1;
            } else if(p[k] != 'a' && p[k] != 'e' && p[k] != 'i' && p[k] != 'o' && p[k] != 'u' && p[k] > 'a' && p[k] <= 'z'){
                cons += 1;
            } else if(p[k] != 'A' && p[k] != 'E' && p[k] != 'I' && p[k] != 'O' && p[k] != 'U' && p[k] > 'A' && p[k] <= 'Z'){
                cons += 1;
            }
            k++;
        }
        printf("Letras = %d\n", letras);
        printf("Vogais = %d\n", vog);
        printf("Consoantes = %d\n", cons);
        letras = 0;
        vog = 0;
        cons = 0; 
    }
    return 0;
}