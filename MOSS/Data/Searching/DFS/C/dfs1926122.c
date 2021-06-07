#include <stdio.h>
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,a[N][N];
int color[N],d[N],f[N],tt;
void dfs(void);
void visit(int);

int main(){
    int i,j,k,l,m;
    
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++) a[N][N] = 0;
    }
    
    for(i=1; i<=n; i++){
        scanf("%d%d", &k,&l);
        for(j=0; j<l; j++){
            scanf("%d",&m);
            a[k][m] = 1;
        }
    }
    
    dfs();
    
    return 0;
}

void dfs(){
    int u;
    for(u=1; u<=n; u++){
        color[u] = WHITE;
    }
    tt = 0;
    
    for(u=1; u<=n; u++){
        if(color[u] == WHITE) visit(u);
    }
    for(u=1; u<=n; u++){
        printf("%d %d %d\n",u,d[u],f[u]);
    }
}

void visit(int u){
    int v;
    color[u] = GRAY;
    d[u] = ++tt;
    for(v=1; v<=n; v++){
        if(a[u][v] == 0) continue;
        if(color[v] == WHITE){
            visit(v);
        }
    }
    color[u] = BLACK;
    f[u] = ++tt;
}
