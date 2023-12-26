#include <iostream>
#include "pilha.hpp"
#include <stdlib.h>

Stack * stack_new(){
    Stack * s = (Stack *) malloc(sizeof(Stack));
    s->last = NULL;
    s->size = 0;

    return s;
}

Node * node_new(char character){
    Node * n = (Node *) malloc(sizeof(Node));
    n->previous = NULL;
    n->character = character;
    return n;
}

void stack_delete(Stack * s){
    if(s == NULL) return;
    Node * current = s->last;
    Node * later = NULL;
    while(current != NULL){
        later = current;
        current = current->previous;
        free(later);
    }

    free(s);
}

bool stack_insert(Stack * s, char character){
    Node * n = node_new(character);
    if(s->last == NULL){
        s->last = n;
        (s->size)++;
        return true;
    } else{
        n->previous = s->last;
        s->last = n;
        (s->size)++;
        return true;
    }

    return false;
}

bool stack_remove(Stack * s){
    if(s->size == 0) return false;
    Node * last_one = s->last;
    s->last = s->last->previous;
    free(last_one);
    (s->size)--;

    return true;
}

void stack_show(Stack * s, Node * last_node){
    if(last_node->previous != NULL){
        stack_show(s, last_node->previous);
    }

    if(last_node == s->last){
        std::cout << s->last->character << '\n';
        return;
    }

    std::cout << last_node->character << " -> ";
}

int stack_size(Stack * s){
    return s->size;
}

char * read_expression(){
    char * expression = (char *) malloc(sizeof(char));
    char c;
    int i = 0;

    while(true){
        scanf("%c", &c);
        if(c == '\n') break;
        expression[i] = c;
        i++;
        expression = (char *) realloc(expression, (i + 1) * sizeof(char));
    }

    expression[i] = '\0';
    
    return expression;
}

void check_expression(char * expression){
    Stack * s = stack_new();
    int i = 0;
    bool flag = true;

    while(expression[i] != '\0'){
        if(expression[i] == '('){
            stack_insert(s, expression[i]);
        } else if(expression[i] == ')'){
            if(s->last == NULL){
                flag = false;
                break;
            }
            if(s->last->character == '('){
                flag = stack_remove(s);
            } else{
                flag = false;
                break;
            }
        }

        if(expression[i] == '['){
            stack_insert(s, expression[i]);
        } else if(expression[i] == ']'){
            if(s->last == NULL){
                flag = false;
                break;
            }
            if(s->last->character == '['){
                flag = stack_remove(s);
            } else{
                flag = false;
                break;
            }
        }

        if(expression[i] == '{'){
            stack_insert(s, expression[i]);
        } else if(expression[i] == '}'){
            if(s->last == NULL){
                flag = false;
                break;
            }
            if(s->last->character == '{'){
                flag = stack_remove(s);
            } else{
                flag = false;
                break;
            }
        }

        if(flag == false) break;
        i++;
    }

    if(s->size != 0) flag = false;

    if(flag == false){
        std::cout << "A EXPRESSAO : " << expression << " E INVALIDA\n";
    } else{
        std::cout << "A EXPRESSAO : " << expression << " E VALIDA\n";
    }

}

void delete_expression(char * expression){
    free(expression);
}