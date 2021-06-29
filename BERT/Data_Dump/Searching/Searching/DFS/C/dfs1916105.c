#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int d;
  int f;
}timestamp;

typedef struct{
  int u;
  int k;
  int *v;
}graph;

void dfs(int);
void visit(int);

graph g[110];
timestamp t[110];
int mytime = 0;


int main(void){
  int i,j,n;

  scanf("%d", &n);


  for(i = 0; i <= n; i++)
    t[i].d = t[i].f = 0;

  for(i = 1; i <= n; i++){
    scanf("%d%d", &g[i].u, &g[i].k);
    g[i].v = (int *)malloc(sizeof(int) * (g[i].k+1));
    for(j = 1; j <= g[i].k; j++){
      scanf("%d", &g[i].v[j]);
    }
  }

  dfs(n);

  for(i = 1; i <= n; i++)
    printf("%d %d %d\n", i, t[i].d, t[i].f);
 
  return 0;
}


void dfs(int n){
  int i;

  for(i = 1; i <= n; i++)
    if(t[i].d == 0)
      visit(i);

}


void visit(int u){
  int i,j;

  t[u].d = ++mytime;

  for(i = 1; i <= g[u].k; i++){
    if(t[g[u].v[i]].d == 0)
      visit(g[u].v[i]);
  }

  t[u].f = ++mytime;

}
