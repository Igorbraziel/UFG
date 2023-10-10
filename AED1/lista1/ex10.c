#include <stdio.h>
#include <stdlib.h>

int tabuleiro(char matriz[][1000], int ordem, int i, int j, int seguros){
    if(i >= ordem) return seguros;

    int novo_seguros = seguros;

    if(i == 0 && j == 0){
        if(matriz[i][j] != 'A' && matriz[i][j] != '<') novo_seguros++;
    } else if(i == ordem - 1 && j == 0){
        if(matriz[i][j] != 'V' && matriz[i][j] != '<') novo_seguros++;
    } else if(i == 0 && j == ordem - 1){
        if(matriz[i][j] != 'A' && matriz[i][j] != '>') novo_seguros++;
    } else if(i == ordem - 1 && j == ordem - 1){
        if(matriz[i][j] != 'V' && matriz[i][j] != '>') novo_seguros++; 
    } else if(i == 0){
        if(matriz[i][j] != 'A') novo_seguros++;
    } else if(i == ordem - 1){
        if(matriz[i][j] != 'V') novo_seguros++;
    } else if(j == 0){
        if(matriz[i][j] != '<') novo_seguros++;
    } else if(j == ordem - 1){
        if(matriz[i][j] != '>') novo_seguros++;
    } else{
        novo_seguros++;
    }

    if(j == ordem - 1){
        return tabuleiro(matriz, ordem, i + 1, 0, novo_seguros);
    } else{
        return tabuleiro(matriz, ordem, i, j + 1, novo_seguros);
    }
}

int main(){
    int ordem, i, j;
    char matriz[1000][1000];
    char lixo;

    scanf("%d%*c", &ordem);
    
    for(i = 0; i < ordem; i++){
        for(j = 0; j < ordem; j++){
            scanf("%c%c", &matriz[i][j], &lixo);
        }
    }

    printf("%d\n", tabuleiro(matriz, ordem, 0, 0, 0));

    return 0;
}