#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arq = NULL;
    int x = 1;

    arq = fopen("dados", "wb");

    if(arq == NULL){
        printf("ERRO\n");
        return 1;
    }

    while(x <= 100){
        fwrite(&x, sizeof(int), 1, arq);
        x++;
    }

    fclose(arq);

    return 0;
}