#include <stdio.h>
#include <stdlib.h>

void DisplayArray(int A[], int N)
{
    int i;
    for (i = 0; i < N; i++) {
        if (i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void InsertionSort(int A[], int N)
{
    int v, i, j;
    for (i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        DisplayArray(A, N);
    }
}

int main(void)
{
    int N, i;
    scanf("%d%*c", &N);
    int* A = (int*)malloc(sizeof(int) * N);

    for (i = 0; i < N; i++) scanf("%d", &A[i]);
    scanf("%*c");

    DisplayArray(A, N);
    InsertionSort(A, N);

    return 0;
}
