#include <stdio.h>
int n,G[100][100],d[100],T=0,f[100]={0};
void visit(int);
  
int main()
{
  int a,i,j,k,l,m;
 
  for(i=0;i<n;i++){
    d[i]=0;
  }
    scanf("%d",&n);
  
  for(i=0;i<n+1;i++){
    for(j=0;j<n+1;j++) {
      G[i][j] = 0;
    }
  }
 
  for(i=0;i<n;i++){
    scanf("%d%d",&k,&m);
    for(j=0;j<m;j++) {
      scanf("%d",&a);
      G[k-1][a-1]=1;
    }
  }
  for(i=0;i<n;i++){
    if(d[i]==0) 
      visit(i);
  } 
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}
void visit(int u) {
  int i,j,v;
  T++;  
  d[u]=T;
  for(v=0;v<n;v++){
    if(G[u][v]==1&&d[v]==0){
      visit(v);
    }
  }
  T++;
  f[u]=T;
}
 
