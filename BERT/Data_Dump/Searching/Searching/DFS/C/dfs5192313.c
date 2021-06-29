#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int m[101][101]={0};
int d[101],f[101];
int color[101]={WHITE};

int n,time=0;

void visit(int u){
    color[u] = GRAY;
    d[u] = ++time;
    for(int v=1;v<=n;v++){
        if(m[u][v]==0) continue;
        if(color[v] == WHITE) visit(v);
    }
    color[u] = BLACK;
    f[u]=++time;
}

void dfs(){
    time = 0;
    for(int i=1; i<=n; i++){
        if(color[i]==WHITE) visit(i);
    }
}

int main(){
    
    int u,k,v;

    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        scanf("%d%d",&u,&k);
        if(k!=0){
            for(int j=1; j<=k; j++){
                scanf("%d",&v);
                m[u][v]++;
            }
        }
    }

    dfs();

    for(int i=1; i<=n; i++){
        printf("%d %d %d\n",i,d[i],f[i]);
    }

}
