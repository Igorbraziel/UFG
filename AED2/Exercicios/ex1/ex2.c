#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_MAX_STRING 50
#define SUCCESS 1
#define FAULT 0

struct node{
    int matriculation;
    char name[SIZE_MAX_STRING];
    char course[SIZE_MAX_STRING];
    float note1;
    float note2;
    struct node * next;
    struct node * previous;
};

typedef struct node Node;

struct registry{
    Node * first;
    Node * last;
    int size;
};

typedef struct registry Registry;

Registry * Make_Registry(){
    Registry * record = NULL;
    record = (Registry *) malloc(1 * sizeof(Registry));
    record->first = NULL;
    record->last = NULL;
    record->size = 0;
}

Node * New_Node(int matriculation, char * name, char * course, float note1, float note2){
    Node * new_node = NULL;
    new_node = (Node *) malloc(1 * sizeof(Node));
    new_node->matriculation = matriculation;
    strcpy(new_node->name, name);
    strcpy(new_node->course, course);
    new_node->note1 = note1;
    new_node->note2 = note2;
    new_node->next = NULL;
    new_node->previous = NULL;

    return new_node;
}

int Exists_Matriculation_Registry(Registry * record, int matriculation){
    if(record->first == NULL) return SUCCESS;
    int i;
    Node * current = record->first;

    for(i = 0; i < record->size; i++){
        if(current->matriculation == matriculation) return FAULT;
        current = current->next;
    }

    return SUCCESS;
}

int CREATE(Registry * record){
    int matriculation;
    char name[SIZE_MAX_STRING];
    char course[SIZE_MAX_STRING];
    float note1;
    float note2;
    
    printf("Digite o número de matrícula a ser registrado: ");
    scanf("%d%*c", &matriculation);

    if(Exists_Matriculation_Registry(record, matriculation) == 0){
        printf("Falha na criação de um novo registro\n");
        return FAULT;
    }

    printf("Digite o nome a ser registrado: ");
    scanf("%[^\n]%*c", name);

    printf("Digite o nome do curso a ser registrado: ");
    scanf("%[^\n]%*c", course);

    printf("Digite a primeira nota a ser registrada: ");
    scanf("%f", &note1);

    printf("Digite a segunda nota a ser registrada: ");
    scanf("%f", &note2);

    if(record->first == NULL){
        record->first = New_Node(matriculation, name, course, note1, note2);
        record->last = New_Node(matriculation, name, course, note1, note2);
    } else if(record->size == 1){
        record->last = New_Node(matriculation, name, course, note1, note2);
        record->first->next = record->last;
        record->first->previous = record->last;
        record->last->next = record->first;
        record->last->previous = record->first;
    } else{
        Node * previous = record->last;
        record->last = New_Node(matriculation, name, course, note1, note2);
        previous->next = record->last;
        record->last->previous = previous;
        record->last->next = record->first;
    }

    printf("CREATE concluído com sucesso!\n");
    record->size += 1;
    return SUCCESS;
}

int READ(Registry * record){
    if(record->first == NULL) return FAULT;
    Node * current = record->first;
    int i;

    printf("------------------------------------\n");
    for(i = 0; i < record->size; i++){
        printf("Número de Matrícula: %d\n", current->matriculation);
        printf("Nome do Aluno: %s\n", current->name);
        printf("Nome do Curso: %s\n", current->course);
        printf("Primeira Nota do Aluno: %.2f\n", current->note1);
        printf("Segunda Nota do Aluno: %.2f\n", current->note2);
        printf("Média Final do Aluno: %.2f\n", (float) ((current->note1 + current->note2) / 2));
        printf("------------------------------------\n");
        current = current->next;
    }
    return SUCCESS;
}

int main(){
    Registry * first_registry;
    first_registry = Make_Registry();

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
            CREATE(first_registry);
        } else if (options == 2){
            READ(first_registry);
        } /*else if (options == 3){
            UPDATE(first_registry);
        } else if (options == 4){
            DELETE(first_registry);
        } else if (options == 5){
            break;
        }*/
    }
    
    return 0;
}