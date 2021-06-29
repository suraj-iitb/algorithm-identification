#include <stdio.h>
#define rep(i,n) for(int (i) = 0; (i) < (n); ++ (i) )

void printArray(int A[] , int N) {
    rep(i,N-1)
        printf("%d ", A[i]);
    printf("%d\n", A[N-1]);
}

void insertionSort(int A[], int N) {
    int ins,cmp;
    for(ins = 1; ins < N; ins++) {
        int value = A[ins];
        for(cmp = ins -1; cmp >= 0 && A[cmp] > value ;cmp--) {
            A[cmp+1] = A[cmp];
        }
        A[cmp+1] = value;
        printArray(A, N);
    }
}

int main(void) {
    int A[100];
    int N;
    
    scanf("%d", &N);
    rep(i,N)
        scanf("%d", &A[i]);
    printArray(A, N);
    insertionSort(A, N);
    return 0;
}
