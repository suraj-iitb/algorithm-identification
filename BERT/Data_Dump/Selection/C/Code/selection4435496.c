#include <stdio.h>
#include <stdlib.h>

int count;

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;

    count += 1;
}

void selectionSort(int A[], int N)
{
    int i;
    int j;
    int minj;

    for(i = 0; i < N; i++) {
        minj = i;
        for(j = i; j < N; j++) {
            if(A[j] < A[minj]) {
                minj = j;
            }
        }
        if(i != minj) {
            swap(&A[i], &A[minj]);
        }
    }
}

int main()
{
    int N;
    int *A;
    int i;

    scanf("%d", &N);
    A = (int *)malloc(sizeof(int) * N);
    for(i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    count = 0;
    selectionSort(A, N);

    for(i = 0; i < N-1; i++) {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[N-1]);
    printf("%d\n", count);

    return 0;
}
