#include <stdio.h>
#include <stdlib.h>
int main() {
    int i, j, rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int **A, **B, **sum, **sub;
    A = (int **)malloc(rows * sizeof(int *));
    B = (int **)malloc(rows * sizeof(int *));
    sum = (int **)malloc(rows * sizeof(int *));
    sub = (int **)malloc(rows * sizeof(int *));
    for(i = 0; i < rows; i++) {
        A[i] = (int *)malloc(cols * sizeof(int));
        B[i] = (int *)malloc(cols * sizeof(int));
        sum[i] = (int *)malloc(cols * sizeof(int));
        sub[i] = (int *)malloc(cols * sizeof(int));    }
    printf("Enter elements of Matrix A:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            sum[i][j] = A[i][j] + B[i][j];
            sub[i][j] = A[i][j] - B[i][j];
        }
    }
    printf("\nMatrix Addition:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix Subtraction:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", sub[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < rows; i++) {
        free(A[i]);
        free(B[i]);
        free(sum[i]);
        free(sub[i]);
    }
    free(A);
    free(B);
    free(sum);
    free(sub);

    return 0;
}
