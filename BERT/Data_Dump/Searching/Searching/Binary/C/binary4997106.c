#include <stdio.h>
int n, q, max, min, mid, idct, count = 0, ans;
int main() {
    scanf("%d", &n);
    int s[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    scanf("%d", &q);
    int t[q + 1];
    for (int i = 0; i < q; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < q; i++) {
        min = 0;
        max = n - 1;
        ans = t[i];
        idct = 0;
        while (idct == 0 && min <= max) {
            mid = (min + max) / 2;
            if (s[mid] > ans) {
                max = mid - 1;
            } else if (s[mid] < ans) {
                min = mid + 1;
            } else {
                idct = 1;
                count++;
            }
        }
    }
    printf("%d\n", count);
}
