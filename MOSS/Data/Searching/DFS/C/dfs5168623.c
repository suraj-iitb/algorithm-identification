#include <stdio.h>

#define nMAX 100
#define BLACK 2
#define WHITE 0
#define GRAY 1
#define INCLUDE 3
#define NINCLUDE -3

void dfs(void);
void visit(int r);

int t, color[nMAX + 1], d[nMAX + 1], f[nMAX + 1];
int n, G[nMAX + 1][nMAX + 1];

int main (){

  int  i, j, u, k, v;

  scanf("%d", &n);

  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      G[i][j] = NINCLUDE;
    }
  }

  for(i = 1; i <= n; i++){
    scanf("%d", &u);
    scanf("%d", &k);
    if(k !=0){
    for(j = 1; j <= k; j++){
      scanf("%d", &v);
      G[u][v] = INCLUDE;
      }
    }
  }

  dfs();
 
  for(i = 1; i <= n; i++) 
    printf("%d %d %d\n", i , d[i], f[i]);
  
  return 0;
}

void dfs(void){

  int i;

  for(i = 1; i <= n; i++)
    color[i] = WHITE;

  t = 0;
  
  for(i = 1; i <= n; i++){
    if(color[i] == WHITE)
      visit(i);
  }
}

void visit(int r){

  int i;
  color[r] = GRAY;
  d[r] = ++t;
  for(i = 1; i <= n; i++){
    if(G[r][i] == NINCLUDE) continue;
    if(color[i] == WHITE)
      visit(i);
  }
  color[r] = BLACK;
  f[r] = ++t;
}

