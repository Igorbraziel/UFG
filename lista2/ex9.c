    #include <stdio.h>
     
    int main(){
        double n, r0 = 1, r1 = 0, r2, e, e1;
     
        scanf("%lf", &n);
        scanf("%lf", &e);
        e1 = n - (r1*r1);
        while(e1 > e){
            r1 = (r0 + (n/r0))/2;
            r0 = r1;
            e1 = n - (r1*r1);
            if(e1 < 0){
                e1 = -e1; 
                 }
            printf("r: %.9lf, err: %.9lf\n", r1, e1);
        }
     
        return 0;
    }