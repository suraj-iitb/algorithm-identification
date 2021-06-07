#include <stdio.h>

int n,A[100][100],cnt[100],d[100],f[100],t=0;

void dfs(int);

int main(){
  int u,v,k,i,j;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    cnt[i]=0;
    for(j=0;j<n;j++){
      A[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      A[u][v]=1;
    }
  }

  for(i=0;i<n;i++){
    if(cnt[i]==0){
      dfs(i);
    }
  }

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
}

void dfs(int u){
  int v;
  
  cnt[u]=1;
  d[u]=++t;
  for(v=0;v<n;v++){
    if(A[u][v]==0){
      continue;
    }
    if(cnt[v]==0){
      dfs(v);
    }
  }
  cnt[u]=2;
  f[u]=++t;
  
}

