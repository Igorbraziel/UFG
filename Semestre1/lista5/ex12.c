#include <stdio.h>

struct racional{
    int num;
    int div;
};

typedef struct racional Racional;

int MMC(int x, int y){
    int mmc = 0, i;    
    if(x > y){
        i = x;
        while(1){
            if(i % x == 0 && i % y == 0){
                mmc = i;
                return mmc;
            }
            i++;
        }
    } else{
        i = y;
        while(1){
            if(i % x == 0 && i % y == 0){
                mmc = i;
                return mmc;
            }
            i++;
        }
    }
}

Racional somaR(Racional n1, Racional n2){
    Racional soma;
    int mmc;

    mmc = MMC(n1.div, n2.div);
    n1.num *= (mmc / n1.div);
    n2.num *= (mmc / n2.div);

    soma.num = n1.num + n2.num;
    soma.div = mmc;

    return soma;

}

Racional multR(Racional n1, Racional n2){
    Racional mult;

    mult.num = n1.num * n2.num;
    mult.div = n1.div * n2.div;

    return mult;
}

Racional divR(Racional n1, Racional n2){
    Racional divisao;

    divisao.num = n1.num * n2.div;
    divisao.div = n1.div * n2.num;

    return divisao;
}

Racional subR(Racional n1, Racional n2){
    Racional sub;
    int mmc;

    mmc = MMC(n1.div, n2.div);

    n1.num *= (mmc / n1.div);
    n2.num *= (mmc / n2.div);

    sub.num = n1.num - n2.num;
    sub.div = mmc;

    return sub;

}

void reduzFracao(Racional *n){
    int i;

    if(n->num > n->div){
        for(i = 2; i <= n->num; i++){
            if(n->num % i == 0 && n->div % i == 0){
                n->num = n->num / i;
                n->div = n->div / i;
                i = 1; 
            }
        }
    } else{
        for(i = 2; i <= n->div; i++){
            if(n->num % i == 0 && n->div % i == 0){
                n->num = n->num / i;
                n->div = n->div / i;
                i = 1; 
            }
        }
    }
}

int main(){
    Racional n1, n2, soma, mult, divisao, sub;
    int i;
    char c;

    while(scanf("%d %d %c %d %d", &n1.num, &n1.div, &c, &n2.num, &n2.div) != EOF){
        soma = somaR(n1, n2);

        mult = multR(n1, n2);

        divisao = divR(n1, n2);

        sub = subR(n1, n2);

        if(c == '+'){
            reduzFracao(&soma);
            printf("%d %d\n", soma.num, soma.div);
        } else if(c == '-'){
            reduzFracao(&sub);
            printf("%d %d\n", sub.num, sub.div);
        } else if(c == '*'){
            reduzFracao(&mult);
            printf("%d %d\n", mult.num, mult.div);
        } else if(c == '/'){
            reduzFracao(&divisao);
            printf("%d %d\n", divisao.num, divisao.div);
        }
    }


    return 0;
}