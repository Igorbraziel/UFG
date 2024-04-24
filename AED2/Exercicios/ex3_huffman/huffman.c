#include <stdio.h>
#include <stdlib.h>

#define TRUE 1 
#define FALSE 0

struct node {
    char character;
    float frequency;
    struct node * right;
    struct node * left;
    struct node * next;
    struct node * previous;
};

typedef struct node Node;

struct list {
    Node * first;
    Node * last;
    int size;
};

typedef struct list List;

int LenStr(char * string){
    int i = 0;
    while(string[i] != '\0'){
        i++;
    }
    return i;
}

int CountCharInStr(char character, char * string){
    int counter = 0, i = 0;
    while(string[i] != '\0'){
        if(string[i] == character) counter++;
        i++;
    }

    return counter;
}

float CharFrequencyInStr(char character, char * string){
    int quantity = CountCharInStr(character, string);
    return (float) (((float) quantity / LenStr(string)) * 100);
}

void FreeTree(Node ** root){
    if(*root != NULL){
        FreeTree(&((*root)->left));
        FreeTree(&((*root)->right));
        free(*root);
    }
}

List * CreateList(){
    List * list = NULL;
    list = (List *) malloc(1 * sizeof(List));
    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    return list;
}

Node * CreateNode(char character, float frequency){
    Node * node = NULL;
    node = (Node *) malloc(1 * sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    node->previous = NULL;
    node->next = NULL;

    return node;
}

int IsCharInList(List * list, char character){
    Node * current = list->first;
    while(current != NULL){
        if(current->character == character) return TRUE;
        current = current->next;
    }

    return FALSE;
}

void InsertList(List * list, Node * node){
    if(list == NULL) return;
    if(list->first == NULL){
        list->first = node;
        list->last = node;
    } else if (list->first->next == NULL){
        list->last = node;
        list->first->next = list->last;
        list->last->previous = list->first;
    } else {
        Node * previous = list->last;
        list->last = node;
        previous->next = list->last;
        list->last->previous = previous;
    }
    list->size++;
}

void DeleteList(List * list){
    if(list == NULL) return;
    if(list->first == NULL) return;
    if(list->size == 1){
        Node * removed = list->last;
        list->first = NULL;
        list->last = NULL;
        removed = NULL;
    } else if (list->size == 2){
        Node * removed = list->last;
        list->first->next = NULL;
        list->first->previous = NULL;
        list->last = list->first;
        removed = NULL;
    } else {
        Node * removed = list->last;
        list->last = list->last->previous;
        list->last->next = NULL;
        removed = NULL;
    }
    list->size--;
}

void ShowList(List * list){
    if(list == NULL) return;
    if(list->first == NULL) return;
    char percent = '%';
    Node * current = list->first;
    while(current != NULL){
        printf("Character: %c - Frequency: %f%c\n", current->character, current->frequency, percent);
        current = current->next;
    }
}

void ReadString(char * string){
    int i = 0;
    char c;
    while(1){
        scanf("%c", &c);
        if(c == '\n') break;
        string[i] = c;
        i++;
    }
    string[i] = '\0';
}

void ListSort(List * list){
    if(list == NULL) return;
    if(list->first == NULL) return;
    int order = 0;
    while(1){
        Node * current = list->first;
        while(current->next != NULL){
            if(current->frequency < current->next->frequency){
               Node * next = current->next;
               char temporary_char = current->character;
               float temporary_frequency = current->frequency; 
               current->character = next->character;
               current->frequency = next->frequency;
               next->character = temporary_char;
               next->frequency = temporary_frequency;
            } else {
                order++;
            }
            current = current->next;
        }
        if(order >= list->size - 1) break;
        order = 0;
    }
}

int MyPow(int x, int exponent){
    if (exponent == 0){
        return 1;
    }
    return x * MyPow(x, exponent - 1);
}

int IntToBin(int number, int exponent){
    if(number == 0) return 0;
    return ((number % 2) * MyPow(10, exponent)) + IntToBin(number/2, exponent + 1);
}

void HuffmanAlgorithm(Node * root, char character){
    int bin;
    if(root != NULL){
        if(root->character != character){
            HuffmanAlgorithm(root->right, character);
            HuffmanAlgorithm(root->left, character);
        } else {                                                                                                                     
            bin = IntToBin(character, 0) / 10000;
            printf("\nRepresentation of character (%c) after Huffman Algorithm: %d\n\n", character, bin);
            return;
        }

        if(root->left != NULL && root->left->character == character){
            printf("Node (%c) found in the left\n", character);
        } 
        if(root->right != NULL && root->right->character == character){
            printf("Node (%c) found in the right\n", character);
        }
    }
}

int main(){
    List * list = CreateList();
    char text[100];
    float frequency;
    char character;
    int i = 0;

    printf("Huffman Algorithm:\n");
    printf("Enter the text to be compressed: ");
    scanf("%[^\n]%*c", text);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    // writing in the list
    while(text[i] != '\0'){
        character = text[i];
        frequency = CharFrequencyInStr(character, text);
        if(IsCharInList(list, character) == FALSE){
            InsertList(list, CreateNode(character, frequency));
        }
        i++;
    }

    ShowList(list);

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    // join all the nodes in just one
    while(list->size > 1){
        ListSort(list);
        Node * last = list->last;
        Node * penultimate = last->previous;
        char c = 'N';
        Node * new_node = CreateNode(c, last->frequency + penultimate->frequency);
        new_node->right = last;
        new_node->left = penultimate;
        new_node->previous = penultimate->previous;
        new_node->next = last->next;
        DeleteList(list);
        DeleteList(list);
        InsertList(list, new_node);
        ShowList(list);
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    }

    i = 0;
    while(text[i] != '\0'){
        HuffmanAlgorithm(list->first, text[i]);
        i++;
    }
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    
    return 0;
}