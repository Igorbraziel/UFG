#include <stdio.h>
#define N 24

void comparacao(char *paises, char *str, int *indice){
    int i = 0, x = 0, k = 0;
    while(str[i] != '\0'){
        i++;
    }
    x = i;
    i = 0;
    while(str[i] != '\0'){
        if(str[i] == paises[i]){
            k++;
        }
        i++;
    }
    if(k==x) *indice = 1;
}

int main(){
    char paises[N][100] = {"brasil", "alemanha", "austria", "coreia", "espanha", "grecia", "estados-unidos",
        "inglaterra", "australia", "portugal", "suecia", "turquia", "argentina", "chile", "mexico", "antardida",
        "canada", "irlanda", "belgica", "italia", "libia", "siria", "marrocos", "japao"};
    char frases[N][100] = {"Feliz Natal!", "Frohliche Weihnachten!", "Frohe Weihnacht!", "Chuk Sung Tan!",
        "Feliz Navidad!", "Kala Christougena!", "Merry Christmas!", "Merry Christmas!", "Merry Christmas!", "Feliz Natal!",
        "God Jul!", "Mutlu Noeller", "Feliz Navidad!", "Feliz Navidad!", "Feliz Navidad!", "Merry Christmas!",
        "Merry Christmas!", "Nollaig Shona Dhuit!", "Zalig Kerstfeest!", "Buon Natale!", "Buon Natale!", "Milad Mubarak!",
        "Milad Mubarak!", "Merii Kurisumasu!"};
    char str[100];
    int indice = -1, i = 0;

    while(scanf("%s", str) != EOF){
        for(i=0;i<N;i++){
            comparacao(paises[i], str, &indice);
            if(indice != -1){
                indice = i;
                break;
            }
        }
        if(indice == -1){
            printf("-- NOT FOUND --\n");
        } else{
            printf("%s\n", frases[indice]);
        }
        indice = -1;
    }

    return 0;
}