#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int n;

int head = 0, tail = 0;
int Q[1000000];

void enqueue(int q)
{
    Q[tail] = q;
    tail++;
}

int dequeue()
{
    int tmp = Q[head];
    head++;
    return tmp;
}

void bfs(int G[n + 1][n + 1], int d[])
{
    enqueue(1);

    while (head != tail)
    {
        int u = dequeue();

        for (int i = 1; i <= n; i++)
        {
            if (G[u][i] == 1 && d[i] == -1)
            {
                d[i] = d[u] + 1;
                enqueue(i);
            }
        }
    }
}

int main(void)
{

    scanf("%d", &n);

    int G[n + 1][n + 1];
    int d[n + 1];

    for (int i = 1; i <= n; i++)
    {
        d[i] = -1;
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

    d[1] = 0;

    bfs(G, d);

    for (int i = 1; i <= n; i++)
    {
        printf("%d %d\n", i, d[i]);
    }

    return 0;
}
