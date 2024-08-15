// exibir quantos passos e o tempo gasto para fazer o hash
// ler o arquivo com 3000 números aleatórios para fazer o hash
/*
Seu trabalho deverá ler o arquivo fornecido "numeros_aleatorios.txt", 
e criar uma função hash para armazenamento das chaves em um vetor com no máximo 2000 posições.
O trabalho deverá também carregar um arquivo fornecido pelo executor chamado "checkin.txt" com 
a mesma estrutura do arquivo "numeros_aleatorios.txt".
Seu programa deverá buscar cada uma das chaves do arquivo "checkin.txt" na relação de 
chaves organizadas a partir do arquivo arquivo "numeros_aleatorios.txt".

Apresentar em tela as seguintes informações:
- Quantidade de passos necessários para encontrar a chave
- Quantidade de colisões identificadas
- Tempo necessário para encontrar
*/

/*
Ideias:
Encadeamento separado --> Ideia Utilizada
Duplo Hashing --> Ideia Utilizada
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBERS_PATH "numeros_aleatorios.txt" // OS ARQUIVOS PRECISAM ESTAR NA MESMA PASTA 
#define CHECKIN_PATH "checkin.txt" // OS ARQUIVOS PRECISAM ESTAR NA MESMA PASTA
#define MAX_TABLE_LENGTH 2000

#define CLEAN_COLORS "\033[m"
/*****************************COLORS***************************************/
#define C_BLACK     "\033[1;30m"
#define C_RED       "\033[1;31m"
#define C_GREEN     "\033[1;32m"
#define C_YELLOW    "\033[1;33m"
#define C_BLUE      "\033[1;34m"
#define C_MAGENTA   "\033[1;35m"
#define C_CYAN      "\033[1;36m"
#define C_GRAY      "\033[1;37m"
/**************************************************************************/

/***************************BACKGROUNDS************************************/
#define BG_BLACK    "\033[40m"
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_CYAN     "\033[46m"
#define BG_GRAY     "\033[47m"
/**************************************************************************/

struct table_value {
    int value;
    int current_index;
};

typedef struct table_value Table_value;

struct hash_table {
    Table_value value;
    Table_value vector[50];
};

typedef struct hash_table Hash_table;

int HashFunction(int value){
    int key;
    key = ((67 * value) + 1) % MAX_TABLE_LENGTH;
    return key;
}

int HashInVector(int value){
    int key;
    key = ((191 * value) + 6) % 50;
    return key;
}

int MyPow(int number, int exponent){
    if(exponent == 0) {
        return 1;
    }
    return number * MyPow(number, exponent - 1);
}

