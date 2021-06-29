#include<stdio.h>
#define N 100

int M[N][N], color[N], d[N], f[N], tt=0;


void dfs(int u, int n){
    int v;
    color[u]=1;
    d[u]=++tt;
    for(v=0; v<n; v++)
    {
        if(M[u][v]==0){}
        else if(color[v]==0)
        {
            dfs(v, n);
        }
    }
    color[u]=2;
    f[u]=++tt;
}
int main(void)
{
    int n,i,j;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            M[i][j]=0;
        }
    }

    int u, k, v;
    for(i=0; i<n; i++)
    {
        
        scanf("%d", &u);
        u--;
        scanf("%d", &k);
        for(j=0; j<k; j++)
        {
            scanf("%d", &v);
            v--;
            M[u][v]=1;
        }
    }
    for(i=0; i<n; i++)
    {
        color[i]=0;
    }
    for(u=0; u<n; u++)
    {
        if(color[u]==0)
        {
            dfs(u, n);
        }
    }
    for(u=0; u<n; u++)
    {
        printf("%d %d %d\n", u+1, d[u], f[u]);
    }
    return 0;
}
