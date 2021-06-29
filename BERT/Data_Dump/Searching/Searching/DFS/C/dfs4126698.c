#include <stdio.h>
#define N 100

typedef struct{
  int u;
  int k;
  int v[N];
}DFS;

DFS data[N];
int  time, n;
int color[N], d[N], f[N];

void visit(int u){
  int i, l, j;
  color[u] = 1;
  d[u] = ++time;
  for(i = 0; i < data[u].k; i++){
    l = data[u].v[i];
    for(j = 0; j < n; j++){
      if(data[j].u == l){
	if(color[j] == 0){
	  visit(j);
	}
      }
    }
  }
  color[u] = 2;
  f[u] = ++time;
}

int main(){
  int i, j;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d%d", &data[i].u, &data[i].k);
    for(j = 0; j < data[i].k; j++){
      scanf("%d", &data[i].v[j]);
    }
  }

  for(i = 0; i < n; i++){
    color[i] = 0;
  }
  time = 0;
  for(i = 0; i < n; i++){
    if(color[i] == 0){
      visit(i);
    }
  }

  for(i = 0; i < n; i++){
    printf("%d %d %d\n", data[i].u, d[i], f[i]);
  }

  return 0;
}
  

