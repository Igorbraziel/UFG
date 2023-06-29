#include <stdio.h>

int Permutacao(int matriz[500][500], int n, int *soma ){
    int i, i2, indice = 1;
    int k0 = 0, k1 = 0;

    for(i=0;i<n;i++){
        for(i2=0;i2<n;i2++){
            *soma = (*soma) + matriz[i][i2]; 
            if(matriz[i][i2] == 1) k1++;
            if(matriz[i][i2] == 0) k0++;
        }
        if(k1 != 1 || k0 != n -1) indice = 0;
        k1 = 0;
        k0 = 0;
    }
    for(i=0;i<n;i++){
        for(i2=0;i2<n;i2++){
            if(matriz[i2][i] == 1) k1++;
            if(matriz[i2][i] == 0) k0++;
        }
        if(k1 != 1 || k0 != n -1) indice = 0;
        k1 = 0;
        k0 = 0;
    }
    return indice;
}

int main(){
    int A[500][500];
    int n, i, i2, x;
    int soma = 0;

    scanf("%d", &n);

    for(i=0;i<n;i++){
        for(i2=0;i2<n;i2++){
            scanf("%d", &A[i][i2]);
        }
    }

    x = Permutacao(A, n, &soma);
    printf("%d\n", n);

    if(x==1) printf("PERMUTACAO\n");
    if(x==0) printf("NAO EH PERMUTACAO\n");

    printf("%d\n", soma);

    return 0;
}