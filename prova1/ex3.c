    #include <stdio.h>
    int ffat(int f){
        int i;
        i=1;
        if(f<0){
            f = -f;
    }
        while(f>0){
        i *= f;
        f--;
    }
        return i;
     
     
     
     
    }
    int main(){
        int n, p, c=0, x, y, z, cont1=0, cont=0;
        scanf("%d %d", &n, &p);
        while(n<=p){
        while(cont<=n){
            x = ffat(n);
            y = ffat(cont);
            z = ffat(n-cont);
            c = (x)/(y*z);
            if(cont1==0){
                printf("%d", c);
            } else{
                printf(",%d", c);
        
    }
            cont++;
            cont1++;
    }
        cont1 = 0;
        cont = 0;
        n++;
        printf("\n");
     
    }
        return 0;
    }