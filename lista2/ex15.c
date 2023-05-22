#include <stdio.h>

int main(){
    int n, n1, n2=284, div1=1, div2=1, cont1=0, soma1 = 0, soma2 = 0;
    scanf("%d", &n);
    if(n<1 || n>=9){
        return 0;
    }
        while(1){
            for(n1=220;n1<n2;n1++){
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
            n2++;
        }
    
    return 0;
}