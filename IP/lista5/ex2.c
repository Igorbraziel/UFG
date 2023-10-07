#include <stdio.h>
#include <string.h>
 
struct mercado{
    char prod[1000][50];
    float prec[1000];
};
 
typedef struct mercado Mercado;
 
void le_matriz(Mercado *comp, int tm){
    int i;
    for(i=0;i<tm;i++){
        scanf("%s", (*comp).prod[i]);
        scanf("%f", &(*comp).prec[i]);
    }
}
 
float le_compras(Mercado comp, int t, int tm){
    char str[50];
    int qtd, i, j, k, c = 0;
    float soma = 0;
 
    for(k=0;k<t;k++){
        scanf("%s %d", str, &qtd);
        for(i=0;i<tm;i++){
            for(j=0;comp.prod[i][j] != '\0';j++){
                if(str[j] != comp.prod[i][j]){
                    c++;
                }
            }
            if(c==0){
                soma += (comp.prec[i] * qtd);
            }
            c = 0;
        }
    }
    return soma;
}
 
int main(){
    Mercado comp;
    int t, i, tm, tv;
    float pf = 0;
 
    scanf("%d", &t);
 
    for(i=0;i<t;i++){
        scanf("%d", &tm);
        le_matriz(&comp, tm);
        scanf("%d", &tv);
        pf = le_compras(comp, tv, tm);
        printf("R$ %.2f\n", pf);
        memset(&comp, 0, sizeof(Mercado));
        pf = 0;
    }
    
 
    return 0;
}