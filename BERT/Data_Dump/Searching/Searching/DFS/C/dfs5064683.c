#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[N][N];
int color[N], d[N], f[N], t;

void depth_visit(int u)
{
    int v;
    color[u] = GRAY;
    d[u] = ++t;

    for (v = 0; v < n; v++)
    {
        if (M[u][v] == 0)
        {
            continue;
        }
        if (color[v] == WHITE)
        {
            depth_visit(v);
        }
    }
    color[u] = BLACK;
    f[u] = ++t;
}

void depth()
{
    int u;

    for (u = 0; u < n; u++)
    {
        color[u] = WHITE;
    }
    t = 0;

    for (u = 0; u < n; u++)
    {
        if (color[u] == WHITE)
        {
            depth_visit(u);
        }
    }
    for (u = 0; u < n; u++)
    {
        printf("%d %d %d\n", u + 1, d[u], f[u]);
    }
}

int main(void)
{
    int u, v, k;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M[i][j] = 0;
        }
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

    depth();

    return 0;
}

