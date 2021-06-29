#include<stdio.h>
int G[105][105],d[105],f[105],color[105],n,time=0;
void visit(int u){
    //printf("%d\n",u);
    int i=1;

    color[u]=1;
    d[u]=++time;
    while(G[u][i]!=-1){
        if(color[G[u][i]]==0){
            visit(G[u][i]);
        }
        i++;
    }
    color[u]=2;
    f[u]=++time;
}

int main(){
    int k,i,j,unuse;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d %d",&unuse,&k);
        for(j=1; j<=k; j++){
            scanf("%d",&G[i][j]);
        }
        G[i][j]=-1;
    }

    for(i=0; i<n; i++){
        color[i]=0;
    }

    for(i=1; i<=n; i++){
        if(color[i]==0){
            visit(i);
        }
    }

    for(i=1; i<=n; i++){
        printf("%d %d %d\n",i,d[i],f[i]);
    }



    return 0;
}
