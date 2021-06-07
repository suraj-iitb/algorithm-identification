#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[N][N];
int color[N], d[N], f[N], tt;

void dfs_visit(int i)
{
    color[i] = GRAY;
    d[i] = ++tt;
    for (int j = 0; j < n; j++)
    {
        if (M[i][j] == 0)
            continue;
        if (color[j] == WHITE)
            dfs_visit(j);
    }
    color[i] = BLACK;
    f[i] = ++tt;
}

void dfs()
{
    for (int i = 0; i < n; i++)
        color[i] = WHITE;
    tt = 0;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == WHITE)
            dfs_visit(i);
    }

    for (int i = 0; i < n; i++)
        printf("%d %d %d\n", i + 1, d[i], f[i]);
}

int main()
{
    int u, v, k;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            M[i][j] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &u, &k);
        u--;
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &v);
            v--;
            M[u][v] = 1;
        }
    }

    dfs();
    return 0;
}
