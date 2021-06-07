#include<stdio.h>
#include<stdlib.h>
#define N 100
#define white 0
#define black 2
#define gray 1

int A[N][N],color[N],d[N],f[N];
int t;

void visit(int u,int n){
  int i;
  color[u] = gray;
  d[u] = ++t;
  for(i=0;i<n;i++){
    if(A[u][i] == 0){
      continue;
    }
    if(color[i] == white){
      visit(i,n);
    }
  }
  color[u] = black;
  f[u] = ++t;
}

void dfs(int n){
  int u;
  for(u=0;u<n;u++){
    color[u] = white;
  }
  t = 0;
  for(u=0;u<n;u++){
    if(color[u] == white){
      visit(u,n);
    }
  }
}

int main(){
  int n,i,u,k,j,v;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j] = 0;
    }
  }
  
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      A[u][v] = 1;
    }
  }

  dfs(n);

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
}
  
  

