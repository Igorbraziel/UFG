#include <stdio.h>

int main(){
    char str[51];
    int i, itotal;
    while( scanf("%[^\n]%*c", str) != EOF ){
        i = 0;
        itotal = 0;
        while(str[itotal] != '\0'){
            if(i%2 == 0 && str[itotal] != ' '){
                if(str[itotal] >= 'A' && str[itotal] <= 'Z'){
                    printf("%c", str[itotal]);
                    i++;
                    itotal++;
                } else if(str[itotal] >= 'a' && str[itotal] <= 'z'){
                    printf("%c", str[itotal] - 32);
                    i++;
                    itotal++;
                }
            } else if(i%2 != 0 && str[itotal] != ' '){
                if(str[itotal] >= 'A' && str[itotal] <= 'Z'){
                    printf("%c", str[itotal] + 32);
                    i++;
                    itotal++;
                } else if(str[itotal] >= 'a' && str[itotal] <= 'z'){
                    printf("%c", str[itotal]);
                    i++;
                    itotal++;
                }
            } else if(str[itotal] == ' '){
                printf(" ");
                itotal++;
            }
        }
        printf("\n");
    }
    return 0;
}