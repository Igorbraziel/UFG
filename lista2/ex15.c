#include <stdio.h>

int main(){
    int n, n1, n2=2, div1=1, div2=1, cont1=0, soma1 = 0, soma2 = 0, cont=0;
    scanf("%d", &n);
    if(n<1 || n>=9){
        return 0;
    }
        while(cont<n){
            for(n1=1;n1<n2;n1++){
                if(n1%div1 == 0 && n1 != div1){
                    soma1 += div1;
                }
                if(n2%div2 == 0 && n2 != div2){
                    soma2 += div2;
                }
                if(soma1 == n2 && soma2 == n1){
                    printf("(%d,%d)", n1, n2);
                }
                div1++;
                div2++;
            }   
            n1=220;
            n2++;
            cont++;
        }
    
    return 0;
}