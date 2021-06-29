#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <stdio.h>

#define printArr(a, n) for(int i=0;i<(n);++i)printf(i==(n)-1?"%d\n":"%d ",(a)[i])

void insertionSort(int *A, const int N) {
    printArr(A, N);
    for(int i = 1; i < N; ++i) {
        int tmp = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > tmp) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = tmp;
        printArr(A, N);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int A[N], B[N];
    for(int i = 0; i < N; ++i) {
        scanf("%d", A + i);
    }
    //memcpy(B, A, sizeof(A));

    // solve
    insertionSort(A, N);

    // definitely right sort
    //std::sort(B, B + N);
    // make sure
    //for(int i = 0; i < N; ++i) {
    //    assert(A[i] == B[i]);
    //}

    return 0;
}

