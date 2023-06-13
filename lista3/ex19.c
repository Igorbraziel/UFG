#include <stdio.h>

long int charParaint(const char *p){
    long int n = 0;
    int i = 0, peso = 1, cont = 0, valor = 0;
    while(p[cont] != '\0'){
        cont++;
    }
    i = cont - 1;
    if(p[0] == '-'){
        while(i >= 1){
            valor = (p[i] - '0');
            valor *= peso;
            n += valor;
            peso *= 10;
            i--;
        }
        return -n;
    } else if(p[0] != '-'){
        while(i >= 0){
            valor = (p[i] - '0');
            valor *= peso;
            n += valor;
            peso *= 10;
            i--;
        }
        return n;
    }
    
}

int main(){
    char str[128];
    long int x;
    while( scanf("%s", str) != EOF ){
         x = charParaint(str);
         printf("%ld %ld\n", x, 2*x);
    }
    return 0;
}