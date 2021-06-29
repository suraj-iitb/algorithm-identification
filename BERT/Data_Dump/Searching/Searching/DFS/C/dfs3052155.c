#include<stdio.h>

#define N 501

static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n,A[N][N],C[N],d[N],f[N],tt;

void dfs_a(int u){

  int v;
  
  C[u] = GRAY;

  tt++;

  d[u] = tt;

  for(v=0;v<n;v++){
    
    if(A[u][v] == 0){
      continue;
    }
    
    if(C[v] == WHITE){
      dfs_a(v);
    }

  }

  C[u] = BLACK;

  f[u] = ++tt;

}

void dfs_b(){

  int i,u;
  
  for(i=0;i<n;i++){
    C[i] = WHITE;
  }
  
  tt = 0;

  for(u=0;u<n;u++){
    
    if(C[u] == WHITE){
      dfs_a(u);
    }
  }
  
  for(i=0;i<n;i++){
    
    printf("%d %d %d\n",i+1,d[i],f[i]);
    
  }
}


int main(){

  int i,j,u,k,v;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    
    scanf("%d%d",&u,&k);

    u--;

    for(j=0;j<k;j++){
      
      scanf("%d",&v);
      
      v--;

      A[u][v] = 1;

    }
  }

  dfs_b();

  return 0;
}

