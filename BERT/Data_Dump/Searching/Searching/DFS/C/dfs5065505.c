#include <stdio.h>
#define N 200
#define WHITE 0 //未探索
#define GRAY 1 //頂点発見
#define BLACK 2 //探索終了

int n, time, color[N], G[N][N], d[N], f[N];

void DFS()
{
    int u;
    for(u=1; u<=n; u++)
    {
        color[u] = WHITE;
        time = 0;
    }
    
    for(u=1; u<=n; u++)
    {
        if(color[u] == WHITE)
        {
            DFS_time(u);
        }
    }
}

void DFS_time(int u)
{
    int v;
    color[u] = GRAY;
    d[u] = ++time;
    for(v=1; v<=n; v++)
    {
        if(color[v]==WHITE && G[u][v]==GRAY)
        {
            DFS_time(v);
        }
    }
    color[u] = BLACK;
    f[u] = ++time;
}

int main(void)
{
    int i,j,k,l;
    int Adj[N];
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            G[i][j] = WHITE;
        }
    }
  
    for(i=1;i <= n;i++)
    {
        scanf("%d%d",&k,&l);
        for(j=1;j <= l;j++)
        {
            scanf("%d",&Adj[j]);
            G[k][Adj[j]] = GRAY;
        }
    }
  
    DFS();
    
    for(i=1;i<=n;i++)
    {
        printf("%d %d %d\n",i,d[i],f[i]);
    }
    
    return 0;
}

