#include <stdio.h>
#define MAX 105
#define WHITE 0
#define GLAY 1
#define BLACK 2
int n,color[MAX],d[MAX],f[MAX],time,A[MAX][MAX];
void visit(int u){
  int v,i;
  color[u]=1;
  d[u]=++time;
  for(v=0;v<n;v++){
    if(A[u][v]==0)continue;
    if(color[v]==0)visit(v);
  }
    color[u]=2;
    f[u]=++time;

  



}
void dfs(void){
  int i;
  for(i=0;i<n;i++){
    color[i]=0;
    time=0;
  }
    for(i=0;i<n;i++){

      if(color[i]==0) visit(i);
}
    for(i=0;i<n;i++){
      printf("%d %d %d\n",i+1,d[i],f[i]);
    }
}


int main(){

  int i,j,u,k,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j]=0;

    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      A[u-1][v-1]=1;
    }
  }

  dfs();

  return 0;
}

