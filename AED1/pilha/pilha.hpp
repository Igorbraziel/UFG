#ifndef __STACK_HPP__
#define __STACK_HPP__

struct node{
    char character;
    struct node * previous;
};

typedef struct node Node;

struct stack{
    int size;
    Node * last;
};

typedef struct stack Stack;

Stack * stack_new();
Node * node_new(char character);
void stack_delete(Stack * s);
bool stack_insert(Stack * s, char character);
bool stack_remove(Stack * s);
void stack_show(Stack * s, Node * last_one);
int stack_size(Stack * s); 
void check_expression(char * expression);
char * read_expression();
void delete_expression(char * expression);

#endif