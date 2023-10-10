#include <stdio.h>
#include <stdlib.h>

int BatalhaNaval(char **matriz, char NL, char NC, int l, int c, int *derrubados){
    if(matriz[l][c] == '#'){
         if(l == 0 && c == 0){
            if(matriz[l][c + 1] == 'a' && matriz[l + 1][c] == 'a'){
                (*derrubados) = (*derrubados) + 1;
            } else{
                matriz[l][c] = 'a';
            }
        } else if(l == 0 && c == NC - 1){
            if(matriz[l][c - 1] == 'a' && matriz[l + 1][c] == 'a'){
                (*derrubados) = (*derrubados) + 1;
            } else{
                matriz[l][c] = 'a';
            }
        } else if(l == NL - 1 && c == 0){
            if(matriz[l][c + 1] == 'a' && matriz[l - 1][c] == 'a'){
                (*derrubados) = (*derrubados) + 1;
            } else{
                matriz[l][c] = 'a';
            }
        } else if(l == NL - 1 && c == NC - 1){
            if(matriz[l][c - 1] == 'a' && matriz[l - 1][c] == 'a'){
                (*derrubados) = (*derrubados) + 1;
            } else{
                matriz[l][c] = 'a';
            }
        } else if(l == 0){
            if(matriz[l][c - 1] == 'a' && matriz[l][c + 1] == 'a' && matriz[l + 1][c] == 'a'){
                (*derrubados) = (*derrubados) + 1;
            } else{
                matriz[l][c] = 'a';
            }
        } else if(l == NL - 1){
            if(matriz[l][c - 1] == 'a' && matriz[l][c + 1] == 'a' && matriz[l - 1][c] == 'a'){
                (*derrubados) = (*derrubados) + 1;
            } else{
                matriz[l][c] = 'a';
            }
        } else if(c == 0){
            if(matriz[l + 1][c] == 'a' && matriz[l - 1][c] == 'a' && matriz[l][c + 1] == 'a'){
                (*derrubados) = (*derrubados) + 1;
            } else{
                matriz[l][c] = 'a';
            }
        } else if(c == NC - 1){
            if(matriz[l + 1][c] == 'a' && matriz[l - 1][c] == 'a' && matriz[l][c - 1] == 'a'){
                (*derrubados) = (*derrubados) + 1;
            } else{
                matriz[l][c] = 'a';
            }
        } else{
            if(matriz[l - 1][c] == 'a' && matriz[l + 1][c] == 'a' && matriz[l][c + 1] == 'a' && matriz[l][c - 1] == 'a'){
                (*derrubados) = (*derrubados) + 1;
            } else{
                matriz[l][c] = 'a';
            }
        }
    }
}

int main(){
    int numLinhas, numColunas, numDisparos;
    int i, j, l, c;
    int Navios_Derrubados = 0;
    char **matriz;
    char letra[1000];

    scanf("%d %d%*c", &numLinhas, &numColunas);

    matriz = (char **) malloc((numLinhas + 1) * sizeof(char *));

    for(i = 0; i < numLinhas; i ++){
        matriz[i] = (char *) malloc((numColunas + 1) * sizeof(char));
    }

    for(i = 0; i < numLinhas; i++){
        scanf("%s", letra);
        for(j = 0; letra[j] != '\0'; j++){
            matriz[i][j] = letra[j];
        }
    }

    scanf("%d", &numDisparos);

    for(i = 0; i < numDisparos; i++){
        scanf("%d %d", &l, &c);
        BatalhaNaval(matriz, numLinhas, numColunas, l - 1, c - 1, &Navios_Derrubados);
    }

    printf("%d\n", Navios_Derrubados);

    for(i = 0; i < numLinhas; i ++){
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}