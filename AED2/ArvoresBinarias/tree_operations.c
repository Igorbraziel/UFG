#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * right;
    struct node * left;
};

typedef struct node Node;

Node * NewNode(int value){
    Node * nd = NULL;
    nd = (Node *) malloc(1 * sizeof(Node));
    nd->left = NULL;
    nd->right = NULL;
    nd->value = value;

    return nd;
}

void InsertionTree(Node ** top, int number){
    if(*top == NULL){
        *top = NewNode(number);
    } else {
        if(number < (*top)->value){
            InsertionTree(&((*top)->left), number);
        } else {
            InsertionTree(&((*top)->right), number);
        }
    }
}

void ShowTree(Node * top){
    if(top != NULL){
        ShowTree(top->left);
        printf("(%d) ", top->value);
        ShowTree(top->right);
    }
}

int ToCountNodes(Node * top){
    if(top == NULL){
        return 0;
    } else {
        return 1 + ToCountNodes(top->right) + ToCountNodes(top->left);
    }
}

int ToCountSheets(Node * top){
    if(top == NULL){
        return 0;
    } 
    if(top->right == NULL && top->left == NULL){
        return 1;
    }
    return ToCountSheets(top->left) + ToCountSheets(top->right);
}

int bigger(int a, int b) {
    if (a > b){
        return a;
    }
    else{
        return b;
    }

} //bigger

int Height(Node * top) {
    if ((top == NULL) || (top->left == NULL && top->right == NULL)){
        return 0;
    }
    else{
        return 1 + bigger(Height(top->left), Height(top->right));
    }
}

Node * SearchTree(Node * top, int value){
    if(top == NULL){
        return NULL;
    }
    if(top->value == value){
        return top;
    }
    if(top->value > value){
        SearchTree(top->left, value);
    } else {
        SearchTree(top->right, value);
    }
}

Node * RemoveTree(Node ** top, int value){
    if(*top == NULL){
        return NULL;
    } else if ((*top)->value > value){
        (*top)->left = RemoveTree(&((*top)->left), value);
    } else if ((*top)->value < value){
        (*top)->right = RemoveTree(&((*top)->right), value);
    } else {
        if((*top)->left == NULL && (*top)->right == NULL){
            free(*top);
            *top = NULL;
        } else if((*top)->left == NULL){
            Node * removed = *top;
            *top = (*top)->right;
            free(removed);
        } else if((*top)->right == NULL){
            Node * removed = *top;
            *top = (*top)->left;
            free(removed);
        } else{
            Node * temporary = (*top)->left;
            while(temporary->right != NULL){
                temporary = temporary->right;
            }
            (*top)->value = temporary->value;
            temporary->value = value;
            (*top)->left = RemoveTree(&((*top)->left), value);
        }
    }
    return *top;
}

void FreeTree(Node ** top){
    if(*top != NULL){
        FreeTree(&((*top)->left));
        FreeTree(&((*top)->right));
        free(*top);
    }
}

int main() {
    Node * top = NULL;
    InsertionTree(&top, 5);
    InsertionTree(&top, 3);
    InsertionTree(&top, 8);
    InsertionTree(&top, 1);
    InsertionTree(&top, 4);
    InsertionTree(&top, 6);
    InsertionTree(&top, 9);
    InsertionTree(&top, 0);
    InsertionTree(&top, 2);
    InsertionTree(&top, 7);
    ShowTree(top);
    printf("\n");
    printf("%d\n", ToCountNodes(top));
    printf("%d\n", ToCountSheets(top));
    printf("%d\n", Height(top));
    RemoveTree(&top, 8);
    RemoveTree(&top, 3);
    RemoveTree(&top, 5);
    ShowTree(top);
    printf("\n");
    
    FreeTree(&top);
    return 0;
}