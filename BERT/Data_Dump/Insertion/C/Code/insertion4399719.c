#include <stdio.h>

void printArray(int A[], int N)
{
    int i;
    for(i = 0; i < N-1; i++) {
        printf("%d ", A[i]);
    }
    if(N >= 1) {
        printf("%d\n", A[i]);
    }
}

void insertionSort(int A[], int N)
{
    int i;
    int v;
    int j;
    for(i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        printArray(&A[0], N);
    }
}

int main()
{
    int N;
    int i;
    int A[1000];

    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    printArray(&A[0], N);
    insertionSort(&(A[0]), N);

    return 0;
}
