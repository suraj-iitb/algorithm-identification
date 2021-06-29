#include <stdio.h>
#define N 100
#define WHITE 0
#define BLACK 1
#define GRAY 2

int n,A[N][N],d[N],f[N],color[N],t=0;

 void DFSvisit(int u){
  int v;

  color[u]=GRAY;
  t++;
  d[u] = t;

  for(v=0;v<n;v++){
    if(A[u][v]==1 && color[v]==WHITE)   DFSvisit(v);
  }
  color[u] = BLACK;
  f[u] = ++t;

  return;
}


int main(){
  int i,j,u,v,k;

 
  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      A[u-1][v-1] = 1;
    }
  }

  for(i=0;i<n;i++){
    color[i]=WHITE;
  }

  for(i=0;i<n;i++){
    if(color[i]==WHITE)    DFSvisit(i);
  }

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
}
