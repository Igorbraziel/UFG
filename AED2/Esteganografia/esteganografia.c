/*
MENSAGEM

M -> 77 -> 1001101                  ESTRUTURA DE DADOS
E -> 69 -> 1000101                  
S -> 78 -> 1010011                  E -> 1000101 -> 69 
N -> 83 -> 1010011                  S -> 1010011 -> 83
A -> 65 -> 1000001                  T -> 1010100 -> 84
G -> 71 -> 1000111                  .
E -> 69 -> 1000101                  .
M -> 77 -> 1001101                  .

pegue o primeiro bit do seu arquivo.png o primeiro bit é binario, vá no ultimo digito e o substitua pelo
primeiro digito binario do M, vá para o segundo bit da imagem, troque o ultimo digito novamente pelo
próximo digito binario do M, assim por diante, até percorrer a MENSAGEM e guardar seus digitos

*/
#include <stdio.h>
#define IMAGE_PATH "image.jpg"

int MyPow(int x, int exponent){
    if (exponent == 0){
        return 1;
    }
    return x * MyPow(x, exponent - 1);
}

int IntToBin(int number, int exponent){
    if(number == 0) return 0;
    return ((number % 2) * MyPow(10, exponent)) + IntToBin(number/2, exponent + 1);
}

int BinToInt(int number, int exponent){
    if(number == 0) return 0;
    return ((number % 10) * MyPow(2, exponent)) + BinToInt(number/10, exponent + 1);
}

int ChangeLastDigit(int number, int digit){
    if(digit == number % 10) return number;
    if(digit == 0) return number - 1;
    if(digit == 1) return number + 1;
}

void ChangeImageByte(FILE * file, int *index_to_insert, int digit){
    int value;

    fseek(file, *index_to_insert, SEEK_SET);
    value = fgetc(file);

    if(value == EOF) return;

    value = IntToBin(value, 0);
    value = ChangeLastDigit(value, digit);
    value = BinToInt(value, 0);

    fseek(file, *index_to_insert, SEEK_SET);
    fputc(value, file);

    (*index_to_insert) = (*index_to_insert) + 1;
}

int main(){
    FILE * file = NULL;
    int value, digit, i = 0;
    int exp = 0, sum = 0, result, j = 1;
    int index_byte = 0, index_str = 0;
    char message[100] = {"MESSAGE"};
    char read_message[100];

    // IN THE FIRST OPEN OF FILE, WE PUT THE SECRET MESSAGE IN THE IMAGE

    file = fopen(IMAGE_PATH, "r+");

    while(message[i] != '\0'){
        int value = message[i];
        value = IntToBin(value, 0);
        while(value > 0){
            digit = value % 10;
            ChangeImageByte(file, &index_byte, digit);
            value = value / 10;
        }
        i++;
    }

    printf("HIDE MESSAGE IN THE IMAGE: ( %s )\n", message);
    printf("----------------------------------------------\n");

    fclose(file);

    //--------------------------------------------------------------------------
    // IN THE SECOND OPEN OF FILE, WE READ THE IMAGE BYTES AND FOUND THE SECRET MESSAGE

    file = fopen(IMAGE_PATH, "r");

    i = 1;
    while (i <= index_byte){
        value = fgetc(file);
        if(value == EOF) break;
        value = IntToBin(value, 0);
        value = (value % 10) * MyPow(10, exp);
        sum += value;

        if(j == 7){
            result = BinToInt(sum, 0);
            read_message[index_str] = result;
            index_str++;
            j = 0;
            exp = -1;
            sum = 0;
        }
        exp++;
        i++;
        j++;
    }

    read_message[index_str] = '\0';

    printf("READ MESSAGE THAT WE FIND IN THE IMAGE: ( %s )\n", read_message);

    fclose(file);

    return 0;
}