#include <stdio.h>

int main(){
    double matriz[2][2];
    int i, i2;
    double ida = 1, volta = 1, det = 0;

    for(i=0;i<2;i++){
        for(i2=0;i2<2;i2++){
            scanf("%lf", &matriz[i][i2]);
        }
    }

    for(i=0;i<2;i++){
        for(i2=0;i2<2;i2++){
            if(i==i2){
                ida *= matriz[i][i2];
            } else if (i != i2){
                volta *= matriz[i][i2];
            }
        }
    }
    
    det = ida - volta;
    printf("%.2lf\n", det);
    return 0;
}