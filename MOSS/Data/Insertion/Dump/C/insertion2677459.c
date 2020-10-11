#include <stdio.h>

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

int N;
int A[1000];

int show(int *A, int N) {
    REP(i, N - 1)printf("%d ", A[i]);
    printf("%d\n", A[N - 1]);
}

int insertionSort(int *A, int N) {
    show(A,N);
    FOR(i, 1, N) {
        int v = A[i];
        int j = i - 1;
        while (0 <= j && v < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        show(A, N);
    }
}

void solver() {
    scanf("%d", &N);
    REP(i, N)scanf("%d", &A[i]);
    insertionSort(A, N);
}

int main() {
    solver();
    return 0;
}
