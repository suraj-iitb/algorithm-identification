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

void bubbleSort(int *A, int N)
{
    int i, j, v, flag, num = 0;
    
    flag = 1;
    while (flag) {
        flag = 0;
        for (i = N - 1; i > 0; i--) {
            if (A[i] < A[i - 1]) {
                swap(&A[i], &A[i - 1]);
                num++;
                flag = 1;
            }
        }
    }

    printLine(A, N);
    printf("%d\n", num);
}

int main()
{
    int N;
    int A[100] = {0};
    int i;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    bubbleSort(A, N);

    return 0;
}
