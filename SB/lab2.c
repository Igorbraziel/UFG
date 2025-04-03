#include "stdio.h"

int is_upper(int c){
    if(65 <= c && c <= 90) return 1;
    
    return 0;
}

int is_lower(int c){
    if(97 <= c && c <= 122) return 1;
    
    return 0;
}


int string2num(char *s, int base){
    int a = 0;
    char decrement;

    for( ; *s ; s++){
        decrement = '0';

        if(is_lower(*s)){
            decrement = decrement + 39;
        }
        
        if(is_upper(*s)){
            decrement = decrement + 7;
        } 

        a = a * base + (*s - decrement);
    }

    return a;
}

int main(){

    printf("%d\n", string2num("1234", 10));
    printf("%d\n", string2num("1234", 10) + 1);
    printf("%d\n", string2num("1000", 2));

    printf("%d\n", string2num("1a", 16));
    printf("%d\n", string2num("AbC", 16));

    return 0;
}