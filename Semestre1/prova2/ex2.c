#include <stdio.h>
 
#define N 256+1
 
void str_clean(char *str, char *clr, char *nova){
    int i = 0, i2 = 0, k = 0, j = 0;
 
    while(str[i] != '\0'){
        while(clr[i2] != '\0'){
            if(str[i] == clr[i2]){
                k++;
            }
            i2++;
        }
        if(k == 0){
            nova[j] = str[i];
            j++;
        }
        k = 0;
        i2 = 0;
        i++;
    }
    nova[j] = '\0';
}
 
int main(){
    char str[N]; // string original
    char clr[N]; // lista de caracteres indesejados
    char nova[N];
 
    scanf("%[^\n]%*c", str);
    scanf("%[^\n]%*c", clr);
 
    str_clean(str, clr, nova);
    
    printf("%s\n", nova);
    return 0;
}