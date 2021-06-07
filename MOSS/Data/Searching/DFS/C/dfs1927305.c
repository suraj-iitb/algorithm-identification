#include<stdio.h>
int n,t,A[101][101],d[101],f[101],C[101];
   
void DFS(int u)
{
  int i;
  C[u]=1;
  d[u]=++t;
  for(i=0;i<n;i++){
    if(A[u][i]==1){
      if(C[i]==0)DFS(i);
    }
  }
  C[u]=2;
  f[u]=++t;
}
  
int main()
{
  int i,j,k,v,w;
   
  scanf("%d",&n);
  for(i=0;i<n;i++){
    C[i]=0;
    for(j=0;j<n;j++){
      A[i][j]=0;
    }
  }
  t=0;
  for(i=0;i<n;i++){
    scanf("%d%d",&v,&k);
    for(j=0;j<k;j++){
      scanf("%d",&w);
      A[v-1][w-1]=1;
    }
  }
  for(i=0;i<n;i++){
    if(C[i]==0)DFS(i);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}
