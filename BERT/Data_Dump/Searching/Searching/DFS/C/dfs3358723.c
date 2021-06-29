#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, time;
int color[N], d[N], f[N];
int M[N][N];


void dfs()
{

  int u;
  
  for(u=0;u<n;u++){
    color[u] =  WHITE;
  }
  
  time = 0;
  
  for(u=0;u<n;u++){
    if(color[u] == WHITE){
      visit(u);
    }
  }

}


void visit(int u)
{
  
  int v;
  
  color[u] = GRAY; // White vertex u has just been discovered
  d[u] = ++time;
  
  for(v=0;v<n;v++){ // Explore edge (u,v)
    if(M[u][v] == 0){
      continue;
    }
    if(color[v] == WHITE){
      visit(v);
    }
  }
  
  color[u] = BLACK; // Blacken u; it is finished
  f[u] = ++time;

}


int main()
{

  int u, v, k, i, j;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }
  
  dfs();

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
  
}
  

