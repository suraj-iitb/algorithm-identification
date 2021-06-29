#include <stdio.h>
#define WHITE 0
#define GLAY 1
#define BLACK 2

int n, G[100][100];
int c[100], d[100], f[100];
int t;

void visit(int u)
{
    int v;
    c[u] = GLAY;
    d[u] = ++t;
    
    for(v=0; v<n; v++){
        if(G[u][v] == 0)
            continue;
        if(c[v] == WHITE){
            visit(v);
        }
    }
    c[u] = BLACK;
    f[u] = ++t;
}

void dfs()
{
    int u;
    
    for(u=0; u<n; u++)
    c[u] = WHITE;
    t = 0;
    
    for(u=0; u<n; u++){
        if(c[u] == WHITE)
            visit(u);
    }
}

int main()
{
    int i, j;
    int u, k, v;
    
    scanf("%d", &n);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            G[i][j] = 0;
        }
    }
    
    for(i=0; i<n; i++){
        scanf("%d %d", &u, &k);
        for(j=0; j<k; j++){
            scanf("%d", &v);
            G[u-1][v-1] = 1;
        }
    }
    dfs();
    
    for( u=0; u<n; u++ )
    printf("%d %d %d\n", u+1, d[u], f[u]);
    
    return 0;
}


