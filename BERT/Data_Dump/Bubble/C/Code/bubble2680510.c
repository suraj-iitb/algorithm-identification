#include <stdio.h>
#include <math.h>

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

typedef long long ll;

#define INF 1145141919
#define size (int)1e+5

int arr[size];

int Min(int a, int b) {
    return a > b ? b : a;
}

int Max(int a, int b) {
    return a > b ? a : b;
}

int Swap(int *a, int *b) {
    int t = *b;
    *b = *a;
    *a = t;
}

bubbleSort(int *A, int N) {
    int cnt = 0;
    int flag = 1;
    while (flag != 0) {
        flag = 0;
        for (int i = N - 1; i >= 1; i--) {
            if (A[i] < A[i - 1]) {
                Swap(&A[i], &A[i - 1]);
                cnt++;
                flag = 1;
            }
        }
    }
    for (int i = 0; i < N - 1; ++i) {
        printf("%d ", arr[i]);
    }
    printf("%d\n%d\n", arr[N - 1], cnt);
}

void solver() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    bubbleSort(&arr,N);
}


int main() {
    solver();
    return 0;
}
