#include<stdio.h>
int G[101][101],n,m=1,stump[101][2];
int DFS(int);
int main(void)
{
    int k,v,u,i,j;
    scanf("%d", &n);
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++) G[i][j]=0;
        stump[i][0]=0;
        stump[i][1]=0;
    }
    for(i=0;i<n;i++){
        scanf("%d", &u);
        scanf("%d", &k);
        for(j=0;j<k;j++){
            scanf("%d", &v);
            G[u][v] = 1;
        }
    }
    DFS(1);
    for(i=1;i<=n;i++){
        if(stump[i][0]==0) DFS(i);
    }
    for(i=1;i<=n;i++) printf("%d %d %d\n", i, stump[i][0], stump[i][1]);
    return 0;
}
int DFS(int num)
{
    int l;
    if(stump[num][0]==0){
        stump[num][0]=m;
        m++;
    }
    for(l=0;l<=n;l++){
        if(G[num][l]==1&&stump[l][0]==0) DFS(l);
    }
    if(stump[num][1]==0){
        stump[num][1]=m;
        m++;
    }
    return 0;
}
