#include <stdio.h>

int rep = 0;

void selectionSort(int *A, int N) {
    int i, j, minj, temp;
    for (i = 0; i < N-1; i++) {
        minj = i;

        for (j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (A[i] != A[minj])    rep++;

        temp = A[i];
        A[i] = A[minj];
        A[minj] = temp;
    }
}

int main(void) {
    int i, N;
    int A[100] = {0};

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    selectionSort(A, N);

    for (i = 0; i < N; i++) {
        printf("%d", A[i]);
        
        if (i != N-1) {
            printf(" ");
        }
    }
    printf("\n");

    printf("%d\n", rep);

    return 0;
}
