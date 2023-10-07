    #include <stdio.h>
    #include <math.h>
    long int bindec(long int b){
        int valor = 0, x = 10, exp = 0, soma = 0;
        int cont = 1;
        if(b<0){
             b = -b;
    }
        while(b > 0){
            if(b%10==0){
            valor = 0;
            b = b/10;
    } else if (b%10 != 0){
            valor = 1;
            b = b/10;
    }
            soma = soma + (valor * (pow(2, exp)));
            exp ++;
    }
        return soma;
    }
    int main(){
        long int n, n1;
        scanf("%ld", &n);
        n1 = bindec(n);
        if(n<0){
            printf("-%ld\n", n1);
    } else if(n>=0){
            printf("%ld\n", n1);
    }
        
        return 0;
     
    }