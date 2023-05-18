#include <stdio.h>

int main(){
    int n, cont, imp = 1, n1;
    scanf("%d", &n);
    if(n<=0){
        return 0;
    }
    for(cont=1;cont<=n;cont++){
        
        if((n*n*n) == cont){
            printf("%d*%d*%d = \n", n, n, n);
        }
    }

    return 0;
}