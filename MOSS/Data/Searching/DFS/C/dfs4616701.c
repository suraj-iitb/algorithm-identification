#include <stdio.h>
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int t = 0;
int d[N], f[N];
int D[N][N], n;
int v;
int color[N];

void dfs(void);
void visit(int);

int main()
{
    int i, j;
    int u, k, v;

    scanf("%d", &n);

    //入力
    for (i = 1; i <= n; i++)
    {
        scanf("%d%d", &u, &k);
        for (j = 1; j <= k; j++)
        {
            scanf("%d", &v);
            D[i][v] = BLACK;
        }
    }
    //
    /*
    for(j=0;j<n;j++)
     color[j]= WHITE;
     t=0;
     
     for(u=0;u<n;u++){
       if(color[u] == WHITE)dfs(u);
     }
 */
    dfs();

    //出力
    for (i = 1; i <= n; i++)
    {
        printf("%d %d %d\n", i, d[i], f[i]);
    }

    return 0;
}

void dfs(void)
{ // int G
    //for each vertex u in V
    int i;
    int u;

    for (u = 1; u <= n; u++)
    {
        color[u] = WHITE;
    }

    t = 0;
    for (u = 1; u <= n; u++)
    {
        if (color[u] == WHITE)
            visit(u);
    }
}

void visit(int u)
{
    int i;
    int v;
    color[u] = GRAY;
    d[u] = ++t;
    //for each v in Adj[u]

    for (v = 1; v <= n; v++)
    {
        if (color[v] == WHITE && D[u][v] == BLACK)
            visit(v);
    }
    color[u] = BLACK;
    f[u] = ++t; //visit終了
}

