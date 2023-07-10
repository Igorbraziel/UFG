#include <stdio.h>

double felev(double exp, int n){
    int cont;
    double x;
    x = exp;
    for(cont=1;cont<n;cont++){
        exp = exp * x;
    }
    return exp;
}

int main(){
    double exp, elev, soma, valor;
    int n, fat, cont;
    scanf("%lf", &exp);
    scanf("%d", &n);
    if(n<0 || n>9){
        return 0;
    }
    for(n=n;n>0;n--){
        fat=1;
        for(cont=n;cont>0;cont--){
            fat *= cont;
        }
        elev = felev((double) exp, (int) n);
        valor = elev/fat;
        soma += valor;
    }
    soma += 1;
    printf("e^%.2lf = %.6lf\n", exp, soma);

    return 0;
}