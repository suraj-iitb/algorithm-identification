#include<stdio.h>
void dfs();
void visit(int);
int n,a[100][100],t,d[100],f[100],col[100];
int main(){
  int u,k,v,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++)for(j=0;j<n;j++)a[i][j]=0;
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      a[u][v]=1;
    }
  }
  dfs();
  for(i=0;i<n;i++)printf("%d %d %d\n",i+1,d[i],f[i]);
  return 0;
}
void dfs(){
  int i;
  for(i=0;i<n;i++)col[i]=0;
  t=0;
  for(i=0;i<n;i++)if(col[i]==0)visit(i);
}
void visit(int u){
  int i;
  col[u]=1;
  d[u]=++t;
  for(i=0;i<n;i++){
    if(a[u][i]==0)continue;
    if(col[i]==0)visit(i);
  }
  col[u]=2;
  f[u]=++t;
}
