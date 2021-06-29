#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 101

int n,time;
int color[N],d[N]={},f[N]={};
int G[N][N]={};

void visit(int u){
    int v;
    color[u]=GRAY;
    d[u]=++time;
    for(v=0;v<n;v++){
        if(G[u][v]==0)continue;
        if(color[v]==WHITE)visit(v);
    }
    color[u]=BLACK;
    f[u]=++time;
}

void dfs(void){
    int u;
    for(u=0;u<n;u++)color[u]=WHITE;
    time=0;
    for(u=0;u<n;u++){
        if(color[u]==WHITE)visit(u);
    }
}

int main(){
    int id,num,a,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&id,&num);
        for(j=0;j<num;j++){
            scanf("%d",&a);
            G[i][a-1]=1;
        }
    }
    dfs();
    for(i=0;i<n;i++){
        printf("%d %d %d\n",i+1,d[i],f[i]);
    }
    return 0;
}

