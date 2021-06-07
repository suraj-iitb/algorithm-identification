#include <stdio.h>
#define N 100
#define NOT_VISITED 0
#define SEMI_VISITED 1
#define VISITED 2

int n, M[N][N];
int status[N], d[N], f[N], tt;

void dfs_visit(int u) {
    int v;
    status[u] = SEMI_VISITED;
    d[u] = ++tt;
    for (v = 0; v < n; v++) {
        if (M[u][v] == 0) continue;
        if (status[v] == NOT_VISITED) {
            dfs_visit(v);
        }
    }
    status[u] = VISITED;
    f[u] = ++tt;
}

void dfs() {
    int u;
    for (u = 0; u < n; u++) status[u] = NOT_VISITED;
    tt = 0;

    for (u = 0; u < n; u++) {
        if (status[u] == NOT_VISITED) dfs_visit(u);
    }
    for (u = 0; u < n; u++) {
        printf("%d %d %d\n", u + 1, d[u], f[u]);
    }    
}

int main(void)
{
    int u, v, k, i, j;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) M[i][j] = 0;
    }

    for (i = 0; i < n; i++) {
        scanf("%d %d", &u, &k);
        u--;
        for (j = 0; j < k; j++) {
            scanf("%d", &v);
            v--;
            M[u][v] = 1;
        }
    }
    
    dfs();

    return 0;
}
