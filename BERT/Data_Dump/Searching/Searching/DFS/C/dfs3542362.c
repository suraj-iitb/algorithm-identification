#include <stdio.h>

int adja[101][101];
int d[101], f[101], cnt;

void dfs(int u) {
    d[u] = ++cnt;
    for (int i = 0, v; (v = adja[u][i]) > 0; ++i) {
        if (d[v] > 0)
            continue;
        dfs(v);
    }
    f[u] = ++cnt;
}

int main() {
    int n, k, u;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &u, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &adja[u][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 0)
            dfs(i);
        printf("%d %d %d\n", i, d[i], f[i]);
    }

    return 0;
}
