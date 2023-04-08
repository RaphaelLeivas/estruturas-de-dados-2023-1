// alocação dinamica de vetores e matrizes

#include <stdio.h>
#include <stdlib.h>

#define VECTOR_SIZE 10
#define MATRIX_ROWS 3
#define MATRIX_COLUMNS 3

int main()
{
    printf("Hello World\n");
    
    int* vector = malloc(sizeof(int) * VECTOR_SIZE);
    int** matrix = malloc(MATRIX_ROWS * sizeof(int*)); // sizeof int*: é o tamanho dos pointeiros 
    
    for(int i = 0; i < MATRIX_ROWS; i++) matrix[i] = malloc(MATRIX_COLUMNS * sizeof(int));
    
    for (int i = 0; i < MATRIX_ROWS; ++i) {
        for (int j = 0; j < MATRIX_COLUMNS; ++j) {
            matrix[i][j] = i + j;
        }
    }
    
    for (int i = 0; i < VECTOR_SIZE; ++i) {
        printf("%d\n", vector[i]);
    }
    
    for (int i = 0; i < MATRIX_ROWS; ++i) {
        for (int j = 0; j < MATRIX_COLUMNS; ++j) {
           printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    free(matrix);
    free(vector);

    return 0;
}