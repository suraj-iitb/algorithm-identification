#include<stdio.h>
#define nmax 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs();
void dfvi(int);
 


int n,M[nmax][nmax];
int color[nmax],d[nmax],f[nmax];
int time;

void dfvi(int u){
  int v;
  color[u] = GRAY;
  d[u] = ++time;
  for(v = 0 ; v < n ; v++){
    if(M[u][v] == 0){
      continue;
    }
    if(color[v] == WHITE){
      dfvi(v);
    }
  }
  color[u] = BLACK;
  f[u] = ++time;
}

void dfs(){
  int u;
  for(u = 0 ; u < n ; u++){
    color[u] = WHITE;
  }
  
  time = 0;
  
  for(u = 0 ; u < n ; u++){
    if(color[u] == WHITE){
      dfvi(u);
    }
  }
  for(u = 0 ; u < n ; u++){
    printf("%d %d %d\n",u + 1,d[u],f[u]);
  }
}

int main(){
  int u,v,k;
  int i,j;

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    for(j = 0 ; j < n ; j++){
      M[i][j] = 0;
    }
  }

  for(i = 0 ; i < n ; i++){
    scanf("%d %d",&u,&k);
    u=u-1;
    for(j = 0 ; j < k ; j++){
      scanf("%d",&v);
      v=v-1;
      M[u][v] = 1;
    }
  }
  dfs();

  return 0;
}



