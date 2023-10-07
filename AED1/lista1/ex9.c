#include <stdio.h>

void hanoi(char origem, char destino, char auxiliar, int numDisc){
    if(numDisc == 1){
        printf("(%c,%c)\n", origem, destino);
        return;
    }
    hanoi(origem, auxiliar, destino, numDisc - 1);
    printf("(%c,%c)\n", origem, destino);
    hanoi(auxiliar, destino, origem, numDisc - 1);
}

int main(){
    int n;

    scanf("%d", &n);

    hanoi('O', 'D', 'A', n);

    return 0;
}