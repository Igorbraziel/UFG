#include <stdio.h>
#define MAX 99

int main(){
    char matriz[MAX][MAX];
    char b, c;
    int impar;
    int i, i2, j = 0, n = 0, k = 0, v = 0;

    scanf("%d %c %c", &impar, &b, &c);

    if(impar % 2 == 0 || impar < 3 || impar > 99){
        printf("Dimensao invalida!\n");
        return 0;
    }

    n = impar / 2;
    k = 1;
    j = n - 1;
    for(i=0;i<impar;i++){
        for(i2=0;i2<impar;i2++){
            if(i==0){
                if(i2<n){
                    matriz[i][i2] = ' ';
                    printf("%c ", matriz[i][i2]);
                } else if(i2==n){
                    matriz[i][i2] = b;
                    printf("%c ", matriz[i][i2]);
                }
            } else if(i > 0 && i <= n){
                if(i2<n-k){
                    matriz[i][i2] = ' ';
                    printf("%c ", matriz[i][i2]);
                } else if(i2==n-k){
                    matriz[i][n-k] = b;
                    printf("%c ", matriz[i][n-k]);
                    v = n - k;
                    v++;
                    while(v < n + k){
                        matriz[i][v] = c;
                        printf("%c ", matriz[i][v]);
                        v++;
                    }
                    matriz[i][n+k] = b;
                    printf("%c ", matriz[i][n+k]);
                    k++;
                } 
            } else if(i > n && i < impar - 1 && j > 0){
                if(i2<n-j){
                    matriz[i][i2] = ' ';
                    printf("%c ", matriz[i][i2]);
                } else if(i2==n-j){
                    matriz[i][n-j] = b;
                    printf("%c ", matriz[i][n-j]);
                    v = n - j;
                    v++;
                    while(v < n + j){
                        matriz[i][v] = c;
                        printf("%c ", matriz[i][v]);
                        v++;
                    }
                    matriz[i][n+j] = b;
                    printf("%c ", matriz[i][n+j]);
                    j--;
                    break;
                }
            } else if(i == impar - 1){
                if(i2<n){
                    matriz[i][i2] = ' ';
                    printf("%c ", matriz[i][i2]);
                } else if(i2==n){
                    matriz[i][i2] = b;
                    printf("%c ", matriz[i][i2]);
                }
            } 
        }
        printf("\n");
    }
    
       
    return 0;
}