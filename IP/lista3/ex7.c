    #include <stdio.h>
     
    int main(){
        int v[10000], i2 = 0, i = 0, x, y, i3 = 0, max = 0, valor = 0, i4 = 0;
        while(1){
            scanf("%d", &x);
            if(x==0) break;
            while(i<x){
                scanf("%d", &y);
                v[i] = y;
                if(v[i] >= max){
                    max = v[i];
                }
                i++;
            }
            while(i2<=max){
                while(i3 < x){
                    if(v[i3] <= i2){
                        valor += 1;
                    }
                    i3++;
                }
                printf("(%d) %d\n", i2, valor);
                i2++;
                i3 = 0;
                valor = 0;
            }
            i = 0;
            max = 0;
            i2 = 0;
            i3 = 0;
        }
        return 0;
    }