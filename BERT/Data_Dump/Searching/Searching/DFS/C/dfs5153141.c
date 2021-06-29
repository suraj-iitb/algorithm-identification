#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int k;
  int *v;
  int d;
  int f;
  int c;
} G;

void dfs(int, G *);
int visit(int, G *, int);

int main(){
  G *V;
  int n, i, j, u, k;
  scanf("%d", &n);
  V = (G *)malloc((n+1) * sizeof(G));
  while(i < n){
    scanf("%d", &u);
    scanf("%d", &V[u].k);
    V[u].v = (int *)malloc(V[u].k * sizeof(int));
    for(j = 0; j < V[u].k; j++) scanf("%d", &V[u].v[j]);
    i++;
  }
  dfs(n, V);
  for(i = 1; i <= n; i++) printf("%d %d %d\n", i, V[i].d, V[i].f);
  return 0;
}

void dfs(int n, G *V){
  int i, time;
  for(i = 1; i <= n; i++) V[i].c = 0;
  time = 0;
  for(i = 1; i <= n; i++){
    if(V[i].c == 0) time = visit(i, V, time);
  }
}

int visit(int u, G *V, int time){
  int j;
  V[u].c = 1;
  V[u].d = ++time;
  for(j = 0; j < V[u].k; j++){
    if(V[V[u].v[j]].c == 0) time = visit(V[u].v[j], V, time);
  }
  V[u].c = 2;
  V[u].f = ++time;
  return time;
}

