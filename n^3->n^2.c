#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int N; 
    int** A; 
    int** B; 
};

struct Matrix* initMatrix(int N) {
    struct Matrix* mat = malloc(sizeof(struct Matrix));
    mat->N = N;
    mat->A = malloc(N * sizeof(int*));
    mat->B = malloc(N * sizeof(int*));
    
    for (int i = 0; i < N; i++) {
        mat->A[i] = malloc(N * sizeof(int));
        mat->B[i] = malloc(N * sizeof(int));
    }
    return mat;
}

void updateAndBuildMatrix(struct Matrix* mat, int M) {
    for (int i = 0; i < M; i++) {
        int R1, R2, C1, C2, V;
        scanf("%d %d %d %d %d", &R1, &R2, &C1, &C2, &V);
        mat->B[R1 - 1][C1 - 1] += V;
        if (R2 < mat->N)
            mat->B[R2][C1 - 1] -= V;
        if (C2 < mat->N)
            mat->B[R1 - 1][C2] -= V;
        if (R2 < mat->N && C2 < mat->N)
            mat->B[R2][C2] += V;
    }

    for (int i = 0; i < mat->N; i++) {
        for (int j = 0; j < mat->N; j++) {
            mat->A[i][j] = mat->B[i][j];
            if (i > 0)
                mat->A[i][j] += mat->A[i - 1][j];
            if (j > 0)
                mat->A[i][j] += mat->A[i][j - 1];
            if (i > 0 && j > 0)
                mat->A[i][j] -= mat->A[i - 1][j - 1];
        }
    }
}

int main() {
    int size;
    scanf("%d", &size);
    int N = size;
    struct Matrix* mat = initMatrix(N);

    updateAndBuildMatrix(mat, size);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat->A[i][j]);
        }
        printf("\n");
    }

    free(mat);
    return 0;
}
