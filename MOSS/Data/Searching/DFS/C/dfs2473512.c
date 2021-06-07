#include<stdio.h>
 
#define MAX 101
#define WHITE -1
#define GRAY 0
#define BLACK 1
 
int n,t;
int color[MAX],d[MAX],f[MAX],Adj[MAX][MAX];
 
dfs(){
  int i;
 
  for(i=0;i<n;i++) color[i]=WHITE;
  t=0;
  for(i=0;i<n;i++){
    if(color[i]==WHITE) visit(i);
  }
}
 
visit(int r){
  int i;
 
  color[r]=GRAY;
  d[r]=++t;
 
  for(i=0;i<n;i++){
    if(Adj[r][i]==1 && color[i]==WHITE) visit(i);
  }
 
  color[r]=BLACK;
  f[r]=++t;
}
 
int main(){
  int i,u,k,j,v;
 
  for(i=0;i<MAX;i++){
    for(j=0;j<MAX;j++){ 
      Adj[i][j]=0;
    }
  }
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      Adj[u-1][v-1]=1;
    }
  }
 
  dfs();
 
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
 
  return 0;
}
