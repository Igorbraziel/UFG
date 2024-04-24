#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE_MAX_EXPRESSION 100
#define TRUE 1
#define FALSE 0

struct node {
    int value;
    struct node * next;
    struct node * previous;
};

typedef struct node Node;

struct stack {
    Node * first;
    Node * last;
    int size;
};

typedef struct stack Stack;

Node * CreateNode(int value){
    Node * nd = NULL;
    nd = (Node *) malloc(1 * sizeof(Node));
    nd->value = value;
    nd->next = NULL;
    nd->previous = NULL;
    return nd;
}

Stack * CreateStack(){
    Stack * st = NULL;
    st = (Stack *) malloc(1 * sizeof(Stack));
    st->first = NULL;
    st->last = NULL;
    st->size = 0;
    return st;
}

void FreeStack(Stack * st){
    if(st == NULL) return;
    if(st->first == NULL){
        free(st);
        return;
    }

    Node * current = st->first;
    while(current != NULL){
        Node * removed = current;
        current = current->next;
        free(removed);
    }

    free(st);
}

void StackUp(Stack * st, Node * nd){
    if(st->first == NULL){
        st->first = nd;
        st->last = nd;
    } else if (st->size == 1){
        st->last = nd;
        st->first->next = st->last;
        st->last->previous = st->first;
    } else {
        Node * previous = st->last;
        st->last = nd;
        previous->next = st->last;
        st->last->previous = previous;
    }

    st->size++;
}

int Unstack(Stack * st){
    if(st->size == 0) return 0;
    int removed_value;
    if(st->size == 1){
        Node * removed = st->last;
        removed_value = removed->value;
        st->first = NULL;
        st->last = NULL;
        free(removed);
    } else {
        Node * removed = st->last;
        removed_value = removed->value;
        st->last = st->last->previous;
        st->last->next = NULL;
        free(removed);
    }

    st->size--;
    return removed_value;
}

void ShowStack(Stack * st){
    if(st->first == NULL) return;
    Node * current = st->first;
    while(current != NULL){
        printf("%d ", current->value);
        current = current->next;
    }
}

int CheckSignal(char character){
    if(character == '-' || character == '+' || character == '/' || character == '*' || character == '^' || character == 'r'){
        return TRUE;
    }
    return FALSE;
}

int MyPow(int number, int exponent){
    if(exponent == 0){
        return 1;
    }
    return number * MyPow(number, exponent - 1);
}

int StringToInt(char * string, int len_string){
    int i = 0;
    int template_number, end_number = 0;

    while(string[i] != '\0'){
        template_number = string[i] - '0';
        if(template_number != 0){
            end_number += template_number * MyPow(10, len_string - 1);
        } 
        len_string--;
        i++;
    }

    return end_number;
}

int isNumber(char character){
    if(character >= '0' && character <= '9') return TRUE;
    return FALSE;
}

int len(char * string){
    int i = 0;

    while(string[i] != '\0'){
        i++;
    }

    return i;
}

int ResolveExpression(Stack * st, char * expression){
    int i = 0, j = 0, k = 0, index_to_stackup = 0;
    int result, number;
    char template_string[SIZE_MAX_EXPRESSION];

    while(expression[i] != '\0'){
        if(i + 1 == len(expression) && CheckSignal(expression[i]) == TRUE){
            Node * current = st->first;
            if(expression[i] == '+'){
                result = 0;
                while(current != NULL){
                    result += current->value;
                    current = current->next;
                }
            } else if(expression[i] == '-'){
                while(current != NULL){
                    if(current == st->first){
                        result = current->value;
                    } else{
                        result -= current->value;
                    }
                    current = current->next;
                }
            } else if(expression[i] == '/'){
                while(current != NULL){
                    if(current == st->first){
                        result = current->value;
                    } else{
                        result /= current->value;
                    }
                    current = current->next;
                }
            } else if(expression[i] == '*'){
                while(current != NULL){
                    if(current == st->first){
                        result = current->value;
                    } else{
                        result *= current->value;
                    }
                    current = current->next;
                }
            } else if(expression[i] == '^'){
                while(current != NULL){
                    if(current == st->first){
                        result = current->value;
                    } else{
                        result = MyPow(result, current->value);
                    }
                    current = current->next;
                }
            } else if(expression[i] == 'r'){
                result = sqrt((double) current->value);
            }
            while(st->size > 0){
                Unstack(st);
            }
            StackUp(st, CreateNode(result));
        } else if(CheckSignal(expression[i]) == TRUE){
            Node * current = st->first;
            k = 0;
            while(k < index_to_stackup){
                current = current->next;
                k++;
            }
            if(expression[i] == '+'){
                result = 0;
                while(current != NULL){
                    result += current->value;
                    current = current->next;
                }
            } else if(expression[i] == '-'){
                k = 0;
                while(current != NULL){
                    if(k == 0){
                        result = current->value;
                        k = 1;
                    } else{
                        result -= current->value;
                    }
                    current = current->next;
                }
            } else if(expression[i] == '/'){
                j = 0;
                while(current != NULL){
                    if(k == 0){
                        result = current->value;
                        k = 1;
                    } else{
                        result /= current->value;
                    }
                    current = current->next;
                }
            } else if(expression[i] == '*'){
                k = 0;
                while(current != NULL){
                    if(k == 0){
                        result = current->value;
                        k = 1;
                    } else{
                        result *= current->value;
                    }
                    current = current->next;
                }
            } else if(expression[i] == '^'){
                k = 0;
                while(current != NULL){
                    if(k == 0){
                        result = current->value;
                        k = 1;
                    } else{
                        result = MyPow(result, current->value);
                    }
                    current = current->next;
                }
            } else if(expression[i] == 'r'){
                result = sqrt((double) current->value);
            }
            while(st->size > index_to_stackup){
                Unstack(st);
            }
            StackUp(st, CreateNode(result));
            index_to_stackup++;
        } else if(isNumber(expression[i]) == TRUE){
            j = 0;
            while(isNumber(expression[i]) == TRUE && expression[i] != '\0'){
                template_string[j] = expression[i];
                i++;
                j++;
            }
            template_string[j] = '\0';
            number = StringToInt(template_string, j);
            StackUp(st, CreateNode(number));
        }
        i++;
    }
    return st->first->value;
}

int main(){
    Stack * my_stack = NULL;
    char expression[SIZE_MAX_EXPRESSION];
    int result;

    my_stack = CreateStack();

    printf("Digite a sua expressão matemática de maneira pós-fixa: ");
    scanf("%[^\n]%*c", expression);
    result = ResolveExpression(my_stack, expression);
    printf("Resultado da sua expressão matemática: %d\n", result);

    FreeStack(my_stack);
    return 0;
}