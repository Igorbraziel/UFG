#include <stdio.h>

struct familias{
    int pessoas[1000];
    int qtdPessoas;
};

typedef struct familias Familia;

void Troia(Familia *family, int *qtdFamilias, int person1, int person2){
    int i, j;

    if(*(qtdFamilias) < 50000){
        for(i = 0; i < *(qtdFamilias); i++){
            for(j = 0; j < family[i].qtdPessoas; j++){
                if(person1 == family[i].pessoas[j]){
                    family[i].pessoas[family[i].qtdPessoas] = person2;
                    family[i].qtdPessoas += 1;
                    return; 
                } else if(person2 == family[i].pessoas[j]){
                    family[i].pessoas[family[i].qtdPessoas] = person1;
                    family[i].qtdPessoas += 1;
                    return; 
                }
            }
        }

        family[*(qtdFamilias)].qtdPessoas = 2;
        family[*(qtdFamilias)].pessoas[0] = person1;
        family[*(qtdFamilias)].pessoas[1] = person2;
        *(qtdFamilias) = *(qtdFamilias) + 1;

        return;
    }
}

int main(){
    Familia family[1000];
    int qtdFamilias;
    int i, numPessoas, qtdLinhas;
    int person1, person2;

    scanf("%d %d", &numPessoas, &qtdLinhas);

    for(i = 0; i < qtdLinhas; i++){
        scanf("%d %d", &person1, &person2);
        if(i == 0){
            family[0].qtdPessoas = 2;
            family[0].pessoas[0] = person1;
            family[0].pessoas[1] = person2;
            qtdFamilias = 1;
        } else{
            Troia(family, &qtdFamilias, person1, person2);
        }
    }

    printf("%d\n", qtdFamilias);

    return 0;
}