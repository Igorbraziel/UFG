#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

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

struct coordinate {
    float x;
    float y;
};

typedef struct coordinate Coordinate;

struct node {
    char name[100];
    Coordinate  * ordered_pair;
    char category[100];
    struct node * left;
    struct node * right;
};

typedef struct node Node;

Coordinate * NewCoordinate(float x, float y) {
    Coordinate * ordered_pair = (Coordinate *) malloc(1 * sizeof(Coordinate));
    ordered_pair->x = x;
    ordered_pair->y = y;

    return ordered_pair;
}

Node * NewNode(const char * name, Coordinate * ordered_pair, const char * category) {
    Node * new_node = (Node *) malloc(1 * sizeof(Node));
    strcpy(new_node->name, name);
    new_node->ordered_pair = ordered_pair;
    strcpy(new_node->category, category);
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void FlushIn(){
    int character;
    while( (character = fgetc(stdin)) != EOF && character != '\n'){}
}

int MyPow(float number, int exponent) {
    if(exponent == 0) {
        return 1;
    }
    return number * MyPow(number, exponent - 1);
}

void TreeInsertion(Node ** top, Node * new_leaf){
    if((*top) == NULL) {
        (*top) = new_leaf;
    } else {
        if(strcmp((*top)->name, new_leaf->name) > 0) {
            TreeInsertion(&((*top)->left), new_leaf);
        } else {
            TreeInsertion(&((*top)->right), new_leaf);
        }
    }
}

void RowDisplay(void){
    printf("-------------------------------------------------------------------------------\n");
}

void ShowNode(Node * nd) {
    if(nd != NULL) {
        sleep(1);
        RowDisplay();
        printf("Nome: %s\n", nd->name);
        printf("Coordenadas: (%.2f, %.2f)\n", nd->ordered_pair->x, nd->ordered_pair->y);
        printf("Categoria: %s\n", nd->category);
    }
}

void Display_InOrder(Node * top) {
    if(top != NULL) {
        Display_InOrder(top->left);
        ShowNode(top);
        Display_InOrder(top->right);
    }
}

void Display_PreOrder(Node * top) {
    if(top != NULL) {
        ShowNode(top);
        Display_PreOrder(top->left);
        Display_PreOrder(top->right);
    }
}

void Display_PostOrder(Node * top) {
    if(top != NULL) {
        Display_PostOrder(top->left);
        Display_PostOrder(top->right);
        ShowNode(top);
    }
}

Node * TreeDelete(Node ** top, Node * nd) {
    if(*top == NULL){
        return NULL;
    } else if (strcmp((*top)->name, nd->name) > 0){
        (*top)->left = TreeDelete(&((*top)->left), nd);
    } else if (strcmp((*top)->name, nd->name) < 0){
        (*top)->right = TreeDelete(&((*top)->right), nd);
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
            strcpy((*top)->name, temporary->name);
            (*top)->ordered_pair = temporary->ordered_pair;
            strcpy((*top)->category, temporary->category);
            strcpy(temporary->name, nd->name);
            temporary->ordered_pair = nd->ordered_pair;
            strcpy(temporary->category, nd->category);
            (*top)->left = TreeDelete(&((*top)->left), nd);
        }
    }
    return *top;
}

