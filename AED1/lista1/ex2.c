#include <stdio.h>

void Fibonacci(int num, int f0, int f1, int f2, int k){
    if(num == 0){
        printf("%d\n", f0);
        return;
    } 
    if(num == 1){
        printf("%d %d\n", f0, f1);
        return;
    }
    if(k == num){
        printf("%d\n", f2);
        return;
    }
    printf("%d ", f2);
    Fibonacci(num, f1, f2, f1 + f2, k + 1);
}

int main(){
    int n;
    scanf("%d", &n);
    Fibonacci(n, 0, 1, 0, 0);
    return 0;
}