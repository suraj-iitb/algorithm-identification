#include<stdio.h>
#include<stdlib.h>

#define WHITE -1
#define GRAY -2
#define BLACK -3
#define END -100

int* adlist [105];
int d[105];
int f[105];
int color[105];
int TIME = 0;

void dfs(int);
void visit(int);

int main(){
  int i ,j, n, vernum, degree, p;

  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    scanf("%d%d", &vernum, &degree);

    adlist[vernum] = malloc(sizeof(int)*(degree+1));
    for(j = 0; j < degree; j++){
      scanf("%d", &adlist[vernum][j]);
    }
    adlist[vernum][degree] = END;
  }
  /*
  for(i = 1; i <= n; i++){
    for(j = 0; adlist[i][j] != END; j++){
      printf("adlist[%d][%d] = %d ", i, j, adlist[i][j]);
    }
    printf("\n");
  }
  */
  
  dfs(n);

  for(i = 1; i <= n; i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }
  
  
  return 0;
}

void dfs(int n){
  int u;
  for(u = 1; u <= n; u++){
    color[u] = WHITE;
  }
  TIME = 0;
  for(u = 1; u <= n; u++){
    if(color[u] == WHITE){
      visit(u);
    }
  }
}

void visit(int u){
  int v, node;
  color[u] = GRAY;
  TIME = TIME + 1;
  d[u] = TIME;
  for(v = 0; adlist[u][v] != END; v++){
    node = adlist[u][v];
    if(color[node] == WHITE){
      visit(node);
    }
  }
  color[u] = BLACK;
  TIME = TIME + 1;
  f[u] = TIME;
}