void TreeFree(Node ** top) {
    if(*top != NULL) {
        TreeFree(&((*top)->left));
        TreeFree(&((*top)->right));
        free(*top);
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

Node * TreeNameSearch(Node * top, const char * name) {
    if(top == NULL) return NULL;
    if(strcmp(top->name, name) == 0) {
        return top;
    } else if(strcmp(top->name, name) > 0) {
        TreeNameSearch(top->left, name);
    } else {
        TreeNameSearch(top->right, name);
    }
}

float DistanceBetweenCoordinates(Coordinate * coordinate1, Coordinate * coordinate2) {
    return sqrt((double) MyPow(coordinate2->x - coordinate1->x, 2) + MyPow(coordinate2->y - coordinate1->y, 2));
}

void RadiusDistance(Node * top, Coordinate * central_point, float radius, int * flag){
    if(top != NULL){
        RadiusDistance(top->left, central_point, radius, flag);
        if(DistanceBetweenCoordinates(top->ordered_pair, central_point) <= radius) {
            ShowNode(top);
            (*flag) = 1;
        }
        RadiusDistance(top->right, central_point, radius, flag);
    }
}

void Menu(Node ** top){
    int option, flag;
    char template_name[100];
    char template_category[100];
    float x, y, radius;
    Coordinate * template_coordinate = NULL;
    Node * template_node = NULL;
    
    printf("%s--------------------------------------MENU--------------------------------------%s\n", BG_BLACK, CLEAN_COLORS);
    printf("--Bem-Vindo(a) ao nosso Sistema de Pontos de Navegação!!!\n");
    while(1){
        sleep(2);
        RowDisplay();
        printf("OPÇÕES DO MENU:\n");
        printf("%s(1)%s - %sAdicionar Um Ponto de Navegação%s\n", C_YELLOW, CLEAN_COLORS, C_RED, CLEAN_COLORS);  // Finished
        printf("%s(2)%s - %sRemover Um Ponto de Navegação%s\n", C_YELLOW, CLEAN_COLORS, C_RED, CLEAN_COLORS); // Finished
        printf("%s(3)%s - %sCalcular a distância entre dois Pontos de Navegação%s\n", C_YELLOW, CLEAN_COLORS, C_RED, CLEAN_COLORS); // Finished
        printf("%s(4)%s - %sEncontrar Pontos de Navegação Próximos%s\n", C_YELLOW, CLEAN_COLORS, C_RED, CLEAN_COLORS); // I need to test
        printf("%s(5)%s - %sExibir os Pontos de Navegação%s\n", C_YELLOW, CLEAN_COLORS, C_RED, CLEAN_COLORS);
        printf("%s(6)%s - %sSair do Menu%s\n", C_YELLOW, CLEAN_COLORS, C_RED, CLEAN_COLORS);
        printf("Digite o Número da Opção Desejada: ");
        scanf("%d", &option);
        if(option == 1) {
            sleep(2);
            printf("Digite o Nome do Novo Ponto de Navegação: ");
            FlushIn();
            scanf("%[^\n]", template_name);

            printf("Digite as Coordenadas X e Y do Novo Ponto de Navegação:\n");
            printf("X: ");
            scanf("%f", &x);
            printf("Y: ");
            scanf("%f", &y);
            template_coordinate = NewCoordinate(x, y);

            printf("Digite a Categoria do Novo Ponto de Navegação: ");
            FlushIn();
            scanf("%[^\n]", template_category);

            sleep(2);
            printf("%s-Novo Ponto de Navegação Adicionado com Sucesso!!!%s\n", C_BLUE, CLEAN_COLORS);
        
            TreeInsertion(&(*top), NewNode(template_name, template_coordinate, template_category));
            sleep(2);
        } else if (option == 2){
            sleep(2);
            printf("Digite o Nome do Ponto de Navegação a Ser Removido: ");
            FlushIn();
            scanf("%[^\n]", template_name);
            template_node = TreeNameSearch(*top, template_name);
            if(template_node == NULL){
                printf("%sPONTO DE NAVEGAÇÃO NÃO ENCONTRADO, RETORNANDO AO MENU...%s\n", C_RED, CLEAN_COLORS);
            } else {
                if(TreeDelete(&(*top), template_node) != NULL){
                    printf("%sPonto de Navegação Removido com Sucesso%s\n", C_GREEN, CLEAN_COLORS);
                }
            }
            sleep(2);
        } else if (option == 3){
            sleep(2);
            printf("Selecione o Primeiro Ponto de Navegação, por Nome: ");
            FlushIn();
            scanf("%[^\n]", template_name);
            template_node = TreeNameSearch(*top, template_name);
            if(template_node == NULL) {
                printf("%sPONTO DE NAVEGAÇÃO NÃO ENCONTRADO, RETORNANDO AO MENU...%s\n", C_RED, CLEAN_COLORS);
            } else {
                printf("Selecione o Segundo Ponto de Navegação, por Nome: ");
                FlushIn();
                scanf("%[^\n]", template_name);
                Node * template_node2 = TreeNameSearch(*top, template_name);
                if(template_node2 == NULL) {
                    printf("%sPONTO DE NAVEGAÇÃO NÃO ENCONTRADO, RETORNANDO AO MENU...%s\n", C_RED, CLEAN_COLORS);
                } else {
                    Coordinate * coordinate1 = template_node->ordered_pair;
                    Coordinate * coordinate2 = template_node2->ordered_pair;
                    float distance = sqrt((double) MyPow(coordinate2->x - coordinate1->x, 2) + MyPow(coordinate2->y - coordinate1->y, 2));
                    printf("%sA Distância Entre os Dois Pontos de Navegação é:%s %.2f%s\n", C_MAGENTA, C_BLUE, distance, CLEAN_COLORS);
                }
            }
            sleep(2);
        } else if (option == 4){
            flag = 0;
            sleep(2);
            printf("Digite as Coordenadas do Ponto Central de Busca Desejado:\n");
            printf("X: ");
            scanf("%f", &x);
            printf("Y: ");
            scanf("%f", &y);
            template_coordinate = NewCoordinate(x, y);
            printf("Digite o Valor do Raio de Busca:\n");
            printf("Raio: ");
            scanf("%f", &radius);
            RadiusDistance(*top, template_coordinate, radius, &flag);
            sleep(2);
            if(flag == 0){
                printf("%sNENHUM PONTO DE NAVEGAÇÃO ENCONTRADO NESSE RAIO DE BUSCA...%s\n", C_RED, CLEAN_COLORS);
                sleep(2);
            }
        } else if (option == 5){
            sleep(2);
            printf("Agora Escolha o Número da Opção com que você Deseja Visualizar os Dados:\n");
            printf("%s(1) - Em Ordem%s\n", C_CYAN, CLEAN_COLORS);
            printf("%s(2) - Pré Ordem%s\n", C_CYAN, CLEAN_COLORS);
            printf("%s(3) - Pós Ordem%s\n", C_CYAN, CLEAN_COLORS);
            printf("Digite o Número da Opção Desejada: ");
            scanf("%d", &option);
            if(option == 1) {
                Display_InOrder(*top);
            } else if (option == 2) {
                Display_PreOrder(*top);
            } else if (option == 3) {
                Display_PostOrder(*top);
            } else {
                printf("%sOPÇÃO NÃO ENCONTRADA, RETORNANDO AO MENU...%s\n", C_RED, CLEAN_COLORS);
            }
            sleep(2);
        } else if (option == 6){
            sleep(2);
            break;    
        } else {
            sleep(2);
            printf("%s!!! OPÇÃO NÃO ENCONTRADA !!!%s\n", C_RED, CLEAN_COLORS);
            sleep(2);
        }
    }
    sleep(2);
    printf("%s--Obrigado por utilizar o nosso Sistema, Volte Sempre!!!%s\n", C_BLUE, CLEAN_COLORS);
}

int main(){
    Node * tree_top = NULL;
    Node * new_leaf = NULL;
    Coordinate * new_coordinate = NULL;

    new_coordinate = NewCoordinate(-5.7, 23.9);
    new_leaf = NewNode("Galo Branco", new_coordinate, "Restaurante");
    TreeInsertion(&tree_top, new_leaf);

    new_coordinate = NewCoordinate(-21, 0);
    new_leaf = NewNode("Alvorada", new_coordinate, "Hotel");
    TreeInsertion(&tree_top, new_leaf);

    new_coordinate = NewCoordinate(-59.1, 3.4);
    new_leaf = NewNode("Jerusalém", new_coordinate, "Hotel");
    TreeInsertion(&tree_top, new_leaf);

    new_coordinate = NewCoordinate(-2.3, 3.5);
    new_leaf = NewNode("Petrobras", new_coordinate, "Posto de Combustível");
    TreeInsertion(&tree_top, new_leaf);

    new_coordinate = NewCoordinate(-5.3, 7.2);
    new_leaf = NewNode("Outback", new_coordinate, "Restaurante");
    TreeInsertion(&tree_top, new_leaf);

    new_coordinate = NewCoordinate(-0.1, 0.1);
    new_leaf = NewNode("Goiânia Sul", new_coordinate, "Posto de Combustível");
    TreeInsertion(&tree_top, new_leaf);

    new_coordinate = NewCoordinate(-4.3, 0.5);
    new_leaf = NewNode("Santos Dumont", new_coordinate, "Hotel");
    TreeInsertion(&tree_top, new_leaf);

    new_coordinate = NewCoordinate(-179, 23.7);
    new_leaf = NewNode("Serra Dourada", new_coordinate, "Estádio");
    TreeInsertion(&tree_top, new_leaf);

    Menu(&tree_top);

    TreeFree(&tree_top);
    return 0;
}