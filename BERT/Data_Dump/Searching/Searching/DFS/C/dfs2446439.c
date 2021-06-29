#include <stdio.h>
#define MAX 100
int n,G[MAX][MAX],d[MAX],f[MAX]={0},Time=0;
void Visit(int);

int main(){
    int i,j,u,k,v;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        d[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            G[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        scanf("%d%d",&u,&k);
        for(j=0;j<k;j++){
            scanf("%d",&v);
            G[u-1][v-1]=1;
        }
    }
    for(i=0;i<n;i++){
        if(d[i]==0) Visit(i);
    }
    for(i=0;i<n;i++){
        printf("%d %d %d\n",i+1,d[i],f[i]);
    }
    return 0;
}
void Visit(int u){
    int i,j,p;
    Time++;
    d[u]=Time;
    for(p=0;p<n;p++){
        if(d[p]==0 && G[u][p]==1) Visit(p);
    }
    Time++;
    f[u]=Time;
}
