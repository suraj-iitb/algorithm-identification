#include<stdio.h>
#define M 100
int a[M][M],c[M],d[M],f[M];
int n,t=1;

void vis(int i){
  int j;
  c[i]=1;
  d[i]=t++;
  for(j=0;j<n;j++){
    if(a[i][j]==0)continue;
    if(c[j]==0)vis(j);
  }
  c[i]=2;
  f[i]=t++;
}
void dfs(int i){
  if(c[i]==0)vis(i);
}
int main(){
  int i,j,u,k,v;
  for(i=0;i<=M;i++){
    for(j=0;j<=M;j++){
      a[i][j]=0;
    }
  }
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      a[u][v]=1;
    }
  }
  for(i=0;i<n;i++)c[i]=0;
  for(i=0;i<n;i++)dfs(i);
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}
