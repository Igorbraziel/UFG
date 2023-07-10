        #include <stdio.h>
         
        int main(){
            int n, n1, n2, i2, i1;
            double media1 = 0, media2 = 0;
            n1 = 0;
            n2 = 0;
            i1 = 0;
            i2 = 0;
            while(1){
                scanf("%d", &n);
                if(n == 0){
                    break;
                }
                if((n % 2) == 0){
                    i2++;
                    n2 += n;
                }
                else{
                    i1++;
                    n1 += n;
                }
            }
            if(i1 == 0){
                i1 = 1;
            }
            if(i2 == 0){
                i2 = 1;
            }
            media2 = (double)n2/i2;
            media1 = (double)n1/i1;
            
            printf("MEDIA PAR: %.6lf\n", media2);
            printf("MEDIA IMPAR: %.6lf\n", media1);
         
            return 0;
         
        }