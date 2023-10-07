#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arq = NULL;
    int x = 1629495328;

    arq = fopen("abc", "wb");

    if(arq == NULL){
        printf("ERRO\n");
        return 1;
    }

    while(x <= 1629495330){
        fwrite(&x, sizeof(int), 1, arq);
        x++;
    }

    fclose(arq);

    return 0;
}