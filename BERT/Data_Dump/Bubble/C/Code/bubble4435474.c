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

void bubbleSort(int A[], int N)
{
    int flag;
    int j;

    flag = 1;
    while(flag) {
        flag = 0;
        for(j = N-1; j >= 1; j--) {
            if(A[j] < A[j-1]) {
                swap(&A[j], &A[j-1]);
                flag = 1;
            }
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
    bubbleSort(A, N);

    for(i = 0; i < N-1; i++) {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[N-1]);
    printf("%d\n", count);


    return 0;
}
