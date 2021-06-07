#include <stdio.h>
#define N 101
#define W 0
#define Gl 1
#define B 2
void DFS_V(int);
int V;
int time;
int color[N];
int G[N][N];
int d[N];
int f[N];



 int main(){
  int i;
  int j;
  int k;
  int l;
  int u;
  int A[N];


  scanf("%d",&V);
  for(i=1;i <= V;i++) {
    for(j=1;j <= V;j++){
      G[i][j] = W;
    }
  }
   
  for(i=1;i <= V;i++){
    scanf("%d%d",&k,&l);
    for(j=1;j <= l;j++){
      scanf("%d",&A[j]);
      G[k][A[j]] = Gl;
    }
  }
   

  for(u=1;u <= V;u++){
    color[u] = W;
    time = 0;
  }
  for(u=1;u <= V;u++){
    if(color[u] == W){
      DFS_V(u);
    }
  }
  for(i=1;i<=V;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}
 
 
void DFS_V(int u){
  int v;
  color[u] = Gl; // White vertex u has just been discovered
  d[u] = ++time;
  for(v=1;v<= V ;v++){ // Explore edge (u,v)
    if(color[v] == W && G[u][v] == Gl){
      DFS_V(v);
    }
  }
  color[u] = B; // Blacken u; it is finished
  f[u] = ++time;
   
}
