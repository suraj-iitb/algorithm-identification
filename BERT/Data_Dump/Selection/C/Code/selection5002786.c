#include <stdio.h>

const int INF = 0x3f3f3f3f;
int a[105];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int mn = INF, p;
        for (int j = i; j < n; j++)
            if (a[j] < mn)
                mn = a[j], p = j;
        if (p != i) a[p] ^= a[i] ^= a[p] ^= a[i], ans++;
    }
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i == n - 1) printf("\n");
        else printf(" ");
    }
    printf("%d\n", ans);
}
