#include<stdio.h>
#define N 100

static const int W=0;
static const int G=1;
static const int B=2;

int n,M[N][N];
int color[N],d[N],f[N],tt=0;

void dfs_visit(int u){
  int v;
  color[u] = G;
  tt++;
  d[u] = tt;
  for (v=0;v<n;v++){
    if(M[u][v] == 0)continue;
    if(color[v] == W){
      dfs_visit(v);
    }
  }
  color[u] = B;
  tt++;
  f[u] = tt;
}

void dfs(){
  int i, u;
  for(i=0;i<n;i++)color[i] = W;
  tt = 0;
  for(u=0;u<n;u++){
    if(color[u] == W)dfs_visit(u);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}


int main(){
  int i,j;
  int u,k,v; 
  
  scanf("%d", &n);
  for (i=0;i<n;i++){
    for(j=0;j<n;j++)M[i][j] = 0;
  }
  
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }
  dfs();
}

