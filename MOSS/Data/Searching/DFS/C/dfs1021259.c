#include<stdio.h>
 
#define N 200
#define BLACK 2
#define WHITE 0
#define GRAY  1
 
int n = 0;
int z = 0;
int G[N][N];
int d[N];
int f[N];
int color[N];

void DFSvisit(int);
void DFS();
   
main(){
  int i,j,s,v,r;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      G[i][j] = 0;
    }
  }
  for(i = 0; i < n; i++){
    scanf("%d%d", &v,&r);
    for(j = 0; j < r; j++){
      scanf("%d",&s);
      G[i][s - 1] = 1;
    }
  }
  DFS();
  for(i = 0; i < n; i++){
    printf("%d %d %d\n",i+1, d[i], f[i]);
  }
  return 0;
}

void DFSvisit(int u){
  int t;
  color[u] = GRAY;
  d[u] = ++z;
  for(t = 0; t < n; t++){
    if(G[u][t] == 1 && color[t] == WHITE){
      DFSvisit(t);
    }
  }
  color[u] = BLACK;
  f[u] = ++z;
}

void DFS(){
  int u,z = 0;
  for(u = 0; u < n; u++){
    color[u] = WHITE;
  }
  for(u = 0; u < n; u++){
    if(color[u] == WHITE){
      DFSvisit(u);
     }
  }
}  
