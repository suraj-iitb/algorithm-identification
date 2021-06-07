#include<stdio.h>
#define MAX 150
int graph[MAX][MAX];
int d[MAX],f[MAX];
int time=0,n;

void dfs(i){
  int j;
  time++;
  d[i]=time;
  for(j=0;j<n;j++){
    if(graph[i][j]!=0 && d[j]==0){
      dfs(j);
    }
  }
  time++;
  f[i]=time;
}

int main(){
  int u,k,v;
  int i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      graph[u-1][v-1]=1;
    }
  }
  for(i=0;i<n;i++){
    if(d[i]==0) dfs(i);
  }

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}

