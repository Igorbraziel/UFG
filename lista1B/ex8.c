    #include <stdio.h>
     
    int main(){
        int n, f, cont, cont2, cont3, f2, t;
        scanf("%d", &n);
        t = n;
        cont = 0;
        f2 = 1;
        if( n < 2 ){
            printf("Campeonato invalido!\n");
        }
        
        /*while( cont < (n-1) ){
            f = f + (t-1);
            t--;
            cont++;
        }*/
        
        for( cont2 = 1; cont2 < n; cont2++ ){
            for( cont3 = cont2 + 1; cont3 <=n; cont3++ ){
                printf("Final %d: Time%d X Time%d\n", f2, cont2, cont3);
                    f2++;
            }
            
        }
        
        
        
        
        
        
        
        
        
        
        
        return 0;
    }