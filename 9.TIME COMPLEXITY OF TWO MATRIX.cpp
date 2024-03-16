#include <stdio.h>

#define MAX_SIZE 10

void multiplyMatrix(int firstMatrix[MAX_SIZE][MAX_SIZE], int secondMatrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowFirst, int colFirst, int rowSecond, int colSecond) {
    int i, j, k;

    for (i = 0; i < rowFirst; ++i) {
        for (j = 0; j < colSecond; ++j) {
            result[i][j] = 0;
        }
    }

    for (i = 0; i < rowFirst; ++i) {
        for (j = 0; j < colSecond; ++j) {
            for (k = 0; k < colFirst; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

int main() {
    int rowFirst, colFirst, rowSecond, colSecond;

    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &rowFirst, &colFirst);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &rowSecond, &colSecond);

    if (colFirst != rowSecond) {
        printf("Error! The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 1;
    }

    int firstMatrix[MAX_SIZE][MAX_SIZE], secondMatrix[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < rowFirst; ++i)
        for (int j = 0; j < colFirst; ++j)
            scanf("%d", &firstMatrix[i][j]);

    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < rowSecond; ++i)
        for (int j = 0; j < colSecond; ++j)
            scanf("%d", &secondMatrix[i][j]);

    multiplyMatrix(firstMatrix, secondMatrix, result, rowFirst, colFirst, rowSecond, colSecond);

    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < colSecond; ++j)
            printf("%d ", result[i][j]);
        printf("\n");
    }

    return 0;
}

