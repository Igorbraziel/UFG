#include <stdio.h>

void espelho(char *p1, int *p2, int i){
    int i2 = 0;
    while(i>=0){
        p1[i2] = p2[i];
        i--;
        i2++;
    }
    p1[i2] = '\0';
}

int main(){
    int qtd, i, i2 = 0, i3, n1, n2, t = 0, t1 = 0;
    int v[12221], v2[12221];
    char vs[12221];
    scanf("%d", &qtd);
    for(i=0;i<qtd;i++){
        scanf("%d %d", &n1, &n2);
        while(n1<=n2){
            v[i2] = n1;
            i2++;
            n1++;
        }
        i2--;
        for(i3=0;i3<=i2;i3++){
            printf("%d", v[i3]);
        }
        for(i3=i2;i3>=0;i3--){
            t = v[i3];
            if(t>=0 && t<=9){
                printf("%d", t);
            } else{
                while(t > 0){
                    t1 = t%10;
                    printf("%d", t1);
                    t = t/10;
                }
            }
        }
        printf("\n");
        i2 = 0;
    }
    return 0;
}