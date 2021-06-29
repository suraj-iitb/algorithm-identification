#include <stdio.h>

#define arr_print_d0dn(a, n) for(int i=0;i<(n);++i)printf(i==(n)-1?"%d\n":"%d ",(a)[i])

void insertionSort(int *A, const int N) {
    arr_print_d0dn(A, N);
    for(int i = 1; i < N; ++i) {
        int tmp = A[i];
        int j = i - 1;
        // rotate right to left
        while(j >= 0 && A[j] > tmp) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = tmp;
        arr_print_d0dn(A, N);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for(int i = 0; i < N; ++i) {
        scanf("%d", A + i);
    }
    // solve
    insertionSort(A, N);

    return 0;
}

