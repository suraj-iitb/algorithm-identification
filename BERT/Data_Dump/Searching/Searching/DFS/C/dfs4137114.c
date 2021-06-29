#include<stdio.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs_init(int,int,int*,int*,int*);
void dfs(int,int,int*,int*,int*);

int M[N][N];
int time;

int main(void){
  int n,maxval=0,color[N],d[N],f[N];
  int u,k,v;
  int i,j;

  scanf(" %d",&n);

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      M[i][j] = 0;
    }
  }
  
  for(i = 0; i < n; i++){
    scanf(" %d",&u);
    if(u-1 > maxval) maxval = u-1;
    scanf(" %d",&k);
    for(j = 0; j < k; j++){
      scanf(" %d",&v);
      if(v-1 > maxval) maxval = v-1;
      M[u-1][v-1] = 1;
    }
  }

  dfs_init(n,maxval,color,d,f);

  for(i = 0; i < n; i++){
    if(d[i] != 0){
      printf("%d %d %d\n",i+1,d[i],f[i]);
    }
  }
  
  
  return 0;
}

void dfs_init(int n, int maxval, int *color, int *d, int *f){
  int i;
  for(i = 0; i < n; i++){
    color[i] = WHITE;
  }
  for(i = 0; i < n; i++){
    d[i] = f[i] = 0;
  }

  time = 0;
  
  for(i = 0; i < n; i++){
    if(color[i] == WHITE) dfs(i,maxval,color,d,f);
  }
}

void dfs(int u, int maxval, int *color, int *d, int *f){
  int i,v;
  
  color[u] = GRAY;
  d[u] = ++time;
  for(v = 0; v <= maxval; v++){
    if(M[u][v] && color[v] == WHITE){
      dfs(v,maxval,color,d,f);
    }
  }
  color[u] = BLACK;
  f[u] = ++time;
}

