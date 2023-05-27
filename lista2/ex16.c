    #include <stdio.h>
    #include <math.h>
     
    int main(){
        double x, valor=0, nume, first, second;
        int n, n1, n2, fat = 1, umneg = -1;
        scanf("%lf", &x);
        scanf("%d", &n);
        if(n>9 || n < 1){
            return 0;
        }
        while(n>0){
            for(n1=2*n;n1>0;n1--){
                fat *= n1;
            }
            n2 = n*2;
            first = pow((double) umneg, (double) n);
            second = pow((double) x, (double) n2);
            nume = first * second;
            valor = valor + (nume/fat);
            n--;
            fat = 1;
        }
        valor += 1;
        printf("cos(%.2lf) = %.6lf\n", x, valor);
        return 0;
    }