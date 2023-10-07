#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arqbin = NULL;
    char c;

    arqbin = fopen("abc", "rb");

    if(arqbin == NULL) return 1;

    c = fgetc(arqbin);

    while(c != EOF){
        printf("Codigo: %d\n", c);
        printf("Simbolo: %c\n", c);
        c = fgetc(arqbin);
    }

    fclose(arqbin);

    return 0;
}