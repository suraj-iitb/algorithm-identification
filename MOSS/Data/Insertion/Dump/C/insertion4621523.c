#include <stdio.h>

void printLine(int *A, int N)
{
    int i;

    for (i = 0; i < N; i++) {
        if (i == N-1) {
            printf("%d", A[i]);
            break;
        }
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int N)
{
    int i, j, v;
    
    for (i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        
        printLine(A, N);
    }
}

int main()
{
    int N;
    int A[1000] = {0};
    int i;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    printLine(A, N);
    insertionSort(A, N);

    return 0;
}
