#include <stdio.h>

int FatorialDuplo(int num, int k){
    if(k > num){
        return 1;
    } else if (k == num){
        return num;
    }
    return k * FatorialDuplo(num, k + 2);
}

int main(){
    int n;

    scanf("%d", &n);

    printf("%d\n", FatorialDuplo(n, 1));

    return 0;
}