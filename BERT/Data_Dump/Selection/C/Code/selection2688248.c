///
#include <stdio.h>
#include <math.h>
///
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)
///
typedef long long ll;
///
#define INF 1145141919

///
void swap(int *a, int *b) {
    int t = *b;
    *b = *a;
    *a = t;
}


int selectionSort(int *A, int N) {
    int cnt = 0;
    REP(i, N) {
        int minj = i;
        FOR(j, i, N) {
            if (A[j] < A[minj])
                minj = j;
        }
        if (A[i] != A[minj])cnt++;
        swap(&A[i], &A[minj]);
    }
    return cnt;
}

int N;
int A[10000];

void solver() {
    scanf("%d", &N);
    REP(i, N) scanf("%d", &A[i]);

    int ans = selectionSort(A, N);
    REP(i, N - 1) printf("%d ", A[i]);
    printf("%d\n", A[N - 1]);
    printf("%d\n", ans);
}


int main() {
    solver();
    return 0;
}
