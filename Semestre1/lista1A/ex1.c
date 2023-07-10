    #include <stdio.h>
    int main(){
        int n1, n2, n3;
        int numero;
        int quadrado;
        
        scanf("%d", &n1);
        scanf("%d", &n2);
        scanf("%d", &n3);
        
        if(n1 >= 10 || n2 >= 10 || n3 >= 10){
            printf("DIGITO INVALIDO\n");
            return 0;
        }
        
        numero = n1 * 100 + n2 * 10 + n3;
        quadrado = numero * numero;
        
        printf("%d, %d\n", numero, quadrado);
        
        
        
        
        return 0;
    }