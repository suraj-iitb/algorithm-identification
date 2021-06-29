#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *arr, int len, int target) {
    int i;
    for (i = 0; i < len; i++) {
        if (arr[i] == target) {
            return 1;
        }
    }
    return 0;
}

int main() {

    int i, n, q, ans;
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
        if (linearSearch(S, n, T[i])) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}

