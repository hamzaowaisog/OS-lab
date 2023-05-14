#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrixAddition(int matrixA[][10], int matrixB[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

int main() {
    int rows = 10;
    int cols = 10;

    int matrixA[10][10];
    int matrixB[10][10];
    int result[10][10];

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrixA[i][j] = rand() % 100;
            matrixB[i][j] = rand() % 100;
        }
    }

    clock_t start, end;
    double cpu_time_used;
    start = clock();
    matrixAddition(matrixA, matrixB, result, rows, cols);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Matrix addition without OpenMP\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    printf("Time: %f seconds\n", cpu_time_used);

  
    start = clock();
    #pragma omp parallel for
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nMatrix addition with OpenMP\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    printf("Time: %f seconds\n", cpu_time_used);

    return 0;
}

