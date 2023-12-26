#include "pilha.hpp"
#include <iostream>

int main(){
    char * expression = NULL;

    expression = read_expression();

    check_expression(expression);

    delete_expression(expression);

    return 0;
}