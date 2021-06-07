#include <stdio.h>

int binarySearch(int key, int *a, int left, int right) {
    if (right < left) return 0;
    int mid = (left + right) / 2;
    if (a[mid] == key) return 1;
    else if (a[mid] > key) return binarySearch(key, a, left, mid-1);
    else return binarySearch(key, a, mid+1, right);
}

int main(void) {
    int n, q, i, T;
    int ans = 0;
    scanf("%d", &n);
    int A[n+1];

    for (i = 1; i <= n; i++) scanf("%d", &A[i]);

    scanf("%d", &q);

    for (i = 0; i < q; i++) {
        scanf("%d", &T);
        ans += binarySearch(T, A, 1, n);
    }
    printf("%d\n", ans);
}
