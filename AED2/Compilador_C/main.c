#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define file_name "base_algorithm.c"

typedef struct tree {
    char word[100];
    struct tree * left;
    struct tree * right;
} Tree;

typedef struct stack_node {
    char character;
    struct stack_node * next;
    struct stack_node * previous;
} Stack_Node;

typedef struct stack {
    Stack_Node * last;
    int size;
} Stack;

Tree * NewTreeNode(char * word){
    Tree * new_node = (Tree *) malloc(sizeof(Tree));
    strcpy(new_node->word, word);
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

Stack_Node * NewStackNode(const char character){
    Stack_Node * new_node = (Stack_Node *) malloc(sizeof(Stack_Node));
    new_node->character = character;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}

Stack * NewStack(){
    Stack * st = (Stack *) malloc(sizeof(Stack));
    st->last = NULL;
    st->size = 0;
    return st;
}

void InsertTree(Tree ** top, char * word){
    if(*top == NULL){
        Tree * new_node = NewTreeNode(word);
        *top = new_node;
    } else {
        if(strcmp((*top)->word, word) > 0){
            InsertTree(&(*top)->left, word);
        } else {
            InsertTree(&(*top)->right, word);
        }
    }
}

void InsertStack(Stack * st, Stack_Node * new_node){
    if(st == NULL) return;
    if(st->last == NULL){
        st->last = new_node;
        st->size++;
    } else {
        Stack_Node * template = st->last;
        st->last = new_node;
        template->next = st->last;
        st->last->previous = template;
        st->size++;
    }
}

void ShowTree(Tree * top){
    if(top != NULL){
        ShowTree(top->left);
        printf("-%s\n", top->word);
        ShowTree(top->right);
    }
}

void ShowStack(Stack * st){
    if(st == NULL) return;
    if(st->last == NULL) return;
    Stack_Node * current = st->last;
    while(current != NULL){
        printf("%c ", current->character);
        current = current->previous;
    }
}

void FreeTree(Tree * top){
    if(top != NULL){
        FreeTree(top->left);
        FreeTree(top->right);
        free(top);
    }
}

void FreeStack(Stack * st){
    if(st == NULL) return;
    if(st->last == NULL) return;
    Stack_Node * current = st->last;
    while(current != NULL){
        Stack_Node * removed = current;
        current = current->previous;
        free(removed);
    }
    free(st);
}

char DeleteStack(Stack * st){
    if(st == NULL) return '0';
    if(st->last == NULL) return '0';
    if(st->size == 1){
        char removed_character = st->last->character;
        Stack_Node * removed_node = st->last;
        free(removed_node);
        st->last = NULL;
        st->size--;
        return removed_character;
    } else if(st->last->previous != NULL){
        Stack_Node * removed_node = st->last;
        char removed_character = st->last->character;
        st->last = st->last->previous;
        st->last->next = NULL;
        free(removed_node);
        st->size--;
        return removed_character;
    }
}

int SearchTree(Tree * top, const char * word){
    if(top == NULL){
        return FALSE;
    } 
    if(strcmp(top->word, word) == 0){
        return TRUE;
    }
    if (strcmp(top->word, word) > 0){
        SearchTree(top->left, word);
    } else {
        SearchTree(top->right, word);
    }
}

void ShowStackErrors(Stack * input_block, Stack * output_block){
    if(input_block->last == NULL){
        printf("Não há erros na fechadura de parênteses, chaves ou colchetes\n");
    } else {
        printf("Há %d erros na fechadura de parênteses, chaves ou colchetes\n", input_block->size);
        printf("Os blocos que não foram fechados são: ");
        ShowStack(input_block);
        printf("\n");
    }

    if(output_block->last == NULL){
        printf("Não há erros na abertura de parênteses, chaves ou colchetes\n");
    } else {
        printf("Há %d erros na abertura de parênteses, chaves ou colchetes\n", output_block->size);
        printf("Os blocos que não foram abertos terminam com: ");
        ShowStack(output_block);
        printf("\n");
    }
}

int main(){
    Tree * top = NULL;
    Tree * correct_words = NULL;
    Tree * wrong_words = NULL;
    Stack * st = NewStack();
    Stack * errors_stack = NewStack();
    FILE * file_ = fopen(file_name, "r");
    int data_size = 32, i;
    int flag = 0, command_index = 0; 
    char c, removed_value;
    char command_word[100];
    char Data[100][100] = {
        "fopen", // function 1
        "fclose", // function 2
        "fgetc", // function 3
        "fputc", // function 4
        "fprintf", // function 5
        "fscanf", // function 6
        "free", // function 7
        "malloc", // function 8
        "calloc", // function 9
        "printf", // function 10
        "scanf", // function 11
        "include", // using after # 12
        "define", // using after # 13
        "int", // Type of data 14
        "char", // Type of data 15
        "float", // Type of data 16
        "return", // keyword 17
        "void", // keyword 18 
        "break", // keyword 19
        "if", // keyword 20
        "else if", // keyword 21
        "else", // keyword 22
        "main", // keyword 23
        "while", // keyword 24
        "for", // keyword 25
        "typedef", // keyword 26
        "&&", // Logical Operator 27
        "||", // Logical Operator 28
        "struct", // keyword 29
        "sqrt", // function 30
        "FILE", // Type od data 31
        "realloc" // function 32
    };  

    // Inserting the data in the tree
    for(i = 0; i < data_size; i++){
        InsertTree(&top, Data[i]);
    }

    while(1){ // Verification of the algorithm
        c = fgetc(file_);
        if(c == EOF) break;
        if(flag == 0){
            if((65 <= c && c <= 90) || (97 <= c && c <= 122)){
                command_word[command_index] = c;
                command_index++;
                command_word[command_index] = '\0';
            } else {
                if(SearchTree(top, command_word) == TRUE){
                    if(SearchTree(correct_words, command_word) == FALSE){
                        InsertTree(&correct_words, command_word);
                    }
                } else {
                    if(SearchTree(wrong_words, command_word) == FALSE && strcmp(command_word, "") != 0){
                        InsertTree(&wrong_words, command_word);
                    }
                }
                command_index = 0;
                strcpy(command_word, "");
            }
        }
        
        if(c == '('){
            flag = 1;
            InsertStack(st, NewStackNode(c));
        }
        if(c == '['){
            InsertStack(st, NewStackNode(c));
        }
        if(c == '{'){
            InsertStack(st, NewStackNode(c));
        }
        if(c == ')'){
            flag = 0;
            removed_value = DeleteStack(st);
            if(removed_value != '('){
                InsertStack(errors_stack, NewStackNode(c));
            }
        }
        if(c == ']'){
            removed_value = DeleteStack(st);
            if(removed_value != '['){
                InsertStack(errors_stack, NewStackNode(c));
            }
        }
        if(c == '}'){
            removed_value = DeleteStack(st);
            if(removed_value != '{'){
                InsertStack(errors_stack, NewStackNode(c));
            }
        }
        if(c == '<') flag = 1;
        if(c == '>') flag = 0;
    }

    printf("----------------------------------------------------------------------------\n");
    ShowStackErrors(st, errors_stack);
    printf("----------------------------------------------------------------------------\n");

    printf("Palavras com a sintaxe correta segundo o compilador de linguagem C: {\n");
    ShowTree(correct_words);
    printf("}\n");
    printf("----------------------------------------------------------------------------\n");
    printf("Palavras com a sintaxe incorreta segundo o compilador de linguagem C: {\n");
    printf("(AQUI INCLUI AS VÁRIAVEIS UTILIZADAS NO ALGORITMO,\nQUE NÃO SÃO RECONHECIDAS COMO PALAVRAS-CHAVE DA LINGUAGEM C)\n");
    ShowTree(wrong_words);
    printf("}\n");
    printf("----------------------------------------------------------------------------\n");

    fclose(file_);
    FreeTree(top);
    FreeTree(correct_words);
    FreeTree(wrong_words);
    FreeStack(st);
    FreeStack(errors_stack);

    return 0;
}