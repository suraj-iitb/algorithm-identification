#include <stdio.h>
#define REP(i, n) for ((i)=0; (i)<(n); (i)++)

int linearSearch(int key, int *a, int n) {
    int i = 0;
    a[n] = key;
    while (a[i] != key) i++;
    return i != n;
}

int main(void) {
    int n, q, i, T;
    int ans = 0;
    scanf("%d", &n);
    int A[n+1];

    REP(i, n) scanf("%d", &A[i]);

    scanf("%d", &q);

    REP(i, q) {
        scanf("%d", &T);
        ans += linearSearch(T, A, n);
    }
    printf("%d\n", ans);
}
