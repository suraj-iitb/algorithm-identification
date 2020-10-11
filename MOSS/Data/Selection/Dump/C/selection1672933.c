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

int SelectionSort(int A[], int N)
{
    int i, j, minj, tmp, count = 0;

    for (i = 0; i < N; i++) {
        minj = i;
        for (j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) count++;
        tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
    }

    return count;
}

int main(void)
{
    int N, i, numOfExchanges;
    scanf("%d%*c", &N);
    int* A = (int*)malloc(sizeof(int) * N);

    for (i = 0; i < N; i++) scanf("%d", &A[i]);
    scanf("%*c");

    numOfExchanges = SelectionSort(A, N);
    DisplayArray(A, N);
    printf("%d\n", numOfExchanges);

    return 0;
}
