#include<stdio.h>
#define N 100
#define W 0
#define G 1
#define B 2

int A[N][N],color[N],d[N],f[N];
int n,time = 0;

void dfs(int u){
  int v;
  color[u] = G;
  d[u] = ++time;
  for(v = 0; v < n; v++){
    if(A[u][v] == W) continue;
    if(color[v] == W) dfs(v);
  }
  color[u] = B;
  f[u] = ++time;
}

void dfs_init(){
  int i;
  for(i = 0; i < n; i++){
    color[i] = W;
  }
}


int main(){
  int i,j,a,b,c;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      A[i][j] = 0;
    }
  }
  for(i = 0; i < n; i++){
     scanf("%d%d",&a,&b);
     a--;
     for(j = 0; j < b; j++){
       scanf("%d",&c);
       c--;
       A[a][c] = 1;
     }
   }
  dfs_init();
  dfs(0);
  for(i = 0; i < n; i++){
    if(color[i] == W) dfs(i);
    printf("%d %d %d\n",i + 1,d[i],f[i]);
  }
  
  return 0;
}

