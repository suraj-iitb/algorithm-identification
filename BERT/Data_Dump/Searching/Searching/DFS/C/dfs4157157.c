#include<stdio.h>

void dfs_init(int);
void dfs(int,int);

int a[100][100],c[100],d[100],f[100],t;

int main(){
  int n,u,k,v,i,j;

  scanf("%d",&n);

  for(i=0;i<=n-1;i++){
    for(j=0;j<=n-1;j++){
      a[i][j]=0;
    }
  }
  
  for(j=0;j<=n-1;j++){
    scanf("%d%d",&u,&k);
    u--;
    for(i=0;i<=k-1;i++){
      scanf("%d",&v);
      v--;
      a[u][v]=1;
    }
  }
  dfs_init(n);
  return 0;
}

  void  dfs_init(int n){
    int i;

    for(i=0;i<=n-1;i++){
      c[i]=-1;
      t=0;
    }

    for(i=0;i<=n-1;i++){
      if(c[i]==-1)dfs(i,n);
    }

    for(i=0;i<=n-1;i++){
      printf("%d %d %d\n",i+1,d[i],f[i]);
    }
  }

  void dfs(int u,int n){
    int i;
    c[u]=0;
    d[u]=++t;
    for(i=0;i<=n-1;i++){
      if(a[u][i]&&c[i]==-1)dfs(i,n);
    }
    c[u]=1;
    f[u]=++t;
  }



















