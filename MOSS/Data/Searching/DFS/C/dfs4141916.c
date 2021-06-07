#include <stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[100][100];
int color[100];
int time;
int d[100], f[100];

void visit(int u)
{
    int v;

    color[u] = GRAY;
    d[u] = ++time;
    for (v = 0; v < n; v++)
    {
        if (M[u][v] == 0)
            continue;
        if (color[v] == WHITE)
            visit(v);
    }
    color[u] = BLACK;
    f[u] = ++time;
}

void dfs()
{
    int u;

    for (u = 0; u < n; u++)
        {
            color[u] = WHITE;
        }
    time = 0;

    for (u = 0; u < n; u++)
    {
        if (color[u] == WHITE)
            visit(u);
    }
}

int main()
{
    int u, v, k;
    int i, j;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                    {
                        M[i][j] = 0;
                    }
        }

    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &u, &k);
        for (j = 0; j < k; j++)
        {
            scanf("%d", &v);
            M[u - 1][v - 1] = 1;
        }
    }

    dfs();
    for (i = 0; i < n; i++)
        printf("%d %d %d\n", i + 1, d[i], f[i]);

    return 0;
}

