#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define TRUE 1
#define FALSE 0
#define file_name "base_algorithm.c"

typedef struct tree {
    char word[100];
    int error_line;
    struct tree * left;
    struct tree * right;
} Tree;

typedef struct stack_node {
    char character;
    int error_line;
    struct stack_node * next;
    struct stack_node * previous;
} Stack_Node;

typedef struct stack {
    Stack_Node * last;
    int size;
} Stack;

Tree * NewTreeNode(char * word, int line){
    Tree * new_node = (Tree *) malloc(sizeof(Tree));
    strcpy(new_node->word, word);
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->error_line = line;
    return new_node;
}

Stack_Node * NewStackNode(const char character, int line){
    Stack_Node * new_node = (Stack_Node *) malloc(sizeof(Stack_Node));
    new_node->character = character;
    new_node->next = NULL;
    new_node->previous = NULL;
    new_node->error_line = line;
    return new_node;
}

Stack * NewStack(){
    Stack * st = (Stack *) malloc(sizeof(Stack));
    st->last = NULL;
    st->size = 0;
    return st;
}

void InsertTree(Tree ** top, char * word, int line){
    if(*top == NULL){
        Tree * new_node = NewTreeNode(word, line);
        *top = new_node;
    } else {
        if(strcmp((*top)->word, word) > 0){
            InsertTree(&(*top)->left, word, line);
        } else {
            InsertTree(&(*top)->right, word, line);
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
        printf("-%s", top->word);
        if(top->error_line != -1) {
            printf("%s - Erro de sintaxe encontrado na linha:%s %d%s", C_RED, C_BLUE, top->error_line, CLEAN_COLORS);
        }
        printf("\n");
        ShowTree(top->right);
    }
}

void ShowStack(Stack * st){
    if(st == NULL) return;
    if(st->last == NULL) return;
    Stack_Node * current = st->last;
    while(current != NULL){
        printf("\n %s%c%s", C_BLUE, current->character, CLEAN_COLORS);
        if(current->error_line != -1) {
            printf("%s - Erro na linha:%s %d%s", C_GREEN, C_BLUE, current->error_line, CLEAN_COLORS);
        }
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
        printf("%s", C_GREEN);
        printf("Não há erros na fechadura de parênteses, chaves ou colchetes%s\n\n", CLEAN_COLORS);
    } else {
        printf("%s", C_RED);
        printf("Há %d erros na fechadura de parênteses, chaves ou colchetes\n", input_block->size);
        printf("Os blocos que não foram fechados são: ");
        printf("%s", CLEAN_COLORS);
        ShowStack(input_block);
        printf("\n");
    }

    if(output_block->last == NULL){
        printf("%s", C_GREEN);
        printf("Não há erros na abertura de parênteses, chaves ou colchetes%s\n", CLEAN_COLORS);
    } else {
        printf("%s", C_RED);
        printf("Há %d erros na abertura de parênteses, chaves ou colchetes\n", output_block->size);
        printf("Os blocos que não foram abertos terminam com: ");
        printf("%s", CLEAN_COLORS);
        ShowStack(output_block);
        printf("\n");
    }
}

int main(){
    Tree * top = NULL;
    Tree * correct_words = NULL;
    Tree * wrong_words = NULL;
    Stack * st = NewStack();
    Stack * errors_stack_output = NewStack();
    Stack * errors_stack_input = NewStack();
    FILE * file_ = fopen(file_name, "r");
    int data_size = 38, i, current_line = 1;
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
        "realloc", // function 32
        "double", // 33 
        "const", // 34
        "sizeof", // 35
        "switch", // 36
        "case", // 37
        "unsigned" // 38
    };  

    // Inserting the data in the tree
    for(i = 0; i < data_size; i++){
        InsertTree(&top, Data[i], -1);  
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
                        InsertTree(&correct_words, command_word, -1);
                    }
                } else {
                    if(SearchTree(wrong_words, command_word) == FALSE && strcmp(command_word, "") != 0){
                        InsertTree(&wrong_words, command_word, current_line);
                    }
                }
                command_index = 0;
                strcpy(command_word, "");
            }
        }
        
        if(c == '('){
            flag = 1;
            InsertStack(st, NewStackNode(c, current_line));
        }
        if(c == '['){
            InsertStack(st, NewStackNode(c, current_line));
        }
        if(c == '{'){
            InsertStack(st, NewStackNode(c, current_line));
        }
        if(c == ')'){
            flag = 0;
            removed_value = DeleteStack(st);
            if(removed_value != '('){
                InsertStack(errors_stack_output, NewStackNode(c, current_line));
                if(removed_value != '0'){
                    InsertStack(errors_stack_input, NewStackNode(removed_value, current_line));
                }
            }
        }
        if(c == ']'){
            removed_value = DeleteStack(st);
            if(removed_value != '['){
                InsertStack(errors_stack_output, NewStackNode(c, current_line));
                if(removed_value != '0'){
                    InsertStack(errors_stack_input, NewStackNode(removed_value, current_line));
                }
            }
        }
        if(c == '}'){
            removed_value = DeleteStack(st);
            if(removed_value != '{'){
                InsertStack(errors_stack_output, NewStackNode(c, current_line));
                if(removed_value != '0'){
                    InsertStack(errors_stack_input, NewStackNode(removed_value, current_line));
                }
            }
        }
        if(c == '<') flag = 1;
        if(c == '>') flag = 0;
        if(c == '\n') current_line++;
    }

    while(1){
        if(st->last != NULL){
            c = DeleteStack(st);
            if(c == '0') break;
            current_line = st->last->error_line;
            InsertStack(errors_stack_input, NewStackNode(c, current_line));
        } else {
            break;
        }
    }

    printf("----------------------------------------------------------------------------\n");
    ShowStackErrors(errors_stack_input, errors_stack_output);
    printf("----------------------------------------------------------------------------\n");

    printf("%s", C_BLUE);
    printf("Palavras com a sintaxe correta segundo o compilador de linguagem C: %s{\n", CLEAN_COLORS);
    ShowTree(correct_words);
    printf("}\n");
    printf("----------------------------------------------------------------------------\n");
    printf("%s", C_BLUE);
    printf("Palavras com a sintaxe incorreta segundo o compilador de linguagem C: %s{\n", CLEAN_COLORS);
    printf("(AQUI INCLUI AS VÁRIAVEIS UTILIZADAS NO ALGORITMO,\nQUE NÃO SÃO RECONHECIDAS COMO PALAVRAS-CHAVE DA LINGUAGEM C)\n");
    ShowTree(wrong_words);
    printf("}\n");
    printf("----------------------------------------------------------------------------\n");

    fclose(file_);
    FreeTree(top);
    FreeTree(correct_words);
    FreeTree(wrong_words);
    FreeStack(st);
    FreeStack(errors_stack_input);
    FreeStack(errors_stack_output);

    return 0;
}