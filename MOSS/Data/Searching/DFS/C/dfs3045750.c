#include <stdio.h>
#define n_max 101

int n,time=0;
int adj[n_max][n_max];
int used[n_max];
int f[n_max],d[n_max];

void dfs(int x){
  int i;
  
  for(i=1;i<=n;i++){
    if(adj[x][i]==1 && used[i]==0){
      used[i]=1;
      time++;
      d[i]=time;
      dfs(i);
    }
  }  
  f[x]=++time;  
}

int main(){
  int i,j,u,k,num;
  
  scanf("%d",&n);//ヴァーテックスの数
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);//頂点のナンバーと、その頂点からのびる線の数
    for(j=0;j<k;j++){
      scanf("%d",&num);
      adj[u][num]=1;
    }
  }
  
  for(i=1;i<=n;i++){
    if(used[i]==0){
      d[i]=++time;
      used[i]=1;
      dfs(i);
    }
  }
  for(i=1;i<=n;i++)printf("%d %d %d\n",i,d[i],f[i]);
  return 0;
}

