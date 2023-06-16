#include <stdio.h>
#include <math.h>

int main(){
    char numero[100000];
    int v1[100000], vn[100000];
    int n, d, i = 0, i2 = 0, t = 0, i3 = 0, t1 = 0, k = 0, i4 = 0;
    while(1){
        scanf("%d %d", &n, &d);
        if(n == 0 && d == 0){
            break;
        }
        scanf("%s", numero);
        while(numero[i] != '\0'){
            v1[i] = numero[i] - '0';
            i++;
        }
        i = 0;
        t = n - d;
        t1 = t;
        while(i < t){
            for(i2=i4;i2<n;i2++){
                for(i3=i2+1;i3<n;i3++){
                    if(v1[i2] <= v1[i3]){
                        k++;
                    }
                }
                if(k < t1){
                    vn[i] = v1[i2];
                        i4 = i2;
                        i++;
                        t1--;
                        break;
                }
                k = 0;
            }
        }
        i2 = 0;
        i3 = 0;
        k = 0;
        for(i4=0;i4<t;i4++){
            printf("%d", vn[i4]);
        }
        printf("\n");
        for(i4=0;i4<t;i4++){
            vn[i4] = 0;
        }
        for(i4=0;i4<n;i4++){
            v1[i4] = 0;
        }
        i4 = 0;
    }
    return 0;
}