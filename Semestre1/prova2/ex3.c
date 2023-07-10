#include <stdio.h>
 
int main(){
    int matriz[1000][1000];
    int N_L, N_C;
    int i, j;
    int maior, menor;
    int Ima, Jma, Ime, Jme;
 
    scanf("%d %d", &N_L, &N_C);
 
    for(i=0;i<N_L;i++){
        for(j=0;j<N_C;j++){
            scanf("%d", &matriz[i][j]);
            if(i == 0 && j == 0){
                maior = matriz[i][j];
                menor = matriz[i][j];
            }
        }    
    }
 
    for(i=0;i<N_L;i++){
        for(j=0;j<N_C;j++){
            if(matriz[i][j] > maior) maior = matriz[i][j];
            if(matriz[i][j] < menor) menor = matriz[i][j];
        }    
    }
 
    for(i=0;i<N_L;i++){
        for(j=0;j<N_C;j++){
            if(matriz[i][j] == maior){
                Ima = i;
                Jma = j;
            }
            if(matriz[i][j] == menor){
                Ime = i;
                Jme = j;    
            }
        }    
    }
 
        matriz[Ima][Jma] = menor;
        matriz[Ime][Jme] = maior;
 
    for(i=0;i<N_L;i++){
        for(j=0;j<N_C;j++){
            printf("%d ", matriz[i][j]);
        }    
        printf("\n");
    }
 
    return 0;
}