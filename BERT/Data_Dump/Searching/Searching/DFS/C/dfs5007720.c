#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int time = 1;
int n;

void dfs(int u, int G[n + 1][n + 1], int d[], int f[], int cond[])
{
    cond[u] = 1;
    d[u] = time++;
    for (int i = 1; i <= n; i++)
    {
        if (G[u][i] == 1 && cond[i] == 0)
        {
            dfs(i, G, d, f, cond);
        }
    }

    cond[u] = 2;
    f[u] = time++;
}

int main(void)
{

    scanf("%d", &n);

    int G[n + 1][n + 1];
    int d[n + 1], f[n + 1], cond[n + 1];

    for (int i = 1; i <= n; i++)
    {
        f[i] = 0;
        d[i] = 0;
        cond[i] = 0;
        for (int j = 1; j <= n; j++)
        {
            G[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int u, k;
        scanf("%d %d", &u, &k);

        for (int j = 1; j <= k; j++)
        {
            int v;
            scanf("%d", &v);
            G[i][v] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (cond[i] == 0)
            dfs(i, G, d, f, cond);
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d %d %d\n", i, d[i], f[i]);
    }

    return 0;
}
