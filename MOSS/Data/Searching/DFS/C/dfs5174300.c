#include<stdio.h>
#define MAX 100

int n,m[MAX][MAX];
int flag[MAX],d[MAX],f[MAX],t;
void dfs_go(int);
void dfs(void);

void dfs_go(int u){
    int v;
    flag[u]=1;
    d[u]=++t;
    for(v=0;v<n;v++){
        if(m[u][v]==0) continue;
        if(flag[v]==0) dfs_go(v);
    }
    flag[u]=2;
    f[u]=++t;
}
void dfs(void){
    int u;
    for(u=0;u<n;u++) flag[u]=0;
    t=0;
    for(u=0;u<n;u++) if(flag[u]==0) dfs_go(u);
    for(u=0;u<n;u++) printf("%d %d %d\n",u+1,d[u],f[u]);
}
int main(){
    int u,v,k,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) m[i][j]=0;
    }
    for(i=0;i<n;i++){
        scanf("%d %d ",&u,&k);
        u--;
        for(j=0;j<k;j++){
            scanf("%d",&v);
            v--;
            m[u][v]=1;
        }
    }
    dfs();
    return 0;
}
