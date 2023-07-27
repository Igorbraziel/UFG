#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fracao{
    int *num;
    int *den;
};

typedef struct fracao Fracao;

int main(){
    int qtd, i, x, y, n = 0, k = 0, k1 = 0, indice = 0, i2 = 0;
    int *pn = NULL, *pd = NULL;
    char c = '0';
    Fracao n1;

    scanf("%d", &qtd);

    for(i = 1; i <= qtd; i++){

        while(c != '\n'){
            scanf("%d/%d%c", &x, &y, &c);
            if(i2 == 0){
                n1.num = (int *) malloc((i2 + 1) * sizeof(int));
                n1.den = (int *) malloc((i2 + 1) * sizeof(int));
            } else{
                pn = (int *) realloc(n1.num, (i2 + 1) * sizeof(int));
                pd = (int *) realloc(n1.den, (i2 + 1) * sizeof(int));
                n1.num = pn;
                n1.den = pd;
            }
            n1.num[i2] = x;
            n1.den[i2] = y;
            i2++;
        }

        c = '0';

        printf("Caso de teste %d\n", i);

        for(n=0;n<i2+1;n++){
            for(k1=n;k1<i2+1;k1++){
                if(k1 != n && (float) (n1.num[n]) / (n1.den[n]) == (float) (n1.num[k1]) / (n1.den[k1])){
                    printf("%d/%d equivalente a %d/%d\n", n1.num[n], n1.den[n], n1.num[k1], n1.den[k1]);
                    indice++;
                }
            }
        }

        free(n1.num);
        free(n1.den);

        if(indice == 0){
            printf("Nao ha fracoes equivalentes na sequencia\n");
        }
        indice = 0;
        i2 = 0;
    }

    return 0;
}