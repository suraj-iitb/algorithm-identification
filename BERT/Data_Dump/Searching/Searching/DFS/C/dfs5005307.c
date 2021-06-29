#include <stdio.h>
#define N 100
#define WHITE 0 // 未探索
#define GRAY 1 // 発見済み
#define BLACK 2 // 探索済み

int n, M[N][N], tt;
int d[N], f[N];
char color[N];

void dfs_visit(int u) {
    int i;
    color[u] = GRAY;
    d[u] = ++tt;

    for (i = 0; i < n; i++) {
        if (M[u][i] && color[i] == WHITE) dfs_visit(i);
    }
    color[u] = BLACK;
    f[u] = ++tt;
}

void dfs() {
    // init
    int i;
    for (i = 0; i < n; i++) color[i] = WHITE;
    tt = 0;
    
    for (i = 0; i < n; i++) {
        if (color[i] == WHITE) dfs_visit(i);
    }
}


int main(void) {
    int i, j, u, k, m;
    scanf("%d", &n);
    for (i = 0; i < n; i++) { // 隣接行列化
        scanf("%d%d", &u, &k);
        u--; // 1 スタートの配列に変換
        for (j = 0; j < k; j++) {
            scanf("%d", &m);
            m--;
            M[u][m] = 1;
        }
    }

    dfs();
    
    for (i = 0; i < n; i++) {
        printf("%d %d %d\n", i + 1, d[i], f[i]);
    }

    return 0;
}

