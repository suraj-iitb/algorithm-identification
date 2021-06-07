#include<stdio.h>

#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs();
void visit(int );

int n,time;
int color[N],d[N],f[N],G[N][N];

int main(){
int i,j;
int u,k,v;

scanf("%d",&n);

for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        G[i][j]=0;
    }
}

for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=1;j<=k;j++){
        scanf("%d",&v);
        G[u][v]=1;
    }
}

dfs();

for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
}

return 0;

}

void dfs(){
    int i;

    for(i=1;i<=n;i++) color[i]=0;

    time=0;

    for(i=1;i<=n;i++){
        if(color[i]==0) visit(i);
    }

}

void visit(int u){
    int i;

    color[u]=1;

    d[u]=++time;

    for(i=1;i<=n;i++){
        if(G[u][i]==0) continue;
        if(color[i]==0) visit(i);
    }

    color[u]=2;
    f[u]=++time;

}
