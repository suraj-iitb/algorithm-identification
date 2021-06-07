#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int a[101][101],d[101],f[101],n,t,color[101];
void dfs_visit(int i){
  int j;
  color[i]=GRAY;
  d[i]=++t;
  for(j=1;j<=n;j++){
    if(a[i][j]==0)continue;
    if(color[j]==WHITE){
      dfs_visit(j);
    }
  }
  color[i]=BLACK;
  f[i]=++t;
}

void dfs(){
  int i;
  t=0;
  for(i=1;i<=n;i++){
    color[i]=WHITE;
  }
  for(i=1;i<=n;i++){
    if(color[i]==WHITE){
      dfs_visit(i);
    }
  }
}

int main(){
  int u,k,l,i,j;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      a[i][j]=0;
      d[i]=-1;
      f[i]=-1;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&l);
      a[u][l]=1;
    }
  }
  dfs();
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }

  return 0;
}

