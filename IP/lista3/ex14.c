#include <stdio.h>
#define N 128+1
int le_string( char * str, int n ){
    int i = 0, k = 0;
    while(str[i] != '\0' && str[i] != '\r'){
        k++;
    }
    return k;
}
void print_codes( char * str ){
    int i = 0, k = 0;
    while(str[i] != '\0' && str[i] != '\r'){
        printf("%d", str[i]);
    }
}
int main() {
char str[N], s[N];
char c;
int i;

    scanf("%c", &c);
    le_string(str, 3);
    print_codes(str);
    printf("caracter:%c, str:%s\n", c, str);
    scanf("%c", &c);
    le_string(str, 5);
    print_codes(str);
    printf("caracter:%c, str:%s\n", c, str);
    scanf("%c", &c);
    le_string(str, 5);
    print_codes(str);
    printf("caracter:%c, str:%s\n", c, str);
    scanf("%d", &i);
    le_string(str, 3);
    print_codes(str);
    printf("inteiro:%d, str:%s\n", i, str);
    //printf("Digite inteiros separados por espaco: ");
    scanf("%d", &i);
    //printf("inteiro:%d\n", i);
    //printf("Le string (15):\n");
    le_string(str, 15);
    print_codes(str);
    printf("inteiro:%d, str:%s\n", i, str);
    //printf("Digite uma string sem espacos: ");
    scanf("%s", s);
    //printf("string:%s\n", str);
    //printf("Le string (10):\n");
    le_string(str, 100);
    print_codes(str);
    printf("string:%s, str:%s\n", s, str);
    //printf("Digite uma string com espacos: ");
    scanf("%s", s);
    //printf("string:%s\n", str);
    //printf("Le string (20):\n");
    le_string(str, 100);
    print_codes(str);
    printf("string:%s, str:%s\n", s, str);
    return 0;
}