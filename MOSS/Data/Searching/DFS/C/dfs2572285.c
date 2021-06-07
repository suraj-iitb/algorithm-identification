/*
 * Problem Description: Depth First Search
 * Category: Graph
 * Author: Khan
 * Date: 18th October, 2017
 */

#include <stdio.h>
#include <string.h>

#define MAXN 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[MAXN][MAXN];
int color[MAXN], d[MAXN], f[MAXN], tt;

void dfs_visit(int u)
{
    color[u] = GRAY;
    d[u] = ++tt;
    for (int i = 0; i < n; ++i)
    {
        if(M[u][i] == 0)
            continue;
        if(color[i] == WHITE)
            dfs_visit(i);
    }
    color[u] = BLACK;
    f[u] = ++tt;
}

void dfs()
{
    for (int i = 0; i < n; ++i)
        color[i] = WHITE;
    tt = 0;
    for (int i = 0; i < n; ++i)
        if(color[i] == WHITE)
            dfs_visit(i);
    for (int i = 0; i < n; ++i)
        printf("%d %d %d\n", i + 1, d[i], f[i]);
}

int main(int argc, char const *argv[])
{
    //freopen("sample.txt", "r", stdin);
    int t;
    memset(M, 0, sizeof(M));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &t, &t);
        int tmp;
        for (int j = 0; j < t; ++j)
        {
            scanf("%d", &tmp);
            M[i][tmp - 1] = 1;
        }
    }
    dfs();
    return 0;
}
