#include <stdio.h>

int main(){
    int h, h2, c1, c2;
    scanf("%d", &h);
    if(h<=0){
        return 0;
    }
    for(h2=1;h2<=h;h2++){
        for(c1=1;c1<h2;c1++){
            for(c2=c1;c2<h2;c2++){
                if((c1*c1) + (c2*c2) == (h2*h2)){
                printf("hipotenusa = %d, catetos %d e %d\n", h2, c1, c2);
                }
            }
        }
    }
    return 0;
}