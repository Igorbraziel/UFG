#include <stdio.h>

void crescente(int *p, int q, int qb){
    int i5 = 0, t = 0, ordem = 0, n = 0;
    n = q + qb;
    while(1){
        for(i5=0;i5<n-1;i5++){
            if(p[i5] > p[i5+1]){
                t = p[i5];
                p[i5] = p[i5+1];
                p[i5+1] = t;
            } else{
                ordem++;
            }
        }    
            if(ordem == n - 1){
                break;
            } else{
                ordem = 0;
            }
    }
}

int main(){
    int q1, q2, i, i2, i3, i4 = 0;
    int v1[50000], v2[50000], vr[50000];
    scanf("%d", &q1);
    scanf("%d", &q2);
    for(i=0;i<q1;i++){
        scanf("%d", &v1[i]);
    }
    for(i2=0;i2<q2;i2++){
        scanf("%d", &v2[i2]);
    }
    i = q1 -1;
    i2 = q2 - 1;
    for(i3=0;i3<q1+q2;i3++){
        if(i>=0){
            vr[i3] = v1[i];
            i--;
        } else if(i2>=0){
            vr[i3] = v2[i2];
            i2--;
        }
    }
    crescente(vr, q1, q2);
    for(i = 0; i < q1 + q2; i++){
        printf("%d\n", vr[i]);
    }
    return 0;
}