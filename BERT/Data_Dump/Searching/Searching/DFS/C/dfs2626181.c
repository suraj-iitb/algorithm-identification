#include<stdio.h>

int n, M[100][100];
int color[100], d[100], f[100], tt;

void dfs_visit(int u) {
    int v;
    color[u] = 1;
    d[u] = ++tt;
    for ( v = 0; v < n; v++ ) {
        if ( M[u][v] == 0 ) continue;
        if ( color[v] == 0 ) dfs_visit(v);
    }
    color[u] = 2;
    f[u] = ++tt;
}

void dfs() {
    int u;
    for ( u = 0; u < n; u++ ) color[u] = 0;
    tt = 0;
    for ( u = 0; u < n; u++ ) if ( color[u] == 0 ) dfs_visit(u);
    for ( u = 0; u < n; u++ ) printf("%d %d %d\n", u + 1, d[u], f[u]);
}

int main(void) {
    int i, j, k, a, b;
    scanf("%d", &n);
    for ( a = 0; a < n; a++ ) {
        for ( b = 0; b < n; b++ ) M[a][b] = 0; 
    }

    for ( a = 0; a < n; a++ ) {
        scanf("%d %d", &i, &k);
        i--;
        for ( b = 0; b < k; b++ ) {
            scanf("%d", &j);
            j--;
            M[i][j] = 1;
        }
    }

    dfs();

    return 0;
}
