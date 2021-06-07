#include <stdio.h>

#define LEN 100000

int n;
int S[LEN];

int binarySearch(int target) {
    int left = 0;
    int right = n;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (target == S[mid]) return 1;
        if (target > S[mid]) left = mid + 1;
        if (target < S[mid]) right = mid;
    }

    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &S[i]);

    int q;
    scanf("%d", &q);

    int k;
    int cnt = 0;
    for (int i = 0; i < q; i++) {
        scanf("%d", &k);
        if (binarySearch(k)) cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}

