#include <stdio.h>

int main(){
    int matriz[2][2];
    int i, i2, ida = 1, volta = 1, det = 0;

    for(i=0;i<2;i++){
        for(i2=0;i2<2;i2++){
            scanf("%d", &matriz[i][i2]);
            if(i==i2){
                ida *= matriz[i][i2];
            } else{
                volta *= matriz[i][i2];
            }
        }
    }
    
    det = ida - volta;
    printf("%d\n", det);
    return 0;
}