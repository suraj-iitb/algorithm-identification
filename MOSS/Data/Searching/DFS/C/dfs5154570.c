#include <stdio.h>
#include <stdlib.h>

void visit(int);
int **A,n,*d,*f,*color,t=0;
int main(){
  int k,u,v;
  int i,j;

  scanf("%d",&n);
  A=(int**)malloc(sizeof(int*)*(n+1));
  d=(int*)malloc(sizeof(int)*(n+1));
  f=(int*)malloc(sizeof(int)*(n+1));
  color=(int*)malloc(sizeof(int)*(n+1));
  for(i=0;i<=n;i++)  A[i]=(int*)malloc(sizeof(int)*(n+1));
  for(i=1;i<=n;i++){
    color[i]=0;
    for(j=1;j<=n;j++){
      A[i][j]=0;
    }
  }
  
  for(i=1;i<=n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    if(k==0)continue;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      A[u][v]=1;
    }
  }
  for(i=1;i<=n;i++){
    if(color[i]==0) visit(i);
  }
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}

void visit(int u){
  int i;
  color[u]=1;
  d[u] = ++t;
  for(i=1;i<=n;i++){
    if(A[u][i]==1&&color[i]==0)visit(i);
  }
  color[u]=2;
  f[u]=++t;
}
  

