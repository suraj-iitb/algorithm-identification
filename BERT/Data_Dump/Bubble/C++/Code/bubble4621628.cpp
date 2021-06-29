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

int bubbleSort(int *A, int N)
{
    int sw = 0;
    int flag = 1;
    for (int i = 0; flag; i++) {
        flag = 0;
        for (int j = N - 1; j > i; j--) {
            if (A[j - 1] > A[j]) {
                swap(&A[j], &A[j - 1]);
                sw++;
                flag = 1;
            }
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

    sw = bubbleSort(A, N);
    printLine(A, N);
    printf("%d\n", sw);

    return 0;
}
