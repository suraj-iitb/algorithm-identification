#include<stdio.h>
#include<string.h>

int n,a[110][110],vis[110],d[110],f[110],tag=0;
void dfs(int x){
    int u,v,stack[110],top=0;
    top++;
    stack[top]=x;
    vis[x]=1;
    tag++;
    d[x]=tag;
    while(top){
        u=stack[top];
        for(v=1;v<=n;v++)
            if(vis[v]==0){
                if(a[u][v]){
                    top++;
                    stack[top]=v;
                    vis[v]=1;
                    tag++;
                    d[v]=tag;
                    break;
                }
            }
        if(v==n+1){
            tag++;
            f[u]=tag;
            top--;
        }
    }
}
int main(){
    int u,k,v,i,j;
    memset(a,0,sizeof(a));
    memset(vis,0,sizeof(vis));
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d%d",&u,&k);
        for(j=1; j<=k;j++){
            scanf("%d",&v);
            a[u][v]=1;
        }
    }
    for(i=1; i<=n; i++)
        if(vis[i]==0)
            dfs(i);
    for(i=1; i<=n; i++)
        printf("%d %d %d\n",i,d[i],f[i]);
    return 0;
}
