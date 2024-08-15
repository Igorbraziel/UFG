#include <stdio.h>
#include <stdlib.h>

// HEAP //

void ShowVector(int * vector, int current_size){
    int i;
    for(i = 0; i < current_size; i++){
        printf("%d\n", vector[i]);
    }
}

void Insertion(int * vector, int * current_size, int value) {
    if((*current_size) == 0) {
        vector[0] = value;
        *current_size += 1;
    } else {
        int i, j, temporary1, temporary2;
        vector = (int *) realloc(vector, ((*current_size) + 1) * sizeof(int));
        for(i = 0; i < *current_size; i++){
            if(value > vector[i]) {
                temporary1 = vector[i];
                for(j = i; j < *current_size; j++){
                    temporary2 = vector[j + 1];
                    vector[j + 1] = temporary1;
                    temporary1 = temporary2;
                }
                vector[i] = value;
                *current_size += 1;
                return;
            }
        }
        vector[i] = value;
        *current_size += 1;
    }   
}


int main(){
    int * vector = (int *) malloc(1 * sizeof(int));
    int current_size = 0;
    Insertion(vector, &current_size, 3);
    Insertion(vector, &current_size, 5);
    Insertion(vector, &current_size, 1);
    Insertion(vector, &current_size, 77);
    Insertion(vector, &current_size, 49);
    Insertion(vector, &current_size, 88);
    Insertion(vector, &current_size, 100);
    Insertion(vector, &current_size, 3);
    Insertion(vector, &current_size, -1);
    Insertion(vector, &current_size, 32);
    ShowVector(vector, current_size);

    free(vector);
    return 0;
}