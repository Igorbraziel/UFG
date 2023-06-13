#include <stdio.h>

void palavra(char *p, char *p2, int x){
    int i1 = 0, i2 = 0;
    for(i1=0;i1<x;i1++){
        p2[i1] = p[i1];
    }
    p2[x] = '\0';
}

int main(){
    int qtd, i, n, i2 = 0, i3;
    char vs[499], vn[499];
    scanf("%d%*c", &qtd);
    for(i=0;i<qtd;i++){
        scanf("%d %[^\n]%*c", &n, vs);
        palavra(vs, vn, n);
        while(1){
            if(vn[i2] != '\0'){
                printf("%c", vn[i2]);
            }
            if(vn[i2] == '\0'){
                printf("\n");
                break;
            }
            i2++;
        }
        i2 = 0;
    }
    return 0;
}