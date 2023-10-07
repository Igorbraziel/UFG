#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
    FILE *arq = NULL;
    int x = 0, y = 0, e = 0;
    int i;

    if(argv[1] == NULL || argv[2] == NULL || argc > 3){
        printf("A linha de comando deve seguir a seguinte sintaxe:\n");
        printf("./seq A B <ENTER>\n");
        return 0;
    }

    for(i = 0; argv[1][i] != '\0'; i++){

    }
    i--;

    for( ; i >= 0; i--){
        x += (argv[1][i] - '0') * pow(10, e);
        e++;
    }
    e = 0;

    for(i = 0; argv[2][i] != '\0'; i++){

    }
    i--;

    for( ; i >= 0; i--){
        y += (argv[2][i] - '0') * pow(10, e);
        e++;
    }

    if(x >= y){
        printf("(%d", x);
        x--;
        while(x >= y){
            printf(", %d", x);
            x--;
        }
        printf(")\n");
    } else{
        printf("(%d", x);
        x++;
        while(x <= y){
            printf(", %d", x);
            x++;
        }
        printf(")\n");
    }
    
    
    return 0;
}