#include<stdio.h>

#define WHITE 0
#define GLAY 1
#define BLACK 2
#define MAX 101
#define TRUE 1
#define FALSE 0

int n;
int color[MAX];
int d[MAX];
int f[MAX];
int G[MAX][MAX];
int time_dfs = 0;

void dfs();
void search(int);

int main(){
  int i,j,id,k,v;

  scanf("%d",&n);

  for(i = 1; i <= n; i++)color[i] = WHITE;

  for(i = 1; i <= n; i++){
    scanf("%d %d", &id, &k);
    for(j = 1; j <= k; j++ ){
      scanf("%d",&v);
      G[id][v] = TRUE;
    }
  }
  dfs(1);
  
  for(i = 1; i <= n; i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
 
  
  return  0;
}

void dfs(){
  int u_i;

  for(u_i = 1; u_i <= n; u_i++){
    if(color[u_i] == WHITE)search(u_i);
  }

  return;
}

void search(int id){
  int v;
  
  color[id] = GLAY;
  d[id] = ++time_dfs;
  for(v = 1; v <= n; v++){
    if(G[id][v] == FALSE)continue;
    if(color[v] == WHITE){
      search(v);
    }
   }
  color[id] = BLACK;
  f[id] = ++time_dfs;
}
