#include<stdio.h>

int g[102][102];
int d[102],f[102];
int t=0,n;

int dfs(int x){
  t++;
  int i;
  for(i=1;i<=n;i++){
    if(d[x]==0)
      d[x] = t;
    if(g[x][i]==1 && f[i]==0){
      g[x][i]=0;
      if(d[i]==0){
	dfs(i);
	t++;
      }
    }
    if(i==n && f[x]==0){
      f[x] = t+1;
    }
  }
  return 0;
}

int main(){
  scanf("%d", &n);
  int i,j;
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      g[i][j] = 0;
    }
    d[i]=0;
    f[i]=0;
  }

  int u,k;
  for(i=0;i<n;i++){
    scanf("%d %d", &u,&k);
    for(j=0;j<k;j++){
      int v;
      scanf("%d", &v);
      g[u][v] = 1;
    }
  }

  for(i=1;i<=n;i++){
    if(f[i]==0){
      dfs(i);
      t++;
    }
  }
  for(i=1;i<=n;i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }
  return 0;
}
