#include <stdio.h>
#define N 100

int M[N][N];
int color[N],d[N],f[N],tt;

void dfs_visit(int u,int n){
    int v;
    color[u] = 1;
    d[u] = ++tt;
    for(v=0;v<n;v++){
        if(M[u][v] == 0) continue;
        if(color[v] == 0){
            dfs_visit(v,n);
        }
    }
    color[u] = 2;
    f[u] = ++tt;
}

void dfs(int n){
    int u;
    for(u=0;u<n;u++) color[u] = 0;
    tt = 0;
    for(u=0;u<n;u++) if(color[u] == 0) dfs_visit(u,n);
    for(u=0;u<n;u++) printf("%d %d %d\n",u+1,d[u],f[u]);
}

int main(void){
    int n,u,v,k,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            M[i][j] = 0;
        }
    }
    for(i=0;i<n;i++){
        scanf("%d %d",&u,&k);
        u--;
        for(j=0;j<k;j++){
            scanf("%d",&v);
            v--;
            M[u][v]=1;
        }
    }
    dfs(n);
    
    return 0;
}

