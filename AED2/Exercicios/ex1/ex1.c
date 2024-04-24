#include <stdio.h>
#include <string.h>

#define SIZE_MAX_STRING 50
#define NUM_ROWS 50
#define SUCCESS 1
#define FAULT 0

struct registry {
    int matriculation;
    char name[SIZE_MAX_STRING];
    char course[SIZE_MAX_STRING];
    float note1;
    float note2;
};

typedef struct registry Registry;

int CREATE(Registry * array, int * current_size){
    if(*current_size > 49){
        printf("Falha na criação de um novo registro\n");
        return FAULT;
    }

    int matriculation;
    int i;

    printf("Digite o número de matrícula a ser registrado: ");
    scanf("%d%*c", &matriculation);

    for(i = 0; i < *current_size; i++){
        if(matriculation == array[i].matriculation){
            printf("Falha na criação de um novo registro\n");
            return FAULT;
        }
    }

    array[*current_size].matriculation = matriculation;

    printf("Digite o nome a ser registrado: ");
    scanf("%[^\n]%*c", array[*current_size].name);

    printf("Digite o nome do curso a ser registrado: ");
    scanf("%[^\n]%*c", array[*current_size].course);
    
    printf("Digite a primeira nota a ser registrada: ");
    scanf("%f", &array[*current_size].note1);

    printf("Digite a segunda nota a ser registrada: ");
    scanf("%f", &array[*current_size].note2);

    printf("CREATE concluído com sucesso!\n");
    (*current_size) = (*current_size) + 1;

    return SUCCESS;
}

int READ(Registry * array, int current_size){
    if(current_size == 0){
        printf("Registrio vazio\n");
        return FAULT;
    }
    int i;

    printf("------------------------------------\n");
    for(i = 0; i < current_size; i++){
        printf("Número de Matrícula: %d\n", array[i].matriculation);
        printf("Nome do Aluno: %s\n", array[i].name);
        printf("Nome do Curso: %s\n", array[i].course);
        printf("Primeira Nota do Aluno: %.2f\n", array[i].note1);
        printf("Segunda Nota do Aluno: %.2f\n", array[i].note2);
        printf("Média Final do Aluno: %.2f\n", (float) ((array[i].note1 + array[i].note2) / 2));
        printf("------------------------------------\n");
    }
    return SUCCESS;
}

int UPDATE(Registry * array, int current_size){
    int matriculation, i, j;

    printf("Digite o número de matrícula desejado para alterar os dados do aluno: ");
    scanf("%d", &matriculation);

    for(i = 0; i < current_size; i++){
        if(matriculation == array[i].matriculation){
            printf("Digite o novo número de matricula desejado: ");
            scanf("%d%*c", &matriculation);
            for(j = 0; j < current_size; j++){
                if(matriculation == array[j].matriculation){
                    printf("Falha no UPDATE de registro\n");
                    return FAULT;
                }
            }

            array[i].matriculation = matriculation;

            printf("Digite o novo nome a ser registrado: ");
            scanf("%[^\n]%*c", array[i].name);

            printf("Digite o novo curso a ser registrado: ");
            scanf("%[^\n]%*c", array[i].course);

            printf("Digite a nova primeira nota a ser registrada: ");
            scanf("%f", &array[i].note1);

            printf("Digite a nova segunda nota a ser registrada: ");
            scanf("%f", &array[i].note2);

            printf("UPDATE concluído com sucesso!\n");

            return SUCCESS;
            
        }
    }

    printf("Falha no UPDATE de registro\n");
    return FAULT;
}

int DELETE(Registry * array, int * current_size){
    if(*current_size == 0){
        printf("Falha no DELETE de registros\n");
        return FAULT;
    }

    int matriculation, i, j;
    char option;

    printf("Digite o número de matrícula do aluno que será removido do registro: ");
    scanf("%d%*c", &matriculation);

    for(i = 0; i < *current_size; i++){
        if(matriculation == array[i].matriculation){
            printf("Registro Encontrado, deseja realmente excluir? [S/N]: ");
            scanf("%c", &option);
            if(option == 's' || option == 'S'){
                for(j = i; j < (*current_size) - 1; j++){
                    array[j].matriculation = array[j+1].matriculation;
                    strcpy(array[j].name, array[j+1].name);
                    strcpy(array[j].course, array[j+1].course);
                    array[j].note1 = array[j+1].note1;
                    array[j].note2 = array[j+1].note2;
                }
                array[j].matriculation = 0;
                strcpy(array[j].name, "");
                strcpy(array[j].course, "");
                array[j].note1 = 0;
                array[j].note2 = 0;

                printf("DELETE concluído com sucesso!\n");
                (*current_size) = (*current_size) - 1;

                return SUCCESS;
            }
        }
    }

    printf("Falha no DELETE de registros\n");
    return FAULT;
}

int main(){
    Registry array[NUM_ROWS];
    int current_size = 0;
    int options;

    while(1){
        printf("------------------------------------\n");
        printf("Para CRIAR novo registro digite (1)\n");
        printf("Para LER todos os registros digite (2)\n");
        printf("Para ATUALIZAR os registros digite (3)\n");
        printf("Para EXCLUIR algum registro digite (4)\n");
        printf("Para SAIR do programa digite (5)\n");
        printf("------------------------------------\n");
        printf("Opção: ");
        scanf("%d", &options);

        if(options == 1){
            CREATE(array, &current_size);
        } else if (options == 2){
            READ(array, current_size);
        } else if (options == 3){
            UPDATE(array, current_size);
        } else if (options == 4){
            DELETE(array, &current_size);
        } else if (options == 5){
            break;
        }
    }
    
    return 0;
}