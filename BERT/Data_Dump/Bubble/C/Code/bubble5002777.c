#include <stdio.h>

int a[105];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                a[j] ^= a[j + 1] ^= a[j] ^= a[j + 1];
                ans++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i == n - 1) printf("\n");
        else printf(" ");
    }
    printf("%d\n", ans);
}
