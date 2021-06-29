#include <stdio.h>

void printLine(int *A, int N)
{
    int i;

    for (i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int selectionSort(int *A, int N)
{
    int minj;
    int sw = 0;
    for (int i = 0; i < N - 1; i++) {
        minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(&A[i], &A[minj]);
            sw++;
        }
    }
    return sw;
}

int main()
{
    int N, A[100], sw;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    sw = selectionSort(A, N);
    printLine(A, N);
    printf("%d\n", sw);

    return 0;
}