int LENGTH(char * str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

void HashTableInitialization(Hash_table * ht){
    int i, j;
    for(i = 0; i < MAX_TABLE_LENGTH; i++){
        ht[i].value.value = -1;
        ht[i].value.current_index = -1;
        for(j = 0; j < 50; j++){
            ht[i].vector[j].value = -1;
            ht[i].vector[j].current_index = -1;
        }
    }
}

int StringToInt(char * str, int str_length) {
    int i, current_length = str_length - 1;
    int number = 0;
    for(i = 0; i < str_length; i++){
        number += (str[i] - '0') * MyPow(10, current_length);
        current_length--;
    }
    return number;
}

int main(){
    Hash_table hash_table[MAX_TABLE_LENGTH];
    int c, value, key, index, counter;
    int str_length;
    int i = 0, j;
    int steps = 0, total_steps = 0, collisions = 0, total_collisions = 0;
    char number_string[100];
    FILE * random_numbers_file = NULL;
    FILE * checkin_file = NULL;
    clock_t start, end;

    random_numbers_file = fopen(NUMBERS_PATH, "r");

    if(random_numbers_file == NULL) {
        printf("ERRO NA ABERTURA DO ARQUIVO, OLHE SE O CAMINHO DO ARQUIVO ESTÁ CORRETO\n");
        return 1;
    }

    HashTableInitialization(hash_table);

    while((c = fgetc(random_numbers_file)) != EOF) {
        if('0' <= c && c <= '9') {
            number_string[i] = c;
            i++;
        } else {
            number_string[i] = '\0';
            str_length = i;
            i = 0;
            value = StringToInt(number_string, str_length);
            key = HashFunction(value);
            if(hash_table[key].value.value == -1) {
                hash_table[key].value.value = value;
            } else {
                if(hash_table[key].value.value != value) {
                    index = HashInVector(value);
                    if(hash_table[key].vector[index].value == -1){
                        hash_table[key].vector[index].value = value;
                        hash_table[key].vector[index].current_index = index;
                    } else {
                        counter = 0;
                        while(1){
                            index++;
                            counter++;
                            if(counter > 50) {
                                printf("FALHA NA INSERÇÃO DE VALORES NA TABELA\n");
                                return 1;
                            }
                            if(index > 49) {
                                index = 0;
                            }
                            if(hash_table[key].vector[index].value == -1){
                                hash_table[key].vector[index].value = value;
                                hash_table[key].vector[index].current_index = index;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    fclose(random_numbers_file);

    i = 0;

    checkin_file = fopen(CHECKIN_PATH, "r");

    if(checkin_file == NULL) {
        printf("ERRO NA ABERTURA DO ARQUIVO, OLHE SE O CAMINHO DO ARQUIVO ESTÁ CORRETO\n");
        return 1;
    }

    start = clock();

    while((c = fgetc(checkin_file)) != EOF) {
        if('0' <= c && c <= '9') {
            number_string[i] = c;
            i++;
        } else {
            steps = 0;
            collisions = 0;
            number_string[i] = '\0';
            str_length = i;
            i = 0;
            value = StringToInt(number_string, str_length);
            key = HashFunction(value);
            steps++;
            if(hash_table[key].value.value == value) {
                printf("Valor encontrado: (%d) Chave do valor: (%d)\n", hash_table[key].value.value, key);
            } else {
                steps++;
                collisions++;
                index = HashInVector(value);
                if(hash_table[key].vector[index].value == value) {
                    printf("Valor (%d) encontrado na chave (%d), no índice (%d) do vetor\n", hash_table[key].vector[index].value, key, hash_table[key].vector[index].current_index);
                } else {
                    steps++;
                    collisions++;
                    counter = 0;
                    while(1){
                        index++;
                        counter++;
                        if(counter > 50) {
                            printf("Valor (%d) não encontrado na tabela hash\n", value);
                            collisions = 0;
                            steps = 0;
                            break;
                        }
                        if(index > 49) {
                            index = 0;
                        }
                        if(hash_table[key].vector[index].value == value){
                            printf("Valor (%d) encontrado na chave (%d), no índice (%d) do vetor\n", hash_table[key].vector[index].value, key, hash_table[key].vector[index].current_index);
                            break;
                        }
                        steps++;
                        collisions++;
                    }
                }
            }
            total_collisions += collisions;
            total_steps += steps;
            if(steps != 0){
               printf("Passos necessários para encontrar a chave: %d\n", steps);
               printf("Colisões identificadas até encontrar a chave: %d\n", collisions);
            }
        }
    }

    end = clock();

    printf("%s----------------------------------------------------------------\n", C_RED);
    printf("TOTAL DE PASSOS PARA EXECUÇÃO DO ALGORITMO: %s%d %sPASSOS\n", C_BLUE, total_steps, C_RED);
    printf("TOTAL DE COLISÕES IDENTIFICADAS NO ALGORITMO: %s%d %sCOLISÕES\n", C_BLUE, total_collisions, C_RED);
    printf("TEMPO TOTAL GASTO PARA EXECUÇÃO DO ALGORITMO: %s%lf %sSEGUNDOS\n", C_BLUE, ((double) end - start) / ((double) CLOCKS_PER_SEC), C_RED);
    printf("----------------------------------------------------------------%s\n", CLEAN_COLORS);

    fclose(checkin_file);

    return 0;
}