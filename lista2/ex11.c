#include <stdio.h>

int main(){
    int tt, a, b, cont, c1, d1, u1, u2, d2, c2;
    int a2;
    int b2;
    scanf("%d", &tt);
    for(cont=0;cont<tt;cont++){
        scanf("%d %d", &a, &b);
        if(a < 100 || a > 999 || b < 100 || b > 999 || a == b || a%10 == 0 || a%100 < 10 || b%10 == 0 || b%100 < 10){
            return 0;
        }
        u1 = a%10;
        d1 = (a%100) - u1;
        c1 = (a%1000) - (u1+d1);
        u1 *= 100;
        c1 /= 100;
        a2 = u1 + c1 + d1;

        u2 = b%10;
        d2 = (b%100) - u2;
        c2 = (b%1000) - (u2+d2);
        u2 *= 100;
        c2 /= 100;
        b2 = u2 + c2 + d2;
        
        if(a2 > b2){
            printf("%d\n", a2);
        }
        if(b2 > a2){
            printf("%d\n", b2);
        }

    }
    return 0;
}