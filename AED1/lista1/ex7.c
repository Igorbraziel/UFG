#include <stdio.h>

int BancoInteligente(int dinheiro, int n2, int n5, int n10, int n20, int n50, int n100, int qtd_trocos){
    int k2 = 0, k5 = 0, k10 = 0, k20 = 0, k50 = 0, k100 = 0;
    int dinheiroMovel = dinheiro;

    if(dinheiroMovel / 100 > 0){
        if(dinheiroMovel / 100 <= n100){
            k100 = dinheiroMovel / 100;
            dinheiroMovel -= k100 * 100;
        } else{
            k100 = n100;
            dinheiroMovel -= k100 * 100;
        }
    }

    if(dinheiroMovel / 50 > 0){
        if(dinheiroMovel / 50 <= n50){
            k50 = dinheiroMovel / 50;
            dinheiroMovel -= k50 * 50;
        } else{
            k50 = n50;
            dinheiroMovel -= k50 * 50;
        }
    }

    if(dinheiroMovel / 20 > 0){
        if(dinheiroMovel / 20 <= n20){
            k20 = dinheiroMovel / 20;
            dinheiroMovel -= k20 * 20;
        } else{
            k20 = n20;
            dinheiroMovel -= k20 * 20;
        }
    }

    if(dinheiroMovel / 10 > 0){
        if(dinheiroMovel / 10 <= n10){
            k10 = dinheiroMovel / 10;
            dinheiroMovel -= k10 * 10;
        } else{
            k10 = n10;
            dinheiroMovel -= k10 * 10;
        }
    }

    if(dinheiroMovel / 5 > 0){
        if(dinheiroMovel / 5 <= n5){
            k5 = dinheiroMovel / 5;
            dinheiroMovel -= k5 * 5;
        } else{
            k5 = n5;
            dinheiroMovel -= k5 * 5;
        }
    }

    if(dinheiroMovel / 2 > 0){
        if(dinheiroMovel / 2 <= n2){
            k2 = dinheiroMovel / 2;
            dinheiroMovel -= k2 * 2;
        } else{
            k2 = n2;
            dinheiroMovel -= k2 * 2;
        }
    }

    if(k100 * 100 + k50 * 50 + k20 * 20 + k10 * 10 + k5 * 5 + k2 * 2 < dinheiro) return qtd_trocos;
    
    if(k100 > 0){
        n100--;
    }
    
    if(k50 > 0){
        n50--;
    }
    
    if(k20 > 0){
        n20--;
    } 
    
    if(k10 > 0){
        n10--;
    } 
    
    if(k5 > 0){
        n5--;
    } 
    
    if(k2 > 0){
        n2--;
    }
    

    BancoInteligente(dinheiro, n2, n5, n10, n20, n50, n100, qtd_trocos + 1);
}

int main(){
    int saque;
    int n2, n5, n10, n20, n50, n100;
    int k = 0;

    scanf("%d", &saque);
    scanf("%d %d %d %d %d %d", &n2, &n5, &n10, &n20, &n50, &n100);

    printf("%d\n", BancoInteligente(saque, n2, n5, n10, n20, n50, n100, k));

    return 0;
}