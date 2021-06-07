#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int len, int key) {
    int left = 0;
    int right = len;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] == key) {
            return 1;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return 0;
}

int main() {

    int n, i, q, ans;
    scanf("%d", &n);
    
    int S[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    int T[q];
    for (i = 0; i < q; i++) {
        scanf("%d", &T[i]);
    }

    ans = 0;
    for (i = 0; i < q; i++) {
        if (binarySearch(S, n, T[i])) {
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}

