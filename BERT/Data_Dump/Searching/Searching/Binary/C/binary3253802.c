#include <stdio.h>

// nは配列の要素数
int binarySearch(int A[], int n, int key) {
    int left = 0;
    int right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (A[mid] == key) {
            return 1;
        } else if (key < A[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return 0;
}

int main(void) {
    int n, q, i, key;
    int cnt = 0;
    int S[100000];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", S + i);
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &key);
        if (binarySearch(S, n, key)) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}

