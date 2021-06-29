#include <stdio.h>
int time[101][2]={},g[101][101]={},n,cnt=1;
int flag[101]={};
void dfs(int);
int main(){
    int i,j,q,p,tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&q,&p);
        for(j=0;j<p;j++){
            scanf("%d",&tmp);
            g[q][tmp]=1;
        }
    }
    for(i=1;i<=n;i++){
        if(time[i][0]==0){
            dfs(i);
        }
    }
    for(i=1;i<=n;i++){
        printf("%d %d %d\n",i,time[i][0],time[i][1]);
    }
    return 0;
}
void dfs(int x){
    int i;
    if(time[x][0]==0){
        time[x][0]=cnt;
        cnt++;
    }
    for(i=1;i<=n;i++){
        if(g[x][i]!=0 && flag[i]==0){
            flag[x]=1;
            dfs(i);
        }
    }
    if(time[x][1]==0){
        time[x][1]=cnt;
        cnt++;
    }
}
