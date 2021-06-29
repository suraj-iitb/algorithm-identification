#include <stdio.h>
#include <stdbool.h>:
typedef long long ll;

const ll b1 = 1048577, p1 = 1e6 + 7, b2 = 998244353, p2 = 995731;
int c1[1000010], c2[1000010];

int main() {
    int n, q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        c1[x * b1 % p1] = 1;
        c2[x * b2 % p2] = 1;
    }
    scanf("%d", &q);
    int ans = 0;
    while (q--) {
        int x; scanf("%d", &x);
        if (c1[x * b1 % p1] && c2[x * b2 % p2]) ans++;
    }
    printf("%d\n", ans);
}
