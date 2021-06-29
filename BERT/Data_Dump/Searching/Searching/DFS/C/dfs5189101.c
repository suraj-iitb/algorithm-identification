#include <stdio.h>
#define N 100

int n,M[N][N],c[N],d[N],f[N],t;
void dfs_visit(int);
void dfs();

int main(){
    int u,v,k,i,j;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) M[i][j]=0;
    }

    for(i=0;i<n;i++){
        scanf("%d%d",&u,&k);
        u--;
        for(j=0;j<k;j++){
            scanf("%d",&v);
            v--;
            M[u][v]=1;
        }
    }

    dfs();

    return 0;
}

void dfs_visit(int u){
    int v;
    c[u]=1;
    d[u]=++t;
    for(v=0;v<n;v++){
        if(M[u][v]==0) continue;
        if(c[v]==0){
            dfs_visit(v);
        }
    }
    c[u]=2;
    f[u]=++t;
}

void dfs(){
    int u;
    for(u=0;u<n;u++) c[u]=0;
    t=0;

    for(u=0;u<n;u++){
        if(c[u]==0) dfs_visit(u);
    }
    for(u=0;u<n;u++){
        printf("%d %d %d\n",u+1,d[u],f[u]);
    }
}
