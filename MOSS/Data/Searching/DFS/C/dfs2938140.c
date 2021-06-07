#include <stdio.h>

#define N     100
#define WHITE 0
#define GRAY  1
#define BLACK 2

static int n;
static int M[N][N];
static int color[N];
static int start[N];
static int end[N];
static int t;

static void dfs_visit(int u)
{
    color[u] = GRAY;
    start[u] = ++t;
    for (int v = 0; v < n; v++) {
        if (M[u][v] == 0)
            continue;
        if (color[v] == WHITE)
            dfs_visit(v);
    }
    color[u] = BLACK;
    end[u] = ++t;
}

static void dfs()
{
    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
    }

    t = 0;

    for (int i = 0; i < n; i++) {
        if (color[i] == WHITE) {
            dfs_visit(i);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", i + 1, start[i], end[i]);
    }
}

int main()
{
    int u, v, k;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &u, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &v);
            M[u - 1][v - 1] = 1;
        }
    }

    dfs();

    return 0;
}
